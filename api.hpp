#ifndef LIB_RUBY_PARSER_API_HPP
#define LIB_RUBY_PARSER_API_HPP

#include "parser_options.hpp"
#include "parser_result.hpp"

namespace lib_ruby_parser
{
    /// Parses given `input` according to `option`.
    /// This is the main entrypoint API.
    ParserResult parse(ByteList input, ParserOptions options);
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_API_HPP
