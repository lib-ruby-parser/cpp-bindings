#include "comment.h"

namespace lib_ruby_parser
{
    class Loc
    {
    public:
        bool operator==(const Loc &other);
    };

    bool Comment::operator==(const Comment &other)
    {
        return (kind == other.kind) && (*location == *(other.location));
    }

    bool Comment::operator!=(const Comment &other)
    {
        return !(*this == other);
    }
} // namespace lib_ruby_parser
