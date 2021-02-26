#include "make.h"
#include "variant.h"
#include "../../message.h"
#include "../../loc.h"
#include "../../diagnostic.h"

namespace lib_ruby_parser {

Diagnostic *make_fraction_after_numeric(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<FractionAfterNumeric>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_no_digits_after_dot(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<NoDigitsAfterDot>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unknown_type_of_percent_string(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<UnknownTypeOfPercentString>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_numeric_literal_without_digits(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<NumericLiteralWithoutDigits>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_list(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<UnterminatedList>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_regexp(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<UnterminatedRegexp>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_string(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<UnterminatedString>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_quoted_string(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<UnterminatedQuotedString>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_unicode_escape(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<InvalidUnicodeEscape>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_too_large_unicode_codepoint(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<TooLargeUnicodeCodepoint>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_unicode_codepoint(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<InvalidUnicodeCodepoint>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_multiple_codepoint_at_single_char(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<MultipleCodepointAtSingleChar>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_escape_character(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<InvalidEscapeCharacter>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_hex_escape(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<InvalidHexEscape>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_heredoc(ErrorLevel level, Loc *loc, BytePtr heredoc_id)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<UnterminatedHeredoc>(byte_ptr_to_owned_string(heredoc_id))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_heredoc_id(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<UnterminatedHeredocId>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_slash_r_at_middle_of_line(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<SlashRAtMiddleOfLine>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_d_star_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<DStarInterpretedAsArgPrefix>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_star_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<StarInterpretedAsArgPrefix>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ampersand_interpreted_as_arg_prefix(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<AmpersandInterpretedAsArgPrefix>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_triple_dot_at_eol(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<TripleDotAtEol>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_parentheses_iterpreted_as_arglist(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<ParenthesesIterpretedAsArglist>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ambiguous_first_argument(ErrorLevel level, Loc *loc, char operator_)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<AmbiguousFirstArgument>(operator_)),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ambiguous_operator(ErrorLevel level, Loc *loc, BytePtr operator_, BytePtr interpreted_as)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<AmbiguousOperator>(byte_ptr_to_owned_string(operator_), byte_ptr_to_owned_string(interpreted_as))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_character_syntax(ErrorLevel level, Loc *loc, BytePtr suggestion)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<InvalidCharacterSyntax>(byte_ptr_to_owned_string(suggestion))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_octal_digit(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<InvalidOctalDigit>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_trailing_char_in_number(ErrorLevel level, Loc *loc, char c)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<TrailingCharInNumber>(c)),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_embedded_document_meets_eof(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<EmbeddedDocumentMeetsEof>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_char(ErrorLevel level, Loc *loc, char c)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<InvalidChar>(c)),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_incomplete_character_syntax(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<IncompleteCharacterSyntax>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_gvar_without_id(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<GvarWithoutId>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_gvar_name(ErrorLevel level, Loc *loc, char c)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<InvalidGvarName>(c)),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ivar_without_id(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<IvarWithoutId>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_ivar_name(ErrorLevel level, Loc *loc, char c)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<InvalidIvarName>(c)),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cvar_without_id(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<CvarWithoutId>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_cvar_name(ErrorLevel level, Loc *loc, char c)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<InvalidCvarName>(c)),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unknown_regex_options(ErrorLevel level, Loc *loc, BytePtr options)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<UnknownRegexOptions>(byte_ptr_to_owned_string(options))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unterminated_unicode_escape(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<UnterminatedUnicodeEscape>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_encoding_error(ErrorLevel level, Loc *loc, BytePtr error)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<EncodingError>(byte_ptr_to_owned_string(error))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ambiguous_ternary_operator(ErrorLevel level, Loc *loc, BytePtr condition)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<AmbiguousTernaryOperator>(byte_ptr_to_owned_string(condition))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ambiguous_regexp(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<AmbiguousRegexp>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_else_without_rescue(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<ElseWithoutRescue>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_begin_not_at_top_level(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<BeginNotAtTopLevel>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_alias_nth_ref(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<AliasNthRef>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_csend_inside_masgn(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<CsendInsideMasgn>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_class_or_module_name_must_be_constant(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<ClassOrModuleNameMustBeConstant>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_endless_setter_definition(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<EndlessSetterDefinition>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_unexpected_token(ErrorLevel level, Loc *loc, BytePtr token_name)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<UnexpectedToken>(byte_ptr_to_owned_string(token_name))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_class_definition_in_method_body(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<ClassDefinitionInMethodBody>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_module_definition_in_method_body(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<ModuleDefinitionInMethodBody>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_return_in_class_or_module_body(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<InvalidReturnInClassOrModuleBody>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_const_argument(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<ConstArgument>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ivar_argument(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<IvarArgument>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_gvar_argument(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<GvarArgument>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cvar_argument(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<CvarArgument>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_no_such_local_variable(ErrorLevel level, Loc *loc, BytePtr var_name)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<NoSuchLocalVariable>(byte_ptr_to_owned_string(var_name))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_ordinary_param_defined(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<OrdinaryParamDefined>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_numparam_used(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<NumparamUsed>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_tok_at_eol_without_expression(ErrorLevel level, Loc *loc, BytePtr token_name)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<TokAtEolWithoutExpression>(byte_ptr_to_owned_string(token_name))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_end_in_method(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<EndInMethod>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_comparison_after_comparison(ErrorLevel level, Loc *loc, BytePtr comparison)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<ComparisonAfterComparison>(byte_ptr_to_owned_string(comparison))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_circular_argument_reference(ErrorLevel level, Loc *loc, BytePtr arg_name)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<CircularArgumentReference>(byte_ptr_to_owned_string(arg_name))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_dynamic_constant_assignment(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<DynamicConstantAssignment>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_self(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<CantAssignToSelf>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_nil(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<CantAssignToNil>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_true(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<CantAssignToTrue>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_false(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<CantAssignToFalse>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_file(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<CantAssignToFile>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_line(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<CantAssignToLine>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_encoding(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<CantAssignToEncoding>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_assign_to_numparam(ErrorLevel level, Loc *loc, BytePtr numparam)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<CantAssignToNumparam>(byte_ptr_to_owned_string(numparam))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_cant_set_variable(ErrorLevel level, Loc *loc, BytePtr var_name)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<CantSetVariable>(byte_ptr_to_owned_string(var_name))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_block_given_to_yield(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<BlockGivenToYield>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_block_and_block_arg_given(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<BlockAndBlockArgGiven>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_symbol_literal_with_interpolation(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<SymbolLiteralWithInterpolation>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_reserved_for_numparam(ErrorLevel level, Loc *loc, BytePtr numparam)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<ReservedForNumparam>(byte_ptr_to_owned_string(numparam))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_key_must_be_valid_as_local_variable(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<KeyMustBeValidAsLocalVariable>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_duplicate_variable_name(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<DuplicateVariableName>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_duplicate_key_name(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<DuplicateKeyName>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_singleton_literal(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<SingletonLiteral>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_nth_ref_is_too_big(ErrorLevel level, Loc *loc, BytePtr nth_ref)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<NthRefIsTooBig>(byte_ptr_to_owned_string(nth_ref))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_duplicated_argument_name(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<DuplicatedArgumentName>()),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_regex_error(ErrorLevel level, Loc *loc, BytePtr error)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<RegexError>(byte_ptr_to_owned_string(error))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_invalid_symbol(ErrorLevel level, Loc *loc, BytePtr symbol)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<InvalidSymbol>(byte_ptr_to_owned_string(symbol))),
        std::unique_ptr<Loc>(loc));
}
Diagnostic *make_void_value_expression(ErrorLevel level, Loc *loc)
{
    return new Diagnostic(
        level,
        std::make_unique<DiagnosticMessage>(std::make_unique<VoidValueExpression>()),
        std::unique_ptr<Loc>(loc));
}

}
