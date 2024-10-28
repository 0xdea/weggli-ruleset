use std::borrow::Cow;

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
    source: Cow<'a, str>,
    #[serde(rename = "match")]
    match_result: Cow<'a, QueryResult>,
}

impl<'a> RuleMatchReport<'a> {
    pub fn new(m: &'a RuleMatch) -> Self {
        Self {
            rule: Cow::Borrowed(m.rule().id()),
            description: Cow::Borrowed(m.rule().description().unwrap_or_default()),
            checker: Cow::Borrowed(m.checker().name()),
            tags: Cow::Borrowed(m.rule().tags()),
            severity: m.rule().severity(),
            source: Cow::Borrowed(m.source()),
            match_result: Cow::Borrowed(m.result()),
        }
    }
}
