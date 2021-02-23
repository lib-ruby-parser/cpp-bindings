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
        return (kind == other.kind) && (*(key_l.get()) == *(other.key_l.get())) && (*(value_l.get()) == *(other.value_l.get()));
    }

    bool MagicComment::operator!=(const MagicComment &other)
    {
        return !(*this == other);
    }
} // namespace lib_ruby_parser
