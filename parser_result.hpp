#ifndef LIB_RUBY_PARSER_PARSER_RESULT_HPP
#define LIB_RUBY_PARSER_PARSER_RESULT_HPP

#include "nodes.hpp"
#include "token.hpp"
#include "diagnostic.hpp"
#include "comment.hpp"
#include "magic_comment.hpp"
#include "decoded_input.hpp"

namespace lib_ruby_parser
{
    /// Equivalent of `lib_ruby_parser::ParserResult`
    class ParserResult
    {
    public:
        /// Final AST, nullable.
        Node *ast;

        /// List of tokens, empty if `parser_options.record_tokens` was set to false
        TokenList tokens;

        /// List of diagnostics (errors/warnings)
        DiagnosticList diagnostics;

        /// List of comments
        CommentList comments;

        /// List of magic comments
        MagicCommentList magic_comments;

        /// Decoded input
        ///
        /// Sometimes source code has a magic encoding comment
        /// that forces us to re-encode given source to other encoding.
        ///
        /// In such cases source code on the byte level is different and so
        /// all locations (Loc) refer to that new re-encode byte ranges.
        ///
        /// Thus, always use this re-encoded byte array to compute source code
        /// of any location.
        DecodedInput input;

        ~ParserResult();

        ParserResult(const ParserResult &) = delete;
        ParserResult &operator=(ParserResult const &) = delete;

        ParserResult(ParserResult &&) = default;
        ParserResult &operator=(ParserResult &&) = default;
    };

#ifdef TEST_ENV
    void run_test_group_parser_result(void);
#endif
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_PARSER_RESULT_HPP
