use crate::gen::helpers::{map_node_fields, map_nodes};
use crate::gen::helpers::{Field, FieldType};

pub(crate) struct ClassesCpp<'a> {
    nodes: &'a [lib_ruby_parser_nodes::Node],
}

impl<'a> ClassesCpp<'a> {
    pub(crate) fn new(nodes: &'a [lib_ruby_parser_nodes::Node]) -> Self {
        Self { nodes }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/gen/nodes/classes.cpp", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#include \"classes.h\"

namespace lib_ruby_parser {{

{implementations}

}}
",
            implementations = self.implementations().join("\n")
        )
    }

    fn implementations(&self) -> Vec<String> {
        map_nodes(self.nodes, |n| NodeImplementation::new(n).code())
    }
}

struct NodeImplementation<'a> {
    node: &'a lib_ruby_parser_nodes::Node,
}

impl<'a> NodeImplementation<'a> {
    fn new(node: &'a lib_ruby_parser_nodes::Node) -> Self {
        Self { node }
    }

    fn code(&self) -> String {
        format!(
            "{class_name}::{class_name}({args})
{{
{constructor}
}}
",
            class_name = self.node.struct_name,
            args = self.args().join(", "),
            constructor = self.construtor_stmts().join("\n")
        )
    }

    fn args(&self) -> Vec<String> {
        map_node_fields(&self.node.fields, |f| {
            format!(
                "{field_type} {field_name}",
                field_type = FieldType::new(&f.field_type).cpp_type(),
                field_name = Field::new(f).cpp_name()
            )
        })
    }

    fn construtor_stmts(&self) -> Vec<String> {
        map_node_fields(&self.node.fields, |f| {
            let field_name = Field::new(f).cpp_name();

            let mut rhs = field_name.clone();
            if FieldType::new(&f.field_type).needs_move() {
                rhs = format!("std::move({})", rhs)
            }

            format!(
                "this->{field_name} = {rhs};",
                field_name = field_name,
                rhs = rhs
            )
        })
    }
}
