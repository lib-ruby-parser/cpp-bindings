#ifndef LIB_RUBY_PARSER_MAGIC_COMMENT_H
#define LIB_RUBY_PARSER_MAGIC_COMMENT_H

#include <memory>
#include "range.h"

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
                              std::unique_ptr<Range> value_l);

        bool operator==(const MagicComment &other);
        bool operator!=(const MagicComment &other);
    };

    extern "C"
    {
        MagicComment *make_magic_comment(MagicCommentKind kind, Range *key_l, Range *value_l);
    }
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_MAGIC_COMMENT_H
