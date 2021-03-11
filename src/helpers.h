#ifndef LIB_RUBY_PARSER_HELPERS_H
#define LIB_RUBY_PARSER_HELPERS_H

#include <vector>
#include <string>
#include <memory>

namespace lib_ruby_parser
{
    // Constructs a string from null-terminated char pointer
    // TODO: remove as unused?
    std::string char_ptr_to_string(char *ptr);

    // Returns a char pointer of a given std::string
    // TODO: remove as unused?
    char *string_to_char_ptr(std::string s);
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_HELPERS_H
