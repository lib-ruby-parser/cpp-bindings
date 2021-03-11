#ifndef LIB_RUBY_PARSER_NODE_H
#define LIB_RUBY_PARSER_NODE_H

#include "gen/nodes/variant.h"

namespace lib_ruby_parser
{
    // Generic node (tagged union)
    class Node
    {
    public:
        // std::variant of all possible nodes
        node_variant_t inner;

        Node() = delete;
        Node(Node &&) = default;
        Node(const Node &) = delete;
        explicit Node(node_variant_t inner);

        // Returns `true` if `Node` holds requested variant
        template <typename T>
        bool is() const
        {
            return std::holds_alternative<std::unique_ptr<T>>(inner);
        }

        // Returns pointer to requested variant.
        // `node.is<Args>()` must be used before calling
        // `Args *args = node.get<Args>()`
        template <typename T>
        T *get() const
        {
            return std::get<std::unique_ptr<T>>(inner).get();
        }
    };
}

#endif // LIB_RUBY_PARSER_NODE_H
