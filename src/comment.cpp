#include "comment.h"

namespace lib_ruby_parser
{
    class Loc
    {
    public:
        bool operator==(const Loc &other);
    };

    Comment::Comment(CommentType kind, std::unique_ptr<Loc> location)
    {
        this->kind = kind;
        this->location = std::move(location);
    }

    bool Comment::operator==(const Comment &other)
    {
        return (kind == other.kind) && (*location == *(other.location));
    }

    bool Comment::operator!=(const Comment &other)
    {
        return !(*this == other);
    }
} // namespace lib_ruby_parser
