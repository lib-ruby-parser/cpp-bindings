#ifndef LIB_RUBY_PARSER_GEN_NODES_CLASSES_H
#define LIB_RUBY_PARSER_GEN_NODES_CLASSES_H

#include <memory>
#include <vector>
#include <string>
#include "../../loc.h"
#include "../../bytes.h"

namespace lib_ruby_parser {

class Node;


// Represents `alias to from` statement.
class Alias
{
public:
    // Target of the `alias`.
    //
    // `Sym("foo")` node for `alias :foo :bar`
    std::unique_ptr<Node> to;
    // Source of the `alias`.
    //
    // `Sym("bar")` node for `alias :foo :bar`
    std::unique_ptr<Node> from;
    // Location of the `alias` keyword
    //
    // ```text
    // alias foo bar
    // ~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the full expression
    //
    // ```text
    // alias foo bar
    // ~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Alias() = delete;
    Alias(Alias &&) = default;
    Alias(const Alias &) = delete;
    explicit Alias(std::unique_ptr<Node> to, std::unique_ptr<Node> from, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

// Represents `a &&= 1` statement.
class AndAsgn
{
public:
    // Receiver of the `&&=` operation.
    //
    // `Lvasgn("a")` node for `a &&= 1`
    std::unique_ptr<Node> recv;
    // Right hand statement of assignment
    //
    // `Int("1")` node for `a &&= 1`
    std::unique_ptr<Node> value;
    // Location of the `&&=` operator
    //
    // ```text
    // a &&= 1
    //   ~~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // a &&= 1
    // ~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    AndAsgn() = delete;
    AndAsgn(AndAsgn &&) = default;
    AndAsgn(const AndAsgn &) = delete;
    explicit AndAsgn(std::unique_ptr<Node> recv, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents `foo && bar` (or `foo and bar`) statement.
class And
{
public:
    // Left hand statament of the `&&` operation.
    //
    // `Lvar("foo")` node for `foo && bar`
    std::unique_ptr<Node> lhs;
    // Right hand statement of the `&&` operation.
    //
    // `Lvar("bar")` node for `foo && bar`
    std::unique_ptr<Node> rhs;
    // Location of the `&&` (or `and`) operator
    //
    // ```text
    // a && b
    //   ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // a && b
    // ~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    And() = delete;
    And(And &&) = default;
    And(const And &) = delete;
    explicit And(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents a positional required block/method argument.//// `a` in `def m(a); end` or `proc { |a| }`
class Arg
{
public:
    // Name of the argument
    std::string name;
    // Location of the full expression
    //
    // ```text
    // def m(argument); end
    //       ~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Arg() = delete;
    Arg(Arg &&) = default;
    Arg(const Arg &) = delete;
    explicit Arg(std::string name, std::unique_ptr<Loc> expression_l);
};

// Represents an arguments list//// `Args(vec![Arg("a"), Optarg("b", Int("1"))])` in `def m(a, b = 1); end`
class Args
{
public:
    // List of arguments
    std::vector<Node> args;
    // Location of the full expression
    //
    // ```text
    // def m(a, b = 1, c:, &blk); end
    //      ~~~~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;
    // Location of the open parenthesis
    //
    // ```text
    // def m(a, b = 1, c:, &blk); end
    //      ~
    // ```
    //
    // `None` for code like `def m; end` or `def m arg; end`
    std::unique_ptr<Loc> begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // def m(a, b = 1, c:, &blk); end
    //                         ~
    // ```
    //
    // `None` for code like `def m; end` or `def m arg; end`
    std::unique_ptr<Loc> end_l;

    Args() = delete;
    Args(Args &&) = default;
    Args(const Args &) = delete;
    explicit Args(std::vector<Node> args, std::unique_ptr<Loc> expression_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l);
};

// Represents an array literal
class Array
{
public:
    // A list of elements
    std::vector<Node> elements;
    // Location of the open bracket
    //
    // ```text
    // [1, 2, 3]
    // ~
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of the closing bracket
    //
    // ```text
    // [1, 2, 3]
    //         ~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // [1, 2, 3]
    // ~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Array() = delete;
    Array(Array &&) = default;
    Array(const Array &) = delete;
    explicit Array(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents an array pattern used in pattern matching
class ArrayPattern
{
public:
    // A list of elements
    std::vector<Node> elements;
    // Location of the open bracket
    //
    // ```text
    // [1, ^a, 3 => foo]
    // ~
    // ```
    //
    // `None` for pattern like `1, 2` without brackets
    std::unique_ptr<Loc> begin_l;
    // Location of the closing bracket
    //
    // ```text
    // [1, ^a, 3 => foo]
    //                 ~
    // ```
    //
    // `None` for pattern like `1, 2` without brackets
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // [1, ^a, 3 => foo]
    // ~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    ArrayPattern() = delete;
    ArrayPattern(ArrayPattern &&) = default;
    ArrayPattern(const ArrayPattern &) = delete;
    explicit ArrayPattern(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents an array pattern *with trailing comma* used in pattern matching//// It's slightly different from `ArrayPattern`, trailing comma at the end works as `, *`
class ArrayPatternWithTail
{
public:
    // A list of elements
    std::vector<Node> elements;
    // Location of the open bracket
    //
    // ```text
    // [1, ^a, 3 => foo,]
    // ~
    // ```
    //
    // `None` for pattern like `1, 2,` without brackets
    std::unique_ptr<Loc> begin_l;
    // Location of the closing bracket
    //
    // ```text
    // [1, ^a, 3 => foo,]
    //                  ~
    // ```
    //
    // `None` for pattern like `1, 2,` without brackets
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // [1, ^a, 3 => foo,]
    // ~~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    ArrayPatternWithTail() = delete;
    ArrayPatternWithTail(ArrayPatternWithTail &&) = default;
    ArrayPatternWithTail(const ArrayPatternWithTail &) = delete;
    explicit ArrayPatternWithTail(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents special global variables://     1. `` $` ``//     2. `$&`//     3. `$'`//     4. `$+`
class BackRef
{
public:
    // Name of the variable (`"$+"` for `$+`)
    std::string name;
    // Location of the full expression
    //
    // ```text
    // $+
    // ~~
    // ```
    std::unique_ptr<Loc> expression_l;

    BackRef() = delete;
    BackRef(BackRef &&) = default;
    BackRef(const BackRef &) = delete;
    explicit BackRef(std::string name, std::unique_ptr<Loc> expression_l);
};

// Represents compound statement (i.e. a multi-statement)//// Basically all blocks of code are wrapped into `Begin` node (e.g. method/block body, rescue/ensure handler etc)
class Begin
{
public:
    // A list of statements
    std::vector<Node> statements;
    // Begin of the block
    //
    // ```text
    // (1; 2)
    // ~
    // ```
    //
    // `None` if the block of code is "implicit", like
    //
    // ```text
    // if true; 1; 2; end
    // ```
    std::unique_ptr<Loc> begin_l;
    // End of the block
    //
    // ```text
    // (1; 2)
    //      ~
    // ```
    //
    // `None` if the block of code is "implicit", like
    //
    // ```text
    // if true; 1; 2; end
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // (1; 2)
    // ~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Begin() = delete;
    Begin(Begin &&) = default;
    Begin(const Begin &) = delete;
    explicit Begin(std::vector<Node> statements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a Ruby block that is passed to a method (`proc { |foo| bar }`)
class Block
{
public:
    // Method call that takes a block
    //
    // `Send("foo")` in `foo {}`
    std::unique_ptr<Node> call;
    // A list of argument that block takes
    //
    // `vec![ Arg("a"), Optarg("b", Int("1")) ]` for `proc { |a, b = 1| }`
    //
    // `None` if the block takes no arguments
    std::unique_ptr<Node> args;
    // Block body, `None` if block has no body.
    std::unique_ptr<Node> body;
    // Location of the open brace
    //
    // ```text
    // proc { }
    //      ~
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of the closing brace
    //
    // ```text
    // proc { }
    //        ~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // proc { }
    // ~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Block() = delete;
    Block(Block &&) = default;
    Block(const Block &) = delete;
    explicit Block(std::unique_ptr<Node> call, std::unique_ptr<Node> args, std::unique_ptr<Node> body, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a `&blk` argument of the method call (but not of the method definition, see `BlockArg`)
class BlockPass
{
public:
    // Value that is converted to a block
    //
    // `Int("1")` in `foo(&1)` (yes, it's possible)
    std::unique_ptr<Node> value;
    // Location of the `&` operator
    //
    // ```text
    // foo(&blk)
    //     ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // foo(&bar)
    //     ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    BlockPass() = delete;
    BlockPass(BlockPass &&) = default;
    BlockPass(const BlockPass &) = delete;
    explicit BlockPass(std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents a `&blk` argument in the method definition (but not in the method call, see `BlockPass`)
class Blockarg
{
public:
    // Name of the argument, `String("foo")` for `def m(&foo)`
    std::string name;
    // Location of the `&` operator
    //
    // ```text
    // def m(&foo); end
    //       ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the name
    //
    // ```text
    // def m(&foo); end
    //        ~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the full expression
    //
    // ```text
    // def m(&foo); end
    //       ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Blockarg() = delete;
    Blockarg(Blockarg &&) = default;
    Blockarg(const Blockarg &) = delete;
    explicit Blockarg(std::string name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

// Represents a `break` keyword (with optional argument)
class Break
{
public:
    // A list of arguments
    std::vector<Node> args;
    // Location of the `break` keyword
    //
    // ```text
    // break :foo
    // ~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the full expression
    //
    // ```text
    // break(:foo)
    // ~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Break() = delete;
    Break(Break &&) = default;
    Break(const Break &) = delete;
    explicit Break(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

// Represents a `case` statement (for pattern matching see `CaseMatch` node)
class Case
{
public:
    // Expression given to `case`, `Int("1")` for `case 1; end`
    // `None` for code like
    //
    // ```text
    // case
    // when pattern
    // end
    // ```
    std::unique_ptr<Node> expr;
    // A list of `When` nodes (each has `patterns` and `body`)
    std::vector<Node> when_bodies;
    // Body of the `else` branch, `None` if there's no `else` branch
    std::unique_ptr<Node> else_body;
    // Location of the `case` keyword
    //
    // ```text
    // case 1; end
    // ~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `else` keyword
    //
    // ```text
    // case 1; else; end
    //         ~~~~
    // ```
    //
    // `None` if there's no `else` branch
    std::unique_ptr<Loc> else_l;
    // Location of the `end` keyword
    //
    // ```text
    // case 1; end
    //         ~~~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // case 1; end
    // ~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Case() = delete;
    Case(Case &&) = default;
    Case(const Case &) = delete;
    explicit Case(std::unique_ptr<Node> expr, std::vector<Node> when_bodies, std::unique_ptr<Node> else_body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a `case` statement used for pattern matching (for regular `case` see `Case` node)
class CaseMatch
{
public:
    // Expression given to `case`, `Int("1")` for `case 1; in 1; end`
    // `None` for code like
    //
    // ```text
    // case
    // in pattern
    // end
    // ```
    std::unique_ptr<Node> expr;
    // A list of `InPattern` nodes (each has `pattern`, `guard` and `body`)
    std::vector<Node> in_bodies;
    // Body of the `else` branch, `None` if there's no `else` branch
    std::unique_ptr<Node> else_body;
    // Location of the `case` keyword
    //
    // ```text
    // case 1; in 2; end
    // ~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `else` keyword
    //
    // ```text
    // case 1; in 2; else; end
    //               ~~~~
    // ```
    //
    // `None` if there's no `else` branch
    std::unique_ptr<Loc> else_l;
    // Location of the `end` keyword
    //
    // ```text
    // case 1; in 2; end
    //               ~~~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // case 1; in 2; end
    // ~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    CaseMatch() = delete;
    CaseMatch(CaseMatch &&) = default;
    CaseMatch(const CaseMatch &) = delete;
    explicit CaseMatch(std::unique_ptr<Node> expr, std::vector<Node> in_bodies, std::unique_ptr<Node> else_body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a constant assignment (i.e. `A = 1`)
class Casgn
{
public:
    // Scope where the constant is defined:
    //     1. `Some(Const("A"))` for `A::B = 1`
    //     2. `None` if it's defined in the current scope (i.e. `A = 1`)
    //     3. `Some(Cbase)` if it's defined in the global scope (i.e. `::A = 1`)
    std::unique_ptr<Node> scope;
    // Name of the constant, `String("A")` for `A = 1`
    std::string name;
    // Value that is assigned to a constant, `Int("1")` for `A = 1`.
    //
    // **Note**: `None` if constant assignment is a part of the multi-assignment.
    // In such case `value` belongs to `Masgn` node of the multi-assignment.
    std::unique_ptr<Node> value;
    // Location of the `::` operator
    //
    // ```text
    // A::B = 1
    //  ~~
    //
    // ::A = 1
    // ~~
    // ```
    //
    // `None` if the constant is defined in the current scope
    std::unique_ptr<Loc> double_colon_l;
    // Location of the constant name
    //
    // ```text
    // A::CONST = 1
    //    ~~~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the `=` operator
    //
    // ```text
    // A = 1
    //   ~
    // ```
    //
    // `None` if constant assignment is a part of the multi-assignment.
    // In such case `=` belongs to a `Masgn` node
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // A = 1
    // ~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Casgn() = delete;
    Casgn(Casgn &&) = default;
    Casgn(const Casgn &) = delete;
    explicit Casgn(std::unique_ptr<Node> scope, std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> double_colon_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents leading `::` part of the constant access/assignment that is used to get/set on a global namespace.
class Cbase
{
public:
    // Location of the full expression
    //
    // ```text
    // ::A
    // ~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Cbase() = delete;
    Cbase(Cbase &&) = default;
    Cbase(const Cbase &) = delete;
    explicit Cbase(std::unique_ptr<Loc> expression_l);
};

// Represents a class definition (using a `class` keyword, `Class.new` is just a method call)
class Class
{
public:
    // Name of the class, `String("Foo")` for `class Foo; end`
    std::unique_ptr<Node> name;
    // Superclass. Can be an expression in cases like `class A < (obj.foo + 1); end`
    //
    // `None` if no explicit superclass given (i.e. `class Foo; end`)
    std::unique_ptr<Node> superclass;
    // Body of the method, `None` if there's no body.
    std::unique_ptr<Node> body;
    // Location of the `class` keyword.
    //
    // ```text
    // class Foo; end
    // ~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `<` operator
    //
    // ```text
    // class A < B; end
    //         ~
    // ```
    //
    // `None` if there's no explicit superclass given.
    std::unique_ptr<Loc> operator_l;
    // Location of the `end` keyword.
    //
    // ```text
    // class Foo; end
    //            ~~~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // class Foo; end
    // ~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Class() = delete;
    Class(Class &&) = default;
    Class(const Class &) = delete;
    explicit Class(std::unique_ptr<Node> name, std::unique_ptr<Node> superclass, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a `Complex` literal (that returns an `Complex` number)
class Complex
{
public:
    // Value of the complex literal, returned as a `String`, `String("1i")` for `1i`
    std::string value;
    // Location of the `-` (but not `+`) operator. `+` is a part of the literal:
    //     1. `+1i` is `String("+1i")` with `operator = None`
    //     2. `-1i` is `String("1i")` with `operator = String("-")`
    //
    // ```text
    // -1i
    // ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // -1i
    // ~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Complex() = delete;
    Complex(Complex &&) = default;
    Complex(const Complex &) = delete;
    explicit Complex(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents constant access (i.e. `Foo::Bar`)
class Const
{
public:
    // Scope where the constant is taken from:
    //     1. `Some(Const("A"))` for `A::B`
    //     2. `None` if it's taken from the current scope (i.e. `A`)
    //     3. `Some(Cbase)` if it's taken from the global scope (i.e. `::A`)
    std::unique_ptr<Node> scope;
    // Name of the constant, `String("Foo")` for `Foo`
    std::string name;
    // Location of the `::` operator. `None` if constant is taken from the current scope.
    //
    // ```text
    // A::B
    //  ~~
    // ```
    std::unique_ptr<Loc> double_colon_l;
    // Location of the constant name
    //
    // ```text
    // Foo::Bar
    //      ~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the full expression
    //
    // ```text
    // Foo::Bar
    // ~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Const() = delete;
    Const(Const &&) = default;
    Const(const Const &) = delete;
    explicit Const(std::unique_ptr<Node> scope, std::string name, std::unique_ptr<Loc> double_colon_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

// Const pattern used in pattern matching (e.g. `in A(1, 2)`)
class ConstPattern
{
public:
    // Constant that is used, `Const("Foo")` for `in For(42)`
    std::unique_ptr<Node> const_;
    // Inner part of the constant pattern
    //
    // `ArrayPattern(vec![ Int("1") ])` for `Foo(1)`
    std::unique_ptr<Node> pattern;
    // Location of the open parenthesis
    //
    // ```text
    // case 1; in Foo(42); end
    //               ~
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // case 1; in Foo(42); end
    //                  ~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // case 1; in Foo(42); end
    //            ~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    ConstPattern() = delete;
    ConstPattern(ConstPattern &&) = default;
    ConstPattern(const ConstPattern &) = delete;
    explicit ConstPattern(std::unique_ptr<Node> const_, std::unique_ptr<Node> pattern, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents conditional method call using `&.` operator
class CSend
{
public:
    // Receiver of the method call, `Int("1")` for `1&.foo`
    std::unique_ptr<Node> recv;
    // Name of the method, `String("foo")` for `1&.foo`
    std::string method_name;
    // List of arguments
    //
    // ```text
    // foo&.bar(42)
    // # and also setters like
    // foo&.bar = 42
    // ```
    std::vector<Node> args;
    // Location of the `&.` operator
    //
    // ```text
    // foo&.bar
    //    ~~
    // ```
    std::unique_ptr<Loc> dot_l;
    // Location of the method name
    //
    // ```text
    // foo&.bar(42)
    //      ~~~
    // ```
    //
    // `None` in a very special case when method call is implicit (i.e. `foo&.()`)
    std::unique_ptr<Loc> selector_l;
    // Location of the open parenthesis
    //
    // ```text
    // foo&.bar(42)
    //         ~
    // ```
    //
    // `None` if there are no parentheses
    std::unique_ptr<Loc> begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // foo&.bar(42)
    //            ~
    // ```
    //
    // `None` if there are no parentheses
    std::unique_ptr<Loc> end_l;
    // Location of the operator if `CSend` is a part of assignment like
    //
    // ```text
    // foo&.bar = 1
    //          ~
    // ```
    //
    // `None` for a regular call.
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // foo&.bar(42)
    // ~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    CSend() = delete;
    CSend(CSend &&) = default;
    CSend(const CSend &) = delete;
    explicit CSend(std::unique_ptr<Node> recv, std::string method_name, std::vector<Node> args, std::unique_ptr<Loc> dot_l, std::unique_ptr<Loc> selector_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents access to class variable (i.e. `@@var`)
class Cvar
{
public:
    // Name of the class variable, `String("@@foo")` for `@@foo`
    std::string name;
    // Location of the full expression
    //
    // ```text
    // @@foo
    // ~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Cvar() = delete;
    Cvar(Cvar &&) = default;
    Cvar(const Cvar &) = delete;
    explicit Cvar(std::string name, std::unique_ptr<Loc> expression_l);
};

// Represents class variable assignment (i.e. `@@var = 42`)
class Cvasgn
{
public:
    // Name of the class variable, `String("@@foo")` for `@@foo = 1`
    std::string name;
    // Value that is assigned to class variable, `Int("1")` for `@@foo = 1`
    std::unique_ptr<Node> value;
    // Location of the class variable name
    //
    // ```text
    // @@foo = 1
    // ~~~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the `=` operator
    //
    // ```text
    // @@foo = 1
    //       ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // @@foo = 1
    // ~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Cvasgn() = delete;
    Cvasgn(Cvasgn &&) = default;
    Cvasgn(const Cvasgn &) = delete;
    explicit Cvasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents method definition using `def` keyword (not on a singleton, see `Defs` node).
class Def
{
public:
    // Name of the method, `String("foo")` for `def foo; end`
    std::string name;
    // Arguments of a method, `None` if there's no arguments.
    //
    // All information about parentheses around arguments is stored in this node.
    std::unique_ptr<Node> args;
    // Body of a method, `None` if there's no body.
    std::unique_ptr<Node> body;
    // Location of the `def` keyword.
    //
    // ```text
    // def foo; end
    // ~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the method name.
    //
    // ```text
    // def foo; end
    //     ~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the `end` keyword.
    //
    // ```text
    // def foo; end
    //          ~~~
    // ```
    //
    // `None` for endless method definition
    std::unique_ptr<Loc> end_l;
    // Location of the `=` operator for endless method definition
    //
    // ```text
    // def m() = 1
    //         ~
    // ```
    //
    // `None` for regular method definition
    std::unique_ptr<Loc> assignment_l;
    // Location of the full expression
    //
    // ```text
    // def m(a); foo; end
    // ~~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Def() = delete;
    Def(Def &&) = default;
    Def(const Def &) = delete;
    explicit Def(std::string name, std::unique_ptr<Node> args, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> assignment_l, std::unique_ptr<Loc> expression_l);
};

// Represents a `defined?(foo)` expression
class Defined
{
public:
    // Value given to `defined?`
    std::unique_ptr<Node> value;
    // Location of the `defined?` keyword
    //
    // ```text
    // defined?(foo)
    // ~~~~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // defined?(foo)
    //         ~
    // ```
    //
    // `None` if there are no parentheses
    std::unique_ptr<Loc> begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // defined?(foo)
    //             ~
    // ```
    //
    // `None` if there are no parentheses
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // defined?(foo)
    // ~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Defined() = delete;
    Defined(Defined &&) = default;
    Defined(const Defined &) = delete;
    explicit Defined(std::unique_ptr<Node> value, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a singleton method definition (i.e. `def self.foo; end`)
class Defs
{
public:
    // Definee of a method definition, `Lvar("x")` for `def x.foo; end
    std::unique_ptr<Node> definee;
    // Name of the method, `String("foo")` for `def x.foo; end`
    std::string name;
    // Arguments of a method, `None` if there's no arguments.
    //
    // All information about parentheses around arguments is stored in this node.
    std::unique_ptr<Node> args;
    // Body of the method, `None` if there's no body.
    std::unique_ptr<Node> body;
    // Location of the `def` keyword
    //
    // ```text
    // def self.foo; end
    // ~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `.`
    //
    // ```text
    // def self.foo; end
    //         ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the method name
    //
    // ```text
    // def self.foo; end
    //          ~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the `=` operator for endless method definition
    //
    // ```text
    // def self.foo() = 42
    //                ~
    // ```
    //
    // `None` for regular method definition
    std::unique_ptr<Loc> assignment_l;
    // Location of the `end` keyword
    //
    // ```text
    // def self.foo; end
    //               ~~~
    // ```
    //
    // `None` for endless method definition
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // def self.foo; end
    // ~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Defs() = delete;
    Defs(Defs &&) = default;
    Defs(const Defs &) = delete;
    explicit Defs(std::unique_ptr<Node> definee, std::string name, std::unique_ptr<Node> args, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> assignment_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a string with interpolation (i.e. `"#{foo}"`)
class Dstr
{
public:
    // A list of string parts (static literals and interpolated expressions)
    std::vector<Node> parts;
    // Location of the string begin
    //
    // ```text
    // "#{foo}"
    // ~
    //
    // %Q{#{foo}}
    // ~~~
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of the string end
    //
    // ```text
    // "#{foo}"
    //        ~
    //
    // %Q{#{foo}}
    //          ~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // "#{foo}"
    // ~~~~~~~~
    //
    // %Q{#{foo}}
    // ~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Dstr() = delete;
    Dstr(Dstr &&) = default;
    Dstr(const Dstr &) = delete;
    explicit Dstr(std::vector<Node> parts, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a symbol with interpolation (i.e. `:"#{foo}"`)
class Dsym
{
public:
    // A list of symbol parts (static literals and interpolated expressions)
    std::vector<Node> parts;
    // Location of the symbol begin
    //
    // ```text
    // :"#{foo}"
    // ~~
    // ```
    //
    // `None` if `Dsym` is a part of the interpolated symbol array:
    //
    // ```text
    // %I[#{bar}]
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of the symbol begin
    //
    // ```text
    // :"#{foo}"
    //         ~
    // ```
    //
    // `None` if `Dsym` is a part of the interpolated symbol array:
    //
    // ```text
    // %I[#{bar}]
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // :"#{foo}"
    // ~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Dsym() = delete;
    Dsym(Dsym &&) = default;
    Dsym(const Dsym &) = delete;
    explicit Dsym(std::vector<Node> parts, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents exclusive flip-flop (i.e. in `if foo...bar; end`)
class EFlipFlop
{
public:
    // Left part of the flip-flop. `None` if based on a range without begin (`...bar`)
    std::unique_ptr<Node> left;
    // Right part of the flip-flop. `None` if based on a range without end (`foo...`)
    std::unique_ptr<Node> right;
    // Location of the `...` operator
    //
    // ```text
    // if foo...bar; end
    //       ~~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // if foo...bar; end
    //    ~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    EFlipFlop() = delete;
    EFlipFlop(EFlipFlop &&) = default;
    EFlipFlop(const EFlipFlop &) = delete;
    explicit EFlipFlop(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents a special empty else that is a part of the pattern matching.//// Usually empty else (e.g. part of the `if` statement) doesn't mean anything,// however in pattern matching it prevents raising a `NoPatternError`.//// Throwing away this `else` may affect your code.
class EmptyElse
{
public:
    // Location of the `else` keyword
    //
    // ```text
    // case foo; in 1; else; end
    //                 ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    EmptyElse() = delete;
    EmptyElse(EmptyElse &&) = default;
    EmptyElse(const EmptyElse &) = delete;
    explicit EmptyElse(std::unique_ptr<Loc> expression_l);
};

// Represents a special `__ENCODING__` keyword
class Encoding
{
public:
    // Location of the `__ENCODING__` keyword
    //
    // ```text
    // __ENCODING__
    // ~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Encoding() = delete;
    Encoding(Encoding &&) = default;
    Encoding(const Encoding &) = delete;
    explicit Encoding(std::unique_ptr<Loc> expression_l);
};

// Represents a block of code with `ensure` (i.e. `begin; ensure; end`)
class Ensure
{
public:
    // Block of code that is wrapped into `ensure`
    // **Note**: that's the body of the `ensure` block
    //
    // `Int("1")` for `begin; 1; ensure; 2; end`
    std::unique_ptr<Node> body;
    // Body of the `ensure` block
    //
    // `Int("2")` for `begin; 1; ensure; 2; end`
    std::unique_ptr<Node> ensure;
    // Location of the `ensure` keyword
    //
    // ```text
    // begin; ensure; end
    //        ~~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the full expression
    //
    // ```text
    // begin; 1; rescue; 2; else; 3; ensure; 4; end
    //        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    //
    // **Note**: begin/end belong to `KwBegin` node.
    std::unique_ptr<Loc> expression_l;

    Ensure() = delete;
    Ensure(Ensure &&) = default;
    Ensure(const Ensure &) = delete;
    explicit Ensure(std::unique_ptr<Node> body, std::unique_ptr<Node> ensure, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

// Represents range literal with excluded `end` (i.e. `1...3`)
class Erange
{
public:
    // Begin of the range, `None` if range has no begin (i.e `...42`)
    std::unique_ptr<Node> left;
    // End of the range, `None` if range has no end (i.e `42...`)
    std::unique_ptr<Node> right;
    // Location of the `...` operator
    //
    // ```text
    // 1...3
    //  ~~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // 1...3
    // ~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Erange() = delete;
    Erange(Erange &&) = default;
    Erange(const Erange &) = delete;
    explicit Erange(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents a `false` literal
class False
{
public:
    // Location of the `false` literal
    //
    // ```text
    // false
    // ~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    False() = delete;
    False(False &&) = default;
    False(const False &) = delete;
    explicit False(std::unique_ptr<Loc> expression_l);
};

// Represents a special `__FILE__` literal
class File
{
public:
    // Location of the `__FILE__` literal
    //
    // ```text
    // __FILE__
    // ~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    File() = delete;
    File(File &&) = default;
    File(const File &) = delete;
    explicit File(std::unique_ptr<Loc> expression_l);
};

// Represents a find pattern using in pattern matching (i.e. `in [*x, 1 => a, *y]`)//// It's different from `ArrayPattern`/`ConstPattern` because it supports multiple wildcard pattern
class FindPattern
{
public:
    // Inner part of the find pattern
    std::vector<Node> elements;
    // Location of the begin
    //
    // ```text
    // case foo; in [*x, 1 => a, *y]; end
    //              ~
    // ```
    //
    // `None` if there are no brackets/parentheses
    std::unique_ptr<Loc> begin_l;
    // Location of the end
    //
    // ```text
    // case foo; in [*x, 1 => a, *y]; end
    //                             ~
    // ```
    //
    // `None` if there are no brackets/parentheses
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in [*x, 1 => a, *y]; end
    //              ~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    FindPattern() = delete;
    FindPattern(FindPattern &&) = default;
    FindPattern(const FindPattern &) = delete;
    explicit FindPattern(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a float literal (i.e. `42.5`)
class Float
{
public:
    // String value of the literal, `String("42.5")` for `42.5`
    std::string value;
    // Location of unary `-` (but not `+`)
    //
    // ```text
    // -42.5
    // ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // -42.5
    // ~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Float() = delete;
    Float(Float &&) = default;
    Float(const Float &) = delete;
    explicit Float(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents a `for` loop
class For
{
public:
    // Variable that is used in loop, `Lvasgn("a")` in `for a in b; end`
    std::unique_ptr<Node> iterator;
    // Collection that is for iteration. `Lvar("b")` in `for a in b; end`
    std::unique_ptr<Node> iteratee;
    // Body of the loop. `None` if there's no body
    std::unique_ptr<Node> body;
    // Location of the `for` keyword
    //
    // ```text
    // for a in b; end
    // ~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `in` keyword
    //
    // ```text
    // for a in b; end
    //       ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the `do` keyword
    //
    // ```text
    // for a in b do; end
    //            ~~
    // ```
    //
    // **Note**: this `do` is optional, and so `begin_l` can be `None`.
    std::unique_ptr<Loc> begin_l;
    // Location of the `end` keyword
    //
    // ```text
    // for a in b; end
    //             ~~~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // for a in b; end
    // ~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    For() = delete;
    For(For &&) = default;
    For(const For &) = delete;
    explicit For(std::unique_ptr<Node> iterator, std::unique_ptr<Node> iteratee, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a special `...` argument that forwards positional/keyword/block arguments.
class ForwardArg
{
public:
    // Location of the `...`
    //
    // ```text
    // def m(...); end
    //       ~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    ForwardArg() = delete;
    ForwardArg(ForwardArg &&) = default;
    ForwardArg(const ForwardArg &) = delete;
    explicit ForwardArg(std::unique_ptr<Loc> expression_l);
};

// Represents a `...` operator that contains forwarded argument (see `ForwardArg`)
class ForwardedArgs
{
public:
    // Location of the `...`
    //
    // ```text
    // def m(...); foo(...); end
    //                 ~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    ForwardedArgs() = delete;
    ForwardedArgs(ForwardedArgs &&) = default;
    ForwardedArgs(const ForwardedArgs &) = delete;
    explicit ForwardedArgs(std::unique_ptr<Loc> expression_l);
};

// Represents access to global variable (i.e. `$foo`)
class Gvar
{
public:
    // Name of the global variable, `String("$foo")` for `$foo`
    std::string name;
    // Location of the full expression
    //
    // ```text
    // $foo
    // ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Gvar() = delete;
    Gvar(Gvar &&) = default;
    Gvar(const Gvar &) = delete;
    explicit Gvar(std::string name, std::unique_ptr<Loc> expression_l);
};

// Represents global variable assignment (i.e. `$foo = 42`)
class Gvasgn
{
public:
    // Name of the global variable, `String("$foo")` for `$foo`
    std::string name;
    // Value that is assigned to global variable, `Int("42")` for `$foo = 42`
    //
    // `None` if global variable assignment is a part of the multi-assignment.
    // In such case `value` is a part of the `Masgn` node.
    std::unique_ptr<Node> value;
    // Location of the global variable name
    //
    // ```text
    // $foo = 42
    // ~~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the `=` operator
    //
    // ```text
    // $foo = 42
    //      ~
    // ```
    //
    // `None` if global variable assignment is a part of the multi-assignment.
    // In such case `=` operator belongs to the `Masgn` node.
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // $foo = 42
    // ~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Gvasgn() = delete;
    Gvasgn(Gvasgn &&) = default;
    Gvasgn(const Gvasgn &) = delete;
    explicit Gvasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents a hash literal (i.e. `{ foo: 42 }`)
class Hash
{
public:
    // A list of key-value pairs
    std::vector<Node> pairs;
    // Location of the open parenthesis
    //
    // ```text
    // { a: 1 }
    // ~
    // ```
    //
    // `None` if hash literal is implicit, e.g. `foo(key: "value")`
    std::unique_ptr<Loc> begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // { a: 1 }
    //        ~
    // ```
    //
    // `None` if hash literal is implicit, e.g. `foo(key: "value")`
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // { a: 1 }
    // ~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Hash() = delete;
    Hash(Hash &&) = default;
    Hash(const Hash &) = delete;
    explicit Hash(std::vector<Node> pairs, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents kwargs that are given to a method call, super or yield (i.e. `foo(bar: 1)`)
class Kwargs
{
public:
    // A list of key-value pairs
    std::vector<Node> pairs;
    // Location of the full expression
    //
    // ```text
    // foo(bar: 1)
    //     ~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Kwargs() = delete;
    Kwargs(Kwargs &&) = default;
    Kwargs(const Kwargs &) = delete;
    explicit Kwargs(std::vector<Node> pairs, std::unique_ptr<Loc> expression_l);
};

// Represents a hash pattern used in pattern matching (i.e. `in { a: 1 }`)
class HashPattern
{
public:
    // A list of inner patterns
    std::vector<Node> elements;
    // Location of the open parenthesis
    //
    // ```text
    // case foo; in { a: 1 }; end
    //              ~
    // ```
    //
    // `None` if there are no parentheses
    std::unique_ptr<Loc> begin_l;
    // Location of the open parenthesis
    //
    // ```text
    // case foo; in { a: 1 }; end
    //                     ~
    // ```
    //
    // `None` if there are no parentheses
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in { a: 1 }; end
    //              ~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    HashPattern() = delete;
    HashPattern(HashPattern &&) = default;
    HashPattern(const HashPattern &) = delete;
    explicit HashPattern(std::vector<Node> elements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a here-document literal (both with and without interpolation)//// It's similar to `Dstr` in terms of abstract syntax tree, but has different source maps.
class Heredoc
{
public:
    // A list of string parts (static literals and interpolated expressions)
    std::vector<Node> parts;
    // Location of the here-document body
    //
    // ```text
    // <<-HERE\n  a\n   #{42}\nHERE
    //          ~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> heredoc_body_l;
    // Location of the here-document end
    //
    // ```text
    // <<-HERE\n  a\n   #{42}\nHERE
    //                         ~~~~
    // ```
    std::unique_ptr<Loc> heredoc_end_l;
    // Location of the here-document identifier
    //
    // ```text
    // <<-HERE\n  a\n   #{42}\nHERE
    // ~~~~~~~
    // ```
    //
    // **Note**: This is the only node (with `XHeredoc`) that has `expression_l` smaller that all other sub-locations merged.
    // The reason for that is that it's possible to add more code after here-document ID:
    //
    // ```text
    // <<-HERE + "rest"
    //   content
    // HERE
    // ```
    std::unique_ptr<Loc> expression_l;

    Heredoc() = delete;
    Heredoc(Heredoc &&) = default;
    Heredoc(const Heredoc &) = delete;
    explicit Heredoc(std::vector<Node> parts, std::unique_ptr<Loc> heredoc_body_l, std::unique_ptr<Loc> heredoc_end_l, std::unique_ptr<Loc> expression_l);
};

// Represents an `if` statement (i.e. `if foo; bar; else; baz; end`)
class If
{
public:
    // Condition given to the `if` statement, `Lvar("a")` for `if a; b; else; c; end`
    std::unique_ptr<Node> cond;
    // True-branch of the `if` statement, `Lvar("b")` for `if a; b; else; c; end`
    std::unique_ptr<Node> if_true;
    // False-branch of the `if` statement, `Lvar("c")` for `if a; b; else; c; end`
    std::unique_ptr<Node> if_false;
    // Location of the `if` keyword
    //
    // ```text
    // if foo; end
    // ~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `then` keyword
    //
    // ```text
    // if foo then; end
    //        ~~~~
    // ```
    //
    // `None` if `then` keyword is omitted
    std::unique_ptr<Loc> begin_l;
    // Location of the `else` keyword
    //
    // ```text
    // if foo; else; end
    //         ~~~~
    // ```
    //
    // `None` if there's no `else` branch
    std::unique_ptr<Loc> else_l;
    // Location of the `end` keyword
    //
    // ```text
    // if foo; end
    //         ~~~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // if a then; b; else; c end
    // ~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    If() = delete;
    If(If &&) = default;
    If(const If &) = delete;
    explicit If(std::unique_ptr<Node> cond, std::unique_ptr<Node> if_true, std::unique_ptr<Node> if_false, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents an `if` guard used in pattern matching (i.e. `case foo; in pattern if guard; end`)
class IfGuard
{
public:
    // Condition of the guard, `Lvar("foo")` in `in pattern if guard`
    std::unique_ptr<Node> cond;
    // Location of the `if` keyword
    //
    // ```text
    // case foo; in pattern if cond; end
    //                      ~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in pattern if cond; end
    //                      ~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    IfGuard() = delete;
    IfGuard(IfGuard &&) = default;
    IfGuard(const IfGuard &) = delete;
    explicit IfGuard(std::unique_ptr<Node> cond, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

// Represents an `if`/`unless` modifier (i.e. `stmt if cond`)
class IfMod
{
public:
    // Condition of the modifier
    std::unique_ptr<Node> cond;
    // True-branch of the modifier.
    //
    // Always set for `if` modifier.
    // Always `None` for `unless` modifier.
    std::unique_ptr<Node> if_true;
    // False-branch of the modifier.
    //
    // Always set for `unless` modifier.
    // Always `None` for `if` modifier.
    std::unique_ptr<Node> if_false;
    // Location of the `if`/`unless` keyword
    //
    // ```text
    // stmt if cond
    //      ~~
    //
    // stmt unless cond
    //      ~~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the full expression
    //
    // ```text
    // stmt if cond
    // ~~~~~~~~~~~~
    //
    // stmt unless cond
    // ~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    IfMod() = delete;
    IfMod(IfMod &&) = default;
    IfMod(const IfMod &) = delete;
    explicit IfMod(std::unique_ptr<Node> cond, std::unique_ptr<Node> if_true, std::unique_ptr<Node> if_false, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

// Represents ternary `if` statement (i.e. `cond ? if_true : if_false`)
class IfTernary
{
public:
    // Condition of the `if` statement
    std::unique_ptr<Node> cond;
    // True-branch
    std::unique_ptr<Node> if_true;
    // True-branch
    std::unique_ptr<Node> if_false;
    // Location of the `?` operator
    //
    // ```text
    // cond ? if_true : if_false
    //      ~
    // ```
    std::unique_ptr<Loc> question_l;
    // Location of the `:` operator
    //
    // ```text
    // cond ? if_true : if_false
    //                ~
    // ```
    std::unique_ptr<Loc> colon_l;
    // Location of the full expression
    //
    // ```text
    // cond ? if_true : if_false
    // ~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    IfTernary() = delete;
    IfTernary(IfTernary &&) = default;
    IfTernary(const IfTernary &) = delete;
    explicit IfTernary(std::unique_ptr<Node> cond, std::unique_ptr<Node> if_true, std::unique_ptr<Node> if_false, std::unique_ptr<Loc> question_l, std::unique_ptr<Loc> colon_l, std::unique_ptr<Loc> expression_l);
};

// Represents inclusive flip-flop (i.e. in `if foo..bar; end`)
class IFlipFlop
{
public:
    // Left part of the flip-flop. `None` if based on a range without begin (`..bar`)
    std::unique_ptr<Node> left;
    // Right part of the flip-flop. `None` if based on a range without end (`foo..`)
    std::unique_ptr<Node> right;
    // Location of the `..` operator
    //
    // ```text
    // if foo..bar; end
    //       ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // if foo..bar; end
    //    ~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    IFlipFlop() = delete;
    IFlipFlop(IFlipFlop &&) = default;
    IFlipFlop(const IFlipFlop &) = delete;
    explicit IFlipFlop(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents a one-line pattern matching that can throw an error (i.e. `foo => pattern`)
class MatchPattern
{
public:
    // Value that is used for matching
    std::unique_ptr<Node> value;
    // Pattern that is used for matching
    std::unique_ptr<Node> pattern;
    // Location of the `=>` operator
    //
    // ```text
    // foo => pattern
    //     ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // foo => pattern
    // ~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    MatchPattern() = delete;
    MatchPattern(MatchPattern &&) = default;
    MatchPattern(const MatchPattern &) = delete;
    explicit MatchPattern(std::unique_ptr<Node> value, std::unique_ptr<Node> pattern, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents a one-line pattern matching that never throws but returns true/false (i.e. `foo in pattern`)
class MatchPatternP
{
public:
    // Value that is used for matching
    std::unique_ptr<Node> value;
    // Pattern that is used for matching
    std::unique_ptr<Node> pattern;
    // Location of the `in` operator
    //
    // ```text
    // foo in pattern
    //     ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // foo in pattern
    // ~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    MatchPatternP() = delete;
    MatchPatternP(MatchPatternP &&) = default;
    MatchPatternP(const MatchPatternP &) = delete;
    explicit MatchPatternP(std::unique_ptr<Node> value, std::unique_ptr<Node> pattern, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents an `in pattern` branch of the pattern matching
class InPattern
{
public:
    // Value that is used for matching
    std::unique_ptr<Node> pattern;
    // Guard that is used for matching
    //
    // Optional, so can be `None`
    std::unique_ptr<Node> guard;
    // Body of the branch that is invoked if value matches pattern
    std::unique_ptr<Node> body;
    // Location of the `in` keyword
    //
    // ```text
    // case value; in pattern; end
    //             ~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `then` keyword
    //
    // ```text
    // case value; in pattern then; end
    //                        ~~~~
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of the full expression
    //
    // ```text
    // case value; in pattern then; 42; end
    //             ~~~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    InPattern() = delete;
    InPattern(InPattern &&) = default;
    InPattern(const InPattern &) = delete;
    explicit InPattern(std::unique_ptr<Node> pattern, std::unique_ptr<Node> guard, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> expression_l);
};

// Represents indexing operation (i.e. `foo[1,2,3]`)
class Index
{
public:
    // Receiver of indexing
    std::unique_ptr<Node> recv;
    // A list of indexes
    std::vector<Node> indexes;
    // Location of open bracket
    //
    // ```text
    // foo[1, 2, 3]
    //    ~
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of closing bracket
    //
    // ```text
    // foo[1, 2, 3]
    //            ~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // foo[1, 2, 3]
    // ~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Index() = delete;
    Index(Index &&) = default;
    Index(const Index &) = delete;
    explicit Index(std::unique_ptr<Node> recv, std::vector<Node> indexes, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents assignment using indexing operation (i.e. `foo[1, 2, 3] = bar`)
class IndexAsgn
{
public:
    // Receiver of the indexing
    std::unique_ptr<Node> recv;
    // A list of indexes
    std::vector<Node> indexes;
    // Value that is assigned
    //
    // `None` if assignment is a part of the multi-assignment.
    // In such case `value` belongs to `Masgn` node.
    std::unique_ptr<Node> value;
    // Location of open bracket
    //
    // ```text
    // foo[1, 2, 3] = bar
    //    ~
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of closing bracket
    //
    // ```text
    // foo[1, 2, 3] = bar
    //            ~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the `=` operator
    //
    // ```text
    // foo[1, 2, 3] = bar
    //              ~
    // ```
    //
    // `None` if assignment is a part of the multi-assignment.
    // In such case operator `=` belongs to `Masgn` node.
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // foo[1, 2, 3] = bar
    // ~~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    IndexAsgn() = delete;
    IndexAsgn(IndexAsgn &&) = default;
    IndexAsgn(const IndexAsgn &) = delete;
    explicit IndexAsgn(std::unique_ptr<Node> recv, std::vector<Node> indexes, std::unique_ptr<Node> value, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents an integer literal (i.e. `42`)
class Int
{
public:
    // String value of the literal, `String("42")` for `42`
    std::string value;
    // Location of unary `-` (but not `+`)
    //
    // ```text
    // -42
    // ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // -42
    // ~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Int() = delete;
    Int(Int &&) = default;
    Int(const Int &) = delete;
    explicit Int(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents inclusive range (i.e. `2..4`)
class Irange
{
public:
    // Begin of the range, `None` if range has no `begin` (i.e. `..4`)
    std::unique_ptr<Node> left;
    // End of the range, `None` if range has no `end` (i.e. `2..`)
    std::unique_ptr<Node> right;
    // Location of the `..` operator
    //
    // ```text
    // 2..4
    //  ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // 2..4
    // ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Irange() = delete;
    Irange(Irange &&) = default;
    Irange(const Irange &) = delete;
    explicit Irange(std::unique_ptr<Node> left, std::unique_ptr<Node> right, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents access to instance variable (i.e. `@foo`)
class Ivar
{
public:
    // Name of the instance variable, `String("@foo")` in `@foo`
    std::string name;
    // Location of the full expression
    //
    // ```text
    // @foo
    // ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Ivar() = delete;
    Ivar(Ivar &&) = default;
    Ivar(const Ivar &) = delete;
    explicit Ivar(std::string name, std::unique_ptr<Loc> expression_l);
};

// Represents instance variable assignment (i.e `@foo = 42`)
class Ivasgn
{
public:
    // Name of the instance variable, `String("@foo")` in `@foo = 42`
    std::string name;
    // Value that is assigned to instance variable.
    //
    // `None` if instance variable assignment is a part of the multi-assignment.
    // In such case `value` is a part of the `Masgn` node.
    std::unique_ptr<Node> value;
    // Location of the instance variable name.
    //
    // ```text
    // @foo = 1
    // ~~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the `=` operator.
    //
    // ```text
    // @foo = 1
    //      ~
    // ```
    //
    // `None` if instance variable assignment is a part of the multi-assignment.
    // In such case `value` is a part of the `Masgn` node.
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // @foo = 42
    // ~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Ivasgn() = delete;
    Ivasgn(Ivasgn &&) = default;
    Ivasgn(const Ivasgn &) = delete;
    explicit Ivasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents required keyword argument (i.e. `foo` in `def m(foo:); end`)
class Kwarg
{
public:
    // Name of the keyword argument
    std::string name;
    // Location of the name
    //
    // ```text
    // def foo(bar:); end
    //         ~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the full expression
    //
    // ```text
    // def foo(bar:); end
    //         ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Kwarg() = delete;
    Kwarg(Kwarg &&) = default;
    Kwarg(const Kwarg &) = delete;
    explicit Kwarg(std::string name, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

// Represents an explicit `begin; end` block.//// The reason why it's different is that only// ```text// begin; foo; end while cond// ```// is a post-while loop (same with post-until loop)
class KwBegin
{
public:
    // A list of statements
    std::vector<Node> statements;
    // Location of the `begin` keyword
    //
    // ```text
    // begin; foo; end
    // ~~~~~
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of the `begin` keyword
    //
    // ```text
    // begin; foo; end
    //             ~~~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // begin; foo; bar
    // ~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    KwBegin() = delete;
    KwBegin(KwBegin &&) = default;
    KwBegin(const KwBegin &) = delete;
    explicit KwBegin(std::vector<Node> statements, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents an special argument that rejects all keyword arguments (i.e. `def m(**nil); end`)
class Kwnilarg
{
public:
    // Location of the `nil`
    //
    // ```text
    // def m(**nil); end
    //         ~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the `nil`
    //
    // ```text
    // def m(**nil); end
    //       ~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Kwnilarg() = delete;
    Kwnilarg(Kwnilarg &&) = default;
    Kwnilarg(const Kwnilarg &) = delete;
    explicit Kwnilarg(std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

// Represents an optional keyword argument (i.e. `foo` in `def m(foo: 42); end`)
class Kwoptarg
{
public:
    // Name of the optional keyword argument
    std::string name;
    // Default value of the optional keyword argument
    std::unique_ptr<Node> default_;
    // Location of the argument name
    //
    // ```text
    // def m(foo: 1); end
    //       ~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the argument name
    //
    // ```text
    // def m(foo: 1); end
    //       ~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Kwoptarg() = delete;
    Kwoptarg(Kwoptarg &&) = default;
    Kwoptarg(const Kwoptarg &) = delete;
    explicit Kwoptarg(std::string name, std::unique_ptr<Node> default_, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

// Represents a keyword rest argument (i.e. `foo` in `def m(**foo); end`)
class Kwrestarg
{
public:
    // Name of the keyword rest argument, `String("foo")` in `def m(**foo); end`.
    //
    // `None` if argument has no name (`def m(**); end`)
    std::string name;
    // Location of the `**` operator
    //
    // ```text
    // def m(**foo); end
    //       ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the argument name
    //
    // ```text
    // def m(**foo); end
    //         ~~~
    // ```
    //
    // `None` if argument has no name (`def m(**); end`)
    std::unique_ptr<Loc> name_l;
    // Location of the full expression
    //
    // ```text
    // def m(**foo); end
    //       ~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Kwrestarg() = delete;
    Kwrestarg(Kwrestarg &&) = default;
    Kwrestarg(const Kwrestarg &) = delete;
    explicit Kwrestarg(std::string name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

// Represents a keyword arguments splat (i.e. `**bar` in a call like `foo(**bar)`)
class Kwsplat
{
public:
    // Value that is converted into a `Hash` using `**`
    std::unique_ptr<Node> value;
    // Location of the `**` operator
    //
    // ```text
    // foo(**bar)
    //     ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // foo(**bar)
    //     ~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Kwsplat() = delete;
    Kwsplat(Kwsplat &&) = default;
    Kwsplat(const Kwsplat &) = delete;
    explicit Kwsplat(std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents a lambda call using `->` (i.e. `-> {}`)//// Note that `Lambda` is a part of the `Block`, not other way around.
class Lambda
{
public:
    // Location of the `->`
    //
    // ```text
    // -> {}
    // ~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Lambda() = delete;
    Lambda(Lambda &&) = default;
    Lambda(const Lambda &) = delete;
    explicit Lambda(std::unique_ptr<Loc> expression_l);
};

// Represents a special `__LINE__` literal
class Line
{
public:
    // Location of the `__LINE__` literal
    //
    // ```text
    // __LINE__
    // ~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Line() = delete;
    Line(Line &&) = default;
    Line(const Line &) = delete;
    explicit Line(std::unique_ptr<Loc> expression_l);
};

// Represents access to a local variable (i.e. `foo`)//// Parser knows that it's a local variable because://     1. there was an assignment to this variable **before** accessing it//     2. it's an argument of the current method / block//     3. it's been implicitly declared by `MatchWithLvasgn` node//// Otherwise it's a method call (see `Send`)
class Lvar
{
public:
    // Name of the local variable
    std::string name;
    // Location of the local variable
    //
    // ```text
    // foo
    // ~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Lvar() = delete;
    Lvar(Lvar &&) = default;
    Lvar(const Lvar &) = delete;
    explicit Lvar(std::string name, std::unique_ptr<Loc> expression_l);
};

// Represents local variable assignment (i.e. `foo = 42`)
class Lvasgn
{
public:
    // Name of the local variable
    std::string name;
    // Value that is assigned to a local variable
    std::unique_ptr<Node> value;
    // Location of the local variable name
    //
    // ```text
    // foo = 42
    // ~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the `=` operator
    //
    // ```text
    // foo = 42
    //     ~
    // ```
    //
    // `None` if local variable assignment is a part of the multi-assignment.
    // In such case `value` is a part of the `Masgn` node.
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // foo = 42
    // ~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Lvasgn() = delete;
    Lvasgn(Lvasgn &&) = default;
    Lvasgn(const Lvasgn &) = delete;
    explicit Lvasgn(std::string name, std::unique_ptr<Node> value, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents mass-assignment (i.e. `foo, bar = 1, 2`)
class Masgn
{
public:
    // Left hand statement of the assignment
    std::unique_ptr<Node> lhs;
    // Left hand statement of the assignment
    std::unique_ptr<Node> rhs;
    // Location of the `=` operator
    //
    // ```text
    // foo, bar = 1, 2
    //          ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // foo, bar = 1, 2
    // ~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Masgn() = delete;
    Masgn(Masgn &&) = default;
    Masgn(const Masgn &) = delete;
    explicit Masgn(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents pattern matching using one of the given patterns (i.e. `foo in 1 | 2`)
class MatchAlt
{
public:
    // Left pattern
    std::unique_ptr<Node> lhs;
    // Right pattern
    std::unique_ptr<Node> rhs;
    // Location of the `|` operator
    //
    // ```text
    // foo in 1 | 2
    //          ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // foo in 1 | 2
    //        ~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    MatchAlt() = delete;
    MatchAlt(MatchAlt &&) = default;
    MatchAlt(const MatchAlt &) = delete;
    explicit MatchAlt(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents matching with renaming into specified local variable (i.e. `case 1; in Integer => a; end`)
class MatchAs
{
public:
    // Pattern that is used for matching
    std::unique_ptr<Node> value;
    // Variable that is assigned if matched (see `MatchVar` node)
    std::unique_ptr<Node> as_;
    // Location of the `=>` operator
    //
    // ```text
    // case 1; in Integer => a; end
    //                    ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the `=>` operator
    //
    // ```text
    // case 1; in Integer => a; end
    //            ~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    MatchAs() = delete;
    MatchAs(MatchAs &&) = default;
    MatchAs(const MatchAs &) = delete;
    explicit MatchAs(std::unique_ptr<Node> value, std::unique_ptr<Node> as_, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents implicit matching using `if /regex/`//// ```text// if /.*///   puts 'true'// else//   puts 'false'// end// ```// Prints "false".//// Under the hood this construction matches regex against `$_`, so the following works:// ```text// $_ = 'match_me'// if /match_me///   puts 'true'// else//   puts 'false'// end// ```// this code prints "true".
class MatchCurrentLine
{
public:
    // Given regex
    std::unique_ptr<Node> re;
    // Location of the regex
    //
    // ```text
    // if /re/; end
    //    ~~~~
    // ```
    //
    // Technically this location is redundant, but keeping it is the only way to
    // have the same interface for all nodes.
    std::unique_ptr<Loc> expression_l;

    MatchCurrentLine() = delete;
    MatchCurrentLine(MatchCurrentLine &&) = default;
    MatchCurrentLine(const MatchCurrentLine &) = delete;
    explicit MatchCurrentLine(std::unique_ptr<Node> re, std::unique_ptr<Loc> expression_l);
};

// Represents empty hash pattern that is used in pattern matching (i.e. `in **nil`)
class MatchNilPattern
{
public:
    // Location of the `**` operator
    //
    // ```text
    // in **nil
    //    ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the name
    //
    // ```text
    // in **nil
    //      ~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the full expression
    //
    // ```text
    // in **nil
    //    ~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    MatchNilPattern() = delete;
    MatchNilPattern(MatchNilPattern &&) = default;
    MatchNilPattern(const MatchNilPattern &) = delete;
    explicit MatchNilPattern(std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

// Represents a wildcard pattern used in pattern matching (i.e. `in *foo`)
class MatchRest
{
public:
    // Name of the variable name
    //
    // `None` if there's no name (i.e. `in *`)
    std::unique_ptr<Node> name;
    // Location of the `*` operator
    //
    // ```text
    // case foo; in *bar; end
    //              ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the `*` operator
    //
    // ```text
    // case foo; in *bar; end
    //              ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    MatchRest() = delete;
    MatchRest(MatchRest &&) = default;
    MatchRest(const MatchRest &) = delete;
    explicit MatchRest(std::unique_ptr<Node> name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents matching with assignment into a local variable (i.e. `pattern => var`)
class MatchVar
{
public:
    // Name of the variable that is assigned if matching succeeds
    std::string name;
    // Location of the name
    //
    // ```text
    // case foo; in pattern => bar; end
    //                         ~~~
    // ```
    //
    // **Note** it can also be produced by a hash pattern
    //
    // ```text
    // case foo; in { a: }; end
    //                ~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in pattern => bar; end
    //                         ~~~
    // ```
    //
    // **Note** it can also be produced by a hash pattern
    //
    // ```text
    // case foo; in { a: }; end
    //                ~~
    // ```
    std::unique_ptr<Loc> expression_l;

    MatchVar() = delete;
    MatchVar(MatchVar &&) = default;
    MatchVar(const MatchVar &) = delete;
    explicit MatchVar(std::string name, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

// Represents matching a regex that produces local variables (i.e. `/(?<match>bar)/ =~ 'bar'`)//// Each named group in regex declares a local variable.
class MatchWithLvasgn
{
public:
    // Regex that is used for matching
    std::unique_ptr<Node> re;
    // Value that is used for matching
    std::unique_ptr<Node> value;
    // Location of the `=~` operatir
    //
    // ```text
    // /(?<match>bar)/ =~ 'bar'
    //                 ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // /(?<match>bar)/ =~ 'bar'
    // ~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    MatchWithLvasgn() = delete;
    MatchWithLvasgn(MatchWithLvasgn &&) = default;
    MatchWithLvasgn(const MatchWithLvasgn &) = delete;
    explicit MatchWithLvasgn(std::unique_ptr<Node> re, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents left hand statement of the mass-assignment (i.e. `foo, bar` in `foo, bar = 1, 2`)
class Mlhs
{
public:
    // A list of items that are assigned
    std::vector<Node> items;
    // Location of the open parenthesis
    //
    // ```text
    // (a, b) = 1, 2
    // ~
    // ```
    //
    // `None` if there are no parentheses
    std::unique_ptr<Loc> begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // (a, b) = 1, 2
    //      ~
    // ```
    //
    // `None` if there are no parentheses
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // (a, b) = 1, 2
    // ~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Mlhs() = delete;
    Mlhs(Mlhs &&) = default;
    Mlhs(const Mlhs &) = delete;
    explicit Mlhs(std::vector<Node> items, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents module declaration using `module` keyword
class Module
{
public:
    // Name of the module
    std::unique_ptr<Node> name;
    // Body of the module
    //
    // `None` if module has no body
    std::unique_ptr<Node> body;
    // Location of the `module` keyword
    //
    // ```text
    // module M; end
    // ~~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `end` keyword
    //
    // ```text
    // module M; end
    //           ~~~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // module M; end
    // ~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Module() = delete;
    Module(Module &&) = default;
    Module(const Module &) = delete;
    explicit Module(std::unique_ptr<Node> name, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents `next` keyword
class Next
{
public:
    // Arguments given to `next`
    std::vector<Node> args;
    // Location of the `next` keyword
    //
    // ```text
    // next 42
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the full expression
    //
    // ```text
    // next(42)
    // ~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Next() = delete;
    Next(Next &&) = default;
    Next(const Next &) = delete;
    explicit Next(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

// Represents `nil` literal
class Nil
{
public:
    // Location of the `nil` keyword
    //
    // ```text
    // nil
    // ~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Nil() = delete;
    Nil(Nil &&) = default;
    Nil(const Nil &) = delete;
    explicit Nil(std::unique_ptr<Loc> expression_l);
};

// Represents numeric global variable (e.g. `$1`)
class NthRef
{
public:
    // Name of the variable, `String("1")` for `$1`
    std::string name;
    // Location of the full expression
    //
    // ```text
    // $1
    // ~~
    // ```
    std::unique_ptr<Loc> expression_l;

    NthRef() = delete;
    NthRef(NthRef &&) = default;
    NthRef(const NthRef &) = delete;
    explicit NthRef(std::string name, std::unique_ptr<Loc> expression_l);
};

// Represents a block that takes numbered parameters (i.e. `proc { _1 }`)
class Numblock
{
public:
    // Method call that takes a block
    std::unique_ptr<Node> call;
    // Number of parameters that block takes
    uint32_t numargs;
    // Block body
    std::unique_ptr<Node> body;
    // Location of the open brace
    //
    // ```text
    // proc { _1 }
    //      ~
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of the closing brace
    //
    // ```text
    // proc { _1 }
    //           ~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the open brace
    //
    // ```text
    // proc { _1 }
    // ~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Numblock() = delete;
    Numblock(Numblock &&) = default;
    Numblock(const Numblock &) = delete;
    explicit Numblock(std::unique_ptr<Node> call, uint32_t numargs, std::unique_ptr<Node> body, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents an operation with assignment (e.g. `a += 1`)
class OpAsgn
{
public:
    // Left hand statement of the assignment
    std::unique_ptr<Node> recv;
    // Operator, can be one of:
    //     1. `+=`
    //     2. `-=`
    //     3. `*=`
    //     4. `/=`
    //     5. `|=`
    //     6. `&=`
    //     7. `>>=`
    //     8. `<<=`
    //     9. `%=`
    //     10. `^=`
    //     11. `**=`
    std::string operator_;
    // Right hand statement of the assignment
    std::unique_ptr<Node> value;
    // Location of the operator
    //
    // ```text
    // a.b <<= c
    //     ~~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the operator
    //
    // ```text
    // a.b <<= c
    // ~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    OpAsgn() = delete;
    OpAsgn(OpAsgn &&) = default;
    OpAsgn(const OpAsgn &) = delete;
    explicit OpAsgn(std::unique_ptr<Node> recv, std::string operator_, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents optional positional argument (i.e. `foo` in `m(foo = 1)`)
class Optarg
{
public:
    // Name of the argument
    std::string name;
    // Default value of the argument
    std::unique_ptr<Node> default_;
    // Location of the argument name
    //
    // ```text
    // def m(foo = 1); end
    //       ~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the `=` operator
    //
    // ```text
    // def m(foo = 1); end
    //           ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // def m(foo = 1); end
    //       ~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Optarg() = delete;
    Optarg(Optarg &&) = default;
    Optarg(const Optarg &) = delete;
    explicit Optarg(std::string name, std::unique_ptr<Node> default_, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents `foo || bar` (or `foo or bar`) statement.
class Or
{
public:
    // Left hand statement
    std::unique_ptr<Node> lhs;
    // Right hand statement
    std::unique_ptr<Node> rhs;
    // Location of the `||`/`or` operator
    //
    // ```text
    // foo || bar
    //     ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // foo || bar
    // ~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Or() = delete;
    Or(Or &&) = default;
    Or(const Or &) = delete;
    explicit Or(std::unique_ptr<Node> lhs, std::unique_ptr<Node> rhs, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents `lhs ||= rhs` assignment
class OrAsgn
{
public:
    // Left hand statement
    std::unique_ptr<Node> recv;
    // Right hand statement
    std::unique_ptr<Node> value;
    // Location of the `||=` operator
    //
    // ```text
    // foo ||= bar
    //     ~~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // foo ||= bar
    // ~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    OrAsgn() = delete;
    OrAsgn(OrAsgn &&) = default;
    OrAsgn(const OrAsgn &) = delete;
    explicit OrAsgn(std::unique_ptr<Node> recv, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents a key/value pair (e.g. a part of the `Hash` node)
class Pair
{
public:
    // Key of the pair
    std::unique_ptr<Node> key;
    // Value of the pair
    std::unique_ptr<Node> value;
    // Location of the `:` or `=>` operator
    //
    // ```text
    // { foo: bar }
    //      ~
    //
    // { :foo => bar }
    //        ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // { foo: bar }
    //   ~~~~~~~~
    //
    // { :foo => bar }
    //   ~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Pair() = delete;
    Pair(Pair &&) = default;
    Pair(const Pair &) = delete;
    explicit Pair(std::unique_ptr<Node> key, std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents a pattern based on a "pinned" variable (e.g. `^foo`)
class Pin
{
public:
    // Variable that is pinned
    std::unique_ptr<Node> var;
    // Location of the `^` operator
    //
    // ```text
    // case foo; in ^bar; end
    //              ~
    // ```
    std::unique_ptr<Loc> selector_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in ^bar; end
    //              ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Pin() = delete;
    Pin(Pin &&) = default;
    Pin(const Pin &) = delete;
    explicit Pin(std::unique_ptr<Node> var, std::unique_ptr<Loc> selector_l, std::unique_ptr<Loc> expression_l);
};

// Represents `END { .. }` statement
class Postexe
{
public:
    // Body of the block
    std::unique_ptr<Node> body;
    // Location of the `END` keyword
    //
    // ```text
    // END { 42 }
    // ~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // END { 42 }
    //     ~
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // END { 42 }
    //          ~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // END { 42 }
    // ~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Postexe() = delete;
    Postexe(Postexe &&) = default;
    Postexe(const Postexe &) = delete;
    explicit Postexe(std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents `BEGIN { ... }` statement
class Preexe
{
public:
    // Body of the block
    std::unique_ptr<Node> body;
    // Location of the `BEGIN` keyword
    //
    // ```text
    // BEGIN { 42 }
    // ~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // BEGIN { 42 }
    //       ~
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // BEGIN { 42 }
    //            ~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // BEGIN { 42 }
    // ~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Preexe() = delete;
    Preexe(Preexe &&) = default;
    Preexe(const Preexe &) = delete;
    explicit Preexe(std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a sole block argument (e.g. `|foo|`)//// Block that takes a single array argument automatically expands it.// Adding trailing comma after block argument disables this behavior (and then the only argument is emitted as `Arg`).
class Procarg0
{
public:
    // Parts of the sole block argument.
    //
    // `proc { |(a, b)| }` also counts as a sole argument, so this list may contain:
    //     1. A single `Arg` node (for `proc { |a| }` case)
    //     2. Multiple `Arg` nodes  (for `proc { |(a, b, c)| }` case)
    std::vector<Node> args;
    // Location of the open parenthesis
    //
    // ```text
    // proc { |(foo, bar)| }
    //         ~
    // ```
    //
    // `None` if there's only one argument
    std::unique_ptr<Loc> begin_l;
    // Location of the open parenthesis
    //
    // ```text
    // proc { |(foo, bar)| }
    //                  ~
    // ```
    //
    // `None` if there's only one argument
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // proc { |(foo, bar)| }
    //         ~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Procarg0() = delete;
    Procarg0(Procarg0 &&) = default;
    Procarg0(const Procarg0 &) = delete;
    explicit Procarg0(std::vector<Node> args, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents rational literal (e.g. `1r`)
class Rational
{
public:
    // String value of the literal, `String("1r")` for `1r`
    std::string value;
    // Location of the unary `-` (but not `+`)
    //
    // ```text
    // -1r
    // ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // -1r
    // ~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Rational() = delete;
    Rational(Rational &&) = default;
    Rational(const Rational &) = delete;
    explicit Rational(std::string value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents `redo` keyword
class Redo
{
public:
    // Location of the full expression
    //
    // ```text
    // redo
    // ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Redo() = delete;
    Redo(Redo &&) = default;
    Redo(const Redo &) = delete;
    explicit Redo(std::unique_ptr<Loc> expression_l);
};

// Represents flags of the regex literal (i.e. `mix` for `/foo/mix`)
class RegOpt
{
public:
    // A list of flags
    std::string options;
    // Location of the full expression
    //
    // ```text
    // /foo/mix
    //      ~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    RegOpt() = delete;
    RegOpt(RegOpt &&) = default;
    RegOpt(const RegOpt &) = delete;
    explicit RegOpt(std::string options, std::unique_ptr<Loc> expression_l);
};

// Represents regex literal (e.g. `/foo/`)
class Regexp
{
public:
    // A list of static and dynamic regex parts
    std::vector<Node> parts;
    // Regex options.
    //
    // `None` if regex has no explicit flags
    std::unique_ptr<Node> options;
    // Location of the regex begin
    //
    // ```text
    // /foo/
    // ~
    //
    // %r{foo}
    // ~~
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of the regex end
    //
    // ```text
    // /foo/
    //     ~
    //
    // %r{foo}
    //       ~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // /foo/mix
    // ~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Regexp() = delete;
    Regexp(Regexp &&) = default;
    Regexp(const Regexp &) = delete;
    explicit Regexp(std::vector<Node> parts, std::unique_ptr<Node> options, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a `rescue` block
class Rescue
{
public:
    // Body of the block that is wrapped into `rescue` (i.e. the part that may throw an error)
    std::unique_ptr<Node> body;
    // A list of `rescue` handlers (see `RescueBody` node)
    std::vector<Node> rescue_bodies;
    // Else branch.
    //
    // `None` if there's no `else` branch
    std::unique_ptr<Node> else_;
    // Location of the `else` keyword
    //
    // ```text
    // begin; 1; rescue StandardError => e; 2; else; 3; end
    //                                         ~~~~
    // ```
    //
    // `None` if there's no `else` branch
    std::unique_ptr<Loc> else_l;
    // Location of the full expression
    //
    // ```text
    // begin; 1; rescue StandardError => e; 2; else; 3; end
    //        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    //
    // **Note**: `begin/end` keywords belong to `KwBegin` node
    std::unique_ptr<Loc> expression_l;

    Rescue() = delete;
    Rescue(Rescue &&) = default;
    Rescue(const Rescue &) = delete;
    explicit Rescue(std::unique_ptr<Node> body, std::vector<Node> rescue_bodies, std::unique_ptr<Node> else_, std::unique_ptr<Loc> else_l, std::unique_ptr<Loc> expression_l);
};

// Represents a single `rescue` handler (i.e. `rescue E => e ...`)
class RescueBody
{
public:
    // A list of exception classes
    //
    // `None` if no classes specified (i.e. `rescue => e; ...` or just `rescue; ...`)
    std::unique_ptr<Node> exc_list;
    // Variable that captures exception
    //
    // `None` if no variable specified (i.e. `rescue E; ...` or just `rescue; ... `)
    std::unique_ptr<Node> exc_var;
    // Body of the handler
    std::unique_ptr<Node> body;
    // Location of the `rescue` keyword
    //
    // ```text
    // begin; 1; rescue E => e; 2; end
    //           ~~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `=>` operator
    //
    // ```text
    // begin; 1; rescue E => e; 2; end
    //                    ~~
    // ```
    //
    // `None` if exception is not captured.
    std::unique_ptr<Loc> assoc_l;
    // Location of the `then` keyword
    //
    // ```text
    // begin; 1; rescue E => e then; 2; end
    //                         ~~~~
    // ```
    //
    // `then` is optional, so `begin_l` can be `None`
    std::unique_ptr<Loc> begin_l;
    // Location of the full expression
    //
    // ```text
    // begin; 1; rescue E => e then; 2; end
    //           ~~~~~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    RescueBody() = delete;
    RescueBody(RescueBody &&) = default;
    RescueBody(const RescueBody &) = delete;
    explicit RescueBody(std::unique_ptr<Node> exc_list, std::unique_ptr<Node> exc_var, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> assoc_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> expression_l);
};

// Represents positional rest argument (i.e. `*foo` in `def m(*foo); end`)
class Restarg
{
public:
    // Name of the argument.
    //
    // `None` if argument has no name (i.e. `def m(*); end`)
    std::string name;
    // Location of the `*` operator
    //
    // ```text
    // def m(*foo); end
    //       ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the argument name
    //
    // ```text
    // def m(*foo); end
    //        ~~~
    // ```
    std::unique_ptr<Loc> name_l;
    // Location of the full expression
    //
    // ```text
    // def m(*foo); end
    //       ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Restarg() = delete;
    Restarg(Restarg &&) = default;
    Restarg(const Restarg &) = delete;
    explicit Restarg(std::string name, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> name_l, std::unique_ptr<Loc> expression_l);
};

// Represents `retry` keyword
class Retry
{
public:
    // Location of the `retry` keyword
    //
    // ```text
    // retry
    // ~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Retry() = delete;
    Retry(Retry &&) = default;
    Retry(const Retry &) = delete;
    explicit Retry(std::unique_ptr<Loc> expression_l);
};

// Represents `return` keyword
class Return
{
public:
    // A list of values that is returned
    std::vector<Node> args;
    // Location of the `return` keyword
    //
    // ```text
    // return 1, 2
    // ~~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the full expression
    //
    // ```text
    // return 1, 2
    // ~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Return() = delete;
    Return(Return &&) = default;
    Return(const Return &) = delete;
    explicit Return(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

// Represents opening a singleton class (i.e. `class << foo; ... end;`)
class SClass
{
public:
    // Expression that is used to get a singleton class
    //
    // `Lvar("foo")` for `class << foo; end`
    std::unique_ptr<Node> expr;
    // Body of the block
    std::unique_ptr<Node> body;
    // Location of the `class` keyword
    //
    // ```text
    // class << foo; end
    // ~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `<<` operator
    //
    // ```text
    // class << foo; end
    //       ~~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the `end` keyword
    //
    // ```text
    // class << foo; end
    //               ~~~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // class << foo; end
    // ~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    SClass() = delete;
    SClass(SClass &&) = default;
    SClass(const SClass &) = delete;
    explicit SClass(std::unique_ptr<Node> expr, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents `self` keyword
class Self_
{
public:
    // Location of the `self` keyword
    //
    // ```text
    // self
    // ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Self_() = delete;
    Self_(Self_ &&) = default;
    Self_(const Self_ &) = delete;
    explicit Self_(std::unique_ptr<Loc> expression_l);
};

// Represents a method call (e.g. `foo.bar(42)`)
class Send
{
public:
    // Receiver of the method call
    //
    // `None` for implicit method call (e.g. `foo(42)`)
    std::unique_ptr<Node> recv;
    // Name of the method that is called
    std::string method_name;
    // A list of arguments
    std::vector<Node> args;
    // Location of the `.` operator
    //
    // ```text
    // foo.bar(42)
    //    ~
    // ```
    //
    // `None` for implicit method call (e.g. `foo(42)`)
    std::unique_ptr<Loc> dot_l;
    // Location of the method name
    //
    // ```text
    // foo.bar(42)
    //     ~~~
    // ```
    //
    // `None` in a very special case when method call is implicit (i.e. `foo.(42)`)
    std::unique_ptr<Loc> selector_l;
    // Location of open parenthesis
    //
    // ```text
    // foo(42)
    //    ~
    // ```
    //
    // `None` if there are parentheses
    std::unique_ptr<Loc> begin_l;
    // Location of closing parenthesis
    //
    // ```text
    // foo(42)
    //       ~
    // ```
    //
    // `None` if there are parentheses
    std::unique_ptr<Loc> end_l;
    // Location of the operator if method is a setter
    //
    // ```text
    // foo.bar = 42
    //         ~
    // ```
    //
    // `None` otherwise
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // foo.bar(42)
    // ~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Send() = delete;
    Send(Send &&) = default;
    Send(const Send &) = delete;
    explicit Send(std::unique_ptr<Node> recv, std::string method_name, std::vector<Node> args, std::unique_ptr<Loc> dot_l, std::unique_ptr<Loc> selector_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents a special block argument that "shadows" outer variable (i.e. `|;foo|`)
class Shadowarg
{
public:
    // Name of the argument
    std::string name;
    // Location of the argument
    //
    // ```text
    // proc { |;foo|}
    //          ~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Shadowarg() = delete;
    Shadowarg(Shadowarg &&) = default;
    Shadowarg(const Shadowarg &) = delete;
    explicit Shadowarg(std::string name, std::unique_ptr<Loc> expression_l);
};

// Represents an arguments splat (i.e. `*bar` in a call like `foo(*bar)`)
class Splat
{
public:
    // Value that is converted to array
    std::unique_ptr<Node> value;
    // Location of the `*` operator
    //
    // ```text
    // foo(*bar)
    //     ~
    // ```
    std::unique_ptr<Loc> operator_l;
    // Location of the full expression
    //
    // ```text
    // foo(*bar)
    //     ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Splat() = delete;
    Splat(Splat &&) = default;
    Splat(const Splat &) = delete;
    explicit Splat(std::unique_ptr<Node> value, std::unique_ptr<Loc> operator_l, std::unique_ptr<Loc> expression_l);
};

// Represents a plain non-interpolated string literal (e.g. `"foo"`)
class Str
{
public:
    // Value of the string literal
    //
    // Note that it's a `StringValue`, not a `String`.
    // The reason is that you can get UTF-8 incompatible strings
    // from a valid UTF-8 source using escape sequences like `"\xFF"`
    //
    // These "\", "x", "F", "F" chars are valid separately, but together
    // they construct a char with code = 255 that is invalid for UTF-8.
    //
    // You can use `to_string_lossy` or `to_string` methods to get a raw string value.
    Bytes value;
    // Location of the string begin
    //
    // ```text
    // "foo"
    // ~
    // ```
    //
    // `None` if string literal is a part of the words array (like `%w[foo bar baz]`)
    std::unique_ptr<Loc> begin_l;
    // Location of the string begin
    //
    // ```text
    // "foo"
    //     ~
    // ```
    //
    // `None` if string literal is a part of the words array (like `%w[foo bar baz]`)
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // "foo"
    // ~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Str() = delete;
    Str(Str &&) = default;
    Str(const Str &) = delete;
    explicit Str(Bytes value, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a `super` keyword
class Super
{
public:
    // A list of arguments given to `super`
    std::vector<Node> args;
    // Location of the `super` keyword
    //
    // ```text
    // super(1, 2)
    // ~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // super(1, 2)
    //      ~
    // ```
    //
    // `None` if there are no parentheses
    std::unique_ptr<Loc> begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // super(1, 2)
    //           ~
    // ```
    //
    // `None` if there are no parentheses
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // super(1, 2)
    // ~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Super() = delete;
    Super(Super &&) = default;
    Super(const Super &) = delete;
    explicit Super(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a plain symbol literal (i.e. `:foo`)//// Note that `:` in `{ foo: bar }` belongs to a `pair` node.
class Sym
{
public:
    // Value of the symbol literal
    //
    // Note that it's a `StringValue`, not a `String`.
    // The reason is that you can get UTF-8 incompatible strings
    // from a valid UTF-8 source using escape sequences like `"\xFF"`
    //
    // These "\", "x", "F", "F" chars are valid separately, but together
    // they construct a char with code = 255 that is invalid for UTF-8.
    //
    // You can use `to_string_lossy` or `to_string` methods to get a raw symbol value.
    Bytes name;
    // Location of the symbol begin
    //
    // ```text
    // :foo
    // ~
    // ```
    //
    // `None` if symbol is a label (`{ foo: 1 }`) or a part of the symbols array (`%i[foo bar baz]`)
    std::unique_ptr<Loc> begin_l;
    // Location of the symbol end
    //
    // ```text
    // { 'foo': 1 }
    //        ~
    // ```
    //
    // `None` if symbol is **not** a string label (`:foo`) or a part of the symbols array (`%i[foo bar baz]`)
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // :foo
    // ~~~~
    //
    // { foo: 1 }
    //   ~~~~
    //
    // %i[foo]
    //    ~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Sym() = delete;
    Sym(Sym &&) = default;
    Sym(const Sym &) = delete;
    explicit Sym(Bytes name, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a `true` literal
class True
{
public:
    // Location of the `true` keyword
    //
    // ```text
    // true
    // ~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    True() = delete;
    True(True &&) = default;
    True(const True &) = delete;
    explicit True(std::unique_ptr<Loc> expression_l);
};

// Represents an `undef` keyword (e.g. `undef foo, :bar`)
class Undef
{
public:
    // A list of names to `undef`
    std::vector<Node> names;
    // Location the `undef` keyword
    //
    // ```text
    // undef foo, :bar
    // ~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the full expression
    //
    // ```text
    // undef :foo, bar
    // ~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Undef() = delete;
    Undef(Undef &&) = default;
    Undef(const Undef &) = delete;
    explicit Undef(std::vector<Node> names, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

// Represents an `unless` guard used in pattern matching (i.e. `in pattern unless guard`)
class UnlessGuard
{
public:
    // Condition of the guard, `Lvar("foo")` in `in pattern unless guard`
    std::unique_ptr<Node> cond;
    // Location of the `unless` keyword
    //
    // ```text
    // case foo; in pattern unless cond; end
    //                      ~~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the full expression
    //
    // ```text
    // case foo; in pattern unless cond; end
    //                      ~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    UnlessGuard() = delete;
    UnlessGuard(UnlessGuard &&) = default;
    UnlessGuard(const UnlessGuard &) = delete;
    explicit UnlessGuard(std::unique_ptr<Node> cond, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

// Represents `until` loop
class Until
{
public:
    // Condition of the loop
    std::unique_ptr<Node> cond;
    // Body of the loop.
    //
    // `None` if body is empty
    std::unique_ptr<Node> body;
    // Location of the `until` keyword
    //
    // ```text
    // until cond do; foo; end
    // ~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `do` keyword
    //
    // ```text
    // until cond do; foo; end
    //            ~~
    // ```
    //
    // `do` is optional, and so `begin_l` can be `None`
    std::unique_ptr<Loc> begin_l;
    // Location of the `end` keyword
    //
    // ```text
    // until cond do; foo; end
    //                     ~~~
    // ```
    //
    // `None` if loop is a modifier (i.e. `foo until bar`)
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // until cond do; foo; end
    // ~~~~~~~~~~~~~~~~~~~~~~~
    //
    // foo until bar
    // ~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Until() = delete;
    Until(Until &&) = default;
    Until(const Until &) = delete;
    explicit Until(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a post-until loop//// ```text// begin//   foo// end until bar// ```
class UntilPost
{
public:
    // Condition of the loop
    std::unique_ptr<Node> cond;
    // Body of the loop
    std::unique_ptr<Node> body;
    // Location of the `until` keyword
    //
    // ```text
    // begin; foo; end until bar
    //                 ~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `until` keyword
    //
    // ```text
    // begin; foo; end until bar
    // ~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    UntilPost() = delete;
    UntilPost(UntilPost &&) = default;
    UntilPost(const UntilPost &) = delete;
    explicit UntilPost(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

// Represents a branch of the `case` statement (i.e. `when foo`)
class When
{
public:
    // A list of values to compare/match against
    std::vector<Node> patterns;
    // Body of the `when` branch
    std::unique_ptr<Node> body;
    // Location of the `when` keyword
    //
    // ```text
    // case foo; when bar; end
    //           ~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `then` keyword
    //
    // ```text
    // case foo; when bar then baz; end
    //                    ~~~~
    // ```
    //
    // `then` is optional, and so `begin_l` can be `None`
    std::unique_ptr<Loc> begin_l;
    // Location of the full expression
    //
    // ```text
    // case foo; when bar then baz; end
    //           ~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    When() = delete;
    When(When &&) = default;
    When(const When &) = delete;
    explicit When(std::vector<Node> patterns, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> expression_l);
};

// Represents `while` loop
class While
{
public:
    // Condition of the loop
    std::unique_ptr<Node> cond;
    // Body of the loop.
    //
    // `None` if body is empty
    std::unique_ptr<Node> body;
    // Location of the `while` keyword
    //
    // ```text
    // while cond do; foo; end
    // ~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `do` keyword
    //
    // ```text
    // while cond do; foo; end
    //            ~~
    // ```
    //
    // `do` is optional, and so `begin_l` can be `None`
    std::unique_ptr<Loc> begin_l;
    // Location of the `end` keyword
    //
    // ```text
    // while cond do; foo; end
    //                     ~~~
    // ```
    //
    // `None` if loop is a modifier (i.e. `foo while bar`)
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // while cond do; foo; end
    // ~~~~~~~~~~~~~~~~~~~~~~~
    //
    // foo while bar
    // ~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    While() = delete;
    While(While &&) = default;
    While(const While &) = delete;
    explicit While(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a post-while loop//// ```text// begin//   foo// end while bar// ```
class WhilePost
{
public:
    // Condition of the loop
    std::unique_ptr<Node> cond;
    // Body of the loop
    std::unique_ptr<Node> body;
    // Location of the `while` keyword
    //
    // ```text
    // begin; foo; end while bar
    //                 ~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the `while` keyword
    //
    // ```text
    // begin; foo; end while bar
    // ~~~~~~~~~~~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    WhilePost() = delete;
    WhilePost(WhilePost &&) = default;
    WhilePost(const WhilePost &) = delete;
    explicit WhilePost(std::unique_ptr<Node> cond, std::unique_ptr<Node> body, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> expression_l);
};

// Represents a executable here-document literal (both with and without interpolation)//// It's similar to `Xstr` in terms of abstract syntax tree, but has different source maps.
class XHeredoc
{
public:
    // A list of string parts (static literals and interpolated expressions)
    std::vector<Node> parts;
    // Location of the executable here-document body
    //
    // ```text
    // <<-`HERE`\n  a\n   #{42}\nHERE
    //          ~~~~~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> heredoc_body_l;
    // Location of the executable here-document end
    //
    // ```text
    // <<-`HERE`\n  a\n   #{42}\nHERE
    //                         ~~~~
    // ```
    std::unique_ptr<Loc> heredoc_end_l;
    // Location of the executable here-document identifier
    //
    // ```text
    // <<-`HERE`\n  a\n   #{42}\nHERE
    // ~~~~~~~
    // ```
    //
    // **Note**: This is the only node (with `Heredoc`) that has `expression_l` smaller that all other sub-locations merged.
    // The reason for that is that it's possible to add more code after here-document ID:
    //
    // ```text
    // <<-`HERE` + "rest"
    //   content
    // HERE
    // ```
    std::unique_ptr<Loc> expression_l;

    XHeredoc() = delete;
    XHeredoc(XHeredoc &&) = default;
    XHeredoc(const XHeredoc &) = delete;
    explicit XHeredoc(std::vector<Node> parts, std::unique_ptr<Loc> heredoc_body_l, std::unique_ptr<Loc> heredoc_end_l, std::unique_ptr<Loc> expression_l);
};

// Represents an executable string (i.e. `` `sh #{script_name}` ``)
class Xstr
{
public:
    // A list of string parts (static literals and interpolated expressions)
    std::vector<Node> parts;
    // Location of the string begin
    //
    // ```text
    // `#{foo}`
    // ~
    //
    // %X{#{foo}}
    // ~~~
    // ```
    std::unique_ptr<Loc> begin_l;
    // Location of the string end
    //
    // ```text
    // `#{foo}`
    //        ~
    //
    // %X{#{foo}}
    //          ~
    // ```
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // `#{foo}`
    // ~~~~~~~~
    //
    // %X{#{foo}}
    // ~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Xstr() = delete;
    Xstr(Xstr &&) = default;
    Xstr(const Xstr &) = delete;
    explicit Xstr(std::vector<Node> parts, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents an `yield` keyword
class Yield
{
public:
    // A list of arguments given to `yield`
    std::vector<Node> args;
    // Location of the `yield` keyword
    //
    // ```text
    // yield 1, 2
    // ~~~~~
    // ```
    std::unique_ptr<Loc> keyword_l;
    // Location of the open parenthesis
    //
    // ```text
    // yield(1, 2)
    //      ~
    // ```
    //
    // `None` if there are no parentheses
    std::unique_ptr<Loc> begin_l;
    // Location of the closing parenthesis
    //
    // ```text
    // yield(1, 2)
    //           ~
    // ```
    //
    // `None` if there are no parentheses
    std::unique_ptr<Loc> end_l;
    // Location of the full expression
    //
    // ```text
    // yield(1, 2)
    // ~~~~~~~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    Yield() = delete;
    Yield(Yield &&) = default;
    Yield(const Yield &) = delete;
    explicit Yield(std::vector<Node> args, std::unique_ptr<Loc> keyword_l, std::unique_ptr<Loc> begin_l, std::unique_ptr<Loc> end_l, std::unique_ptr<Loc> expression_l);
};

// Represents a `super` call without arguments and parentheses//// It's different from `super()` as it implicitly forwards current arguments
class ZSuper
{
public:
    // Location of the `super` keyword
    //
    // ```text
    // super
    // ~~~~~
    // ```
    std::unique_ptr<Loc> expression_l;

    ZSuper() = delete;
    ZSuper(ZSuper &&) = default;
    ZSuper(const ZSuper &) = delete;
    explicit ZSuper(std::unique_ptr<Loc> expression_l);
};

}

#include "../../node.h"

#endif // LIB_RUBY_PARSER_GEN_NODES_CLASSES_H
