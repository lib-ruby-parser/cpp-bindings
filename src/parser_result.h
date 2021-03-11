#ifndef LIB_RUBY_PARSER_PARSER_RESULT_H
#define LIB_RUBY_PARSER_PARSER_RESULT_H

#include <string>
#include <vector>
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
    // Result of the parser with all captured data
    class ParserResult
    {
    public:
        // AST node
        std::unique_ptr<Node> ast;

        // A list of tokens, empty if `ParserOptions::record_tokens` is set to false
        std::vector<Token> tokens;

        // A list of diagnostic messages (warnings and errors)
        std::vector<Diagnostic> diagnostics;

        // A list of comments
        std::vector<Comment> comments;

        // A list of magic comments
        std::vector<MagicComment> magic_comments;

        // Decoded input.
        Input input;

        ParserResult() = delete;
        explicit ParserResult(
            std::unique_ptr<Node> ast,
            std::vector<Token> tokens,
            std::vector<Diagnostic> diagnostics,
            std::vector<Comment> comments,
            std::vector<MagicComment> magic_comments,
            Input input);

        // The main method of this library. Performs parsing of the given `source` according to given `options`.
        static std::unique_ptr<ParserResult> from_source(Bytes source, const ParserOptions &options);
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_PARSER_RESULT_H
