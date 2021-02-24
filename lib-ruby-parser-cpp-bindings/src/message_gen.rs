use crate::bindings;
use crate::Ptr;
use crate::BytePtr;

impl From<lib_ruby_parser::Diagnostic> for Ptr<bindings::Diagnostic> {
    fn from(diagnostic: lib_ruby_parser::Diagnostic) -> Self {
        let lib_ruby_parser::Diagnostic { message, level, loc } = diagnostic;
        let level = bindings::ErrorLevel::from(&level);
        let loc = Ptr::<bindings::Loc>::from(loc).unwrap();

        let ptr = match message {
            lib_ruby_parser::DiagnosticMessage::FractionAfterNumeric {  } => {
                unsafe { bindings::make_fraction_after_numeric(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::NoDigitsAfterDot {  } => {
                unsafe { bindings::make_no_digits_after_dot(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::UnknownTypeOfPercentString {  } => {
                unsafe { bindings::make_unknown_type_of_percent_string(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::NumericLiteralWithoutDigits {  } => {
                unsafe { bindings::make_numeric_literal_without_digits(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedList {  } => {
                unsafe { bindings::make_unterminated_list(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedRegexp {  } => {
                unsafe { bindings::make_unterminated_regexp(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedString {  } => {
                unsafe { bindings::make_unterminated_string(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedQuotedString {  } => {
                unsafe { bindings::make_unterminated_quoted_string(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidUnicodeEscape {  } => {
                unsafe { bindings::make_invalid_unicode_escape(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::TooLargeUnicodeCodepoint {  } => {
                unsafe { bindings::make_too_large_unicode_codepoint(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidUnicodeCodepoint {  } => {
                unsafe { bindings::make_invalid_unicode_codepoint(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::MultipleCodepointAtSingleChar {  } => {
                unsafe { bindings::make_multiple_codepoint_at_single_char(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidEscapeCharacter {  } => {
                unsafe { bindings::make_invalid_escape_character(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidHexEscape {  } => {
                unsafe { bindings::make_invalid_hex_escape(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedHeredoc { heredoc_id } => {
                let heredoc_id = BytePtr::from(heredoc_id);
                unsafe { bindings::make_unterminated_heredoc(level, loc, heredoc_id) }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedHeredocId {  } => {
                unsafe { bindings::make_unterminated_heredoc_id(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::SlashRAtMiddleOfLine {  } => {
                unsafe { bindings::make_slash_r_at_middle_of_line(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::DStarInterpretedAsArgPrefix {  } => {
                unsafe { bindings::make_d_star_interpreted_as_arg_prefix(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::StarInterpretedAsArgPrefix {  } => {
                unsafe { bindings::make_star_interpreted_as_arg_prefix(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::AmpersandInterpretedAsArgPrefix {  } => {
                unsafe { bindings::make_ampersand_interpreted_as_arg_prefix(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::TripleDotAtEol {  } => {
                unsafe { bindings::make_triple_dot_at_eol(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::ParenthesesIterpretedAsArglist {  } => {
                unsafe { bindings::make_parentheses_iterpreted_as_arglist(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::AmbiguousFirstArgument { operator } => {
                let operator = operator as i8;
                unsafe { bindings::make_ambiguous_first_argument(level, loc, operator) }
            },
            lib_ruby_parser::DiagnosticMessage::AmbiguousOperator { operator, interpreted_as } => {
                let operator = BytePtr::from(operator);
                let interpreted_as = BytePtr::from(interpreted_as);
                unsafe { bindings::make_ambiguous_operator(level, loc, operator, interpreted_as) }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidCharacterSyntax { suggestion } => {
                let suggestion = BytePtr::from(suggestion);
                unsafe { bindings::make_invalid_character_syntax(level, loc, suggestion) }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidOctalDigit {  } => {
                unsafe { bindings::make_invalid_octal_digit(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::TrailingCharInNumber { c } => {
                let c = c as i8;
                unsafe { bindings::make_trailing_char_in_number(level, loc, c) }
            },
            lib_ruby_parser::DiagnosticMessage::EmbeddedDocumentMeetsEof {  } => {
                unsafe { bindings::make_embedded_document_meets_eof(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidChar { c } => {
                let c = c as i8;
                unsafe { bindings::make_invalid_char(level, loc, c) }
            },
            lib_ruby_parser::DiagnosticMessage::IncompleteCharacterSyntax {  } => {
                unsafe { bindings::make_incomplete_character_syntax(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::GvarWithoutId {  } => {
                unsafe { bindings::make_gvar_without_id(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidGvarName { c } => {
                let c = c as i8;
                unsafe { bindings::make_invalid_gvar_name(level, loc, c) }
            },
            lib_ruby_parser::DiagnosticMessage::IvarWithoutId {  } => {
                unsafe { bindings::make_ivar_without_id(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidIvarName { c } => {
                let c = c as i8;
                unsafe { bindings::make_invalid_ivar_name(level, loc, c) }
            },
            lib_ruby_parser::DiagnosticMessage::CvarWithoutId {  } => {
                unsafe { bindings::make_cvar_without_id(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidCvarName { c } => {
                let c = c as i8;
                unsafe { bindings::make_invalid_cvar_name(level, loc, c) }
            },
            lib_ruby_parser::DiagnosticMessage::UnknownRegexOptions { options } => {
                let options = BytePtr::from(options);
                unsafe { bindings::make_unknown_regex_options(level, loc, options) }
            },
            lib_ruby_parser::DiagnosticMessage::UnterminatedUnicodeEscape {  } => {
                unsafe { bindings::make_unterminated_unicode_escape(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::EncodingError { error } => {
                let error = BytePtr::from(error);
                unsafe { bindings::make_encoding_error(level, loc, error) }
            },
            lib_ruby_parser::DiagnosticMessage::AmbiguousTernaryOperator { condition } => {
                let condition = BytePtr::from(condition);
                unsafe { bindings::make_ambiguous_ternary_operator(level, loc, condition) }
            },
            lib_ruby_parser::DiagnosticMessage::AmbiguousRegexp {  } => {
                unsafe { bindings::make_ambiguous_regexp(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::ElseWithoutRescue {  } => {
                unsafe { bindings::make_else_without_rescue(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::BeginNotAtTopLevel {  } => {
                unsafe { bindings::make_begin_not_at_top_level(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::AliasNthRef {  } => {
                unsafe { bindings::make_alias_nth_ref(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::CsendInsideMasgn {  } => {
                unsafe { bindings::make_csend_inside_masgn(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::ClassOrModuleNameMustBeConstant {  } => {
                unsafe { bindings::make_class_or_module_name_must_be_constant(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::EndlessSetterDefinition {  } => {
                unsafe { bindings::make_endless_setter_definition(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::UnexpectedToken { token_name } => {
                let token_name = BytePtr::from(token_name);
                unsafe { bindings::make_unexpected_token(level, loc, token_name) }
            },
            lib_ruby_parser::DiagnosticMessage::ClassDefinitionInMethodBody {  } => {
                unsafe { bindings::make_class_definition_in_method_body(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::ModuleDefinitionInMethodBody {  } => {
                unsafe { bindings::make_module_definition_in_method_body(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidReturnInClassOrModuleBody {  } => {
                unsafe { bindings::make_invalid_return_in_class_or_module_body(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::ConstArgument {  } => {
                unsafe { bindings::make_const_argument(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::IvarArgument {  } => {
                unsafe { bindings::make_ivar_argument(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::GvarArgument {  } => {
                unsafe { bindings::make_gvar_argument(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::CvarArgument {  } => {
                unsafe { bindings::make_cvar_argument(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::NoSuchLocalVariable { var_name } => {
                let var_name = BytePtr::from(var_name);
                unsafe { bindings::make_no_such_local_variable(level, loc, var_name) }
            },
            lib_ruby_parser::DiagnosticMessage::OrdinaryParamDefined {  } => {
                unsafe { bindings::make_ordinary_param_defined(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::NumparamUsed {  } => {
                unsafe { bindings::make_numparam_used(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::TokAtEolWithoutExpression { token_name } => {
                let token_name = BytePtr::from(token_name);
                unsafe { bindings::make_tok_at_eol_without_expression(level, loc, token_name) }
            },
            lib_ruby_parser::DiagnosticMessage::EndInMethod {  } => {
                unsafe { bindings::make_end_in_method(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::ComparisonAfterComparison { comparison } => {
                let comparison = BytePtr::from(comparison);
                unsafe { bindings::make_comparison_after_comparison(level, loc, comparison) }
            },
            lib_ruby_parser::DiagnosticMessage::CircularArgumentReference { arg_name } => {
                let arg_name = BytePtr::from(arg_name);
                unsafe { bindings::make_circular_argument_reference(level, loc, arg_name) }
            },
            lib_ruby_parser::DiagnosticMessage::DynamicConstantAssignment {  } => {
                unsafe { bindings::make_dynamic_constant_assignment(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToSelf {  } => {
                unsafe { bindings::make_cant_assign_to_self(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToNil {  } => {
                unsafe { bindings::make_cant_assign_to_nil(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToTrue {  } => {
                unsafe { bindings::make_cant_assign_to_true(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToFalse {  } => {
                unsafe { bindings::make_cant_assign_to_false(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToFile {  } => {
                unsafe { bindings::make_cant_assign_to_file(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToLine {  } => {
                unsafe { bindings::make_cant_assign_to_line(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToEncoding {  } => {
                unsafe { bindings::make_cant_assign_to_encoding(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::CantAssignToNumparam { numparam } => {
                let numparam = BytePtr::from(numparam);
                unsafe { bindings::make_cant_assign_to_numparam(level, loc, numparam) }
            },
            lib_ruby_parser::DiagnosticMessage::CantSetVariable { var_name } => {
                let var_name = BytePtr::from(var_name);
                unsafe { bindings::make_cant_set_variable(level, loc, var_name) }
            },
            lib_ruby_parser::DiagnosticMessage::BlockGivenToYield {  } => {
                unsafe { bindings::make_block_given_to_yield(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::BlockAndBlockArgGiven {  } => {
                unsafe { bindings::make_block_and_block_arg_given(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::SymbolLiteralWithInterpolation {  } => {
                unsafe { bindings::make_symbol_literal_with_interpolation(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::ReservedForNumparam { numparam } => {
                let numparam = BytePtr::from(numparam);
                unsafe { bindings::make_reserved_for_numparam(level, loc, numparam) }
            },
            lib_ruby_parser::DiagnosticMessage::KeyMustBeValidAsLocalVariable {  } => {
                unsafe { bindings::make_key_must_be_valid_as_local_variable(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::DuplicateVariableName {  } => {
                unsafe { bindings::make_duplicate_variable_name(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::DuplicateKeyName {  } => {
                unsafe { bindings::make_duplicate_key_name(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::SingletonLiteral {  } => {
                unsafe { bindings::make_singleton_literal(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::NthRefIsTooBig { nth_ref } => {
                let nth_ref = BytePtr::from(nth_ref);
                unsafe { bindings::make_nth_ref_is_too_big(level, loc, nth_ref) }
            },
            lib_ruby_parser::DiagnosticMessage::DuplicatedArgumentName {  } => {
                unsafe { bindings::make_duplicated_argument_name(level, loc, ) }
            },
            lib_ruby_parser::DiagnosticMessage::RegexError { error } => {
                let error = BytePtr::from(error);
                unsafe { bindings::make_regex_error(level, loc, error) }
            },
            lib_ruby_parser::DiagnosticMessage::InvalidSymbol { symbol } => {
                let symbol = BytePtr::from(symbol);
                unsafe { bindings::make_invalid_symbol(level, loc, symbol) }
            },
            lib_ruby_parser::DiagnosticMessage::VoidValueExpression {  } => {
                unsafe { bindings::make_void_value_expression(level, loc, ) }
            }
        };

        Ptr::new(ptr)
    }
}