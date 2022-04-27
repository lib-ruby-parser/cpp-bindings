# C++ bindings for `lib-ruby-parser`

[Documentation](https://lib-ruby-parser.github.io/cpp-bindings/)

All classes/methods are defined under `lib_ruby_parser` namespace. API mostly mirrors Rust version.

Pre-compiled libraries and header files are available on [Releases](https://github.com/lib-ruby-parser/cpp-bindings/releases), supported platforms:

+ `x86_64-apple-darwin`
+ `x86_64-unknown-linux-gnu`
+ `x86_64-pc-windows-msvc`

## Basic API

```cpp
// Configure parsing options
lib_ruby_parser::ParserOptions options(
    /* 1. filename */
    lib_ruby_parser::String::Copied("(eval)"),

    /* 2. decoder */
    lib_ruby_parser::MaybeDecoder(lib_ruby_parser::Decoder(nullptr)),

    /* 3. token_rewriter */
    lib_ruby_parser::MaybeTokenRewriter(lib_ruby_parser::TokenRewriter(nullptr)),

    /* 4. record_tokens */
    true);

// Setup input to parse
lib_ruby_parser::ByteList input = lib_ruby_parser::ByteList::Copied("2 + 3", 5);

lib_ruby_parser::ParserResult result = lib_ruby_parser::parse(
    std::move(input),
    std::move(options));

assert_eq(result.ast->tag, lib_ruby_parser::Node::Tag::SEND);
assert_eq(result.tokens.len, 4); // tINT tPLUS tINT EOF
assert_eq(result.comments.len, 0);
assert_eq(result.magic_comments.len, 0);
assert_byte_list(result.input.bytes, "2 + 3");
```

`ParserResult` contains the following fields:

1. `Node* ast` - potentually nullable AST, tagged enum
2. `TokenList tokens` - list of tokens
3. `DiagnosticList diagnostics` - list of diagnostics
4. `CommentList comments` - list of comments
5. `MagicCommentList magic_comments` - list of magic comments
6. `DecodedInput input` - decoded input

All node classes fully match node structs of the original Rust implementation. You can check [full documentation](https://docs.rs/lib-ruby-parser) (`nodes` module)

