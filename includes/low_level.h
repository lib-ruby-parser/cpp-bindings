#ifndef LIB_RUBY_PARSER_LOW_LEVEL_H
#define LIB_RUBY_PARSER_LOW_LEVEL_H

#include <cstddef>
#include "make_node.h"
#include "comment_type.h"
#include "error_level.h"
#include "magic_comment_kind.h"

namespace lib_ruby_parser
{
    class Loc;
    class Range;
    class Token;
    class Comment;
    class Diagnostic;
    class CustomDecoder;
    class MagicComment;
    class TokenRewriter;
    class ParserResult;
    class ParserOptions;

    namespace low_level
    {
        namespace make
        {
            extern "C"
            {
                struct TokenVec
                {
                    Token **list;
                    size_t length;
                };

                struct DiagnosticVec
                {
                    Diagnostic **list;
                    size_t length;
                };

                struct CommentVec
                {
                    Comment **list;
                    size_t length;
                };

                struct MagicCommentVec
                {
                    MagicComment **list;
                    size_t length;
                };

                ParserResult *make_parser_result(
                    Node *ast,
                    TokenVec tokens,
                    DiagnosticVec diagnostics,
                    CommentVec comments,
                    MagicCommentVec magic_comments,
                    char *input);

                Comment *make_comment(CommentType kind, Range *location);
                Diagnostic *make_diagnostic(ErrorLevel level, char *message, Range *range);
                MagicComment *make_magic_comment(MagicCommentKind kind, Range *key_l, Range *value_l);
                Range *make_range(size_t begin_pos, size_t end_pos);
                Loc *make_loc(size_t begin, size_t end);
                Token *make_token(int token_type, char *token_value, Loc *loc);
            }
        } // namespace make

        namespace custom_decoder
        {
            extern "C"
            {
                struct CustomDecoderResult
                {
                    bool success;

                    char *output;
                    size_t output_length;

                    char *error_message;
                    size_t error_message_length;

                    static CustomDecoderResult Ok(char *output, size_t length);
                    static CustomDecoderResult Error(char *error_message, size_t length);
                };

                CustomDecoderResult rewrite(CustomDecoder *decoder, const char *encoding_ptr, size_t encoding_length, const char *input_ptr, size_t input_length);
            }
        } // namespace custom_decoder

        namespace parser_options
        {
            extern "C"
            {
                const char *parser_options_buffer_name(ParserOptions *options);
                CustomDecoder *parser_options_custom_decoder(ParserOptions *options);
                TokenRewriter *parser_options_token_rewriter(ParserOptions *options);
                bool parser_options_debug(ParserOptions *options);
                bool parser_options_record_tokens(ParserOptions *options);
            }
        } // namespace parser_options

        namespace helpers
        {
            extern "C"
            {
                void free_str(char *s);
            }
        } // namespace helpers

        namespace token_rewriter
        {
            extern "C"
            {
                enum RawRewriteAction
                {
                    REWRITE_ACTION_KEEP,
                    REWRITE_ACTION_DROP,
                };

                enum RawLexStateAction
                {
                    LEX_STATE_SET,
                    LEX_STATE_KEEP
                };

                struct RawToken
                {
                    int token_type;
                    const char *token_value_ptr;
                    size_t token_value_len;
                    size_t loc_begin;
                    size_t loc_end;
                };

                struct RawTokenRewriterResult
                {
                    RawRewriteAction rewrite_action;
                    RawLexStateAction lex_state_action;
                    int next_state;

                    RawToken token;
                };

                RawTokenRewriterResult rewrite_token(TokenRewriter *rewriter, RawToken token, const char *input_ptr, size_t input_len);
            }
        } // namespace token_rewriter

        extern "C"
        {

            char *token_name(int id);
        }
    } // namespace low_level
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_LOW_LEVEL_H
