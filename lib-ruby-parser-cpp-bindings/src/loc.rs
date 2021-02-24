use crate::bindings;
use crate::Ptr;

impl From<lib_ruby_parser::Loc> for Ptr<bindings::Loc> {
    fn from(loc: lib_ruby_parser::Loc) -> Self {
        let ptr = unsafe { bindings::make_loc(loc.begin as u32, loc.end as u32) };
        Ptr::new(ptr)
    }
}

impl From<Ptr<bindings::Loc>> for lib_ruby_parser::Loc {
    fn from(loc: Ptr<bindings::Loc>) -> Self {
        let loc = loc.unwrap();
        lib_ruby_parser::Loc {
            begin: unsafe { bindings::loc_begin(loc) } as usize,
            end: unsafe { bindings::loc_end(loc) } as usize,
        }
    }
}

impl From<Option<lib_ruby_parser::Loc>> for Ptr<bindings::Loc> {
    fn from(maybe_loc: Option<lib_ruby_parser::Loc>) -> Self {
        match maybe_loc {
            Some(loc) => Self::from(loc),
            None => Self::new(std::ptr::null_mut()),
        }
    }
}
