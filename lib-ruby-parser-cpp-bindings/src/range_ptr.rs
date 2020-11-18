use crate::bindings::{make_range, size_t, Range};

pub struct RangePtr {
    ptr: *mut Range,
}

impl RangePtr {
    pub fn unwrap(self) -> *mut Range {
        self.ptr
    }
}

impl From<lib_ruby_parser::source::Range> for RangePtr {
    fn from(range: lib_ruby_parser::source::Range) -> Self {
        let begin_pos = range.begin_pos as size_t;
        let end_pos = range.end_pos as size_t;
        Self {
            ptr: unsafe { make_range(begin_pos, end_pos) },
        }
    }
}

impl From<Option<lib_ruby_parser::source::Range>> for RangePtr {
    fn from(maybe_range: Option<lib_ruby_parser::source::Range>) -> Self {
        match maybe_range {
            Some(range) => Self::from(range),
            None => Self {
                ptr: std::ptr::null_mut(),
            },
        }
    }
}
