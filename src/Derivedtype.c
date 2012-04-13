#include "Derivedtype.h"
#include <string.h>

EdgeType* new_edge(){
	EdgeType* edge = (EdgeType*)malloc(sizeof(EdgeType));
	edge->id = new_edgeId();
	edge->start = NULL;
	edge->end = NULL;
    edge->ings = NULL;
	edge->attributes = g_hash_table_new(g_str_hash, g_str_equal);
	return edge;
}

VertexType* new_vertex(){
	VertexType* vertex = (VertexType*)malloc(sizeof(VertexType));
	vertex->id = new_vertexId();
	vertex->attributes = g_hash_table_new(g_str_hash, g_str_equal);
	//vertex->number_of_out = 0;
	//vertex->number_of_in = 0;
	vertex->outEdges = NULL;
	vertex->inEdges = NULL;
	vertex->ings = NULL;
	return vertex;
}

GraphType* new_graph(){
	GraphType* graph = (GraphType*)malloc(sizeof(GraphType));
	graph->id = new_graphId();
	//graph->number_of_e = 0;
	//graph->number_of_v = 0;
	graph->edgeIdList = NULL;
	graph->vertexIdList = NULL;
	graph->edges = g_hash_table_new(g_str_hash, g_str_equal);
	graph->vertices = g_hash_table_new(g_int_hash, g_int_equal);
	return graph;
}

ListType* new_list(){
	return NULL;
}

StringType* new_string(){
	return (StringType*)g_string_new("");
}

int destroy_edge(EdgeType* e){
	g_hash_table_destroy(e->attributes);
	VertexType* v1 = e->start;
	VertexType* v2 = e->end;
	g_list_remove(v1->outEdges, e);
	g_list_remove(v2->inEdges, e);
	e->start = NULL;
	e->end = NULL;
    int l = g_list_length(e->ings);
    int n = 0;
    for(n; n<l; n++){
        GraphType* g = g_list_nth_data(e->ings);
        g_remove_edge(g, e);
    }
	free(e);
	return 0;
}

int destroy_vertex(VertexType* v){
	g_hash_table_destroy(v->attributes);
    EdgeType* e;
    int l = g_list_length(v->outEdges);
    int n = 0;
    for(n; n<l; n++){
        e = g_list_nth_data(v->outEdges);
        destroy_edge(e);
    }
    l = g_list_length(v->inEdges);
    n = 0;
    for(n; n<l; n++){
        e = g_list_nth_data(v->inEdges);
        destroy_edge(e);
    }
    l = g_list_length(v->ings);
    n = 0;
    for(n; n<l; n++){
        GraphType* g = g_list_nth_data(e->ings);
        g_remove_vertex(g, v);
    }
	free(v);
	return 0;
}

int destroy_graph(GraphType* g){
	//g_array_free(g->edgeIdList, 1);
	g_list_free_1(g->vertexIdList);
	//g_hash_table_destroy(g->edges);
	g_hash_table_destroy(g->vertices);
	free(g);
	return 0;
}

int destroy_list(ListType* list){
	g_list_free_1((GList*)list);
	return 0;
}

int destroy_string(StringType* s){
	g_string_free((GString*)s, 1);
	return 0;
}

int edge_assign_direction(EdgeType* e, VertexType* v1, VertexType v2){
	e->start = v1;
	e->end = v2;
	g_array_append_val(v1->outEdges, e);
	//v1->number_of_out++;
	g_array_append_val(v2->inEdges, e);
	//v2->number_of_in++;
	int l = g_list_length(v1->ings);
	int n = 0;
	for(n; n<l; n++){
		GraphType* g = g_list_nth_data(v1-ings, n);
		g_insert_v(g, v2);
	}
	return 0;
}

int edge_assign_attribute(EdgeType* e, char* attribute, void* value){
	g_hash_table_insert(e->attributes, attribute, value);
	return 0;
}

void* edge_get_attribute_value(EdgeType* e, char* attribute){
	return g_hash_table_lookup(e->attributes, attribute);
}

VertexType* get_start_vertex(EdgeType* e){
	return e->start;
}

VertexType* get_end_vertex(EdgeType* e){
	return e->end;
}

int vertex_assign_attribute(VertexType* v, char* attribute, void* value){
	g_hash_table_insert(v->attributes, attribute, value);
	return 0;
}

void* vertex_get_attribute_value(VertexType* v, char* attribute){
	return g_hash_table_lookup(v->attributes, attribute);
}

GList* get_out_edges(VertexType* v){
	return v->outEdges;
}

GList* get_in_edges(VertexType* v){
	return v->inEdges;
}

GList* get_g_allv(GraphType* g){
	GList* list = NULL;
	int l = g_list_length(g->vertexIdList);
	int n = 0;
	for(n; n<l; n++){
		int* key = g_list_nth_data(g->vertexIdList, n);
		VertexType* v = (VertexType*)g_hash_table_lookup(g->vertices, key);
		list = g_list_append(list, v);
	}
	return list;
}

GList* get_g_alle(GraphType* g){
	GList* vlist = get_g_allv(g);
	GList* elist = NULL;
	int l = g_list_length(vlist);
	int n = 0;
	for(n; n<l; n++){
		VertexType* v = g_list_nth_data(vlist, n);
		elist = g_list_concat(elist, get_out_edges(v));
	}
}

int g_remove_edge(GraphType* g, EdgeType* e){
	g_list_remove(g->edgeIdList, &(e-id));
    g_hash_table_remove(g->edges, e);
    return 0;
}

int g_remove_vertex(GraphType* g, VertexType* v){
	g_list_remove(g->vertexIdList, &(v-id));
    g_hash_table_remove(g->vertices, v);
	return 0;
}

int g_insert_v(GraphType* g, VertexType* v){
	if(g_hash_table_contains(g->vertices, &(v->id))){
		return 0;
	}
	g->vertexIdList = g_list_append(g->vertexIdList, &(v->id));
	g_hash_table_insert(g->vertices, &(v->id), v);
	v->ings = g_list_append(v->ings, g);
	GList* out_e_list = get_out_edges(v);
	int l = g_list_length(out_e_list);
	int n = 0;
	for(n; n<l; n++){
		EdgeType* e = g_list_nth_data(out_e_list);
		VertexType* vsub = e->end;
		g_insert_v(g, vsub);
	}
}

GList* edge_match(GList* elist, char* attribute, void* value, int vtype){
	int l = g_list_length(elist);
	int n = 0;
	GList* result;
	for(n; n<l; n++){
		EdgeType* e = g_list_nth_data(elist);
		void* attr_v;
		if((attr_v = g_hash_table_lookup(e->attributes, attribute))!=NULL){
				switch(vtype){
					case INT: if((int)*attr_v == (int)*value) result = g_list_append(result, e); break;
					case FLOAT: if((float)*attr_v == (float)*value) result = g_list_append(result, e); break;
					case STRING: if(strcmp((char*)attr_v, (char*)value)==0) result = g_list_append(result, e); break;
					default: break;
				}
		}
	}
	return result;
}

GList* vertex_match(GList* vlist, char* attribute, void* value, int vtype){
	int l = g_list_length(vlist);
	int n = 0;
	GList* result;
	for(n; n<l; n++){
		VertexType* v = g_list_nth_data(vlist);
		void* attr_v;
		if((attr_v = g_hash_table_lookup(v->attributes, attribute))!=NULL){
				switch(vtype){
					case INT: if((int)*attr_v == (int)*value) result = g_list_append(result, v); break;
					case FLOAT: if((float)*attr_v == (float)*value) result = g_list_append(result, v); break;
					case STRING: if(strcmp((char*)attr_v, (char*)value)==0) result = g_list_append(result, v); break;
					default: break;
				}
		}
	}
	return result;
}

EdgeId new_edegId(){
	static EdgeId eid = 0;
	return eid++;
}

VertexId new_vertexId(){
	static VertexId vid = 0;
	return vid++;
}

GraphId new_graphId(){
	static GraphId gid = 0;
	return gid++;
}
