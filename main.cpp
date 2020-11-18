#include <string>
#include <iostream>
#include <vector>
#include "includes/lib-ruby-parser.h"

int main()
{
    auto result = lib_ruby_parser::ParserResult::from_source(std::string("2 + 2"));
}
