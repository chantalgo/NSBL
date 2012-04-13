#ifndef DERIVEDTYPE_H_NSBL
#define DERIVEDTYPE_H_NSBL

#include <glib/ghash.h>
#include <glib/gstring.h>
#include <glib/glist.h>
#include <glib/garray.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#define INT 1
#define FLOAT 2
#define STRING 3

typedef int EdgeId;
typedef int VertexId;
typedef int GraphId;
typedef GHashTable AttributeTable;

typedef GList ListType;
typedef GString StringType;

typedef struct{
	EdgeId id;
	VertexType* start;
	VertexType* end;
    GList* ings;
	AttributeTable* attributes;
}EdgeType;

typedef struct{
	VertexId id;
	AttributeTable* attributes;
	//int number_of_out;
	//int number_of_in;
	GList* ings;
	GList* outEdges;
	GList* inEdges;
}VertexType;

typedef struct{
	GraphId id;
	//int number_of_e;
	//int number_of_v;
	GList* edgeIdList;
	GList* vertexIdList;
	GHashTable* edges;
	GHashTable* vertices;
}GraphType;

/*Function declaration*/
/*Init*/
EdgeType* new_edge();
VertexType* new_vertex();
GraphType* new_graph();
ListType* new_list();
StringType* new_string();

int destroy_edge(EdgeType* e);
int destroy_vertex(VertexType* v);
int destroy_graph(GraphType* g);
int destroy_list(ListType* list);
int destroy_string(StringType* s);

int edge_assign_direction(EdgeType* e, VertexType* v1, VertexType* v2);
int edge_assign_attribute(EdgeType* e, char* attribute, void* value);
void* edge_get_attribute_value(EdgeType* e, char* attribute);
VertexType* get_end_vertex(EdgeType* e);
VertexType* get_start_vertex(EdgeType* e);

int vertex_assign_attribute(VertexType* v, char* attribute, void* value);
void* vertex_get_attribute_value(VertexType* v, char* attribute);
GList* get_out_edges(VertexType* v);
GList* get_in_edges(VertexType* v);

GList* get_g_alle(GraphType* g);
GList* get_g_allv(GraphType* g);
int g_remove_edge(EdgeType* e);
int g_remove_vertex(GraphType* g, VertexType* v);
int g_insert_v(GraphType* g, VertexType* v);
int g_insert_subg(GraphType* g, GraphType* subg);

GList* edge_match(GList* elist, char* attribute, void* value);
GList* vertex_match(GList* vlist, char* attribute, void* value);

int list_append(ListType* list, void* data);
ListType* list_declare(...);
int list_remove(void* data);

StringType* string_append(StringType* s, const char* seq);
#endif