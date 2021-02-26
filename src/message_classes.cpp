#include "message_classes.h"
#include <iostream>

namespace lib_ruby_parser {

FractionAfterNumeric::FractionAfterNumeric()
{
    
}
NoDigitsAfterDot::NoDigitsAfterDot()
{
    
}
UnknownTypeOfPercentString::UnknownTypeOfPercentString()
{
    
}
NumericLiteralWithoutDigits::NumericLiteralWithoutDigits()
{
    
}
UnterminatedList::UnterminatedList()
{
    
}
UnterminatedRegexp::UnterminatedRegexp()
{
    
}
UnterminatedString::UnterminatedString()
{
    
}
UnterminatedQuotedString::UnterminatedQuotedString()
{
    
}
InvalidUnicodeEscape::InvalidUnicodeEscape()
{
    
}
TooLargeUnicodeCodepoint::TooLargeUnicodeCodepoint()
{
    
}
InvalidUnicodeCodepoint::InvalidUnicodeCodepoint()
{
    
}
MultipleCodepointAtSingleChar::MultipleCodepointAtSingleChar()
{
    
}
InvalidEscapeCharacter::InvalidEscapeCharacter()
{
    
}
InvalidHexEscape::InvalidHexEscape()
{
    
}
UnterminatedHeredoc::UnterminatedHeredoc(std::string heredoc_id)
{
    this->heredoc_id = heredoc_id;
}
UnterminatedHeredocId::UnterminatedHeredocId()
{
    
}
SlashRAtMiddleOfLine::SlashRAtMiddleOfLine()
{
    
}
DStarInterpretedAsArgPrefix::DStarInterpretedAsArgPrefix()
{
    
}
StarInterpretedAsArgPrefix::StarInterpretedAsArgPrefix()
{
    
}
AmpersandInterpretedAsArgPrefix::AmpersandInterpretedAsArgPrefix()
{
    
}
TripleDotAtEol::TripleDotAtEol()
{
    
}
ParenthesesIterpretedAsArglist::ParenthesesIterpretedAsArglist()
{
    
}
AmbiguousFirstArgument::AmbiguousFirstArgument(char operator_)
{
    this->operator_ = operator_;
}
AmbiguousOperator::AmbiguousOperator(std::string operator_, std::string interpreted_as)
{
    this->operator_ = operator_;
    this->interpreted_as = interpreted_as;
}
InvalidCharacterSyntax::InvalidCharacterSyntax(std::string suggestion)
{
    this->suggestion = suggestion;
}
InvalidOctalDigit::InvalidOctalDigit()
{
    
}
TrailingCharInNumber::TrailingCharInNumber(char c)
{
    this->c = c;
}
EmbeddedDocumentMeetsEof::EmbeddedDocumentMeetsEof()
{
    
}
InvalidChar::InvalidChar(char c)
{
    this->c = c;
}
IncompleteCharacterSyntax::IncompleteCharacterSyntax()
{
    
}
GvarWithoutId::GvarWithoutId()
{
    
}
InvalidGvarName::InvalidGvarName(char c)
{
    this->c = c;
}
IvarWithoutId::IvarWithoutId()
{
    
}
InvalidIvarName::InvalidIvarName(char c)
{
    this->c = c;
}
CvarWithoutId::CvarWithoutId()
{
    
}
InvalidCvarName::InvalidCvarName(char c)
{
    this->c = c;
}
UnknownRegexOptions::UnknownRegexOptions(std::string options)
{
    this->options = options;
}
UnterminatedUnicodeEscape::UnterminatedUnicodeEscape()
{
    
}
EncodingError::EncodingError(std::string error)
{
    this->error = error;
}
AmbiguousTernaryOperator::AmbiguousTernaryOperator(std::string condition)
{
    this->condition = condition;
}
AmbiguousRegexp::AmbiguousRegexp()
{
    
}
ElseWithoutRescue::ElseWithoutRescue()
{
    
}
BeginNotAtTopLevel::BeginNotAtTopLevel()
{
    
}
AliasNthRef::AliasNthRef()
{
    
}
CsendInsideMasgn::CsendInsideMasgn()
{
    
}
ClassOrModuleNameMustBeConstant::ClassOrModuleNameMustBeConstant()
{
    
}
EndlessSetterDefinition::EndlessSetterDefinition()
{
    
}
UnexpectedToken::UnexpectedToken(std::string token_name)
{
    this->token_name = token_name;
}
ClassDefinitionInMethodBody::ClassDefinitionInMethodBody()
{
    
}
ModuleDefinitionInMethodBody::ModuleDefinitionInMethodBody()
{
    
}
InvalidReturnInClassOrModuleBody::InvalidReturnInClassOrModuleBody()
{
    
}
ConstArgument::ConstArgument()
{
    
}
IvarArgument::IvarArgument()
{
    
}
GvarArgument::GvarArgument()
{
    
}
CvarArgument::CvarArgument()
{
    
}
NoSuchLocalVariable::NoSuchLocalVariable(std::string var_name)
{
    this->var_name = var_name;
}
OrdinaryParamDefined::OrdinaryParamDefined()
{
    
}
NumparamUsed::NumparamUsed()
{
    
}
TokAtEolWithoutExpression::TokAtEolWithoutExpression(std::string token_name)
{
    this->token_name = token_name;
}
EndInMethod::EndInMethod()
{
    
}
ComparisonAfterComparison::ComparisonAfterComparison(std::string comparison)
{
    this->comparison = comparison;
}
CircularArgumentReference::CircularArgumentReference(std::string arg_name)
{
    this->arg_name = arg_name;
}
DynamicConstantAssignment::DynamicConstantAssignment()
{
    
}
CantAssignToSelf::CantAssignToSelf()
{
    
}
CantAssignToNil::CantAssignToNil()
{
    
}
CantAssignToTrue::CantAssignToTrue()
{
    
}
CantAssignToFalse::CantAssignToFalse()
{
    
}
CantAssignToFile::CantAssignToFile()
{
    
}
CantAssignToLine::CantAssignToLine()
{
    
}
CantAssignToEncoding::CantAssignToEncoding()
{
    
}
CantAssignToNumparam::CantAssignToNumparam(std::string numparam)
{
    this->numparam = numparam;
}
CantSetVariable::CantSetVariable(std::string var_name)
{
    this->var_name = var_name;
}
BlockGivenToYield::BlockGivenToYield()
{
    
}
BlockAndBlockArgGiven::BlockAndBlockArgGiven()
{
    
}
SymbolLiteralWithInterpolation::SymbolLiteralWithInterpolation()
{
    
}
ReservedForNumparam::ReservedForNumparam(std::string numparam)
{
    this->numparam = numparam;
}
KeyMustBeValidAsLocalVariable::KeyMustBeValidAsLocalVariable()
{
    
}
DuplicateVariableName::DuplicateVariableName()
{
    
}
DuplicateKeyName::DuplicateKeyName()
{
    
}
SingletonLiteral::SingletonLiteral()
{
    
}
NthRefIsTooBig::NthRefIsTooBig(std::string nth_ref)
{
    this->nth_ref = nth_ref;
}
DuplicatedArgumentName::DuplicatedArgumentName()
{
    
}
RegexError::RegexError(std::string error)
{
    this->error = error;
}
InvalidSymbol::InvalidSymbol(std::string symbol)
{
    this->symbol = symbol;
}
VoidValueExpression::VoidValueExpression()
{
    
}

bool FractionAfterNumeric::operator==(const FractionAfterNumeric &)
{
    return true;
}
bool NoDigitsAfterDot::operator==(const NoDigitsAfterDot &)
{
    return true;
}
bool UnknownTypeOfPercentString::operator==(const UnknownTypeOfPercentString &)
{
    return true;
}
bool NumericLiteralWithoutDigits::operator==(const NumericLiteralWithoutDigits &)
{
    return true;
}
bool UnterminatedList::operator==(const UnterminatedList &)
{
    return true;
}
bool UnterminatedRegexp::operator==(const UnterminatedRegexp &)
{
    return true;
}
bool UnterminatedString::operator==(const UnterminatedString &)
{
    return true;
}
bool UnterminatedQuotedString::operator==(const UnterminatedQuotedString &)
{
    return true;
}
bool InvalidUnicodeEscape::operator==(const InvalidUnicodeEscape &)
{
    return true;
}
bool TooLargeUnicodeCodepoint::operator==(const TooLargeUnicodeCodepoint &)
{
    return true;
}
bool InvalidUnicodeCodepoint::operator==(const InvalidUnicodeCodepoint &)
{
    return true;
}
bool MultipleCodepointAtSingleChar::operator==(const MultipleCodepointAtSingleChar &)
{
    return true;
}
bool InvalidEscapeCharacter::operator==(const InvalidEscapeCharacter &)
{
    return true;
}
bool InvalidHexEscape::operator==(const InvalidHexEscape &)
{
    return true;
}
bool UnterminatedHeredoc::operator==(const UnterminatedHeredoc &other)
{
    return heredoc_id == other.heredoc_id;
}
bool UnterminatedHeredocId::operator==(const UnterminatedHeredocId &)
{
    return true;
}
bool SlashRAtMiddleOfLine::operator==(const SlashRAtMiddleOfLine &)
{
    return true;
}
bool DStarInterpretedAsArgPrefix::operator==(const DStarInterpretedAsArgPrefix &)
{
    return true;
}
bool StarInterpretedAsArgPrefix::operator==(const StarInterpretedAsArgPrefix &)
{
    return true;
}
bool AmpersandInterpretedAsArgPrefix::operator==(const AmpersandInterpretedAsArgPrefix &)
{
    return true;
}
bool TripleDotAtEol::operator==(const TripleDotAtEol &)
{
    return true;
}
bool ParenthesesIterpretedAsArglist::operator==(const ParenthesesIterpretedAsArglist &)
{
    return true;
}
bool AmbiguousFirstArgument::operator==(const AmbiguousFirstArgument &other)
{
    return operator_ == other.operator_;
}
bool AmbiguousOperator::operator==(const AmbiguousOperator &other)
{
    return operator_ == other.operator_ && interpreted_as == other.interpreted_as;
}
bool InvalidCharacterSyntax::operator==(const InvalidCharacterSyntax &other)
{
    return suggestion == other.suggestion;
}
bool InvalidOctalDigit::operator==(const InvalidOctalDigit &)
{
    return true;
}
bool TrailingCharInNumber::operator==(const TrailingCharInNumber &other)
{
    return c == other.c;
}
bool EmbeddedDocumentMeetsEof::operator==(const EmbeddedDocumentMeetsEof &)
{
    return true;
}
bool InvalidChar::operator==(const InvalidChar &other)
{
    return c == other.c;
}
bool IncompleteCharacterSyntax::operator==(const IncompleteCharacterSyntax &)
{
    return true;
}
bool GvarWithoutId::operator==(const GvarWithoutId &)
{
    return true;
}
bool InvalidGvarName::operator==(const InvalidGvarName &other)
{
    return c == other.c;
}
bool IvarWithoutId::operator==(const IvarWithoutId &)
{
    return true;
}
bool InvalidIvarName::operator==(const InvalidIvarName &other)
{
    return c == other.c;
}
bool CvarWithoutId::operator==(const CvarWithoutId &)
{
    return true;
}
bool InvalidCvarName::operator==(const InvalidCvarName &other)
{
    return c == other.c;
}
bool UnknownRegexOptions::operator==(const UnknownRegexOptions &other)
{
    return options == other.options;
}
bool UnterminatedUnicodeEscape::operator==(const UnterminatedUnicodeEscape &)
{
    return true;
}
bool EncodingError::operator==(const EncodingError &other)
{
    return error == other.error;
}
bool AmbiguousTernaryOperator::operator==(const AmbiguousTernaryOperator &other)
{
    return condition == other.condition;
}
bool AmbiguousRegexp::operator==(const AmbiguousRegexp &)
{
    return true;
}
bool ElseWithoutRescue::operator==(const ElseWithoutRescue &)
{
    return true;
}
bool BeginNotAtTopLevel::operator==(const BeginNotAtTopLevel &)
{
    return true;
}
bool AliasNthRef::operator==(const AliasNthRef &)
{
    return true;
}
bool CsendInsideMasgn::operator==(const CsendInsideMasgn &)
{
    return true;
}
bool ClassOrModuleNameMustBeConstant::operator==(const ClassOrModuleNameMustBeConstant &)
{
    return true;
}
bool EndlessSetterDefinition::operator==(const EndlessSetterDefinition &)
{
    return true;
}
bool UnexpectedToken::operator==(const UnexpectedToken &other)
{
    return token_name == other.token_name;
}
bool ClassDefinitionInMethodBody::operator==(const ClassDefinitionInMethodBody &)
{
    return true;
}
bool ModuleDefinitionInMethodBody::operator==(const ModuleDefinitionInMethodBody &)
{
    return true;
}
bool InvalidReturnInClassOrModuleBody::operator==(const InvalidReturnInClassOrModuleBody &)
{
    return true;
}
bool ConstArgument::operator==(const ConstArgument &)
{
    return true;
}
bool IvarArgument::operator==(const IvarArgument &)
{
    return true;
}
bool GvarArgument::operator==(const GvarArgument &)
{
    return true;
}
bool CvarArgument::operator==(const CvarArgument &)
{
    return true;
}
bool NoSuchLocalVariable::operator==(const NoSuchLocalVariable &other)
{
    return var_name == other.var_name;
}
bool OrdinaryParamDefined::operator==(const OrdinaryParamDefined &)
{
    return true;
}
bool NumparamUsed::operator==(const NumparamUsed &)
{
    return true;
}
bool TokAtEolWithoutExpression::operator==(const TokAtEolWithoutExpression &other)
{
    return token_name == other.token_name;
}
bool EndInMethod::operator==(const EndInMethod &)
{
    return true;
}
bool ComparisonAfterComparison::operator==(const ComparisonAfterComparison &other)
{
    return comparison == other.comparison;
}
bool CircularArgumentReference::operator==(const CircularArgumentReference &other)
{
    return arg_name == other.arg_name;
}
bool DynamicConstantAssignment::operator==(const DynamicConstantAssignment &)
{
    return true;
}
bool CantAssignToSelf::operator==(const CantAssignToSelf &)
{
    return true;
}
bool CantAssignToNil::operator==(const CantAssignToNil &)
{
    return true;
}
bool CantAssignToTrue::operator==(const CantAssignToTrue &)
{
    return true;
}
bool CantAssignToFalse::operator==(const CantAssignToFalse &)
{
    return true;
}
bool CantAssignToFile::operator==(const CantAssignToFile &)
{
    return true;
}
bool CantAssignToLine::operator==(const CantAssignToLine &)
{
    return true;
}
bool CantAssignToEncoding::operator==(const CantAssignToEncoding &)
{
    return true;
}
bool CantAssignToNumparam::operator==(const CantAssignToNumparam &other)
{
    return numparam == other.numparam;
}
bool CantSetVariable::operator==(const CantSetVariable &other)
{
    return var_name == other.var_name;
}
bool BlockGivenToYield::operator==(const BlockGivenToYield &)
{
    return true;
}
bool BlockAndBlockArgGiven::operator==(const BlockAndBlockArgGiven &)
{
    return true;
}
bool SymbolLiteralWithInterpolation::operator==(const SymbolLiteralWithInterpolation &)
{
    return true;
}
bool ReservedForNumparam::operator==(const ReservedForNumparam &other)
{
    return numparam == other.numparam;
}
bool KeyMustBeValidAsLocalVariable::operator==(const KeyMustBeValidAsLocalVariable &)
{
    return true;
}
bool DuplicateVariableName::operator==(const DuplicateVariableName &)
{
    return true;
}
bool DuplicateKeyName::operator==(const DuplicateKeyName &)
{
    return true;
}
bool SingletonLiteral::operator==(const SingletonLiteral &)
{
    return true;
}
bool NthRefIsTooBig::operator==(const NthRefIsTooBig &other)
{
    return nth_ref == other.nth_ref;
}
bool DuplicatedArgumentName::operator==(const DuplicatedArgumentName &)
{
    return true;
}
bool RegexError::operator==(const RegexError &other)
{
    return error == other.error;
}
bool InvalidSymbol::operator==(const InvalidSymbol &other)
{
    return symbol == other.symbol;
}
bool VoidValueExpression::operator==(const VoidValueExpression &)
{
    return true;
}

}
