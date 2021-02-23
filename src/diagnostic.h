#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_H
#define LIB_RUBY_PARSER_DIAGNOSTIC_H

#include <string>
#include <memory>
#include <iostream>
#include "loc.h"
#include "error_level.h"

namespace lib_ruby_parser
{
    class Diagnostic
    {
    public:
        ErrorLevel level;
        std::string message;
        std::unique_ptr<Loc> loc;

        Diagnostic() = delete;
        Diagnostic(Diagnostic &&) = default;
        Diagnostic(const Diagnostic &) = delete;
        explicit Diagnostic(ErrorLevel level,
                            std::string message,
                            std::unique_ptr<Loc> loc);

        bool operator==(const Diagnostic &other);
        bool operator!=(const Diagnostic &other);

        friend std::ostream &operator<<(std::ostream &os, const Diagnostic &diagnostic);
    };

} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_H
