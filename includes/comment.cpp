#include "comment.h"

namespace lib_ruby_parser
{
    Comment::Comment(CommentType kind, std::unique_ptr<Range> location)
    {
        this->kind = kind;
        this->location = std::move(location);
    }

    bool Comment::operator==(const Comment &other)
    {
        return (kind == other.kind) && (*(location.get()) == *(other.location.get()));
    }

    bool Comment::operator!=(const Comment &other)
    {
        return !(*this == other);
    }

    extern "C"
    {
        Comment *make_comment(CommentType kind, Range *location)
        {
            return new Comment(kind, std::unique_ptr<Range>(location));
        }
    }
} // namespace lib_ruby_parser
