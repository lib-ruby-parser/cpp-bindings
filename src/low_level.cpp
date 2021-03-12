#include <cstring>
#include "low_level.h"
#include "comment.h"
#include "loc.h"
#include "bytes.h"
#include "custom_decoder.h"
#include "token.h"
#include "diagnostic.h"
#include "magic_comment.h"
#include "parser_options.h"
#include "parser_result.h"
#include "message.h"

namespace lib_ruby_parser
{
    namespace low_level
    {
        namespace make
        {
            template <typename T>
            std::vector<T> ptr_to_vec(T **ptr, uint32_t size)
            {
                std::vector<T> v;
                for (uint32_t i = 0; i < size; i++)
                {
                    v.push_back(std::move(*ptr[i]));
                    delete (ptr[i]);
                }
                if (size != 0)
                {
                    free(ptr);
                }
                return v;
            }

            std::vector<Token> tokens_vec_to_cpp_vec(TokenVec tokens)
            {
                return ptr_to_vec<Token>(tokens.ptr, tokens.length);
            }

            std::vector<Diagnostic> diagnostics_vec_to_cpp_vec(DiagnosticVec diagnostics)
            {
                return ptr_to_vec<Diagnostic>(diagnostics.ptr, diagnostics.length);
            }

            std::vector<Comment> comments_vec_to_cpp_vec(CommentVec comments)
            {
                return ptr_to_vec<Comment>(comments.ptr, comments.length);
            }

            std::vector<MagicComment> magic_comments_vec_to_cpp_vec(MagicCommentVec magic_comments)
            {
                return ptr_to_vec<MagicComment>(magic_comments.ptr, magic_comments.length);
            }

            extern "C"
            {
                ParserResult *make_parser_result(
                    Node *ast,
                    TokenVec tokens,
                    DiagnosticVec diagnostics,
                    CommentVec comments,
                    MagicCommentVec magic_comments,
                    void *input)
                {
                    auto result = new ParserResult(
                        std::unique_ptr<Node>(ast),
                        tokens_vec_to_cpp_vec(tokens),
                        diagnostics_vec_to_cpp_vec(diagnostics),
                        comments_vec_to_cpp_vec(comments),
                        magic_comments_vec_to_cpp_vec(magic_comments),
                        Input(input));

                    return result;
                }

                Comment *make_comment(CommentType kind, Loc *location)
                {
                    return new Comment(kind, std::unique_ptr<Loc>(location));
                }

                MagicComment *make_magic_comment(MagicCommentKind kind, Loc *key_l, Loc *value_l)
                {
                    return new MagicComment(kind, std::unique_ptr<Loc>(key_l), std::unique_ptr<Loc>(value_l));
                }

                Loc *make_loc(uint32_t begin, uint32_t end)
                {
                    return new Loc(begin, end);
                }

                Token *make_token(int token_type, BytePtr token_value, Loc *loc)
                {
                    auto result = new Token(
                        token_type,
                        Bytes(token_value),
                        std::unique_ptr<Loc>(loc));
                    return result;
                }
            }
        } // namespace make

        namespace custom_decoder
        {
            extern "C"
            {
                CustomDecoderResult rewrite(CustomDecoder *decoder, BytePtr encoding_ptr, BytePtr input_ptr)
                {
                    auto encoding = std::string(encoding_ptr.ptr, encoding_ptr.size);
                    auto input = Bytes((char *)input_ptr.ptr, input_ptr.size);
                    input.mark_borrowed();

                    auto cpp_result = decoder->rewrite(encoding, std::move(input));

                    if (std::holds_alternative<Bytes>(cpp_result.data))
                    {
                        auto output_ptr = std::get<Bytes>(cpp_result.data).into_ptr();
                        return CustomDecoderResult::Ok(output_ptr);
                    }
                    else
                    {
                        return CustomDecoderResult::Error(Bytes(std::get<std::string>(cpp_result.data)).into_ptr());
                    }
                }

                CustomDecoderResult CustomDecoderResult::Ok(BytePtr output)
                {
                    CustomDecoderResult result;
                    result.output = output;
                    result.success = true;
                    return result;
                }

                CustomDecoderResult CustomDecoderResult::Error(BytePtr error_message)
                {
                    CustomDecoderResult result;
                    result.error_message = error_message;
                    result.success = false;
                    return result;
                }
            }
        } // namespace custom_decoder

        namespace parser_options
        {
            extern "C"
            {
                BytePtr parser_options_buffer_name(ParserOptions *options)
                {
                    return make_byte_ptr(options->buffer_name.c_str(), options->buffer_name.size());
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

                void free_byte_ptr2(BytePtr byte_ptr)
                {
                    ::lib_ruby_parser::free_byte_ptr(byte_ptr);
                }
            }
        } // namespace helpers

        namespace token_rewriter
        {
            Token token_from_raw_token(RawToken raw_token)
            {
                return Token(
                    raw_token.token_type,
                    Bytes(raw_token.token_value),
                    std::make_unique<Loc>(
                        raw_token.loc_begin,
                        raw_token.loc_end));
            }

            RawToken raw_token_to_token(Token token)
            {
                RawToken result;
                result.token_type = token.token_type;
                result.token_value = token.token_value.into_ptr();
                result.loc_begin = token.loc->begin;
                result.loc_end = token.loc->end;
                return result;
            }

            extern "C"
            {

                RawTokenRewriterResult rewrite_token(TokenRewriter *rewriter, RawToken raw_token, BytePtr input_ptr)
                {
                    auto token = token_from_raw_token(raw_token);
                    auto input = Bytes(input_ptr);
                    input.mark_borrowed();

                    auto cpp_result = rewriter->rewrite_token(token, input);

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

        namespace loc
        {
            extern "C"
            {
                uint32_t loc_begin(Loc *loc)
                {
                    return loc->begin;
                }
                uint32_t loc_end(Loc *loc)
                {
                    return loc->end;
                }
            }
        } // namespace loc

    } // namespace low_level
} // namespace lib_ruby_parser
