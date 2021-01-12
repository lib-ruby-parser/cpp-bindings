#include <iostream>
#include <variant>
#include <string>
#include <fstream>
#include <streambuf>
#include <assert.h>
#include "includes/lib-ruby-parser.h"

using namespace lib_ruby_parser;

void test_range()
{
    Range range(10, 100);
    assert(range.begin_pos == 10);
    assert(range.end_pos == 100);
    assert(range.size() == 90);
    assert(range == Range(10, 100));
    assert(range != Range(20, 100));
    assert(range != Range(10, 200));
}

void test_node()
{
    Node node(
        std::make_unique<Int>(
            std::string("42"),
            std::unique_ptr<Range>(nullptr),
            std::make_unique<Range>(3, 4)));

    assert(node.is<Int>());
    assert(!node.is<Float>());

    assert(node.get<Int>()->operator_l == nullptr);
    assert(*(node.get<Int>()->expression_l) == Range(3, 4));
    assert(node.get<Int>()->value == std::string("42"));
}

void test_parse()
{
    auto result = ParserResult::from_source(std::string("42"), ParserOptions());

    assert(result->ast != nullptr);
    auto ast = std::move(result->ast);

    assert(ast->is<Int>());
    auto int_node = ast->get<Int>();

    assert(int_node->value == "42");
    assert(*(int_node->expression_l) == Range(0, 2));
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

    auto result = ParserResult::from_source(std::string("42"), std::move(options));

    assert(result->tokens.size() == 2);

    assert_token(result->tokens[0], "tINTEGER", "42", 0, 2);
    assert_token(result->tokens[1], "EOF", "", 2, 2);
}

void test_diagnostics()
{
    auto result = ParserResult::from_source(std::string("self = 1; nil = 2"), ParserOptions());

    assert(result->diagnostics.size() == 2);

    assert(result->diagnostics[0] == Diagnostic(
                                         ErrorLevel::ERROR,
                                         std::string("Can't change the value of self"),
                                         std::make_unique<Range>(0, 4)));

    assert(result->diagnostics[1] == Diagnostic(
                                         ErrorLevel::ERROR,
                                         std::string("Can't assign to nil"),
                                         std::make_unique<Range>(10, 13)));
}

void test_comments()
{
    auto result = ParserResult::from_source(std::string("# foo\n# bar\nbaz"), ParserOptions());

    assert(result->comments.size() == 2);

    assert(result->comments[0] == Comment(
                                      CommentType::INLINE,
                                      std::make_unique<Range>(0, 6)));
    assert(result->comments[1] == Comment(
                                      CommentType::INLINE,
                                      std::make_unique<Range>(6, 12)));
}

void test_magic_comments()
{
    auto result = ParserResult::from_source(
        std::string("# warn-indent: true\n# frozen-string-literal: true\n# encoding: utf-8\n"),
        ParserOptions());

    assert(result->magic_comments.size() == 3);

    assert(result->magic_comments[0] == MagicComment(
                                            MagicCommentKind::WARN_INDENT,
                                            std::make_unique<Range>(2, 13),
                                            std::make_unique<Range>(15, 19)));
    assert(result->magic_comments[1] == MagicComment(
                                            MagicCommentKind::FROZEN_STRING_LITERAL,
                                            std::make_unique<Range>(22, 43),
                                            std::make_unique<Range>(45, 49)));
    assert(result->magic_comments[2] == MagicComment(
                                            MagicCommentKind::ENCODING,
                                            std::make_unique<Range>(52, 60),
                                            std::make_unique<Range>(62, 67)));
}

void test_range_source()
{
    auto result = ParserResult::from_source(std::string("100 + 200"), ParserOptions());
    auto send = result->ast->get<Send>();
    auto recv = send->recv->get<Int>();
    auto arg = send->args[0].get<Int>();
    auto input = result->input;

    assert(recv->expression_l->source(result->input) == std::string("100"));
    assert(arg->expression_l->source(result->input) == std::string("200"));
}

void test_parse_all()
{
    std::ifstream file("all_nodes.rb");
    std::string source((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());

    auto result = ParserResult::from_source(source, ParserOptions());
    assert(result->ast != nullptr);
}

class DummyDecoderState
{
public:
    std::string encoding;
    std::string input;
};

class DummyDecoder : public CustomDecoder
{
public:
    bool return_error;
    std::string output_to_return;
    std::string error_to_return;

    std::shared_ptr<DummyDecoderState> state;

    DummyDecoder()
    {
        this->return_error = false;
        this->output_to_return = "";
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

    static std::unique_ptr<DummyDecoder> AlwaysRewriteTo(std::string output_to_return)
    {
        auto result = std::make_unique<DummyDecoder>();
        result->return_error = false;
        result->output_to_return = output_to_return;
        return result;
    }

    virtual CustomDecoder::Result rewrite(std::string encoding, std::string input)
    {
        this->state->encoding = encoding;
        this->state->input = input;

        if (return_error)
        {
            return Result::Error(error_to_return);
        }
        else
        {
            return Result::Ok(output_to_return);
        }
    }
};

void test_custom_decoder_ok()
{
    ParserOptions options;
    auto decoder = DummyDecoder::AlwaysRewriteTo("# encoding: foo\n3 + 5");
    auto state = decoder->state;

    options.custom_decoder = std::move(decoder);
    options.record_tokens = true;
    std::string input = "# encoding: bar\n2 + 2";
    auto result = ParserResult::from_source(input, std::move(options));

    auto ast = std::move(result->ast);
    assert(ast->is<Send>());
    assert(ast->get<Send>()->recv->is<Int>());
    assert(ast->get<Send>()->recv->get<Int>()->value == "3");
    assert(ast->get<Send>()->args.size() == 1);
    assert(ast->get<Send>()->args[0].is<Int>());
    assert(ast->get<Send>()->args[0].get<Int>()->value == "5");

    assert(state->input == input);
    assert(state->encoding == "BAR");
}

void test_custom_decoder_error()
{
    ParserOptions options;
    auto decoder = DummyDecoder::AlwaysFailWith("test error");
    auto state = decoder->state;

    options.custom_decoder = std::move(decoder);
    std::string input = "# encoding: bar\n2 + 3";
    auto result = ParserResult::from_source(input, std::move(options));

    assert(result->ast == nullptr);
    assert(result->diagnostics.size() == 1);

    assert(result->diagnostics[0] == Diagnostic(
                                         ErrorLevel::ERROR,
                                         std::string("encoding error: DecodingError(\"test error\")"),
                                         std::make_unique<Range>(12, 15)));

    assert(state->input == input);
    assert(state->encoding == "BAR");
}

int main()
{
    test_range();
    test_node();
    test_parse();
    test_tokens();
    test_diagnostics();
    test_comments();
    test_magic_comments();
    test_range_source();

    test_parse_all();

    test_custom_decoder_ok();
    test_custom_decoder_error();

    std::cout << "all tests passed.\n";
}
