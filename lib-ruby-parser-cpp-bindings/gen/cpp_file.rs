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
        let class_forwards: Vec<String> = self
            .cpp_classes
            .iter()
            .map(CppClass::forward_decl)
            .collect();

        let classes: Vec<String> = self.cpp_classes.iter().map(CppClass::code).collect();

        let variants: Vec<String> = self
            .cpp_classes
            .iter()
            .map(|c| format!("std::unique_ptr<{}>", CppClass::class_name(c)))
            .collect();

        let make_fns: Vec<String> = self.cpp_classes.iter().map(CppClass::make_fn).collect();

        format!(
            "#ifndef LIB_RUBY_PARSER_GEN_H
#define LIB_RUBY_PARSER_GEN_H

#include <memory>
#include <vector>
#include <string>
#include <variant>
#include \"range.h\"

namespace lib_ruby_parser {{

class Node;
{class_forwards}

template <typename T>
std::vector<T> ptr_to_vec(T **ptr, size_t len);
std::string char_ptr_to_string(char *ptr, size_t len);

{classes}

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

#include \"parser_result.h\"

namespace lib_ruby_parser {{
extern \"C\" {{
    {make_fns}
}}
}}

#endif // LIB_RUBY_PARSER_GEN_H",
            class_forwards = class_forwards.join("\n"),
            classes = classes.join("\n"),
            variants = variants.join(",\n    "),
            make_fns = make_fns.join("\n    ")
        )
    }
}
