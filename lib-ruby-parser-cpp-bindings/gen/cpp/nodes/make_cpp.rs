use crate::gen::helpers::{map_node_fields, map_nodes};
use crate::gen::helpers::{Field, FieldType};

pub(crate) struct MakeCpp<'a> {
    nodes: &'a [lib_ruby_parser_nodes::Node],
}

impl<'a> MakeCpp<'a> {
    pub(crate) fn new(nodes: &'a [lib_ruby_parser_nodes::Node]) -> Self {
        Self { nodes }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/gen/nodes/make.cpp", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "
#include <vector>
#include \"make.h\"
#include \"node.h\"

namespace lib_ruby_parser {{

std::vector<Node> nodes_vec_to_cpp_vec(NodeVec nodes)
{{
    std::vector<Node> v;
    for (uint32_t i = 0; i < nodes.length; i++)
    {{
        v.push_back(std::move(*nodes.ptr[i]));
        delete (nodes.ptr[i]);
    }}
    if (nodes.length != 0)
    {{
        free(nodes.ptr);
    }}
    return v;
}}

extern \"C\" {{

{make_fns}

}}
}}
",
            make_fns = self.make_fns().join("\n")
        )
    }

    fn make_fns(&self) -> Vec<String> {
        map_nodes(self.nodes, |n| MakeFn::new(n).code())
    }
}

struct MakeFn<'a> {
    node: &'a lib_ruby_parser_nodes::Node,
}

impl<'a> MakeFn<'a> {
    fn new(node: &'a lib_ruby_parser_nodes::Node) -> Self {
        Self { node }
    }

    fn code(&self) -> String {
        format!(
            "Node *make_{fn_name}({args}) {{
    node_variant_t inner = std::make_unique<{class_name}>({cast_args});
    return new Node(std::move(inner));
}}",
            class_name = self.node.struct_name,
            fn_name = self.node.filename,
            args = self.args().join(", "),
            cast_args = self.cast_args().join(", ")
        )
    }

    fn args(&self) -> Vec<String> {
        map_node_fields(&self.node.fields, |f| {
            format!(
                "{ptr_type} {ptr_name}",
                ptr_type = FieldType::new(&f.field_type).c_ptr(),
                ptr_name = Field::new(f).cpp_name()
            )
        })
    }

    fn cast_args(&self) -> Vec<String> {
        map_node_fields(&self.node.fields, |f| c_to_cpp(f))
    }
}

fn c_to_cpp(field: &lib_ruby_parser_nodes::Field) -> String {
    let field_name = Field::new(field).cpp_name();

    match field.field_type {
        lib_ruby_parser_nodes::FieldType::Node
        | lib_ruby_parser_nodes::FieldType::MaybeNode
        | lib_ruby_parser_nodes::FieldType::RegexOptions => {
            format!("std::unique_ptr<Node>({})", field_name)
        }

        lib_ruby_parser_nodes::FieldType::Nodes => {
            format!("nodes_vec_to_cpp_vec({name})", name = field_name)
        }
        lib_ruby_parser_nodes::FieldType::Loc | lib_ruby_parser_nodes::FieldType::MaybeLoc => {
            format!("std::unique_ptr<Loc>({})", field_name)
        }

        lib_ruby_parser_nodes::FieldType::U8 | lib_ruby_parser_nodes::FieldType::Usize => {
            field_name
        }

        lib_ruby_parser_nodes::FieldType::Str
        | lib_ruby_parser_nodes::FieldType::MaybeStr
        | lib_ruby_parser_nodes::FieldType::Chars
        | lib_ruby_parser_nodes::FieldType::RawString => {
            format!("byte_ptr_to_owned_string({})", field_name)
        }
        lib_ruby_parser_nodes::FieldType::StringValue => {
            format!("Bytes({})", field_name)
        }
    }
}
