#ifndef LIB_RUBY_PARSER_COMMENT_HPP
#define LIB_RUBY_PARSER_COMMENT_HPP

#include <cstddef>
#include "loc.hpp"

namespace lib_ruby_parser
{
    /// Equivalent of `lib_ruby_parser::source::CommentType`
    enum class CommentType
    {
        INLINE,
        DOCUMENT,
        UNKNOWN,
    };

    /// Equivalent of `lib_ruby_parser::source::Comment`
    class Comment
    {
    public:
        /// Location of the comment
        Loc location;

        /// Kind of the comment (inline/document/unknown)
        CommentType kind;

        Comment() = delete;
        Comment(Loc location, CommentType kind);

        Comment(const Comment &) = default;
        Comment &operator=(Comment const &) = default;

        Comment(Comment &&) = default;
        Comment &operator=(Comment &&) = default;
    };

    /// Equivalent of `Vec<lib_ruby_parser::source::Comment>`
    class CommentList
    {
    public:
        Comment *ptr;
        size_t capacity;
        size_t len;

        CommentList() = delete;
        CommentList(Comment *ptr, size_t len, size_t capacity);
        ~CommentList();

        CommentList(const CommentList &) = delete;
        CommentList &operator=(CommentList const &) = delete;

        CommentList(CommentList &&);
        CommentList &operator=(CommentList &&);
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_COMMENT_HPP
