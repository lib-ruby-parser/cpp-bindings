use crate::gen::helpers::{map_node_fields, map_nodes};
use crate::gen::helpers::{Field, FieldType};

pub(crate) struct MakeH<'a> {
    nodes: &'a [lib_ruby_parser_nodes::Node],
}

impl<'a> MakeH<'a> {
    pub(crate) fn new(nodes: &'a [lib_ruby_parser_nodes::Node]) -> Self {
        Self { nodes }
    }

    pub(crate) fn write(&self) {
        std::fs::write("../src/gen/nodes/make.h", self.contents()).unwrap()
    }

    fn contents(&self) -> String {
        format!(
            "#ifndef LIB_RUBY_PARSER_MAKE_NODE_H
#define LIB_RUBY_PARSER_MAKE_NODE_H

#include <stdint.h>
#include \"../../byte_ptr.h\"

namespace lib_ruby_parser {{

class Node;
class Loc;

extern \"C\" {{

struct NodeVec
{{
    Node **ptr;
    uint32_t length;

    NodeVec(Node **ptr, uint32_t length)
    {{
        this->ptr = ptr;
        this->length = length;
    }}
}};

{make_fn_decls}

}}
}}

#endif // LIB_RUBY_PARSER_MAKE_NODE_H",
            make_fn_decls = self.make_fn_decls().join("\n")
        )
    }

    fn make_fn_decls(&self) -> Vec<String> {
        map_nodes(self.nodes, |n| MakeFnDecl::new(n).code())
    }
}

struct MakeFnDecl<'a> {
    node: &'a lib_ruby_parser_nodes::Node,
}

impl<'a> MakeFnDecl<'a> {
    fn new(node: &'a lib_ruby_parser_nodes::Node) -> Self {
        Self { node }
    }

    fn code(&self) -> String {
        format!(
            "Node *make_{fn_name}({args});",
            fn_name = self.node.filename,
            args = self.args().join(", "),
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
}
