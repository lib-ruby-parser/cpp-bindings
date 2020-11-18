use crate::bindings::Node;
use crate::CppFromRust;

pub struct NodePtr {
    ptr: *mut Node,
}

impl NodePtr {
    pub fn unwrap(self) -> *mut Node {
        self.ptr
    }
}

impl From<lib_ruby_parser::Node> for NodePtr {
    fn from(node: lib_ruby_parser::Node) -> Self {
        Self {
            ptr: CppFromRust::convert(node),
        }
    }
}

impl From<Option<lib_ruby_parser::Node>> for NodePtr {
    fn from(node: Option<lib_ruby_parser::Node>) -> Self {
        match node {
            Some(node) => Self::from(node),
            None => Self {
                ptr: std::ptr::null_mut(),
            },
        }
    }
}

impl From<Box<lib_ruby_parser::Node>> for NodePtr {
    fn from(node: Box<lib_ruby_parser::Node>) -> Self {
        Self::from(*node)
    }
}

impl From<Option<Box<lib_ruby_parser::Node>>> for NodePtr {
    fn from(maybe_node: Option<Box<lib_ruby_parser::Node>>) -> Self {
        match maybe_node {
            Some(node) => Self::from(node),
            None => Self {
                ptr: std::ptr::null_mut(),
            },
        }
    }
}
