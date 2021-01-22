use lib_ruby_parser_nodes::{FieldType, Node};

pub(crate) struct RustFile {
    nodes: Vec<Node>,
}

impl RustFile {
    pub(crate) fn new(nodes: Vec<Node>) -> Self {
        Self { nodes }
    }

    pub(crate) fn code(&self) -> String {
        format!(
            "use crate::bindings;
use crate::Ptr;
use crate::BytePtr;

{impls}

impl From<lib_ruby_parser::Node> for Ptr<bindings::Node> {{
    fn from(node: lib_ruby_parser::Node) -> Self {{
        match node {{
            {match_branches}
        }}
    }}
}}
",
            impls = self.impls().join("\n"),
            match_branches = self.match_branches().join("\n            ")
        )
    }

    fn impls(&self) -> Vec<String> {
        self.nodes
            .iter()
            .map(|node| CppFromRustImpl::new(node).code())
            .collect()
    }

    fn match_branches(&self) -> Vec<String> {
        self.nodes
            .iter()
            .map(|node| {
                format!(
                    "lib_ruby_parser::Node::{rust_struct_name}(inner) => inner.into(),",
                    rust_struct_name = node.struct_name
                )
            })
            .collect()
    }
}

struct CppFromRustImpl<'a> {
    node: &'a Node,
}

impl<'a> CppFromRustImpl<'a> {
    pub(crate) fn new(node: &'a Node) -> Self {
        Self { node }
    }

    pub(crate) fn code(&self) -> String {
        format!(
            "impl From<{rust_struct_name}> for Ptr<bindings::Node> {{
    fn from(node: {rust_struct_name}) -> Self {{
        let {rust_struct_name} {{ {rust_fields_list} }} = node;
        {conversions}
        let ptr = unsafe {{
            bindings::make_{make_fn}({cpp_fields_list})
        }};
        Ptr::new(ptr)
    }}
}}
",
            rust_struct_name = self.rust_struct_name(),
            rust_fields_list = self.rust_fields_list(),
            conversions = self.conversions(),
            make_fn = self.node.filename,
            cpp_fields_list = self.cpp_fields_list(),
        )
    }

    fn rust_struct_name(&self) -> String {
        format!("lib_ruby_parser::nodes::{}", self.node.struct_name)
    }

    fn rust_fields_list(&self) -> String {
        self.node
            .fields
            .iter()
            .map(|f| f.field_name.to_owned())
            .collect::<Vec<_>>()
            .join(", ")
    }

    fn conversions(&self) -> String {
        self.node
            .fields
            .iter()
            .map(|f| match f.field_type {
                FieldType::Node | FieldType::MaybeNode | FieldType::RegexOptions => format!(
                    "let {field_name} = Ptr::<bindings::Node>::from({field_name}).unwrap();",
                    field_name = f.field_name
                ),
                FieldType::Nodes => format!(
                    "let {field_name} = bindings::NodeVec::from({field_name});",
                    field_name = f.field_name
                ),
                FieldType::Range | FieldType::MaybeRange => format!(
                    "let {field_name} = Ptr::<bindings::Range>::from({field_name}).unwrap();",
                    field_name = f.field_name
                ),
                FieldType::MaybeStr => format!(
                    "let {field_name} = BytePtr::from({field_name});",
                    field_name = f.field_name
                ),
                FieldType::StringValue => format!(
                    "let {field_name} = BytePtr::from({field_name});",
                    field_name = f.field_name
                ),
                FieldType::Chars => format!(
                    "let {field_name} = BytePtr::from({field_name});",
                    field_name = f.field_name
                ),
                FieldType::Str | FieldType::RawString => format!(
                    "let {field_name} = BytePtr::from({field_name});",
                    field_name = f.field_name
                ),
                FieldType::U8 | FieldType::Usize => format!(
                    "let {field_name} = {field_name} as bindings::size_t;",
                    field_name = f.field_name
                ),
            })
            .collect::<Vec<_>>()
            .join("\n        ")
    }

    fn cpp_fields_list(&self) -> String {
        self.node
            .fields
            .iter()
            .map(|f| f.field_name.to_owned())
            .collect::<Vec<_>>()
            .join(", ")
    }
}
