#include "magic_comment.hpp"
#include "utils.hpp"

namespace lib_ruby_parser
{
    MagicComment::MagicComment(MagicCommentKind kind_,
                               Loc key_l_, Loc value_l_) : kind(kind_),
                                                           key_l(key_l_),
                                                           value_l(value_l_) {}

    LIST_IMPL(MagicCommentList, MagicComment, LIB_RUBY_PARSER_drop_magic_comment_list);
} // namespace lib_ruby_parser
