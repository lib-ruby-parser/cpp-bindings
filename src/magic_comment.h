#ifndef LIB_RUBY_PARSER_MAGIC_COMMENT_H
#define LIB_RUBY_PARSER_MAGIC_COMMENT_H

#include <memory>
#include "magic_comment_kind.h"

namespace lib_ruby_parser
{
    class Loc;

    class MagicComment
    {
    public:
        MagicCommentKind kind;
        std::unique_ptr<Loc> key_l;
        std::unique_ptr<Loc> value_l;

        MagicComment() = delete;
        MagicComment(MagicComment &&) = default;
        MagicComment(const MagicComment &) = delete;
        explicit MagicComment(MagicCommentKind kind,
                              std::unique_ptr<Loc> key_l,
                              std::unique_ptr<Loc> value_l);

        bool operator==(const MagicComment &other);
        bool operator!=(const MagicComment &other);
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_MAGIC_COMMENT_H
