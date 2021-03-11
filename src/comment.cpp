#include "comment.h"

namespace lib_ruby_parser
{
    Comment::Comment(CommentType kind, std::unique_ptr<Loc> location) : kind(kind),
                                                                        location(std::move(location)) {}
    bool Comment::operator==(const Comment &other)
    {
        return (kind == other.kind) && (*location == *(other.location));
    }

    bool Comment::operator!=(const Comment &other)
    {
        return !(*this == other);
    }
} // namespace lib_ruby_parser
