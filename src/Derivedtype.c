#include "Derivedtype.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>

// may have problem when delete a ...
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

//
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
	ListType* l = (ListType*)malloc(sizeof(ListType));
	l->type = UNKNOWN_T;
    l->list = NULL;
	return l;
}

StringType* new_string(){
	return (StringType*)g_string_new("");
}

int destroy_edge(EdgeType* e){
#ifdef _DEBUG
    fprintf(stdout, "DEBUG: DESTROY EDGE: ");
    print_e(e);
    fprintf(stdout, "\n");
    fprintf(stdout, "------ REMOVE ATTR\n");
#endif
    g_hash_table_foreach(e->attributes, &destroy_attr_from_table, NULL);
    g_hash_table_destroy(e->attributes);
#ifdef _DEBUG
    fprintf(stdout, "------ REMOVE me FROM v1 and v2\n");
#endif
    VertexType* v1 = e->start;
    VertexType* v2 = e->end;
    v1->outEdges = g_list_remove(v1->outEdges, e);
    v2->inEdges = g_list_remove(v2->inEdges, e);
    e->start = NULL;
    e->end = NULL;
#ifdef _DEBUG
    fprintf(stdout, "------ REMOVE me FROM all Gs\n");
#endif
    int l = g_list_length(e->ings);
    int n = 0;
    for(n; n<l; n++){
        GraphType* g = g_list_nth_data(e->ings, n);
        g_remove_edge(g, e);
    }
#ifdef _DEBUG
    fprintf(stdout, "------ REMOVE INGs\n");
#endif
    g_list_free(e->ings);
    free(e);
    return 0;
}

int destroy_vertex(VertexType* v){
#ifdef _DEBUG
    fprintf(stdout, "DEBUG: DESTROY VERTEX: ");
    print_v(v);
    fprintf(stdout, "\n");
    fprintf(stdout, "====== REMOVE ALL ATTR\n");
#endif
    g_hash_table_foreach(v->attributes, &destroy_attr_from_table, NULL);
    g_hash_table_destroy(v->attributes);
    EdgeType* e;
    int l = g_list_length(v->outEdges);
    int n = 0;
    while ( g_list_length(v->outEdges) > 0 ){
#ifdef _DEBUG
        fprintf(stdout, "====== REMOVE OUTEdges %d/%d\n", n++, l );
#endif
        e = (EdgeType*) g_list_nth_data(v->outEdges, 0);
        destroy_edge(e);
    }
    l = g_list_length(v->inEdges);
    n = 0; 
    while ( g_list_length(v->inEdges) > 0 ) {
#ifdef _DEBUG
        fprintf(stdout, "====== REMOVE INEdges %d/%d\n", n++, l );
#endif
        e = (EdgeType*) g_list_nth_data(v->inEdges, 0);
        destroy_edge(e);
    }
    l = g_list_length(v->ings);
    for(n=0; n<l; n++){
#ifdef _DEBUG
        fprintf(stdout, "====== REMOVE me FROM ALL Gs %d/%d\n", n, l );
#endif
        GraphType* g = g_list_nth_data(v->ings, n);
        g_remove_vertex(g, v);
    }
#ifdef _DEBUG
    fprintf(stdout, "====== REMOVE MYSELF: outE, inE, ings\n");
#endif
    g_list_free(v->outEdges);
    g_list_free(v->inEdges);
    g_list_free(v->ings);
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
	g_list_free(list->list);
	free(list);
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

Attribute * new_attr( int type, void * val ) {
    Attribute * attr = (Attribute *) malloc ( sizeof( Attribute ) );
    attr->type = type;
    switch (type) {
        case INT_T :
            attr->value.iv = (val==NULL) ? 0 : *(int *)val; break;
        case FLOAT_T :
            attr->value.fv = (val==NULL) ? 0.0 : *(float *)val; break;
		case BOOL_T:
			attr->value.bv = (val==NULL) ? 0 : ((*(bool*)val > 0) ? true : false); break;
        case STRING_T :
            attr->value.sv = (val==NULL) ? NULL : val; break;
        case UNKNOWN_T :
            attr->value.sv = NULL;
            break;
        default :
            fprintf(stderr,"Derivedtype:new_attr: unknown type!!!!\n");
    }
    return attr;
}

Attribute* new_attr_INT_T(int i){
	return new_attr(INT_T, &i);
}

Attribute* new_attr_FLOAT_T(float f){
	return new_attr(FLOAT_T, &f);
}

Attribute* new_attr_BOOL_T(bool b){
	return new_attr(BOOL_T, &b);
}

Attribute* new_attr_STRING_T(GString* s){
	return new_attr(STRING_T, s);
}

int assign_attr( Attribute * attr, int type, void * val ) {
    switch (type) {
        case INT_T :
            attr->value.iv = * (int *) val; break;
        case FLOAT_T :
            attr->value.fv = * (float *) val; break;
		case BOOL_T:
			attr->value.bv = * (bool *) val; break;
        case STRING_T :
            if (attr->value.sv != NULL) g_string_free(attr->value.sv,1);
            attr->value.sv = (GString *) val;
            break;
        default :
            fprintf(stderr,"Derivedtype:assign_attr: unknown type!!!!\n");
    }
}

int cmp_attr( Attribute * attr1, void * val ) {
    switch (attr1->type) {
        case INT_T :
            return attr1->value.iv - * (int *) val;
        case FLOAT_T : {
            float tt = attr1->value.fv - * (float *) val;
            if ( tt == 0.0 ) return 0;
            else if ( tt < 0.0 ) return -1;
            else return 1;
        }
		case BOOL_T:
			return (attr1->value.bv == *(bool*)val) ? 0 : 1;
        case STRING_T :
            return strcmp( attr1->value.sv->str, ((GString*) val)->str );
        default :
            fprintf(stderr,"Derivedtype:cmp_attr: unknown type!!!!\n");
    }
}

void output_attr( char * key, Attribute * attr, FILE * out ){
    switch (attr->type) {
        case INT_T :
            fprintf(out, "%s -> %d", key, attr->value.iv); break;
        case FLOAT_T :
            fprintf(out, "%s -> %f", key, attr->value.fv); break;
		case BOOL_T:
			fprintf(out, (attr->value.bv ? "%s -> TRUE" : "%s -> FALSE"), key); break;
        case STRING_T :
            if(attr->value.sv == NULL) {
                fprintf(stderr,"output_attr: NULL String.\n");
            }
            fprintf(out, "%s -> \"%s\"", key, (attr->value.sv)->str); break;
        default :
            fprintf(stderr,"Derivedtype:output_attr: unknown type %ld!!!!\n", attr->type);
    }
        printf("\n");
}

void destroy_attr ( Attribute * attr ) {
#ifdef _DEBUG
    fprintf(stderr, "DEBUG: Destroy Attr : ");
    switch ( attr->type ) {
        case INT_T :
            fprintf(stderr, " INT_T --> %d\n", attr->value.iv); break;
        case FLOAT_T :
            fprintf(stderr, " FLOAT_T --> %f\n", attr->value.fv); break;
		case BOOL_T:
			fprintf(stderr, (attr->value.bv ? "BOOL_T --> TRUE" : "FLOAT --> FALSE")); break;
        case STRING_T :
            fprintf(stderr," STRING_T --> %s\n", attr->value.sv->str); break;
    }
#endif
    if ( attr->type == STRING_T ) g_string_free( attr->value.sv, 1 );
    free( attr );
}

static void destroy_attr_from_table ( gpointer key, gpointer entry, gpointer dummy2 ) {
    Attribute * attr = (Attribute *) entry;
    char * attr_name = (char *) key;
#ifdef _DEBUG
    fprintf(stderr, "DEBUG: Remove attr `%s' from table \n", attr_name);
#endif
    destroy_attr( attr );
}

int get_attr_value_INT_T(Attribute* attr, int lno) {
    if(attr == NULL) die(lno, "get_attr_value_INT_T: null attribute.\n");
    if(attr->type == INT_T) 
        return attr->value.iv;
    else if (attr->type == FLOAT_T) 
        return (int) attr->value.fv;
    else 
        die(lno, "get_attr_value_INT_T: atttribute type NOT INT or FLOAT\n");
}

float get_attr_value_FLOAT_T(Attribute* attr, int lno) {
    if(attr == NULL) die(lno, "get_attr_value_FLOAT_T: null attribute.\n");
    if(attr->type == INT_T) 
        return (float) attr->value.iv;
    else if (attr->type == FLOAT_T) 
        return attr->value.fv;
    else 
        die(lno, "get_attr_value_FLOAT_T: atttribute type NOT INT or FLOAT\n");
}

bool get_attr_value_BOOL_T(Attribute* attr, int lno) {
    if(attr == NULL) die(lno, "get_attr_value_BOOL_T: null attribute.\n");
    if(attr->type == BOOL_T)
        return attr->value.bv;
    else
        die(lno, "get_attr_value_BOOL_T: atttribute type NOT BOOL.\n");
}

StringType* get_attr_value_STRING_T(Attribute* attr, int lno) {
    if(attr == NULL) die(lno, "get_attr_value_STRING_T: null attribute.\n");
    if(attr->type == STRING_T)
        return attr->value.sv;
    else
        die(lno, "get_attr_value_STRING_T: atttribute type NOT STRING.\n");
}

void* get_attr_value(Attribute* attr, int type, int lno){
	if(attr == NULL) die(lno, "get_attr_value: <null> Attribute error \n");
    void * rt = NULL;
	switch(attr->type){
		case INT_T:
			rt = (void *) &(attr->value.iv);
			break;
		case FLOAT_T:
			rt = (void *) &(attr->value.fv);
			break;
		case STRING_T:
			rt = (void *) attr->value.sv;
			break;
		case BOOL_T:
			rt = (void *) &(attr->value.bv);
		default:
			return NULL;
	}
	if(type != attr->type && type != RESERVED)
    	die(lno, "get_attr_value: atttribute type dismatch : %d != %d \n", type, attr->type);
    return rt;
}

int edge_assign_attribute ( EdgeType* e, char * attr_name, void * val, int type ) {
    Attribute* attr = (Attribute*)g_hash_table_lookup(e->attributes, attr_name);
    if (attr != NULL) {
        if ( attr->type != type ) {
    		die(-1, "edge_assign_attribute: attribute type mismatch error \n");
        }
    }
    else {
        attr = new_attr( type, NULL );
        g_hash_table_insert( e->attributes, attr_name, attr );
    }
    assign_attr( attr, type, val );
    return 0;
}

int edge_remove_attribute(EdgeType* e, char* attr_name){
    if (e == NULL) {
#ifdef _DEBUG
        fprintf(stderr, "Warning: edge_remove_attribute: Edge is NULL.\n");
#endif    
        return 1;
    }
    if (!g_hash_table_remove(e->attributes, attr_name)) {
        die(-1, "edge_remove_attribute FAILURE to remove %s.\n", attr_name);
        return 2;
    }
    return 0;
}

Attribute* edge_get_attribute(EdgeType* e, char* attribute, int autoNew, int lno){	
    Attribute* attr = g_hash_table_lookup(e->attributes, attribute);
    if (attr == NULL && autoNew) {
        attr = new_attr(UNKNOWN_T, NULL);
        g_hash_table_insert( e->attributes, attribute, attr );
    }
    return attr;
}

void* edge_get_attribute_value(EdgeType* e, char* attribute, int lno){
	Attribute* attr;
	if( (attr = edge_get_attribute(e, attribute, 0, lno)) != NULL)
		return get_attr_value(attr, RESERVED,lno);
	return NULL;
}

VertexType* get_start_vertex(EdgeType* e){
    return e->start;
}

VertexType* get_end_vertex(EdgeType* e){
    return e->end;
}

int vertex_assign_attribute(VertexType* v, char* attr_name, void * val, int type ) {
    Attribute* attr = (Attribute*)g_hash_table_lookup(v->attributes, attr_name);
    if (attr != NULL) {
        if ( attr->type != type ) {
    		die(-1, "vertex_assign_attribute: attribute type mismatch error \n");
        }
    }
    else {
        attr = new_attr( type, NULL );
        g_hash_table_insert( v->attributes, attr_name, attr );
    }
    assign_attr( attr, type, val );
    return 0;
}

int vertex_remove_attribute(VertexType* v, char* attr_name) {
    if (v == NULL) {
#ifdef _DEBUG
        fprintf(stderr, "Warning: vertex_remove_attribute: Vertex is NULL.\n");
#endif
        return 1;
    }
    if (!g_hash_table_remove(v->attributes, attr_name)) {
        die(-1, "vertex_remove_attribute FAILURE to remove %s.\n", attr_name);
        return 2;
    }
    return 0;
}

Attribute* vertex_get_attribute(VertexType* v, char* attribute, int autoNew, int lno){
    Attribute* attr = g_hash_table_lookup(v->attributes, attribute);
    if (attr == NULL && autoNew) {
        attr = new_attr(UNKNOWN_T, NULL);
        g_hash_table_insert( v->attributes, attribute, attr );
    }
    return attr;
}

void* vertex_get_attribute_value(VertexType* v, char* attribute, int lno){
	Attribute* attr;
	if( (attr = vertex_get_attribute(v, attribute, 0, lno)) != NULL)
		return get_attr_value(attr, RESERVED,lno);
	return NULL;
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

int g_append_list(GraphType* g, ListType* list){
	int length = g_list_length(list->list);
	int i;
	for(i=0; i<length; i++){
		switch(list->type){
			case VERTEX_T:
				g_insert_v(g, (VertexType*)g_list_nth_data(list->list, i));
				break;
			case EDGE_T:
				g_insert_e(g, (EdgeType*)g_list_nth_data(list->list, i));
				break;
			default:
				break;
		}
	}
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

ListType* match_string(ListType* list, char* attribute, char* s){
	int l = g_list_length(list->list);
	int n = 0;
	GList* result;
	switch(list->type){
		case EDGE_T:
			for(n; n<l; n++){
				EdgeType* e = g_list_nth_data(list->list, n);
				Attribute* attr_v;
				if((attr_v = g_hash_table_lookup(e->attributes, attribute))!=NULL){
					if(strcmp(attr_v->value.sv->str, (char*)s)==0) 
						result = g_list_append(result, e);
				}	
			}
			break;
		case VERTEX_T:
			for(n; n<l; n++){
				VertexType* e = g_list_nth_data(list->list, n);
				Attribute* attr_v;
				if((attr_v = g_hash_table_lookup(e->attributes, attribute))!=NULL){
					if(strcmp(attr_v->value.sv->str, (char*)s)==0) 
						result = g_list_append(result, e);
				}	
			}
			break;
	}
	g_list_free(list->list);
	list->list = result;
	return list;
}

ListType* match_num(ListType* list, char* attribute, float cmpv, int op){
	int l = g_list_length(list->list);
	int n = 0;
	GList* result;
	void* e;
	for(n; n<l; n++){
		Attribute* attr_v;
		if(list->type == EDGE_T){
			EdgeType* p = (EdgeType*)g_list_nth_data(list->list, n);
			e = p;
			attr_v = g_hash_table_lookup(p->attributes, attribute);
		}
		else if(list->type == VERTEX_T){
			VertexType* p = (VertexType*)g_list_nth_data(list->list, n);
			e = p;
			attr_v = g_hash_table_lookup(p->attributes, attribute);
		}
		else
			break;
		if(attr_v!=NULL){
			float f=0.0;
			if(attr_v->type == INT_T)
				f = (float)attr_v->value.iv;
			else if(attr_v->type == FLOAT_T)
				f =attr_v->value.fv;
			switch(op){
				case OP_EQ:
					if(f == cmpv)
						result = g_list_append(result, e);
					break;
				case OP_GT:
					if(f > cmpv)
						result = g_list_append(result, e);
					break;
				case OP_LT:
					if(f < cmpv)
						result = g_list_append(result, e);
					break;
				case OP_GE:
					if(f >= cmpv)
						result = g_list_append(result, e);
					break;
				case OP_LE:
					if(f <= cmpv)
						result = g_list_append(result, e);
					break;
			}
		}
	}
	g_list_free(list->list);
	list->list = result;
	return list;
}

ListType* list_declaration(int type,int n, ...){
	ListType* newlist = (ListType*)malloc(sizeof(ListType));
	newlist->list = NULL;
	newlist->type = type;
	int i;
	va_list args;
	va_start(args, n);
	for(i=0; i<n; i++){
		switch(type){
			case VERTEX_T:
				{VertexType* v = va_arg(args, VertexType*);
				newlist->list = g_list_append(newlist->list, v);
				}
				break;
			case EDGE_T:
				{EdgeType* e = va_arg(args, EdgeType*);
				newlist->list = g_list_append(newlist->list, e);
				}
				break;
			default:
				break;
		}
	}
	va_end(args);
	return newlist;
}

void* list_getelement(ListType* list, int index){
	//if(g_list_length(list->list)<(index+1))
	//	return NULL;
	void * rlt = (void *) g_list_nth_data(list->list, index);
    if (rlt == NULL) die(-1,"list_getelement: member NOT exist.\n");
	return g_list_nth_data(list->list, index);
}

ListType* list_append(ListType* list, int type, void* obj){
	if(list->type == UNKNOWN_T)
		list->type = type;
	else if(list->type != type){
		die(-1, "unmatched list append element\n");
	}
	if(g_list_index(list->list, obj) == -1){
		list->list = g_list_append(list->list, obj);
	}
	return list;
}

int list_assign_element(ListType* list, int type, int index, void* obj){
	if(g_list_length(list->list)<=(index+1))
		return 1;
	if(list->type == UNKNOWN_T)
		list->type = type;
	else if(list->type != type){
		return 1;
	}
	void* p = g_list_nth_data(list->list, index);
	p = obj;
	return 0;
} 

ListType* list_append_gl(ListType* l, GList* gl, int type){
	if(l->type != type){
		die(-1,"unmatched type for list append glist\n");
	}
	int len = g_list_length(gl);
	int i;
	void* obj;
	for(i=0; i<len; i++){
		obj = g_list_nth_data(gl,i);
		list_append(l, type, obj);
	}
	return l;
}

int print_list(ListType* list){	
    int i;
	int type = list->type;
	int length = g_list_length(list->list);
    printf("<List>: ");
	for(i=0; i<length; i++){
		switch(type){
			case VERTEX_T:
				print_v((VertexType*)g_list_nth_data(list->list, i));
				break;
			case EDGE_T:
				print_e((EdgeType*)g_list_nth_data(list->list, i));
				break;
            default: die(-1, "print_list: list print wrong type\n");
				break;
		}
        printf(" ");
	}
	printf("\n");
	return 0;
}

int print_v(VertexType* v){
    printf("<Vertex: %ld>", v->id);
    return 0;
}

int print_e(EdgeType* e){
    printf("<Edge: %ld> : %ld -> %ld ", e->id, e->start->id, e->end->id);
    return 0;
}

int print_v_attr(VertexType* v){
    if( v == NULL ) 
        die(-1, "print_v_attr: NULL pointer.\n");
    GList* klist = g_hash_table_get_keys(v->attributes);
    int l = g_list_length(klist);
    int n = 0;
    printf("<Vertex> : Id = %ld\n", v->id);
    for(n; n<l; n++){
        void* key = g_list_nth_data(klist, n);
        Attribute* value = g_hash_table_lookup(v->attributes, key);
        output_attr( (char *) key, value, stdout);
    }
    g_list_free(klist);
    return 0;
}

int print_e_attr(EdgeType* e){
    GList* klist = g_hash_table_get_keys(e->attributes);
    int l = g_list_length(klist);
    int n = 0;
    printf("\nEdge Attributes=======================\n");
	printf("vstart: ");
	print_v(e->start);
	printf("--->vend: ");
	print_v(e->end);
	printf("\n");
    printf("<Edge> : Id = %ld\n", e->id);
    for(n; n<l; n++){
        void* key = g_list_nth_data(klist, n);
        Attribute* value = g_hash_table_lookup(e->attributes, key);
        output_attr( (char *) key, value, stdout);
    }
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

int print_LIST_T(ListType* l){
    print_list(l);
    return 0;
}

int print_VERTEX_T(VertexType* v){
	print_v_attr(v);
	return 0;
}

int print_EDGE_T(EdgeType* e){
	print_e_attr(e);
	return 0;
}

int print_GRAPH_T(GraphType* g){
	print_g(g);
	return 0;
}

int print_attr(Attribute* attr){
	if(attr==NULL)	
    	die(-1, "print_attr: <null> attribute \n");
	switch(attr->type){
		case BOOL_T: 
			printf((attr->value.bv)? "TRUE" : "FALSE" );
			break;
		case INT_T:
			printf("%d", attr->value.iv);
			break;
		case FLOAT_T:
			printf("%f", attr->value.fv);
			break;
		case STRING_T:
			printf("%s", (attr->value.sv)->str);
			break;
		default:
            die(-1,"print_attr: unsupported type\n");
			break;
	}
	return 0;
}

void die(int lno, char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr,"FATAL ERROR:");
    if(lno<0)
        fprintf(stderr,": ");
    else
        fprintf(stderr,"%d: ",lno);
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(EXIT_FAILURE);         // die
    return;
}


static Attribute* relational_operator( Attribute* attr1, Attribute* attr2, int op, int lno) {
    int type1 = attr1->type, type2 = attr2->type, resultype;
    Attribute* result;
    float f1, f2;
    if(type1 == INT_T)
        f1 = attr1->value.iv;
    else if(type1 == FLOAT_T)
        f1 = attr1->value.fv;
    if(type2 == INT_T)
        f2 = attr2->value.iv;
    else if(type2 == FLOAT_T)
        f2 = attr2->value.fv;
    if(type1 == INT_T && type2 == FLOAT_T ||
                type1 == FLOAT_T && type2 == FLOAT_T ||
                    type1 == FLOAT_T && type2 == INT_T ||
        type1 == INT_T && type2 == INT_T){ 
    switch(op){
        case OP_GT:
            return result = new_attr_BOOL_T(f1>f2);
        case OP_LT:
            return result = new_attr_BOOL_T(f1<f2);
        case OP_GE:
            return result = new_attr_BOOL_T(f1>=f2);
        case OP_LE:
            return result = new_attr_BOOL_T(f1<=f2);
    }
    }else
        die(lno, "relational_operator: unsupported op %d .\n",op);
}

static Attribute* math_operator( Attribute* attr1, Attribute* attr2, int op, int lno) {
    int type1 = attr1->type, type2 = attr2->type, resultype;
    Attribute* result;
    if(type1 == INT_T && type2 == INT_T) {
        result = new_attr(INT_T, NULL);
        resultype = INT_T;
    }
    else if (type1 == INT_T && type2 == FLOAT_T ||
                type1 == FLOAT_T && type2 == FLOAT_T ||
                    type1 == FLOAT_T && type2 == INT_T) {
        result = new_attr(FLOAT_T, NULL);
        resultype = FLOAT_T;
    }
    if(resultype == INT_T || resultype == FLOAT_T){
        switch (op) {
            case OP_ADD :
                if(resultype == INT_T) 
                    result->value.iv = attr1->value.iv + attr2->value.iv;
                else if (resultype == FLOAT_T)
                    result->value.fv = attr1->value.fv + attr2->value.fv;
                else
                    die(lno, "math_operator: coding error\n");
				break;
            case OP_SUB :
                if(resultype == INT_T)
                    result->value.iv = attr1->value.iv - attr2->value.iv;
                else if (resultype == FLOAT_T)
                    result->value.fv = attr1->value.fv - attr2->value.fv;
                else
                    die(lno, "math_operator: coding error\n");
				break;
            case OP_MUL :
                if(resultype == INT_T)
                    result->value.iv = attr1->value.iv * attr2->value.iv;
                else if (resultype == FLOAT_T)
                    result->value.fv = attr1->value.fv * attr2->value.fv;
                else
                    die(lno, "math_operator: coding error\n");
				break;
            case OP_DIV :
                if(resultype == INT_T)
                    result->value.iv = attr1->value.iv / attr2->value.iv;
                else if (resultype == FLOAT_T)
                    result->value.fv = attr1->value.fv / attr2->value.fv;
                else
                    die(lno, "math_operator: coding error\n");
				break;
            default:
                die(lno, "math_operator: unsupported op %d.\n",op);
        }
    }
    else
                die(lno, "math_operator: unsupported op %d.\n",op);
    return result;
}

static Attribute* logic_operator( Attribute* attr1, Attribute* attr2, int op, int lno) {
    int type1 = attr1->type, type2 = attr2->type, resultype;
    Attribute* result;
    if(attr1->type == BOOL_T && attr2->type == BOOL_T){
        switch(op){
            case OP_AND:
                return new_attr_BOOL_T(attr1->value.bv && attr2->value.bv);
            case OP_OR:
                return new_attr_BOOL_T(attr1->value.bv || attr2->value.bv);
            default: 
                die(lno, "logic_operator: unsupported op %d.",op);
        }
    }
    else
                die(lno, "logic_operator: unsupported op %d.",op);
}

static Attribute* equal_operator( Attribute* attr1, Attribute* attr2, int op, int lno) {
    int type1 = attr1->type, type2 = attr2->type, resultype;
    Attribute* result;
    if(type1 == type2){
        switch(type1){
            case INT_T:
                return result = new_attr_BOOL_T( (op==OP_EQ) ? (attr1->value.iv==attr2->value.iv) : (attr1->value.iv != attr2->value.iv) );
            case FLOAT_T:
                return result = new_attr_BOOL_T( (op==OP_EQ) ? (attr1->value.fv==attr2->value.fv) : (attr1->value.fv != attr2->value.fv) );
            case BOOL_T:
                return result = new_attr_BOOL_T( (op==OP_EQ) ? (attr1->value.bv==attr2->value.bv) : (attr1->value.bv != attr2->value.bv) );
            case STRING_T:
                return result = new_attr_BOOL_T( (op==OP_EQ) ? strcmp(attr1->value.sv->str, attr2->value.sv->str)==0 : strcmp(attr1->value.sv->str, attr2->value.sv->str)!=0 );
        }
    }
    else {
        return new_attr_BOOL_T( false );
    }
}

Attribute* binary_operator( Attribute* attr1, Attribute* attr2, int op, int reverse, int rm1, int rm2, int lno) {
    if(reverse) {
        Attribute* tmp = attr1;
        attr1 = attr2;
        attr2 = tmp;
    }
    Attribute* result;
    switch (op) {
        case OP_ADD:
        case OP_SUB:
        case OP_MUL:
        case OP_DIV:
            result = math_operator(attr1, attr2, op, lno);break;
        case OP_GT:
        case OP_LT:
        case OP_GE:
        case OP_LE:
            result = relational_operator(attr1, attr2, op, lno);break;
        case OP_AND:
        case OP_OR:
            result = logic_operator(attr1, attr2, op, lno); break;
        case OP_EQ:
        case OP_NE:
            result = equal_operator(attr1, attr2, op, lno); break;
        default:
            die(lno, "binary_opertor: unsupported OP %d.\n", op);
    }
    if(rm1==FLAG_DESTROY_ATTR) destroy_attr(attr1);
    if(rm2==FLAG_DESTROY_ATTR) destroy_attr(attr2);

    return result;
}

//static = attr1
void assign_operator_to_static(Attribute* attr1, int type, void* value, int rm_attr1, int lno){
	if(attr1 == NULL)
        die(lno, "assign_operator_to_static: <null> Attribute error\n ");
	int type1 = attr1->type;
	if(type1 == type){
		switch(type){
			case INT_T:
				*(int*)value = attr1->value.iv;
				break;
			case FLOAT_T:
				*(float*)value = attr1->value.fv;
				break;
			case BOOL_T:
				*(bool*)value = attr1->value.bv;
				break;
			case STRING_T:
				value = attr1->value.sv;
				break;
			default:
                die(lno, "assign_operator_to_static: incompatible type\n");
		}
	}
	else if(type1==FLOAT_T && type==INT_T){
		*(int*)value = (int)(attr1->value.fv);
	}
	else if(type1==INT_T && type==FLOAT_T){
		*(float*)value = (float)(attr1->value.iv);
	}
	else
                die(lno, "assign_operator_to_static: incompatible type\n");

	if(rm_attr1==FLAG_DESTROY_ATTR) destroy_attr(attr1);
}

//attr1 = attr2
Attribute* assign_operator(Attribute* attr1, Attribute* attr2, int rm_attr1, int rm_attr2, int lno){
	if(attr1 == NULL || attr2 == NULL)
        die(lno, "assign_operator: <null> Attribute error\n");
    if(attr1->type == UNKNOWN_T) attr1->type = attr2->type;
	int type1 = attr1->type, type2 = attr2->type;
	if(type1 == type2){
		switch(type1){
			case INT_T:
				attr1->value.iv = attr2->value.iv;
				break;
			case FLOAT_T:
				attr1->value.fv = attr2->value.fv;
				break;
			case BOOL_T:
				attr1->value.bv = attr2->value.bv;
				break;
			case STRING_T:
                if(attr1->value.sv != NULL) g_string_free(attr1->value.sv,1);
				attr1->value.sv = g_string_new( (attr2->value.sv)->str );
				break;
			default:
                die( lno, "assign_operator : incompatible type.\n");

		}
	}
	else if(type1==FLOAT_T && type2==INT_T){
		attr1->value.fv = (float)(attr1->value.iv);
	}
	else if(type1==INT_T && type2==FLOAT_T){
		attr1->value.iv = (int)(attr2->value.fv);
	}
	else
                die( lno, "assign_operator : incompatible type.\n");
	
	if(rm_attr2==FLAG_DESTROY_ATTR) destroy_attr(attr2);

	return attr1;
}

Attribute* unary_operator(Attribute* attr1, int op,int rm_attr1, int lno){
	if(attr1 == NULL)
        die(lno, "NULL Attribute error");
	int	type1 = attr1->type;
	Attribute* result;
	switch(op){
		case OP_PLUS:
			if(type1 == INT_T){
				result = new_attr(INT_T, NULL);
				result->value.iv = +(attr1->value.iv);
			}
			else if(type1 == FLOAT_T){
				result = new_attr(FLOAT_T, NULL);
				result->value.fv = +(attr1->value.fv);
			}
			else
                die(lno, "unary_operator: incompatible type.\n");
			break;
		case OP_MINUS:
			if(type1 == INT_T){
				result = new_attr(INT_T, NULL);
				result->value.iv = -(attr1->value.iv);
			}
			else if(type1 == FLOAT_T){
				result = new_attr(FLOAT_T, NULL);
				result->value.fv = -(attr1->value.fv);
			}
			else
                die(lno, "unary_operator: incompatible type.\n");
			break;
		case OP_NOT:
			if(type1 == BOOL_T){
				result = new_attr(BOOL_T, NULL);
				result->value.bv = !(attr1->value.bv);
			}
			else
                die(lno, "unary_operator: incompatible type %d.\n", type1);
			break;
		default:
                die(lno, "unary_operator: unknown operator.\n");
			break;
	}
	if(rm_attr1==FLAG_DESTROY_ATTR) destroy_attr(attr1);
	return result;
}

Attribute* cast_operator(Attribute* attr1, int type, int rm_attr1, int lno){
	if(attr1 == NULL)
        die(lno, "NULL Attribute error");
	int	type1 = attr1->type;
	Attribute* result;
	if(type1 == INT_T && type == FLOAT_T){
		result = new_attr(FLOAT_T, NULL);
		result->value.fv = (float)attr1->value.iv;
	}
	else if(type1 == FLOAT_T && type == INT_T){
		result = new_attr(INT_T, NULL);
		result->value.iv = (int)attr1->value.fv;
	}
	else if(type1 == INT_T && type ==INT_T){
		result = new_attr(INT_T, NULL);
		result->value.iv = attr1->value.iv;
	}
	else if(type1 == FLOAT_T && type == FLOAT_T){
		result = new_attr(FLOAT_T, NULL);
		result->value.fv = attr1->value.fv;
	}
	else
        die(lno, "cast_operator: illegal type conversion ");

	if(rm_attr1==FLAG_DESTROY_ATTR) destroy_attr(attr1);
	return result;
}

Attribute* object_get_attribute(void* v, int obj, char* attribute, int autoNew, int lno){
	if(v==NULL)
        die(lno, "object_get_attribute: null object\n");
	Attribute* attr = NULL;
	switch(obj){
		case VERTEX_T:
			attr = vertex_get_attribute((VertexType*)v, attribute, autoNew, lno);
			break;
		case EDGE_T:
			attr = edge_get_attribute((EdgeType*)v, attribute, autoNew, lno);
			break;
		default:
        	die(lno, "object_get_attribute: illegal object type\n");
	}
    if(attr==NULL)
        die(lno, "object_get_attribute: attibute `%s' not exsit.\n");
	return attr;
}

StringType*	assign_operator_string(StringType** s1, StringType** s2) {
    if (s1 != NULL) destroy_string(*s1);
    return (*s1 = *s2);
}

ListType* list_match(ListType* l, bool (*func) (void*, int), int rm_l){
	if(l==NULL)
   		die(-1,"NULL parameter error \n");
	ListType* newl = (ListType*)malloc(sizeof(ListType));
	newl->type = l->type;
	int length = g_list_length(l->list);
	int i, b;
	void* obj;
	for(i=0; i<length; i++){
		obj = g_list_nth_data(l->list, i);
		switch(l->type){
			case VERTEX_T:
				b = func(obj, VERTEX_T);
				break;
			case EDGE_T:
				b = func(obj, EDGE_T);
				break;
			default:
        		die(-1,"Illegal type error \n");
		}
		if(b){
			newl->list = g_list_append(newl->list, obj);
		}
	}
	if(rm_l == FLAG_DESTROY_ATTR)destroy_list(l);
	return newl;
}

ListType* list_pipe(ListType* l, int type, int pipe_op, int rm_l){
	ListType* newl = (ListType*)malloc(sizeof(ListType));
	newl->list = NULL;
	newl->type = type;
	int len = g_list_length(l->list);
	int i;
	for(i=0; i<len; i++){
		switch(type){
			case EDGE_T:
				if(pipe_op==OP_OUTE)
					newl = list_append_gl(newl, ((VertexType*)g_list_nth_data(l->list, i))->outEdges, EDGE_T);
				else if(pipe_op==OP_INE)
					newl = list_append_gl(newl, ((VertexType*)g_list_nth_data(l->list, i))->inEdges, EDGE_T);
				else
					die(-1,"illegal pipe op for vlist\n");
				break;
			case VERTEX_T:
				if(pipe_op==OP_SV)
					newl = list_append(newl, VERTEX_T, ((EdgeType*)g_list_nth_data(l->list, i))->start);
				else if(pipe_op==OP_EV)
					newl = list_append(newl, VERTEX_T, ((EdgeType*)g_list_nth_data(l->list, i))->end);
				else
					die(-1,"illegel pipe op for elist\n");
				break;
			default: die(-1,"illegal pipe type \n");
		}
	}
	if(rm_l == FLAG_DESTROY_ATTR)destroy_list(l);
	return newl;
}

ListType*           assign_operator_list(ListType** l1, ListType** l2) {
    if (l1 != NULL) destroy_list(*l1);
    return (*l1 = *l2);
}

VertexType*         assign_operator_vertex(VertexType** v1, VertexType** v2) {
    if (v1 != NULL) destroy_vertex(*v1);
    return (*v1 = *v2);
}

EdgeType*           assign_operator_edge(EdgeType** e1, EdgeType** e2) {
    if (e1 != NULL) destroy_edge(*e1);
    return (*e1 = *e2);
}

GraphType*          assign_operator_graph(GraphType** g1, GraphType** g2) {
    if (g1 != NULL) destroy_graph(*g1);
    return (*g1 = *g2);
}
