#ifndef ERROR_H___NSBL_
#define ERROR_H___NSBL_

/*******************
 * Internal Errors *
 *******************/
#define ErrorSymbolTableKeyAlreadyExsit                 -301

/******************
 * Compiler Error *
 ******************/
#define ErrorIdentifierAlreadyDeclared                  +901
#define ErrorIdentifierUsedBeforeDeclaration            +902
#define ErrorFunctionCalledBeforeDeclaration            +903
#define ErrorFunctionCallNOTEqualNumberOfParameters     +904
#define ErrorFunctionCallIncompatibleParameterType      +905
#define ErrorFuncLiteralCallIncompatibleParameterType   +906

#define ErrorDynamicAttributeUsedInNonDynamicScope      +920


/**********
 * output *
 **********/
// ATTENTION: always set ERRNO before calling errorInfo
void errorInfo(char* fmt, ...);
void errorInfoExt(char* fmt, ...);
void errorInfoNote(char* fmt, ...);
#endif
