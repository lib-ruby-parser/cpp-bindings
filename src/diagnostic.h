#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <string>
#include <memory>
#include <iostream>
#include "error_level.h"
#include "message.h"
#include "bytes.h"

namespace lib_ruby_parser
{
    class Loc;

    class Diagnostic
    {
    public:
        ErrorLevel level;
        diagnostic_message_variant_t message;
        std::unique_ptr<Loc> loc;

        Diagnostic() = delete;
        Diagnostic(Diagnostic &&) = default;
        Diagnostic(const Diagnostic &) = delete;
        explicit Diagnostic(ErrorLevel level,
                            diagnostic_message_variant_t message,
                            std::unique_ptr<Loc> loc);

        template <typename T>
        bool is()
        {
            return std::holds_alternative<std::unique_ptr<T>>(message);
        }

        template <typename T>
        T *get()
        {
            return std::get<std::unique_ptr<T>>(message).get();
        }

        bool operator==(const Diagnostic &other);
        bool operator!=(const Diagnostic &other);

        friend std::ostream &operator<<(std::ostream &os, const Diagnostic &diagnostic);

        std::string render_message();
        std::string render(const Bytes &input);
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
