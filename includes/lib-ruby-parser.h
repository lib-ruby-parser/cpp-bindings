#ifndef LIB_RUBY_PARSER_H
#define LIB_RUBY_PARSER_H

#include "types.h"
#include "gen.h"
#include "parser_result.h"

namespace lib_ruby_parser
{
    template <typename T>
    std::vector<T> ptr_to_vec(T **ptr, size_t len)
    {
        std::vector<T> v;
        for (auto i = 0; i < len; i++)
        {
            v.push_back(std::move(*ptr[i]));
            free(ptr[i]);
        }
        if (len != 0)
        {
            free(ptr);
        }
        return std::move(v);
    }

    std::string char_ptr_to_string(char *ptr, size_t len)
    {
        std::string result(ptr, len);
        free(ptr);
        return result;
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_H
