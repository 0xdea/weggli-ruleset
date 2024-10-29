use std::borrow::Cow;
use std::fmt::Debug;
use std::sync::Arc;

use rustc_hash::FxHashSet;
use serde::{Deserialize, Serialize};
use weggli::result::QueryResult;

use crate::matcher::RuleMatch;
use crate::rule::Severity;

#[derive(Deserialize, Serialize)]
pub struct RuleMatchReport<'a> {
    rule: Cow<'a, str>,
    checker: Cow<'a, str>,
    #[serde(skip_serializing_if = "str::is_empty")]
    description: Cow<'a, str>,
    #[serde(skip_serializing_if = "FxHashSet::<String>::is_empty")]
    tags: Cow<'a, FxHashSet<String>>,
    severity: Severity,
    source: Arc<str>,
    #[serde(rename = "match")]
    match_result: Cow<'a, QueryResult>,
}

impl<'a> Debug for RuleMatchReport<'a> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut m = f.debug_struct("RuleMatchReport");

        m.field("rule", &self.rule as _);
        m.field("checker", &self.checker as _);

        if let Some(ref description) = self.description() {
            m.field("description", description as _);
        }

        m.field("tags", self.tags());
        m.field("severity", &self.severity as _);
        m.field("matches", &self.match_result as _);

        m.finish_non_exhaustive()
    }
}

impl<'a> RuleMatchReport<'a> {
    pub fn new(m: &'a RuleMatch) -> Self {
        Self {
            rule: Cow::Borrowed(m.rule().id()),
            description: Cow::Borrowed(m.rule().description().unwrap_or_default()),
            checker: Cow::Borrowed(m.checker().name()),
            tags: Cow::Borrowed(m.rule().tags()),
            severity: m.rule().severity(),
            source: m.source(),
            match_result: Cow::Borrowed(m.result()),
        }
    }

    pub fn rule(&self) -> &str {
        &self.rule
    }

    pub fn checker(&self) -> &str {
        &self.checker
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

    pub fn source(&self) -> &str {
        &self.source
    }

    pub fn result(&self) -> &QueryResult {
        &self.match_result
    }

    pub fn display(&self, before: usize, after: usize, line_numbers: bool) -> String {
        self.match_result
            .display(&self.source, before, after, line_numbers)
    }

    pub fn into_owned(self) -> RuleMatchReport<'static> {
        RuleMatchReport {
            rule: self.rule.into_owned().into(),
            description: self.description.into_owned().into(),
            checker: self.checker.into_owned().into(),
            tags: Cow::Owned(self.tags.into_owned()),
            severity: self.severity,
            source: self.source,
            match_result: Cow::Owned(self.match_result.into_owned()),
        }
    }
}
