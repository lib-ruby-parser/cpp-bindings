#include "test_helper.hpp"
#include "../diagnostic.hpp"
#include "../utils.hpp"
#include <cstdlib>

namespace lib_ruby_parser
{
#ifndef DIAGNOSTIC_HAS_BLOB
#define DIAGNOSTIC_HAS_BLOB
    BLOB(Diagnostic);
#endif // DIAGNOSTIC_HAS_BLOB

#ifndef DIAGNOSTIC_LIST_HAS_BLOB
#define DIAGNOSTIC_LIST_HAS_BLOB
    BLOB(DiagnosticList);
#endif // DIAGNOSTIC_LIST_HAS_BLOB

    extern "C"
    {
        DiagnosticBlob lib_ruby_parser__test__make_diagnostic();
    }
    static void test_diagnostic(void)
    {
        annotate_test;

        Diagnostic diagnostic = from_blob<DiagnosticBlob, Diagnostic>(
            lib_ruby_parser__test__make_diagnostic());

        assert_eq(diagnostic.level, ErrorLevel::ERROR);
        assert_eq(diagnostic.message.tag, DiagnosticMessage::Tag::UNTERMINATED_HEREDOC);
        assert_string_eq(diagnostic.message.as.unterminated_heredoc.heredoc_id, "foo");
        assert_eq(diagnostic.loc.begin, 1);
        assert_eq(diagnostic.loc.end, 2);
    }

    static void test_diagnostic_render(void)
    {
        annotate_test;

        Diagnostic diagnostic(
            ErrorLevel::ERROR,
            DiagnosticMessage(UnterminatedHeredoc(String::Copied("foo"))),
            Loc(1, 4));
        SourceLine *lines = static_cast<SourceLine *>(malloc(sizeof(SourceLine) * 1));
        lines[0].start = 0;
        lines[0].end = 9;
        lines[0].ends_with_eof = true;
        DecodedInput input(
            String::Copied("(eval)"),
            SourceLineList(lines, 1, 1),
            ByteList::Copied("2 + 2 + 3", 9));

        std::string rendered = diagnostic.render(input);
        const char *expected = "(eval):1:1: error: can't find string \"foo\" anywhere before EOF\n"
                               "(eval):1: 2 + 2 + 3\n"
                               "(eval):1:  ^~~";

        assert_str_eq(rendered.data(), expected);
    }

    extern "C"
    {
        DiagnosticListBlob lib_ruby_parser__test__make_diagnostic_list(void);
    }
    static void test_diagnostic_list(void)
    {
        annotate_test;

        DiagnosticList diagnostic_list = from_blob<DiagnosticListBlob, DiagnosticList>(
            lib_ruby_parser__test__make_diagnostic_list());

        assert_eq(diagnostic_list.len, 1);
        assert_eq(diagnostic_list.ptr[0].level, ErrorLevel::ERROR);
        assert_eq(diagnostic_list.ptr[0].message.tag, DiagnosticMessage::Tag::UNTERMINATED_HEREDOC);
        assert_string_eq(diagnostic_list.ptr[0].message.as.unterminated_heredoc.heredoc_id, "foo");
        assert_eq(diagnostic_list.ptr[0].loc.begin, 1);
        assert_eq(diagnostic_list.ptr[0].loc.end, 2);
    }

    void run_test_group_diagnostic(void);
    void run_test_group_diagnostic(void)
    {
        const test_fn_t tests[] = {
            test_diagnostic,
            test_diagnostic_render,
            test_diagnostic_list,
        };

        run_tests_as_group("diagnostic", tests, sizeof(tests) / sizeof(test_fn_t));
    }
}
