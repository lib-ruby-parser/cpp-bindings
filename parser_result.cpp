#include "parser_result.hpp"
#include "utils.hpp"

namespace lib_ruby_parser
{
    ParserResult::~ParserResult()
    {
        if (this->ast)
        {
            delete this->ast;
        }
    }
}
