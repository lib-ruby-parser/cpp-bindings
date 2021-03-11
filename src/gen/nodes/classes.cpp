#include "classes.h"

namespace lib_ruby_parser {

Alias::Alias(std::unique_ptr<Node> to, std::unique_ptr<Node> from, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l):
    to(std::move(to)),
    from(std::move(from)),
    keyword_l(std::move(keyword_l)),
    expression_l(std::move(expression_l)) {}

AndAsgn::AndAsgn(std::unique_ptr<Node> recv, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    recv(std::move(recv)),
    value(std::move(value)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

And::And(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    lhs(std::move(lhs)),
    rhs(std::move(rhs)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Arg::Arg(std::string name, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    expression_l(std::move(expression_l)) {}

Args::Args(std::vector<Node> args, std::unique_ptr<Loc> expression_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l):
    args(std::move(args)),
    expression_l(std::move(expression_l)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)) {}

Array::Array(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    elements(std::move(elements)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

ArrayPattern::ArrayPattern(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    elements(std::move(elements)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

ArrayPatternWithTail::ArrayPatternWithTail(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    elements(std::move(elements)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

BackRef::BackRef(std::string name, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    expression_l(std::move(expression_l)) {}

Begin::Begin(std::vector<Node> statements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    statements(std::move(statements)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Block::Block(std::unique_ptr<Node> call, std::unique_ptr<Node> args, std::unique_ptr<Node> body, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    call(std::move(call)),
    args(std::move(args)),
    body(std::move(body)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

BlockPass::BlockPass(std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    value(std::move(value)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Blockarg::Blockarg(std::string name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    operator_l(std::move(operator_l)),
    name_l(std::move(name_l)),
    expression_l(std::move(expression_l)) {}

Break::Break(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l):
    args(std::move(args)),
    keyword_l(std::move(keyword_l)),
    expression_l(std::move(expression_l)) {}

Case::Case(std::unique_ptr<Node> expr, std::vector<Node> when_bodies, std::unique_ptr<Node> else_body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    expr(std::move(expr)),
    when_bodies(std::move(when_bodies)),
    else_body(std::move(else_body)),
    keyword_l(std::move(keyword_l)),
    else_l(std::move(else_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

CaseMatch::CaseMatch(std::unique_ptr<Node> expr, std::vector<Node> in_bodies, std::unique_ptr<Node> else_body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    expr(std::move(expr)),
    in_bodies(std::move(in_bodies)),
    else_body(std::move(else_body)),
    keyword_l(std::move(keyword_l)),
    else_l(std::move(else_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Casgn::Casgn(std::unique_ptr<Node> scope, std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> double_colon_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    scope(std::move(scope)),
    name(std::move(name)),
    value(std::move(value)),
    double_colon_l(std::move(double_colon_l)),
    name_l(std::move(name_l)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Cbase::Cbase(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

Class::Class(std::unique_ptr<Node> name, std::unique_ptr<Node> superclass, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    superclass(std::move(superclass)),
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    operator_l(std::move(operator_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Complex::Complex(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    value(std::move(value)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Const::Const(std::unique_ptr<Node> scope, std::string name, std::unique_ptr<Loc> double_colon_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l):
    scope(std::move(scope)),
    name(std::move(name)),
    double_colon_l(std::move(double_colon_l)),
    name_l(std::move(name_l)),
    expression_l(std::move(expression_l)) {}

ConstPattern::ConstPattern(std::unique_ptr<Node> const_, std::unique_ptr<Node> pattern, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    const_(std::move(const_)),
    pattern(std::move(pattern)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

CSend::CSend(std::unique_ptr<Node> recv, std::string method_name, std::vector<Node> args, std::unique_ptr<Loc> dot_l, std::unique_ptr<Loc> selector_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    recv(std::move(recv)),
    method_name(std::move(method_name)),
    args(std::move(args)),
    dot_l(std::move(dot_l)),
    selector_l(std::move(selector_l)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Cvar::Cvar(std::string name, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    expression_l(std::move(expression_l)) {}

Cvasgn::Cvasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    value(std::move(value)),
    name_l(std::move(name_l)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Def::Def(std::string name, std::unique_ptr<Node> args, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> assignment_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    args(std::move(args)),
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    name_l(std::move(name_l)),
    end_l(std::move(end_l)),
    assignment_l(std::move(assignment_l)),
    expression_l(std::move(expression_l)) {}

Defined::Defined(std::unique_ptr<Node> value, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    value(std::move(value)),
    keyword_l(std::move(keyword_l)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Defs::Defs(std::unique_ptr<Node> definee, std::string name, std::unique_ptr<Node> args, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> assignment_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    definee(std::move(definee)),
    name(std::move(name)),
    args(std::move(args)),
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    operator_l(std::move(operator_l)),
    name_l(std::move(name_l)),
    assignment_l(std::move(assignment_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Dstr::Dstr(std::vector<Node> parts, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    parts(std::move(parts)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Dsym::Dsym(std::vector<Node> parts, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    parts(std::move(parts)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

EFlipFlop::EFlipFlop(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    left(std::move(left)),
    right(std::move(right)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

EmptyElse::EmptyElse(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

Encoding::Encoding(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

Ensure::Ensure(std::unique_ptr<Node> body, std::unique_ptr<Node> ensure, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l):
    body(std::move(body)),
    ensure(std::move(ensure)),
    keyword_l(std::move(keyword_l)),
    expression_l(std::move(expression_l)) {}

Erange::Erange(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    left(std::move(left)),
    right(std::move(right)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

False::False(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

File::File(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

FindPattern::FindPattern(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    elements(std::move(elements)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Float::Float(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    value(std::move(value)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

For::For(std::unique_ptr<Node> iterator, std::unique_ptr<Node> iteratee, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    iterator(std::move(iterator)),
    iteratee(std::move(iteratee)),
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    operator_l(std::move(operator_l)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

ForwardArg::ForwardArg(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

ForwardedArgs::ForwardedArgs(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

Gvar::Gvar(std::string name, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    expression_l(std::move(expression_l)) {}

Gvasgn::Gvasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    value(std::move(value)),
    name_l(std::move(name_l)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Hash::Hash(std::vector<Node> pairs, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    pairs(std::move(pairs)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Kwargs::Kwargs(std::vector<Node> pairs, std::unique_ptr<Loc> expression_l):
    pairs(std::move(pairs)),
    expression_l(std::move(expression_l)) {}

HashPattern::HashPattern(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    elements(std::move(elements)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Heredoc::Heredoc(std::vector<Node> parts, std::unique_ptr<Loc> heredoc_body_l, std::unique_ptr<Loc> heredoc_end_l, std::unique_ptr<Loc> expression_l):
    parts(std::move(parts)),
    heredoc_body_l(std::move(heredoc_body_l)),
    heredoc_end_l(std::move(heredoc_end_l)),
    expression_l(std::move(expression_l)) {}

If::If(std::unique_ptr<Node> cond, std::unique_ptr<Node> if_true, std::unique_ptr<Node> if_false, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    cond(std::move(cond)),
    if_true(std::move(if_true)),
    if_false(std::move(if_false)),
    keyword_l(std::move(keyword_l)),
    begin_l(std::move(begin_l)),
    else_l(std::move(else_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

IfGuard::IfGuard(std::unique_ptr<Node> cond, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l):
    cond(std::move(cond)),
    keyword_l(std::move(keyword_l)),
    expression_l(std::move(expression_l)) {}

IfMod::IfMod(std::unique_ptr<Node> cond, std::unique_ptr<Node> if_true, std::unique_ptr<Node> if_false, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l):
    cond(std::move(cond)),
    if_true(std::move(if_true)),
    if_false(std::move(if_false)),
    keyword_l(std::move(keyword_l)),
    expression_l(std::move(expression_l)) {}

IfTernary::IfTernary(std::unique_ptr<Node> cond, std::unique_ptr<Node> if_true, std::unique_ptr<Node> if_false, std::unique_ptr<Loc> question_l, std::unique_ptr<Loc> colon_l, std::unique_ptr<Loc> expression_l):
    cond(std::move(cond)),
    if_true(std::move(if_true)),
    if_false(std::move(if_false)),
    question_l(std::move(question_l)),
    colon_l(std::move(colon_l)),
    expression_l(std::move(expression_l)) {}

IFlipFlop::IFlipFlop(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    left(std::move(left)),
    right(std::move(right)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

MatchPattern::MatchPattern(std::unique_ptr<Node> value, std::unique_ptr<Node> pattern, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    value(std::move(value)),
    pattern(std::move(pattern)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

MatchPatternP::MatchPatternP(std::unique_ptr<Node> value, std::unique_ptr<Node> pattern, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    value(std::move(value)),
    pattern(std::move(pattern)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

InPattern::InPattern(std::unique_ptr<Node> pattern, std::unique_ptr<Node> guard, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> expression_l):
    pattern(std::move(pattern)),
    guard(std::move(guard)),
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    begin_l(std::move(begin_l)),
    expression_l(std::move(expression_l)) {}

Index::Index(std::unique_ptr<Node> recv, std::vector<Node> indexes, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    recv(std::move(recv)),
    indexes(std::move(indexes)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

IndexAsgn::IndexAsgn(std::unique_ptr<Node> recv, std::vector<Node> indexes, std::unique_ptr<Node> value, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    recv(std::move(recv)),
    indexes(std::move(indexes)),
    value(std::move(value)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Int::Int(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    value(std::move(value)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Irange::Irange(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    left(std::move(left)),
    right(std::move(right)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Ivar::Ivar(std::string name, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    expression_l(std::move(expression_l)) {}

Ivasgn::Ivasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    value(std::move(value)),
    name_l(std::move(name_l)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Kwarg::Kwarg(std::string name, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    name_l(std::move(name_l)),
    expression_l(std::move(expression_l)) {}

KwBegin::KwBegin(std::vector<Node> statements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    statements(std::move(statements)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Kwnilarg::Kwnilarg(std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l):
    name_l(std::move(name_l)),
    expression_l(std::move(expression_l)) {}

Kwoptarg::Kwoptarg(std::string name, std::unique_ptr<Node> default_, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    default_(std::move(default_)),
    name_l(std::move(name_l)),
    expression_l(std::move(expression_l)) {}

Kwrestarg::Kwrestarg(std::string name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    operator_l(std::move(operator_l)),
    name_l(std::move(name_l)),
    expression_l(std::move(expression_l)) {}

Kwsplat::Kwsplat(std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    value(std::move(value)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Lambda::Lambda(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

Line::Line(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

Lvar::Lvar(std::string name, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    expression_l(std::move(expression_l)) {}

Lvasgn::Lvasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    value(std::move(value)),
    name_l(std::move(name_l)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Masgn::Masgn(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    lhs(std::move(lhs)),
    rhs(std::move(rhs)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

MatchAlt::MatchAlt(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    lhs(std::move(lhs)),
    rhs(std::move(rhs)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

MatchAs::MatchAs(std::unique_ptr<Node> value, std::unique_ptr<Node> as_, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    value(std::move(value)),
    as_(std::move(as_)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

MatchCurrentLine::MatchCurrentLine(std::unique_ptr<Node> re, std::unique_ptr<Loc> expression_l):
    re(std::move(re)),
    expression_l(std::move(expression_l)) {}

MatchNilPattern::MatchNilPattern(std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l):
    operator_l(std::move(operator_l)),
    name_l(std::move(name_l)),
    expression_l(std::move(expression_l)) {}

MatchRest::MatchRest(std::unique_ptr<Node> name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

MatchVar::MatchVar(std::string name, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    name_l(std::move(name_l)),
    expression_l(std::move(expression_l)) {}

MatchWithLvasgn::MatchWithLvasgn(std::unique_ptr<Node> re, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    re(std::move(re)),
    value(std::move(value)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Mlhs::Mlhs(std::vector<Node> items, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    items(std::move(items)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Module::Module(std::unique_ptr<Node> name, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Next::Next(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l):
    args(std::move(args)),
    keyword_l(std::move(keyword_l)),
    expression_l(std::move(expression_l)) {}

Nil::Nil(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

NthRef::NthRef(std::string name, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    expression_l(std::move(expression_l)) {}

Numblock::Numblock(std::unique_ptr<Node> call, uint32_t numargs, std::unique_ptr<Node> body, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    call(std::move(call)),
    numargs(numargs),
    body(std::move(body)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

OpAsgn::OpAsgn(std::unique_ptr<Node> recv, std::string operator_, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    recv(std::move(recv)),
    operator_(std::move(operator_)),
    value(std::move(value)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Optarg::Optarg(std::string name, std::unique_ptr<Node> default_, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    default_(std::move(default_)),
    name_l(std::move(name_l)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Or::Or(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    lhs(std::move(lhs)),
    rhs(std::move(rhs)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

OrAsgn::OrAsgn(std::unique_ptr<Node> recv, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    recv(std::move(recv)),
    value(std::move(value)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Pair::Pair(std::unique_ptr<Node> key, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    key(std::move(key)),
    value(std::move(value)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Pin::Pin(std::unique_ptr<Node> var, std::unique_ptr<Loc> selector_l, std::unique_ptr<Loc> expression_l):
    var(std::move(var)),
    selector_l(std::move(selector_l)),
    expression_l(std::move(expression_l)) {}

Postexe::Postexe(std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Preexe::Preexe(std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Procarg0::Procarg0(std::vector<Node> args, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    args(std::move(args)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Rational::Rational(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    value(std::move(value)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Redo::Redo(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

RegOpt::RegOpt(std::string options, std::unique_ptr<Loc> expression_l):
    options(std::move(options)),
    expression_l(std::move(expression_l)) {}

Regexp::Regexp(std::vector<Node> parts, std::unique_ptr<Node> options, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    parts(std::move(parts)),
    options(std::move(options)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Rescue::Rescue(std::unique_ptr<Node> body, std::vector<Node> rescue_bodies, std::unique_ptr<Node> else_, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> expression_l):
    body(std::move(body)),
    rescue_bodies(std::move(rescue_bodies)),
    else_(std::move(else_)),
    else_l(std::move(else_l)),
    expression_l(std::move(expression_l)) {}

RescueBody::RescueBody(std::unique_ptr<Node> exc_list, std::unique_ptr<Node> exc_var, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> assoc_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> expression_l):
    exc_list(std::move(exc_list)),
    exc_var(std::move(exc_var)),
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    assoc_l(std::move(assoc_l)),
    begin_l(std::move(begin_l)),
    expression_l(std::move(expression_l)) {}

Restarg::Restarg(std::string name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    operator_l(std::move(operator_l)),
    name_l(std::move(name_l)),
    expression_l(std::move(expression_l)) {}

Retry::Retry(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

Return::Return(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l):
    args(std::move(args)),
    keyword_l(std::move(keyword_l)),
    expression_l(std::move(expression_l)) {}

SClass::SClass(std::unique_ptr<Node> expr, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    expr(std::move(expr)),
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    operator_l(std::move(operator_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Self_::Self_(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

Send::Send(std::unique_ptr<Node> recv, std::string method_name, std::vector<Node> args, std::unique_ptr<Loc> dot_l, std::unique_ptr<Loc> selector_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    recv(std::move(recv)),
    method_name(std::move(method_name)),
    args(std::move(args)),
    dot_l(std::move(dot_l)),
    selector_l(std::move(selector_l)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Shadowarg::Shadowarg(std::string name, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    expression_l(std::move(expression_l)) {}

Splat::Splat(std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l):
    value(std::move(value)),
    operator_l(std::move(operator_l)),
    expression_l(std::move(expression_l)) {}

Str::Str(Bytes value, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    value(std::move(value)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Super::Super(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    args(std::move(args)),
    keyword_l(std::move(keyword_l)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Sym::Sym(Bytes name, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    name(std::move(name)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

True::True(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}

Undef::Undef(std::vector<Node> names, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l):
    names(std::move(names)),
    keyword_l(std::move(keyword_l)),
    expression_l(std::move(expression_l)) {}

UnlessGuard::UnlessGuard(std::unique_ptr<Node> cond, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l):
    cond(std::move(cond)),
    keyword_l(std::move(keyword_l)),
    expression_l(std::move(expression_l)) {}

Until::Until(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    cond(std::move(cond)),
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

UntilPost::UntilPost(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l):
    cond(std::move(cond)),
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    expression_l(std::move(expression_l)) {}

When::When(std::vector<Node> patterns, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> expression_l):
    patterns(std::move(patterns)),
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    begin_l(std::move(begin_l)),
    expression_l(std::move(expression_l)) {}

While::While(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    cond(std::move(cond)),
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

WhilePost::WhilePost(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l):
    cond(std::move(cond)),
    body(std::move(body)),
    keyword_l(std::move(keyword_l)),
    expression_l(std::move(expression_l)) {}

XHeredoc::XHeredoc(std::vector<Node> parts, std::unique_ptr<Loc> heredoc_body_l, std::unique_ptr<Loc> heredoc_end_l, std::unique_ptr<Loc> expression_l):
    parts(std::move(parts)),
    heredoc_body_l(std::move(heredoc_body_l)),
    heredoc_end_l(std::move(heredoc_end_l)),
    expression_l(std::move(expression_l)) {}

Xstr::Xstr(std::vector<Node> parts, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    parts(std::move(parts)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

Yield::Yield(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l):
    args(std::move(args)),
    keyword_l(std::move(keyword_l)),
    begin_l(std::move(begin_l)),
    end_l(std::move(end_l)),
    expression_l(std::move(expression_l)) {}

ZSuper::ZSuper(std::unique_ptr<Loc> expression_l):
    expression_l(std::move(expression_l)) {}


}
