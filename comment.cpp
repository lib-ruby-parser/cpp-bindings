#include "utils.hpp"

#include "comment.hpp"

namespace lib_ruby_parser
{
    BLOB(Loc);
    BLOB(CommentType);
    BLOB(Comment);
    BLOB(CommentList);

    Comment::Comment(Loc location_,
                     CommentType kind_) : location(location_),
                                          kind(kind_) {}

    LIST_IMPL(CommentList, Comment, LIB_RUBY_PARSER_drop_comment_list);
} // namespace lib_ruby_parser

#ifdef TEST_ENV

#include "test_helper.hpp"

namespace lib_ruby_parser
{
    extern "C"
    {
        CommentType lib_ruby_parser__test__make_comment_type_document(void);
        CommentType lib_ruby_parser__test__make_comment_type_inline(void);
        CommentType lib_ruby_parser__test__make_comment_type_unknown(void);
    }
    static void test_comment_type_options(void)
    {
        annotate_test;

        CommentType comment_type;

        comment_type = lib_ruby_parser__test__make_comment_type_document();
        assert_eq(comment_type, CommentType::DOCUMENT);

        comment_type = lib_ruby_parser__test__make_comment_type_inline();
        assert_eq(comment_type, CommentType::INLINE);

        comment_type = lib_ruby_parser__test__make_comment_type_unknown();
        assert_eq(comment_type, CommentType::UNKNOWN);
    }

    extern "C"
    {
        CommentBlob lib_ruby_parser__test__make_comment(LocBlob location, CommentTypeBlob kind);
    }
    static void test_comment_fields(void)
    {
        annotate_test;

        Comment comment = from_blob<CommentBlob, Comment>(
            lib_ruby_parser__test__make_comment(
                into_blob<Loc, LocBlob>(Loc(1, 2)),
                into_blob<CommentType, CommentTypeBlob>(CommentType::INLINE)));

        assert_comment(comment, Loc(1, 2), CommentType::INLINE);
    }

    extern "C"
    {
        CommentListBlob lib_ruby_parser__test__make_comment_list(CommentBlob comment);
    }
    static void test_comment_list_fields(void)
    {
        annotate_test;

        CommentList comment_list = from_blob<CommentListBlob, CommentList>(
            lib_ruby_parser__test__make_comment_list(
                lib_ruby_parser__test__make_comment(
                    into_blob<Loc, LocBlob>(Loc(1, 2)),
                    into_blob<CommentType, CommentTypeBlob>(CommentType::INLINE))));
        assert_eq(comment_list.len, 1);
        assert_comment(comment_list.ptr[0], Loc(1, 2), CommentType::INLINE);
    }

    void run_test_group_comment(void)
    {
        const test_fn_t tests[] = {
            test_comment_type_options,
            test_comment_fields,
            test_comment_list_fields,
        };

        run_tests_as_group("comment", tests, sizeof(tests) / sizeof(test_fn_t));
    }
}

#endif
