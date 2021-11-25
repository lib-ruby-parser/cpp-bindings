#include <fstream>
#include <vector>
#include <string>
#include <streambuf>
#include "../lib-ruby-parser.hpp"

class FileToParse
{
public:
    lib_ruby_parser::String filepath = lib_ruby_parser::String(nullptr, 0, 0);
    lib_ruby_parser::ByteList content = lib_ruby_parser::ByteList(nullptr, 0, 0);

    FileToParse(std::string filepath_)
    {
        filepath = lib_ruby_parser::String::Copied(
            filepath_.c_str());

        std::ifstream f(filepath_);
        std::string content_s = std::string((std::istreambuf_iterator<char>(f)),
                                            std::istreambuf_iterator<char>());
        content = lib_ruby_parser::ByteList::Copied(
            content_s.c_str(),
            content_s.length());
    }
};

class FileList
{
public:
    std::vector<FileToParse> files;

    FileList(char *filelist_path)
    {
        std::ifstream f(filelist_path);
        std::string line;
        while (std::getline(f, line))
        {
            files.push_back(FileToParse(line));
        }
    }
};
