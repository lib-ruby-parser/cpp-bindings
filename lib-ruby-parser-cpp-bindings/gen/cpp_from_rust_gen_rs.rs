use super::helpers::{map_node_fields, map_nodes};
use lib_ruby_parser_nodes::FieldType;

pub(crate) struct CppFromRustGen<'a> {
    nodes: &'a [lib_ruby_parser_nodes::Node],
}

impl<'a> CppFromRustGen<'a> {
    pub(crate) fn new(nodes: &'a [lib_ruby_parser_nodes::Node]) -> Self {
        Self { nodes }
    }

    pub(crate) fn write(&self) {
        std::fs::write("src/cpp_from_rust_gen.rs", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
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
        map_nodes(self.nodes, |node| CppFromRustImpl::new(node).code())
    }

    fn match_branches(&self) -> Vec<String> {
        map_nodes(self.nodes, |node| {
            format!(
                "lib_ruby_parser::Node::{rust_struct_name}(inner) => inner.into(),",
                rust_struct_name = node.struct_name
            )
        })
    }
}

struct CppFromRustImpl<'a> {
    node: &'a lib_ruby_parser_nodes::Node,
}

impl<'a> CppFromRustImpl<'a> {
    pub(crate) fn new(node: &'a lib_ruby_parser_nodes::Node) -> Self {
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
        map_node_fields(&self.node.fields, |f| f.field_name.to_owned()).join(", ")
    }

    fn conversions(&self) -> String {
        map_node_fields(&self.node.fields, |f| match f.field_type {
            FieldType::Node | FieldType::MaybeNode | FieldType::RegexOptions => format!(
                "let {field_name} = Ptr::<bindings::Node>::from({field_name}).unwrap();",
                field_name = f.field_name
            ),
            FieldType::Nodes => format!(
                "let {field_name} = bindings::NodeVec::from({field_name});",
                field_name = f.field_name
            ),
            FieldType::Loc | FieldType::MaybeLoc => format!(
                "let {field_name} = Ptr::<bindings::Loc>::from({field_name}).unwrap();",
                field_name = f.field_name
            ),
            FieldType::MaybeStr
            | FieldType::StringValue
            | FieldType::Chars
            | FieldType::Str
            | FieldType::RawString => format!(
                "let {field_name} = BytePtr::from({field_name});",
                field_name = f.field_name
            ),
            FieldType::U8 | FieldType::Usize => format!(
                "let {field_name} = {field_name} as u32;",
                field_name = f.field_name
            ),
        })
        .join("\n        ")
    }

    fn cpp_fields_list(&self) -> String {
        map_node_fields(&self.node.fields, |f| f.field_name.to_owned()).join(", ")
    }
}
