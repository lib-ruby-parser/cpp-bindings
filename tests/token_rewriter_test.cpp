#include "test_helper.hpp"
#include "../token_rewriter.hpp"
#include "../utils.hpp"
#include <cstring>
#include <cstdlib>

namespace lib_ruby_parser
{
#ifndef REWRITE_ACTION_HAS_BLOB
#define REWRITE_ACTION_HAS_BLOB
    BLOB(RewriteAction);
#endif // REWRITE_ACTION_HAS_BLOB

#ifndef LEX_STATE_HAS_BLOB
#define LEX_STATE_HAS_BLOB
    BLOB(LexStateAction);
#endif // LEX_STATE_HAS_BLOB

#ifndef TOKEN_REWRITER_RESULT_HAS_BLOB
#define TOKEN_REWRITER_RESULT_HAS_BLOB
    BLOB(TokenRewriterResult);
#endif // TOKEN_REWRITER_RESULT_HAS_BLOB

#ifndef TOKEN_REWRITER_HAS_BLOB
#define TOKEN_REWRITER_HAS_BLOB
    BLOB(TokenRewriter);
#endif // TOKEN_REWRITER_HAS_BLOB

#ifndef MAYBE_TOKEN_REWRITER_RESULT_HAS_BLOB
#define MAYBE_TOKEN_REWRITER_RESULT_HAS_BLOB
    BLOB(MaybeTokenRewriter);
#endif // MAYBE_TOKEN_REWRITER_RESULT_HAS_BLOB

    extern "C"
    {
        RewriteActionBlob lib_ruby_parser__test__make_rewrite_action__drop(void);
        RewriteActionBlob lib_ruby_parser__test__make_rewrite_action__keep(void);
    }
    static void test_rewriter_action(void)
    {
        annotate_test;

        RewriteAction rewrite_action;

        rewrite_action = from_blob<RewriteActionBlob, RewriteAction>(
            lib_ruby_parser__test__make_rewrite_action__drop());
        assert_eq(rewrite_action, RewriteAction::DROP);

        rewrite_action = from_blob<RewriteActionBlob, RewriteAction>(
            lib_ruby_parser__test__make_rewrite_action__keep());
        assert_eq(rewrite_action, RewriteAction::KEEP);
    }

    extern "C"
    {
        LexStateActionBlob lib_ruby_parser__test__make_lex_state_action__set(int32_t next_state);
        LexStateActionBlob lib_ruby_parser__test__make_lex_state_action__keep(void);
    }
    static void test_lex_state_action(void)
    {
        annotate_test;

        LexStateAction set_42 = from_blob<LexStateActionBlob, LexStateAction>(
            lib_ruby_parser__test__make_lex_state_action__set(42));
        assert_eq(set_42.tag, LexStateAction::Tag::SET);
        assert_eq(set_42.as.set, 42);

        LexStateAction keep = from_blob<LexStateActionBlob, LexStateAction>(
            lib_ruby_parser__test__make_lex_state_action__keep());
        assert_eq(keep.tag, LexStateAction::Tag::KEEP);
    }

    extern "C"
    {
        TokenRewriterResultBlob lib_ruby_parser__test__make_token_rewriter_result(void);
    }
    static void test_token_rewriter_result(void)
    {
        annotate_test;

        TokenRewriterResult result = from_blob<TokenRewriterResultBlob, TokenRewriterResult>(
            lib_ruby_parser__test__make_token_rewriter_result());
        assert_token(*(result.rewritten_token), "kDEF");
        assert_eq(result.token_action, RewriteAction::KEEP);
        assert_eq(result.lex_state_action.tag, LexStateAction::Tag::SET);
        assert_eq(result.lex_state_action.as.set, 17);
    }

    extern "C"
    {
        TokenRewriterBlob lib_ruby_parser__test__always_keep_token_rewriter(void);
        TokenRewriterBlob lib_ruby_parser__test__always_rewrite_token_rewriter(void);
    }
    static void test_token_rewriter(void)
    {
        annotate_test;

        const char *INPUT = "foo";
        SharedByteList input(INPUT, strlen(INPUT));

        {
            TokenRewriter token_rewriter = from_blob<TokenRewriterBlob, TokenRewriter>(
                lib_ruby_parser__test__always_keep_token_rewriter());

            Token *token = new Token(
                LIB_RUBY_PARSER_TOKEN_tPLUS,
                Bytes(ByteList(nullptr, 0, 0)),
                Loc(0, 0),
                0,
                0);
            TokenRewriterResult result = (token_rewriter.f)(token, input);
            assert_token(*(result.rewritten_token), "tPLUS");
        }

        {
            TokenRewriter token_rewriter = from_blob<TokenRewriterBlob, TokenRewriter>(
                lib_ruby_parser__test__always_rewrite_token_rewriter());
            Token *token = new Token(
                LIB_RUBY_PARSER_TOKEN_tPLUS,
                Bytes(ByteList(nullptr, 0, 0)),
                Loc(0, 0),
                0,
                0);
            TokenRewriterResult result = (token_rewriter.f)(token, input);
            assert_token(*(result.rewritten_token), "tMINUS");
        }
    }

    extern "C"
    {
        MaybeTokenRewriterBlob lib_ruby_parser__test__some_always_keep_token_rewriter(void);
        MaybeTokenRewriterBlob lib_ruby_parser__test__none_token_rewriter(void);
    }
    static void test_maybe_token_rewriter(void)
    {
        annotate_test;

        TokenRewriter always_keep_token_rewriter = from_blob<TokenRewriterBlob, TokenRewriter>(
            lib_ruby_parser__test__always_keep_token_rewriter());

        {
            MaybeTokenRewriter some = from_blob<MaybeTokenRewriterBlob, MaybeTokenRewriter>(
                lib_ruby_parser__test__some_always_keep_token_rewriter());
            assert(some.is_some());
            assert_eq(some.token_rewriter.f, always_keep_token_rewriter.f);
        }

        {
            MaybeTokenRewriter none = from_blob<MaybeTokenRewriterBlob, MaybeTokenRewriter>(
                lib_ruby_parser__test__none_token_rewriter());
            assert(none.is_none());
        }
    }

    void run_test_group_token_rewriter(void);
    void run_test_group_token_rewriter(void)
    {
        const test_fn_t tests[] = {
            test_rewriter_action,
            test_lex_state_action,
            test_token_rewriter_result,
            test_token_rewriter,
            test_maybe_token_rewriter,
        };

        run_tests_as_group("token_rewriter", tests, sizeof(tests) / sizeof(test_fn_t));
    }

}
