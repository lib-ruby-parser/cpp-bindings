#ifndef LIB_RUBY_PARSER_HELPERS_H
#define LIB_RUBY_PARSER_HELPERS_H

#include <vector>
#include <string>
#include <memory>
#include "node.h"
#include "make_node.h"

namespace lib_ruby_parser
{
    std::string char_ptr_to_string(char *ptr);
    char *string_to_char_ptr(std::string s);
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_HELPERS_H
