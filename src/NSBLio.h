#ifndef NSBLIO_H_NSBL
#define NSBLIO_H_NSBL

#include <stdio.h>
#include <string.h>
#include "Derivedtype.h"

//function to print string
void printString(char* str);

//function to print float
void printFloat(float f);

//function to print integer
void printInteger(int i);

//function to break line(newline)
void printFromNewLine();

//graph, vertex and edge printing functions to be used from graph lib. 

/*print functions for graph, 
edge and vertex*/
int print_g(GraphType* g);
int print_v(VertexType* v);
int print_e(EdgeType* e);
int print_v_attr(VertexType* v);
int print_e_attr(EdgeType* e);


#endif