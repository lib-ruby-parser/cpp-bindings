#ifndef LIB_RUBY_PARSER_HELPERS_H
#define LIB_RUBY_PARSER_HELPERS_H

#include <vector>
#include <string>
#include <memory>
#include "node.h"

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
        return v;
    }

    std::string char_ptr_to_string(char *ptr);
    char *string_to_char_ptr(std::string s);
    extern "C"
    {
        void free_str(char *s);
    }

    std::vector<Node> nodes_vec_to_cpp_vec(NodeVec nodes);
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_HELPERS_H
