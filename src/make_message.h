#ifndef LIB_RUBY_PARSER_MAKE_MESSAGE_H
#define LIB_RUBY_PARSER_MAKE_MESSAGE_H

#include "error_level.h"
#include "byte_ptr.h"

namespace lib_ruby_parser {

class Diagnostic;
class Loc;

extern "C" {

Diagnostic *make_fraction_after_numeric(ErrorLevel level, Loc *loc);
Diagnostic *make_no_digits_after_dot(ErrorLevel level, Loc *loc);
Diagnostic *make_unknown_type_of_percent_string(ErrorLevel level, Loc *loc);
Diagnostic *make_numeric_literal_without_digits(ErrorLevel level, Loc *loc);
Diagnostic *make_unterminated_list(ErrorLevel level, Loc *loc);
Diagnostic *make_unterminated_regexp(ErrorLevel level, Loc *loc);
Diagnostic *make_unterminated_string(ErrorLevel level, Loc *loc);
Diagnostic *make_unterminated_quoted_string(ErrorLevel level, Loc *loc);
Diagnostic *make_invalid_unicode_escape(ErrorLevel level, Loc *loc);
Diagnostic *make_too_large_unicode_codepoint(ErrorLevel level, Loc *loc);
Diagnostic *make_invalid_unicode_codepoint(ErrorLevel level, Loc *loc);
Diagnostic *make_multiple_codepoint_at_single_char(ErrorLevel level, Loc *loc);
Diagnostic *make_invalid_escape_character(ErrorLevel level, Loc *loc);
Diagnostic *make_invalid_hex_escape(ErrorLevel level, Loc *loc);
Diagnostic *make_unterminated_heredoc(ErrorLevel level, Loc *loc, BytePtr heredoc_id);
Diagnostic *make_unterminated_heredoc_id(ErrorLevel level, Loc *loc);
Diagnostic *make_slash_r_at_middle_of_line(ErrorLevel level, Loc *loc);
Diagnostic *make_d_star_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc);
Diagnostic *make_star_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc);
Diagnostic *make_ampersand_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc);
Diagnostic *make_triple_dot_at_eol(ErrorLevel level, Loc *loc);
Diagnostic *make_parentheses_iterpreted_as_arglist(ErrorLevel level, Loc *loc);
Diagnostic *make_ambiguous_first_argument(ErrorLevel level, Loc *loc, char operator_);
Diagnostic *make_ambiguous_operator(ErrorLevel level, Loc *loc, BytePtr operator_, BytePtr interpreted_as);
Diagnostic *make_invalid_character_syntax(ErrorLevel level, Loc *loc, BytePtr suggestion);
Diagnostic *make_invalid_octal_digit(ErrorLevel level, Loc *loc);
Diagnostic *make_trailing_char_in_number(ErrorLevel level, Loc *loc, char c);
Diagnostic *make_embedded_document_meets_eof(ErrorLevel level, Loc *loc);
Diagnostic *make_invalid_char(ErrorLevel level, Loc *loc, char c);
Diagnostic *make_incomplete_character_syntax(ErrorLevel level, Loc *loc);
Diagnostic *make_gvar_without_id(ErrorLevel level, Loc *loc);
Diagnostic *make_invalid_gvar_name(ErrorLevel level, Loc *loc, char c);
Diagnostic *make_ivar_without_id(ErrorLevel level, Loc *loc);
Diagnostic *make_invalid_ivar_name(ErrorLevel level, Loc *loc, char c);
Diagnostic *make_cvar_without_id(ErrorLevel level, Loc *loc);
Diagnostic *make_invalid_cvar_name(ErrorLevel level, Loc *loc, char c);
Diagnostic *make_unknown_regex_options(ErrorLevel level, Loc *loc, BytePtr options);
Diagnostic *make_unterminated_unicode_escape(ErrorLevel level, Loc *loc);
Diagnostic *make_encoding_error(ErrorLevel level, Loc *loc, BytePtr error);
Diagnostic *make_ambiguous_ternary_operator(ErrorLevel level, Loc *loc, BytePtr condition);
Diagnostic *make_ambiguous_regexp(ErrorLevel level, Loc *loc);
Diagnostic *make_else_without_rescue(ErrorLevel level, Loc *loc);
Diagnostic *make_begin_not_at_top_level(ErrorLevel level, Loc *loc);
Diagnostic *make_alias_nth_ref(ErrorLevel level, Loc *loc);
Diagnostic *make_csend_inside_masgn(ErrorLevel level, Loc *loc);
Diagnostic *make_class_or_module_name_must_be_constant(ErrorLevel level, Loc *loc);
Diagnostic *make_endless_setter_definition(ErrorLevel level, Loc *loc);
Diagnostic *make_unexpected_token(ErrorLevel level, Loc *loc, BytePtr token_name);
Diagnostic *make_class_definition_in_method_body(ErrorLevel level, Loc *loc);
Diagnostic *make_module_definition_in_method_body(ErrorLevel level, Loc *loc);
Diagnostic *make_invalid_return_in_class_or_module_body(ErrorLevel level, Loc *loc);
Diagnostic *make_const_argument(ErrorLevel level, Loc *loc);
Diagnostic *make_ivar_argument(ErrorLevel level, Loc *loc);
Diagnostic *make_gvar_argument(ErrorLevel level, Loc *loc);
Diagnostic *make_cvar_argument(ErrorLevel level, Loc *loc);
Diagnostic *make_no_such_local_variable(ErrorLevel level, Loc *loc, BytePtr var_name);
Diagnostic *make_ordinary_param_defined(ErrorLevel level, Loc *loc);
Diagnostic *make_numparam_used(ErrorLevel level, Loc *loc);
Diagnostic *make_tok_at_eol_without_expression(ErrorLevel level, Loc *loc, BytePtr token_name);
Diagnostic *make_end_in_method(ErrorLevel level, Loc *loc);
Diagnostic *make_comparison_after_comparison(ErrorLevel level, Loc *loc, BytePtr comparison);
Diagnostic *make_circular_argument_reference(ErrorLevel level, Loc *loc, BytePtr arg_name);
Diagnostic *make_dynamic_constant_assignment(ErrorLevel level, Loc *loc);
Diagnostic *make_cant_assign_to_self(ErrorLevel level, Loc *loc);
Diagnostic *make_cant_assign_to_nil(ErrorLevel level, Loc *loc);
Diagnostic *make_cant_assign_to_true(ErrorLevel level, Loc *loc);
Diagnostic *make_cant_assign_to_false(ErrorLevel level, Loc *loc);
Diagnostic *make_cant_assign_to_file(ErrorLevel level, Loc *loc);
Diagnostic *make_cant_assign_to_line(ErrorLevel level, Loc *loc);
Diagnostic *make_cant_assign_to_encoding(ErrorLevel level, Loc *loc);
Diagnostic *make_cant_assign_to_numparam(ErrorLevel level, Loc *loc, BytePtr numparam);
Diagnostic *make_cant_set_variable(ErrorLevel level, Loc *loc, BytePtr var_name);
Diagnostic *make_block_given_to_yield(ErrorLevel level, Loc *loc);
Diagnostic *make_block_and_block_arg_given(ErrorLevel level, Loc *loc);
Diagnostic *make_symbol_literal_with_interpolation(ErrorLevel level, Loc *loc);
Diagnostic *make_reserved_for_numparam(ErrorLevel level, Loc *loc, BytePtr numparam);
Diagnostic *make_key_must_be_valid_as_local_variable(ErrorLevel level, Loc *loc);
Diagnostic *make_duplicate_variable_name(ErrorLevel level, Loc *loc);
Diagnostic *make_duplicate_key_name(ErrorLevel level, Loc *loc);
Diagnostic *make_singleton_literal(ErrorLevel level, Loc *loc);
Diagnostic *make_nth_ref_is_too_big(ErrorLevel level, Loc *loc, BytePtr nth_ref);
Diagnostic *make_duplicated_argument_name(ErrorLevel level, Loc *loc);
Diagnostic *make_regex_error(ErrorLevel level, Loc *loc, BytePtr error);
Diagnostic *make_invalid_symbol(ErrorLevel level, Loc *loc, BytePtr symbol);
Diagnostic *make_void_value_expression(ErrorLevel level, Loc *loc);

}

}

#endif // LIB_RUBY_PARSER_MAKE_MESSAGE_H
