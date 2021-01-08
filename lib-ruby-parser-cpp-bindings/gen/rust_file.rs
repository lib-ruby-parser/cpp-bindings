use super::CppFieldType;
use lib_ruby_parser_nodes::{FieldType, Node};

pub struct RustFile {
    nodes: Vec<Node>,
}

impl RustFile {
    pub fn new(nodes: Vec<Node>) -> Self {
        Self { nodes }
    }

    pub fn code(&self) -> String {
        format!(
            "use crate::{{CppFromRust, NodePtr, RangePtr, nodes_to_ptr}};
use crate::bindings::*;
use crate::helpers::{{string_to_char_ptr, maybe_string_to_char_ptr, string_value_to_char_ptr, chars_to_char_ptr}};

{impls}

impl CppFromRust<lib_ruby_parser::Node> for Node {{
    fn convert(node: lib_ruby_parser::Node) -> *mut Self {{
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
                    "lib_ruby_parser::Node::{rust_struct_name}(inner) => Node::convert(inner),",
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
    pub fn new(node: &'a Node) -> Self {
        Self { node }
    }

    pub fn code(&self) -> String {
        format!(
            "impl CppFromRust<{rust_struct_name}> for Node {{
    fn convert(node: {rust_struct_name}) -> *mut Self {{
        let {rust_struct_name} {{ {rust_fields_list} }} = node;
        {conversions}
        unsafe {{
            make_{make_fn}({cpp_fields_list})
        }}
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
                    "let {field_name} = NodePtr::from({field_name}).unwrap();",
                    field_name = f.field_name
                ),
                FieldType::Nodes => format!(
                    "let ({field_name}, {field_name}_len) = nodes_to_ptr({field_name});",
                    field_name = f.field_name
                ),
                FieldType::Range | FieldType::MaybeRange => format!(
                    "let {field_name} = RangePtr::from({field_name}).unwrap();",
                    field_name = f.field_name
                ),
                FieldType::MaybeStr => format!(
                    "let {field_name} = maybe_string_to_char_ptr({field_name});",
                    field_name = f.field_name
                ),
                FieldType::StringValue => format!(
                    "let {field_name} = string_value_to_char_ptr({field_name});",
                    field_name = f.field_name
                ),
                FieldType::Chars => format!(
                    "let {field_name} = chars_to_char_ptr({field_name});",
                    field_name = f.field_name
                ),
                FieldType::Str | FieldType::RawString => format!(
                    "let {field_name} = string_to_char_ptr({field_name});",
                    field_name = f.field_name
                ),
                FieldType::U8 | FieldType::Usize => format!(
                    "let {field_name} = {field_name} as size_t;",
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
            .map(|f| {
                let mut result = vec![f.field_name.to_owned()];
                if CppFieldType::new(&f.field_type).needs_len() {
                    result.push(format!("{}_len", f.field_name));
                }
                result
            })
            .collect::<Vec<_>>()
            .concat()
            .join(", ")
    }
}
