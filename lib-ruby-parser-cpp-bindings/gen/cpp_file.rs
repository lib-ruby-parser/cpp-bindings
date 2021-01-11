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

    pub fn node_h(&self) -> String {
        let class_forwards: Vec<String> =
            self.cpp_classes.iter().map(CppClass::definition).collect();

        let variants: Vec<String> = self
            .cpp_classes
            .iter()
            .map(|c| format!("std::unique_ptr<{}>", CppClass::class_name(c)))
            .collect();

        format!(
            "#ifndef LIB_RUBY_PARSER_NODE_H
#define LIB_RUBY_PARSER_NODE_H

#include <memory>
#include <vector>
#include <string>
#include <variant>
#include \"range.h\"

namespace lib_ruby_parser {{

class Node;
{class_forwards}

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

extern \"C\"
{{
    struct NodeVec
    {{
        Node **list;
        size_t length;

        NodeVec(Node **list, size_t length)
        {{
            this->list = list;
            this->length = length;
        }}
    }};
}}

}}
#endif // LIB_RUBY_PARSER_NODE_H
",
            class_forwards = class_forwards.join("\n"),
            variants = variants.join(",\n    "),
        )
    }

    pub fn node_cpp(&self) -> String {
        let implementations = self
            .cpp_classes
            .iter()
            .map(CppClass::implementation)
            .collect::<Vec<_>>();

        format!(
            "#include \"node.h\"
namespace lib_ruby_parser {{
{implementations}
}}
",
            implementations = implementations.join("\n")
        )
    }

    pub fn make_node_h(&self) -> String {
        let make_fn_decls: Vec<String> = self
            .cpp_classes
            .iter()
            .map(CppClass::make_fn_decl)
            .collect();

        format!(
            "#ifndef LIB_RUBY_PARSER_MAKE_NODE_H
#define LIB_RUBY_PARSER_MAKE_NODE_H

#include \"node.h\"

namespace lib_ruby_parser {{
extern \"C\" {{

{make_fn_decls}

}}
}}

#endif // LIB_RUBY_PARSER_MAKE_NODE_H",
            make_fn_decls = make_fn_decls.join("\n")
        )
    }

    pub fn make_node_cpp(&self) -> String {
        let make_fns: Vec<String> = self.cpp_classes.iter().map(CppClass::make_fn).collect();

        format!(
            "
#include \"make_node.h\"
#include \"helpers.h\"

namespace lib_ruby_parser {{
extern \"C\" {{

{make_fns}

}}
}}
",
            make_fns = make_fns.join("\n")
        )
    }
}
