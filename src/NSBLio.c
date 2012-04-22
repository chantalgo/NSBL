#include <string.h>
#include <stdlib.h>
#include "NSBLio.h"

//function to print string
void printString(char* str)
{
	printf("%s",str);
}

//function to print float
void printFloat(float f)
{
	printf("%f",f);
}

//function to print integer
void printInteger(int i)
{
	printf("%d",i);
}


//function to break line(newline)
void printFromNewLine()
{
	printf("\n");
}

//graph, vertex and edge printing functions to be used from graph lib.

//function to print vertex id.
int print_v(VertexType* v){
	printf("vid: %ld ", v->id);
	return 0;
}

//function to print edge id, start vertex and end vertex ids
int print_e(EdgeType* e){
	printf("eid %ld : %ld -> %ld ", e->id, e->start->id, e->end->id);
	return 0;
}

//function to print all the vertex attributes
int print_v_attr(VertexType* v){
	GList* klist = g_hash_table_get_keys(v->attributes);
	int l = g_list_length(klist);
	int n = 0;
	printf("\nVertex Attributes=======================\n");
	for(n; n<l; n++){
		void* key = g_list_nth_data(klist, n);
		Attribute* value = g_hash_table_lookup(v->attributes, key);
		switch(value->type){
			case INT: printf("%s -> %d\n", (char*)key, *(int*)value->value);break;
			case FLOAT: printf("%s -> %f\n", (char*)key, *(float*)value->value);break;
			case STRING: printf("%s -> %s\n", (char*)key, (char*)value->value);break;
			default: break;
		}
	}
	printf("========================================\n");
	g_list_free(klist);
	return 0;
}

//function to print all the edge attributes
int print_e_attr(EdgeType* e){
	GList* klist = g_hash_table_get_keys(e->attributes);
	int l = g_list_length(klist);
	int n = 0;
	printf("\nEdge Attributes=======================\n");
	for(n; n<l; n++){
		void* key = g_list_nth_data(klist, n);
		Attribute* value = g_hash_table_lookup(e->attributes, key);
		switch(value->type){
			case INT: printf("%s -> %d\n", (char*)key, *(int*)value->value);break;
			case FLOAT: printf("%s -> %f\n", (char*)key, *(float*)value->value);break;
			case STRING: printf("%s -> %s\n", (char*)key, (char*)value->value);break;
			default: break;
		}
	}
	printf("========================================\n");
	g_list_free(klist);
	return 0;
}

//function to print all the graph vertoces and edges
int print_g(GraphType* g){
	GList* vlist = get_g_allv(g);
	GList* elist = get_g_alle(g);
	int l,n;
	printf("\nGraph===========================\n");
	l = g_list_length(vlist);
	printf("Vertices: \n");
	for(n=0; n<l; n++){
		VertexType* v = g_list_nth_data(vlist, n);
		print_v(v);
		printf(" | ");
	}
	printf("\n");

	l = g_list_length(elist);
	printf("Edges: \n");
	for(n=0; n<l; n++){
		EdgeType* e = g_list_nth_data(elist, n);
		print_e(e);
		printf(" | ");
	}
	printf("\n");
	printf("==================================\n");
	g_list_free(vlist);
	g_list_free(elist);
	return 0;
} 