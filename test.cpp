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
    test_parse_all();

    std::cout << "all tests passed.\n";
}
