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

    std::string char_ptr_to_string(char *ptr, size_t len)
    {
        std::string result(ptr, len);
        free(ptr);
        return result;
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_HELPERS_H
