use crate::gen::helpers::map_nodes;

pub(crate) struct VariantH<'a> {
    nodes: &'a [lib_ruby_parser_nodes::Node],
}

impl<'a> VariantH<'a> {
    pub(crate) fn new(nodes: &'a [lib_ruby_parser_nodes::Node]) -> Self {
        Self { nodes }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/gen/nodes/variant.h", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_GEN_NODES_VARIANT_H
#define LIB_RUBY_PARSER_GEN_NODES_VARIANT_H

#include <memory>
#include <vector>
#include <string>
#include <variant>
#include \"classes.h\"

namespace lib_ruby_parser {{

using node_variant_t = std::variant<
    {variants}>;
}}
#endif // LIB_RUBY_PARSER_GEN_NODES_VARIANT_H
",
            variants = self.variants().join(",\n    "),
        )
    }

    fn variants(&self) -> Vec<String> {
        map_nodes(self.nodes, |node| {
            format!("std::unique_ptr<{}>", node.struct_name)
        })
    }
}
