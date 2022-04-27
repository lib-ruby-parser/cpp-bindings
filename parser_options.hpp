#ifndef LIB_RUBY_PARSER_PARSER_OPTIONS_HPP
#define LIB_RUBY_PARSER_PARSER_OPTIONS_HPP

#include <cstdint>
#include <cstdbool>
#include "string.hpp"
#include "decoder.hpp"
#include "token_rewriter.hpp"

namespace lib_ruby_parser
{
    /// Equivalent of `lib_ruby_parser::ParserOptions`
    class ParserOptions
    {
    public:
        String buffer_name;
        MaybeDecoder decoder;
        MaybeTokenRewriter token_rewriter;
        bool record_tokens;

        ParserOptions(
            String buffer_name,
            MaybeDecoder decoder,
            MaybeTokenRewriter token_rewriter,
            bool record_tokens);

        ParserOptions(const ParserOptions &) = delete;
        ParserOptions &operator=(ParserOptions const &) = delete;

        ParserOptions(ParserOptions &&) = default;
        ParserOptions &operator=(ParserOptions &&) = default;
    };

#ifdef TEST_ENV
    void run_test_group_parser_options(void);
#endif

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_PARSER_OPTIONS_HPP
