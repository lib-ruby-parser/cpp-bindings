#include "token.hpp"
#include "utils.hpp"

namespace lib_ruby_parser
{
    extern "C"
    {
        char *LIB_RUBY_PARSER_token_name(const Token *token);
    }
    Token::Token(int32_t token_type_,
                 Bytes token_value_,
                 Loc loc_,
                 int32_t lex_state_before_,
                 int32_t lex_state_after_) : token_type(token_type_),
                                             token_value(std::move(token_value_)),
                                             loc(loc_),
                                             lex_state_before(lex_state_before_),
                                             lex_state_after(lex_state_after_) {}
    std::string Token::token_name() const
    {
        char *token_name_ptr = LIB_RUBY_PARSER_token_name(this);
        std::string token_name(token_name_ptr);
        free(token_name_ptr);
        return token_name;
    }

    LIST_IMPL(TokenList, Token, LIB_RUBY_PARSER_drop_token_list);
} // namespace lib_ruby_parser
