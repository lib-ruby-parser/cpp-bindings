pub(crate) struct Ptr<T> {
    ptr: *mut T,
}

impl<T> Ptr<T> {
    pub(crate) fn new(ptr: *mut T) -> Self {
        Self { ptr }
    }

    pub(crate) fn null() -> Self {
        Self {
            ptr: std::ptr::null_mut(),
        }
    }

    pub(crate) fn unwrap(self) -> *mut T {
        self.ptr
    }
}
