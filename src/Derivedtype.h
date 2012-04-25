#ifndef DERIVEDTYPE_H_NSBL
#define DERIVEDTYPE_H_NSBL

#include <glib/ghash.h>
#include <glib/gstring.h>
#include <glib/glist.h>
#include <glib/garray.h>
#include <glib/gslist.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>

#define INT 1
#define FLOAT 2
#define STRING 3
#define VERTEX 4
#define EDGE 5

#define EQ 30
#define GE 31
#define LE 32
#define GT 33
#define LT 34


typedef long int EdgeId;
typedef long int VertexId;
typedef long int GraphId;
typedef GHashTable AttributeTable;

//typedef GList ListType;
//typedef GString StringType;

typedef struct{
	long int type;
	void* value;
}Attribute;

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
	EdgeId id;
	VertexType* start;
	VertexType* end;
    GList* ings;
	AttributeTable* attributes;
}EdgeType;

typedef struct{
	GraphId id;
	//int number_of_e;
	//int number_of_v;
	GList* edgeIdList;
	GList* vertexIdList;
	GHashTable* edges;
	GHashTable* vertices;
}GraphType;

typedef struct{
	int type;
	GList* list;
}ListType;

/*Function declaration*/
/*Init*/
EdgeType* new_edge();
VertexType* new_vertex();
GraphType* new_graph();
//ListType* new_list();
//StringType* new_string();

int destroy_edge(EdgeType* e);
int destroy_vertex(VertexType* v);
int destroy_graph(GraphType* g);
//int destroy_list(ListType* list);
//int destroy_string(StringType* s);

int edge_assign_direction(EdgeType* e, VertexType* v1, VertexType* v2);
int edge_assign_attribute(EdgeType* e, char* attribute, void* value, int type);
void* edge_get_attribute_value(EdgeType* e, char* attribute);
VertexType* get_end_vertex(EdgeType* e);
VertexType* get_start_vertex(EdgeType* e);

int vertex_assign_attribute(VertexType* v, char* attribute, void* value, int type);
void* vertex_get_attribute_value(VertexType* v, char* attribute);
GList* get_v_outedges(VertexType* v);
GList* get_v_inedges(VertexType* v);

GList* get_ving_outedges(GraphType* g, VertexType* v);
GList* get_ving_inedges(GraphType* g, VertexType* v);

GList* get_g_alle(GraphType* g);
GList* get_g_allv(GraphType* g);
int g_remove_edge(GraphType* g, EdgeType* e);
int g_remove_vertex(GraphType* g, VertexType* v);
int g_insert_v(GraphType* g, VertexType* v);
int g_insert_e(GraphType* g, EdgeType* v);
int g_insert_subg(GraphType* g, GraphType* subg);
int g_append_list(GraphType* g, ListType* list);

ListType* match_string(ListType* list, char* attribute, char* s);

ListType* match_num(ListType* list, char* attribute, float a, op);

ListType* pipe(ListType* list, int pipiop);

ListType* list_declaration(int type, int n, ...);
void* list_getelement(ListType* list, int index);
int list_append(ListType* list, int type, void* obj);
int list_assign(ListType* list, int type, int index, void* obj);

/*print functions*/
int print_g(GraphType* g);
int print_v(VertexType* v);
int print_e(EdgeType* e);
int print_v_attr(VertexType* v);
int print_e_attr(EdgeType* e);
int print_list(ListType* list);

//int list_append(ListType* list, void* data);
//ListType* list_declare(...);
//int list_remove(void* data);

//StringType* string_append(StringType* s, const char* seq);
#endif
