#include "parser_result.h"

namespace lib_ruby_parser
{
    extern "C"
    {
        ParserResult *parse(const char *code, size_t len, ParserOptions *options);
    }

    ParserResult::ParserResult(
        std::unique_ptr<Node> ast,
        std::vector<Token> tokens,
        std::vector<Diagnostic> diagnostics,
        std::vector<Comment> comments,
        std::vector<MagicComment> magic_comments,
        std::string input)
    {
        this->ast = std::move(ast);
        this->tokens = std::move(tokens);
        this->diagnostics = std::move(diagnostics);
        this->comments = std::move(comments);
        this->magic_comments = std::move(magic_comments);
        this->input = input;
    }

    std::unique_ptr<ParserResult> ParserResult::from_source(Bytes source, ParserOptions options)
    {
        return std::unique_ptr<ParserResult>(parse(source.ptr(), source.size(), &options));
    }
} // namespace lib_ruby_parser
