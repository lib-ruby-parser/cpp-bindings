#include "test_helper.hpp"
#include "../parser_result.hpp"
#include "../utils.hpp"
#include <cstdlib>

namespace lib_ruby_parser
{
#ifndef PARSER_RESULT_HAS_BLOB
#define PARSER_RESULT_HAS_BLOB
    BLOB(ParserResult);
#endif // PARSER_RESULT_HAS_BLOB

    extern "C"
    {
        ParserResultBlob lib_ruby_parser__test__make_parser_result(void);
    }
    static void test_parser_result(void)
    {
        annotate_test;

        ParserResult parser_result = from_blob<ParserResultBlob, ParserResult>(
            lib_ruby_parser__test__make_parser_result());

        // ast
        assert_eq(parser_result.ast->tag, Node::Tag::RETRY);
        assert_loc(parser_result.ast->as.retry.expression_l, Loc(1, 2));

        // tokens
        assert_eq(parser_result.tokens.len, 1);
        assert_token(parser_result.tokens.ptr[0], "tINTEGER");

        // diagnostics
        assert_eq(parser_result.diagnostics.len, 1);
        assert_eq(parser_result.diagnostics.ptr[0].level, ErrorLevel::WARNING);
        assert_eq(parser_result.diagnostics.ptr[0].message.tag, DiagnosticMessage::Tag::END_IN_METHOD);
        assert_loc(parser_result.diagnostics.ptr[0].loc, Loc(5, 6));

        // comments
        assert_eq(parser_result.comments.len, 1);
        assert_eq(parser_result.comments.ptr[0].kind, CommentType::INLINE);
        assert_loc(parser_result.comments.ptr[0].location, Loc(7, 8));

        // magic comments
        assert_eq(parser_result.magic_comments.len, 1);
        assert_eq(parser_result.magic_comments.ptr[0].kind, MagicCommentKind::ENCODING);
        assert_loc(parser_result.magic_comments.ptr[0].key_l, Loc(9, 10));
        assert_loc(parser_result.magic_comments.ptr[0].value_l, Loc(11, 12));

        // decoded input
        assert_string_eq(parser_result.input.name, "(eval)");
        assert_eq(parser_result.input.lines.len, 1);
        assert_source_line(parser_result.input.lines.ptr[0], 10, 20, false);
        assert_byte_list(parser_result.input.bytes, "2 + 2");
    }

    void run_test_group_parser_result(void);
    void run_test_group_parser_result(void)
    {
        const test_fn_t tests[] = {
            test_parser_result,
        };

        run_tests_as_group("parser_result", tests, sizeof(tests) / sizeof(test_fn_t));
    }
}
