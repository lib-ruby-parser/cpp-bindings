#include "make_message.h"
#include "diagnostic.h"

namespace lib_ruby_parser {

Diagnostic *make_fraction_after_numeric(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<FractionAfterNumeric>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_no_digits_after_dot(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<NoDigitsAfterDot>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unknown_type_of_percent_string(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<UnknownTypeOfPercentString>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_numeric_literal_without_digits(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<NumericLiteralWithoutDigits>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_list(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<UnterminatedList>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_regexp(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<UnterminatedRegexp>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_string(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<UnterminatedString>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_quoted_string(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<UnterminatedQuotedString>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_unicode_escape(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<InvalidUnicodeEscape>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_too_large_unicode_codepoint(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<TooLargeUnicodeCodepoint>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_unicode_codepoint(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<InvalidUnicodeCodepoint>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_multiple_codepoint_at_single_char(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<MultipleCodepointAtSingleChar>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_escape_character(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<InvalidEscapeCharacter>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_hex_escape(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<InvalidHexEscape>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_heredoc(ErrorLevel level, Loc *loc, BytePtr heredoc_id)
{
    diagnostic_message_variant_t message = std::make_unique<UnterminatedHeredoc>(byte_ptr_to_owned_string(heredoc_id));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_heredoc_id(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<UnterminatedHeredocId>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_slash_r_at_middle_of_line(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<SlashRAtMiddleOfLine>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_d_star_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<DStarInterpretedAsArgPrefix>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_star_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<StarInterpretedAsArgPrefix>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ampersand_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<AmpersandInterpretedAsArgPrefix>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_triple_dot_at_eol(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<TripleDotAtEol>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_parentheses_iterpreted_as_arglist(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<ParenthesesIterpretedAsArglist>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ambiguous_first_argument(ErrorLevel level, Loc *loc, char operator_)
{
    diagnostic_message_variant_t message = std::make_unique<AmbiguousFirstArgument>(operator_);
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ambiguous_operator(ErrorLevel level, Loc *loc, BytePtr operator_, BytePtr interpreted_as)
{
    diagnostic_message_variant_t message = std::make_unique<AmbiguousOperator>(byte_ptr_to_owned_string(operator_), byte_ptr_to_owned_string(interpreted_as));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_character_syntax(ErrorLevel level, Loc *loc, BytePtr suggestion)
{
    diagnostic_message_variant_t message = std::make_unique<InvalidCharacterSyntax>(byte_ptr_to_owned_string(suggestion));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_octal_digit(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<InvalidOctalDigit>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_trailing_char_in_number(ErrorLevel level, Loc *loc, char c)
{
    diagnostic_message_variant_t message = std::make_unique<TrailingCharInNumber>(c);
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_embedded_document_meets_eof(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<EmbeddedDocumentMeetsEof>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_char(ErrorLevel level, Loc *loc, char c)
{
    diagnostic_message_variant_t message = std::make_unique<InvalidChar>(c);
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_incomplete_character_syntax(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<IncompleteCharacterSyntax>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_gvar_without_id(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<GvarWithoutId>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_gvar_name(ErrorLevel level, Loc *loc, char c)
{
    diagnostic_message_variant_t message = std::make_unique<InvalidGvarName>(c);
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ivar_without_id(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<IvarWithoutId>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_ivar_name(ErrorLevel level, Loc *loc, char c)
{
    diagnostic_message_variant_t message = std::make_unique<InvalidIvarName>(c);
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cvar_without_id(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<CvarWithoutId>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_cvar_name(ErrorLevel level, Loc *loc, char c)
{
    diagnostic_message_variant_t message = std::make_unique<InvalidCvarName>(c);
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unknown_regex_options(ErrorLevel level, Loc *loc, BytePtr options)
{
    diagnostic_message_variant_t message = std::make_unique<UnknownRegexOptions>(byte_ptr_to_owned_string(options));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_unicode_escape(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<UnterminatedUnicodeEscape>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_encoding_error(ErrorLevel level, Loc *loc, BytePtr error)
{
    diagnostic_message_variant_t message = std::make_unique<EncodingError>(byte_ptr_to_owned_string(error));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ambiguous_ternary_operator(ErrorLevel level, Loc *loc, BytePtr condition)
{
    diagnostic_message_variant_t message = std::make_unique<AmbiguousTernaryOperator>(byte_ptr_to_owned_string(condition));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ambiguous_regexp(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<AmbiguousRegexp>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_else_without_rescue(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<ElseWithoutRescue>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_begin_not_at_top_level(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<BeginNotAtTopLevel>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_alias_nth_ref(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<AliasNthRef>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_csend_inside_masgn(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<CsendInsideMasgn>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_class_or_module_name_must_be_constant(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<ClassOrModuleNameMustBeConstant>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_endless_setter_definition(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<EndlessSetterDefinition>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unexpected_token(ErrorLevel level, Loc *loc, BytePtr token_name)
{
    diagnostic_message_variant_t message = std::make_unique<UnexpectedToken>(byte_ptr_to_owned_string(token_name));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_class_definition_in_method_body(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<ClassDefinitionInMethodBody>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_module_definition_in_method_body(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<ModuleDefinitionInMethodBody>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_return_in_class_or_module_body(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<InvalidReturnInClassOrModuleBody>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_const_argument(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<ConstArgument>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ivar_argument(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<IvarArgument>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_gvar_argument(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<GvarArgument>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cvar_argument(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<CvarArgument>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_no_such_local_variable(ErrorLevel level, Loc *loc, BytePtr var_name)
{
    diagnostic_message_variant_t message = std::make_unique<NoSuchLocalVariable>(byte_ptr_to_owned_string(var_name));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ordinary_param_defined(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<OrdinaryParamDefined>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_numparam_used(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<NumparamUsed>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_tok_at_eol_without_expression(ErrorLevel level, Loc *loc, BytePtr token_name)
{
    diagnostic_message_variant_t message = std::make_unique<TokAtEolWithoutExpression>(byte_ptr_to_owned_string(token_name));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_end_in_method(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<EndInMethod>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_comparison_after_comparison(ErrorLevel level, Loc *loc, BytePtr comparison)
{
    diagnostic_message_variant_t message = std::make_unique<ComparisonAfterComparison>(byte_ptr_to_owned_string(comparison));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_circular_argument_reference(ErrorLevel level, Loc *loc, BytePtr arg_name)
{
    diagnostic_message_variant_t message = std::make_unique<CircularArgumentReference>(byte_ptr_to_owned_string(arg_name));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_dynamic_constant_assignment(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<DynamicConstantAssignment>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_self(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<CantAssignToSelf>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_nil(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<CantAssignToNil>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_true(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<CantAssignToTrue>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_false(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<CantAssignToFalse>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_file(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<CantAssignToFile>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_line(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<CantAssignToLine>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_encoding(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<CantAssignToEncoding>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_numparam(ErrorLevel level, Loc *loc, BytePtr numparam)
{
    diagnostic_message_variant_t message = std::make_unique<CantAssignToNumparam>(byte_ptr_to_owned_string(numparam));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_set_variable(ErrorLevel level, Loc *loc, BytePtr var_name)
{
    diagnostic_message_variant_t message = std::make_unique<CantSetVariable>(byte_ptr_to_owned_string(var_name));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_block_given_to_yield(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<BlockGivenToYield>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_block_and_block_arg_given(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<BlockAndBlockArgGiven>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_symbol_literal_with_interpolation(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<SymbolLiteralWithInterpolation>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_reserved_for_numparam(ErrorLevel level, Loc *loc, BytePtr numparam)
{
    diagnostic_message_variant_t message = std::make_unique<ReservedForNumparam>(byte_ptr_to_owned_string(numparam));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_key_must_be_valid_as_local_variable(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<KeyMustBeValidAsLocalVariable>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_duplicate_variable_name(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<DuplicateVariableName>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_duplicate_key_name(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<DuplicateKeyName>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_singleton_literal(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<SingletonLiteral>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_nth_ref_is_too_big(ErrorLevel level, Loc *loc, BytePtr nth_ref)
{
    diagnostic_message_variant_t message = std::make_unique<NthRefIsTooBig>(byte_ptr_to_owned_string(nth_ref));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_duplicated_argument_name(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<DuplicatedArgumentName>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_regex_error(ErrorLevel level, Loc *loc, BytePtr error)
{
    diagnostic_message_variant_t message = std::make_unique<RegexError>(byte_ptr_to_owned_string(error));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_symbol(ErrorLevel level, Loc *loc, BytePtr symbol)
{
    diagnostic_message_variant_t message = std::make_unique<InvalidSymbol>(byte_ptr_to_owned_string(symbol));
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}
Diagnostic *make_void_value_expression(ErrorLevel level, Loc *loc)
{
    diagnostic_message_variant_t message = std::make_unique<VoidValueExpression>();
    return new Diagnostic(level, std::move(message), std::unique_ptr<Loc>(loc));
}

}
