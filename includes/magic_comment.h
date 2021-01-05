#ifndef LIB_RUBY_PARSER_MAGIC_COMMENT_H
#define LIB_RUBY_PARSER_MAGIC_COMMENT_H

#include "range.h"
#include "helpers.h"

namespace lib_ruby_parser
{
    enum MagicCommentKind
    {
        ENCODING,
        FROZEN_STRING_LITERAL,
        WARN_INDENT,
        SHAREABLE_CONSTANT_VALUE,
    };

    class MagicComment
    {
    public:
        MagicCommentKind kind;
        std::unique_ptr<Range> key_l;
        std::unique_ptr<Range> value_l;

        MagicComment() = delete;
        MagicComment(MagicComment &&) = default;
        MagicComment(const MagicComment &) = delete;
        explicit MagicComment(MagicCommentKind kind,
                              std::unique_ptr<Range> key_l,
                              std::unique_ptr<Range> value_l) : kind(kind), key_l(std::move(key_l)), value_l(std::move(value_l)) {}

        inline bool operator==(const MagicComment &other)
        {
            return (kind == other.kind) && (*(key_l.get()) == *(other.key_l.get())) && (*(value_l.get()) == *(other.value_l.get()));
        }

        inline bool operator!=(const MagicComment &other)
        {
            return !(*this == other);
        }
    };

    extern "C"
    {
        MagicComment *make_magic_comment(MagicCommentKind kind, Range *key_l, Range *value_l)
        {
            return new MagicComment(kind, std::unique_ptr<Range>(key_l), std::unique_ptr<Range>(value_l));
        }
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_MAGIC_COMMENT_H
