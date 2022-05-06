#include "utils.hpp"

#include "comment.hpp"

namespace lib_ruby_parser
{
    BLOB(Loc);
    BLOB(CommentType);
    BLOB(Comment);
    BLOB(CommentList);

    Comment::Comment(Loc location_,
                     CommentType kind_) : location(location_),
                                          kind(kind_) {}

    LIST_IMPL(CommentList, Comment, LIB_RUBY_PARSER_drop_comment_list);
} // namespace lib_ruby_parser
