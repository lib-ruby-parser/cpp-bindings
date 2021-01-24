pub(crate) trait CppFromRust<T> {
    fn convert(value: T) -> *mut Self;
}
