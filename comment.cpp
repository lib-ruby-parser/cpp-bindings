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
} // namespace lib_ruby_parser
