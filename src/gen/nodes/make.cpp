
#include <vector>
#include "make.h"
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

Node *make_alias(Node * to, Node * from, Loc * keyword_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Alias>(std::unique_ptr<Node>(to), std::unique_ptr<Node>(from), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_and_asgn(Node * recv, Node * value, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<AndAsgn>(std::unique_ptr<Node>(recv), std::unique_ptr<Node>(value), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_and(Node * lhs, Node * rhs, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<And>(std::unique_ptr<Node>(lhs), std::unique_ptr<Node>(rhs), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_arg(BytePtr name, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Arg>(byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_args(NodeVec args, Loc * expression_l, Loc * begin_l, Loc * end_l) {
    node_variant_t inner = std::make_unique<Args>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Loc>(expression_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l));
    return new Node(std::move(inner));
}
Node *make_array(NodeVec elements, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Array>(nodes_vec_to_cpp_vec(elements), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_array_pattern(NodeVec elements, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<ArrayPattern>(nodes_vec_to_cpp_vec(elements), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_array_pattern_with_tail(NodeVec elements, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<ArrayPatternWithTail>(nodes_vec_to_cpp_vec(elements), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_back_ref(BytePtr name, Loc * expression_l) {
    node_variant_t inner = std::make_unique<BackRef>(byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_begin(NodeVec statements, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Begin>(nodes_vec_to_cpp_vec(statements), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_block(Node * call, Node * args, Node * body, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Block>(std::unique_ptr<Node>(call), std::unique_ptr<Node>(args), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_block_pass(Node * value, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<BlockPass>(std::unique_ptr<Node>(value), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_blockarg(BytePtr name, Loc * operator_l, Loc * name_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Blockarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_break_(NodeVec args, Loc * keyword_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Break>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_case(Node * expr, NodeVec when_bodies, Node * else_body, Loc * keyword_l, Loc * else_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Case>(std::unique_ptr<Node>(expr), nodes_vec_to_cpp_vec(when_bodies), std::unique_ptr<Node>(else_body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(else_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_case_match(Node * expr, NodeVec in_bodies, Node * else_body, Loc * keyword_l, Loc * else_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<CaseMatch>(std::unique_ptr<Node>(expr), nodes_vec_to_cpp_vec(in_bodies), std::unique_ptr<Node>(else_body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(else_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_casgn(Node * scope, BytePtr name, Node * value, Loc * double_colon_l, Loc * name_l, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Casgn>(std::unique_ptr<Node>(scope), byte_ptr_to_owned_string(name), std::unique_ptr<Node>(value), std::unique_ptr<Loc>(double_colon_l), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_cbase(Loc * expression_l) {
    node_variant_t inner = std::make_unique<Cbase>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_class(Node * name, Node * superclass, Node * body, Loc * keyword_l, Loc * operator_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Class>(std::unique_ptr<Node>(name), std::unique_ptr<Node>(superclass), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_complex(BytePtr value, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Complex>(byte_ptr_to_owned_string(value), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_const_(Node * scope, BytePtr name, Loc * double_colon_l, Loc * name_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Const>(std::unique_ptr<Node>(scope), byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(double_colon_l), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_const_pattern(Node * const_, Node * pattern, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<ConstPattern>(std::unique_ptr<Node>(const_), std::unique_ptr<Node>(pattern), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_csend(Node * recv, BytePtr method_name, NodeVec args, Loc * dot_l, Loc * selector_l, Loc * begin_l, Loc * end_l, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<CSend>(std::unique_ptr<Node>(recv), byte_ptr_to_owned_string(method_name), nodes_vec_to_cpp_vec(args), std::unique_ptr<Loc>(dot_l), std::unique_ptr<Loc>(selector_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_cvar(BytePtr name, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Cvar>(byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_cvasgn(BytePtr name, Node * value, Loc * name_l, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Cvasgn>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(value), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_def(BytePtr name, Node * args, Node * body, Loc * keyword_l, Loc * name_l, Loc * end_l, Loc * assignment_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Def>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(args), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(assignment_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_defined(Node * value, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Defined>(std::unique_ptr<Node>(value), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_defs(Node * definee, BytePtr name, Node * args, Node * body, Loc * keyword_l, Loc * operator_l, Loc * name_l, Loc * assignment_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Defs>(std::unique_ptr<Node>(definee), byte_ptr_to_owned_string(name), std::unique_ptr<Node>(args), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(assignment_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_dstr(NodeVec parts, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Dstr>(nodes_vec_to_cpp_vec(parts), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_dsym(NodeVec parts, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Dsym>(nodes_vec_to_cpp_vec(parts), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_eflipflop(Node * left, Node * right, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<EFlipFlop>(std::unique_ptr<Node>(left), std::unique_ptr<Node>(right), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_empty_else(Loc * expression_l) {
    node_variant_t inner = std::make_unique<EmptyElse>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_encoding_(Loc * expression_l) {
    node_variant_t inner = std::make_unique<Encoding>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_ensure(Node * body, Node * ensure, Loc * keyword_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Ensure>(std::unique_ptr<Node>(body), std::unique_ptr<Node>(ensure), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_erange(Node * left, Node * right, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Erange>(std::unique_ptr<Node>(left), std::unique_ptr<Node>(right), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_false_(Loc * expression_l) {
    node_variant_t inner = std::make_unique<False>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_file(Loc * expression_l) {
    node_variant_t inner = std::make_unique<File>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_find_pattern(NodeVec elements, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<FindPattern>(nodes_vec_to_cpp_vec(elements), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_float(BytePtr value, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Float>(byte_ptr_to_owned_string(value), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_for_(Node * iterator, Node * iteratee, Node * body, Loc * keyword_l, Loc * operator_l, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<For>(std::unique_ptr<Node>(iterator), std::unique_ptr<Node>(iteratee), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_forward_arg(Loc * expression_l) {
    node_variant_t inner = std::make_unique<ForwardArg>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_forwarded_args(Loc * expression_l) {
    node_variant_t inner = std::make_unique<ForwardedArgs>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_gvar(BytePtr name, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Gvar>(byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_gvasgn(BytePtr name, Node * value, Loc * name_l, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Gvasgn>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(value), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_hash(NodeVec pairs, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Hash>(nodes_vec_to_cpp_vec(pairs), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwargs(NodeVec pairs, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Kwargs>(nodes_vec_to_cpp_vec(pairs), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_hash_pattern(NodeVec elements, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<HashPattern>(nodes_vec_to_cpp_vec(elements), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_heredoc(NodeVec parts, Loc * heredoc_body_l, Loc * heredoc_end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Heredoc>(nodes_vec_to_cpp_vec(parts), std::unique_ptr<Loc>(heredoc_body_l), std::unique_ptr<Loc>(heredoc_end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_if_(Node * cond, Node * if_true, Node * if_false, Loc * keyword_l, Loc * begin_l, Loc * else_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<If>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(if_true), std::unique_ptr<Node>(if_false), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(else_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_if_guard(Node * cond, Loc * keyword_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<IfGuard>(std::unique_ptr<Node>(cond), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_if_mod(Node * cond, Node * if_true, Node * if_false, Loc * keyword_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<IfMod>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(if_true), std::unique_ptr<Node>(if_false), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_if_ternary(Node * cond, Node * if_true, Node * if_false, Loc * question_l, Loc * colon_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<IfTernary>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(if_true), std::unique_ptr<Node>(if_false), std::unique_ptr<Loc>(question_l), std::unique_ptr<Loc>(colon_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_iflipflop(Node * left, Node * right, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<IFlipFlop>(std::unique_ptr<Node>(left), std::unique_ptr<Node>(right), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_pattern(Node * value, Node * pattern, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<MatchPattern>(std::unique_ptr<Node>(value), std::unique_ptr<Node>(pattern), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_pattern_p(Node * value, Node * pattern, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<MatchPatternP>(std::unique_ptr<Node>(value), std::unique_ptr<Node>(pattern), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_in_pattern(Node * pattern, Node * guard, Node * body, Loc * keyword_l, Loc * begin_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<InPattern>(std::unique_ptr<Node>(pattern), std::unique_ptr<Node>(guard), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_index(Node * recv, NodeVec indexes, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Index>(std::unique_ptr<Node>(recv), nodes_vec_to_cpp_vec(indexes), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_index_asgn(Node * recv, NodeVec indexes, Node * value, Loc * begin_l, Loc * end_l, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<IndexAsgn>(std::unique_ptr<Node>(recv), nodes_vec_to_cpp_vec(indexes), std::unique_ptr<Node>(value), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_int(BytePtr value, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Int>(byte_ptr_to_owned_string(value), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_irange(Node * left, Node * right, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Irange>(std::unique_ptr<Node>(left), std::unique_ptr<Node>(right), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_ivar(BytePtr name, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Ivar>(byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_ivasgn(BytePtr name, Node * value, Loc * name_l, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Ivasgn>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(value), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwarg(BytePtr name, Loc * name_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Kwarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwbegin(NodeVec statements, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<KwBegin>(nodes_vec_to_cpp_vec(statements), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwnilarg(Loc * name_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Kwnilarg>(std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwoptarg(BytePtr name, Node * default_, Loc * name_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Kwoptarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(default_), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwrestarg(BytePtr name, Loc * operator_l, Loc * name_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Kwrestarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_kwsplat(Node * value, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Kwsplat>(std::unique_ptr<Node>(value), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_lambda(Loc * expression_l) {
    node_variant_t inner = std::make_unique<Lambda>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_line(Loc * expression_l) {
    node_variant_t inner = std::make_unique<Line>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_lvar(BytePtr name, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Lvar>(byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_lvasgn(BytePtr name, Node * value, Loc * name_l, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Lvasgn>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(value), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_masgn(Node * lhs, Node * rhs, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Masgn>(std::unique_ptr<Node>(lhs), std::unique_ptr<Node>(rhs), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_alt(Node * lhs, Node * rhs, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<MatchAlt>(std::unique_ptr<Node>(lhs), std::unique_ptr<Node>(rhs), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_as(Node * value, Node * as_, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<MatchAs>(std::unique_ptr<Node>(value), std::unique_ptr<Node>(as_), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_current_line(Node * re, Loc * expression_l) {
    node_variant_t inner = std::make_unique<MatchCurrentLine>(std::unique_ptr<Node>(re), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_nil_pattern(Loc * operator_l, Loc * name_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<MatchNilPattern>(std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_rest(Node * name, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<MatchRest>(std::unique_ptr<Node>(name), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_var(BytePtr name, Loc * name_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<MatchVar>(byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_match_with_lvasgn(Node * re, Node * value, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<MatchWithLvasgn>(std::unique_ptr<Node>(re), std::unique_ptr<Node>(value), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_mlhs(NodeVec items, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Mlhs>(nodes_vec_to_cpp_vec(items), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_module(Node * name, Node * body, Loc * keyword_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Module>(std::unique_ptr<Node>(name), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_next(NodeVec args, Loc * keyword_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Next>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_nil(Loc * expression_l) {
    node_variant_t inner = std::make_unique<Nil>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_nth_ref(BytePtr name, Loc * expression_l) {
    node_variant_t inner = std::make_unique<NthRef>(byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_numblock(Node * call, uint32_t  numargs, Node * body, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Numblock>(std::unique_ptr<Node>(call), numargs, std::unique_ptr<Node>(body), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_op_asgn(Node * recv, BytePtr operator_, Node * value, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<OpAsgn>(std::unique_ptr<Node>(recv), byte_ptr_to_owned_string(operator_), std::unique_ptr<Node>(value), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_optarg(BytePtr name, Node * default_, Loc * name_l, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Optarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Node>(default_), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_or(Node * lhs, Node * rhs, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Or>(std::unique_ptr<Node>(lhs), std::unique_ptr<Node>(rhs), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_or_asgn(Node * recv, Node * value, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<OrAsgn>(std::unique_ptr<Node>(recv), std::unique_ptr<Node>(value), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_pair(Node * key, Node * value, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Pair>(std::unique_ptr<Node>(key), std::unique_ptr<Node>(value), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_pin(Node * var, Loc * selector_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Pin>(std::unique_ptr<Node>(var), std::unique_ptr<Loc>(selector_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_postexe(Node * body, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Postexe>(std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_preexe(Node * body, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Preexe>(std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_procarg0(NodeVec args, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Procarg0>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_rational(BytePtr value, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Rational>(byte_ptr_to_owned_string(value), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_redo(Loc * expression_l) {
    node_variant_t inner = std::make_unique<Redo>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_reg_opt(BytePtr options, Loc * expression_l) {
    node_variant_t inner = std::make_unique<RegOpt>(byte_ptr_to_owned_string(options), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_regexp(NodeVec parts, Node * options, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Regexp>(nodes_vec_to_cpp_vec(parts), std::unique_ptr<Node>(options), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_rescue(Node * body, NodeVec rescue_bodies, Node * else_, Loc * else_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Rescue>(std::unique_ptr<Node>(body), nodes_vec_to_cpp_vec(rescue_bodies), std::unique_ptr<Node>(else_), std::unique_ptr<Loc>(else_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_rescue_body(Node * exc_list, Node * exc_var, Node * body, Loc * keyword_l, Loc * assoc_l, Loc * begin_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<RescueBody>(std::unique_ptr<Node>(exc_list), std::unique_ptr<Node>(exc_var), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(assoc_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_restarg(BytePtr name, Loc * operator_l, Loc * name_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Restarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(name_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_retry(Loc * expression_l) {
    node_variant_t inner = std::make_unique<Retry>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_return_(NodeVec args, Loc * keyword_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Return>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_sclass(Node * expr, Node * body, Loc * keyword_l, Loc * operator_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<SClass>(std::unique_ptr<Node>(expr), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_self_(Loc * expression_l) {
    node_variant_t inner = std::make_unique<Self_>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_send(Node * recv, BytePtr method_name, NodeVec args, Loc * dot_l, Loc * selector_l, Loc * begin_l, Loc * end_l, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Send>(std::unique_ptr<Node>(recv), byte_ptr_to_owned_string(method_name), nodes_vec_to_cpp_vec(args), std::unique_ptr<Loc>(dot_l), std::unique_ptr<Loc>(selector_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_shadowarg(BytePtr name, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Shadowarg>(byte_ptr_to_owned_string(name), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_splat(Node * value, Loc * operator_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Splat>(std::unique_ptr<Node>(value), std::unique_ptr<Loc>(operator_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_str_(BytePtr value, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Str>(Bytes(value), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_super_(NodeVec args, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Super>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_sym(BytePtr name, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Sym>(Bytes(name), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_true_(Loc * expression_l) {
    node_variant_t inner = std::make_unique<True>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_undef(NodeVec names, Loc * keyword_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Undef>(nodes_vec_to_cpp_vec(names), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_unless_guard(Node * cond, Loc * keyword_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<UnlessGuard>(std::unique_ptr<Node>(cond), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_until(Node * cond, Node * body, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Until>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_until_post(Node * cond, Node * body, Loc * keyword_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<UntilPost>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_when(NodeVec patterns, Node * body, Loc * keyword_l, Loc * begin_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<When>(nodes_vec_to_cpp_vec(patterns), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_while_(Node * cond, Node * body, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<While>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_while_post(Node * cond, Node * body, Loc * keyword_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<WhilePost>(std::unique_ptr<Node>(cond), std::unique_ptr<Node>(body), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_x_heredoc(NodeVec parts, Loc * heredoc_body_l, Loc * heredoc_end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<XHeredoc>(nodes_vec_to_cpp_vec(parts), std::unique_ptr<Loc>(heredoc_body_l), std::unique_ptr<Loc>(heredoc_end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_xstr(NodeVec parts, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Xstr>(nodes_vec_to_cpp_vec(parts), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_yield_(NodeVec args, Loc * keyword_l, Loc * begin_l, Loc * end_l, Loc * expression_l) {
    node_variant_t inner = std::make_unique<Yield>(nodes_vec_to_cpp_vec(args), std::unique_ptr<Loc>(keyword_l), std::unique_ptr<Loc>(begin_l), std::unique_ptr<Loc>(end_l), std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}
Node *make_zsuper(Loc * expression_l) {
    node_variant_t inner = std::make_unique<ZSuper>(std::unique_ptr<Loc>(expression_l));
    return new Node(std::move(inner));
}

}
}
