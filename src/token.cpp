#include "token.h"

namespace lib_ruby_parser
{
    Token::Token(
        int token_type,
        Bytes token_value,
        std::unique_ptr<Loc> loc)
    {
        this->token_type = token_type;
        this->token_value = std::move(token_value);
        this->loc = std::move(loc);
    }

    extern "C"
    {

        BytePtr token_name(int id);
    }

    std::string Token::name()
    {
        BytePtr ptr = token_name(token_type);
        return byte_ptr_to_owned_string(ptr);
    }

    std::ostream &operator<<(std::ostream &os, const Token &token)
    {
        os << "[" << token.token_type << ", " << token.token_value << ", " << *(token.loc) << "]";
        return os;
    }

    bool Token::operator==(const Token &other)
    {
        return (token_type == other.token_type) && (token_value == other.token_value) && (*loc == *(other.loc));
    }

    bool Token::operator!=(const Token &other)
    {
        return !(*this == other);
    }
} // namespace lib_ruby_parser
