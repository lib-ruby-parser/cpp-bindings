use super::{Field, FieldType};

pub(crate) struct NodeH<'a> {
    nodes: &'a [lib_ruby_parser_nodes::Node],
}

impl<'a> NodeH<'a> {
    pub(crate) fn new(nodes: &'a [lib_ruby_parser_nodes::Node]) -> Self {
        Self { nodes }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/node.h", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_NODE_H
#define LIB_RUBY_PARSER_NODE_H

#include <memory>
#include <vector>
#include <string>
#include <variant>
#include \"loc.h\"
#include \"bytes.h\"

namespace lib_ruby_parser {{

class Node;
{class_declarations}

using node_variant_t = std::variant<
    {variants}>;

class Node
{{
public:
    node_variant_t inner;
    Node() = delete;
    Node(Node &&) = default;
    Node(const Node &) = delete;
    explicit Node(node_variant_t inner) : inner(std::move(inner)) {{}}

    template <typename T>
    bool is()
    {{
        return std::holds_alternative<std::unique_ptr<T>>(inner);
    }}

    template <typename T>
    T *get()
    {{
        return std::get<std::unique_ptr<T>>(inner).get();
    }}
}};

}}
#endif // LIB_RUBY_PARSER_NODE_H
",
            class_declarations = self.class_declarations().join("\n"),
            variants = self.variants().join(",\n    "),
        )
    }

    fn class_declarations(&self) -> Vec<String> {
        self.nodes
            .iter()
            .map(|node| CppClassDeclaration::new(node).code())
            .collect()
    }

    fn variants(&self) -> Vec<String> {
        self.nodes
            .iter()
            .map(|node| format!("std::unique_ptr<{}>", node.struct_name))
            .collect()
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
        self.node
            .fields
            .iter()
            .map(|f| {
                format!(
                    "{field_type} {field_name}",
                    field_type = FieldType::new(&f.field_type).cpp_type(),
                    field_name = Field::new(f).cpp_name()
                )
            })
            .collect()
    }
}
