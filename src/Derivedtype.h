#ifndef DERIVEDTYPE_H_NSBL
#define DERIVEDTYPE_H_NSBL
#include "type.h"
#include "operator.h"

#include <glib/ghash.h>
#include <glib/gstring.h>
#include <glib/glist.h>
#include <glib/garray.h>
#include <glib/gslist.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>


#define FLAG_NO_REVERSE         0
#define FLAG_REVERSE            1
#define FLAG_KEEP_ATTR          0
#define FLAG_DESTROY_ATTR       1

#define EQ 30
#define GE 31
#define LE 32
#define GT 33
#define LT 34


typedef long int EdgeId;
typedef long int VertexId;
typedef long int GraphId;
typedef GHashTable AttributeTable;

typedef GString StringType;

typedef union {
    int         iv;
    float       fv;
    char *      sv;
}AttrValue;

typedef struct{
	long int    type;
	AttrValue   value;
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
EdgeType*           new_edge();
VertexType*         new_vertex();
GraphType*          new_graph();
ListType*           new_list();
StringType*         new_string();

int                 destroy_edge(EdgeType* e);
int                 destroy_vertex(VertexType* v);
int                 destroy_graph(GraphType* g);
int                 destroy_list(ListType* list);
int                 destroy_string(StringType* s);

Attribute*          new_attr( int type, void * val );
void                destroy_attr ( Attribute * attr );
int                 assign_attr( Attribute * attr, int type, void * val );
int                 cmp_attr( Attribute * attr1, void * val );
void                output_attr( char * key, Attribute * attr, FILE * out );
static void         destroy_attr_from_table ( gpointer key, gpointer entry, gpointer dummy2 );
void *              get_attr_value( Attribute * attr, int type );       //TODO

int                 edge_assign_direction(EdgeType* e, VertexType* v1, VertexType* v2);
int                 edge_assign_attribute(EdgeType* e, char* attribute, void* value, int type);
int                 edge_remove_attribute(EdgeType* e, char* attribute);
Attribute*          edge_get_attribute(EdgeType* e, char* attribute);       //TODO
void*               edge_get_attribute_value(EdgeType* e, char* attribute);
VertexType*         get_end_vertex(EdgeType* e);
VertexType*         get_start_vertex(EdgeType* e);

int                 vertex_assign_attribute(VertexType* v, char* attribute, void* value, int type);
int                 vertex_remove_attribute(VertexType* v, char* attribute);
Attribute*          vertex_get_attribute(VertexType* v, char* attribute);       //TODO
void*               vertex_get_attribute_value(VertexType* v, char* attribute);
GList*              get_v_outedges(VertexType* v);
GList*              get_v_inedges(VertexType* v);

GList*              get_ving_outedges(GraphType* g, VertexType* v);
GList*              get_ving_inedges(GraphType* g, VertexType* v);

GList*              get_g_alle(GraphType* g);
GList*              get_g_allv(GraphType* g);
int                 g_remove_edge(GraphType* g, EdgeType* e);
int                 g_remove_vertex(GraphType* g, VertexType* v);
int                 g_insert_v(GraphType* g, VertexType* v);
int                 g_insert_e(GraphType* g, EdgeType* v);
int                 g_insert_subg(GraphType* g, GraphType* subg);
int					g_append_list(GraphType* g, ListType* list);

ListType* 			match_string(ListType* list, char* attribute, char* s);
ListType* 			match_num(ListType* list, char* attribute, float a, int op);
ListType* 			pipe(ListType* list, int pipiop);


ListType* 			list_declaration(int type, int n, ...);
void* 				list_getelement(ListType* list, int index);
int 				list_append(ListType* list, int type, void* obj);
int 				list_assign(ListType* list, int type, int index, void* obj);

/*print functions*/
int                 print_g(GraphType* g);
int                 print_v(VertexType* v);
int                 print_e(EdgeType* e);
int                 print_v_attr(VertexType* v);
int                 print_e_attr(EdgeType* e);

//TODO
Attribute*          binary_operator( Attribute* attr1, Attribute* attr2, int op, int reverse, int rm_attr1, int rm_attr2, int lno);
// static = attr1
void                assign_operator_to_static( Attribute* attr1, int type, void * value, int rm_attr1, int lno);
// attr1 = attr2
Attribute*          assign_operator( Attribute* attr1, Attribute* attr2, int rm_attr1, int rm_attr2, int lno);
Attribute*          unary_operator( Attribute* attr1, int op, int rm_attr1, int lno);
Attribute*          cast_operator( Attribute* attr1, int op, int rm_attr1, int lno);
Attribute*          object_get_attribute(void* v, int obj, char* attribute);
ListType*           list_match( ListType * l, bool (*func) (void *, int ), int rm_l );

// DONE
StringType*         assign_operator_string(StringType* s1, StringType* s2);
ListType*           assign_operator_list(ListType* l1, ListType* l2);
VertexType*         assign_operator_vertex(VertexType* v1, VertexType* v2);
EdgeType*           assign_operator_edge(EdgeType* e1, EdgeType* e2);
GraphType*          assign_operator_graph(GraphType* g1, GraphType* g2);

//int list_append(ListType* list, void* data);
//ListType* list_declare(...);
//int list_remove(void* data);

//StringType* string_append(StringType* s, const char* seq);
#endif
