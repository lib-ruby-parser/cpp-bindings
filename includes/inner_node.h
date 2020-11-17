#ifndef LIB_RUBY_PARSER_NODE_H
#define LIB_RUBY_PARSER_NODE_H

#include <cstddef>
#include <memory>
#include "range.h"

class InnerNode
{
public:
    std::unique_ptr<Range> expression_l;
};

#endif // LIB_RUBY_PARSER_NODE_H
