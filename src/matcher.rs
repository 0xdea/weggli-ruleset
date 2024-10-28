use thiserror::Error;
use tree_sitter::Parser;

use crate::rule::RuleSet;

pub struct RuleMatcher {
    rules: RuleSet,
    c_parser: Parser,
    cxx_parser: Parser,
}

#[derive(Debug, Error)]
pub enum RuleMatcherError {
    #[error("cannot construct parser")]
    Parser(weggli::WeggliError),
}

impl RuleMatcher {
    pub fn new(rules: RuleSet) -> Result<Self, RuleMatcherError> {
        Ok(Self {
            rules,
            c_parser: weggli::get_parser(false).map_err(RuleMatcherError::Parser)?,
            cxx_parser: weggli::get_parser(true).map_err(RuleMatcherError::Parser)?,
        })
    }

    pub fn matches(&mut self, source: impl AsRef<str>) -> Result<(), RuleMatcherError> {
        self.matches_with(source, true)
    }

    pub fn matches_with(&mut self, source: impl AsRef<str>, is_cxx: bool) -> Result<(), RuleMatcherError> {
        let source = source.as_ref();

        let checkers = self.rules.viable_checkers(source);

        if checkers.is_empty() {
            return Ok(())
        }

        let tree = if is_cxx {
            self.cxx_parser.parse(source, None)
        } else {
            self.c_parser.parse(source, None)
        };

        // parse failed...
        let Some(tree) = tree else {
            return Ok(())
        };

        // TODO: actually report something ...
        for (_rule, checker) in checkers {
            checker.check_match(&tree, source);
        }

        Ok(())
    }
}
