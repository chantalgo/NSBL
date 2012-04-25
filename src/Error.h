#ifndef ERROR_H_NSBL_
#define ERROR_H_NSBL_

/*******************
 * Internal Errors *
 *******************/
#define ErrorSymbolTableKeyAlreadyExsit                 -301
#define ErrorNoBinderForId                              -302
#define ErrorNoBinderForAttribute                       -303

/******************
 * Compiler Error *
 ******************/
// Lex 0-20
#define ErrorUnrecognizedLexeme                         +1

// syntax 21-50
#define ErrorSyntax                                     +21
#define ErrorAttributeDeclaration						+22
#define ErrorDerivedTypeDeclaration						+23
#define ErrorAssignmentExpression						+24
#define ErrorListMixedType								+25

// semantic 51-80
#define ErrorIdentifierAlreadyDeclared                  +51
#define ErrorIdentifierUsedBeforeDeclaration            +52
#define ErrorFunctionCalledBeforeDeclaration            +53
#define ErrorFunctionCallNOTEqualNumberOfParameters     +54
#define ErrorFunctionCallIncompatibleParameterType      +55
#define ErrorFuncLiteralCallIncompatibleParameterType   +56
#define ErrorAttributeTypeNotSupported                  +57
#define ErrorDeclareAttrForWrongType                    +58
#define ErrorDelAttrFromWrongType                       +59
#define ErrorDelVariableOfWrongType                     +60
#define ErrorBinaryOperationWithDynamicType             +61
#define ErrorGetAttrForWrongType                        +62
#define ErrorMactchWrongType                            +63
#define ErrorWrongFuncCall                              +64


#define ErrorCallBreakOutsideOfLoop                     +70
#define ErrorCallContinueOutsideOfLoop                  +71
#define ErrorCallReturnOutsideOfFunc                    +72

#define ErrorDynamicAttributeUsedInNonDynamicScope      +81

#define ErrorOperatorNotSupportedByType                 +91
#define ErrorTypeMisMatch                               +92
#define ErrorCastType                                   +93
/**********
 * output *
 **********/
// ATTENTION: always set ERRNO before calling errorInfo
void errorInfo(int eno, long long line, char* fmt, ...);
void errorInfoExt(char* fmt, ...);
void errorInfoNote(char* fmt, ...);
#endif
