#include "test_helper.hpp"
#include "../api.hpp"

namespace lib_ruby_parser
{
    static void test_parse(void)
    {
        annotate_test;

        ParserOptions options(
            String::Copied("(eval)"),
            MaybeDecoder(Decoder(nullptr, nullptr)),
            MaybeTokenRewriter(TokenRewriter(nullptr)),
            true);

        ByteList input = ByteList::Copied("2 + 3", 5);

        ParserResult result = parse(
            std::move(input),
            std::move(options));

        assert_eq(result.ast->tag, Node::Tag::SEND);
        assert_eq(result.tokens.len, 4); // tINT tPLUS tINT EOF
        assert_eq(result.comments.len, 0);
        assert_eq(result.magic_comments.len, 0);
        assert_byte_list(result.input.bytes, "2 + 3");
    }

    void run_test_group_api(void)
    {
        const test_fn_t tests[] = {
            test_parse,
        };

        run_tests_as_group("api", tests, sizeof(tests) / sizeof(test_fn_t));
    }
}
