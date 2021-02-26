#ifndef LIB_RUBY_PARSER_RENDER_MESSAGE_H
#define LIB_RUBY_PARSER_RENDER_MESSAGE_H

#include "../../error_level.h"
#include "../../byte_ptr.h"

namespace lib_ruby_parser {

class Diagnostic;
class Loc;

extern "C" {

BytePtr render_message_fraction_after_numeric(ErrorLevel level, Loc *loc);
BytePtr render_message_no_digits_after_dot(ErrorLevel level, Loc *loc);
BytePtr render_message_unknown_type_of_percent_string(ErrorLevel level, Loc *loc);
BytePtr render_message_numeric_literal_without_digits(ErrorLevel level, Loc *loc);
BytePtr render_message_unterminated_list(ErrorLevel level, Loc *loc);
BytePtr render_message_unterminated_regexp(ErrorLevel level, Loc *loc);
BytePtr render_message_unterminated_string(ErrorLevel level, Loc *loc);
BytePtr render_message_unterminated_quoted_string(ErrorLevel level, Loc *loc);
BytePtr render_message_invalid_unicode_escape(ErrorLevel level, Loc *loc);
BytePtr render_message_too_large_unicode_codepoint(ErrorLevel level, Loc *loc);
BytePtr render_message_invalid_unicode_codepoint(ErrorLevel level, Loc *loc);
BytePtr render_message_multiple_codepoint_at_single_char(ErrorLevel level, Loc *loc);
BytePtr render_message_invalid_escape_character(ErrorLevel level, Loc *loc);
BytePtr render_message_invalid_hex_escape(ErrorLevel level, Loc *loc);
BytePtr render_message_unterminated_heredoc(ErrorLevel level, Loc *loc, BytePtr heredoc_id);
BytePtr render_message_unterminated_heredoc_id(ErrorLevel level, Loc *loc);
BytePtr render_message_slash_r_at_middle_of_line(ErrorLevel level, Loc *loc);
BytePtr render_message_d_star_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc);
BytePtr render_message_star_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc);
BytePtr render_message_ampersand_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc);
BytePtr render_message_triple_dot_at_eol(ErrorLevel level, Loc *loc);
BytePtr render_message_parentheses_iterpreted_as_arglist(ErrorLevel level, Loc *loc);
BytePtr render_message_ambiguous_first_argument(ErrorLevel level, Loc *loc, char operator_);
BytePtr render_message_ambiguous_operator(ErrorLevel level, Loc *loc, BytePtr operator_, BytePtr interpreted_as);
BytePtr render_message_invalid_character_syntax(ErrorLevel level, Loc *loc, BytePtr suggestion);
BytePtr render_message_invalid_octal_digit(ErrorLevel level, Loc *loc);
BytePtr render_message_trailing_char_in_number(ErrorLevel level, Loc *loc, char c);
BytePtr render_message_embedded_document_meets_eof(ErrorLevel level, Loc *loc);
BytePtr render_message_invalid_char(ErrorLevel level, Loc *loc, char c);
BytePtr render_message_incomplete_character_syntax(ErrorLevel level, Loc *loc);
BytePtr render_message_gvar_without_id(ErrorLevel level, Loc *loc);
BytePtr render_message_invalid_gvar_name(ErrorLevel level, Loc *loc, char c);
BytePtr render_message_ivar_without_id(ErrorLevel level, Loc *loc);
BytePtr render_message_invalid_ivar_name(ErrorLevel level, Loc *loc, char c);
BytePtr render_message_cvar_without_id(ErrorLevel level, Loc *loc);
BytePtr render_message_invalid_cvar_name(ErrorLevel level, Loc *loc, char c);
BytePtr render_message_unknown_regex_options(ErrorLevel level, Loc *loc, BytePtr options);
BytePtr render_message_unterminated_unicode_escape(ErrorLevel level, Loc *loc);
BytePtr render_message_encoding_error(ErrorLevel level, Loc *loc, BytePtr error);
BytePtr render_message_ambiguous_ternary_operator(ErrorLevel level, Loc *loc, BytePtr condition);
BytePtr render_message_ambiguous_regexp(ErrorLevel level, Loc *loc);
BytePtr render_message_else_without_rescue(ErrorLevel level, Loc *loc);
BytePtr render_message_begin_not_at_top_level(ErrorLevel level, Loc *loc);
BytePtr render_message_alias_nth_ref(ErrorLevel level, Loc *loc);
BytePtr render_message_csend_inside_masgn(ErrorLevel level, Loc *loc);
BytePtr render_message_class_or_module_name_must_be_constant(ErrorLevel level, Loc *loc);
BytePtr render_message_endless_setter_definition(ErrorLevel level, Loc *loc);
BytePtr render_message_unexpected_token(ErrorLevel level, Loc *loc, BytePtr token_name);
BytePtr render_message_class_definition_in_method_body(ErrorLevel level, Loc *loc);
BytePtr render_message_module_definition_in_method_body(ErrorLevel level, Loc *loc);
BytePtr render_message_invalid_return_in_class_or_module_body(ErrorLevel level, Loc *loc);
BytePtr render_message_const_argument(ErrorLevel level, Loc *loc);
BytePtr render_message_ivar_argument(ErrorLevel level, Loc *loc);
BytePtr render_message_gvar_argument(ErrorLevel level, Loc *loc);
BytePtr render_message_cvar_argument(ErrorLevel level, Loc *loc);
BytePtr render_message_no_such_local_variable(ErrorLevel level, Loc *loc, BytePtr var_name);
BytePtr render_message_ordinary_param_defined(ErrorLevel level, Loc *loc);
BytePtr render_message_numparam_used(ErrorLevel level, Loc *loc);
BytePtr render_message_tok_at_eol_without_expression(ErrorLevel level, Loc *loc, BytePtr token_name);
BytePtr render_message_end_in_method(ErrorLevel level, Loc *loc);
BytePtr render_message_comparison_after_comparison(ErrorLevel level, Loc *loc, BytePtr comparison);
BytePtr render_message_circular_argument_reference(ErrorLevel level, Loc *loc, BytePtr arg_name);
BytePtr render_message_dynamic_constant_assignment(ErrorLevel level, Loc *loc);
BytePtr render_message_cant_assign_to_self(ErrorLevel level, Loc *loc);
BytePtr render_message_cant_assign_to_nil(ErrorLevel level, Loc *loc);
BytePtr render_message_cant_assign_to_true(ErrorLevel level, Loc *loc);
BytePtr render_message_cant_assign_to_false(ErrorLevel level, Loc *loc);
BytePtr render_message_cant_assign_to_file(ErrorLevel level, Loc *loc);
BytePtr render_message_cant_assign_to_line(ErrorLevel level, Loc *loc);
BytePtr render_message_cant_assign_to_encoding(ErrorLevel level, Loc *loc);
BytePtr render_message_cant_assign_to_numparam(ErrorLevel level, Loc *loc, BytePtr numparam);
BytePtr render_message_cant_set_variable(ErrorLevel level, Loc *loc, BytePtr var_name);
BytePtr render_message_block_given_to_yield(ErrorLevel level, Loc *loc);
BytePtr render_message_block_and_block_arg_given(ErrorLevel level, Loc *loc);
BytePtr render_message_symbol_literal_with_interpolation(ErrorLevel level, Loc *loc);
BytePtr render_message_reserved_for_numparam(ErrorLevel level, Loc *loc, BytePtr numparam);
BytePtr render_message_key_must_be_valid_as_local_variable(ErrorLevel level, Loc *loc);
BytePtr render_message_duplicate_variable_name(ErrorLevel level, Loc *loc);
BytePtr render_message_duplicate_key_name(ErrorLevel level, Loc *loc);
BytePtr render_message_singleton_literal(ErrorLevel level, Loc *loc);
BytePtr render_message_nth_ref_is_too_big(ErrorLevel level, Loc *loc, BytePtr nth_ref);
BytePtr render_message_duplicated_argument_name(ErrorLevel level, Loc *loc);
BytePtr render_message_regex_error(ErrorLevel level, Loc *loc, BytePtr error);
BytePtr render_message_invalid_symbol(ErrorLevel level, Loc *loc, BytePtr symbol);
BytePtr render_message_void_value_expression(ErrorLevel level, Loc *loc);

BytePtr render_fraction_after_numeric(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_no_digits_after_dot(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_unknown_type_of_percent_string(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_numeric_literal_without_digits(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_unterminated_list(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_unterminated_regexp(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_unterminated_string(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_unterminated_quoted_string(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_invalid_unicode_escape(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_too_large_unicode_codepoint(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_invalid_unicode_codepoint(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_multiple_codepoint_at_single_char(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_invalid_escape_character(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_invalid_hex_escape(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_unterminated_heredoc(ErrorLevel level, Loc *loc, BytePtr heredoc_id, BytePtr input);
BytePtr render_unterminated_heredoc_id(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_slash_r_at_middle_of_line(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_d_star_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_star_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_ampersand_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_triple_dot_at_eol(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_parentheses_iterpreted_as_arglist(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_ambiguous_first_argument(ErrorLevel level, Loc *loc, char operator_, BytePtr input);
BytePtr render_ambiguous_operator(ErrorLevel level, Loc *loc, BytePtr operator_, BytePtr interpreted_as, BytePtr input);
BytePtr render_invalid_character_syntax(ErrorLevel level, Loc *loc, BytePtr suggestion, BytePtr input);
BytePtr render_invalid_octal_digit(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_trailing_char_in_number(ErrorLevel level, Loc *loc, char c, BytePtr input);
BytePtr render_embedded_document_meets_eof(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_invalid_char(ErrorLevel level, Loc *loc, char c, BytePtr input);
BytePtr render_incomplete_character_syntax(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_gvar_without_id(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_invalid_gvar_name(ErrorLevel level, Loc *loc, char c, BytePtr input);
BytePtr render_ivar_without_id(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_invalid_ivar_name(ErrorLevel level, Loc *loc, char c, BytePtr input);
BytePtr render_cvar_without_id(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_invalid_cvar_name(ErrorLevel level, Loc *loc, char c, BytePtr input);
BytePtr render_unknown_regex_options(ErrorLevel level, Loc *loc, BytePtr options, BytePtr input);
BytePtr render_unterminated_unicode_escape(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_encoding_error(ErrorLevel level, Loc *loc, BytePtr error, BytePtr input);
BytePtr render_ambiguous_ternary_operator(ErrorLevel level, Loc *loc, BytePtr condition, BytePtr input);
BytePtr render_ambiguous_regexp(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_else_without_rescue(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_begin_not_at_top_level(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_alias_nth_ref(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_csend_inside_masgn(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_class_or_module_name_must_be_constant(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_endless_setter_definition(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_unexpected_token(ErrorLevel level, Loc *loc, BytePtr token_name, BytePtr input);
BytePtr render_class_definition_in_method_body(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_module_definition_in_method_body(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_invalid_return_in_class_or_module_body(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_const_argument(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_ivar_argument(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_gvar_argument(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_cvar_argument(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_no_such_local_variable(ErrorLevel level, Loc *loc, BytePtr var_name, BytePtr input);
BytePtr render_ordinary_param_defined(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_numparam_used(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_tok_at_eol_without_expression(ErrorLevel level, Loc *loc, BytePtr token_name, BytePtr input);
BytePtr render_end_in_method(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_comparison_after_comparison(ErrorLevel level, Loc *loc, BytePtr comparison, BytePtr input);
BytePtr render_circular_argument_reference(ErrorLevel level, Loc *loc, BytePtr arg_name, BytePtr input);
BytePtr render_dynamic_constant_assignment(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_cant_assign_to_self(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_cant_assign_to_nil(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_cant_assign_to_true(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_cant_assign_to_false(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_cant_assign_to_file(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_cant_assign_to_line(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_cant_assign_to_encoding(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_cant_assign_to_numparam(ErrorLevel level, Loc *loc, BytePtr numparam, BytePtr input);
BytePtr render_cant_set_variable(ErrorLevel level, Loc *loc, BytePtr var_name, BytePtr input);
BytePtr render_block_given_to_yield(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_block_and_block_arg_given(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_symbol_literal_with_interpolation(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_reserved_for_numparam(ErrorLevel level, Loc *loc, BytePtr numparam, BytePtr input);
BytePtr render_key_must_be_valid_as_local_variable(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_duplicate_variable_name(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_duplicate_key_name(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_singleton_literal(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_nth_ref_is_too_big(ErrorLevel level, Loc *loc, BytePtr nth_ref, BytePtr input);
BytePtr render_duplicated_argument_name(ErrorLevel level, Loc *loc, BytePtr input);
BytePtr render_regex_error(ErrorLevel level, Loc *loc, BytePtr error, BytePtr input);
BytePtr render_invalid_symbol(ErrorLevel level, Loc *loc, BytePtr symbol, BytePtr input);
BytePtr render_void_value_expression(ErrorLevel level, Loc *loc, BytePtr input);

BytePtr render_message_diagnostic(Diagnostic *diagnostic);
BytePtr render_diagnostic(Diagnostic *diagnostic, BytePtr input);

}

}

#endif // LIB_RUBY_PARSER_RENDER_MESSAGE_H
