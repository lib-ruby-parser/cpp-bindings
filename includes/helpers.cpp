#include <vector>
#include <string>
#include "helpers.h"

namespace lib_ruby_parser
{
    std::string char_ptr_to_string(char *ptr)
    {
        std::string result(ptr);
        free(ptr);
        return result;
    }

    std::vector<Node> nodes_vec_to_cpp_vec(NodeVec nodes)
    {
        return ptr_to_vec<Node>(nodes.list, nodes.length);
    }
} // namespace lib_ruby_parser
