#ifndef LIB_RUBY_PARSER_MAGIC_COMMENT_HPP
#define LIB_RUBY_PARSER_MAGIC_COMMENT_HPP

#include <cstddef>
#include "loc.hpp"

namespace lib_ruby_parser
{
    /// Equivalent of `lib_ruby_parser::source::MagicCommentKind`
    enum class MagicCommentKind
    {
        ENCODING,
        FROZEN_STRING_LITERAL,
        WARN_INDENT,
        SHAREABLE_CONSTANT_VALUE,
    };

    /// Equivalent of `lib_ruby_parser::source::MagicComment`
    class MagicComment
    {
    public:
        MagicCommentKind kind;
        Loc key_l;
        Loc value_l;

        MagicComment() = delete;
        MagicComment(MagicCommentKind kind, Loc key_l, Loc value_l);

        MagicComment(const MagicComment &) = default;
        MagicComment &operator=(MagicComment const &) = default;

        MagicComment(MagicComment &&) = default;
        MagicComment &operator=(MagicComment &&) = default;
    };

    /// Equivalent of `Vec<lib_ruby_parser::source::MagicComment>`
    class MagicCommentList
    {
    public:
        MagicComment *ptr;
        size_t capacity;
        size_t len;

        MagicCommentList() = delete;
        MagicCommentList(MagicComment *ptr, size_t len, size_t capacity);
        ~MagicCommentList();

        MagicCommentList(const MagicCommentList &) = delete;
        MagicCommentList &operator=(MagicCommentList const &) = delete;

        MagicCommentList(MagicCommentList &&);
        MagicCommentList &operator=(MagicCommentList &&);
    };

#ifdef TEST_ENV
    void run_test_group_magic_comment(void);
#endif

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_MAGIC_COMMENT_HPP
