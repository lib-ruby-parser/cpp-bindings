#ifndef LIB_RUBY_PARSER_MAKE_NODE_H
#define LIB_RUBY_PARSER_MAKE_NODE_H

#include <stdint.h>
#include "byte_ptr.h"

namespace lib_ruby_parser {

class Node;
class Loc;

extern "C" {

struct NodeVec
{
    Node **ptr;
    uint32_t length;

    NodeVec(Node **ptr, uint32_t length)
    {
        this->ptr = ptr;
        this->length = length;
    }
};

Node *make_alias(Node * to, Node * from, Loc * keyword_l, Loc * expression_l);
Node *make_and_asgn(Node * recv, Node * value, Loc * operator_l, Loc * expression_l);
Node *make_and(Node * lhs, Node * rhs, Loc * operator_l, Loc * expression_l);
Node *make_arg(BytePtr name, Loc * expression_l);
Node *make_args(NodeVec args, Loc * expression_l, Loc * begin_l, Loc * end_l);
Node *make_array(NodeVec elements, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_array_pattern(NodeVec elements, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_array_pattern_with_tail(NodeVec elements, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_back_ref(BytePtr name, Loc * expression_l);
Node *make_begin(NodeVec statements, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_block(Node * call, Node * args, Node * body, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_block_pass(Node * value, Loc * operator_l, Loc * expression_l);
Node *make_blockarg(BytePtr name, Loc * operator_l, Loc * name_l, Loc * expression_l);
Node *make_break_(NodeVec args, Loc * keyword_l, Loc * expression_l);
Node *make_case(Node * expr, NodeVec when_bodies, Node * else_body, Loc * keyword_l, Loc * else_l, Loc * end_l, Loc * expression_l);
Node *make_case_match(Node * expr, NodeVec in_bodies, Node * else_body, Loc * keyword_l, Loc * else_l, Loc * end_l, Loc * expression_l);
Node *make_casgn(Node * scope, BytePtr name, Node * value, Loc * double_colon_l, Loc * name_l, Loc * operator_l, Loc * expression_l);
Node *make_cbase(Loc * expression_l);
Node *make_class(Node * name, Node * superclass, Node * body, Loc * keyword_l, Loc * operator_l, Loc * end_l, Loc * expression_l);
Node *make_complex(BytePtr value, Loc * operator_l, Loc * expression_l);
Node *make_const_(Node * scope, BytePtr name, Loc * double_colon_l, Loc * name_l, Loc * expression_l);
Node *make_const_pattern(Node * const_, Node * pattern, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_csend(Node * recv, BytePtr method_name, NodeVec args, Loc * dot_l, Loc * selector_l, Loc * begin_l, Loc * end_l, Loc * operator_l, Loc * expression_l);
Node *make_cvar(BytePtr name, Loc * expression_l);
Node *make_cvasgn(BytePtr name, Node * value, Loc * name_l, Loc * operator_l, Loc * expression_l);
Node *make_def(BytePtr name, Node * args, Node * body, Loc * keyword_l, Loc * name_l, Loc * end_l, Loc * assignment_l, Loc * expression_l);
Node *make_defined(Node * value, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_defs(Node * definee, BytePtr name, Node * args, Node * body, Loc * keyword_l, Loc * operator_l, Loc * name_l, Loc * assignment_l, Loc * end_l, Loc * expression_l);
Node *make_dstr(NodeVec parts, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_dsym(NodeVec parts, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_eflipflop(Node * left, Node * right, Loc * operator_l, Loc * expression_l);
Node *make_empty_else(Loc * expression_l);
Node *make_encoding_(Loc * expression_l);
Node *make_ensure(Node * body, Node * ensure, Loc * keyword_l, Loc * expression_l);
Node *make_erange(Node * left, Node * right, Loc * operator_l, Loc * expression_l);
Node *make_false_(Loc * expression_l);
Node *make_file(Loc * expression_l);
Node *make_find_pattern(NodeVec elements, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_float(BytePtr value, Loc * operator_l, Loc * expression_l);
Node *make_for_(Node * iterator, Node * iteratee, Node * body, Loc * keyword_l, Loc * operator_l, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_forward_arg(Loc * expression_l);
Node *make_forwarded_args(Loc * expression_l);
Node *make_gvar(BytePtr name, Loc * expression_l);
Node *make_gvasgn(BytePtr name, Node * value, Loc * name_l, Loc * operator_l, Loc * expression_l);
Node *make_hash(NodeVec pairs, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_kwargs(NodeVec pairs, Loc * expression_l);
Node *make_hash_pattern(NodeVec elements, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_heredoc(NodeVec parts, Loc * heredoc_body_l, Loc * heredoc_end_l, Loc * expression_l);
Node *make_if_(Node * cond, Node * if_true, Node * if_false, Loc * keyword_l, Loc * begin_l, Loc * else_l, Loc * end_l, Loc * expression_l);
Node *make_if_guard(Node * cond, Loc * keyword_l, Loc * expression_l);
Node *make_if_mod(Node * cond, Node * if_true, Node * if_false, Loc * keyword_l, Loc * expression_l);
Node *make_if_ternary(Node * cond, Node * if_true, Node * if_false, Loc * question_l, Loc * colon_l, Loc * expression_l);
Node *make_iflipflop(Node * left, Node * right, Loc * operator_l, Loc * expression_l);
Node *make_match_pattern(Node * value, Node * pattern, Loc * operator_l, Loc * expression_l);
Node *make_match_pattern_p(Node * value, Node * pattern, Loc * operator_l, Loc * expression_l);
Node *make_in_pattern(Node * pattern, Node * guard, Node * body, Loc * keyword_l, Loc * begin_l, Loc * expression_l);
Node *make_index(Node * recv, NodeVec indexes, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_index_asgn(Node * recv, NodeVec indexes, Node * value, Loc * begin_l, Loc * end_l, Loc * operator_l, Loc * expression_l);
Node *make_int(BytePtr value, Loc * operator_l, Loc * expression_l);
Node *make_irange(Node * left, Node * right, Loc * operator_l, Loc * expression_l);
Node *make_ivar(BytePtr name, Loc * expression_l);
Node *make_ivasgn(BytePtr name, Node * value, Loc * name_l, Loc * operator_l, Loc * expression_l);
Node *make_kwarg(BytePtr name, Loc * name_l, Loc * expression_l);
Node *make_kwbegin(NodeVec statements, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_kwnilarg(Loc * name_l, Loc * expression_l);
Node *make_kwoptarg(BytePtr name, Node * default_, Loc * name_l, Loc * expression_l);
Node *make_kwrestarg(BytePtr name, Loc * operator_l, Loc * name_l, Loc * expression_l);
Node *make_kwsplat(Node * value, Loc * operator_l, Loc * expression_l);
Node *make_lambda(Loc * expression_l);
Node *make_line(Loc * expression_l);
Node *make_lvar(BytePtr name, Loc * expression_l);
Node *make_lvasgn(BytePtr name, Node * value, Loc * name_l, Loc * operator_l, Loc * expression_l);
Node *make_masgn(Node * lhs, Node * rhs, Loc * operator_l, Loc * expression_l);
Node *make_match_alt(Node * lhs, Node * rhs, Loc * operator_l, Loc * expression_l);
Node *make_match_as(Node * value, Node * as_, Loc * operator_l, Loc * expression_l);
Node *make_match_current_line(Node * re, Loc * expression_l);
Node *make_match_nil_pattern(Loc * operator_l, Loc * name_l, Loc * expression_l);
Node *make_match_rest(Node * name, Loc * operator_l, Loc * expression_l);
Node *make_match_var(BytePtr name, Loc * name_l, Loc * expression_l);
Node *make_match_with_lvasgn(Node * re, Node * value, Loc * operator_l, Loc * expression_l);
Node *make_mlhs(NodeVec items, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_module(Node * name, Node * body, Loc * keyword_l, Loc * end_l, Loc * expression_l);
Node *make_next(NodeVec args, Loc * keyword_l, Loc * expression_l);
Node *make_nil(Loc * expression_l);
Node *make_nth_ref(BytePtr name, Loc * expression_l);
Node *make_numblock(Node * call, uint32_t  numargs, Node * body, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_op_asgn(Node * recv, BytePtr operator_, Node * value, Loc * operator_l, Loc * expression_l);
Node *make_optarg(BytePtr name, Node * default_, Loc * name_l, Loc * operator_l, Loc * expression_l);
Node *make_or(Node * lhs, Node * rhs, Loc * operator_l, Loc * expression_l);
Node *make_or_asgn(Node * recv, Node * value, Loc * operator_l, Loc * expression_l);
Node *make_pair(Node * key, Node * value, Loc * operator_l, Loc * expression_l);
Node *make_pin(Node * var, Loc * selector_l, Loc * expression_l);
Node *make_postexe(Node * body, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_preexe(Node * body, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_procarg0(NodeVec args, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_rational(BytePtr value, Loc * operator_l, Loc * expression_l);
Node *make_redo(Loc * expression_l);
Node *make_reg_opt(BytePtr options, Loc * expression_l);
Node *make_regexp(NodeVec parts, Node * options, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_rescue(Node * body, NodeVec rescue_bodies, Node * else_, Loc * else_l, Loc * expression_l);
Node *make_rescue_body(Node * exc_list, Node * exc_var, Node * body, Loc * keyword_l, Loc * assoc_l, Loc * begin_l, Loc * expression_l);
Node *make_restarg(BytePtr name, Loc * operator_l, Loc * name_l, Loc * expression_l);
Node *make_retry(Loc * expression_l);
Node *make_return_(NodeVec args, Loc * keyword_l, Loc * expression_l);
Node *make_sclass(Node * expr, Node * body, Loc * keyword_l, Loc * operator_l, Loc * end_l, Loc * expression_l);
Node *make_self_(Loc * expression_l);
Node *make_send(Node * recv, BytePtr method_name, NodeVec args, Loc * dot_l, Loc * selector_l, Loc * begin_l, Loc * end_l, Loc * operator_l, Loc * expression_l);
Node *make_shadowarg(BytePtr name, Loc * expression_l);
Node *make_splat(Node * value, Loc * operator_l, Loc * expression_l);
Node *make_str_(BytePtr value, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_super_(NodeVec args, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_sym(BytePtr name, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_true_(Loc * expression_l);
Node *make_undef(NodeVec names, Loc * keyword_l, Loc * expression_l);
Node *make_unless_guard(Node * cond, Loc * keyword_l, Loc * expression_l);
Node *make_until(Node * cond, Node * body, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_until_post(Node * cond, Node * body, Loc * keyword_l, Loc * expression_l);
Node *make_when(NodeVec patterns, Node * body, Loc * keyword_l, Loc * begin_l, Loc * expression_l);
Node *make_while_(Node * cond, Node * body, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_while_post(Node * cond, Node * body, Loc * keyword_l, Loc * expression_l);
Node *make_x_heredoc(NodeVec parts, Loc * heredoc_body_l, Loc * heredoc_end_l, Loc * expression_l);
Node *make_xstr(NodeVec parts, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_yield_(NodeVec args, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l);
Node *make_zsuper(Loc * expression_l);

}
}

#endif // LIB_RUBY_PARSER_MAKE_NODE_H