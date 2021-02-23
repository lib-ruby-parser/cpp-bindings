#include <iostream>
#include <variant>
#include <string>
#include <fstream>
#include <streambuf>
#include <assert.h>
#include "target/lib-ruby-parser.h"

using namespace lib_ruby_parser;

void test_loc()
{
    Loc loc(10, 100);
    assert(loc.begin == 10);
    assert(loc.end == 100);
    assert(loc.size() == 90);
    assert(loc == Loc(10, 100));
    assert(loc != Loc(20, 100));
    assert(loc != Loc(10, 200));
}

void test_node()
{
    Node node(
        std::make_unique<Int>(
            std::string("42"),
            std::unique_ptr<Loc>(nullptr),
            std::make_unique<Loc>(3, 4)));

    assert(node.is<Int>());
    assert(!node.is<Float>());

    assert(node.get<Int>()->operator_l == nullptr);
    assert(*(node.get<Int>()->expression_l) == Loc(3, 4));
    assert(node.get<Int>()->value == std::string("42"));
}

void test_parse()
{
    auto result = ParserResult::from_source(Bytes("42"), ParserOptions());

    assert(result->ast != nullptr);
    auto ast = std::move(result->ast);

    assert(ast->is<Int>());
    auto int_node = ast->get<Int>();

    assert(int_node->value == "42");
    assert(*(int_node->expression_l) == Loc(0, 2));
    assert(int_node->operator_l == nullptr);
}

#define assert_token(token, exp_name, exp_value, exp_begin, exp_end) \
    assert((token).name() == std::string(exp_name));                 \
    assert((token).token_value == std::string(exp_value));           \
    assert((token).loc->begin == exp_begin);                         \
    assert((token).loc->end == exp_end);

void test_tokens()
{
    ParserOptions options;
    options.buffer_name = "(test_tokens)";
    options.record_tokens = true;

    auto result = ParserResult::from_source(Bytes("42"), std::move(options));

    assert(result->tokens.size() == 2);

    assert_token(result->tokens[0], "tINTEGER", "42", 0, 2);
    assert_token(result->tokens[1], "EOF", "", 2, 2);
}

void test_diagnostics()
{
    auto result = ParserResult::from_source(Bytes("self = 1; nil = 2"), ParserOptions());

    assert(result->diagnostics.size() == 2);

    assert(result->diagnostics[0] == Diagnostic(
                                         ErrorLevel::ERROR,
                                         std::string("Can't change the value of self"),
                                         std::make_unique<Loc>(0, 4)));

    assert(result->diagnostics[1] == Diagnostic(
                                         ErrorLevel::ERROR,
                                         std::string("Can't assign to nil"),
                                         std::make_unique<Loc>(10, 13)));
}

void test_comments()
{
    auto result = ParserResult::from_source(Bytes("# foo\n# bar\nbaz"), ParserOptions());

    assert(result->comments.size() == 2);

    assert(result->comments[0] == Comment(
                                      CommentType::INLINE,
                                      std::make_unique<Loc>(0, 6)));
    assert(result->comments[1] == Comment(
                                      CommentType::INLINE,
                                      std::make_unique<Loc>(6, 12)));
}

void test_magic_comments()
{
    auto result = ParserResult::from_source(
        Bytes("# warn-indent: true\n# frozen-string-literal: true\n# encoding: utf-8\n"),
        ParserOptions());

    assert(result->magic_comments.size() == 3);

    assert(result->magic_comments[0] == MagicComment(
                                            MagicCommentKind::WARN_INDENT,
                                            std::make_unique<Loc>(2, 13),
                                            std::make_unique<Loc>(15, 19)));
    assert(result->magic_comments[1] == MagicComment(
                                            MagicCommentKind::FROZEN_STRING_LITERAL,
                                            std::make_unique<Loc>(22, 43),
                                            std::make_unique<Loc>(45, 49)));
    assert(result->magic_comments[2] == MagicComment(
                                            MagicCommentKind::ENCODING,
                                            std::make_unique<Loc>(52, 60),
                                            std::make_unique<Loc>(62, 67)));
}

void test_loc_source()
{
    auto result = ParserResult::from_source(Bytes("100 + 200"), ParserOptions());
    auto send = result->ast->get<Send>();
    auto recv = send->recv->get<Int>();
    auto arg = send->args[0].get<Int>();

    assert(recv->expression_l->source(result->input) == std::string("100"));
    assert(arg->expression_l->source(result->input) == std::string("200"));
}

void test_parse_all()
{
    std::ifstream file("all_nodes.rb");
    std::string source((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());

    auto result = ParserResult::from_source(Bytes(source), ParserOptions());
    assert(result->ast != nullptr);
}

class DummyDecoderState
{
public:
    std::string encoding;
    Bytes input;
};

class DummyDecoder : public CustomDecoder
{
public:
    bool return_error;
    Bytes output_to_return;
    std::string error_to_return;

    std::shared_ptr<DummyDecoderState> state;

    DummyDecoder()
    {
        this->return_error = false;
        this->output_to_return = Bytes("");
        this->error_to_return = "";
        this->state = std::make_shared<DummyDecoderState>();
    }
    virtual ~DummyDecoder() = default;

    static std::unique_ptr<DummyDecoder> AlwaysFailWith(std::string error_to_return)
    {
        auto result = std::make_unique<DummyDecoder>();
        result->return_error = true;
        result->error_to_return = error_to_return;
        return result;
    }

    static std::unique_ptr<DummyDecoder> AlwaysRewriteTo(Bytes output_to_return)
    {
        auto result = std::make_unique<DummyDecoder>();
        result->return_error = false;
        result->output_to_return = std::move(output_to_return);
        return result;
    }

    virtual CustomDecoder::Result rewrite(std::string encoding, Bytes input)
    {
        this->state->encoding = encoding;
        this->state->input = input.clone();

        if (return_error)
        {
            return Result::Error(error_to_return);
        }
        else
        {
            return Result::Ok(std::move(output_to_return));
        }
    }
};

void test_custom_decoder_ok()
{
    ParserOptions options;
    auto decoder = DummyDecoder::AlwaysRewriteTo(Bytes("# encoding: foo\n3 + 5"));
    auto state = decoder->state;

    options.custom_decoder = std::move(decoder);
    options.record_tokens = true;
    auto input = Bytes("# encoding: bar\n2 + 2");
    auto result = ParserResult::from_source(input.clone(), std::move(options));

    auto ast = std::move(result->ast);
    assert(ast->is<Send>());
    assert(ast->get<Send>()->recv->is<Int>());
    assert(ast->get<Send>()->recv->get<Int>()->value == "3");
    assert(ast->get<Send>()->args.size() == 1);
    assert(ast->get<Send>()->args[0].is<Int>());
    assert(ast->get<Send>()->args[0].get<Int>()->value == "5");

    assert(state->input.to_string() == input.to_string());
    assert(state->encoding == "BAR");
}

void test_custom_decoder_error()
{
    ParserOptions options;
    auto decoder = DummyDecoder::AlwaysFailWith("test error");
    auto state = decoder->state;

    options.custom_decoder = std::move(decoder);
    auto input = Bytes("# encoding: bar\n2 + 3");
    auto result = ParserResult::from_source(input.clone(), std::move(options));

    assert(result->ast == nullptr);
    assert(result->diagnostics.size() == 1);

    assert(result->diagnostics[0] == Diagnostic(
                                         ErrorLevel::ERROR,
                                         std::string("encoding error: DecodingError(\"test error\")"),
                                         std::make_unique<Loc>(12, 15)));

    assert(state->input.to_string() == input.to_string());
    assert(state->encoding == "BAR");
}

class CustomTokenRewriter : public TokenRewriter
{
public:
    virtual Result rewrite_token(Token token, Bytes input)
    {
        (void)input; // suppress the warning

        if (token.token_value == "2")
        {
            token.token_value = Bytes("3");
        }

        return Result(std::move(token), RewriteAction::KEEP, LexStateAction::Keep());
    }
    virtual ~CustomTokenRewriter() {}
};

void test_custom_rewriter()
{
    ParserOptions options;
    options.token_rewriter = std::make_unique<CustomTokenRewriter>();
    options.record_tokens = true;

    auto result = ParserResult::from_source(Bytes("2"), std::move(options));

    assert(result->tokens.size() == 2);

    assert_token(result->tokens[0], "tINTEGER", "3", 0, 1);
    assert_token(result->tokens[1], "EOF", "", 1, 1);
}

int main()
{
#define test(name)                         \
    std::cout << "Running test_" << #name; \
    test_##name();                         \
    std::cout << "... OK\n";

    test(loc);
    test(node);
    test(parse);
    test(tokens);
    test(diagnostics);
    test(comments);
    test(magic_comments);
    test(loc_source);

    test(parse_all);

    test(custom_decoder_ok);
    test(custom_decoder_error);

    test(custom_rewriter);

    std::cout << "all tests passed.\n";
}
