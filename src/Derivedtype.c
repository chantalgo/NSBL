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

//ListType* new_list(){
//	return NULL;
//}

//StringType* new_string(){
//	return (StringType*)g_string_new("");
//}

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

//int destroy_list(ListType* list){
//	g_list_free_1((GList*)list);
//	return 0;
//}

//int destroy_string(StringType* s){
//	g_string_free((GString*)s, 1);
//	return 0;
//}

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
        case STRING_T :
            attr->value.sv = (val==NULL) ? NULL : val; break;
        default :
            fprintf(stderr,"Derivedtype:new_attr: unknown type!!!!\n");
    }
    return attr;
}

int assign_attr( Attribute * attr, int type, void * val ) {
    switch (type) {
        case INT_T :
            attr->value.iv = * (int *) val; break;
        case FLOAT_T :
            attr->value.fv = * (float *) val; break;
        case STRING_T :
            if (attr->value.sv != NULL) free(attr->value.sv);
            char *str = (char *) val;
            int slen = strlen(str);
            attr->value.sv = (char *) malloc ( slen );
            strcpy( attr->value.sv, str );
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
        case STRING_T :
            return strcmp( attr1->value.sv, (char *) val );
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
        case STRING_T :
            fprintf(out, "%s -> \"%s\"", key, attr->value.sv); break;
        default :
            fprintf(stderr,"Derivedtype:output_attr: unknown type!!!!\n");
    }
        printf("\n");
}

void destroy_attr ( Attribute * attr ) {
#ifdef _DEBUG
    fprintf(stderr, "DEBUG: Destroy Attr : ");
    switch ( attr->type ) {
        case INT_T :
            fprintf(stderr, " INT_T --> %d\n", attr->value.sv); break;
        case FLOAT_T :
            fprintf(stderr, " FLOAT_T --> %f\n", attr->value.fv); break;
        case STRING_T :
            fprintf(stderr," STRING_T --> %s\n", attr->value.sv); break;
    }
#endif
    if ( attr->type == STRING_T ) free( attr->value.sv );
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

int edge_assign_attribute ( EdgeType* e, char * attr_name, void * val, int type ) {
    Attribute* attr = (Attribute*)g_hash_table_lookup(e->attributes, attr_name);
    if (attr != NULL) {
        if ( attr->type != type ) {
            //dynamic type error handler
            return 1;
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
        fprintf(stderr, "Runtime Error: edge_remove_attribute FAILURE to remove %s.\n", attr_name);
        return 2;
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

int vertex_assign_attribute(VertexType* v, char* attr_name, void * val, int type ) {
    Attribute* attr = (Attribute*)g_hash_table_lookup(v->attributes, attr_name);
    if (attr != NULL) {
        if ( attr->type != type ) {
            //dynamic type error handler
            return 1;
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
        fprintf(stderr, "Runtime Error: vertex_remove_attribute FAILURE to remove %s.\n", attr_name);
        return 2;
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

int g_append_list(GraphType* g, ListType* list){
	int length = g_slist_length(list->list);
	int i;
	for(i=0; i<length; i++){
		switch(list->type){
			case VERTEX_T:
				g_insert_v(g, (VertexType*)g_slist_nth_data(list->list, i));
				break;
			case EDGE_T:
				g_insert_e(g, (EdgeType*)g_slist_nth_data(list->list, i));
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

GList* edge_match(GList* elist, char* attribute, void* value){
    int l = g_list_length(elist);
    int n = 0;
    GList* result;
    for(n; n<l; n++){
        EdgeType* e = g_list_nth_data(elist, n);
        Attribute* attr_v;
        if((attr_v = g_hash_table_lookup(e->attributes, attribute))!=NULL){
            if ( cmp_attr(attr_v, value ) == 0 ) result = g_list_append(result, e);
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
            if ( cmp_attr(attr_v, value ) == 0 ) result = g_list_append(result, v);
        }
    }
    return result;
}

ListType* list_declaration(int type,int n, ...){
	ListType* newlist = (ListType*)malloc(sizeof(ListType));
	newlist->list = NULL;
	newlist->type = type;
	int i;
	va_list args;
	va_start(args, type);
	for(i=0; i<n; i++){
		switch(type){
			case VERTEX_T:
				{VertexType* v = va_arg(args, struct VertexType*);
				newlist->list = g_slist_append(newlist->list, v);
				}
				break;
			case EDGE_T:
				{EdgeType* e = va_arg(args, struct EdgeType*);
				newlist->list = g_slist_append(newlist->list, e);
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
	if(g_slist_length(list->list)<=(index+1))
		return NULL;
	return g_slist_nth_data(list->list, index);
}

int list_append(ListType* list, int type, void* obj){
	if(list->type == -1)
		list->type = type;
	else if(list->type != type){
		return 1;
	}
	list->list = g_slist_append(list->list, obj);
	return 0;
}

int list_assign(ListType* list, int type, int index, void* obj){
	if(g_slist_length(list->list)<=(index+1))
		return 1;
	if(list->type == -1)
		list->type = type;
	else if(list->type != type){
		return 1;
	}
	void* p = g_slist_nth_data(list->list, index);
	p = obj;
	return 0;
} 

int print_list(ListType* list){	
    int i;
	int type = list->type;
	int length = g_slist_length(list->list);
	for(i=0; i<length; i++){
		switch(type){
			case VERTEX_T:
				print_v((VertexType*)g_slist_nth_data(list->list, i));
				break;
			case EDGE_T:
				print_e((EdgeType*)g_slist_nth_data(list->list, i));
				break;
			default:
				break;
		}
	}
	printf("\n");
	return 0;
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
    printf("\nVertex Attributes=========================\n");
    for(n; n<l; n++){
        void* key = g_list_nth_data(klist, n);
        Attribute* value = g_hash_table_lookup(v->attributes, key);
        output_attr( (char *) key, value, stdout);
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
        output_attr( (char *) key, value, stdout);
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

void die(char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr,"FATAL ERROR:");
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(EXIT_FAILURE);         // die
    return;
}

Attribute* binary_operator( Attribute* attr1, Attribute* attr2, int op, int reverse, int rm1, int rm2, int lno) {
    if(reverse) {
        Attribute* tmp = attr1;
        attr1 = attr2;
        attr2 = tmp;
    }
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
                    die("binary_operator: coding error\n");
            case OP_SUB :
                if(resultype == INT_T)
                    result->value.iv = attr1->value.iv - attr2->value.iv;
                else if (resultype == FLOAT_T)
                    result->value.fv = attr1->value.fv - attr2->value.fv;
                else
                    die("binary_operator: coding error\n");
            case OP_MUL :
                if(resultype == INT_T)
                    result->value.iv = attr1->value.iv * attr2->value.iv;
                else if (resultype == FLOAT_T)
                    result->value.fv = attr1->value.fv * attr2->value.fv;
                else
                    die("binary_operator: coding error\n");
            case OP_DIV :
                if(resultype == INT_T)
                    result->value.iv = attr1->value.iv / attr2->value.iv;
                else if (resultype == FLOAT_T)
                    result->value.fv = attr1->value.fv / attr2->value.fv;
                else
                    die("binary_operator: coding error\n");
            default:
                die("binary_operator: unsupported op %d\n",op);
        }
    }
    if(rm1==FLAG_DESTROY_ATTR) destroy_attr(attr1);
    if(rm2==FLAG_DESTROY_ATTR) destroy_attr(attr2);

    return result;
}
