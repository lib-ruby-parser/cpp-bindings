#ifndef LIB_RUBY_PARSER_DIAGNOSTIC_HPP
#define LIB_RUBY_PARSER_DIAGNOSTIC_HPP

#include <cstddef>
#include "messages.hpp"
#include "loc.hpp"
#include "decoded_input.hpp"

namespace lib_ruby_parser
{
    /*
        Equivalent of `lib_ruby_parser::ErrorLevel`
    */
    enum class ErrorLevel
    {
        WARNING,
        ERROR
    };

    /*
        Equivalent of `lib_ruby_parser::Diagnostic`
    */
    class Diagnostic
    {
    public:
        /*
            Level of the diagnostic (error/warning)
        */
        ErrorLevel level;

        /*
            Message of the diagnsotic
        */
        DiagnosticMessage message;

        /*
            Location of the diagnostic
        */
        Loc loc;

        Diagnostic() = delete;
        Diagnostic(ErrorLevel level, DiagnosticMessage message, Loc loc);

        Diagnostic(const Diagnostic &) = delete;
        Diagnostic &operator=(Diagnostic const &) = delete;

        Diagnostic(Diagnostic &&) = default;
        Diagnostic &operator=(Diagnostic &&) = default;

        /*
            Render given diagnsostic on a given source input.
            Equivalent of lib_ruby_parser::Diagnostic::render.
            Return owned NULL-terminated string.
        */
        std::string render(const DecodedInput &input) const;
    };

    /*
        Equivalent of `Vec<lib_ruby_parser::Diagnostic`
    */
    class DiagnosticList
    {
    public:
        Diagnostic *ptr;
        size_t capacity;
        size_t len;

        DiagnosticList() = delete;
        DiagnosticList(Diagnostic *ptr, size_t len, size_t capacity);
        ~DiagnosticList();

        DiagnosticList(const DiagnosticList &) = delete;
        DiagnosticList &operator=(DiagnosticList const &) = delete;

        DiagnosticList(DiagnosticList &&);
        DiagnosticList &operator=(DiagnosticList &&);
    };

#ifdef TEST_ENV
    void run_test_group_diagnostic(void);
#endif
} // namespace lib_ruby_parser

#endif // LIB_RUBY_PARSER_DIAGNOSTIC_HPP
