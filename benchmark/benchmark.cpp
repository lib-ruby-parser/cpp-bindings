#include <cstdlib>
#include <iostream>
#include <chrono>

#include "rb_filelist.hpp"
#include "../lib-ruby-parser.hpp"

int main()
{
    char *filelist_path = std::getenv("FILELIST_PATH");
    if (filelist_path == nullptr)
    {
        std::cerr << "\nNo FILELIST_PATH provided.\n\nUsage: FILELIST_PATH=path/to/filelist ./path/to/exe\n";
        return 1;
    }

    FileList filelist(filelist_path);

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    for (size_t i = 0; i < filelist.files.size(); i++)
    {
        FileToParse file = std::move(filelist.files[i]);

        lib_ruby_parser::ParserOptions options(
            std::move(file.filepath),
            lib_ruby_parser::MaybeDecoder::None(),
            lib_ruby_parser::MaybeTokenRewriter::None(),
            false);
        lib_ruby_parser::ByteList input = std::move(file.content);

        lib_ruby_parser::parse(
            std::move(options),
            std::move(input));
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / 1000000000 << "[s]" << std::endl;

    return 0;
}
