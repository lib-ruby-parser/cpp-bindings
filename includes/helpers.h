#ifndef LIB_RUBY_PARSER_HELPERS_H
#define LIB_RUBY_PARSER_HELPERS_H

#include <vector>
#include <string>

namespace lib_ruby_parser
{
    template <typename T>
    std::vector<T> ptr_to_vec(T **ptr, size_t len)
    {
        std::vector<T> v;
        for (size_t i = 0; i < len; i++)
        {
            v.push_back(std::move(*ptr[i]));
            delete (ptr[i]);
        }
        if (len != 0)
        {
            free(ptr);
        }
        return std::move(v);
    }

    std::string char_ptr_to_string(char *ptr)
    {
        std::string result(ptr);
        free(ptr);
        return result;
    }

    // class Node;
    // extern "C"
    // {
    //     struct NodeVec
    //     {
    //         Node **list;
    //         size_t length;

    //         NodeVec(Node **list, size_t length) : list(list), length(length) {}
    //     };

    //     NodeVec make_node_vec(Node **list, size_t length)
    //     {
    //         return NodeVec(list, length);
    //     }
    // }

    // std::vector<Node> nodes_vec_to_cpp_vec(NodeVec nodes)
    // {
    //     return ptr_to_vec<Node>(nodes.list, nodes.length);
    // }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_HELPERS_H
