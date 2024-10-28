use std::path::Path;
use std::sync::Arc;

use thiserror::Error;
use tree_sitter::Parser;
use weggli::result::QueryResult;

use crate::rule::{Checker, Rule, RuleError, RuleSet};

pub struct RuleMatcher {
    rules: RuleSet,
    c_parser: Parser,
    cxx_parser: Parser,
}

pub struct RuleMatch {
    rule: Arc<Rule>,
    checker: usize,
    source: Arc<str>,
    result: QueryResult,
}

impl RuleMatch {
    pub fn rule(&self) -> &Rule {
        &self.rule
    }

    pub fn checker(&self) -> &Checker {
        &self.rule().checks()[self.checker]
    }

    pub fn source(&self) -> &str {
        &self.source
    }

    pub fn result(&self) -> &QueryResult {
        &self.result
    }

    pub fn display(&self, before: usize, after: usize, line_numbers: bool) -> String {
        self.result
            .display(&self.source, before, after, line_numbers)
    }
}

#[derive(Debug, Error)]
pub enum RuleMatcherError {
    #[error("cannot construct parser")]
    Parser(weggli::WeggliError),
    #[error(transparent)]
    Rules(#[from] RuleError),
}

impl RuleMatcher {
    pub fn new(rules: RuleSet) -> Result<Self, RuleMatcherError> {
        Ok(Self {
            rules,
            c_parser: weggli::get_parser(false).map_err(RuleMatcherError::Parser)?,
            cxx_parser: weggli::get_parser(true).map_err(RuleMatcherError::Parser)?,
        })
    }

    pub fn from_file(path: impl AsRef<Path>) -> Result<Self, RuleMatcherError> {
        Self::new(RuleSet::from_file(path)?)
    }

    pub fn from_str(rule: impl AsRef<str>) -> Result<Self, RuleMatcherError> {
        Self::new(RuleSet::from_str(rule)?)
    }

    pub fn from_directory(root: impl AsRef<Path>) -> Result<Self, RuleMatcherError> {
        Self::from_directory_with(root, true)
    }

    pub fn from_directory_with(
        root: impl AsRef<Path>,
        ignore_errors: bool,
    ) -> Result<Self, RuleMatcherError> {
        Self::new(RuleSet::from_directory(root, ignore_errors)?)
    }

    pub fn rules(&self) -> &RuleSet {
        &self.rules
    }

    pub fn matches(&mut self, source: impl AsRef<str>) -> Result<Vec<RuleMatch>, RuleMatcherError> {
        self.matches_with(source, true)
    }

    pub fn matches_with(
        &mut self,
        source: impl AsRef<str>,
        is_cxx: bool,
    ) -> Result<Vec<RuleMatch>, RuleMatcherError> {
        let source = source.as_ref();

        let checkers = self.rules.viable_checkers(source);

        if checkers.is_empty() {
            return Ok(Vec::with_capacity(0));
        }

        let tree = if is_cxx {
            self.cxx_parser.parse(source, None)
        } else {
            self.c_parser.parse(source, None)
        };

        // parse failed...
        let Some(tree) = tree else {
            return Ok(Vec::with_capacity(0));
        };

        let source = Arc::<str>::from(source);

        let results = checkers
            .into_iter()
            .flat_map(|(rule, index, checker)| {
                let source = source.clone();
                checker
                    .check_match(&tree, &source)
                    .into_iter()
                    .map(move |result| RuleMatch {
                        rule: rule.clone(),
                        checker: index,
                        source: source.clone(),
                        result,
                    })
            })
            .collect();

        Ok(results)
    }
}
