#include <iostream>
#include "includes/lib-ruby-parser.h"

int main()
{
    auto result = ParserResult::from("42", 2);

    auto ast = std::move(result->ast);
    auto int_node = std::move(std::get<Int>(ast->inner));

    std::cout << int_node.value << "\n";
    std::cout << int_node.expression_l->begin_pos << "\n";
    std::cout << int_node.expression_l->end_pos << "\n";

    return 0;
}
