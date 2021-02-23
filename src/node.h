#ifndef LIB_RUBY_PARSER_NODE_H
#define LIB_RUBY_PARSER_NODE_H

#include <memory>
#include <vector>
#include <string>
#include <variant>
#include "loc.h"
#include "bytes.h"

namespace lib_ruby_parser {

class Node;

class Alias
{
public:
    std::unique_ptr<Node> to;
    std::unique_ptr<Node> from;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> expression_l;

    Alias() = delete;
    Alias(Alias &&) = default;
    Alias(const Alias &) = delete;
    explicit Alias(std::unique_ptr<Node> to, std::unique_ptr<Node> from, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

class AndAsgn
{
public:
    std::unique_ptr<Node> recv;
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    AndAsgn() = delete;
    AndAsgn(AndAsgn &&) = default;
    AndAsgn(const AndAsgn &) = delete;
    explicit AndAsgn(std::unique_ptr<Node> recv, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class And
{
public:
    std::unique_ptr<Node> lhs;
    std::unique_ptr<Node> rhs;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    And() = delete;
    And(And &&) = default;
    And(const And &) = delete;
    explicit And(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Arg
{
public:
    std::string name;
    std::unique_ptr<Loc> expression_l;

    Arg() = delete;
    Arg(Arg &&) = default;
    Arg(const Arg &) = delete;
    explicit Arg(std::string name, std::unique_ptr<Loc> expression_l);
};

class Args
{
public:
    std::vector<Node> args;
    std::unique_ptr<Loc> expression_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;

    Args() = delete;
    Args(Args &&) = default;
    Args(const Args &) = delete;
    explicit Args(std::vector<Node> args, std::unique_ptr<Loc> expression_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l);
};

class Array
{
public:
    std::vector<Node> elements;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Array() = delete;
    Array(Array &&) = default;
    Array(const Array &) = delete;
    explicit Array(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class ArrayPattern
{
public:
    std::vector<Node> elements;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    ArrayPattern() = delete;
    ArrayPattern(ArrayPattern &&) = default;
    ArrayPattern(const ArrayPattern &) = delete;
    explicit ArrayPattern(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class ArrayPatternWithTail
{
public:
    std::vector<Node> elements;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    ArrayPatternWithTail() = delete;
    ArrayPatternWithTail(ArrayPatternWithTail &&) = default;
    ArrayPatternWithTail(const ArrayPatternWithTail &) = delete;
    explicit ArrayPatternWithTail(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class BackRef
{
public:
    std::string name;
    std::unique_ptr<Loc> expression_l;

    BackRef() = delete;
    BackRef(BackRef &&) = default;
    BackRef(const BackRef &) = delete;
    explicit BackRef(std::string name, std::unique_ptr<Loc> expression_l);
};

class Begin
{
public:
    std::vector<Node> statements;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Begin() = delete;
    Begin(Begin &&) = default;
    Begin(const Begin &) = delete;
    explicit Begin(std::vector<Node> statements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Block
{
public:
    std::unique_ptr<Node> call;
    std::unique_ptr<Node> args;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Block() = delete;
    Block(Block &&) = default;
    Block(const Block &) = delete;
    explicit Block(std::unique_ptr<Node> call, std::unique_ptr<Node> args, std::unique_ptr<Node> body, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class BlockPass
{
public:
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    BlockPass() = delete;
    BlockPass(BlockPass &&) = default;
    BlockPass(const BlockPass &) = delete;
    explicit BlockPass(std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Blockarg
{
public:
    std::string name;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> expression_l;

    Blockarg() = delete;
    Blockarg(Blockarg &&) = default;
    Blockarg(const Blockarg &) = delete;
    explicit Blockarg(std::string name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

class Break
{
public:
    std::vector<Node> args;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> expression_l;

    Break() = delete;
    Break(Break &&) = default;
    Break(const Break &) = delete;
    explicit Break(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

class Case
{
public:
    std::unique_ptr<Node> expr;
    std::vector<Node> when_bodies;
    std::unique_ptr<Node> else_body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> else_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Case() = delete;
    Case(Case &&) = default;
    Case(const Case &) = delete;
    explicit Case(std::unique_ptr<Node> expr, std::vector<Node> when_bodies, std::unique_ptr<Node> else_body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class CaseMatch
{
public:
    std::unique_ptr<Node> expr;
    std::vector<Node> in_bodies;
    std::unique_ptr<Node> else_body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> else_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    CaseMatch() = delete;
    CaseMatch(CaseMatch &&) = default;
    CaseMatch(const CaseMatch &) = delete;
    explicit CaseMatch(std::unique_ptr<Node> expr, std::vector<Node> in_bodies, std::unique_ptr<Node> else_body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Casgn
{
public:
    std::unique_ptr<Node> scope;
    std::string name;
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> double_colon_l;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Casgn() = delete;
    Casgn(Casgn &&) = default;
    Casgn(const Casgn &) = delete;
    explicit Casgn(std::unique_ptr<Node> scope, std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> double_colon_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Cbase
{
public:
    std::unique_ptr<Loc> expression_l;

    Cbase() = delete;
    Cbase(Cbase &&) = default;
    Cbase(const Cbase &) = delete;
    explicit Cbase(std::unique_ptr<Loc> expression_l);
};

class Class
{
public:
    std::unique_ptr<Node> name;
    std::unique_ptr<Node> superclass;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Class() = delete;
    Class(Class &&) = default;
    Class(const Class &) = delete;
    explicit Class(std::unique_ptr<Node> name, std::unique_ptr<Node> superclass, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Complex
{
public:
    std::string value;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Complex() = delete;
    Complex(Complex &&) = default;
    Complex(const Complex &) = delete;
    explicit Complex(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Const
{
public:
    std::unique_ptr<Node> scope;
    std::string name;
    std::unique_ptr<Loc> double_colon_l;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> expression_l;

    Const() = delete;
    Const(Const &&) = default;
    Const(const Const &) = delete;
    explicit Const(std::unique_ptr<Node> scope, std::string name, std::unique_ptr<Loc> double_colon_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

class ConstPattern
{
public:
    std::unique_ptr<Node> const_;
    std::unique_ptr<Node> pattern;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    ConstPattern() = delete;
    ConstPattern(ConstPattern &&) = default;
    ConstPattern(const ConstPattern &) = delete;
    explicit ConstPattern(std::unique_ptr<Node> const_, std::unique_ptr<Node> pattern, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class CSend
{
public:
    std::unique_ptr<Node> recv;
    std::string method_name;
    std::vector<Node> args;
    std::unique_ptr<Loc> dot_l;
    std::unique_ptr<Loc> selector_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    CSend() = delete;
    CSend(CSend &&) = default;
    CSend(const CSend &) = delete;
    explicit CSend(std::unique_ptr<Node> recv, std::string method_name, std::vector<Node> args, std::unique_ptr<Loc> dot_l, std::unique_ptr<Loc> selector_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Cvar
{
public:
    std::string name;
    std::unique_ptr<Loc> expression_l;

    Cvar() = delete;
    Cvar(Cvar &&) = default;
    Cvar(const Cvar &) = delete;
    explicit Cvar(std::string name, std::unique_ptr<Loc> expression_l);
};

class Cvasgn
{
public:
    std::string name;
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Cvasgn() = delete;
    Cvasgn(Cvasgn &&) = default;
    Cvasgn(const Cvasgn &) = delete;
    explicit Cvasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Def
{
public:
    std::string name;
    std::unique_ptr<Node> args;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> assignment_l;
    std::unique_ptr<Loc> expression_l;

    Def() = delete;
    Def(Def &&) = default;
    Def(const Def &) = delete;
    explicit Def(std::string name, std::unique_ptr<Node> args, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> assignment_l, std::unique_ptr<Loc> expression_l);
};

class Defined
{
public:
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Defined() = delete;
    Defined(Defined &&) = default;
    Defined(const Defined &) = delete;
    explicit Defined(std::unique_ptr<Node> value, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Defs
{
public:
    std::unique_ptr<Node> definee;
    std::string name;
    std::unique_ptr<Node> args;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> assignment_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Defs() = delete;
    Defs(Defs &&) = default;
    Defs(const Defs &) = delete;
    explicit Defs(std::unique_ptr<Node> definee, std::string name, std::unique_ptr<Node> args, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> assignment_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Dstr
{
public:
    std::vector<Node> parts;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Dstr() = delete;
    Dstr(Dstr &&) = default;
    Dstr(const Dstr &) = delete;
    explicit Dstr(std::vector<Node> parts, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Dsym
{
public:
    std::vector<Node> parts;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Dsym() = delete;
    Dsym(Dsym &&) = default;
    Dsym(const Dsym &) = delete;
    explicit Dsym(std::vector<Node> parts, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class EFlipFlop
{
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    EFlipFlop() = delete;
    EFlipFlop(EFlipFlop &&) = default;
    EFlipFlop(const EFlipFlop &) = delete;
    explicit EFlipFlop(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class EmptyElse
{
public:
    std::unique_ptr<Loc> expression_l;

    EmptyElse() = delete;
    EmptyElse(EmptyElse &&) = default;
    EmptyElse(const EmptyElse &) = delete;
    explicit EmptyElse(std::unique_ptr<Loc> expression_l);
};

class Encoding
{
public:
    std::unique_ptr<Loc> expression_l;

    Encoding() = delete;
    Encoding(Encoding &&) = default;
    Encoding(const Encoding &) = delete;
    explicit Encoding(std::unique_ptr<Loc> expression_l);
};

class Ensure
{
public:
    std::unique_ptr<Node> body;
    std::unique_ptr<Node> ensure;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> expression_l;

    Ensure() = delete;
    Ensure(Ensure &&) = default;
    Ensure(const Ensure &) = delete;
    explicit Ensure(std::unique_ptr<Node> body, std::unique_ptr<Node> ensure, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

class Erange
{
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Erange() = delete;
    Erange(Erange &&) = default;
    Erange(const Erange &) = delete;
    explicit Erange(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class False
{
public:
    std::unique_ptr<Loc> expression_l;

    False() = delete;
    False(False &&) = default;
    False(const False &) = delete;
    explicit False(std::unique_ptr<Loc> expression_l);
};

class File
{
public:
    std::unique_ptr<Loc> expression_l;

    File() = delete;
    File(File &&) = default;
    File(const File &) = delete;
    explicit File(std::unique_ptr<Loc> expression_l);
};

class FindPattern
{
public:
    std::vector<Node> elements;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    FindPattern() = delete;
    FindPattern(FindPattern &&) = default;
    FindPattern(const FindPattern &) = delete;
    explicit FindPattern(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Float
{
public:
    std::string value;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Float() = delete;
    Float(Float &&) = default;
    Float(const Float &) = delete;
    explicit Float(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class For
{
public:
    std::unique_ptr<Node> iterator;
    std::unique_ptr<Node> iteratee;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    For() = delete;
    For(For &&) = default;
    For(const For &) = delete;
    explicit For(std::unique_ptr<Node> iterator, std::unique_ptr<Node> iteratee, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class ForwardArg
{
public:
    std::unique_ptr<Loc> expression_l;

    ForwardArg() = delete;
    ForwardArg(ForwardArg &&) = default;
    ForwardArg(const ForwardArg &) = delete;
    explicit ForwardArg(std::unique_ptr<Loc> expression_l);
};

class ForwardedArgs
{
public:
    std::unique_ptr<Loc> expression_l;

    ForwardedArgs() = delete;
    ForwardedArgs(ForwardedArgs &&) = default;
    ForwardedArgs(const ForwardedArgs &) = delete;
    explicit ForwardedArgs(std::unique_ptr<Loc> expression_l);
};

class Gvar
{
public:
    std::string name;
    std::unique_ptr<Loc> expression_l;

    Gvar() = delete;
    Gvar(Gvar &&) = default;
    Gvar(const Gvar &) = delete;
    explicit Gvar(std::string name, std::unique_ptr<Loc> expression_l);
};

class Gvasgn
{
public:
    std::string name;
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Gvasgn() = delete;
    Gvasgn(Gvasgn &&) = default;
    Gvasgn(const Gvasgn &) = delete;
    explicit Gvasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Hash
{
public:
    std::vector<Node> pairs;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Hash() = delete;
    Hash(Hash &&) = default;
    Hash(const Hash &) = delete;
    explicit Hash(std::vector<Node> pairs, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Kwargs
{
public:
    std::vector<Node> pairs;
    std::unique_ptr<Loc> expression_l;

    Kwargs() = delete;
    Kwargs(Kwargs &&) = default;
    Kwargs(const Kwargs &) = delete;
    explicit Kwargs(std::vector<Node> pairs, std::unique_ptr<Loc> expression_l);
};

class HashPattern
{
public:
    std::vector<Node> elements;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    HashPattern() = delete;
    HashPattern(HashPattern &&) = default;
    HashPattern(const HashPattern &) = delete;
    explicit HashPattern(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Heredoc
{
public:
    std::vector<Node> parts;
    std::unique_ptr<Loc> heredoc_body_l;
    std::unique_ptr<Loc> heredoc_end_l;
    std::unique_ptr<Loc> expression_l;

    Heredoc() = delete;
    Heredoc(Heredoc &&) = default;
    Heredoc(const Heredoc &) = delete;
    explicit Heredoc(std::vector<Node> parts, std::unique_ptr<Loc> heredoc_body_l, std::unique_ptr<Loc> heredoc_end_l, std::unique_ptr<Loc> expression_l);
};

class If
{
public:
    std::unique_ptr<Node> cond;
    std::unique_ptr<Node> if_true;
    std::unique_ptr<Node> if_false;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> else_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    If() = delete;
    If(If &&) = default;
    If(const If &) = delete;
    explicit If(std::unique_ptr<Node> cond, std::unique_ptr<Node> if_true, std::unique_ptr<Node> if_false, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class IfGuard
{
public:
    std::unique_ptr<Node> cond;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> expression_l;

    IfGuard() = delete;
    IfGuard(IfGuard &&) = default;
    IfGuard(const IfGuard &) = delete;
    explicit IfGuard(std::unique_ptr<Node> cond, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

class IfMod
{
public:
    std::unique_ptr<Node> cond;
    std::unique_ptr<Node> if_true;
    std::unique_ptr<Node> if_false;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> expression_l;

    IfMod() = delete;
    IfMod(IfMod &&) = default;
    IfMod(const IfMod &) = delete;
    explicit IfMod(std::unique_ptr<Node> cond, std::unique_ptr<Node> if_true, std::unique_ptr<Node> if_false, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

class IfTernary
{
public:
    std::unique_ptr<Node> cond;
    std::unique_ptr<Node> if_true;
    std::unique_ptr<Node> if_false;
    std::unique_ptr<Loc> question_l;
    std::unique_ptr<Loc> colon_l;
    std::unique_ptr<Loc> expression_l;

    IfTernary() = delete;
    IfTernary(IfTernary &&) = default;
    IfTernary(const IfTernary &) = delete;
    explicit IfTernary(std::unique_ptr<Node> cond, std::unique_ptr<Node> if_true, std::unique_ptr<Node> if_false, std::unique_ptr<Loc> question_l, std::unique_ptr<Loc> colon_l, std::unique_ptr<Loc> expression_l);
};

class IFlipFlop
{
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    IFlipFlop() = delete;
    IFlipFlop(IFlipFlop &&) = default;
    IFlipFlop(const IFlipFlop &) = delete;
    explicit IFlipFlop(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class MatchPattern
{
public:
    std::unique_ptr<Node> value;
    std::unique_ptr<Node> pattern;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    MatchPattern() = delete;
    MatchPattern(MatchPattern &&) = default;
    MatchPattern(const MatchPattern &) = delete;
    explicit MatchPattern(std::unique_ptr<Node> value, std::unique_ptr<Node> pattern, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class MatchPatternP
{
public:
    std::unique_ptr<Node> value;
    std::unique_ptr<Node> pattern;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    MatchPatternP() = delete;
    MatchPatternP(MatchPatternP &&) = default;
    MatchPatternP(const MatchPatternP &) = delete;
    explicit MatchPatternP(std::unique_ptr<Node> value, std::unique_ptr<Node> pattern, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class InPattern
{
public:
    std::unique_ptr<Node> pattern;
    std::unique_ptr<Node> guard;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> expression_l;

    InPattern() = delete;
    InPattern(InPattern &&) = default;
    InPattern(const InPattern &) = delete;
    explicit InPattern(std::unique_ptr<Node> pattern, std::unique_ptr<Node> guard, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> expression_l);
};

class Index
{
public:
    std::unique_ptr<Node> recv;
    std::vector<Node> indexes;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Index() = delete;
    Index(Index &&) = default;
    Index(const Index &) = delete;
    explicit Index(std::unique_ptr<Node> recv, std::vector<Node> indexes, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class IndexAsgn
{
public:
    std::unique_ptr<Node> recv;
    std::vector<Node> indexes;
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    IndexAsgn() = delete;
    IndexAsgn(IndexAsgn &&) = default;
    IndexAsgn(const IndexAsgn &) = delete;
    explicit IndexAsgn(std::unique_ptr<Node> recv, std::vector<Node> indexes, std::unique_ptr<Node> value, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Int
{
public:
    std::string value;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Int() = delete;
    Int(Int &&) = default;
    Int(const Int &) = delete;
    explicit Int(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Irange
{
public:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Irange() = delete;
    Irange(Irange &&) = default;
    Irange(const Irange &) = delete;
    explicit Irange(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Ivar
{
public:
    std::string name;
    std::unique_ptr<Loc> expression_l;

    Ivar() = delete;
    Ivar(Ivar &&) = default;
    Ivar(const Ivar &) = delete;
    explicit Ivar(std::string name, std::unique_ptr<Loc> expression_l);
};

class Ivasgn
{
public:
    std::string name;
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Ivasgn() = delete;
    Ivasgn(Ivasgn &&) = default;
    Ivasgn(const Ivasgn &) = delete;
    explicit Ivasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Kwarg
{
public:
    std::string name;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> expression_l;

    Kwarg() = delete;
    Kwarg(Kwarg &&) = default;
    Kwarg(const Kwarg &) = delete;
    explicit Kwarg(std::string name, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

class KwBegin
{
public:
    std::vector<Node> statements;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    KwBegin() = delete;
    KwBegin(KwBegin &&) = default;
    KwBegin(const KwBegin &) = delete;
    explicit KwBegin(std::vector<Node> statements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Kwnilarg
{
public:
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> expression_l;

    Kwnilarg() = delete;
    Kwnilarg(Kwnilarg &&) = default;
    Kwnilarg(const Kwnilarg &) = delete;
    explicit Kwnilarg(std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

class Kwoptarg
{
public:
    std::string name;
    std::unique_ptr<Node> default_;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> expression_l;

    Kwoptarg() = delete;
    Kwoptarg(Kwoptarg &&) = default;
    Kwoptarg(const Kwoptarg &) = delete;
    explicit Kwoptarg(std::string name, std::unique_ptr<Node> default_, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

class Kwrestarg
{
public:
    std::string name;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> expression_l;

    Kwrestarg() = delete;
    Kwrestarg(Kwrestarg &&) = default;
    Kwrestarg(const Kwrestarg &) = delete;
    explicit Kwrestarg(std::string name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

class Kwsplat
{
public:
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Kwsplat() = delete;
    Kwsplat(Kwsplat &&) = default;
    Kwsplat(const Kwsplat &) = delete;
    explicit Kwsplat(std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Lambda
{
public:
    std::unique_ptr<Loc> expression_l;

    Lambda() = delete;
    Lambda(Lambda &&) = default;
    Lambda(const Lambda &) = delete;
    explicit Lambda(std::unique_ptr<Loc> expression_l);
};

class Line
{
public:
    std::unique_ptr<Loc> expression_l;

    Line() = delete;
    Line(Line &&) = default;
    Line(const Line &) = delete;
    explicit Line(std::unique_ptr<Loc> expression_l);
};

class Lvar
{
public:
    std::string name;
    std::unique_ptr<Loc> expression_l;

    Lvar() = delete;
    Lvar(Lvar &&) = default;
    Lvar(const Lvar &) = delete;
    explicit Lvar(std::string name, std::unique_ptr<Loc> expression_l);
};

class Lvasgn
{
public:
    std::string name;
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Lvasgn() = delete;
    Lvasgn(Lvasgn &&) = default;
    Lvasgn(const Lvasgn &) = delete;
    explicit Lvasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Masgn
{
public:
    std::unique_ptr<Node> lhs;
    std::unique_ptr<Node> rhs;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Masgn() = delete;
    Masgn(Masgn &&) = default;
    Masgn(const Masgn &) = delete;
    explicit Masgn(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class MatchAlt
{
public:
    std::unique_ptr<Node> lhs;
    std::unique_ptr<Node> rhs;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    MatchAlt() = delete;
    MatchAlt(MatchAlt &&) = default;
    MatchAlt(const MatchAlt &) = delete;
    explicit MatchAlt(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class MatchAs
{
public:
    std::unique_ptr<Node> value;
    std::unique_ptr<Node> as_;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    MatchAs() = delete;
    MatchAs(MatchAs &&) = default;
    MatchAs(const MatchAs &) = delete;
    explicit MatchAs(std::unique_ptr<Node> value, std::unique_ptr<Node> as_, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class MatchCurrentLine
{
public:
    std::unique_ptr<Node> re;
    std::unique_ptr<Loc> expression_l;

    MatchCurrentLine() = delete;
    MatchCurrentLine(MatchCurrentLine &&) = default;
    MatchCurrentLine(const MatchCurrentLine &) = delete;
    explicit MatchCurrentLine(std::unique_ptr<Node> re, std::unique_ptr<Loc> expression_l);
};

class MatchNilPattern
{
public:
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> expression_l;

    MatchNilPattern() = delete;
    MatchNilPattern(MatchNilPattern &&) = default;
    MatchNilPattern(const MatchNilPattern &) = delete;
    explicit MatchNilPattern(std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

class MatchRest
{
public:
    std::unique_ptr<Node> name;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    MatchRest() = delete;
    MatchRest(MatchRest &&) = default;
    MatchRest(const MatchRest &) = delete;
    explicit MatchRest(std::unique_ptr<Node> name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class MatchVar
{
public:
    std::string name;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> expression_l;

    MatchVar() = delete;
    MatchVar(MatchVar &&) = default;
    MatchVar(const MatchVar &) = delete;
    explicit MatchVar(std::string name, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

class MatchWithLvasgn
{
public:
    std::unique_ptr<Node> re;
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    MatchWithLvasgn() = delete;
    MatchWithLvasgn(MatchWithLvasgn &&) = default;
    MatchWithLvasgn(const MatchWithLvasgn &) = delete;
    explicit MatchWithLvasgn(std::unique_ptr<Node> re, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Mlhs
{
public:
    std::vector<Node> items;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Mlhs() = delete;
    Mlhs(Mlhs &&) = default;
    Mlhs(const Mlhs &) = delete;
    explicit Mlhs(std::vector<Node> items, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Module
{
public:
    std::unique_ptr<Node> name;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Module() = delete;
    Module(Module &&) = default;
    Module(const Module &) = delete;
    explicit Module(std::unique_ptr<Node> name, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Next
{
public:
    std::vector<Node> args;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> expression_l;

    Next() = delete;
    Next(Next &&) = default;
    Next(const Next &) = delete;
    explicit Next(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

class Nil
{
public:
    std::unique_ptr<Loc> expression_l;

    Nil() = delete;
    Nil(Nil &&) = default;
    Nil(const Nil &) = delete;
    explicit Nil(std::unique_ptr<Loc> expression_l);
};

class NthRef
{
public:
    std::string name;
    std::unique_ptr<Loc> expression_l;

    NthRef() = delete;
    NthRef(NthRef &&) = default;
    NthRef(const NthRef &) = delete;
    explicit NthRef(std::string name, std::unique_ptr<Loc> expression_l);
};

class Numblock
{
public:
    std::unique_ptr<Node> call;
    uint32_t numargs;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Numblock() = delete;
    Numblock(Numblock &&) = default;
    Numblock(const Numblock &) = delete;
    explicit Numblock(std::unique_ptr<Node> call, uint32_t numargs, std::unique_ptr<Node> body, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class OpAsgn
{
public:
    std::unique_ptr<Node> recv;
    std::string operator_;
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    OpAsgn() = delete;
    OpAsgn(OpAsgn &&) = default;
    OpAsgn(const OpAsgn &) = delete;
    explicit OpAsgn(std::unique_ptr<Node> recv, std::string operator_, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Optarg
{
public:
    std::string name;
    std::unique_ptr<Node> default_;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Optarg() = delete;
    Optarg(Optarg &&) = default;
    Optarg(const Optarg &) = delete;
    explicit Optarg(std::string name, std::unique_ptr<Node> default_, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Or
{
public:
    std::unique_ptr<Node> lhs;
    std::unique_ptr<Node> rhs;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Or() = delete;
    Or(Or &&) = default;
    Or(const Or &) = delete;
    explicit Or(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class OrAsgn
{
public:
    std::unique_ptr<Node> recv;
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    OrAsgn() = delete;
    OrAsgn(OrAsgn &&) = default;
    OrAsgn(const OrAsgn &) = delete;
    explicit OrAsgn(std::unique_ptr<Node> recv, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Pair
{
public:
    std::unique_ptr<Node> key;
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Pair() = delete;
    Pair(Pair &&) = default;
    Pair(const Pair &) = delete;
    explicit Pair(std::unique_ptr<Node> key, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Pin
{
public:
    std::unique_ptr<Node> var;
    std::unique_ptr<Loc> selector_l;
    std::unique_ptr<Loc> expression_l;

    Pin() = delete;
    Pin(Pin &&) = default;
    Pin(const Pin &) = delete;
    explicit Pin(std::unique_ptr<Node> var, std::unique_ptr<Loc> selector_l, std::unique_ptr<Loc> expression_l);
};

class Postexe
{
public:
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Postexe() = delete;
    Postexe(Postexe &&) = default;
    Postexe(const Postexe &) = delete;
    explicit Postexe(std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Preexe
{
public:
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Preexe() = delete;
    Preexe(Preexe &&) = default;
    Preexe(const Preexe &) = delete;
    explicit Preexe(std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Procarg0
{
public:
    std::vector<Node> args;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Procarg0() = delete;
    Procarg0(Procarg0 &&) = default;
    Procarg0(const Procarg0 &) = delete;
    explicit Procarg0(std::vector<Node> args, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Rational
{
public:
    std::string value;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Rational() = delete;
    Rational(Rational &&) = default;
    Rational(const Rational &) = delete;
    explicit Rational(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Redo
{
public:
    std::unique_ptr<Loc> expression_l;

    Redo() = delete;
    Redo(Redo &&) = default;
    Redo(const Redo &) = delete;
    explicit Redo(std::unique_ptr<Loc> expression_l);
};

class RegOpt
{
public:
    std::string options;
    std::unique_ptr<Loc> expression_l;

    RegOpt() = delete;
    RegOpt(RegOpt &&) = default;
    RegOpt(const RegOpt &) = delete;
    explicit RegOpt(std::string options, std::unique_ptr<Loc> expression_l);
};

class Regexp
{
public:
    std::vector<Node> parts;
    std::unique_ptr<Node> options;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Regexp() = delete;
    Regexp(Regexp &&) = default;
    Regexp(const Regexp &) = delete;
    explicit Regexp(std::vector<Node> parts, std::unique_ptr<Node> options, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Rescue
{
public:
    std::unique_ptr<Node> body;
    std::vector<Node> rescue_bodies;
    std::unique_ptr<Node> else_;
    std::unique_ptr<Loc> else_l;
    std::unique_ptr<Loc> expression_l;

    Rescue() = delete;
    Rescue(Rescue &&) = default;
    Rescue(const Rescue &) = delete;
    explicit Rescue(std::unique_ptr<Node> body, std::vector<Node> rescue_bodies, std::unique_ptr<Node> else_, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> expression_l);
};

class RescueBody
{
public:
    std::unique_ptr<Node> exc_list;
    std::unique_ptr<Node> exc_var;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> assoc_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> expression_l;

    RescueBody() = delete;
    RescueBody(RescueBody &&) = default;
    RescueBody(const RescueBody &) = delete;
    explicit RescueBody(std::unique_ptr<Node> exc_list, std::unique_ptr<Node> exc_var, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> assoc_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> expression_l);
};

class Restarg
{
public:
    std::string name;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> name_l;
    std::unique_ptr<Loc> expression_l;

    Restarg() = delete;
    Restarg(Restarg &&) = default;
    Restarg(const Restarg &) = delete;
    explicit Restarg(std::string name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

class Retry
{
public:
    std::unique_ptr<Loc> expression_l;

    Retry() = delete;
    Retry(Retry &&) = default;
    Retry(const Retry &) = delete;
    explicit Retry(std::unique_ptr<Loc> expression_l);
};

class Return
{
public:
    std::vector<Node> args;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> expression_l;

    Return() = delete;
    Return(Return &&) = default;
    Return(const Return &) = delete;
    explicit Return(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

class SClass
{
public:
    std::unique_ptr<Node> expr;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    SClass() = delete;
    SClass(SClass &&) = default;
    SClass(const SClass &) = delete;
    explicit SClass(std::unique_ptr<Node> expr, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Self_
{
public:
    std::unique_ptr<Loc> expression_l;

    Self_() = delete;
    Self_(Self_ &&) = default;
    Self_(const Self_ &) = delete;
    explicit Self_(std::unique_ptr<Loc> expression_l);
};

class Send
{
public:
    std::unique_ptr<Node> recv;
    std::string method_name;
    std::vector<Node> args;
    std::unique_ptr<Loc> dot_l;
    std::unique_ptr<Loc> selector_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Send() = delete;
    Send(Send &&) = default;
    Send(const Send &) = delete;
    explicit Send(std::unique_ptr<Node> recv, std::string method_name, std::vector<Node> args, std::unique_ptr<Loc> dot_l, std::unique_ptr<Loc> selector_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Shadowarg
{
public:
    std::string name;
    std::unique_ptr<Loc> expression_l;

    Shadowarg() = delete;
    Shadowarg(Shadowarg &&) = default;
    Shadowarg(const Shadowarg &) = delete;
    explicit Shadowarg(std::string name, std::unique_ptr<Loc> expression_l);
};

class Splat
{
public:
    std::unique_ptr<Node> value;
    std::unique_ptr<Loc> operator_l;
    std::unique_ptr<Loc> expression_l;

    Splat() = delete;
    Splat(Splat &&) = default;
    Splat(const Splat &) = delete;
    explicit Splat(std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

class Str
{
public:
    Bytes value;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Str() = delete;
    Str(Str &&) = default;
    Str(const Str &) = delete;
    explicit Str(Bytes value, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Super
{
public:
    std::vector<Node> args;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Super() = delete;
    Super(Super &&) = default;
    Super(const Super &) = delete;
    explicit Super(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Sym
{
public:
    Bytes name;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Sym() = delete;
    Sym(Sym &&) = default;
    Sym(const Sym &) = delete;
    explicit Sym(Bytes name, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class True
{
public:
    std::unique_ptr<Loc> expression_l;

    True() = delete;
    True(True &&) = default;
    True(const True &) = delete;
    explicit True(std::unique_ptr<Loc> expression_l);
};

class Undef
{
public:
    std::vector<Node> names;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> expression_l;

    Undef() = delete;
    Undef(Undef &&) = default;
    Undef(const Undef &) = delete;
    explicit Undef(std::vector<Node> names, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

class UnlessGuard
{
public:
    std::unique_ptr<Node> cond;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> expression_l;

    UnlessGuard() = delete;
    UnlessGuard(UnlessGuard &&) = default;
    UnlessGuard(const UnlessGuard &) = delete;
    explicit UnlessGuard(std::unique_ptr<Node> cond, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

class Until
{
public:
    std::unique_ptr<Node> cond;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Until() = delete;
    Until(Until &&) = default;
    Until(const Until &) = delete;
    explicit Until(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class UntilPost
{
public:
    std::unique_ptr<Node> cond;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> expression_l;

    UntilPost() = delete;
    UntilPost(UntilPost &&) = default;
    UntilPost(const UntilPost &) = delete;
    explicit UntilPost(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

class When
{
public:
    std::vector<Node> patterns;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> expression_l;

    When() = delete;
    When(When &&) = default;
    When(const When &) = delete;
    explicit When(std::vector<Node> patterns, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> expression_l);
};

class While
{
public:
    std::unique_ptr<Node> cond;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    While() = delete;
    While(While &&) = default;
    While(const While &) = delete;
    explicit While(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class WhilePost
{
public:
    std::unique_ptr<Node> cond;
    std::unique_ptr<Node> body;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> expression_l;

    WhilePost() = delete;
    WhilePost(WhilePost &&) = default;
    WhilePost(const WhilePost &) = delete;
    explicit WhilePost(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

class XHeredoc
{
public:
    std::vector<Node> parts;
    std::unique_ptr<Loc> heredoc_body_l;
    std::unique_ptr<Loc> heredoc_end_l;
    std::unique_ptr<Loc> expression_l;

    XHeredoc() = delete;
    XHeredoc(XHeredoc &&) = default;
    XHeredoc(const XHeredoc &) = delete;
    explicit XHeredoc(std::vector<Node> parts, std::unique_ptr<Loc> heredoc_body_l, std::unique_ptr<Loc> heredoc_end_l, std::unique_ptr<Loc> expression_l);
};

class Xstr
{
public:
    std::vector<Node> parts;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Xstr() = delete;
    Xstr(Xstr &&) = default;
    Xstr(const Xstr &) = delete;
    explicit Xstr(std::vector<Node> parts, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class Yield
{
public:
    std::vector<Node> args;
    std::unique_ptr<Loc> keyword_l;
    std::unique_ptr<Loc> begin_l;
    std::unique_ptr<Loc> end_l;
    std::unique_ptr<Loc> expression_l;

    Yield() = delete;
    Yield(Yield &&) = default;
    Yield(const Yield &) = delete;
    explicit Yield(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

class ZSuper
{
public:
    std::unique_ptr<Loc> expression_l;

    ZSuper() = delete;
    ZSuper(ZSuper &&) = default;
    ZSuper(const ZSuper &) = delete;
    explicit ZSuper(std::unique_ptr<Loc> expression_l);
};

using node_variant_t = std::variant<
    std::unique_ptr<Alias>,
    std::unique_ptr<AndAsgn>,
    std::unique_ptr<And>,
    std::unique_ptr<Arg>,
    std::unique_ptr<Args>,
    std::unique_ptr<Array>,
    std::unique_ptr<ArrayPattern>,
    std::unique_ptr<ArrayPatternWithTail>,
    std::unique_ptr<BackRef>,
    std::unique_ptr<Begin>,
    std::unique_ptr<Block>,
    std::unique_ptr<BlockPass>,
    std::unique_ptr<Blockarg>,
    std::unique_ptr<Break>,
    std::unique_ptr<Case>,
    std::unique_ptr<CaseMatch>,
    std::unique_ptr<Casgn>,
    std::unique_ptr<Cbase>,
    std::unique_ptr<Class>,
    std::unique_ptr<Complex>,
    std::unique_ptr<Const>,
    std::unique_ptr<ConstPattern>,
    std::unique_ptr<CSend>,
    std::unique_ptr<Cvar>,
    std::unique_ptr<Cvasgn>,
    std::unique_ptr<Def>,
    std::unique_ptr<Defined>,
    std::unique_ptr<Defs>,
    std::unique_ptr<Dstr>,
    std::unique_ptr<Dsym>,
    std::unique_ptr<EFlipFlop>,
    std::unique_ptr<EmptyElse>,
    std::unique_ptr<Encoding>,
    std::unique_ptr<Ensure>,
    std::unique_ptr<Erange>,
    std::unique_ptr<False>,
    std::unique_ptr<File>,
    std::unique_ptr<FindPattern>,
    std::unique_ptr<Float>,
    std::unique_ptr<For>,
    std::unique_ptr<ForwardArg>,
    std::unique_ptr<ForwardedArgs>,
    std::unique_ptr<Gvar>,
    std::unique_ptr<Gvasgn>,
    std::unique_ptr<Hash>,
    std::unique_ptr<Kwargs>,
    std::unique_ptr<HashPattern>,
    std::unique_ptr<Heredoc>,
    std::unique_ptr<If>,
    std::unique_ptr<IfGuard>,
    std::unique_ptr<IfMod>,
    std::unique_ptr<IfTernary>,
    std::unique_ptr<IFlipFlop>,
    std::unique_ptr<MatchPattern>,
    std::unique_ptr<MatchPatternP>,
    std::unique_ptr<InPattern>,
    std::unique_ptr<Index>,
    std::unique_ptr<IndexAsgn>,
    std::unique_ptr<Int>,
    std::unique_ptr<Irange>,
    std::unique_ptr<Ivar>,
    std::unique_ptr<Ivasgn>,
    std::unique_ptr<Kwarg>,
    std::unique_ptr<KwBegin>,
    std::unique_ptr<Kwnilarg>,
    std::unique_ptr<Kwoptarg>,
    std::unique_ptr<Kwrestarg>,
    std::unique_ptr<Kwsplat>,
    std::unique_ptr<Lambda>,
    std::unique_ptr<Line>,
    std::unique_ptr<Lvar>,
    std::unique_ptr<Lvasgn>,
    std::unique_ptr<Masgn>,
    std::unique_ptr<MatchAlt>,
    std::unique_ptr<MatchAs>,
    std::unique_ptr<MatchCurrentLine>,
    std::unique_ptr<MatchNilPattern>,
    std::unique_ptr<MatchRest>,
    std::unique_ptr<MatchVar>,
    std::unique_ptr<MatchWithLvasgn>,
    std::unique_ptr<Mlhs>,
    std::unique_ptr<Module>,
    std::unique_ptr<Next>,
    std::unique_ptr<Nil>,
    std::unique_ptr<NthRef>,
    std::unique_ptr<Numblock>,
    std::unique_ptr<OpAsgn>,
    std::unique_ptr<Optarg>,
    std::unique_ptr<Or>,
    std::unique_ptr<OrAsgn>,
    std::unique_ptr<Pair>,
    std::unique_ptr<Pin>,
    std::unique_ptr<Postexe>,
    std::unique_ptr<Preexe>,
    std::unique_ptr<Procarg0>,
    std::unique_ptr<Rational>,
    std::unique_ptr<Redo>,
    std::unique_ptr<RegOpt>,
    std::unique_ptr<Regexp>,
    std::unique_ptr<Rescue>,
    std::unique_ptr<RescueBody>,
    std::unique_ptr<Restarg>,
    std::unique_ptr<Retry>,
    std::unique_ptr<Return>,
    std::unique_ptr<SClass>,
    std::unique_ptr<Self_>,
    std::unique_ptr<Send>,
    std::unique_ptr<Shadowarg>,
    std::unique_ptr<Splat>,
    std::unique_ptr<Str>,
    std::unique_ptr<Super>,
    std::unique_ptr<Sym>,
    std::unique_ptr<True>,
    std::unique_ptr<Undef>,
    std::unique_ptr<UnlessGuard>,
    std::unique_ptr<Until>,
    std::unique_ptr<UntilPost>,
    std::unique_ptr<When>,
    std::unique_ptr<While>,
    std::unique_ptr<WhilePost>,
    std::unique_ptr<XHeredoc>,
    std::unique_ptr<Xstr>,
    std::unique_ptr<Yield>,
    std::unique_ptr<ZSuper>>;

class Node
{
public:
    node_variant_t inner;
    Node() = delete;
    Node(Node &&) = default;
    Node(const Node &) = delete;
    explicit Node(node_variant_t inner) : inner(std::move(inner)) {}

    template <typename T>
    bool is()
    {
        return std::holds_alternative<std::unique_ptr<T>>(inner);
    }

    template <typename T>
    T *get()
    {
        return std::get<std::unique_ptr<T>>(inner).get();
    }
};

}
#endif // LIB_RUBY_PARSER_NODE_H
