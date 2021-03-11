#include "node.h"

namespace lib_ruby_parser
{
    Node::Node(node_variant_t inner) : inner(std::move(inner)) {}
}
