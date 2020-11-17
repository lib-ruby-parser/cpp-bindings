use crate::bindings::size_t;
use crate::{string_to_ptr, vec_to_ptr};

pub struct StringPtr {
    ptr: *mut i8,
    len: size_t,
}

impl StringPtr {
    pub fn unwrap(self) -> (*mut i8, size_t) {
        (self.ptr, self.len)
    }
}

impl From<String> for StringPtr {
    fn from(s: String) -> Self {
        let (ptr, len) = string_to_ptr(s);
        Self { ptr, len }
    }
}

impl From<Option<String>> for StringPtr {
    fn from(maybe_s: Option<String>) -> Self {
        if let Some(s) = maybe_s {
            StringPtr::from(s)
        } else {
            StringPtr {
                ptr: std::ptr::null_mut(),
                len: 0,
            }
        }
    }
}

impl From<Vec<char>> for StringPtr {
    fn from(chars: Vec<char>) -> Self {
        StringPtr::from(chars.iter().collect::<String>())
    }
}

impl From<lib_ruby_parser::StringValue> for StringPtr {
    fn from(string_value: lib_ruby_parser::StringValue) -> Self {
        let mut str_bytes = string_value.bytes;
        let len = str_bytes.len() as size_t;
        str_bytes.push(0);
        Self {
            ptr: vec_to_ptr(str_bytes).0,
            len,
        }
    }
}
