#ifndef LIB_RUBY_PARSER_COMMENT_H
#define LIB_RUBY_PARSER_COMMENT_H

#include <memory>
#include "range.h"

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

        bool operator==(const Comment &other);
        bool operator!=(const Comment &other);
    };

    extern "C"
    {
        Comment *make_comment(CommentType kind, Range *location);
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_COMMENT_H
