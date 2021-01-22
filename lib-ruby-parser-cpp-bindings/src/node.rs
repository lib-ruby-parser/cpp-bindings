use crate::bindings;
use crate::Ptr;

impl From<Option<lib_ruby_parser::Node>> for Ptr<bindings::Node> {
    fn from(node: Option<lib_ruby_parser::Node>) -> Self {
        match node {
            Some(node) => Self::from(node),
            None => Self::null(),
        }
    }
}

impl From<Box<lib_ruby_parser::Node>> for Ptr<bindings::Node> {
    fn from(node: Box<lib_ruby_parser::Node>) -> Self {
        Self::from(*node)
    }
}

impl From<Option<Box<lib_ruby_parser::Node>>> for Ptr<bindings::Node> {
    fn from(maybe_node: Option<Box<lib_ruby_parser::Node>>) -> Self {
        match maybe_node {
            Some(node) => Self::from(node),
            None => Self::null(),
        }
    }
}
