#include "node.h"
namespace lib_ruby_parser {
Alias::Alias(std::unique_ptr<Node> to, std::unique_ptr<Node> from, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l)
{
this->to = std::move(to);
this->from = std::move(from);
this->keyword_l = std::move(keyword_l);
this->expression_l = std::move(expression_l);
}

AndAsgn::AndAsgn(std::unique_ptr<Node> recv, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->recv = std::move(recv);
this->value = std::move(value);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

And::And(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->lhs = std::move(lhs);
this->rhs = std::move(rhs);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Arg::Arg(std::string name, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->expression_l = std::move(expression_l);
}

Args::Args(std::vector<Node> args, std::unique_ptr<Loc> expression_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l)
{
this->args = std::move(args);
this->expression_l = std::move(expression_l);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
}

Array::Array(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->elements = std::move(elements);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

ArrayPattern::ArrayPattern(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->elements = std::move(elements);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

ArrayPatternWithTail::ArrayPatternWithTail(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->elements = std::move(elements);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

BackRef::BackRef(std::string name, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->expression_l = std::move(expression_l);
}

Begin::Begin(std::vector<Node> statements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->statements = std::move(statements);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Block::Block(std::unique_ptr<Node> call, std::unique_ptr<Node> args, std::unique_ptr<Node> body, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->call = std::move(call);
this->args = std::move(args);
this->body = std::move(body);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

BlockPass::BlockPass(std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->value = std::move(value);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Blockarg::Blockarg(std::string name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->operator_l = std::move(operator_l);
this->name_l = std::move(name_l);
this->expression_l = std::move(expression_l);
}

Break::Break(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l)
{
this->args = std::move(args);
this->keyword_l = std::move(keyword_l);
this->expression_l = std::move(expression_l);
}

Case::Case(std::unique_ptr<Node> expr, std::vector<Node> when_bodies, std::unique_ptr<Node> else_body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->expr = std::move(expr);
this->when_bodies = std::move(when_bodies);
this->else_body = std::move(else_body);
this->keyword_l = std::move(keyword_l);
this->else_l = std::move(else_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

CaseMatch::CaseMatch(std::unique_ptr<Node> expr, std::vector<Node> in_bodies, std::unique_ptr<Node> else_body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->expr = std::move(expr);
this->in_bodies = std::move(in_bodies);
this->else_body = std::move(else_body);
this->keyword_l = std::move(keyword_l);
this->else_l = std::move(else_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Casgn::Casgn(std::unique_ptr<Node> scope, std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> double_colon_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->scope = std::move(scope);
this->name = std::move(name);
this->value = std::move(value);
this->double_colon_l = std::move(double_colon_l);
this->name_l = std::move(name_l);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Cbase::Cbase(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

Class::Class(std::unique_ptr<Node> name, std::unique_ptr<Node> superclass, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->superclass = std::move(superclass);
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->operator_l = std::move(operator_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Complex::Complex(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->value = std::move(value);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Const::Const(std::unique_ptr<Node> scope, std::string name, std::unique_ptr<Loc> double_colon_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l)
{
this->scope = std::move(scope);
this->name = std::move(name);
this->double_colon_l = std::move(double_colon_l);
this->name_l = std::move(name_l);
this->expression_l = std::move(expression_l);
}

ConstPattern::ConstPattern(std::unique_ptr<Node> const_, std::unique_ptr<Node> pattern, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->const_ = std::move(const_);
this->pattern = std::move(pattern);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

CSend::CSend(std::unique_ptr<Node> recv, std::string method_name, std::vector<Node> args, std::unique_ptr<Loc> dot_l, std::unique_ptr<Loc> selector_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->recv = std::move(recv);
this->method_name = std::move(method_name);
this->args = std::move(args);
this->dot_l = std::move(dot_l);
this->selector_l = std::move(selector_l);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Cvar::Cvar(std::string name, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->expression_l = std::move(expression_l);
}

Cvasgn::Cvasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->value = std::move(value);
this->name_l = std::move(name_l);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Def::Def(std::string name, std::unique_ptr<Node> args, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> assignment_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->args = std::move(args);
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->name_l = std::move(name_l);
this->end_l = std::move(end_l);
this->assignment_l = std::move(assignment_l);
this->expression_l = std::move(expression_l);
}

Defined::Defined(std::unique_ptr<Node> value, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->value = std::move(value);
this->keyword_l = std::move(keyword_l);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Defs::Defs(std::unique_ptr<Node> definee, std::string name, std::unique_ptr<Node> args, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> assignment_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->definee = std::move(definee);
this->name = std::move(name);
this->args = std::move(args);
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->operator_l = std::move(operator_l);
this->name_l = std::move(name_l);
this->assignment_l = std::move(assignment_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Dstr::Dstr(std::vector<Node> parts, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->parts = std::move(parts);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Dsym::Dsym(std::vector<Node> parts, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->parts = std::move(parts);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

EFlipFlop::EFlipFlop(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->left = std::move(left);
this->right = std::move(right);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

EmptyElse::EmptyElse(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

Encoding::Encoding(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

Ensure::Ensure(std::unique_ptr<Node> body, std::unique_ptr<Node> ensure, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l)
{
this->body = std::move(body);
this->ensure = std::move(ensure);
this->keyword_l = std::move(keyword_l);
this->expression_l = std::move(expression_l);
}

Erange::Erange(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->left = std::move(left);
this->right = std::move(right);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

False::False(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

File::File(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

FindPattern::FindPattern(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->elements = std::move(elements);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Float::Float(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->value = std::move(value);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

For::For(std::unique_ptr<Node> iterator, std::unique_ptr<Node> iteratee, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->iterator = std::move(iterator);
this->iteratee = std::move(iteratee);
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->operator_l = std::move(operator_l);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

ForwardArg::ForwardArg(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

ForwardedArgs::ForwardedArgs(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

Gvar::Gvar(std::string name, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->expression_l = std::move(expression_l);
}

Gvasgn::Gvasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->value = std::move(value);
this->name_l = std::move(name_l);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Hash::Hash(std::vector<Node> pairs, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->pairs = std::move(pairs);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Kwargs::Kwargs(std::vector<Node> pairs, std::unique_ptr<Loc> expression_l)
{
this->pairs = std::move(pairs);
this->expression_l = std::move(expression_l);
}

HashPattern::HashPattern(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->elements = std::move(elements);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Heredoc::Heredoc(std::vector<Node> parts, std::unique_ptr<Loc> heredoc_body_l, std::unique_ptr<Loc> heredoc_end_l, std::unique_ptr<Loc> expression_l)
{
this->parts = std::move(parts);
this->heredoc_body_l = std::move(heredoc_body_l);
this->heredoc_end_l = std::move(heredoc_end_l);
this->expression_l = std::move(expression_l);
}

If::If(std::unique_ptr<Node> cond, std::unique_ptr<Node> if_true, std::unique_ptr<Node> if_false, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->cond = std::move(cond);
this->if_true = std::move(if_true);
this->if_false = std::move(if_false);
this->keyword_l = std::move(keyword_l);
this->begin_l = std::move(begin_l);
this->else_l = std::move(else_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

IfGuard::IfGuard(std::unique_ptr<Node> cond, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l)
{
this->cond = std::move(cond);
this->keyword_l = std::move(keyword_l);
this->expression_l = std::move(expression_l);
}

IfMod::IfMod(std::unique_ptr<Node> cond, std::unique_ptr<Node> if_true, std::unique_ptr<Node> if_false, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l)
{
this->cond = std::move(cond);
this->if_true = std::move(if_true);
this->if_false = std::move(if_false);
this->keyword_l = std::move(keyword_l);
this->expression_l = std::move(expression_l);
}

IfTernary::IfTernary(std::unique_ptr<Node> cond, std::unique_ptr<Node> if_true, std::unique_ptr<Node> if_false, std::unique_ptr<Loc> question_l, std::unique_ptr<Loc> colon_l, std::unique_ptr<Loc> expression_l)
{
this->cond = std::move(cond);
this->if_true = std::move(if_true);
this->if_false = std::move(if_false);
this->question_l = std::move(question_l);
this->colon_l = std::move(colon_l);
this->expression_l = std::move(expression_l);
}

IFlipFlop::IFlipFlop(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->left = std::move(left);
this->right = std::move(right);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

MatchPattern::MatchPattern(std::unique_ptr<Node> value, std::unique_ptr<Node> pattern, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->value = std::move(value);
this->pattern = std::move(pattern);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

MatchPatternP::MatchPatternP(std::unique_ptr<Node> value, std::unique_ptr<Node> pattern, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->value = std::move(value);
this->pattern = std::move(pattern);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

InPattern::InPattern(std::unique_ptr<Node> pattern, std::unique_ptr<Node> guard, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> expression_l)
{
this->pattern = std::move(pattern);
this->guard = std::move(guard);
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->begin_l = std::move(begin_l);
this->expression_l = std::move(expression_l);
}

Index::Index(std::unique_ptr<Node> recv, std::vector<Node> indexes, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->recv = std::move(recv);
this->indexes = std::move(indexes);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

IndexAsgn::IndexAsgn(std::unique_ptr<Node> recv, std::vector<Node> indexes, std::unique_ptr<Node> value, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->recv = std::move(recv);
this->indexes = std::move(indexes);
this->value = std::move(value);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Int::Int(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->value = std::move(value);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Irange::Irange(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->left = std::move(left);
this->right = std::move(right);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Ivar::Ivar(std::string name, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->expression_l = std::move(expression_l);
}

Ivasgn::Ivasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->value = std::move(value);
this->name_l = std::move(name_l);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Kwarg::Kwarg(std::string name, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->name_l = std::move(name_l);
this->expression_l = std::move(expression_l);
}

KwBegin::KwBegin(std::vector<Node> statements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->statements = std::move(statements);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Kwnilarg::Kwnilarg(std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l)
{
this->name_l = std::move(name_l);
this->expression_l = std::move(expression_l);
}

Kwoptarg::Kwoptarg(std::string name, std::unique_ptr<Node> default_, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->default_ = std::move(default_);
this->name_l = std::move(name_l);
this->expression_l = std::move(expression_l);
}

Kwrestarg::Kwrestarg(std::string name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->operator_l = std::move(operator_l);
this->name_l = std::move(name_l);
this->expression_l = std::move(expression_l);
}

Kwsplat::Kwsplat(std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->value = std::move(value);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Lambda::Lambda(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

Line::Line(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

Lvar::Lvar(std::string name, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->expression_l = std::move(expression_l);
}

Lvasgn::Lvasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->value = std::move(value);
this->name_l = std::move(name_l);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Masgn::Masgn(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->lhs = std::move(lhs);
this->rhs = std::move(rhs);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

MatchAlt::MatchAlt(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->lhs = std::move(lhs);
this->rhs = std::move(rhs);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

MatchAs::MatchAs(std::unique_ptr<Node> value, std::unique_ptr<Node> as_, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->value = std::move(value);
this->as_ = std::move(as_);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

MatchCurrentLine::MatchCurrentLine(std::unique_ptr<Node> re, std::unique_ptr<Loc> expression_l)
{
this->re = std::move(re);
this->expression_l = std::move(expression_l);
}

MatchNilPattern::MatchNilPattern(std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l)
{
this->operator_l = std::move(operator_l);
this->name_l = std::move(name_l);
this->expression_l = std::move(expression_l);
}

MatchRest::MatchRest(std::unique_ptr<Node> name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

MatchVar::MatchVar(std::string name, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->name_l = std::move(name_l);
this->expression_l = std::move(expression_l);
}

MatchWithLvasgn::MatchWithLvasgn(std::unique_ptr<Node> re, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->re = std::move(re);
this->value = std::move(value);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Mlhs::Mlhs(std::vector<Node> items, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->items = std::move(items);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Module::Module(std::unique_ptr<Node> name, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Next::Next(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l)
{
this->args = std::move(args);
this->keyword_l = std::move(keyword_l);
this->expression_l = std::move(expression_l);
}

Nil::Nil(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

NthRef::NthRef(std::string name, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->expression_l = std::move(expression_l);
}

Numblock::Numblock(std::unique_ptr<Node> call, uint32_t numargs, std::unique_ptr<Node> body, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->call = std::move(call);
this->numargs = numargs;
this->body = std::move(body);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

OpAsgn::OpAsgn(std::unique_ptr<Node> recv, std::string operator_, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->recv = std::move(recv);
this->operator_ = std::move(operator_);
this->value = std::move(value);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Optarg::Optarg(std::string name, std::unique_ptr<Node> default_, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->default_ = std::move(default_);
this->name_l = std::move(name_l);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Or::Or(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->lhs = std::move(lhs);
this->rhs = std::move(rhs);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

OrAsgn::OrAsgn(std::unique_ptr<Node> recv, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->recv = std::move(recv);
this->value = std::move(value);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Pair::Pair(std::unique_ptr<Node> key, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->key = std::move(key);
this->value = std::move(value);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Pin::Pin(std::unique_ptr<Node> var, std::unique_ptr<Loc> selector_l, std::unique_ptr<Loc> expression_l)
{
this->var = std::move(var);
this->selector_l = std::move(selector_l);
this->expression_l = std::move(expression_l);
}

Postexe::Postexe(std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Preexe::Preexe(std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Procarg0::Procarg0(std::vector<Node> args, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->args = std::move(args);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Rational::Rational(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->value = std::move(value);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Redo::Redo(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

RegOpt::RegOpt(std::string options, std::unique_ptr<Loc> expression_l)
{
this->options = std::move(options);
this->expression_l = std::move(expression_l);
}

Regexp::Regexp(std::vector<Node> parts, std::unique_ptr<Node> options, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->parts = std::move(parts);
this->options = std::move(options);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Rescue::Rescue(std::unique_ptr<Node> body, std::vector<Node> rescue_bodies, std::unique_ptr<Node> else_, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> expression_l)
{
this->body = std::move(body);
this->rescue_bodies = std::move(rescue_bodies);
this->else_ = std::move(else_);
this->else_l = std::move(else_l);
this->expression_l = std::move(expression_l);
}

RescueBody::RescueBody(std::unique_ptr<Node> exc_list, std::unique_ptr<Node> exc_var, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> assoc_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> expression_l)
{
this->exc_list = std::move(exc_list);
this->exc_var = std::move(exc_var);
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->assoc_l = std::move(assoc_l);
this->begin_l = std::move(begin_l);
this->expression_l = std::move(expression_l);
}

Restarg::Restarg(std::string name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->operator_l = std::move(operator_l);
this->name_l = std::move(name_l);
this->expression_l = std::move(expression_l);
}

Retry::Retry(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

Return::Return(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l)
{
this->args = std::move(args);
this->keyword_l = std::move(keyword_l);
this->expression_l = std::move(expression_l);
}

SClass::SClass(std::unique_ptr<Node> expr, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->expr = std::move(expr);
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->operator_l = std::move(operator_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Self_::Self_(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

Send::Send(std::unique_ptr<Node> recv, std::string method_name, std::vector<Node> args, std::unique_ptr<Loc> dot_l, std::unique_ptr<Loc> selector_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->recv = std::move(recv);
this->method_name = std::move(method_name);
this->args = std::move(args);
this->dot_l = std::move(dot_l);
this->selector_l = std::move(selector_l);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Shadowarg::Shadowarg(std::string name, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->expression_l = std::move(expression_l);
}

Splat::Splat(std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l)
{
this->value = std::move(value);
this->operator_l = std::move(operator_l);
this->expression_l = std::move(expression_l);
}

Str::Str(Bytes value, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->value = std::move(value);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Super::Super(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->args = std::move(args);
this->keyword_l = std::move(keyword_l);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Sym::Sym(Bytes name, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->name = std::move(name);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

True::True(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

Undef::Undef(std::vector<Node> names, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l)
{
this->names = std::move(names);
this->keyword_l = std::move(keyword_l);
this->expression_l = std::move(expression_l);
}

UnlessGuard::UnlessGuard(std::unique_ptr<Node> cond, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l)
{
this->cond = std::move(cond);
this->keyword_l = std::move(keyword_l);
this->expression_l = std::move(expression_l);
}

Until::Until(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->cond = std::move(cond);
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

UntilPost::UntilPost(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l)
{
this->cond = std::move(cond);
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->expression_l = std::move(expression_l);
}

When::When(std::vector<Node> patterns, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> expression_l)
{
this->patterns = std::move(patterns);
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->begin_l = std::move(begin_l);
this->expression_l = std::move(expression_l);
}

While::While(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->cond = std::move(cond);
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

WhilePost::WhilePost(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l)
{
this->cond = std::move(cond);
this->body = std::move(body);
this->keyword_l = std::move(keyword_l);
this->expression_l = std::move(expression_l);
}

XHeredoc::XHeredoc(std::vector<Node> parts, std::unique_ptr<Loc> heredoc_body_l, std::unique_ptr<Loc> heredoc_end_l, std::unique_ptr<Loc> expression_l)
{
this->parts = std::move(parts);
this->heredoc_body_l = std::move(heredoc_body_l);
this->heredoc_end_l = std::move(heredoc_end_l);
this->expression_l = std::move(expression_l);
}

Xstr::Xstr(std::vector<Node> parts, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->parts = std::move(parts);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

Yield::Yield(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l)
{
this->args = std::move(args);
this->keyword_l = std::move(keyword_l);
this->begin_l = std::move(begin_l);
this->end_l = std::move(end_l);
this->expression_l = std::move(expression_l);
}

ZSuper::ZSuper(std::unique_ptr<Loc> expression_l)
{
this->expression_l = std::move(expression_l);
}

}
