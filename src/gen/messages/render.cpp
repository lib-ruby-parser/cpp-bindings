#include "render.h"
#include "../../diagnostic.h"
#include "../../message.h"

namespace lib_ruby_parser {

extern "C" {

BytePtr render_message_diagnostic(Diagnostic *diagnostic)
{
    return std::visit([diagnostic](auto &&message) {
        using MessageT = std::decay_t<decltype(message)>;

        if constexpr (std::is_same_v<MessageT, std::unique_ptr<FractionAfterNumeric>>) {
            return render_message_fraction_after_numeric(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<NoDigitsAfterDot>>) {
            return render_message_no_digits_after_dot(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnknownTypeOfPercentString>>) {
            return render_message_unknown_type_of_percent_string(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<NumericLiteralWithoutDigits>>) {
            return render_message_numeric_literal_without_digits(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedList>>) {
            return render_message_unterminated_list(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedRegexp>>) {
            return render_message_unterminated_regexp(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedString>>) {
            return render_message_unterminated_string(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedQuotedString>>) {
            return render_message_unterminated_quoted_string(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidUnicodeEscape>>) {
            return render_message_invalid_unicode_escape(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<TooLargeUnicodeCodepoint>>) {
            return render_message_too_large_unicode_codepoint(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidUnicodeCodepoint>>) {
            return render_message_invalid_unicode_codepoint(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<MultipleCodepointAtSingleChar>>) {
            return render_message_multiple_codepoint_at_single_char(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidEscapeCharacter>>) {
            return render_message_invalid_escape_character(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidHexEscape>>) {
            return render_message_invalid_hex_escape(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedHeredoc>>) {
            return render_message_unterminated_heredoc(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->heredoc_id.c_str(), message->heredoc_id.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedHeredocId>>) {
            return render_message_unterminated_heredoc_id(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<SlashRAtMiddleOfLine>>) {
            return render_message_slash_r_at_middle_of_line(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<DStarInterpretedAsArgPrefix>>) {
            return render_message_d_star_interpreted_as_arg_prefix(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<StarInterpretedAsArgPrefix>>) {
            return render_message_star_interpreted_as_arg_prefix(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<AmpersandInterpretedAsArgPrefix>>) {
            return render_message_ampersand_interpreted_as_arg_prefix(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<TripleDotAtEol>>) {
            return render_message_triple_dot_at_eol(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ParenthesesIterpretedAsArglist>>) {
            return render_message_parentheses_iterpreted_as_arglist(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<AmbiguousFirstArgument>>) {
            return render_message_ambiguous_first_argument(diagnostic->level, diagnostic->loc.get(), message->operator_);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<AmbiguousOperator>>) {
            return render_message_ambiguous_operator(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->operator_.c_str(), message->operator_.length()), make_byte_ptr(message->interpreted_as.c_str(), message->interpreted_as.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidCharacterSyntax>>) {
            return render_message_invalid_character_syntax(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->suggestion.c_str(), message->suggestion.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidOctalDigit>>) {
            return render_message_invalid_octal_digit(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<TrailingCharInNumber>>) {
            return render_message_trailing_char_in_number(diagnostic->level, diagnostic->loc.get(), message->c);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<EmbeddedDocumentMeetsEof>>) {
            return render_message_embedded_document_meets_eof(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidChar>>) {
            return render_message_invalid_char(diagnostic->level, diagnostic->loc.get(), message->c);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<IncompleteCharacterSyntax>>) {
            return render_message_incomplete_character_syntax(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<GvarWithoutId>>) {
            return render_message_gvar_without_id(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidGvarName>>) {
            return render_message_invalid_gvar_name(diagnostic->level, diagnostic->loc.get(), message->c);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<IvarWithoutId>>) {
            return render_message_ivar_without_id(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidIvarName>>) {
            return render_message_invalid_ivar_name(diagnostic->level, diagnostic->loc.get(), message->c);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CvarWithoutId>>) {
            return render_message_cvar_without_id(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidCvarName>>) {
            return render_message_invalid_cvar_name(diagnostic->level, diagnostic->loc.get(), message->c);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnknownRegexOptions>>) {
            return render_message_unknown_regex_options(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->options.c_str(), message->options.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedUnicodeEscape>>) {
            return render_message_unterminated_unicode_escape(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<EncodingError>>) {
            return render_message_encoding_error(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->error.c_str(), message->error.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidMultibyteChar>>) {
            return render_message_invalid_multibyte_char(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<AmbiguousTernaryOperator>>) {
            return render_message_ambiguous_ternary_operator(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->condition.c_str(), message->condition.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<AmbiguousRegexp>>) {
            return render_message_ambiguous_regexp(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ElseWithoutRescue>>) {
            return render_message_else_without_rescue(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<BeginNotAtTopLevel>>) {
            return render_message_begin_not_at_top_level(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<AliasNthRef>>) {
            return render_message_alias_nth_ref(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CsendInsideMasgn>>) {
            return render_message_csend_inside_masgn(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ClassOrModuleNameMustBeConstant>>) {
            return render_message_class_or_module_name_must_be_constant(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<EndlessSetterDefinition>>) {
            return render_message_endless_setter_definition(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnexpectedToken>>) {
            return render_message_unexpected_token(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->token_name.c_str(), message->token_name.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ClassDefinitionInMethodBody>>) {
            return render_message_class_definition_in_method_body(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ModuleDefinitionInMethodBody>>) {
            return render_message_module_definition_in_method_body(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidReturnInClassOrModuleBody>>) {
            return render_message_invalid_return_in_class_or_module_body(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ConstArgument>>) {
            return render_message_const_argument(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<IvarArgument>>) {
            return render_message_ivar_argument(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<GvarArgument>>) {
            return render_message_gvar_argument(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CvarArgument>>) {
            return render_message_cvar_argument(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<NoSuchLocalVariable>>) {
            return render_message_no_such_local_variable(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->var_name.c_str(), message->var_name.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<OrdinaryParamDefined>>) {
            return render_message_ordinary_param_defined(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<NumparamUsed>>) {
            return render_message_numparam_used(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<TokAtEolWithoutExpression>>) {
            return render_message_tok_at_eol_without_expression(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->token_name.c_str(), message->token_name.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<EndInMethod>>) {
            return render_message_end_in_method(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ComparisonAfterComparison>>) {
            return render_message_comparison_after_comparison(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->comparison.c_str(), message->comparison.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CircularArgumentReference>>) {
            return render_message_circular_argument_reference(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->arg_name.c_str(), message->arg_name.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<DynamicConstantAssignment>>) {
            return render_message_dynamic_constant_assignment(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToSelf>>) {
            return render_message_cant_assign_to_self(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToNil>>) {
            return render_message_cant_assign_to_nil(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToTrue>>) {
            return render_message_cant_assign_to_true(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToFalse>>) {
            return render_message_cant_assign_to_false(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToFile>>) {
            return render_message_cant_assign_to_file(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToLine>>) {
            return render_message_cant_assign_to_line(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToEncoding>>) {
            return render_message_cant_assign_to_encoding(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToNumparam>>) {
            return render_message_cant_assign_to_numparam(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->numparam.c_str(), message->numparam.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantSetVariable>>) {
            return render_message_cant_set_variable(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->var_name.c_str(), message->var_name.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<BlockGivenToYield>>) {
            return render_message_block_given_to_yield(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<BlockAndBlockArgGiven>>) {
            return render_message_block_and_block_arg_given(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<SymbolLiteralWithInterpolation>>) {
            return render_message_symbol_literal_with_interpolation(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ReservedForNumparam>>) {
            return render_message_reserved_for_numparam(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->numparam.c_str(), message->numparam.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<KeyMustBeValidAsLocalVariable>>) {
            return render_message_key_must_be_valid_as_local_variable(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<DuplicateVariableName>>) {
            return render_message_duplicate_variable_name(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<DuplicateKeyName>>) {
            return render_message_duplicate_key_name(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<SingletonLiteral>>) {
            return render_message_singleton_literal(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<NthRefIsTooBig>>) {
            return render_message_nth_ref_is_too_big(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->nth_ref.c_str(), message->nth_ref.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<DuplicatedArgumentName>>) {
            return render_message_duplicated_argument_name(diagnostic->level, diagnostic->loc.get());
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<RegexError>>) {
            return render_message_regex_error(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->error.c_str(), message->error.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidSymbol>>) {
            return render_message_invalid_symbol(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->symbol.c_str(), message->symbol.length()));
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<VoidValueExpression>>) {
            return render_message_void_value_expression(diagnostic->level, diagnostic->loc.get());
        }
    }, diagnostic->message->variant);
}

BytePtr render_diagnostic(Diagnostic *diagnostic, BytePtr input)
{
    return std::visit([diagnostic, input](auto &&message) {
        using MessageT = std::decay_t<decltype(message)>;

        if constexpr (std::is_same_v<MessageT, std::unique_ptr<FractionAfterNumeric>>) {
            return render_fraction_after_numeric(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<NoDigitsAfterDot>>) {
            return render_no_digits_after_dot(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnknownTypeOfPercentString>>) {
            return render_unknown_type_of_percent_string(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<NumericLiteralWithoutDigits>>) {
            return render_numeric_literal_without_digits(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedList>>) {
            return render_unterminated_list(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedRegexp>>) {
            return render_unterminated_regexp(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedString>>) {
            return render_unterminated_string(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedQuotedString>>) {
            return render_unterminated_quoted_string(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidUnicodeEscape>>) {
            return render_invalid_unicode_escape(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<TooLargeUnicodeCodepoint>>) {
            return render_too_large_unicode_codepoint(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidUnicodeCodepoint>>) {
            return render_invalid_unicode_codepoint(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<MultipleCodepointAtSingleChar>>) {
            return render_multiple_codepoint_at_single_char(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidEscapeCharacter>>) {
            return render_invalid_escape_character(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidHexEscape>>) {
            return render_invalid_hex_escape(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedHeredoc>>) {
            return render_unterminated_heredoc(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->heredoc_id.c_str(), message->heredoc_id.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedHeredocId>>) {
            return render_unterminated_heredoc_id(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<SlashRAtMiddleOfLine>>) {
            return render_slash_r_at_middle_of_line(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<DStarInterpretedAsArgPrefix>>) {
            return render_d_star_interpreted_as_arg_prefix(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<StarInterpretedAsArgPrefix>>) {
            return render_star_interpreted_as_arg_prefix(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<AmpersandInterpretedAsArgPrefix>>) {
            return render_ampersand_interpreted_as_arg_prefix(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<TripleDotAtEol>>) {
            return render_triple_dot_at_eol(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ParenthesesIterpretedAsArglist>>) {
            return render_parentheses_iterpreted_as_arglist(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<AmbiguousFirstArgument>>) {
            return render_ambiguous_first_argument(diagnostic->level, diagnostic->loc.get(), message->operator_, input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<AmbiguousOperator>>) {
            return render_ambiguous_operator(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->operator_.c_str(), message->operator_.length()), make_byte_ptr(message->interpreted_as.c_str(), message->interpreted_as.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidCharacterSyntax>>) {
            return render_invalid_character_syntax(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->suggestion.c_str(), message->suggestion.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidOctalDigit>>) {
            return render_invalid_octal_digit(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<TrailingCharInNumber>>) {
            return render_trailing_char_in_number(diagnostic->level, diagnostic->loc.get(), message->c, input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<EmbeddedDocumentMeetsEof>>) {
            return render_embedded_document_meets_eof(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidChar>>) {
            return render_invalid_char(diagnostic->level, diagnostic->loc.get(), message->c, input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<IncompleteCharacterSyntax>>) {
            return render_incomplete_character_syntax(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<GvarWithoutId>>) {
            return render_gvar_without_id(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidGvarName>>) {
            return render_invalid_gvar_name(diagnostic->level, diagnostic->loc.get(), message->c, input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<IvarWithoutId>>) {
            return render_ivar_without_id(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidIvarName>>) {
            return render_invalid_ivar_name(diagnostic->level, diagnostic->loc.get(), message->c, input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CvarWithoutId>>) {
            return render_cvar_without_id(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidCvarName>>) {
            return render_invalid_cvar_name(diagnostic->level, diagnostic->loc.get(), message->c, input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnknownRegexOptions>>) {
            return render_unknown_regex_options(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->options.c_str(), message->options.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnterminatedUnicodeEscape>>) {
            return render_unterminated_unicode_escape(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<EncodingError>>) {
            return render_encoding_error(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->error.c_str(), message->error.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidMultibyteChar>>) {
            return render_invalid_multibyte_char(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<AmbiguousTernaryOperator>>) {
            return render_ambiguous_ternary_operator(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->condition.c_str(), message->condition.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<AmbiguousRegexp>>) {
            return render_ambiguous_regexp(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ElseWithoutRescue>>) {
            return render_else_without_rescue(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<BeginNotAtTopLevel>>) {
            return render_begin_not_at_top_level(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<AliasNthRef>>) {
            return render_alias_nth_ref(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CsendInsideMasgn>>) {
            return render_csend_inside_masgn(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ClassOrModuleNameMustBeConstant>>) {
            return render_class_or_module_name_must_be_constant(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<EndlessSetterDefinition>>) {
            return render_endless_setter_definition(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<UnexpectedToken>>) {
            return render_unexpected_token(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->token_name.c_str(), message->token_name.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ClassDefinitionInMethodBody>>) {
            return render_class_definition_in_method_body(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ModuleDefinitionInMethodBody>>) {
            return render_module_definition_in_method_body(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidReturnInClassOrModuleBody>>) {
            return render_invalid_return_in_class_or_module_body(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ConstArgument>>) {
            return render_const_argument(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<IvarArgument>>) {
            return render_ivar_argument(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<GvarArgument>>) {
            return render_gvar_argument(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CvarArgument>>) {
            return render_cvar_argument(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<NoSuchLocalVariable>>) {
            return render_no_such_local_variable(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->var_name.c_str(), message->var_name.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<OrdinaryParamDefined>>) {
            return render_ordinary_param_defined(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<NumparamUsed>>) {
            return render_numparam_used(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<TokAtEolWithoutExpression>>) {
            return render_tok_at_eol_without_expression(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->token_name.c_str(), message->token_name.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<EndInMethod>>) {
            return render_end_in_method(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ComparisonAfterComparison>>) {
            return render_comparison_after_comparison(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->comparison.c_str(), message->comparison.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CircularArgumentReference>>) {
            return render_circular_argument_reference(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->arg_name.c_str(), message->arg_name.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<DynamicConstantAssignment>>) {
            return render_dynamic_constant_assignment(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToSelf>>) {
            return render_cant_assign_to_self(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToNil>>) {
            return render_cant_assign_to_nil(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToTrue>>) {
            return render_cant_assign_to_true(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToFalse>>) {
            return render_cant_assign_to_false(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToFile>>) {
            return render_cant_assign_to_file(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToLine>>) {
            return render_cant_assign_to_line(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToEncoding>>) {
            return render_cant_assign_to_encoding(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantAssignToNumparam>>) {
            return render_cant_assign_to_numparam(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->numparam.c_str(), message->numparam.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<CantSetVariable>>) {
            return render_cant_set_variable(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->var_name.c_str(), message->var_name.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<BlockGivenToYield>>) {
            return render_block_given_to_yield(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<BlockAndBlockArgGiven>>) {
            return render_block_and_block_arg_given(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<SymbolLiteralWithInterpolation>>) {
            return render_symbol_literal_with_interpolation(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<ReservedForNumparam>>) {
            return render_reserved_for_numparam(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->numparam.c_str(), message->numparam.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<KeyMustBeValidAsLocalVariable>>) {
            return render_key_must_be_valid_as_local_variable(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<DuplicateVariableName>>) {
            return render_duplicate_variable_name(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<DuplicateKeyName>>) {
            return render_duplicate_key_name(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<SingletonLiteral>>) {
            return render_singleton_literal(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<NthRefIsTooBig>>) {
            return render_nth_ref_is_too_big(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->nth_ref.c_str(), message->nth_ref.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<DuplicatedArgumentName>>) {
            return render_duplicated_argument_name(diagnostic->level, diagnostic->loc.get(), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<RegexError>>) {
            return render_regex_error(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->error.c_str(), message->error.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<InvalidSymbol>>) {
            return render_invalid_symbol(diagnostic->level, diagnostic->loc.get(), make_byte_ptr(message->symbol.c_str(), message->symbol.length()), input);
        }
        if constexpr (std::is_same_v<MessageT, std::unique_ptr<VoidValueExpression>>) {
            return render_void_value_expression(diagnostic->level, diagnostic->loc.get(), input);
        }
    }, diagnostic->message->variant);
}

}

}
