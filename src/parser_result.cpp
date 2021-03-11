#include "parser_result.h"

namespace lib_ruby_parser
{
    extern "C"
    {
        ParserResult *parse(BytePtr input, const ParserOptions *options);
    }

    ParserResult::ParserResult(
        std::unique_ptr<Node> ast,
        std::vector<Token> tokens,
        std::vector<Diagnostic> diagnostics,
        std::vector<Comment> comments,
        std::vector<MagicComment> magic_comments,
        Input input) : ast(std::move(ast)),
                       tokens(std::move(tokens)),
                       diagnostics(std::move(diagnostics)),
                       comments(std::move(comments)),
                       magic_comments(std::move(magic_comments)),
                       input(std::move(input)) {}

    std::unique_ptr<ParserResult> ParserResult::from_source(Bytes source, const ParserOptions &options)
    {
        return std::unique_ptr<ParserResult>(parse(source.into_ptr(), &options));
    }
} // namespace lib_ruby_parser
