#include "test_helper.hpp"
#include "../magic_comment.hpp"
#include "../utils.hpp"

namespace lib_ruby_parser
{
#ifndef MAGIC_COMMENT_KIND_HAS_BLOB
#define MAGIC_COMMENT_KIND_HAS_BLOB
    BLOB(MagicCommentKind);
#endif // MAGIC_COMMENT_KIND_HAS_BLOB

#ifndef MAGIC_COMMENT_HAS_BLOB
#define MAGIC_COMMENT_HAS_BLOB
    BLOB(MagicComment);
#endif // MAGIC_COMMENT_HAS_BLOB

#ifndef MAGIC_COMMENT_LIST_HAS_BLOB
#define MAGIC_COMMENT_LIST_HAS_BLOB
    BLOB(MagicCommentList);
#endif // MAGIC_COMMENT_LIST_HAS_BLOB

#ifndef LOC_HAS_BLOB
#define LOC_HAS_BLOB
    BLOB(Loc);
#endif // LOC_HAS_BLOB

    extern "C"
    {
        MagicCommentKindBlob lib_ruby_parser__test__make_magic_comment_kind_encoding(void);
        MagicCommentKindBlob lib_ruby_parser__test__make_magic_comment_kind_frozen_string_literal(void);
        MagicCommentKindBlob lib_ruby_parser__test__make_magic_comment_kind_warn_indent(void);
        MagicCommentKindBlob lib_ruby_parser__test__make_magic_comment_kind_shareable_constant_value(void);
    }
    static void test_magic_comment_kind_options(void)
    {
        annotate_test;

        MagicCommentKind magic_comment_kind;

        magic_comment_kind = from_blob<MagicCommentKindBlob, MagicCommentKind>(
            lib_ruby_parser__test__make_magic_comment_kind_encoding());
        assert_eq(magic_comment_kind, MagicCommentKind::ENCODING);

        magic_comment_kind = from_blob<MagicCommentKindBlob, MagicCommentKind>(
            lib_ruby_parser__test__make_magic_comment_kind_frozen_string_literal());
        assert_eq(magic_comment_kind, MagicCommentKind::FROZEN_STRING_LITERAL);

        magic_comment_kind = from_blob<MagicCommentKindBlob, MagicCommentKind>(
            lib_ruby_parser__test__make_magic_comment_kind_warn_indent());
        assert_eq(magic_comment_kind, MagicCommentKind::WARN_INDENT);

        magic_comment_kind = from_blob<MagicCommentKindBlob, MagicCommentKind>(
            lib_ruby_parser__test__make_magic_comment_kind_shareable_constant_value());
        assert_eq(magic_comment_kind, MagicCommentKind::SHAREABLE_CONSTANT_VALUE);
    }

    extern "C"
    {
        MagicCommentBlob lib_ruby_parser__test__make_magic_comment(MagicCommentKindBlob kind, LocBlob key_l, LocBlob value_l);
    }
    static void test_magic_comment_fields(void)
    {
        annotate_test;

        MagicComment comment = from_blob<MagicCommentBlob, MagicComment>(
            lib_ruby_parser__test__make_magic_comment(
                into_blob<MagicCommentKind, MagicCommentKindBlob>(
                    MagicCommentKind::FROZEN_STRING_LITERAL),
                into_blob<Loc, LocBlob>(
                    Loc(1, 2)),
                into_blob<Loc, LocBlob>(
                    Loc(3, 4))));

        assert_magic_comment(
            comment,
            MagicCommentKind::FROZEN_STRING_LITERAL,
            Loc(1, 2),
            Loc(3, 4));
    }

    extern "C"
    {
        MagicCommentListBlob lib_ruby_parser__test__make_magic_comment_list(MagicCommentBlob magic_comment);
    }
    static void test_magic_comment_list_fields(void)
    {
        annotate_test;

        MagicCommentList magic_comment_list =
            from_blob<MagicCommentListBlob, MagicCommentList>(
                lib_ruby_parser__test__make_magic_comment_list(
                    lib_ruby_parser__test__make_magic_comment(
                        into_blob<MagicCommentKind, MagicCommentKindBlob>(
                            MagicCommentKind::FROZEN_STRING_LITERAL),
                        into_blob<Loc, LocBlob>(
                            Loc(1, 2)),
                        into_blob<Loc, LocBlob>(
                            Loc(3, 4)))));
        assert_eq(magic_comment_list.len, 1);
        assert_magic_comment(
            magic_comment_list.ptr[0],
            MagicCommentKind::FROZEN_STRING_LITERAL,
            Loc(1, 2),
            Loc(3, 4));
    }

    void run_test_group_magic_comment(void);
    void run_test_group_magic_comment(void)
    {
        const test_fn_t tests[] = {
            test_magic_comment_kind_options,
            test_magic_comment_fields,
            test_magic_comment_list_fields,
        };

        run_tests_as_group("magic_comment", tests, sizeof(tests) / sizeof(test_fn_t));
    }
}
