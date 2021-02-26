#ifndef LIB_RUBY_PARSER_GEN_MESSAGES_CLASSES_H
#define LIB_RUBY_PARSER_GEN_MESSAGES_CLASSES_H

#include <string>
#include <variant>
#include <memory>
#include "../../bytes.h"

namespace lib_ruby_parser {

class BaseDiagnosticMessage
{
public:
    std::string render_message();
    std::string render(const Bytes &input);
};

class FractionAfterNumeric: public BaseDiagnosticMessage {
public:
    
    explicit FractionAfterNumeric();
    bool operator==(const FractionAfterNumeric &other);
};
class NoDigitsAfterDot: public BaseDiagnosticMessage {
public:
    
    explicit NoDigitsAfterDot();
    bool operator==(const NoDigitsAfterDot &other);
};
class UnknownTypeOfPercentString: public BaseDiagnosticMessage {
public:
    
    explicit UnknownTypeOfPercentString();
    bool operator==(const UnknownTypeOfPercentString &other);
};
class NumericLiteralWithoutDigits: public BaseDiagnosticMessage {
public:
    
    explicit NumericLiteralWithoutDigits();
    bool operator==(const NumericLiteralWithoutDigits &other);
};
class UnterminatedList: public BaseDiagnosticMessage {
public:
    
    explicit UnterminatedList();
    bool operator==(const UnterminatedList &other);
};
class UnterminatedRegexp: public BaseDiagnosticMessage {
public:
    
    explicit UnterminatedRegexp();
    bool operator==(const UnterminatedRegexp &other);
};
class UnterminatedString: public BaseDiagnosticMessage {
public:
    
    explicit UnterminatedString();
    bool operator==(const UnterminatedString &other);
};
class UnterminatedQuotedString: public BaseDiagnosticMessage {
public:
    
    explicit UnterminatedQuotedString();
    bool operator==(const UnterminatedQuotedString &other);
};
class InvalidUnicodeEscape: public BaseDiagnosticMessage {
public:
    
    explicit InvalidUnicodeEscape();
    bool operator==(const InvalidUnicodeEscape &other);
};
class TooLargeUnicodeCodepoint: public BaseDiagnosticMessage {
public:
    
    explicit TooLargeUnicodeCodepoint();
    bool operator==(const TooLargeUnicodeCodepoint &other);
};
class InvalidUnicodeCodepoint: public BaseDiagnosticMessage {
public:
    
    explicit InvalidUnicodeCodepoint();
    bool operator==(const InvalidUnicodeCodepoint &other);
};
class MultipleCodepointAtSingleChar: public BaseDiagnosticMessage {
public:
    
    explicit MultipleCodepointAtSingleChar();
    bool operator==(const MultipleCodepointAtSingleChar &other);
};
class InvalidEscapeCharacter: public BaseDiagnosticMessage {
public:
    
    explicit InvalidEscapeCharacter();
    bool operator==(const InvalidEscapeCharacter &other);
};
class InvalidHexEscape: public BaseDiagnosticMessage {
public:
    
    explicit InvalidHexEscape();
    bool operator==(const InvalidHexEscape &other);
};
class UnterminatedHeredoc: public BaseDiagnosticMessage {
public:
    std::string heredoc_id;
    explicit UnterminatedHeredoc(std::string heredoc_id);
    bool operator==(const UnterminatedHeredoc &other);
};
class UnterminatedHeredocId: public BaseDiagnosticMessage {
public:
    
    explicit UnterminatedHeredocId();
    bool operator==(const UnterminatedHeredocId &other);
};
class SlashRAtMiddleOfLine: public BaseDiagnosticMessage {
public:
    
    explicit SlashRAtMiddleOfLine();
    bool operator==(const SlashRAtMiddleOfLine &other);
};
class DStarInterpretedAsArgPrefix: public BaseDiagnosticMessage {
public:
    
    explicit DStarInterpretedAsArgPrefix();
    bool operator==(const DStarInterpretedAsArgPrefix &other);
};
class StarInterpretedAsArgPrefix: public BaseDiagnosticMessage {
public:
    
    explicit StarInterpretedAsArgPrefix();
    bool operator==(const StarInterpretedAsArgPrefix &other);
};
class AmpersandInterpretedAsArgPrefix: public BaseDiagnosticMessage {
public:
    
    explicit AmpersandInterpretedAsArgPrefix();
    bool operator==(const AmpersandInterpretedAsArgPrefix &other);
};
class TripleDotAtEol: public BaseDiagnosticMessage {
public:
    
    explicit TripleDotAtEol();
    bool operator==(const TripleDotAtEol &other);
};
class ParenthesesIterpretedAsArglist: public BaseDiagnosticMessage {
public:
    
    explicit ParenthesesIterpretedAsArglist();
    bool operator==(const ParenthesesIterpretedAsArglist &other);
};
class AmbiguousFirstArgument: public BaseDiagnosticMessage {
public:
    char operator_;
    explicit AmbiguousFirstArgument(char operator_);
    bool operator==(const AmbiguousFirstArgument &other);
};
class AmbiguousOperator: public BaseDiagnosticMessage {
public:
    std::string operator_;
    std::string interpreted_as;
    explicit AmbiguousOperator(std::string operator_, std::string interpreted_as);
    bool operator==(const AmbiguousOperator &other);
};
class InvalidCharacterSyntax: public BaseDiagnosticMessage {
public:
    std::string suggestion;
    explicit InvalidCharacterSyntax(std::string suggestion);
    bool operator==(const InvalidCharacterSyntax &other);
};
class InvalidOctalDigit: public BaseDiagnosticMessage {
public:
    
    explicit InvalidOctalDigit();
    bool operator==(const InvalidOctalDigit &other);
};
class TrailingCharInNumber: public BaseDiagnosticMessage {
public:
    char c;
    explicit TrailingCharInNumber(char c);
    bool operator==(const TrailingCharInNumber &other);
};
class EmbeddedDocumentMeetsEof: public BaseDiagnosticMessage {
public:
    
    explicit EmbeddedDocumentMeetsEof();
    bool operator==(const EmbeddedDocumentMeetsEof &other);
};
class InvalidChar: public BaseDiagnosticMessage {
public:
    char c;
    explicit InvalidChar(char c);
    bool operator==(const InvalidChar &other);
};
class IncompleteCharacterSyntax: public BaseDiagnosticMessage {
public:
    
    explicit IncompleteCharacterSyntax();
    bool operator==(const IncompleteCharacterSyntax &other);
};
class GvarWithoutId: public BaseDiagnosticMessage {
public:
    
    explicit GvarWithoutId();
    bool operator==(const GvarWithoutId &other);
};
class InvalidGvarName: public BaseDiagnosticMessage {
public:
    char c;
    explicit InvalidGvarName(char c);
    bool operator==(const InvalidGvarName &other);
};
class IvarWithoutId: public BaseDiagnosticMessage {
public:
    
    explicit IvarWithoutId();
    bool operator==(const IvarWithoutId &other);
};
class InvalidIvarName: public BaseDiagnosticMessage {
public:
    char c;
    explicit InvalidIvarName(char c);
    bool operator==(const InvalidIvarName &other);
};
class CvarWithoutId: public BaseDiagnosticMessage {
public:
    
    explicit CvarWithoutId();
    bool operator==(const CvarWithoutId &other);
};
class InvalidCvarName: public BaseDiagnosticMessage {
public:
    char c;
    explicit InvalidCvarName(char c);
    bool operator==(const InvalidCvarName &other);
};
class UnknownRegexOptions: public BaseDiagnosticMessage {
public:
    std::string options;
    explicit UnknownRegexOptions(std::string options);
    bool operator==(const UnknownRegexOptions &other);
};
class UnterminatedUnicodeEscape: public BaseDiagnosticMessage {
public:
    
    explicit UnterminatedUnicodeEscape();
    bool operator==(const UnterminatedUnicodeEscape &other);
};
class EncodingError: public BaseDiagnosticMessage {
public:
    std::string error;
    explicit EncodingError(std::string error);
    bool operator==(const EncodingError &other);
};
class AmbiguousTernaryOperator: public BaseDiagnosticMessage {
public:
    std::string condition;
    explicit AmbiguousTernaryOperator(std::string condition);
    bool operator==(const AmbiguousTernaryOperator &other);
};
class AmbiguousRegexp: public BaseDiagnosticMessage {
public:
    
    explicit AmbiguousRegexp();
    bool operator==(const AmbiguousRegexp &other);
};
class ElseWithoutRescue: public BaseDiagnosticMessage {
public:
    
    explicit ElseWithoutRescue();
    bool operator==(const ElseWithoutRescue &other);
};
class BeginNotAtTopLevel: public BaseDiagnosticMessage {
public:
    
    explicit BeginNotAtTopLevel();
    bool operator==(const BeginNotAtTopLevel &other);
};
class AliasNthRef: public BaseDiagnosticMessage {
public:
    
    explicit AliasNthRef();
    bool operator==(const AliasNthRef &other);
};
class CsendInsideMasgn: public BaseDiagnosticMessage {
public:
    
    explicit CsendInsideMasgn();
    bool operator==(const CsendInsideMasgn &other);
};
class ClassOrModuleNameMustBeConstant: public BaseDiagnosticMessage {
public:
    
    explicit ClassOrModuleNameMustBeConstant();
    bool operator==(const ClassOrModuleNameMustBeConstant &other);
};
class EndlessSetterDefinition: public BaseDiagnosticMessage {
public:
    
    explicit EndlessSetterDefinition();
    bool operator==(const EndlessSetterDefinition &other);
};
class UnexpectedToken: public BaseDiagnosticMessage {
public:
    std::string token_name;
    explicit UnexpectedToken(std::string token_name);
    bool operator==(const UnexpectedToken &other);
};
class ClassDefinitionInMethodBody: public BaseDiagnosticMessage {
public:
    
    explicit ClassDefinitionInMethodBody();
    bool operator==(const ClassDefinitionInMethodBody &other);
};
class ModuleDefinitionInMethodBody: public BaseDiagnosticMessage {
public:
    
    explicit ModuleDefinitionInMethodBody();
    bool operator==(const ModuleDefinitionInMethodBody &other);
};
class InvalidReturnInClassOrModuleBody: public BaseDiagnosticMessage {
public:
    
    explicit InvalidReturnInClassOrModuleBody();
    bool operator==(const InvalidReturnInClassOrModuleBody &other);
};
class ConstArgument: public BaseDiagnosticMessage {
public:
    
    explicit ConstArgument();
    bool operator==(const ConstArgument &other);
};
class IvarArgument: public BaseDiagnosticMessage {
public:
    
    explicit IvarArgument();
    bool operator==(const IvarArgument &other);
};
class GvarArgument: public BaseDiagnosticMessage {
public:
    
    explicit GvarArgument();
    bool operator==(const GvarArgument &other);
};
class CvarArgument: public BaseDiagnosticMessage {
public:
    
    explicit CvarArgument();
    bool operator==(const CvarArgument &other);
};
class NoSuchLocalVariable: public BaseDiagnosticMessage {
public:
    std::string var_name;
    explicit NoSuchLocalVariable(std::string var_name);
    bool operator==(const NoSuchLocalVariable &other);
};
class OrdinaryParamDefined: public BaseDiagnosticMessage {
public:
    
    explicit OrdinaryParamDefined();
    bool operator==(const OrdinaryParamDefined &other);
};
class NumparamUsed: public BaseDiagnosticMessage {
public:
    
    explicit NumparamUsed();
    bool operator==(const NumparamUsed &other);
};
class TokAtEolWithoutExpression: public BaseDiagnosticMessage {
public:
    std::string token_name;
    explicit TokAtEolWithoutExpression(std::string token_name);
    bool operator==(const TokAtEolWithoutExpression &other);
};
class EndInMethod: public BaseDiagnosticMessage {
public:
    
    explicit EndInMethod();
    bool operator==(const EndInMethod &other);
};
class ComparisonAfterComparison: public BaseDiagnosticMessage {
public:
    std::string comparison;
    explicit ComparisonAfterComparison(std::string comparison);
    bool operator==(const ComparisonAfterComparison &other);
};
class CircularArgumentReference: public BaseDiagnosticMessage {
public:
    std::string arg_name;
    explicit CircularArgumentReference(std::string arg_name);
    bool operator==(const CircularArgumentReference &other);
};
class DynamicConstantAssignment: public BaseDiagnosticMessage {
public:
    
    explicit DynamicConstantAssignment();
    bool operator==(const DynamicConstantAssignment &other);
};
class CantAssignToSelf: public BaseDiagnosticMessage {
public:
    
    explicit CantAssignToSelf();
    bool operator==(const CantAssignToSelf &other);
};
class CantAssignToNil: public BaseDiagnosticMessage {
public:
    
    explicit CantAssignToNil();
    bool operator==(const CantAssignToNil &other);
};
class CantAssignToTrue: public BaseDiagnosticMessage {
public:
    
    explicit CantAssignToTrue();
    bool operator==(const CantAssignToTrue &other);
};
class CantAssignToFalse: public BaseDiagnosticMessage {
public:
    
    explicit CantAssignToFalse();
    bool operator==(const CantAssignToFalse &other);
};
class CantAssignToFile: public BaseDiagnosticMessage {
public:
    
    explicit CantAssignToFile();
    bool operator==(const CantAssignToFile &other);
};
class CantAssignToLine: public BaseDiagnosticMessage {
public:
    
    explicit CantAssignToLine();
    bool operator==(const CantAssignToLine &other);
};
class CantAssignToEncoding: public BaseDiagnosticMessage {
public:
    
    explicit CantAssignToEncoding();
    bool operator==(const CantAssignToEncoding &other);
};
class CantAssignToNumparam: public BaseDiagnosticMessage {
public:
    std::string numparam;
    explicit CantAssignToNumparam(std::string numparam);
    bool operator==(const CantAssignToNumparam &other);
};
class CantSetVariable: public BaseDiagnosticMessage {
public:
    std::string var_name;
    explicit CantSetVariable(std::string var_name);
    bool operator==(const CantSetVariable &other);
};
class BlockGivenToYield: public BaseDiagnosticMessage {
public:
    
    explicit BlockGivenToYield();
    bool operator==(const BlockGivenToYield &other);
};
class BlockAndBlockArgGiven: public BaseDiagnosticMessage {
public:
    
    explicit BlockAndBlockArgGiven();
    bool operator==(const BlockAndBlockArgGiven &other);
};
class SymbolLiteralWithInterpolation: public BaseDiagnosticMessage {
public:
    
    explicit SymbolLiteralWithInterpolation();
    bool operator==(const SymbolLiteralWithInterpolation &other);
};
class ReservedForNumparam: public BaseDiagnosticMessage {
public:
    std::string numparam;
    explicit ReservedForNumparam(std::string numparam);
    bool operator==(const ReservedForNumparam &other);
};
class KeyMustBeValidAsLocalVariable: public BaseDiagnosticMessage {
public:
    
    explicit KeyMustBeValidAsLocalVariable();
    bool operator==(const KeyMustBeValidAsLocalVariable &other);
};
class DuplicateVariableName: public BaseDiagnosticMessage {
public:
    
    explicit DuplicateVariableName();
    bool operator==(const DuplicateVariableName &other);
};
class DuplicateKeyName: public BaseDiagnosticMessage {
public:
    
    explicit DuplicateKeyName();
    bool operator==(const DuplicateKeyName &other);
};
class SingletonLiteral: public BaseDiagnosticMessage {
public:
    
    explicit SingletonLiteral();
    bool operator==(const SingletonLiteral &other);
};
class NthRefIsTooBig: public BaseDiagnosticMessage {
public:
    std::string nth_ref;
    explicit NthRefIsTooBig(std::string nth_ref);
    bool operator==(const NthRefIsTooBig &other);
};
class DuplicatedArgumentName: public BaseDiagnosticMessage {
public:
    
    explicit DuplicatedArgumentName();
    bool operator==(const DuplicatedArgumentName &other);
};
class RegexError: public BaseDiagnosticMessage {
public:
    std::string error;
    explicit RegexError(std::string error);
    bool operator==(const RegexError &other);
};
class InvalidSymbol: public BaseDiagnosticMessage {
public:
    std::string symbol;
    explicit InvalidSymbol(std::string symbol);
    bool operator==(const InvalidSymbol &other);
};
class VoidValueExpression: public BaseDiagnosticMessage {
public:
    
    explicit VoidValueExpression();
    bool operator==(const VoidValueExpression &other);
};

}

#endif // LIB_RUBY_PARSER_GEN_MESSAGES_CLASSES_H
