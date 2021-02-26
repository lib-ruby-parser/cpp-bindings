use crate::bindings;
use crate::Ptr;
use crate::BytePtr;

#[no_mangle]
pub extern "C" fn render_message_fraction_after_numeric(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::FractionAfterNumeric {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_no_digits_after_dot(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::NoDigitsAfterDot {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_unknown_type_of_percent_string(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::UnknownTypeOfPercentString {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_numeric_literal_without_digits(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::NumericLiteralWithoutDigits {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_unterminated_list(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedList {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_unterminated_regexp(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedRegexp {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_unterminated_string(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedString {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_unterminated_quoted_string(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedQuotedString {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_invalid_unicode_escape(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::InvalidUnicodeEscape {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_too_large_unicode_codepoint(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::TooLargeUnicodeCodepoint {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_invalid_unicode_codepoint(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::InvalidUnicodeCodepoint {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_multiple_codepoint_at_single_char(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::MultipleCodepointAtSingleChar {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_invalid_escape_character(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::InvalidEscapeCharacter {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_invalid_hex_escape(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::InvalidHexEscape {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_unterminated_heredoc(level: bindings::ErrorLevel, loc: *mut bindings::Loc, heredoc_id: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let heredoc_id = heredoc_id.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedHeredoc { heredoc_id };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_unterminated_heredoc_id(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedHeredocId {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_slash_r_at_middle_of_line(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::SlashRAtMiddleOfLine {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_d_star_interpreted_as_arg_prefix(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::DStarInterpretedAsArgPrefix {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_star_interpreted_as_arg_prefix(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::StarInterpretedAsArgPrefix {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_ampersand_interpreted_as_arg_prefix(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::AmpersandInterpretedAsArgPrefix {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_triple_dot_at_eol(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::TripleDotAtEol {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_parentheses_iterpreted_as_arglist(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::ParenthesesIterpretedAsArglist {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_ambiguous_first_argument(level: bindings::ErrorLevel, loc: *mut bindings::Loc, operator: *mut i8) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let operator = operator as u8;
    let message = lib_ruby_parser::DiagnosticMessage::AmbiguousFirstArgument { operator };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_ambiguous_operator(level: bindings::ErrorLevel, loc: *mut bindings::Loc, operator: BytePtr, interpreted_as: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let operator = operator.to_string().unwrap();
    let interpreted_as = interpreted_as.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::AmbiguousOperator { operator, interpreted_as };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_invalid_character_syntax(level: bindings::ErrorLevel, loc: *mut bindings::Loc, suggestion: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let suggestion = suggestion.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::InvalidCharacterSyntax { suggestion };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_invalid_octal_digit(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::InvalidOctalDigit {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_trailing_char_in_number(level: bindings::ErrorLevel, loc: *mut bindings::Loc, c: *mut i8) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let c = c as u8;
    let message = lib_ruby_parser::DiagnosticMessage::TrailingCharInNumber { c };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_embedded_document_meets_eof(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::EmbeddedDocumentMeetsEof {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_invalid_char(level: bindings::ErrorLevel, loc: *mut bindings::Loc, c: *mut i8) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let c = c as u8;
    let message = lib_ruby_parser::DiagnosticMessage::InvalidChar { c };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_incomplete_character_syntax(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::IncompleteCharacterSyntax {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_gvar_without_id(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::GvarWithoutId {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_invalid_gvar_name(level: bindings::ErrorLevel, loc: *mut bindings::Loc, c: *mut i8) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let c = c as u8;
    let message = lib_ruby_parser::DiagnosticMessage::InvalidGvarName { c };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_ivar_without_id(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::IvarWithoutId {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_invalid_ivar_name(level: bindings::ErrorLevel, loc: *mut bindings::Loc, c: *mut i8) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let c = c as u8;
    let message = lib_ruby_parser::DiagnosticMessage::InvalidIvarName { c };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_cvar_without_id(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::CvarWithoutId {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_invalid_cvar_name(level: bindings::ErrorLevel, loc: *mut bindings::Loc, c: *mut i8) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let c = c as u8;
    let message = lib_ruby_parser::DiagnosticMessage::InvalidCvarName { c };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_unknown_regex_options(level: bindings::ErrorLevel, loc: *mut bindings::Loc, options: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let options = options.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::UnknownRegexOptions { options };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_unterminated_unicode_escape(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedUnicodeEscape {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_encoding_error(level: bindings::ErrorLevel, loc: *mut bindings::Loc, error: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let error = error.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::EncodingError { error };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_ambiguous_ternary_operator(level: bindings::ErrorLevel, loc: *mut bindings::Loc, condition: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let condition = condition.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::AmbiguousTernaryOperator { condition };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_ambiguous_regexp(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::AmbiguousRegexp {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_else_without_rescue(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::ElseWithoutRescue {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_begin_not_at_top_level(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::BeginNotAtTopLevel {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_alias_nth_ref(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::AliasNthRef {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_csend_inside_masgn(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::CsendInsideMasgn {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_class_or_module_name_must_be_constant(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::ClassOrModuleNameMustBeConstant {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_endless_setter_definition(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::EndlessSetterDefinition {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_unexpected_token(level: bindings::ErrorLevel, loc: *mut bindings::Loc, token_name: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let token_name = token_name.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::UnexpectedToken { token_name };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_class_definition_in_method_body(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::ClassDefinitionInMethodBody {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_module_definition_in_method_body(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::ModuleDefinitionInMethodBody {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_invalid_return_in_class_or_module_body(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::InvalidReturnInClassOrModuleBody {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_const_argument(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::ConstArgument {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_ivar_argument(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::IvarArgument {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_gvar_argument(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::GvarArgument {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_cvar_argument(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::CvarArgument {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_no_such_local_variable(level: bindings::ErrorLevel, loc: *mut bindings::Loc, var_name: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let var_name = var_name.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::NoSuchLocalVariable { var_name };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_ordinary_param_defined(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::OrdinaryParamDefined {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_numparam_used(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::NumparamUsed {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_tok_at_eol_without_expression(level: bindings::ErrorLevel, loc: *mut bindings::Loc, token_name: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let token_name = token_name.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::TokAtEolWithoutExpression { token_name };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_end_in_method(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::EndInMethod {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_comparison_after_comparison(level: bindings::ErrorLevel, loc: *mut bindings::Loc, comparison: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let comparison = comparison.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::ComparisonAfterComparison { comparison };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_circular_argument_reference(level: bindings::ErrorLevel, loc: *mut bindings::Loc, arg_name: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let arg_name = arg_name.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::CircularArgumentReference { arg_name };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_dynamic_constant_assignment(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::DynamicConstantAssignment {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_cant_assign_to_self(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToSelf {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_cant_assign_to_nil(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToNil {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_cant_assign_to_true(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToTrue {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_cant_assign_to_false(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToFalse {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_cant_assign_to_file(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToFile {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_cant_assign_to_line(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToLine {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_cant_assign_to_encoding(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToEncoding {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_cant_assign_to_numparam(level: bindings::ErrorLevel, loc: *mut bindings::Loc, numparam: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let numparam = numparam.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToNumparam { numparam };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_cant_set_variable(level: bindings::ErrorLevel, loc: *mut bindings::Loc, var_name: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let var_name = var_name.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::CantSetVariable { var_name };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_block_given_to_yield(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::BlockGivenToYield {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_block_and_block_arg_given(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::BlockAndBlockArgGiven {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_symbol_literal_with_interpolation(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::SymbolLiteralWithInterpolation {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_reserved_for_numparam(level: bindings::ErrorLevel, loc: *mut bindings::Loc, numparam: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let numparam = numparam.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::ReservedForNumparam { numparam };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_key_must_be_valid_as_local_variable(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::KeyMustBeValidAsLocalVariable {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_duplicate_variable_name(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::DuplicateVariableName {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_duplicate_key_name(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::DuplicateKeyName {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_singleton_literal(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::SingletonLiteral {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_nth_ref_is_too_big(level: bindings::ErrorLevel, loc: *mut bindings::Loc, nth_ref: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let nth_ref = nth_ref.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::NthRefIsTooBig { nth_ref };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_duplicated_argument_name(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::DuplicatedArgumentName {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_regex_error(level: bindings::ErrorLevel, loc: *mut bindings::Loc, error: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let error = error.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::RegexError { error };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_invalid_symbol(level: bindings::ErrorLevel, loc: *mut bindings::Loc, symbol: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let symbol = symbol.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::InvalidSymbol { symbol };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}

#[no_mangle]
pub extern "C" fn render_message_void_value_expression(level: bindings::ErrorLevel, loc: *mut bindings::Loc) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    
    let message = lib_ruby_parser::DiagnosticMessage::VoidValueExpression {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let message = diagnostic.render_message();
    BytePtr::from(message)
}


#[no_mangle]
pub extern "C" fn render_fraction_after_numeric(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::FractionAfterNumeric {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_no_digits_after_dot(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::NoDigitsAfterDot {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_unknown_type_of_percent_string(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::UnknownTypeOfPercentString {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_numeric_literal_without_digits(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::NumericLiteralWithoutDigits {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_unterminated_list(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedList {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_unterminated_regexp(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedRegexp {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_unterminated_string(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedString {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_unterminated_quoted_string(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedQuotedString {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_invalid_unicode_escape(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::InvalidUnicodeEscape {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_too_large_unicode_codepoint(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::TooLargeUnicodeCodepoint {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_invalid_unicode_codepoint(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::InvalidUnicodeCodepoint {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_multiple_codepoint_at_single_char(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::MultipleCodepointAtSingleChar {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_invalid_escape_character(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::InvalidEscapeCharacter {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_invalid_hex_escape(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::InvalidHexEscape {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_unterminated_heredoc(level: bindings::ErrorLevel, loc: *mut bindings::Loc, heredoc_id: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let heredoc_id = heredoc_id.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedHeredoc { heredoc_id };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_unterminated_heredoc_id(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedHeredocId {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_slash_r_at_middle_of_line(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::SlashRAtMiddleOfLine {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_d_star_interpreted_as_arg_prefix(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::DStarInterpretedAsArgPrefix {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_star_interpreted_as_arg_prefix(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::StarInterpretedAsArgPrefix {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_ampersand_interpreted_as_arg_prefix(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::AmpersandInterpretedAsArgPrefix {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_triple_dot_at_eol(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::TripleDotAtEol {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_parentheses_iterpreted_as_arglist(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::ParenthesesIterpretedAsArglist {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_ambiguous_first_argument(level: bindings::ErrorLevel, loc: *mut bindings::Loc, operator: *mut i8, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let operator = operator as u8;
    let message = lib_ruby_parser::DiagnosticMessage::AmbiguousFirstArgument { operator };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_ambiguous_operator(level: bindings::ErrorLevel, loc: *mut bindings::Loc, operator: BytePtr, interpreted_as: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let operator = operator.to_string().unwrap();
    let interpreted_as = interpreted_as.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::AmbiguousOperator { operator, interpreted_as };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_invalid_character_syntax(level: bindings::ErrorLevel, loc: *mut bindings::Loc, suggestion: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let suggestion = suggestion.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::InvalidCharacterSyntax { suggestion };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_invalid_octal_digit(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::InvalidOctalDigit {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_trailing_char_in_number(level: bindings::ErrorLevel, loc: *mut bindings::Loc, c: *mut i8, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let c = c as u8;
    let message = lib_ruby_parser::DiagnosticMessage::TrailingCharInNumber { c };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_embedded_document_meets_eof(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::EmbeddedDocumentMeetsEof {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_invalid_char(level: bindings::ErrorLevel, loc: *mut bindings::Loc, c: *mut i8, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let c = c as u8;
    let message = lib_ruby_parser::DiagnosticMessage::InvalidChar { c };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_incomplete_character_syntax(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::IncompleteCharacterSyntax {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_gvar_without_id(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::GvarWithoutId {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_invalid_gvar_name(level: bindings::ErrorLevel, loc: *mut bindings::Loc, c: *mut i8, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let c = c as u8;
    let message = lib_ruby_parser::DiagnosticMessage::InvalidGvarName { c };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_ivar_without_id(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::IvarWithoutId {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_invalid_ivar_name(level: bindings::ErrorLevel, loc: *mut bindings::Loc, c: *mut i8, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let c = c as u8;
    let message = lib_ruby_parser::DiagnosticMessage::InvalidIvarName { c };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_cvar_without_id(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::CvarWithoutId {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_invalid_cvar_name(level: bindings::ErrorLevel, loc: *mut bindings::Loc, c: *mut i8, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let c = c as u8;
    let message = lib_ruby_parser::DiagnosticMessage::InvalidCvarName { c };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_unknown_regex_options(level: bindings::ErrorLevel, loc: *mut bindings::Loc, options: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let options = options.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::UnknownRegexOptions { options };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_unterminated_unicode_escape(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::UnterminatedUnicodeEscape {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_encoding_error(level: bindings::ErrorLevel, loc: *mut bindings::Loc, error: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let error = error.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::EncodingError { error };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_ambiguous_ternary_operator(level: bindings::ErrorLevel, loc: *mut bindings::Loc, condition: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let condition = condition.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::AmbiguousTernaryOperator { condition };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_ambiguous_regexp(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::AmbiguousRegexp {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_else_without_rescue(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::ElseWithoutRescue {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_begin_not_at_top_level(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::BeginNotAtTopLevel {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_alias_nth_ref(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::AliasNthRef {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_csend_inside_masgn(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::CsendInsideMasgn {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_class_or_module_name_must_be_constant(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::ClassOrModuleNameMustBeConstant {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_endless_setter_definition(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::EndlessSetterDefinition {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_unexpected_token(level: bindings::ErrorLevel, loc: *mut bindings::Loc, token_name: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let token_name = token_name.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::UnexpectedToken { token_name };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_class_definition_in_method_body(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::ClassDefinitionInMethodBody {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_module_definition_in_method_body(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::ModuleDefinitionInMethodBody {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_invalid_return_in_class_or_module_body(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::InvalidReturnInClassOrModuleBody {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_const_argument(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::ConstArgument {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_ivar_argument(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::IvarArgument {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_gvar_argument(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::GvarArgument {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_cvar_argument(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::CvarArgument {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_no_such_local_variable(level: bindings::ErrorLevel, loc: *mut bindings::Loc, var_name: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let var_name = var_name.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::NoSuchLocalVariable { var_name };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_ordinary_param_defined(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::OrdinaryParamDefined {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_numparam_used(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::NumparamUsed {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_tok_at_eol_without_expression(level: bindings::ErrorLevel, loc: *mut bindings::Loc, token_name: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let token_name = token_name.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::TokAtEolWithoutExpression { token_name };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_end_in_method(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::EndInMethod {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_comparison_after_comparison(level: bindings::ErrorLevel, loc: *mut bindings::Loc, comparison: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let comparison = comparison.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::ComparisonAfterComparison { comparison };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_circular_argument_reference(level: bindings::ErrorLevel, loc: *mut bindings::Loc, arg_name: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let arg_name = arg_name.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::CircularArgumentReference { arg_name };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_dynamic_constant_assignment(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::DynamicConstantAssignment {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_cant_assign_to_self(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToSelf {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_cant_assign_to_nil(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToNil {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_cant_assign_to_true(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToTrue {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_cant_assign_to_false(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToFalse {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_cant_assign_to_file(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToFile {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_cant_assign_to_line(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToLine {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_cant_assign_to_encoding(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToEncoding {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_cant_assign_to_numparam(level: bindings::ErrorLevel, loc: *mut bindings::Loc, numparam: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let numparam = numparam.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::CantAssignToNumparam { numparam };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_cant_set_variable(level: bindings::ErrorLevel, loc: *mut bindings::Loc, var_name: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let var_name = var_name.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::CantSetVariable { var_name };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_block_given_to_yield(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::BlockGivenToYield {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_block_and_block_arg_given(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::BlockAndBlockArgGiven {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_symbol_literal_with_interpolation(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::SymbolLiteralWithInterpolation {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_reserved_for_numparam(level: bindings::ErrorLevel, loc: *mut bindings::Loc, numparam: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let numparam = numparam.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::ReservedForNumparam { numparam };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_key_must_be_valid_as_local_variable(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::KeyMustBeValidAsLocalVariable {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_duplicate_variable_name(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::DuplicateVariableName {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_duplicate_key_name(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::DuplicateKeyName {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_singleton_literal(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::SingletonLiteral {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_nth_ref_is_too_big(level: bindings::ErrorLevel, loc: *mut bindings::Loc, nth_ref: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let nth_ref = nth_ref.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::NthRefIsTooBig { nth_ref };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_duplicated_argument_name(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::DuplicatedArgumentName {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_regex_error(level: bindings::ErrorLevel, loc: *mut bindings::Loc, error: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let error = error.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::RegexError { error };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_invalid_symbol(level: bindings::ErrorLevel, loc: *mut bindings::Loc, symbol: BytePtr, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    let symbol = symbol.to_string().unwrap();
    let message = lib_ruby_parser::DiagnosticMessage::InvalidSymbol { symbol };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}

#[no_mangle]
pub extern "C" fn render_void_value_expression(level: bindings::ErrorLevel, loc: *mut bindings::Loc, input: BytePtr) -> BytePtr {
    let level = lib_ruby_parser::ErrorLevel::from(level);
    let loc = lib_ruby_parser::Loc::from(Ptr::new(loc));
    let input = lib_ruby_parser::source::Input::from(input);
    
    let message = lib_ruby_parser::DiagnosticMessage::VoidValueExpression {  };
    let diagnostic = lib_ruby_parser::Diagnostic::new(level, message, loc);

    let rendered = diagnostic.render(&input);
    BytePtr::from(rendered)
}
