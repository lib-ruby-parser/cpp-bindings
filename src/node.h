#ifndef LIB_RUBY_PARSER_NODE_H
#define LIB_RUBY_PARSER_NODE_H

#include "gen/nodes/variant.h"

namespace lib_ruby_parser
{
    class Node
    {
    public:
        node_variant_t inner;
        Node() = delete;
        Node(Node &&) = default;
        Node(const Node &) = delete;
        explicit Node(node_variant_t inner) : inner(std::move(inner)) {}

        template <typename T>
        bool is()
        {
            return std::holds_alternative<std::unique_ptr<T>>(inner);
        }

        template <typename T>
        T *get()
        {
            return std::get<std::unique_ptr<T>>(inner).get();
        }
    };
}

#endif // LIB_RUBY_PARSER_NODE_H
