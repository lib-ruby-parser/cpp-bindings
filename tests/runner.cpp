#include <iostream>
#include "test_helper.hpp"
#include "test_helper.cpp"

#include "bytes_test.cpp"
#include "comment_test.cpp"
#include "decoded_input_test.cpp"
#include "decoder_test.cpp"
#include "diagnostic_test.cpp"
#include "loc_test.cpp"
#include "magic_comment_test.cpp"
#include "messages_test.cpp"
#include "nodes_test.cpp"
#include "parser_options_test.cpp"
#include "parser_result_test.cpp"
#include "shared_byte_list_test.cpp"
#include "source_line_test.cpp"
#include "string_test.cpp"
#include "token_rewriter_test.cpp"
#include "token_test.cpp"
#include "api_test.cpp"

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
