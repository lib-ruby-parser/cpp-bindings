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
            buffer_name = new char[7];
            memcpy(buffer_name, "(eval)", 6);
            buffer_name[6] = '\0';
            debug = false;
            decoder = nullptr;
            token_rewriter = nullptr;
            record_tokens = false;
        }

        explicit ParserOptions(
            std::string buffer_name_,
            bool debug,
            Decoder *decoder,
            TokenRewriter *token_rewriter,
            bool record_tokens) : debug(debug),
                                  decoder(decoder),
                                  token_rewriter(token_rewriter),
                                  record_tokens(record_tokens)
        {
            buffer_name = new char[buffer_name_.size() + 1];
            std::copy(buffer_name_.begin(), buffer_name_.end(), buffer_name);
            buffer_name[buffer_name_.size()] = '\0';
        }

        ~ParserOptions()
        {
            delete buffer_name;
            delete decoder;
            delete token_rewriter;
        }

        char *buffer_name;
        bool debug;
        Decoder *decoder;
        TokenRewriter *token_rewriter;
        bool record_tokens;
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_PARSER_OPTIONS_H
