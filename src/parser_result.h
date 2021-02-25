#ifndef LIB_RUBY_PARSER_PARSER_RESULT_H
#define LIB_RUBY_PARSER_PARSER_RESULT_H

#include <string>
#include <memory>
#include <stdint.h>
#include "bytes.h"
#include "node.h"
#include "token.h"
#include "diagnostic.h"
#include "comment.h"
#include "magic_comment.h"
#include "parser_options.h"
#include "input.h"

namespace lib_ruby_parser
{
    class ParserResult
    {
    public:
        std::unique_ptr<Node> ast;
        std::vector<Token> tokens;
        std::vector<Diagnostic> diagnostics;
        std::vector<Comment> comments;
        std::vector<MagicComment> magic_comments;
        Input input;

        ParserResult() = delete;
        explicit ParserResult(
            std::unique_ptr<Node> ast,
            std::vector<Token> tokens,
            std::vector<Diagnostic> diagnostics,
            std::vector<Comment> comments,
            std::vector<MagicComment> magic_comments,
            Input input) : ast(std::move(ast)),
                           tokens(std::move(tokens)),
                           diagnostics(std::move(diagnostics)),
                           comments(std::move(comments)),
                           magic_comments(std::move(magic_comments)),
                           input(std::move(input)){};

        static std::unique_ptr<ParserResult> from_source(Bytes source, ParserOptions options);
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_PARSER_RESULT_H
