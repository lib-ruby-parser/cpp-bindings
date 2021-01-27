use crate::bindings;
use crate::Ptr;

impl From<lib_ruby_parser::source::Range> for Ptr<bindings::Range> {
    fn from(range: lib_ruby_parser::source::Range) -> Self {
        let ptr = unsafe { bindings::make_range(range.begin_pos as u32, range.end_pos as u32) };
        Ptr::new(ptr)
    }
}

impl From<Option<lib_ruby_parser::source::Range>> for Ptr<bindings::Range> {
    fn from(maybe_range: Option<lib_ruby_parser::source::Range>) -> Self {
        match maybe_range {
            Some(range) => Self::from(range),
            None => Self::new(std::ptr::null_mut()),
        }
    }
}
