use super::CppClass;
use lib_ruby_parser_nodes::Node;

pub(crate) struct CppFile<'a> {
    cpp_classes: Vec<CppClass<'a>>,
}

impl<'a> CppFile<'a> {
    pub(crate) fn new(nodes: &'a Vec<Node>) -> Self {
        let cpp_classes = nodes
            .iter()
            .map(|node| CppClass::new(node))
            .collect::<Vec<_>>();
        Self { cpp_classes }
    }

    pub(crate) fn node_h(&self) -> String {
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
#include \"bytes.h\"

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

}}
#endif // LIB_RUBY_PARSER_NODE_H
",
            class_forwards = class_forwards.join("\n"),
            variants = variants.join(",\n    "),
        )
    }

    pub(crate) fn node_cpp(&self) -> String {
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

    pub(crate) fn make_node_h(&self) -> String {
        let make_fn_decls: Vec<String> = self
            .cpp_classes
            .iter()
            .map(CppClass::make_fn_decl)
            .collect();

        format!(
            "#ifndef LIB_RUBY_PARSER_MAKE_NODE_H
#define LIB_RUBY_PARSER_MAKE_NODE_H

#include <cstddef>
#include \"bytes.h\"
#include \"byte_ptr.h\"

namespace lib_ruby_parser {{

class Node;
class Range;

extern \"C\" {{

struct NodeVec
{{
    Node **ptr;
    size_t length;

    NodeVec(Node **ptr, size_t length)
    {{
        this->ptr = ptr;
        this->length = length;
    }}
}};

{make_fn_decls}

}}
}}

#endif // LIB_RUBY_PARSER_MAKE_NODE_H",
            make_fn_decls = make_fn_decls.join("\n")
        )
    }

    pub(crate) fn make_node_cpp(&self) -> String {
        let make_fns: Vec<String> = self.cpp_classes.iter().map(CppClass::make_fn).collect();

        format!(
            "
#include <vector>
#include \"make_node.h\"
#include \"node.h\"

namespace lib_ruby_parser {{

std::vector<Node> nodes_vec_to_cpp_vec(NodeVec nodes)
{{
    std::vector<Node> v;
    for (size_t i = 0; i < nodes.length; i++)
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
            make_fns = make_fns.join("\n")
        )
    }
}
