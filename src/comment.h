#ifndef LIB_RUBY_PARSER_COMMENT_H
#define LIB_RUBY_PARSER_COMMENT_H

#include <memory>
#include "comment_type.h"

namespace lib_ruby_parser
{
    class Loc;

    class Comment
    {
    public:
        CommentType kind;
        std::unique_ptr<Loc> location;

        Comment() = delete;
        Comment(Comment &&) = default;
        Comment(const Comment &) = delete;
        explicit Comment(CommentType kind, std::unique_ptr<Loc> location);

        bool operator==(const Comment &other);
        bool operator!=(const Comment &other);
    };
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_COMMENT_H
