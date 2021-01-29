#ifndef LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_H
#define LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_H

namespace lib_ruby_parser
{
    enum class MagicCommentKind
    {
        ENCODING,
        FROZEN_STRING_LITERAL,
        WARN_INDENT,
        SHAREABLE_CONSTANT_VALUE,
    };
}

#endif // LIB_RUBY_PARSER_MAGIC_COMMENT_KIND_H
