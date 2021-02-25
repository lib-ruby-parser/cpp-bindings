#ifndef LIB_RUBY_PARSER_LOW_LEVEL_H
#define LIB_RUBY_PARSER_LOW_LEVEL_H

#include <stdint.h>
#include "make_node.h"
#include "make_message.h"
#include "comment_type.h"
#include "error_level.h"
#include "magic_comment_kind.h"
#include "byte_ptr.h"

namespace lib_ruby_parser
{
    class Loc;
    class Loc;
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
                    Token **ptr;
                    uint32_t length;
                };

                struct DiagnosticVec
                {
                    Diagnostic **ptr;
                    uint32_t length;
                };

                struct CommentVec
                {
                    Comment **ptr;
                    uint32_t length;
                };

                struct MagicCommentVec
                {
                    MagicComment **ptr;
                    uint32_t length;
                };

                ParserResult *make_parser_result(
                    Node *ast,
                    TokenVec tokens,
                    DiagnosticVec diagnostics,
                    CommentVec comments,
                    MagicCommentVec magic_comments,
                    void *input);

                Comment *make_comment(CommentType kind, Loc *location);
                // Diagnostic *make_diagnostic(ErrorLevel level, BytePtr message, Loc *loc);
                MagicComment *make_magic_comment(MagicCommentKind kind, Loc *key_l, Loc *value_l);
                Loc *make_loc(uint32_t begin, uint32_t end);
                Token *make_token(int token_type, BytePtr token_value, Loc *loc);
            }
        } // namespace make

        namespace custom_decoder
        {
            extern "C"
            {
                struct CustomDecoderResult
                {
                    bool success;
                    BytePtr output;
                    BytePtr error_message;

                    static CustomDecoderResult Ok(BytePtr output);
                    static CustomDecoderResult Error(BytePtr error_message);
                };

                CustomDecoderResult rewrite(CustomDecoder *decoder, BytePtr encoding, BytePtr input);
            }
        } // namespace custom_decoder

        namespace parser_options
        {
            extern "C"
            {
                BytePtr parser_options_buffer_name(ParserOptions *options);
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
                    BytePtr token_value;
                    uint32_t loc_begin;
                    uint32_t loc_end;
                };

                struct RawTokenRewriterResult
                {
                    RawRewriteAction rewrite_action;
                    RawLexStateAction lex_state_action;
                    int next_state;

                    RawToken token;
                };

                RawTokenRewriterResult rewrite_token(TokenRewriter *rewriter, RawToken token, BytePtr input);
            }
        } // namespace token_rewriter

        namespace loc
        {
            extern "C"
            {
                uint32_t loc_begin(Loc *loc);
                uint32_t loc_end(Loc *loc);
            }
        } // namespace loc
    }     // namespace low_level
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_LOW_LEVEL_H
