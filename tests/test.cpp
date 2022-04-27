#include <iostream>
#include "../test_helper.hpp"

#include "../bytes.hpp"
#include "../comment.hpp"
#include "../decoded_input.hpp"
#include "../decoder.hpp"
#include "../diagnostic.hpp"
#include "../loc.hpp"
#include "../magic_comment.hpp"
#include "../messages.hpp"
#include "../nodes.hpp"
#include "../parser_options.hpp"
#include "../parser_result.hpp"
#include "../shared_byte_list.hpp"
#include "../source_line.hpp"
#include "../string.hpp"
#include "../token_rewriter.hpp"
#include "../token.hpp"
#include "../api.hpp"

extern "C"
{
    void lib_ruby_parser__test__print_build_info(void);
}

int main()
{
    lib_ruby_parser__test__print_build_info();
    std::cerr << "C++ build info:\n";
    std::cerr << "sizeof(size_t): " << sizeof(size_t) << "\n";
    std::cerr << "sizeof(void*): " << sizeof(void *) << "\n";
    std::cerr << "\n";

    lib_ruby_parser::run_test_group_bytes();
    lib_ruby_parser::run_test_group_comment();
    lib_ruby_parser::run_test_group_decoded_input();
    lib_ruby_parser::run_test_group_decoder();
    lib_ruby_parser::run_test_group_diagnostic();
    lib_ruby_parser::run_test_group_loc();
    lib_ruby_parser::run_test_group_magic_comment();
    lib_ruby_parser::run_test_group_message();
    lib_ruby_parser::run_test_group_node();
    lib_ruby_parser::run_test_group_parser_options();
    lib_ruby_parser::run_test_group_parser_result();
    lib_ruby_parser::run_test_group_shared_byte_list();
    lib_ruby_parser::run_test_group_source_line();
    lib_ruby_parser::run_test_group_string();
    lib_ruby_parser::run_test_group_token_rewriter();
    lib_ruby_parser::run_test_group_token();
    lib_ruby_parser::run_test_group_api();

    std::cerr << "All tests are passing!\n";

    return 0;
}
