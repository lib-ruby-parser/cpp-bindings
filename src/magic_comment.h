#ifndef LIB_RUBY_PARSER_MAGIC_COMMENT_H
#define LIB_RUBY_PARSER_MAGIC_COMMENT_H

#include <memory>
#include "magic_comment_kind.h"
#include "loc.h"

namespace lib_ruby_parser
{
    // Representation of the magic comment (i.e. a special comment at the top of the file)
    class MagicComment
    {
    public:
        // Kind of the magic comment
        MagicCommentKind kind;

        // Location of the key
        //
        // "# encoding: foo"
        //    ~~~~~~~~
        std::unique_ptr<Loc> key_l;

        // Location of the value
        //
        // "# encoding: foo"
        //              ~~~
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
