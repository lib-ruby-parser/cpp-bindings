#include "test_helper.hpp"
#include "../token.hpp"
#include <cstring>
#include <cstdlib>
#include <iostream>

namespace lib_ruby_parser
{
    BLOB(Loc);
    BLOB(Token);
    BLOB(TokenList);

    extern "C"
    {
        TokenBlob lib_ruby_parser__test__make_token_eq(
            LocBlob loc,
            uint32_t lex_state_before,
            uint32_t lex_state_after);
    }
    static void test_token_fields(void)
    {
        annotate_test;

        Token token = from_blob<TokenBlob, Token>(
            lib_ruby_parser__test__make_token_eq(
                into_blob<Loc, LocBlob>(Loc(1, 2)),
                3,
                4));

        assert_eq(token.token_type, LIB_RUBY_PARSER_TOKEN_tEQ);
        assert_token(token, "tEQ");
        assert_byte_list(token.token_value.raw, "=");
        assert_loc(token.loc, Loc(1, 2));
        assert_eq(token.lex_state_before, 3);
        assert_eq(token.lex_state_after, 4);

        Token moved = std::move(token);
    }

    extern "C"
    {
        TokenListBlob lib_ruby_parser__test__make_token_list(TokenBlob token);
    }

    static void test_token_list_fields(void)
    {
        annotate_test;

        TokenList token_list = from_blob<TokenListBlob, TokenList>(
            lib_ruby_parser__test__make_token_list(
                lib_ruby_parser__test__make_token_eq(
                    into_blob<Loc, LocBlob>(Loc(1, 2)),
                    3,
                    4)));
        assert_eq(token_list.len, 1);
        assert_token(token_list.ptr[0], "tEQ");

        TokenList moved = std::move(token_list);
    }

    void run_test_group_token(void)
    {
        const test_fn_t tests[] = {
            test_token_fields,
            test_token_list_fields,
        };

        run_tests_as_group("token", tests, sizeof(tests) / sizeof(test_fn_t));
    }
} // namespace lib_ruby_parser
