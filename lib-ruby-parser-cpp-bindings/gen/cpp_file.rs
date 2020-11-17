use super::CppClass;
use lib_ruby_parser_nodes::Node;

pub struct CppFile<'a> {
    cpp_classes: Vec<CppClass<'a>>,
}

impl<'a> CppFile<'a> {
    pub fn new(nodes: &'a Vec<Node>) -> Self {
        let cpp_classes = nodes
            .iter()
            .map(|node| CppClass::new(node))
            .collect::<Vec<_>>();
        Self { cpp_classes }
    }

    pub fn classes_code(&self) -> String {
        let classes = self
            .cpp_classes
            .iter()
            .map(CppClass::code)
            .collect::<Vec<_>>()
            .join("\n");

        let variants = self
            .cpp_classes
            .iter()
            .map(|class| format!("    {}", CppClass::class_name(class)))
            .collect::<Vec<_>>()
            .join(",\n");

        format!(
            "#ifndef LIB_RUBY_PARSER_GEN_H
#define LIB_RUBY_PARSER_GEN_H

#include <cstddef>
#include <memory>
#include <vector>
#include <string>
#include <variant>
#include \"inner_node.h\"
#include \"range.h\"

class Node;

{classes}
using node_variant_t = std::variant<
{variants}>;

class Node
{{
public:
    node_variant_t inner;
    Node(Node &&) = default;
    Node(const Node &) = delete;
}};

#endif // LIB_RUBY_PARSER_GEN_H",
            classes = classes,
            variants = variants
        )
    }

    pub fn make_node_code(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_MAKE_NODE_H
#define LIB_RUBY_PARSER_MAKE_NODE_H

#include \"gen.h\"

#endif // LIB_RUBY_PARSER_MAKE_NODE_H"
        )
    }
}
