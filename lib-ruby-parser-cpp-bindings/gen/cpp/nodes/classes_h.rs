use crate::gen::helpers::{map_node_fields, map_nodes};
use crate::gen::helpers::{Field, FieldType};

pub(crate) struct ClassesH<'a> {
    nodes: &'a [lib_ruby_parser_nodes::Node],
}

impl<'a> ClassesH<'a> {
    pub(crate) fn new(nodes: &'a [lib_ruby_parser_nodes::Node]) -> Self {
        Self { nodes }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/gen/nodes/classes.h", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_GEN_NODES_CLASSES_H
#define LIB_RUBY_PARSER_GEN_NODES_CLASSES_H

#include <memory>
#include <vector>
#include <string>
#include \"../../loc.h\"
#include \"../../bytes.h\"

namespace lib_ruby_parser {{

class Node;

{class_declarations}

}}

#include \"../../node.h\"

#endif // LIB_RUBY_PARSER_GEN_NODES_CLASSES_H
",
            class_declarations = self.class_declarations().join("\n"),
        )
    }

    fn class_declarations(&self) -> Vec<String> {
        map_nodes(self.nodes, |node| CppClassDeclaration::new(node).code())
    }
}

struct CppClassDeclaration<'a> {
    node: &'a lib_ruby_parser_nodes::Node,
}

impl<'a> CppClassDeclaration<'a> {
    fn new(node: &'a lib_ruby_parser_nodes::Node) -> Self {
        Self { node }
    }

    fn code(&self) -> String {
        format!(
            "
{comment}
class {class_name}
{{
public:
    {fields_declaration}

    {class_name}() = delete;
    {class_name}({class_name} &&) = default;
    {class_name}(const {class_name} &) = delete;
    explicit {class_name}({constructor_args});
}};",
            comment = self.comment(),
            class_name = self.node.struct_name,
            fields_declaration = self.fields_declaration().join("\n    "),
            constructor_args = self.constructor_args().join(", ")
        )
    }

    fn comment(&self) -> String {
        self.node
            .comment
            .lines()
            .map(|l| format!("// {}", l).trim_end().to_owned())
            .collect()
    }

    fn fields_declaration(&self) -> Vec<String> {
        self.node
            .fields
            .iter()
            .flat_map(|f| {
                let mut lines = f
                    .comment
                    .lines()
                    .map(|l| format!("// {}", l).trim_end().to_owned())
                    .collect::<Vec<_>>();
                lines.push(format!(
                    "{field_type} {field_name};",
                    field_type = FieldType::new(&f.field_type).cpp_type(),
                    field_name = Field::new(f).cpp_name()
                ));
                lines
            })
            .collect()
    }

    fn constructor_args(&self) -> Vec<String> {
        map_node_fields(&self.node.fields, |f| {
            format!(
                "{field_type} {field_name}",
                field_type = FieldType::new(&f.field_type).cpp_type(),
                field_name = Field::new(f).cpp_name()
            )
        })
    }
}
