
#include <vector>
#include "make_node.h"
#include "node.h"

namespace lib_ruby_parser {

std::vector<Node> nodes_vec_to_cpp_vec(NodeVec nodes)
{
    std::vector<Node> v;
    for (uint32_t i = 0; i < nodes.length; i++)
    {
        v.push_back(std::move(*nodes.ptr[i]));
        delete (nodes.ptr[i]);
    }
    if (nodes.length != 0)
    {
        free(nodes.ptr);
    }
    return v;
}

extern "C" {

Node *make_alias(Node * to, Node * from, Range * keyword_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Alias>(std::unique_ptr<Node>(to), std::unique_ptr<Node>(from), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_and_asgn(Node * recv, Node * value, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<AndAsgn>(std::unique_ptr<Node>(recv), std::unique_ptr<Node>(value), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_and(Node * lhs, Node * rhs, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<And>(std::unique_ptr<Node>(lhs), std::unique_ptr<Node>(rhs), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_arg(BytePtr name, Range * expression_l) {
    node_variant_t inner = std::make_unique<Arg>(byte_ptr_to_owned_string(name), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_args(NodeVec args, Range * expression_l, Range * begin_l, Range * end_l) {
    node_variant_t inner = std::make_unique<Args>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Range>(expression_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l));
    return new Node(std::move(inner));
}
Node *make_array(NodeVec elements, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Array>(nodes_vec_to_cpp_vec(elements), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_array_pattern(NodeVec elements, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<ArrayPattern>(nodes_vec_to_cpp_vec(elements), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_array_pattern_with_tail(NodeVec elements, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<ArrayPatternWithTail>(nodes_vec_to_cpp_vec(elements), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_back_ref(BytePtr name, Range * expression_l) {
    node_variant_t inner = std::make_unique<BackRef>(byte_ptr_to_owned_string(name), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_begin(NodeVec statements, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Begin>(nodes_vec_to_cpp_vec(statements), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_block(Node * call, Node * args, Node * body, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Block>(std::unique_ptr<Node>(call), std::unique_ptr<Node>(args), std::unique_ptr<Node>(body), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_block_pass(Node * value, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<BlockPass>(std::unique_ptr<Node>(value), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_blockarg(BytePtr name, Range * operator_l, Range * name_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Blockarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_break_(NodeVec args, Range * keyword_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Break>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_case(Node * expr, NodeVec when_bodies, Node * else_body, Range * keyword_l, Range * else_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Case>(std::unique_ptr<Node>(expr), nodes_vec_to_cpp_vec(when_bodies), std::unique_ptr<Node>(else_body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(else_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_case_match(Node * expr, NodeVec in_bodies, Node * else_body, Range * keyword_l, Range * else_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<CaseMatch>(std::unique_ptr<Node>(expr), nodes_vec_to_cpp_vec(in_bodies), std::unique_ptr<Node>(else_body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(else_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_casgn(Node * scope, BytePtr name, Node * value, Range * double_colon_l, Range * name_l, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Casgn>(std::unique_ptr<Node>(scope), byte_ptr_to_owned_string(name), std::unique_ptr<Node>(value), std::unique_ptr<Range>(double_colon_l), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_cbase(Range * expression_l) {
    node_variant_t inner = std::make_unique<Cbase>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_class(Node * name, Node * superclass, Node * body, Range * keyword_l, Range * operator_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Class>(std::unique_ptr<Node>(name), std::unique_ptr<Node>(superclass), std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_complex(BytePtr value, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Complex>(byte_ptr_to_owned_string(value), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_const_(Node * scope, BytePtr name, Range * double_colon_l, Range * name_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Const>(std::unique_ptr<Node>(scope), byte_ptr_to_owned_string(name), std::unique_ptr<Range>(double_colon_l), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_const_pattern(Node * const_, Node * pattern, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<ConstPattern>(std::unique_ptr<Node>(const_), std::unique_ptr<Node>(pattern), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_csend(Node * recv, BytePtr method_name, NodeVec args, Range * dot_l, Range * selector_l, Range * begin_l, Range * end_l, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<CSend>(std::unique_ptr<Node>(recv), byte_ptr_to_owned_string(method_name), nodes_vec_to_cpp_vec(args), std::unique_ptr<Range>(dot_l), std::unique_ptr<Range>(selector_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_cvar(BytePtr name, Range * expression_l) {
    node_variant_t inner = std::make_unique<Cvar>(byte_ptr_to_owned_string(name), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_cvasgn(BytePtr name, Node * value, Range * name_l, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Cvasgn>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(value), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_def(BytePtr name, Node * args, Node * body, Range * keyword_l, Range * name_l, Range * end_l, Range * assignment_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Def>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(args), std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(assignment_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_defined(Node * value, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Defined>(std::unique_ptr<Node>(value), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_defs(Node * definee, BytePtr name, Node * args, Node * body, Range * keyword_l, Range * operator_l, Range * name_l, Range * assignment_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Defs>(std::unique_ptr<Node>(definee), byte_ptr_to_owned_string(name), std::unique_ptr<Node>(args), std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(assignment_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_dstr(NodeVec parts, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Dstr>(nodes_vec_to_cpp_vec(parts), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_dsym(NodeVec parts, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Dsym>(nodes_vec_to_cpp_vec(parts), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_eflipflop(Node * left, Node * right, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<EFlipFlop>(std::unique_ptr<Node>(left), std::unique_ptr<Node>(right), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_empty_else(Range * expression_l) {
    node_variant_t inner = std::make_unique<EmptyElse>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_encoding_(Range * expression_l) {
    node_variant_t inner = std::make_unique<Encoding>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_ensure(Node * body, Node * ensure, Range * keyword_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Ensure>(std::unique_ptr<Node>(body), std::unique_ptr<Node>(ensure), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_erange(Node * left, Node * right, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Erange>(std::unique_ptr<Node>(left), std::unique_ptr<Node>(right), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_false_(Range * expression_l) {
    node_variant_t inner = std::make_unique<False>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_file(Range * expression_l) {
    node_variant_t inner = std::make_unique<File>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_find_pattern(NodeVec elements, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<FindPattern>(nodes_vec_to_cpp_vec(elements), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_float(BytePtr value, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Float>(byte_ptr_to_owned_string(value), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_for_(Node * iterator, Node * iteratee, Node * body, Range * keyword_l, Range * operator_l, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<For>(std::unique_ptr<Node>(iterator), std::unique_ptr<Node>(iteratee), std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_forward_arg(Range * expression_l) {
    node_variant_t inner = std::make_unique<ForwardArg>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_forwarded_args(Range * expression_l) {
    node_variant_t inner = std::make_unique<ForwardedArgs>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_gvar(BytePtr name, Range * expression_l) {
    node_variant_t inner = std::make_unique<Gvar>(byte_ptr_to_owned_string(name), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_gvasgn(BytePtr name, Node * value, Range * name_l, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Gvasgn>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(value), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_hash(NodeVec pairs, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Hash>(nodes_vec_to_cpp_vec(pairs), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwargs(NodeVec pairs, Range * expression_l) {
    node_variant_t inner = std::make_unique<Kwargs>(nodes_vec_to_cpp_vec(pairs), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_hash_pattern(NodeVec elements, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<HashPattern>(nodes_vec_to_cpp_vec(elements), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_heredoc(NodeVec parts, Range * heredoc_body_l, Range * heredoc_end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Heredoc>(nodes_vec_to_cpp_vec(parts), std::unique_ptr<Range>(heredoc_body_l), std::unique_ptr<Range>(heredoc_end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_if_(Node * cond, Node * if_true, Node * if_false, Range * keyword_l, Range * begin_l, Range * else_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<If>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(if_true), std::unique_ptr<Node>(if_false), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(else_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_if_guard(Node * cond, Range * keyword_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<IfGuard>(std::unique_ptr<Node>(cond), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_if_mod(Node * cond, Node * if_true, Node * if_false, Range * keyword_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<IfMod>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(if_true), std::unique_ptr<Node>(if_false), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_if_ternary(Node * cond, Node * if_true, Node * if_false, Range * question_l, Range * colon_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<IfTernary>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(if_true), std::unique_ptr<Node>(if_false), std::unique_ptr<Range>(question_l), std::unique_ptr<Range>(colon_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_iflipflop(Node * left, Node * right, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<IFlipFlop>(std::unique_ptr<Node>(left), std::unique_ptr<Node>(right), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_pattern(Node * value, Node * pattern, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<MatchPattern>(std::unique_ptr<Node>(value), std::unique_ptr<Node>(pattern), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_pattern_p(Node * value, Node * pattern, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<MatchPatternP>(std::unique_ptr<Node>(value), std::unique_ptr<Node>(pattern), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_in_pattern(Node * pattern, Node * guard, Node * body, Range * keyword_l, Range * begin_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<InPattern>(std::unique_ptr<Node>(pattern), std::unique_ptr<Node>(guard), std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_index(Node * recv, NodeVec indexes, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Index>(std::unique_ptr<Node>(recv), nodes_vec_to_cpp_vec(indexes), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_index_asgn(Node * recv, NodeVec indexes, Node * value, Range * begin_l, Range * end_l, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<IndexAsgn>(std::unique_ptr<Node>(recv), nodes_vec_to_cpp_vec(indexes), std::unique_ptr<Node>(value), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_int(BytePtr value, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Int>(byte_ptr_to_owned_string(value), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_irange(Node * left, Node * right, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Irange>(std::unique_ptr<Node>(left), std::unique_ptr<Node>(right), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_ivar(BytePtr name, Range * expression_l) {
    node_variant_t inner = std::make_unique<Ivar>(byte_ptr_to_owned_string(name), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_ivasgn(BytePtr name, Node * value, Range * name_l, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Ivasgn>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(value), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwarg(BytePtr name, Range * name_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Kwarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwbegin(NodeVec statements, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<KwBegin>(nodes_vec_to_cpp_vec(statements), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwnilarg(Range * name_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Kwnilarg>(std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwoptarg(BytePtr name, Node * default_, Range * name_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Kwoptarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(default_), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwrestarg(BytePtr name, Range * operator_l, Range * name_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Kwrestarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwsplat(Node * value, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Kwsplat>(std::unique_ptr<Node>(value), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_lambda(Range * expression_l) {
    node_variant_t inner = std::make_unique<Lambda>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_line(Range * expression_l) {
    node_variant_t inner = std::make_unique<Line>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_lvar(BytePtr name, Range * expression_l) {
    node_variant_t inner = std::make_unique<Lvar>(byte_ptr_to_owned_string(name), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_lvasgn(BytePtr name, Node * value, Range * name_l, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Lvasgn>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(value), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_masgn(Node * lhs, Node * rhs, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Masgn>(std::unique_ptr<Node>(lhs), std::unique_ptr<Node>(rhs), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_alt(Node * lhs, Node * rhs, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<MatchAlt>(std::unique_ptr<Node>(lhs), std::unique_ptr<Node>(rhs), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_as(Node * value, Node * as_, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<MatchAs>(std::unique_ptr<Node>(value), std::unique_ptr<Node>(as_), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_current_line(Node * re, Range * expression_l) {
    node_variant_t inner = std::make_unique<MatchCurrentLine>(std::unique_ptr<Node>(re), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_nil_pattern(Range * operator_l, Range * name_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<MatchNilPattern>(std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_rest(Node * name, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<MatchRest>(std::unique_ptr<Node>(name), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_var(BytePtr name, Range * name_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<MatchVar>(byte_ptr_to_owned_string(name), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_with_lvasgn(Node * re, Node * value, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<MatchWithLvasgn>(std::unique_ptr<Node>(re), std::unique_ptr<Node>(value), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_mlhs(NodeVec items, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Mlhs>(nodes_vec_to_cpp_vec(items), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_module(Node * name, Node * body, Range * keyword_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Module>(std::unique_ptr<Node>(name), std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_next(NodeVec args, Range * keyword_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Next>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_nil(Range * expression_l) {
    node_variant_t inner = std::make_unique<Nil>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_nth_ref(BytePtr name, Range * expression_l) {
    node_variant_t inner = std::make_unique<NthRef>(byte_ptr_to_owned_string(name), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_numblock(Node * call, uint32_t  numargs, Node * body, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Numblock>(std::unique_ptr<Node>(call), numargs, std::unique_ptr<Node>(body), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_op_asgn(Node * recv, BytePtr operator_, Node * value, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<OpAsgn>(std::unique_ptr<Node>(recv), byte_ptr_to_owned_string(operator_), std::unique_ptr<Node>(value), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_optarg(BytePtr name, Node * default_, Range * name_l, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Optarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(default_), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_or(Node * lhs, Node * rhs, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Or>(std::unique_ptr<Node>(lhs), std::unique_ptr<Node>(rhs), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_or_asgn(Node * recv, Node * value, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<OrAsgn>(std::unique_ptr<Node>(recv), std::unique_ptr<Node>(value), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_pair(Node * key, Node * value, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Pair>(std::unique_ptr<Node>(key), std::unique_ptr<Node>(value), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_pin(Node * var, Range * selector_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Pin>(std::unique_ptr<Node>(var), std::unique_ptr<Range>(selector_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_postexe(Node * body, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Postexe>(std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_preexe(Node * body, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Preexe>(std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_procarg0(NodeVec args, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Procarg0>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_rational(BytePtr value, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Rational>(byte_ptr_to_owned_string(value), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_redo(Range * expression_l) {
    node_variant_t inner = std::make_unique<Redo>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_reg_opt(BytePtr options, Range * expression_l) {
    node_variant_t inner = std::make_unique<RegOpt>(byte_ptr_to_owned_string(options), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_regexp(NodeVec parts, Node * options, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Regexp>(nodes_vec_to_cpp_vec(parts), std::unique_ptr<Node>(options), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_rescue(Node * body, NodeVec rescue_bodies, Node * else_, Range * else_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Rescue>(std::unique_ptr<Node>(body), nodes_vec_to_cpp_vec(rescue_bodies), std::unique_ptr<Node>(else_), std::unique_ptr<Range>(else_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_rescue_body(Node * exc_list, Node * exc_var, Node * body, Range * keyword_l, Range * assoc_l, Range * begin_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<RescueBody>(std::unique_ptr<Node>(exc_list), std::unique_ptr<Node>(exc_var), std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(assoc_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_restarg(BytePtr name, Range * operator_l, Range * name_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Restarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(name_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_retry(Range * expression_l) {
    node_variant_t inner = std::make_unique<Retry>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_return_(NodeVec args, Range * keyword_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Return>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_sclass(Node * expr, Node * body, Range * keyword_l, Range * operator_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<SClass>(std::unique_ptr<Node>(expr), std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_self_(Range * expression_l) {
    node_variant_t inner = std::make_unique<Self_>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_send(Node * recv, BytePtr method_name, NodeVec args, Range * dot_l, Range * selector_l, Range * begin_l, Range * end_l, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Send>(std::unique_ptr<Node>(recv), byte_ptr_to_owned_string(method_name), nodes_vec_to_cpp_vec(args), std::unique_ptr<Range>(dot_l), std::unique_ptr<Range>(selector_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_shadowarg(BytePtr name, Range * expression_l) {
    node_variant_t inner = std::make_unique<Shadowarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_splat(Node * value, Range * operator_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Splat>(std::unique_ptr<Node>(value), std::unique_ptr<Range>(operator_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_str_(BytePtr value, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Str>(Bytes(value), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_super_(NodeVec args, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Super>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_sym(BytePtr name, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Sym>(Bytes(name), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_true_(Range * expression_l) {
    node_variant_t inner = std::make_unique<True>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_undef(NodeVec names, Range * keyword_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Undef>(nodes_vec_to_cpp_vec(names), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_unless_guard(Node * cond, Range * keyword_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<UnlessGuard>(std::unique_ptr<Node>(cond), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_until(Node * cond, Node * body, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Until>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_until_post(Node * cond, Node * body, Range * keyword_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<UntilPost>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_when(NodeVec patterns, Node * body, Range * keyword_l, Range * begin_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<When>(nodes_vec_to_cpp_vec(patterns), std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_while_(Node * cond, Node * body, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<While>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_while_post(Node * cond, Node * body, Range * keyword_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<WhilePost>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(body), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_x_heredoc(NodeVec parts, Range * heredoc_body_l, Range * heredoc_end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<XHeredoc>(nodes_vec_to_cpp_vec(parts), std::unique_ptr<Range>(heredoc_body_l), std::unique_ptr<Range>(heredoc_end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_xstr(NodeVec parts, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Xstr>(nodes_vec_to_cpp_vec(parts), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_yield_(NodeVec args, Range * keyword_l, Range * begin_l, Range * end_l, Range * expression_l) {
    node_variant_t inner = std::make_unique<Yield>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Range>(keyword_l), std::unique_ptr<Range>(begin_l), std::unique_ptr<Range>(end_l), std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}
Node *make_zsuper(Range * expression_l) {
    node_variant_t inner = std::make_unique<ZSuper>(std::unique_ptr<Range>(expression_l));
    return new Node(std::move(inner));
}

}
}
