#ifndef LIB_RUBY_PARSER_MESSAGE_H
#define LIB_RUBY_PARSER_MESSAGE_H

#include <string>
#include <variant>
#include <memory>
#include "bytes.h"

namespace lib_ruby_parser {

class DiagnosticMessage
{
public:
    std::string render_message();
    std::string render(const Bytes &input);
};

class FractionAfterNumeric: public DiagnosticMessage {
public:
    
    explicit FractionAfterNumeric();
    bool operator==(const FractionAfterNumeric &other);
};
class NoDigitsAfterDot: public DiagnosticMessage {
public:
    
    explicit NoDigitsAfterDot();
    bool operator==(const NoDigitsAfterDot &other);
};
class UnknownTypeOfPercentString: public DiagnosticMessage {
public:
    
    explicit UnknownTypeOfPercentString();
    bool operator==(const UnknownTypeOfPercentString &other);
};
class NumericLiteralWithoutDigits: public DiagnosticMessage {
public:
    
    explicit NumericLiteralWithoutDigits();
    bool operator==(const NumericLiteralWithoutDigits &other);
};
class UnterminatedList: public DiagnosticMessage {
public:
    
    explicit UnterminatedList();
    bool operator==(const UnterminatedList &other);
};
class UnterminatedRegexp: public DiagnosticMessage {
public:
    
    explicit UnterminatedRegexp();
    bool operator==(const UnterminatedRegexp &other);
};
class UnterminatedString: public DiagnosticMessage {
public:
    
    explicit UnterminatedString();
    bool operator==(const UnterminatedString &other);
};
class UnterminatedQuotedString: public DiagnosticMessage {
public:
    
    explicit UnterminatedQuotedString();
    bool operator==(const UnterminatedQuotedString &other);
};
class InvalidUnicodeEscape: public DiagnosticMessage {
public:
    
    explicit InvalidUnicodeEscape();
    bool operator==(const InvalidUnicodeEscape &other);
};
class TooLargeUnicodeCodepoint: public DiagnosticMessage {
public:
    
    explicit TooLargeUnicodeCodepoint();
    bool operator==(const TooLargeUnicodeCodepoint &other);
};
class InvalidUnicodeCodepoint: public DiagnosticMessage {
public:
    
    explicit InvalidUnicodeCodepoint();
    bool operator==(const InvalidUnicodeCodepoint &other);
};
class MultipleCodepointAtSingleChar: public DiagnosticMessage {
public:
    
    explicit MultipleCodepointAtSingleChar();
    bool operator==(const MultipleCodepointAtSingleChar &other);
};
class InvalidEscapeCharacter: public DiagnosticMessage {
public:
    
    explicit InvalidEscapeCharacter();
    bool operator==(const InvalidEscapeCharacter &other);
};
class InvalidHexEscape: public DiagnosticMessage {
public:
    
    explicit InvalidHexEscape();
    bool operator==(const InvalidHexEscape &other);
};
class UnterminatedHeredoc: public DiagnosticMessage {
public:
    std::string heredoc_id;
    explicit UnterminatedHeredoc(std::string heredoc_id);
    bool operator==(const UnterminatedHeredoc &other);
};
class UnterminatedHeredocId: public DiagnosticMessage {
public:
    
    explicit UnterminatedHeredocId();
    bool operator==(const UnterminatedHeredocId &other);
};
class SlashRAtMiddleOfLine: public DiagnosticMessage {
public:
    
    explicit SlashRAtMiddleOfLine();
    bool operator==(const SlashRAtMiddleOfLine &other);
};
class DStarInterpretedAsArgPrefix: public DiagnosticMessage {
public:
    
    explicit DStarInterpretedAsArgPrefix();
    bool operator==(const DStarInterpretedAsArgPrefix &other);
};
class StarInterpretedAsArgPrefix: public DiagnosticMessage {
public:
    
    explicit StarInterpretedAsArgPrefix();
    bool operator==(const StarInterpretedAsArgPrefix &other);
};
class AmpersandInterpretedAsArgPrefix: public DiagnosticMessage {
public:
    
    explicit AmpersandInterpretedAsArgPrefix();
    bool operator==(const AmpersandInterpretedAsArgPrefix &other);
};
class TripleDotAtEol: public DiagnosticMessage {
public:
    
    explicit TripleDotAtEol();
    bool operator==(const TripleDotAtEol &other);
};
class ParenthesesIterpretedAsArglist: public DiagnosticMessage {
public:
    
    explicit ParenthesesIterpretedAsArglist();
    bool operator==(const ParenthesesIterpretedAsArglist &other);
};
class AmbiguousFirstArgument: public DiagnosticMessage {
public:
    char operator_;
    explicit AmbiguousFirstArgument(char operator_);
    bool operator==(const AmbiguousFirstArgument &other);
};
class AmbiguousOperator: public DiagnosticMessage {
public:
    std::string operator_;
    std::string interpreted_as;
    explicit AmbiguousOperator(std::string operator_, std::string interpreted_as);
    bool operator==(const AmbiguousOperator &other);
};
class InvalidCharacterSyntax: public DiagnosticMessage {
public:
    std::string suggestion;
    explicit InvalidCharacterSyntax(std::string suggestion);
    bool operator==(const InvalidCharacterSyntax &other);
};
class InvalidOctalDigit: public DiagnosticMessage {
public:
    
    explicit InvalidOctalDigit();
    bool operator==(const InvalidOctalDigit &other);
};
class TrailingCharInNumber: public DiagnosticMessage {
public:
    char c;
    explicit TrailingCharInNumber(char c);
    bool operator==(const TrailingCharInNumber &other);
};
class EmbeddedDocumentMeetsEof: public DiagnosticMessage {
public:
    
    explicit EmbeddedDocumentMeetsEof();
    bool operator==(const EmbeddedDocumentMeetsEof &other);
};
class InvalidChar: public DiagnosticMessage {
public:
    char c;
    explicit InvalidChar(char c);
    bool operator==(const InvalidChar &other);
};
class IncompleteCharacterSyntax: public DiagnosticMessage {
public:
    
    explicit IncompleteCharacterSyntax();
    bool operator==(const IncompleteCharacterSyntax &other);
};
class GvarWithoutId: public DiagnosticMessage {
public:
    
    explicit GvarWithoutId();
    bool operator==(const GvarWithoutId &other);
};
class InvalidGvarName: public DiagnosticMessage {
public:
    char c;
    explicit InvalidGvarName(char c);
    bool operator==(const InvalidGvarName &other);
};
class IvarWithoutId: public DiagnosticMessage {
public:
    
    explicit IvarWithoutId();
    bool operator==(const IvarWithoutId &other);
};
class InvalidIvarName: public DiagnosticMessage {
public:
    char c;
    explicit InvalidIvarName(char c);
    bool operator==(const InvalidIvarName &other);
};
class CvarWithoutId: public DiagnosticMessage {
public:
    
    explicit CvarWithoutId();
    bool operator==(const CvarWithoutId &other);
};
class InvalidCvarName: public DiagnosticMessage {
public:
    char c;
    explicit InvalidCvarName(char c);
    bool operator==(const InvalidCvarName &other);
};
class UnknownRegexOptions: public DiagnosticMessage {
public:
    std::string options;
    explicit UnknownRegexOptions(std::string options);
    bool operator==(const UnknownRegexOptions &other);
};
class UnterminatedUnicodeEscape: public DiagnosticMessage {
public:
    
    explicit UnterminatedUnicodeEscape();
    bool operator==(const UnterminatedUnicodeEscape &other);
};
class EncodingError: public DiagnosticMessage {
public:
    std::string error;
    explicit EncodingError(std::string error);
    bool operator==(const EncodingError &other);
};
class AmbiguousTernaryOperator: public DiagnosticMessage {
public:
    std::string condition;
    explicit AmbiguousTernaryOperator(std::string condition);
    bool operator==(const AmbiguousTernaryOperator &other);
};
class AmbiguousRegexp: public DiagnosticMessage {
public:
    
    explicit AmbiguousRegexp();
    bool operator==(const AmbiguousRegexp &other);
};
class ElseWithoutRescue: public DiagnosticMessage {
public:
    
    explicit ElseWithoutRescue();
    bool operator==(const ElseWithoutRescue &other);
};
class BeginNotAtTopLevel: public DiagnosticMessage {
public:
    
    explicit BeginNotAtTopLevel();
    bool operator==(const BeginNotAtTopLevel &other);
};
class AliasNthRef: public DiagnosticMessage {
public:
    
    explicit AliasNthRef();
    bool operator==(const AliasNthRef &other);
};
class CsendInsideMasgn: public DiagnosticMessage {
public:
    
    explicit CsendInsideMasgn();
    bool operator==(const CsendInsideMasgn &other);
};
class ClassOrModuleNameMustBeConstant: public DiagnosticMessage {
public:
    
    explicit ClassOrModuleNameMustBeConstant();
    bool operator==(const ClassOrModuleNameMustBeConstant &other);
};
class EndlessSetterDefinition: public DiagnosticMessage {
public:
    
    explicit EndlessSetterDefinition();
    bool operator==(const EndlessSetterDefinition &other);
};
class UnexpectedToken: public DiagnosticMessage {
public:
    std::string token_name;
    explicit UnexpectedToken(std::string token_name);
    bool operator==(const UnexpectedToken &other);
};
class ClassDefinitionInMethodBody: public DiagnosticMessage {
public:
    
    explicit ClassDefinitionInMethodBody();
    bool operator==(const ClassDefinitionInMethodBody &other);
};
class ModuleDefinitionInMethodBody: public DiagnosticMessage {
public:
    
    explicit ModuleDefinitionInMethodBody();
    bool operator==(const ModuleDefinitionInMethodBody &other);
};
class InvalidReturnInClassOrModuleBody: public DiagnosticMessage {
public:
    
    explicit InvalidReturnInClassOrModuleBody();
    bool operator==(const InvalidReturnInClassOrModuleBody &other);
};
class ConstArgument: public DiagnosticMessage {
public:
    
    explicit ConstArgument();
    bool operator==(const ConstArgument &other);
};
class IvarArgument: public DiagnosticMessage {
public:
    
    explicit IvarArgument();
    bool operator==(const IvarArgument &other);
};
class GvarArgument: public DiagnosticMessage {
public:
    
    explicit GvarArgument();
    bool operator==(const GvarArgument &other);
};
class CvarArgument: public DiagnosticMessage {
public:
    
    explicit CvarArgument();
    bool operator==(const CvarArgument &other);
};
class NoSuchLocalVariable: public DiagnosticMessage {
public:
    std::string var_name;
    explicit NoSuchLocalVariable(std::string var_name);
    bool operator==(const NoSuchLocalVariable &other);
};
class OrdinaryParamDefined: public DiagnosticMessage {
public:
    
    explicit OrdinaryParamDefined();
    bool operator==(const OrdinaryParamDefined &other);
};
class NumparamUsed: public DiagnosticMessage {
public:
    
    explicit NumparamUsed();
    bool operator==(const NumparamUsed &other);
};
class TokAtEolWithoutExpression: public DiagnosticMessage {
public:
    std::string token_name;
    explicit TokAtEolWithoutExpression(std::string token_name);
    bool operator==(const TokAtEolWithoutExpression &other);
};
class EndInMethod: public DiagnosticMessage {
public:
    
    explicit EndInMethod();
    bool operator==(const EndInMethod &other);
};
class ComparisonAfterComparison: public DiagnosticMessage {
public:
    std::string comparison;
    explicit ComparisonAfterComparison(std::string comparison);
    bool operator==(const ComparisonAfterComparison &other);
};
class CircularArgumentReference: public DiagnosticMessage {
public:
    std::string arg_name;
    explicit CircularArgumentReference(std::string arg_name);
    bool operator==(const CircularArgumentReference &other);
};
class DynamicConstantAssignment: public DiagnosticMessage {
public:
    
    explicit DynamicConstantAssignment();
    bool operator==(const DynamicConstantAssignment &other);
};
class CantAssignToSelf: public DiagnosticMessage {
public:
    
    explicit CantAssignToSelf();
    bool operator==(const CantAssignToSelf &other);
};
class CantAssignToNil: public DiagnosticMessage {
public:
    
    explicit CantAssignToNil();
    bool operator==(const CantAssignToNil &other);
};
class CantAssignToTrue: public DiagnosticMessage {
public:
    
    explicit CantAssignToTrue();
    bool operator==(const CantAssignToTrue &other);
};
class CantAssignToFalse: public DiagnosticMessage {
public:
    
    explicit CantAssignToFalse();
    bool operator==(const CantAssignToFalse &other);
};
class CantAssignToFile: public DiagnosticMessage {
public:
    
    explicit CantAssignToFile();
    bool operator==(const CantAssignToFile &other);
};
class CantAssignToLine: public DiagnosticMessage {
public:
    
    explicit CantAssignToLine();
    bool operator==(const CantAssignToLine &other);
};
class CantAssignToEncoding: public DiagnosticMessage {
public:
    
    explicit CantAssignToEncoding();
    bool operator==(const CantAssignToEncoding &other);
};
class CantAssignToNumparam: public DiagnosticMessage {
public:
    std::string numparam;
    explicit CantAssignToNumparam(std::string numparam);
    bool operator==(const CantAssignToNumparam &other);
};
class CantSetVariable: public DiagnosticMessage {
public:
    std::string var_name;
    explicit CantSetVariable(std::string var_name);
    bool operator==(const CantSetVariable &other);
};
class BlockGivenToYield: public DiagnosticMessage {
public:
    
    explicit BlockGivenToYield();
    bool operator==(const BlockGivenToYield &other);
};
class BlockAndBlockArgGiven: public DiagnosticMessage {
public:
    
    explicit BlockAndBlockArgGiven();
    bool operator==(const BlockAndBlockArgGiven &other);
};
class SymbolLiteralWithInterpolation: public DiagnosticMessage {
public:
    
    explicit SymbolLiteralWithInterpolation();
    bool operator==(const SymbolLiteralWithInterpolation &other);
};
class ReservedForNumparam: public DiagnosticMessage {
public:
    std::string numparam;
    explicit ReservedForNumparam(std::string numparam);
    bool operator==(const ReservedForNumparam &other);
};
class KeyMustBeValidAsLocalVariable: public DiagnosticMessage {
public:
    
    explicit KeyMustBeValidAsLocalVariable();
    bool operator==(const KeyMustBeValidAsLocalVariable &other);
};
class DuplicateVariableName: public DiagnosticMessage {
public:
    
    explicit DuplicateVariableName();
    bool operator==(const DuplicateVariableName &other);
};
class DuplicateKeyName: public DiagnosticMessage {
public:
    
    explicit DuplicateKeyName();
    bool operator==(const DuplicateKeyName &other);
};
class SingletonLiteral: public DiagnosticMessage {
public:
    
    explicit SingletonLiteral();
    bool operator==(const SingletonLiteral &other);
};
class NthRefIsTooBig: public DiagnosticMessage {
public:
    std::string nth_ref;
    explicit NthRefIsTooBig(std::string nth_ref);
    bool operator==(const NthRefIsTooBig &other);
};
class DuplicatedArgumentName: public DiagnosticMessage {
public:
    
    explicit DuplicatedArgumentName();
    bool operator==(const DuplicatedArgumentName &other);
};
class RegexError: public DiagnosticMessage {
public:
    std::string error;
    explicit RegexError(std::string error);
    bool operator==(const RegexError &other);
};
class InvalidSymbol: public DiagnosticMessage {
public:
    std::string symbol;
    explicit InvalidSymbol(std::string symbol);
    bool operator==(const InvalidSymbol &other);
};
class VoidValueExpression: public DiagnosticMessage {
public:
    
    explicit VoidValueExpression();
    bool operator==(const VoidValueExpression &other);
};

using diagnostic_message_variant_t = std::variant<
    std::unique_ptr<FractionAfterNumeric>,
    std::unique_ptr<NoDigitsAfterDot>,
    std::unique_ptr<UnknownTypeOfPercentString>,
    std::unique_ptr<NumericLiteralWithoutDigits>,
    std::unique_ptr<UnterminatedList>,
    std::unique_ptr<UnterminatedRegexp>,
    std::unique_ptr<UnterminatedString>,
    std::unique_ptr<UnterminatedQuotedString>,
    std::unique_ptr<InvalidUnicodeEscape>,
    std::unique_ptr<TooLargeUnicodeCodepoint>,
    std::unique_ptr<InvalidUnicodeCodepoint>,
    std::unique_ptr<MultipleCodepointAtSingleChar>,
    std::unique_ptr<InvalidEscapeCharacter>,
    std::unique_ptr<InvalidHexEscape>,
    std::unique_ptr<UnterminatedHeredoc>,
    std::unique_ptr<UnterminatedHeredocId>,
    std::unique_ptr<SlashRAtMiddleOfLine>,
    std::unique_ptr<DStarInterpretedAsArgPrefix>,
    std::unique_ptr<StarInterpretedAsArgPrefix>,
    std::unique_ptr<AmpersandInterpretedAsArgPrefix>,
    std::unique_ptr<TripleDotAtEol>,
    std::unique_ptr<ParenthesesIterpretedAsArglist>,
    std::unique_ptr<AmbiguousFirstArgument>,
    std::unique_ptr<AmbiguousOperator>,
    std::unique_ptr<InvalidCharacterSyntax>,
    std::unique_ptr<InvalidOctalDigit>,
    std::unique_ptr<TrailingCharInNumber>,
    std::unique_ptr<EmbeddedDocumentMeetsEof>,
    std::unique_ptr<InvalidChar>,
    std::unique_ptr<IncompleteCharacterSyntax>,
    std::unique_ptr<GvarWithoutId>,
    std::unique_ptr<InvalidGvarName>,
    std::unique_ptr<IvarWithoutId>,
    std::unique_ptr<InvalidIvarName>,
    std::unique_ptr<CvarWithoutId>,
    std::unique_ptr<InvalidCvarName>,
    std::unique_ptr<UnknownRegexOptions>,
    std::unique_ptr<UnterminatedUnicodeEscape>,
    std::unique_ptr<EncodingError>,
    std::unique_ptr<AmbiguousTernaryOperator>,
    std::unique_ptr<AmbiguousRegexp>,
    std::unique_ptr<ElseWithoutRescue>,
    std::unique_ptr<BeginNotAtTopLevel>,
    std::unique_ptr<AliasNthRef>,
    std::unique_ptr<CsendInsideMasgn>,
    std::unique_ptr<ClassOrModuleNameMustBeConstant>,
    std::unique_ptr<EndlessSetterDefinition>,
    std::unique_ptr<UnexpectedToken>,
    std::unique_ptr<ClassDefinitionInMethodBody>,
    std::unique_ptr<ModuleDefinitionInMethodBody>,
    std::unique_ptr<InvalidReturnInClassOrModuleBody>,
    std::unique_ptr<ConstArgument>,
    std::unique_ptr<IvarArgument>,
    std::unique_ptr<GvarArgument>,
    std::unique_ptr<CvarArgument>,
    std::unique_ptr<NoSuchLocalVariable>,
    std::unique_ptr<OrdinaryParamDefined>,
    std::unique_ptr<NumparamUsed>,
    std::unique_ptr<TokAtEolWithoutExpression>,
    std::unique_ptr<EndInMethod>,
    std::unique_ptr<ComparisonAfterComparison>,
    std::unique_ptr<CircularArgumentReference>,
    std::unique_ptr<DynamicConstantAssignment>,
    std::unique_ptr<CantAssignToSelf>,
    std::unique_ptr<CantAssignToNil>,
    std::unique_ptr<CantAssignToTrue>,
    std::unique_ptr<CantAssignToFalse>,
    std::unique_ptr<CantAssignToFile>,
    std::unique_ptr<CantAssignToLine>,
    std::unique_ptr<CantAssignToEncoding>,
    std::unique_ptr<CantAssignToNumparam>,
    std::unique_ptr<CantSetVariable>,
    std::unique_ptr<BlockGivenToYield>,
    std::unique_ptr<BlockAndBlockArgGiven>,
    std::unique_ptr<SymbolLiteralWithInterpolation>,
    std::unique_ptr<ReservedForNumparam>,
    std::unique_ptr<KeyMustBeValidAsLocalVariable>,
    std::unique_ptr<DuplicateVariableName>,
    std::unique_ptr<DuplicateKeyName>,
    std::unique_ptr<SingletonLiteral>,
    std::unique_ptr<NthRefIsTooBig>,
    std::unique_ptr<DuplicatedArgumentName>,
    std::unique_ptr<RegexError>,
    std::unique_ptr<InvalidSymbol>,
    std::unique_ptr<VoidValueExpression>
>;

}

#endif // LIB_RUBY_PARSER_MESSAGE_H
