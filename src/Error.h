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
#define ErrorEdgeAssignExpression						+26

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
#define ErrorInvalidReturnType                          +65
#define ErrorNoReturnInFunc                             +66
#define ErrorIfConditionNotBOOL                         +67
#define ErrorGetMemberForNotListType                    +68
#define ErrorVoidTypeVariableNotSupported               +69
#define ErrorPipeWrongType								+70
#define ErrorForeachType								+71
#define ErrorAssignLeftOperand                          +72
#define ErrorAssignInMatch                              +73
#define ErrorWrongArgmentType                           +74
#define ErrorGetLengthForTypeNotList                    +75
#define ErrorIllegalDerivedTypeDeclaration              +76


#define ErrorCallBreakOutsideOfLoop                     +80
#define ErrorCallContinueOutsideOfLoop                  +81
#define ErrorCallReturnOutsideOfFunc                    +82
#define ErrorDynamicAttributeUsedInNonDynamicScope      +83

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
