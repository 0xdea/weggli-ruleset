use std::borrow::Borrow;
use std::collections::{HashMap, HashSet};
use std::fs::File;
use std::io::BufReader;
use std::path::{Path, PathBuf};
use std::sync::Arc;

use memchr::memmem;
use nonempty::NonEmpty;
use regex::Regex;
use rustc_hash::{FxHashMap, FxHashSet};
use serde::{Deserialize, Serialize};
use thiserror::Error;
use tree_sitter::Tree;
use walkdir::WalkDir;
use weggli::query::QueryTree;
use weggli::result::QueryResult;
use weggli::RegexMap;

#[derive(Debug, Error)]
pub enum RuleError {
    #[error(transparent)]
    Check(#[from] CheckError),
    #[error("cannot parse rule: {0}")]
    Parse(#[from] serde_yaml::Error),
    #[error("cannot parse rule file {}: {1}", _0.display())]
    ParseFile(PathBuf, anyhow::Error),
    #[error("rule has no checks")]
    NoChecks,
    #[error("rule has no identifier")]
    NoId,
    #[error("rule has multiple checks with the same name")]
    MultipleChecksWithSameName,
    #[error(transparent)]
    Regex(#[from] RegexError),
}

#[derive(Debug, Error)]
pub enum CheckError {
    #[error("check has no name")]
    NoCheckName,
    #[error("check has no patterns")]
    NoCheckPatterns,
    #[error("regex constraint has an invalid query variable `{0}`")]
    InvalidQueryVariable(String),
    #[error("invalid pattern: {0}")]
    Pattern(#[from] weggli::WeggliError),
    #[error(transparent)]
    Regex(#[from] RegexError),
}

#[derive(Debug, Error)]
pub enum RegexError {
    #[error("`{0}` is not in the format `var=regex`")]
    InvalidFormat(String),
    #[error("invalid regex: {0}")]
    InvalidRegex(#[from] regex::Error),
}

#[derive(Clone)]
pub struct RuleSet {
    rules: Arc<FxHashMap<String, Arc<Rule>>>,
}

impl RuleSet {
    pub fn from_directory(root: impl AsRef<Path>, ignore_errors: bool) -> Result<Self, RuleError> {
        let walker = WalkDir::new(root);
        let mut rules = FxHashMap::default();

        for dirent in walker
            .into_iter()
            .filter_entry(|e| {
                e.file_type().is_dir() || {
                    matches!(e.path().extension(), Some(x) if
                    ["yml", "yaml"].contains(&x.to_string_lossy().as_ref()))
                }
            })
            .filter_map(Result::ok)
        {
            if dirent.file_type().is_dir() {
                continue;
            }

            let path = dirent.path();
            match Rule::from_file(path) {
                Ok(rule) => {
                    rules.insert(path.display().to_string(), Arc::new(rule));
                }
                Err(e) => {
                    if !ignore_errors {
                        return Err(e);
                    }
                }
            }
        }

        Ok(Self {
            rules: Arc::new(rules),
        })
    }

    pub fn from_file(path: impl AsRef<Path>) -> Result<Self, RuleError> {
        let path = path.as_ref();
        Ok(Self {
            rules: Arc::new(FxHashMap::from_iter([(
                path.display().to_string(),
                Arc::new(Rule::from_file(path)?),
            )])),
        })
    }

    pub fn from_str(rule: impl AsRef<str>) -> Result<Self, RuleError> {
        Ok(Self {
            rules: Arc::new(FxHashMap::from_iter([(
                String::from("default"),
                Arc::new(Rule::from_str(rule)?),
            )])),
        })
    }

    pub fn iter(&self) -> impl ExactSizeIterator<Item = (&str, &Rule)> {
        self.rules.iter().map(|(p, r)| (p.as_str(), r.as_ref()))
    }

    pub fn viable_checkers(&self, source: impl AsRef<str>) -> Vec<(Arc<Rule>, usize, &Checker)> {
        let source = source.as_ref();

        self.rules
            .values()
            .map(|rule| {
                rule.checks().iter().enumerate().filter_map(|(i, checker)| {
                    if checker.can_match(source) {
                        Some((rule.clone(), i, checker))
                    } else {
                        None
                    }
                })
            })
            .flatten()
            .collect()
    }

    pub fn is_empty(&self) -> bool {
        self.rules.is_empty()
    }

    pub fn len(&self) -> usize {
        self.rules.len()
    }
}

#[derive(
    Debug, Clone, Copy, Default, PartialEq, Eq, PartialOrd, Ord, Hash, Deserialize, Serialize,
)]
#[serde(rename_all = "lowercase")]
pub enum Severity {
    #[default]
    None,
    Low,
    Medium,
    High,
    Critical,
}

pub struct Rule {
    id: String,
    author: String,
    description: String,
    severity: Severity,
    tags: FxHashSet<String>,
    checks: Box<[Checker]>,
}

impl Rule {
    pub fn from_file(path: impl AsRef<Path>) -> Result<Self, RuleError> {
        let path = path.as_ref();
        let file = File::open(path).map_err(|e| RuleError::ParseFile(path.to_owned(), e.into()))?;
        serde_yaml::from_reader(BufReader::new(file))
            .map_err(|e| RuleError::ParseFile(path.to_owned(), e.into()))
    }

    pub fn from_str(rule: impl AsRef<str>) -> Result<Self, RuleError> {
        serde_yaml::from_str(rule.as_ref()).map_err(RuleError::from)
    }

    pub fn id(&self) -> &str {
        &self.id
    }

    pub fn author(&self) -> Option<&str> {
        if self.author.is_empty() {
            None
        } else {
            Some(&self.author)
        }
    }

    pub fn description(&self) -> Option<&str> {
        if self.description.is_empty() {
            None
        } else {
            Some(&self.description)
        }
    }

    pub fn severity(&self) -> Severity {
        self.severity
    }

    pub fn tags(&self) -> &FxHashSet<String> {
        &self.tags
    }

    pub fn has_tag(&self, tag: impl Borrow<str>) -> bool {
        self.tags.contains(tag.borrow())
    }

    pub fn checks(&self) -> &[Checker] {
        &self.checks
    }
}

impl<'de> Deserialize<'de> for Rule {
    fn deserialize<D>(deserializer: D) -> Result<Self, D::Error>
    where
        D: serde::Deserializer<'de>,
    {
        #[derive(Deserialize)]
        struct RuleT {
            id: String,
            #[serde(default)]
            author: String,
            #[serde(default)]
            description: String,
            #[serde(default)]
            severity: Severity,
            #[serde(default)]
            tags: FxHashSet<String>,
            #[serde(
                rename = "check patterns",
                alias = "check-patterns",
                alias = "check pattern",
                alias = "check-pattern"
            )]
            checks: OneOrMany<CheckerT>,
        }

        let rule = RuleT::deserialize(deserializer)?;

        if rule.id.is_empty() {
            return Err(<D::Error as serde::de::Error>::custom(RuleError::NoId));
        }

        let checks = Vec::try_from(rule.checks)
            .map_err(<D::Error as serde::de::Error>::custom)?
            .into_boxed_slice();

        Ok(Rule {
            id: rule.id,
            author: rule.author,
            description: rule.description,
            severity: rule.severity,
            tags: rule.tags,
            checks,
        })
    }
}

#[derive(Debug, Clone, Copy, Default, PartialEq, Eq, PartialOrd, Ord, Deserialize)]
pub enum CheckerLanguage {
    #[serde(rename = "c", alias = "C++")]
    #[default]
    C,
    #[serde(rename = "c++", alias = "C++")]
    Cplusplus,
}

impl CheckerLanguage {
    pub fn is_c(&self) -> bool {
        matches!(self, Self::C)
    }

    pub fn is_cxx(&self) -> bool {
        matches!(self, Self::Cplusplus)
    }
}

pub struct Checker {
    name: Arc<str>,
    language: CheckerLanguage,
    pattern: QueryTree,
    identifiers: Box<[String]>,
    limit: bool,
    unique: bool,
}

impl Checker {
    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn name_for_match(&self) -> Arc<str> {
        self.name.clone()
    }

    pub fn language(&self) -> CheckerLanguage {
        self.language
    }

    pub fn pattern(&self) -> &QueryTree {
        &self.pattern
    }

    pub fn limit(&self) -> bool {
        self.limit
    }

    pub fn unique(&self) -> bool {
        self.unique
    }

    pub fn can_match(&self, source: &str) -> bool {
        self.identifiers
            .iter()
            .all(|ident| memmem::find(source.as_ref(), ident.as_ref()).is_some())
    }

    pub fn check_match(&self, tree: &Tree, source: &str) -> Vec<QueryResult> {
        let matches = self.pattern.matches(tree.root_node(), source);
        if matches.is_empty() {
            return Vec::with_capacity(0);
        }

        let check_unique = |m: &QueryResult| {
            !self.unique || {
                let mut seen = FxHashSet::default();
                m.vars
                    .keys()
                    .filter_map(|k| m.value(k, &source))
                    .all(|x| seen.insert(x))
            }
        };

        let mut skip_set = FxHashSet::default();
        let mut check_limit = |m: &QueryResult| !self.limit || skip_set.insert(m.start_offset());

        matches
            .into_iter()
            .filter(|v| check_unique(v) && check_limit(v))
            .collect()
    }
}

impl<'de> Deserialize<'de> for Checker {
    fn deserialize<D>(deserializer: D) -> Result<Self, D::Error>
    where
        D: serde::Deserializer<'de>,
    {
        let checker = CheckerT::deserialize(deserializer)?
            .try_into()
            .map_err(<D::Error as serde::de::Error>::custom)?;

        Ok(checker)
    }
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum OneOrMany<T> {
    Many(NonEmpty<T>),
    One(T),
}

impl<T> From<OneOrMany<T>> for Vec<T> {
    fn from(value: OneOrMany<T>) -> Self {
        match value {
            OneOrMany::One(v) => vec![v],
            OneOrMany::Many(vs) => vs.into(),
        }
    }
}

#[derive(Debug, Deserialize)]
struct CheckerT {
    #[serde(default = "default_check_name")]
    name: String,
    #[serde(default)]
    language: CheckerLanguage,
    pattern: String,
    #[serde(alias = "regex", default)]
    regexes: Option<OneOrMany<String>>,
    #[serde(default)]
    limit: bool,
    #[serde(default)]
    unique: bool,
}

fn default_check_name() -> String {
    String::from("default")
}

fn validate_checker(checker: CheckerT) -> Result<CheckerT, CheckError> {
    if checker.name.is_empty() {
        return Err(CheckError::NoCheckName);
    }

    Ok(checker)
}

fn build_pattern(
    input: String,
    constraints: &RegexMap,
    cxx: bool,
) -> Result<(QueryTree, HashSet<String>), CheckError> {
    let pattern = weggli::parse_search_pattern(&input, cxx, false, Some(constraints.clone()))?;
    let variables = pattern.variables();

    Ok((pattern, variables))
}

// NOTE: this is from weggli! maybe replace with nom + regex
fn build_regex_mapping(regexes: Option<OneOrMany<String>>) -> Result<RegexMap, CheckError> {
    let mut result = HashMap::new();

    let Some(regexes) = regexes.map(Vec::from) else {
        return Ok(RegexMap::new(result));
    };

    for r in regexes {
        let (var, raw_regex) = r
            .split_once('=')
            .ok_or_else(|| RegexError::InvalidFormat(r.to_owned()))?;

        let var = var.trim();
        let raw_regex = raw_regex.trim();

        let mut normalised_var = if var.starts_with('$') {
            var.to_owned()
        } else {
            format!("${var}")
        };

        let negative = normalised_var.ends_with('!');

        if negative {
            normalised_var.pop(); // remove !
        }

        let regex = Regex::new(raw_regex).map_err(RegexError::from)?;

        result.insert(normalised_var, (negative, regex));
    }

    Ok(RegexMap::new(result))
}

impl TryFrom<CheckerT> for Checker {
    type Error = CheckError;

    fn try_from(c: CheckerT) -> Result<Self, Self::Error> {
        let regexes = build_regex_mapping(c.regexes)?;
        let (pattern, variables) = build_pattern(c.pattern.into(), &regexes, c.language.is_cxx())?;

        for v in regexes.variables() {
            if !variables.contains(v) {
                return Err(CheckError::InvalidQueryVariable(v.to_owned()));
            }
        }

        Ok(Self {
            name: Arc::from(c.name),
            language: c.language,
            identifiers: pattern.identifiers().into_boxed_slice(),
            pattern,
            limit: c.limit,
            unique: c.unique,
        })
    }
}

impl TryFrom<OneOrMany<CheckerT>> for Vec<Checker> {
    type Error = RuleError;

    fn try_from(value: OneOrMany<CheckerT>) -> Result<Self, Self::Error> {
        match value {
            OneOrMany::One(checker) => {
                let checker = validate_checker(checker)?;
                Ok(vec![checker.try_into()?])
            }
            OneOrMany::Many(checkers) => {
                let mut names = FxHashSet::default();
                let mut checks = Vec::new();

                for checker in checkers {
                    let checker = validate_checker(checker)?;

                    if !names.insert(checker.name.to_owned()) {
                        return Err(RuleError::MultipleChecksWithSameName);
                    }

                    checks.push(checker.try_into()?);
                }

                Ok(checks)
            }
        }
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_rule_parse() -> Result<(), RuleError> {
        let rule1 = r#"
id: call-to-unbounded-copy-functions
check pattern:
  regex: func=^gets$
  pattern: '{$func();}'
"#;
        let rule = Rule::from_str(rule1)?;

        assert_eq!(rule.id(), "call-to-unbounded-copy-functions");
        assert_eq!(rule.checks().len(), 1);

        let rule2 = r#"
id: call-to-unbounded-copy-functions
description: call to unbounded copy functions
severity: medium
tags:
- CWE-120
- CWE-242
- CWE-676
check-patterns:
- name: gets
  regex: func=^gets$
  pattern: |
    { $func(); }

- name: st(r|p)(cpy|cat)
  regex: func=st(r|p)(cpy|cat)$
  pattern: '{$func();}'

- name: wc(r|p)(cpy|cat)
  regex: func=wc(r|p)(cpy|cat)$
  pattern: '{$func();}'

- name: sprintf
  regex: func=sprintf$
  pattern: '{$func();}'

- name: scanf
  regex: func=scanf$
  pattern: '{$func();}'
"#;

        let rule = Rule::from_str(rule2)?;

        assert_eq!(rule.id(), "call-to-unbounded-copy-functions");
        assert_eq!(rule.checks().len(), 5);

        Ok(())
    }
}
