#include "Derivedtype.h"
#include <string.h>
#include <stdlib.h>

EdgeId new_edgeId(){
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

int g_hash_table_contains(GHashTable* t, void* key1){
	GList* list = g_hash_table_get_keys(t);
	int l = g_list_length(list);
	int n = 0;
	for(n; n<l; n++){
		void* key2 = g_list_nth_data(list,n);
		if(*(int*)key1 == *(int*)key2){
			g_list_free(list);
			return 1;
		}
	}
	g_list_free(list);
	return 0;
}

EdgeType* new_edge(){
	EdgeType* edge = (EdgeType*) malloc(sizeof(EdgeType));
	edge->id = new_edgeId();
	edge->start = NULL;
	edge->end = NULL;
    edge->ings = NULL;
	edge->attributes = g_hash_table_new(g_str_hash, g_str_equal);
	return edge;
}

VertexType* new_vertex(){
	VertexType* vertex = (VertexType*) malloc(sizeof(VertexType));
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
	GraphType* graph = (GraphType*) malloc(sizeof(GraphType));
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
	v1->outEdges = g_list_remove(v1->outEdges, e);
	v2->inEdges = g_list_remove(v2->inEdges, e);
	e->start = NULL;
	e->end = NULL;
    int l = g_list_length(e->ings);
    int n = 0;
    for(n; n<l; n++){
        GraphType* g = g_list_nth_data(e->ings, n);
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
	for(n=0; n<l; n++){
        e = g_list_nth_data(v->outEdges, n);
        destroy_edge(e);
    }
    l = g_list_length(v->inEdges);
    for(n=0; n<l; n++){
        e = g_list_nth_data(v->inEdges, n);
        destroy_edge(e);
    }
    l = g_list_length(v->ings);
    for(n=0; n<l; n++){
        GraphType* g = g_list_nth_data(e->ings, n);
        g_remove_vertex(g, v);
    }
	free(v);
	return 0;
}

int destroy_graph(GraphType* g){
	g_list_free_1(g->edgeIdList);
	g_list_free_1(g->vertexIdList);
	g_hash_table_destroy(g->edges);
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

int edge_assign_direction(EdgeType* e, VertexType* v1, VertexType* v2){
	e->start = v1;
	e->end = v2;
	v1->outEdges = g_list_append(v1->outEdges, e);
	//v1->number_of_out++;
	//
	v2->inEdges = g_list_append(v2->inEdges, e);
	//v2->number_of_in++;
	return 0;
}

int edge_assign_attribute(EdgeType* e, char* attribute, void* value, int type){
	Attribute* exist = (Attribute*)g_hash_table_lookup(e->attributes, attribute);
	if(exist != NULL){
		if(exist->type != type){
			//dynamic type error handler
			return 1;
		}
		else{
			switch(type){
				case INT:
					*(int*)exist->value = *(int*)value;
					break;
				case FLOAT:
					*(float*)exist->value = *(float*)value;
					break;
				case STRING:
					free(exist->value);
				{
				int len = strlen((char*)value)+1;
				char* scopy = (char*)malloc(sizeof(char)*len);
				char* s = (char*)value;
				int i = 0;
				for(i; i<len; i++){
					scopy[i] = s[i];
				}
				exist->value = (void*)scopy;
				}
				break;
			}
		}
	}else{
		Attribute* attr = (Attribute*) malloc(sizeof(Attribute));
		attr->type = type;
		switch(type){
			case INT:
				attr->value = malloc(sizeof(int));
				*(int*)attr->value = *(int*)value;
				break;
			case FLOAT:
				attr->value = malloc(sizeof(float));
				*(float*)attr->value = *(float*)value;
				break;
			case STRING:
				{
				int len = strlen((char*)value)+1;
				char* scopy = (char*)malloc(sizeof(char)*len);
				char* s = (char*)value;
				int i = 0;
				for(i; i<len; i++){
					scopy[i] = s[i];
				}
				attr->value = (void*)scopy;
				}
				break;
		}
		g_hash_table_insert(e->attributes, attribute, attr);
	}
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

int vertex_assign_attribute(VertexType* v, char* attribute, void* value, int type){
	Attribute* exist = (Attribute*)g_hash_table_lookup(v->attributes, attribute);
	if(exist != NULL){
		if(exist->type != type){
			//dynamic type error handler
			return 1;
		}else{			
			switch(type){
				case INT:
					*(int*)exist->value = *(int*)value;
					break;
				case FLOAT:
					*(float*)exist->value = *(float*)value;
					break;
				case STRING:
					free(exist->value);
				{
				int len = strlen((char*)value)+1;
				char* scopy = (char*)malloc(sizeof(char)*len);
				char* s = (char*)value;
				int i = 0;
				for(i; i<len; i++){
					scopy[i] = s[i];
				}
				exist->value = (void*)scopy;
				}
				break;
			}
		}
	}else{
		Attribute* attr = (Attribute*) malloc(sizeof(Attribute));
		attr->type = type;
		switch(type){
			case INT:
				attr->value = malloc(sizeof(int));
				*(int*)attr->value = *(int*)value;
				break;
			case FLOAT:
				attr->value = malloc(sizeof(float));
				*(float*)attr->value = *(float*)value;
				break;
			case STRING:
				{
				int len = strlen((char*)value)+1;
				char* scopy = (char*)malloc(sizeof(char)*len);
				char* s = (char*)value;
				int i = 0;
				for(i; i<len; i++){
					scopy[i] = s[i];
				}
				attr->value = (void*)scopy;
				}
				break;
		}
		g_hash_table_insert(v->attributes, attribute, attr);
	}
	return 0;
}

void* vertex_get_attribute_value(VertexType* v, char* attribute){
	return g_hash_table_lookup(v->attributes, attribute);
}

GList* get_v_outedges(VertexType* v){
	return v->outEdges;
}

GList* get_v_inedges(VertexType* v){
	return v->inEdges;
}

GList* get_common_edges(GHashTable* edges, GList* list){
	GList* common = NULL;
	int l = g_list_length(list);
	int n = 0;
	for(n; n<l; n++){
		EdgeType* e = g_list_nth_data(list, n);
		if(g_hash_table_contains(edges, &(e->id)))
			common = g_list_append(common, e);
	}
	return common;
}

GList* get_ving_outedges(GraphType* g, VertexType* v){
	GList* elist = get_v_outedges(v);
	return get_common_edges(g->edges, elist);
}

GList* get_ving_inedges(GraphType* g, VertexType* v){
	GList* elist = get_v_inedges(v);
	return get_common_edges(g->edges, elist);
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
	GList* list = NULL;
	int l = g_list_length(g->edgeIdList);
	int n = 0;
	for(n; n<l; n++){
		int* key = g_list_nth_data(g->edgeIdList, n);
		EdgeType* e = (EdgeType*)g_hash_table_lookup(g->edges, key);
		list = g_list_append(list, e);
	}
	return list;
}

int g_remove_edge(GraphType* g, EdgeType* e){
	g->edgeIdList = g_list_remove(g->edgeIdList, &(e->id));
    g_hash_table_remove(g->edges, e);
    return 0;
}

int g_remove_vertex(GraphType* g, VertexType* v){
	g->vertexIdList = g_list_remove(g->vertexIdList, &(v->id));
    g_hash_table_remove(g->vertices, v);
	return 0;
}

int g_insert_v(GraphType* g, VertexType* v){
	g->vertexIdList = g_list_append(g->vertexIdList, &(v->id));
	g_hash_table_insert(g->vertices, &(v->id), v);
	v->ings = g_list_append(v->ings, g);
	return 0;
}

int g_insert_e(GraphType* g, EdgeType* e){
	g->edgeIdList = g_list_append(g->edgeIdList, &(e->id));
	g_hash_table_insert(g->edges, &(e->id), e);
	e->ings = g_list_append(e->ings, g);
	return 0;

}

int g_insert_subg(GraphType* g, GraphType* subg){
	int l,n;
	l = g_list_length(subg->vertexIdList);
	for(n=0; n<l; n++){
		int* key = g_list_nth_data(subg->vertexIdList, n);
		if(g_hash_table_contains(subg->vertices, key))
			continue;
		else{
			g->vertexIdList = g_list_append(g->vertexIdList, key);
			VertexType* v = g_hash_table_lookup(subg->vertices, key);
			g_hash_table_insert(g->vertices, key, v);
		}
	}
	l = g_list_length(subg->edgeIdList);
	for(n=0; n<l; n++){
		int* key = g_list_nth_data(subg->edgeIdList, n);
		if(g_hash_table_contains(subg->edges, key))
			continue;
		else{
			g->edgeIdList = g_list_append(g->edgeIdList, key);
			EdgeType* e = g_hash_table_lookup(subg->edges, key);
			g_hash_table_insert(g->edges, key, e);
		}
	}
}

GList* edge_match(GList* elist, char* attribute, void* value){
	int l = g_list_length(elist);
	int n = 0;
	GList* result;
	for(n; n<l; n++){
		EdgeType* e = g_list_nth_data(elist, n);
		Attribute* attr_v;
		if((attr_v = g_hash_table_lookup(e->attributes, attribute))!=NULL){
				switch(attr_v->type){
					case INT: if(*(int*)attr_v->value == *(int*)value) result = g_list_append(result, e); break;
					case FLOAT: if(*(float*)attr_v->value == *(float*)value) result = g_list_append(result, e); break;
					case STRING: if(strcmp((char*)attr_v->value, (char*)value)==0) result = g_list_append(result, e); break;
					default: break;
				}
		}
	}
	return result;
}

GList* vertex_match(GList* vlist, char* attribute, void* value){
	int l = g_list_length(vlist);
	int n = 0;
	GList* result;
	for(n; n<l; n++){
		VertexType* v = g_list_nth_data(vlist, n);
		Attribute* attr_v;
		if((attr_v = g_hash_table_lookup(v->attributes, attribute))!=NULL){
				switch(attr_v->type){
					case INT: if(*(int*)attr_v->value == *(int*)value) result = g_list_append(result, v); break;
					case FLOAT: if(*(float*)attr_v->value == *(float*)value) result = g_list_append(result, v); break;
					case STRING: if(strcmp((char*)attr_v->value, (char*)value)==0) result = g_list_append(result, v); break;
					default: break;
				}
		}
	}
	return result;
}

int print_v(VertexType* v){
	printf("vid: %ld ", v->id);
	return 0;
}

int print_e(EdgeType* e){
	printf("eid %ld : %ld -> %ld ", e->id, e->start->id, e->end->id);
	return 0;
}

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
