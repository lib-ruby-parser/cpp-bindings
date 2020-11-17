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

#include <vector>
#include <string>
#include <variant>
#include \"inner_node.h\"
#include \"range.h\"

class Node;

std::vector<Node> node_ptr_to_vec(Node *ptr, size_t len);
std::string char_ptr_to_string(char *ptr, size_t len);

{classes}
using node_variant_t = std::variant<
{variants}>;

class Node
{{
public:
    node_variant_t inner;
    Node() = delete;
    Node(node_variant_t inner) : inner(std::move(inner)) {{}}
    Node(Node &&) = default;
    Node(const Node &) = delete;
}};

std::vector<Node> node_ptr_to_vec(Node *ptr, size_t len)
{{
    std::vector<Node> v;
    for (auto i = 0; i < len; i++) {{
        v.push_back(std::move(ptr[i]));
    }}
    return std::move(v);
}}

std::string char_ptr_to_string(char *ptr, size_t len)
{{
    std::string result(ptr, len);
    free(ptr);
    return result;
}}

#endif // LIB_RUBY_PARSER_GEN_H",
            classes = classes,
            variants = variants
        )
    }

    pub fn make_code(&self) -> String {
        let make_fns = self
            .cpp_classes
            .iter()
            .map(CppClass::make_fn)
            .collect::<Vec<_>>()
            .join("\n");

        format!(
            "#ifndef LIB_RUBY_PARSER_mAKE_H
#define LIB_RUBY_PARSER_mAKE_H

#include \"gen.h\"

extern \"C\" {{
{make_fns}

    Range *make_range(size_t begin_pos, size_t end_pos)
    {{
        return new Range(begin_pos, end_pos);
    }}
}}

#endif // LIB_RUBY_PARSER_mAKE_H",
            make_fns = make_fns
        )
    }

    pub fn bindings_code(&self) -> String {
        let class_forwards = self
            .cpp_classes
            .iter()
            .map(CppClass::forward_decl)
            .collect::<Vec<_>>()
            .join("\n");

        let make_decls = self
            .cpp_classes
            .iter()
            .map(CppClass::make_decl)
            .collect::<Vec<_>>()
            .join("\n");

        format!(
            "#ifndef LIB_RUBY_PARSER_BINDINGS_H
#define LIB_RUBY_PARSER_BINDINGS_H

#include <cstddef>

class Node;
class Range;
class ParserResult;
{class_forwards}

extern \"C\" {{
    Range *make_range(size_t begin_pos, size_t end_pos);
    ParserResult *make_parser_result(Node *node);
{make_decls}
}}

#endif // LIB_RUBY_PARSER_BINDINGS_H",
            class_forwards = class_forwards,
            make_decls = make_decls
        )
    }
}
