#ifndef LIB_RUBY_PARSER_PARSER_OPTIONS_H
#define LIB_RUBY_PARSER_PARSER_OPTIONS_H

#include <string>
#include "decoder.h"
#include "token_rewriter.h"

namespace lib_ruby_parser
{
    class ParserOptions
    {
    public:
        ParserOptions()
        {
            buffer_name = "(eval)";
            debug = false;
            decoder = nullptr;
            token_rewriter = nullptr;
            record_tokens = false;
        }

        explicit ParserOptions(
            std::string buffer_name,
            bool debug,
            std::unique_ptr<Decoder> decoder,
            std::unique_ptr<TokenRewriter> token_rewriter,
            bool record_tokens) : buffer_name(buffer_name),
                                  debug(debug),
                                  decoder(std::move(decoder)),
                                  token_rewriter(std::move(token_rewriter)),
                                  record_tokens(record_tokens) {}

        std::string buffer_name;
        bool debug;
        std::unique_ptr<Decoder> decoder;
        std::unique_ptr<TokenRewriter> token_rewriter;
        bool record_tokens;
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_PARSER_OPTIONS_H
