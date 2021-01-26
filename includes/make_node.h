#ifndef LIB_RUBY_PARSER_MAKE_NODE_H
#define LIB_RUBY_PARSER_MAKE_NODE_H

#include <cstddef>
#include "bytes.h"
#include "byte_ptr.h"

namespace lib_ruby_parser {

class Node;
class Range;

extern "C" {

struct NodeVec
{
    Node **ptr;
    size_t length;

    NodeVec(Node **ptr, size_t length)
    {
        this->ptr = ptr;
        this->length = length;
    }
};

Node *make_alias(Node * to, Node * from, Range * keyword_l, Range * expression_l);
Node *make_and_asgn(Node * recv, Node * value, Range * operator_l, Range * expression_l);
Node *make_and(Node * lhs, Node * rhs, Range * operator_l, Range * expression_l);
Node *make_arg(BytePtr name, Range * expression_l);
Node *make_args(NodeVec args, Range * expression_l, Range * begin_l, Range * end_l);
Node *make_array(NodeVec elements, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_array_pattern(NodeVec elements, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_array_pattern_with_tail(NodeVec elements, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_back_ref(BytePtr name, Range * expression_l);
Node *make_begin(NodeVec statements, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_block(Node * call, Node * args, Node * body, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_block_pass(Node * value, Range * operator_l, Range * expression_l);
Node *make_blockarg(BytePtr name, Range * operator_l, Range * name_l, Range * expression_l);
Node *make_break_(NodeVec args, Range * keyword_l, Range * expression_l);
Node *make_case(Node * expr, NodeVec when_bodies, Node * else_body, Range * keyword_l, Range * else_l, Range * end_l, Range * expression_l);
Node *make_case_match(Node * expr, NodeVec in_bodies, Node * else_body, Range * keyword_l, Range * else_l, Range * end_l, Range * expression_l);
Node *make_casgn(Node * scope, BytePtr name, Node * value, Range * double_colon_l, Range * name_l, Range * operator_l, Range * expression_l);
Node *make_cbase(Range * expression_l);
Node *make_class(Node * name, Node * superclass, Node * body, Range * keyword_l, Range * operator_l, Range * end_l, Range * expression_l);
Node *make_complex(BytePtr value, Range * operator_l, Range * expression_l);
Node *make_const_(Node * scope, BytePtr name, Range * double_colon_l, Range * name_l, Range * expression_l);
Node *make_const_pattern(Node * const_, Node * pattern, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_csend(Node * recv, BytePtr method_name, NodeVec args, Range * dot_l, Range * selector_l, Range * begin_l, Range * end_l, Range * operator_l, Range * expression_l);
Node *make_cvar(BytePtr name, Range * expression_l);
Node *make_cvasgn(BytePtr name, Node * value, Range * name_l, Range * operator_l, Range * expression_l);
Node *make_def(BytePtr name, Node * args, Node * body, Range * keyword_l, Range * name_l, Range * end_l, Range * assignment_l, Range * expression_l);
Node *make_defined(Node * value, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_defs(Node * definee, BytePtr name, Node * args, Node * body, Range * keyword_l, Range * operator_l, Range * name_l, Range * assignment_l, Range * end_l, Range * expression_l);
Node *make_dstr(NodeVec parts, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_dsym(NodeVec parts, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_eflipflop(Node * left, Node * right, Range * operator_l, Range * expression_l);
Node *make_empty_else(Range * expression_l);
Node *make_encoding_(Range * expression_l);
Node *make_ensure(Node * body, Node * ensure, Range * keyword_l, Range * expression_l);
Node *make_erange(Node * left, Node * right, Range * operator_l, Range * expression_l);
Node *make_false_(Range * expression_l);
Node *make_file(Range * expression_l);
Node *make_find_pattern(NodeVec elements, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_float(BytePtr value, Range * operator_l, Range * expression_l);
Node *make_for_(Node * iterator, Node * iteratee, Node * body, Range * keyword_l, Range * operator_l, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_forward_arg(Range * expression_l);
Node *make_forwarded_args(Range * expression_l);
Node *make_gvar(BytePtr name, Range * expression_l);
Node *make_gvasgn(BytePtr name, Node * value, Range * name_l, Range * operator_l, Range * expression_l);
Node *make_hash(NodeVec pairs, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_kwargs(NodeVec pairs, Range * expression_l);
Node *make_hash_pattern(NodeVec elements, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_heredoc(NodeVec parts, Range * heredoc_body_l, Range * heredoc_end_l, Range * expression_l);
Node *make_if_(Node * cond, Node * if_true, Node * if_false, Range * keyword_l, Range * begin_l, Range * else_l, Range * end_l, Range * expression_l);
Node *make_if_guard(Node * cond, Range * keyword_l, Range * expression_l);
Node *make_if_mod(Node * cond, Node * if_true, Node * if_false, Range * keyword_l, Range * expression_l);
Node *make_if_ternary(Node * cond, Node * if_true, Node * if_false, Range * question_l, Range * colon_l, Range * expression_l);
Node *make_iflipflop(Node * left, Node * right, Range * operator_l, Range * expression_l);
Node *make_match_pattern(Node * value, Node * pattern, Range * operator_l, Range * expression_l);
Node *make_match_pattern_p(Node * value, Node * pattern, Range * operator_l, Range * expression_l);
Node *make_in_pattern(Node * pattern, Node * guard, Node * body, Range * keyword_l, Range * begin_l, Range * expression_l);
Node *make_index(Node * recv, NodeVec indexes, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_index_asgn(Node * recv, NodeVec indexes, Node * value, Range * begin_l, Range * end_l, Range * operator_l, Range * expression_l);
Node *make_int(BytePtr value, Range * operator_l, Range * expression_l);
Node *make_irange(Node * left, Node * right, Range * operator_l, Range * expression_l);
Node *make_ivar(BytePtr name, Range * expression_l);
Node *make_ivasgn(BytePtr name, Node * value, Range * name_l, Range * operator_l, Range * expression_l);
Node *make_kwarg(BytePtr name, Range * name_l, Range * expression_l);
Node *make_kwbegin(NodeVec statements, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_kwnilarg(Range * name_l, Range * expression_l);
Node *make_kwoptarg(BytePtr name, Node * default_, Range * name_l, Range * expression_l);
Node *make_kwrestarg(BytePtr name, Range * operator_l, Range * name_l, Range * expression_l);
Node *make_kwsplat(Node * value, Range * operator_l, Range * expression_l);
Node *make_lambda(Range * expression_l);
Node *make_line(Range * expression_l);
Node *make_lvar(BytePtr name, Range * expression_l);
Node *make_lvasgn(BytePtr name, Node * value, Range * name_l, Range * operator_l, Range * expression_l);
Node *make_masgn(Node * lhs, Node * rhs, Range * operator_l, Range * expression_l);
Node *make_match_alt(Node * lhs, Node * rhs, Range * operator_l, Range * expression_l);
Node *make_match_as(Node * value, Node * as_, Range * operator_l, Range * expression_l);
Node *make_match_current_line(Node * re, Range * expression_l);
Node *make_match_nil_pattern(Range * operator_l, Range * name_l, Range * expression_l);
Node *make_match_rest(Node * name, Range * operator_l, Range * expression_l);
Node *make_match_var(BytePtr name, Range * name_l, Range * expression_l);
Node *make_match_with_lvasgn(Node * re, Node * value, Range * operator_l, Range * expression_l);
Node *make_mlhs(NodeVec items, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_module(Node * name, Node * body, Range * keyword_l, Range * end_l, Range * expression_l);
Node *make_next(NodeVec args, Range * keyword_l, Range * expression_l);
Node *make_nil(Range * expression_l);
Node *make_nth_ref(BytePtr name, Range * expression_l);
Node *make_numblock(Node * call, size_t  numargs, Node * body, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_op_asgn(Node * recv, BytePtr operator_, Node * value, Range * operator_l, Range * expression_l);
Node *make_optarg(BytePtr name, Node * default_, Range * name_l, Range * operator_l, Range * expression_l);
Node *make_or(Node * lhs, Node * rhs, Range * operator_l, Range * expression_l);
Node *make_or_asgn(Node * recv, Node * value, Range * operator_l, Range * expression_l);
Node *make_pair(Node * key, Node * value, Range * operator_l, Range * expression_l);
Node *make_pin(Node * var, Range * selector_l, Range * expression_l);
Node *make_postexe(Node * body, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_preexe(Node * body, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_procarg0(NodeVec args, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_rational(BytePtr value, Range * operator_l, Range * expression_l);
Node *make_redo(Range * expression_l);
Node *make_reg_opt(BytePtr options, Range * expression_l);
Node *make_regexp(NodeVec parts, Node * options, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_rescue(Node * body, NodeVec rescue_bodies, Node * else_, Range * else_l, Range * expression_l);
Node *make_rescue_body(Node * exc_list, Node * exc_var, Node * body, Range * keyword_l, Range * assoc_l, Range * begin_l, Range * expression_l);
Node *make_restarg(BytePtr name, Range * operator_l, Range * name_l, Range * expression_l);
Node *make_retry(Range * expression_l);
Node *make_return_(NodeVec args, Range * keyword_l, Range * expression_l);
Node *make_sclass(Node * expr, Node * body, Range * keyword_l, Range * operator_l, Range * end_l, Range * expression_l);
Node *make_self_(Range * expression_l);
Node *make_send(Node * recv, BytePtr method_name, NodeVec args, Range * dot_l, Range * selector_l, Range * begin_l, Range * end_l, Range * operator_l, Range * expression_l);
Node *make_shadowarg(BytePtr name, Range * expression_l);
Node *make_splat(Node * value, Range * operator_l, Range * expression_l);
Node *make_str_(BytePtr value, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_super_(NodeVec args, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_sym(BytePtr name, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_true_(Range * expression_l);
Node *make_undef(NodeVec names, Range * keyword_l, Range * expression_l);
Node *make_unless_guard(Node * cond, Range * keyword_l, Range * expression_l);
Node *make_until(Node * cond, Node * body, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_until_post(Node * cond, Node * body, Range * keyword_l, Range * expression_l);
Node *make_when(NodeVec patterns, Node * body, Range * keyword_l, Range * begin_l, Range * expression_l);
Node *make_while_(Node * cond, Node * body, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_while_post(Node * cond, Node * body, Range * keyword_l, Range * expression_l);
Node *make_x_heredoc(NodeVec parts, Range * heredoc_body_l, Range * heredoc_end_l, Range * expression_l);
Node *make_xstr(NodeVec parts, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_yield_(NodeVec args, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l);
Node *make_zsuper(Range * expression_l);

}
}

#endif // LIB_RUBY_PARSER_MAKE_NODE_H