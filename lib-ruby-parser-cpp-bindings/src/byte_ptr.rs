use crate::bindings::{free_byte_ptr, BytePtr};

impl BytePtr {
    pub(crate) fn new(ptr: *const i8, size: usize) -> Self {
        Self {
            ptr: ptr as *mut i8,
            size: size as u32,
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

    pub(crate) fn empty() -> Self {
        Self::new(std::ptr::null_mut(), 0)
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

impl From<lib_ruby_parser::Bytes> for BytePtr {
    fn from(token_value: lib_ruby_parser::Bytes) -> BytePtr {
        BytePtr::from(token_value.into_bytes())
    }
}

impl From<lib_ruby_parser::source::Input> for BytePtr {
    fn from(input: lib_ruby_parser::source::Input) -> BytePtr {
        BytePtr::from(input.as_bytes().to_vec())
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

impl From<BytePtr> for lib_ruby_parser::Bytes {
    fn from(byte_ptr: BytePtr) -> Self {
        Self::new(byte_ptr.into_vec())
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

impl From<BytePtr> for lib_ruby_parser::source::Input {
    fn from(byte_ptr: BytePtr) -> Self {
        let bytes: &[u8] = byte_ptr.into();
        let bytes = bytes.to_vec();
        let mut input = Self::new("(eval)", None);
        input.set_bytes(bytes);
        input
    }
}
