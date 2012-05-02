#include "Derivedtype.h"
#include "NSBLio.h"
#include "FileReadWrite.h"
VertexType * v0_v0_s0 , * v1_v1_s0 , * v2_v2_s0 , * v3_v3_s0 , * v4_v4_s0 , * v5_v5_s0;
EdgeType * e0_e6_s0 , * e1_e7_s0 , * e2_e8_s0 , * e3_e9_s0 , * e4_e10_s0 , * e5_e11_s0;
ListType * vl_vl12_s0;
ListType * l1_vl13_s0 , * l2_vl14_s0 , * l3_vl15_s0;
ListType * le1_el16_s0 , * le2_el17_s0;
ListType * vp_vl18_s0;
VertexType * vt_v19_s0;
int i_i20_s0;
VertexType * vv_v21_s0;
VertexType * tmp_v22_s0;
struct _STR_tmp_match_0 {
};
bool _tmp_match_0 ( void * _obj, int _obj_type, struct _STR_tmp_match_0 * _str ) {
  return get_attr_value_BOOL_T (  binary_operator (  binary_operator ( object_get_attribute( _obj, _obj_type, "::age", 0, 55 )  ,  new_attr_INT_T( 13 ) , OP_GT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 55 ) , unary_operator (object_get_attribute( _obj, _obj_type, "::m", 0, 55 )  , OP_NOT , FLAG_KEEP_ATTR , 55 ) , OP_OR, FLAG_NO_REVERSE , FLAG_DESTROY_ATTR , FLAG_DESTROY_ATTR , 55 ) , 55 )  ;
} // END_MATCH_FUNC 

int main() {

v0_v0_s0 = new_vertex();
v1_v1_s0 = new_vertex();
v2_v2_s0 = new_vertex();
v3_v3_s0 = new_vertex();
v4_v4_s0 = new_vertex();
v5_v5_s0 = new_vertex();
assign_operator (vertex_get_attribute( v1_v1_s0 ,  "::name", 1, 2 ) ,  new_attr_STRING_T( g_string_new ( "a" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 2 ) ;
assign_operator (vertex_get_attribute( v2_v2_s0 ,  "::name", 1, 3 ) ,  new_attr_STRING_T( g_string_new ( "b" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 3 ) ;
assign_operator (vertex_get_attribute( v3_v3_s0 ,  "::name", 1, 4 ) ,  new_attr_STRING_T( g_string_new ( "c" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 4 ) ;
assign_operator (vertex_get_attribute( v4_v4_s0 ,  "::name", 1, 5 ) ,  new_attr_STRING_T( g_string_new ( "d" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 5 ) ;
assign_operator (vertex_get_attribute( v5_v5_s0 ,  "::name", 1, 6 ) ,  new_attr_STRING_T( g_string_new ( "e" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 6 ) ;
assign_operator (vertex_get_attribute( v1_v1_s0 ,  "::age", 1, 8 ) ,  new_attr_INT_T( 10 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 8 ) ;
assign_operator (vertex_get_attribute( v2_v2_s0 ,  "::age", 1, 9 ) ,  new_attr_INT_T( 11 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 9 ) ;
assign_operator (vertex_get_attribute( v3_v3_s0 ,  "::age", 1, 10 ) ,  new_attr_INT_T( 12 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 10 ) ;
assign_operator (vertex_get_attribute( v4_v4_s0 ,  "::age", 1, 11 ) ,  new_attr_INT_T( 13 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 11 ) ;
assign_operator (vertex_get_attribute( v5_v5_s0 ,  "::age", 1, 12 ) ,  new_attr_INT_T( 14 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 12 ) ;
assign_operator (vertex_get_attribute( v1_v1_s0 ,  "::w", 1, 14 ) ,  new_attr_FLOAT_T( 100.1 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 14 ) ;
assign_operator (vertex_get_attribute( v2_v2_s0 ,  "::w", 1, 15 ) ,  new_attr_FLOAT_T( 200.1 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 15 ) ;
assign_operator (vertex_get_attribute( v3_v3_s0 ,  "::w", 1, 16 ) ,  new_attr_FLOAT_T( 300.1 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 16 ) ;
assign_operator (vertex_get_attribute( v4_v4_s0 ,  "::w", 1, 17 ) ,  new_attr_FLOAT_T( 400.1 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 17 ) ;
assign_operator (vertex_get_attribute( v5_v5_s0 ,  "::w", 1, 18 ) ,  new_attr_FLOAT_T( 500.1 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 18 ) ;
assign_operator (vertex_get_attribute( v1_v1_s0 ,  "::m", 1, 20 ) ,  new_attr_BOOL_T( true ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 20 ) ;
assign_operator (vertex_get_attribute( v2_v2_s0 ,  "::m", 1, 21 ) ,  new_attr_BOOL_T( false ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 21 ) ;
assign_operator (vertex_get_attribute( v3_v3_s0 ,  "::m", 1, 22 ) ,  new_attr_BOOL_T( true ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 22 ) ;
assign_operator (vertex_get_attribute( v4_v4_s0 ,  "::m", 1, 23 ) ,  new_attr_BOOL_T( true ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 23 ) ;
assign_operator (vertex_get_attribute( v5_v5_s0 ,  "::m", 1, 24 ) ,  new_attr_BOOL_T( false ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 24 ) ;
e0_e6_s0 = new_edge();
e1_e7_s0 = new_edge();
e2_e8_s0 = new_edge();
e3_e9_s0 = new_edge();
e4_e10_s0 = new_edge();
e5_e11_s0 = new_edge();
edge_assign_direction(e1_e7_s0, v1_v1_s0, v2_v2_s0);
edge_assign_direction(e2_e8_s0, v3_v3_s0, v2_v2_s0);
edge_assign_direction(e3_e9_s0, v4_v4_s0, v2_v2_s0);
edge_assign_direction(e4_e10_s0, v2_v2_s0, v3_v3_s0);
edge_assign_direction(e5_e11_s0, v5_v5_s0, v2_v2_s0);
vl_vl12_s0 = list_declaration( VERTEX_T , 5 , v1_v1_s0 , v2_v2_s0 , v3_v3_s0 , v4_v4_s0 , v5_v5_s0);
l1_vl13_s0 = list_declaration( VERTEX_T , 0);
l2_vl14_s0 = list_declaration( VERTEX_T , 0 );
l3_vl15_s0 = list_declaration( VERTEX_T , 1 , v3_v3_s0);
le1_el16_s0 = list_declaration( EDGE_T , 0 );
le2_el17_s0 = list_declaration( EDGE_T , 0 );
vp_vl18_s0 = list_declaration( VERTEX_T , 1 , v2_v2_s0);
print_VERTEX_T ( v1_v1_s0 );
print_VERTEX_T ( v2_v2_s0 );
print_VERTEX_T ( v3_v3_s0 );
print_VERTEX_T ( v4_v4_s0 );
print_VERTEX_T ( v5_v5_s0 );
print_STRING_T ( g_string_new ( "===================\n" ) );
print_ELIST_T ( l2_vl14_s0 );
ListType * _tmp_vab_0 = (ListType*) malloc(sizeof(ListType));
_tmp_vab_0->list = NULL;
_tmp_vab_0->type = EDGE_T;
int _tmp_vab_1 = g_list_length(vp_vl18_s0->list);
int _tmp_vab_2;
for(_tmp_vab_2=0; _tmp_vab_2<_tmp_vab_1; _tmp_vab_2++){
switch(EDGE_T){
case EDGE_T:
if(OP_INE==OP_OUTE)
_tmp_vab_0 = list_append_gl(_tmp_vab_0, ((VertexType*)g_list_nth_data(vp_vl18_s0->list, _tmp_vab_2))->outEdges, EDGE_T);
else if(OP_INE==OP_INE)
_tmp_vab_0 = list_append_gl(_tmp_vab_0, ((VertexType*)g_list_nth_data(vp_vl18_s0->list, _tmp_vab_2))->inEdges, EDGE_T);
else die(55, "illeage pipe op for vlist\n");
break;
case VERTEX_T:
if(OP_INE==OP_SV)
_tmp_vab_0 = list_append(_tmp_vab_0, VERTEX_T, ((EdgeType*)g_list_nth_data(vp_vl18_s0->list, _tmp_vab_2))->start);
else if(OP_INE==OP_EV)
_tmp_vab_0 = list_append(_tmp_vab_0, VERTEX_T,  ((EdgeType*)g_list_nth_data(vp_vl18_s0->list, _tmp_vab_2))->end);
else die(55, "illeage pipe op for elist\n");
break;
}
}
ListType * _tmp_vab_3 = (ListType*) malloc(sizeof(ListType));
_tmp_vab_3->list = NULL;
_tmp_vab_3->type = VERTEX_T;
int _tmp_vab_4 = g_list_length(_tmp_vab_0->list);
int _tmp_vab_5;
for(_tmp_vab_5=0; _tmp_vab_5<_tmp_vab_4; _tmp_vab_5++){
switch(VERTEX_T){
case EDGE_T:
if(OP_SV==OP_OUTE)
_tmp_vab_3 = list_append_gl(_tmp_vab_3, ((VertexType*)g_list_nth_data(_tmp_vab_0->list, _tmp_vab_5))->outEdges, EDGE_T);
else if(OP_SV==OP_INE)
_tmp_vab_3 = list_append_gl(_tmp_vab_3, ((VertexType*)g_list_nth_data(_tmp_vab_0->list, _tmp_vab_5))->inEdges, EDGE_T);
else die(55, "illeage pipe op for vlist\n");
break;
case VERTEX_T:
if(OP_SV==OP_SV)
_tmp_vab_3 = list_append(_tmp_vab_3, VERTEX_T, ((EdgeType*)g_list_nth_data(_tmp_vab_0->list, _tmp_vab_5))->start);
else if(OP_SV==OP_EV)
_tmp_vab_3 = list_append(_tmp_vab_3, VERTEX_T,  ((EdgeType*)g_list_nth_data(_tmp_vab_0->list, _tmp_vab_5))->end);
else die(55, "illeage pipe op for elist\n");
break;
}
}
destroy_list ( _tmp_vab_0);
struct _STR_tmp_match_0 _STRV_0 = {};
ListType* _tmp_vab_6 = new_list ();
_tmp_vab_6->type = (_tmp_vab_3)->type;
int _tmp_vab_7 = g_list_length( (_tmp_vab_3)->list );
int _tmp_vab_8;
bool _tmp_vab_9;
void *_tmp_vab_10;
for (_tmp_vab_8=0; _tmp_vab_8<_tmp_vab_7; _tmp_vab_8++) {
_tmp_vab_10= g_list_nth_data( (_tmp_vab_3)->list, _tmp_vab_8);
if ( _tmp_vab_9 = _tmp_match_0( _tmp_vab_10, ( _tmp_vab_3)->type, &_STRV_0) ) {
_tmp_vab_6->list = g_list_append ( _tmp_vab_6->list , _tmp_vab_10);
}
}
destroy_list ( _tmp_vab_3);
VertexType * vt_v19_s0;
int _tmp_vab_11 = g_list_length(_tmp_vab_6->list);
int _tmp_vab_12;
for (_tmp_vab_12=0; _tmp_vab_12<_tmp_vab_11; _tmp_vab_12++) {
vt_v19_s0 = g_list_nth_data ( _tmp_vab_6->list, _tmp_vab_12 );
print_VERTEX_T ( vt_v19_s0 );
} //END_OF_FOREACH
destroy_list ( _tmp_vab_6 );
i_i20_s0;
vv_v21_s0 = new_vertex();
for (i_i20_s0 = 0;i_i20_s0 < g_list_length( vl_vl12_s0->list );i_i20_s0 = i_i20_s0 + 1) {
  assign_operator_vertex ( &(vv_v21_s0) , ((VertexType *) list_getelement ( vl_vl12_s0 , i_i20_s0 )) ) ;
  print_STRING_T ( g_string_new ( "list Member :\n" ) );
  print_VERTEX_T ( (VertexType *) list_getelement ( vl_vl12_s0 , i_i20_s0 ) );
} //END_OF_FOR
tmp_v22_s0 = new_vertex();
assign_operator (vertex_get_attribute( tmp_v22_s0 ,  "::i", 1, 66 ) ,  new_attr_INT_T( 0 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 66 ) ;

} // END_OF_MAIN 
