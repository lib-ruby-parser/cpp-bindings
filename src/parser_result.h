#ifndef LIB_RUBY_PARSER_PARSER_RESULT_H
#define LIB_RUBY_PARSER_PARSER_RESULT_H

#include <string>
#include <memory>
#include <cstddef>
#include "bytes.h"
#include "node.h"
#include "token.h"
#include "diagnostic.h"
#include "comment.h"
#include "magic_comment.h"
#include "parser_options.h"

namespace lib_ruby_parser
{
    class ParserResult
    {
    public:
        ParserResult() = delete;
        explicit ParserResult(
            std::unique_ptr<Node> ast,
            std::vector<Token> tokens,
            std::vector<Diagnostic> diagnostics,
            std::vector<Comment> comments,
            std::vector<MagicComment> magic_comments,
            Bytes input);

        std::unique_ptr<Node> ast;
        std::vector<Token> tokens;
        std::vector<Diagnostic> diagnostics;
        std::vector<Comment> comments;
        std::vector<MagicComment> magic_comments;
        Bytes input;

        static std::unique_ptr<ParserResult> from_source(Bytes source, ParserOptions options);
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_PARSER_RESULT_H
