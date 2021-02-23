use crate::bindings;
use crate::BytePtr;
use crate::Ptr;

impl From<&lib_ruby_parser::ErrorLevel> for bindings::ErrorLevel {
    fn from(level: &lib_ruby_parser::ErrorLevel) -> Self {
        match level {
            lib_ruby_parser::ErrorLevel::Warning => bindings::ErrorLevel::WARNING,
            lib_ruby_parser::ErrorLevel::Error => bindings::ErrorLevel::ERROR,
        }
    }
}

impl From<lib_ruby_parser::Diagnostic> for Ptr<bindings::Diagnostic> {
    fn from(diagnostic: lib_ruby_parser::Diagnostic) -> Self {
        let ptr = unsafe {
            bindings::make_diagnostic(
                bindings::ErrorLevel::from(&diagnostic.level),
                BytePtr::from(diagnostic.render_message()),
                Ptr::<bindings::Loc>::from(diagnostic.loc).unwrap(),
            )
        };
        Ptr::new(ptr)
    }
}
