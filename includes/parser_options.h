#ifndef LIB_RUBY_PARSER_PARSER_OPTIONS_H
#define LIB_RUBY_PARSER_PARSER_OPTIONS_H

#include <string>
#include <memory>
#include "custom_decoder.h"
#include "token_rewriter.h"

namespace lib_ruby_parser
{
    class ParserOptions
    {
    public:
        explicit ParserOptions();
        ParserOptions(const ParserOptions &options) = delete;
        ParserOptions(ParserOptions &&options) = default;

        explicit ParserOptions(
            std::string buffer_name,
            bool debug,
            std::unique_ptr<CustomDecoder> custom_decoder,
            std::unique_ptr<TokenRewriter> token_rewriter,
            bool record_tokens);

        std::string buffer_name;
        bool debug;
        std::unique_ptr<CustomDecoder> custom_decoder;
        std::unique_ptr<TokenRewriter> token_rewriter;
        bool record_tokens;
    };

    extern "C"
    {
        const char *parser_options_buffer_name(ParserOptions *options);
        CustomDecoder *parser_options_custom_decoder(ParserOptions *options);
        TokenRewriter *parser_options_token_rewriter(ParserOptions *options);
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_PARSER_OPTIONS_H
