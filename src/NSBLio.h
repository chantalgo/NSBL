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

//function to print all the edges and vertices of a graph 
int print_g(GraphType* g);

//function to print the graph id
int print_v(VertexType* v);

//function to print the edge id, start vertex and end vertex ids
int print_e(EdgeType* e);

//function to print the attributes of a vertex
int print_v_attr(VertexType* v);

//function to print the attributes of an edge
int print_e_attr(EdgeType* e);


#endif