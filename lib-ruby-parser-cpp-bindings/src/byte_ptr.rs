use crate::bindings::{free_byte_ptr, size_t, BytePtr};

impl BytePtr {
    pub(crate) fn new(ptr: *const i8, size: usize) -> Self {
        Self {
            ptr: ptr as *mut i8,
            size: size as size_t,
        }
    }

    pub(crate) fn as_slice(&self) -> &[u8] {
        unsafe { std::slice::from_raw_parts(self.ptr as *mut u8, self.size as usize) }
    }

    pub(crate) fn to_vec(&self) -> Vec<u8> {
        self.as_slice().to_vec()
    }

    pub(crate) fn into_vec(self) -> Vec<u8> {
        let result = self.as_slice().to_vec();
        self.free();
        result
    }

    pub(crate) fn to_string(&self) -> Result<String, std::string::FromUtf8Error> {
        String::from_utf8(self.to_vec())
    }

    pub(crate) fn into_string(self) -> Result<String, std::string::FromUtf8Error> {
        String::from_utf8(self.into_vec())
    }

    pub(crate) fn to_string_lossy(&self) -> String {
        String::from_utf8_lossy(self.as_slice()).into_owned()
    }

    pub(crate) fn into_string_lossy(self) -> String {
        let result = String::from_utf8_lossy(self.as_slice()).into_owned();
        self.free();
        result
    }

    pub(crate) fn free(self) {
        unsafe { free_byte_ptr(self) }
    }
}

impl From<Vec<u8>> for BytePtr {
    fn from(bytes: Vec<u8>) -> Self {
        let bytes = Box::leak(bytes.into_boxed_slice());
        BytePtr::new(bytes.as_ptr() as *const i8, bytes.len())
    }
}

impl From<String> for BytePtr {
    fn from(s: String) -> BytePtr {
        BytePtr::from(s.into_bytes())
    }
}

impl From<&str> for BytePtr {
    fn from(s: &str) -> BytePtr {
        BytePtr::from(s.as_bytes())
    }
}

impl From<&[u8]> for BytePtr {
    fn from(bytes: &[u8]) -> BytePtr {
        BytePtr::new(bytes.as_ptr() as *const i8, bytes.len())
    }
}

impl From<Option<String>> for BytePtr {
    fn from(s: Option<String>) -> BytePtr {
        match s {
            Some(s) => BytePtr::from(s),
            None => BytePtr::from(""),
        }
    }
}

impl From<lib_ruby_parser::TokenValue> for BytePtr {
    fn from(token_value: lib_ruby_parser::TokenValue) -> BytePtr {
        BytePtr::from(token_value.into_bytes())
    }
}

impl From<lib_ruby_parser::source::buffer::Input> for BytePtr {
    fn from(input: lib_ruby_parser::source::buffer::Input) -> BytePtr {
        BytePtr::from(input.bytes)
    }
}

impl From<Vec<char>> for BytePtr {
    fn from(chars: Vec<char>) -> BytePtr {
        BytePtr::from(chars.into_iter().collect::<String>())
    }
}

impl From<lib_ruby_parser::StringValue> for BytePtr {
    fn from(value: lib_ruby_parser::StringValue) -> BytePtr {
        BytePtr::from(value.bytes)
    }
}

impl From<BytePtr> for lib_ruby_parser::TokenValue {
    fn from(byte_ptr: BytePtr) -> Self {
        match byte_ptr.into_string() {
            Ok(s) => lib_ruby_parser::TokenValue::String(s),
            Err(err) => lib_ruby_parser::TokenValue::InvalidString(err.into_bytes()),
        }
    }
}

impl From<BytePtr> for &[u8] {
    fn from(byte_ptr: BytePtr) -> Self {
        unsafe { std::slice::from_raw_parts(byte_ptr.ptr as *const u8, byte_ptr.size as usize) }
    }
}

impl From<BytePtr> for Vec<u8> {
    fn from(byte_ptr: BytePtr) -> Self {
        byte_ptr.into_vec()
    }
}
