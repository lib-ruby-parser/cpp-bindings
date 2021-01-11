#ifndef LIB_RUBY_PARSER_COMMENT_H
#define LIB_RUBY_PARSER_COMMENT_H

#include "range.h"
#include "helpers.h"

namespace lib_ruby_parser
{
    enum CommentType
    {
        INLINE,
        DOCUMENT,
        UNKNOWN
    };

    class Comment
    {
    public:
        CommentType kind;
        std::unique_ptr<Range> location;

        Comment() = delete;
        Comment(Comment &&) = default;
        Comment(const Comment &) = delete;
        explicit Comment(CommentType kind, std::unique_ptr<Range> location);

        inline bool operator==(const Comment &other)
        {
            return (kind == other.kind) && (*(location.get()) == *(other.location.get()));
        }

        inline bool operator!=(const Comment &other)
        {
            return !(*this == other);
        }
    };

    extern "C"
    {
        Comment *make_comment(CommentType kind, Range *location);
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_COMMENT_H
