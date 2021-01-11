#include "comment.h"

namespace lib_ruby_parser
{
    Comment::Comment(CommentType kind, std::unique_ptr<Range> location)
    {
        this->kind = kind;
        this->location = std::move(location);
    }

    extern "C"
    {
        Comment *make_comment(CommentType kind, Range *location)
        {
            return new Comment(kind, std::unique_ptr<Range>(location));
        }
    }
} // namespace lib_ruby_parser
