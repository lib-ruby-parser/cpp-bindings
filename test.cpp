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
    auto result = ParserResult::from_source(std::string("42"));

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
    auto result = ParserResult::from_source(std::string("42"));

    assert(result->tokens.size() == 2);

    assert_token(result->tokens[0], "tINTEGER", "42", 0, 2);
    assert_token(result->tokens[1], "EOF", "", 2, 2);
}

void test_diagnostics()
{
    auto result = ParserResult::from_source(std::string("self = 1; nil = 2"));

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
    auto result = ParserResult::from_source(std::string("# foo\n# bar\nbaz"));

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
    auto result = ParserResult::from_source(std::string("# warn-indent: true\n# frozen-string-literal: true\n# encoding: utf-8\n"));

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
    auto result = ParserResult::from_source(std::string("100 + 200"));
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

    auto result = ParserResult::from_source(source);
    assert(result->ast != nullptr);
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

    std::cout << "all tests passed.\n";
}
