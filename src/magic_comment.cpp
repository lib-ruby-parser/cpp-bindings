#include "magic_comment.h"

namespace lib_ruby_parser
{
    MagicComment::MagicComment(MagicCommentKind kind,
                               std::unique_ptr<Loc> key_l,
                               std::unique_ptr<Loc> value_l)
    {
        this->kind = kind;
        this->key_l = std::move(key_l);
        this->value_l = std::move(value_l);
    }

    bool MagicComment::operator==(const MagicComment &other)
    {
        return (kind == other.kind) && (*key_l == *(other.key_l)) && (*value_l == *(other.value_l));
    }

    bool MagicComment::operator!=(const MagicComment &other)
    {
        return !(*this == other);
    }
} // namespace lib_ruby_parser
