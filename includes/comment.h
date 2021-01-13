#ifndef LIB_RUBY_PARSER_COMMENT_H
#define LIB_RUBY_PARSER_COMMENT_H

#include <memory>
#include "range.h"
#include "comment_type.h"

namespace lib_ruby_parser
{
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
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_COMMENT_H
