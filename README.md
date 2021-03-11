# C++ bindings for `lib-ruby-parser`

tldr; You can find examples in `test/test.cpp`. Valgrind and ASAN give no errors.

## API

All classes/methods are defined in the `lib_ruby_parser` namespace.

1. `ParserResult::from_source(Bytes source, ParserOptions options)`

    Parses given input into `ParserResult`, has the following fields:
    ```cpp
    // AST
    std::unique_ptr<Node> ast;

    // List of tokns
    std::vector<Token> tokens;

    // List of diagnostic messages
    std::vector<Diagnostic> diagnostics;

    // List of comments
    std::vector<Comment> comments;

    // List of magic comments
    std::vector<MagicComment> magic_comments;

    // Decoded input
    Input input;
    ```

2. `Node::is<T>` where `T` is one of the ~100 node types.

    ```cpp
    ast.is<Args>()
    // => true

    ast.is<Defs>()
    // => false
    ```

3. `Node::get<T>` where `T` is one of the ~100 node locs

    ```cpp
    Args *args = ast.get<Args>()
    ```

4. All node classes fully match node structs of the original Rust implementation. You can check [full documentation](https://docs.rs/lib-ruby-parser) (`nodes` module)

5. `Token` has the following fields and methods:

    ```cpp
    std::string token_value;
    std::unique_ptr<Loc> loc; // has numeric "begin" and "end" fields
    std::string name();
    ```

    Also it has a numeric `token_type` field that probably could be used for fast comparison. It is used to get `name()`, so it's different for different token types.

6. `Diagnostic` has the following fields:

    ```cpp
    ErrorLevel level; // enum with WARNING and ERROR values
    std::unique_ptr<DiagnosticMessage> message;
    std::unique_ptr<Loc> loc;
    ```

    can be rendered either using `render_message()` or `render(const Bytes &)`

7. `Comment` has the following fields:

    ```cpp
    CommentType kind; // enum with INLINE, DOCUMENT and UNKNOWN values
    std::unique_ptr<Loc> location;
    ```

8. `Loc` has the following fields and methods:

    ```cpp
    uint32_t begin;
    uint32_t end;
    std::string source(Input &input);
    ```

    `input` is what you get from `ParserResult::from`. It can be different from your original source if it has magic encoding comment.

9. `MagicComment` has the following fields:

    ```cpp
    MagicCommentKind kind; // enum with ENCODING, FROZEN_STRING_LITERAL, WARN_INDENT values

    // location of key/value
    // "# encoding: utf-8"
    //    ~~~~~~~~ key
    //              ~~~~~ value
    std::unique_ptr<Loc> key_l;
    std::unique_ptr<Loc> value_l;
    ```
