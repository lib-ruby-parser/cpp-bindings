use crate::bindings;

impl From<&lib_ruby_parser::ErrorLevel> for bindings::ErrorLevel {
    fn from(level: &lib_ruby_parser::ErrorLevel) -> Self {
        match level {
            lib_ruby_parser::ErrorLevel::Warning => bindings::ErrorLevel::WARNING,
            lib_ruby_parser::ErrorLevel::Error => bindings::ErrorLevel::ERROR,
        }
    }
}
