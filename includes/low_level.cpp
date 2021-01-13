#include <cstring>
#include "low_level.h"
#include "comment.h"
#include "range.h"
#include "bytes.h"
#include "custom_decoder.h"
#include "helpers.h"
#include "token.h"
#include "diagnostic.h"
#include "magic_comment.h"
#include "parser_options.h"
#include "parser_result.h"

namespace lib_ruby_parser
{
    namespace low_level
    {
        namespace make
        {
            std::vector<Token> tokens_vec_to_cpp_vec(TokenVec tokens)
            {
                return ptr_to_vec<Token>(tokens.list, tokens.length);
            }

            std::vector<Diagnostic> diagnostics_vec_to_cpp_vec(DiagnosticVec diagnostics)
            {
                return ptr_to_vec<Diagnostic>(diagnostics.list, diagnostics.length);
            }

            std::vector<Comment> comments_vec_to_cpp_vec(CommentVec comments)
            {
                return ptr_to_vec<Comment>(comments.list, comments.length);
            }

            std::vector<MagicComment> magic_comments_vec_to_cpp_vec(MagicCommentVec magic_comments)
            {
                return ptr_to_vec<MagicComment>(magic_comments.list, magic_comments.length);
            }

            extern "C"
            {
                ParserResult *make_parser_result(
                    Node *ast,
                    TokenVec tokens,
                    DiagnosticVec diagnostics,
                    CommentVec comments,
                    MagicCommentVec magic_comments,
                    char *input)
                {
                    return new ParserResult(
                        std::unique_ptr<Node>(ast),
                        tokens_vec_to_cpp_vec(tokens),
                        diagnostics_vec_to_cpp_vec(diagnostics),
                        comments_vec_to_cpp_vec(comments),
                        magic_comments_vec_to_cpp_vec(magic_comments),
                        char_ptr_to_string(input));
                }

                Comment *make_comment(CommentType kind, Range *location)
                {
                    return new Comment(kind, std::unique_ptr<Range>(location));
                }

                Diagnostic *make_diagnostic(ErrorLevel level, char *message, Range *range)
                {
                    return new Diagnostic(level, char_ptr_to_string(message), std::unique_ptr<Range>(range));
                }

                MagicComment *make_magic_comment(MagicCommentKind kind, Range *key_l, Range *value_l)
                {
                    return new MagicComment(kind, std::unique_ptr<Range>(key_l), std::unique_ptr<Range>(value_l));
                }

                Range *make_range(size_t begin_pos, size_t end_pos)
                {
                    return new Range(begin_pos, end_pos);
                }

                Loc *make_loc(size_t begin, size_t end)
                {
                    return new Loc(begin, end);
                }

                Token *make_token(int token_type, char *token_value, Loc *loc)
                {
                    return new Token(
                        token_type,
                        char_ptr_to_string(token_value),
                        std::unique_ptr<Loc>(loc));
                }
            }
        } // namespace make

        namespace custom_decoder
        {
            extern "C"
            {
                CustomDecoderResult rewrite(CustomDecoder *decoder, const char *encoding_ptr, size_t encoding_length, const char *input_ptr, size_t input_length)
                {
                    auto encoding = std::string((char *)encoding_ptr, encoding_length);
                    auto input = Bytes(input_ptr, input_length);

                    auto cpp_result = decoder->rewrite(std::move(encoding), std::move(input));

                    if (cpp_result.success)
                    {
                        auto length = cpp_result.output.size();
                        auto output = (char *)malloc(length);
                        memcpy(output, cpp_result.output.ptr(), length);
                        return CustomDecoderResult::Ok(output, length);
                    }
                    else
                    {
                        auto error_message = string_to_char_ptr(cpp_result.error_message);
                        auto length = cpp_result.error_message.length();
                        return CustomDecoderResult::Error(error_message, length);
                    }
                }

                CustomDecoderResult CustomDecoderResult::Ok(char *output, size_t length)
                {
                    CustomDecoderResult result;
                    result.output = output;
                    result.output_length = length;
                    result.success = true;
                    return result;
                }

                CustomDecoderResult CustomDecoderResult::Error(char *error_message, size_t length)
                {
                    CustomDecoderResult result;
                    result.error_message = error_message;
                    result.error_message_length = length;
                    result.success = false;
                    return result;
                }
            }
        } // namespace custom_decoder

        namespace parser_options
        {
            extern "C"
            {
                const char *parser_options_buffer_name(ParserOptions *options)
                {
                    return options->buffer_name.c_str();
                }

                CustomDecoder *parser_options_custom_decoder(ParserOptions *options)
                {
                    return options->custom_decoder.get();
                }

                TokenRewriter *parser_options_token_rewriter(ParserOptions *options)
                {
                    return options->token_rewriter.get();
                }

                bool parser_options_debug(ParserOptions *options)
                {
                    return options->debug;
                }

                bool parser_options_record_tokens(ParserOptions *options)
                {
                    return options->record_tokens;
                }
            }
        } // namespace parser_options

        namespace helpers
        {
            extern "C"
            {
                void free_str(char *s)
                {
                    free(s);
                }
            }
        } // namespace helpers

        namespace token_rewriter
        {
            Token token_from_raw_token(RawToken raw_token)
            {
                return Token(
                    raw_token.token_type,
                    std::string(raw_token.token_value_ptr, raw_token.token_value_len),
                    std::make_unique<Loc>(
                        raw_token.loc_begin,
                        raw_token.loc_end));
            }

            RawToken raw_token_to_token(Token token)
            {
                RawToken result;
                result.token_type = token.token_type;
                result.token_value_ptr = string_to_char_ptr(token.token_value);
                result.token_value_len = token.token_value.length();
                result.loc_begin = token.loc->begin;
                result.loc_end = token.loc->end;
                return result;
            }

            extern "C"
            {

                RawTokenRewriterResult rewrite_token(TokenRewriter *rewriter, RawToken raw_token, const char *input_ptr, size_t input_len)
                {
                    auto token = token_from_raw_token(raw_token);
                    auto input = Bytes(input_ptr, input_len);

                    auto cpp_result = rewriter->rewrite_token(std::move(token), std::move(input));

                    RawTokenRewriterResult c_result;

                    switch (cpp_result.lex_state_action.kind)
                    {
                    case TokenRewriter::LexStateAction::Kind::SET:
                        c_result.lex_state_action = RawLexStateAction::LEX_STATE_SET;
                        c_result.next_state = cpp_result.lex_state_action.next_state;
                        break;
                    case TokenRewriter::LexStateAction::Kind::KEEP:
                        c_result.lex_state_action = RawLexStateAction::LEX_STATE_KEEP;
                    default:
                        break;
                    }

                    switch (cpp_result.rewrite_action)
                    {
                    case TokenRewriter::RewriteAction::KEEP:
                        c_result.rewrite_action = RawRewriteAction::REWRITE_ACTION_KEEP;
                        break;
                    case TokenRewriter::RewriteAction::DROP:
                        c_result.rewrite_action = RawRewriteAction::REWRITE_ACTION_DROP;
                        break;

                    default:
                        break;
                    }
                    c_result.token = raw_token_to_token(std::move(cpp_result.token));

                    return c_result;
                }
            }
        } // namespace token_rewriter

    } // namespace low_level
} // namespace lib_ruby_parser
