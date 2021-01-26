#include <cstdlib>
#include <cstring>
#include "helpers.h"

namespace lib_ruby_parser
{
    std::string char_ptr_to_string(char *ptr)
    {
        std::string result(ptr);
        free(ptr);
        return result;
    }

    char *string_to_char_ptr(std::string s)
    {
        char *ptr = (char *)malloc(s.length() + 1);
        strcpy(ptr, s.c_str());
        ptr[s.length()] = '\0';
        return ptr;
    }
} // namespace lib_ruby_parser
