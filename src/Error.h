#ifndef ERROR_H___NSBL_
#define ERROR_H___NSBL_

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

// semantic 51-80
#define ErrorIdentifierAlreadyDeclared                  +51
#define ErrorIdentifierUsedBeforeDeclaration            +52
#define ErrorFunctionCalledBeforeDeclaration            +53
#define ErrorFunctionCallNOTEqualNumberOfParameters     +54
#define ErrorFunctionCallIncompatibleParameterType      +55
#define ErrorFuncLiteralCallIncompatibleParameterType   +56

#define ErrorCallBreakOutsideOfLoop                     +60
#define ErrorCallContinueOutsideOfLoop                  +61
#define ErrorCallReturnOutsideOfFunc                    +62

#define ErrorDynamicAttributeUsedInNonDynamicScope      +71

#define ErrorOperatorNotSupportedByType                 +81
#define ErrorTypeMisMatch                               +82
#define ErrorCastType                                   +83
/**********
 * output *
 **********/
// ATTENTION: always set ERRNO before calling errorInfo
void errorInfo(int eno, long long line, char* fmt, ...);
void errorInfoExt(char* fmt, ...);
void errorInfoNote(char* fmt, ...);
#endif
