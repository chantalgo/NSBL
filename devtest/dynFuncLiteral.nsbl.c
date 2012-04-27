#include "Derivedtype.h"
#include "NSBLio.h"
#include "FileReadWrite.h"
VertexType * v0_v3_s0 , * v1_v4_s0 , * v2_v5_s0 , * v3_v6_s0 , * v4_v7_s0;
EdgeType * e1_e8_s0 , * e2_e9_s0 , * e3_e10_s0 , * e4_e11_s0 , * e5_e12_s0 , * e6_e13_s0;
ListType * el_l14_s0;
ListType * lt1_l15_s0;
ListType * lt2_l16_s0;
ListType * j_l17_s0;
ListType * l_l18_s0;
int iii_i21_s0;
bool axx_fl2_s0 ( void * _obj, int _obj_type , int k_i0_s1 ) {
  assign_operator (object_get_attribute( _obj, _obj_type, "::age" )  ,  new_attr_INT_T( 18 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 3 ) ;
  int i_i1_s1 = 0;
  ( assign_operator_to_static ( binary_operator( object_get_attribute( _obj, _obj_type, "::age" )  ,  new_attr_INT_T( k_i0_s1 ) , OP_ADD, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 6 ) , INT_T , (void *) i_i1_s1 , FLAG_DESTROY_ATTR , 6 ),  i_i1_s1 ) ;
  return i_i1_s1 > 3;
}  // END_OF_FUNC_LITERAL

struct _STR_tmp_match_1 {
};
bool _tmp_match_1 ( void * _obj, int _obj_type, struct _STR_tmp_match_1 * _str ) {
  return  *(bool *) get_attr_value(  binary_operator ( object_get_attribute( _obj, _obj_type, "::age" )  ,  new_attr_INT_T( 0 ) , OP_GT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 41 ) , BOOL_T )  ;
} // END_MATCH_FUNC 

struct _STR_tmp_match_0 {
};
bool _tmp_match_0 ( void * _obj, int _obj_type, struct _STR_tmp_match_0 * _str ) {
  return  *(bool *) get_attr_value(  binary_operator ( object_get_attribute( _obj, _obj_type, "::age" )  ,  new_attr_INT_T( - ( 100 ) ) , OP_GT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 41 ) , BOOL_T )  ;
} // END_MATCH_FUNC 

bool cond_fl20_s0 ( void * _obj, int _obj_type , int k_i19_s4 ) {
  return  *(bool *) get_attr_value(  binary_operator ( object_get_attribute( _obj, _obj_type, "::age" )  ,  new_attr_INT_T( k_i19_s4 ) , OP_GT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 44 ) , BOOL_T ) ;
}  // END_OF_FUNC_LITERAL

struct _STR_tmp_match_2 {
  int iii_i21_s0_match;
};
bool _tmp_match_2 ( void * _obj, int _obj_type, struct _STR_tmp_match_2 * _str ) {
  return  *(bool *) get_attr_value(  binary_operator (  binary_operator ( object_get_attribute( _obj, _obj_type, "::w" )  ,  new_attr_INT_T( _str->iii_i21_s0_match ) , OP_GT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 47 ) ,  new_attr_BOOL_T( cond_fl20_s0 ( _obj, _obj_type, 5 ) ) , OP_OR, FLAG_NO_REVERSE , FLAG_DESTROY_ATTR , FLAG_DESTROY_ATTR , 47 ) , BOOL_T )  ;
} // END_MATCH_FUNC 

int main() {

v0_v3_s0 = new_vertex();
v1_v4_s0 = new_vertex();
v2_v5_s0 = new_vertex();
v3_v6_s0 = new_vertex();
v4_v7_s0 = new_vertex();
assign_operator (vertex_get_attribute( v1_v4_s0 ,  "::age" ) ,  new_attr_INT_T( 10 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 11 ) ;
assign_operator (vertex_get_attribute( v1_v4_s0 ,  "::w" ) ,  new_attr_FLOAT_T( 100.0 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 11 ) ;
assign_operator (vertex_get_attribute( v2_v5_s0 ,  "::age" ) ,  new_attr_INT_T( 2 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 12 ) ;
assign_operator (vertex_get_attribute( v2_v5_s0 ,  "::w" ) ,  new_attr_FLOAT_T( 1000.0 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 12 ) ;
assign_operator (vertex_get_attribute( v3_v6_s0 ,  "::age" ) ,  new_attr_INT_T( 4 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 13 ) ;
assign_operator (vertex_get_attribute( v3_v6_s0 ,  "::w" ) ,  new_attr_FLOAT_T( 200. ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 13 ) ;
assign_operator (vertex_get_attribute( v4_v7_s0 ,  "::age" ) ,  new_attr_INT_T( - ( 1 ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 14 ) ;
assign_operator (vertex_get_attribute( v4_v7_s0 ,  "::w" ) ,  new_attr_FLOAT_T( 300. ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 14 ) ;
e1_e8_s0 = new_edge();
e2_e9_s0 = new_edge();
e3_e10_s0 = new_edge();
e4_e11_s0 = new_edge();
e5_e12_s0 = new_edge();
e6_e13_s0 = new_edge();
edge_assign_direction(e1_e8_s0, v1_v4_s0, v2_v5_s0);
edge_assign_direction(e2_e9_s0, v1_v4_s0, v3_v6_s0);
edge_assign_direction(e3_e10_s0, v2_v5_s0, v3_v6_s0);
edge_assign_direction(e4_e11_s0, v3_v6_s0, v2_v5_s0);
edge_assign_direction(e5_e12_s0, v4_v7_s0, v2_v5_s0);
el_l14_s0 = list_declaration(EDGE_T, 5, e1_e8_s0 , e2_e9_s0 , e3_e10_s0 , e4_e11_s0 , e5_e12_s0);
lt1_l15_s0 = list_declaration(UNKNOWN_T, 0);
lt2_l16_s0 = list_declaration(UNKNOWN_T, 0);
ListType * _tmp_vab_0 = (ListType*) malloc(sizeof(ListType));
_tmp_vab_0->list = NULL;
_tmp_vab_0->type = VERTEX_T;
int _tmp_vab_1 = g_list_length(el_l14_s0->list);
int _tmp_vab_2;
for(_tmp_vab_2=0; _tmp_vab_2<_tmp_vab_1; _tmp_vab_2++){
switch(VERTEX_T){
case EDGE_T:
if(OP_EV==OP_OUTE)
_tmp_vab_0 = list_append_gl(_tmp_vab_0, ((VertexType*)g_list_nth_data(el_l14_s0->list, _tmp_vab_2))->outEdges, EDGE_T);
else if(OP_EV==OP_INE)
_tmp_vab_0 = list_append_gl(_tmp_vab_0, ((VertexType*)g_list_nth_data(el_l14_s0->list, _tmp_vab_2))->inEdges, EDGE_T);
else die("illeage pipe op for vlist\n");
break;
case VERTEX_T:
if(OP_EV==OP_SV)
_tmp_vab_0 = list_append(_tmp_vab_0, VERTEX_T, ((EdgeType*)g_list_nth_data(el_l14_s0->list, _tmp_vab_2))->start);
else if(OP_EV==OP_EV)
_tmp_vab_0 = list_append(_tmp_vab_0, VERTEX_T,  ((EdgeType*)g_list_nth_data(el_l14_s0->list, _tmp_vab_2))->end);
else die("illeage pipe op for elist\n");
break;
}
}
assign_operator_list ( & (lt1_l15_s0) , &(_tmp_vab_0) ) ;
print_LIST_T ( lt1_l15_s0 );
j_l17_s0 = list_declaration(VERTEX_T, 3, v1_v4_s0 , v3_v6_s0 , v4_v7_s0);
ListType * _tmp_vab_3 = (ListType*) malloc(sizeof(ListType));
_tmp_vab_3->list = NULL;
_tmp_vab_3->type = EDGE_T;
int _tmp_vab_4 = g_list_length(j_l17_s0->list);
int _tmp_vab_5;
for(_tmp_vab_5=0; _tmp_vab_5<_tmp_vab_4; _tmp_vab_5++){
switch(EDGE_T){
case EDGE_T:
if(OP_INE==OP_OUTE)
_tmp_vab_3 = list_append_gl(_tmp_vab_3, ((VertexType*)g_list_nth_data(j_l17_s0->list, _tmp_vab_5))->outEdges, EDGE_T);
else if(OP_INE==OP_INE)
_tmp_vab_3 = list_append_gl(_tmp_vab_3, ((VertexType*)g_list_nth_data(j_l17_s0->list, _tmp_vab_5))->inEdges, EDGE_T);
else die("illeage pipe op for vlist\n");
break;
case VERTEX_T:
if(OP_INE==OP_SV)
_tmp_vab_3 = list_append(_tmp_vab_3, VERTEX_T, ((EdgeType*)g_list_nth_data(j_l17_s0->list, _tmp_vab_5))->start);
else if(OP_INE==OP_EV)
_tmp_vab_3 = list_append(_tmp_vab_3, VERTEX_T,  ((EdgeType*)g_list_nth_data(j_l17_s0->list, _tmp_vab_5))->end);
else die("illeage pipe op for elist\n");
break;
}
}
assign_operator_list ( & (lt2_l16_s0) , &(_tmp_vab_3) ) ;
l_l18_s0 = list_declaration(UNKNOWN_T, 0);
struct _STR_tmp_match_0 _STRV_0 = {};
ListType* _tmp_vab_6 = new_list ();
_tmp_vab_6->type = (j_l17_s0)->type;
int _tmp_vab_7 = g_list_length( (j_l17_s0)->list );
int _tmp_vab_8;
bool _tmp_vab_9;
void *_tmp_vab_10;
for (_tmp_vab_8=0; _tmp_vab_8<_tmp_vab_7; _tmp_vab_8++) {
_tmp_vab_10= g_list_nth_data( (j_l17_s0)->list, _tmp_vab_8);
if ( _tmp_vab_9 = _tmp_match_0( _tmp_vab_10, ( j_l17_s0)->type, &_STRV_0) ) {
_tmp_vab_6->list = g_list_append ( _tmp_vab_6->list , _tmp_vab_10);
}
}
struct _STR_tmp_match_1 _STRV_1 = {};
ListType* _tmp_vab_11 = new_list ();
_tmp_vab_11->type = (_tmp_vab_6)->type;
int _tmp_vab_12 = g_list_length( (_tmp_vab_6)->list );
int _tmp_vab_13;
bool _tmp_vab_14;
void *_tmp_vab_15;
for (_tmp_vab_13=0; _tmp_vab_13<_tmp_vab_12; _tmp_vab_13++) {
_tmp_vab_15= g_list_nth_data( (_tmp_vab_6)->list, _tmp_vab_13);
if ( _tmp_vab_14 = _tmp_match_1( _tmp_vab_15, ( _tmp_vab_6)->type, &_STRV_1) ) {
_tmp_vab_11->list = g_list_append ( _tmp_vab_11->list , _tmp_vab_15);
}
}
destroy_list ( _tmp_vab_6);
assign_operator_list ( & (l_l18_s0) , &(_tmp_vab_11) ) ;
iii_i21_s0 = 250;
struct _STR_tmp_match_2 _STRV_2 = {iii_i21_s0};
ListType* _tmp_vab_16 = new_list ();
_tmp_vab_16->type = (j_l17_s0)->type;
int _tmp_vab_17 = g_list_length( (j_l17_s0)->list );
int _tmp_vab_18;
bool _tmp_vab_19;
void *_tmp_vab_20;
for (_tmp_vab_18=0; _tmp_vab_18<_tmp_vab_17; _tmp_vab_18++) {
_tmp_vab_20= g_list_nth_data( (j_l17_s0)->list, _tmp_vab_18);
if ( _tmp_vab_19 = _tmp_match_2( _tmp_vab_20, ( j_l17_s0)->type, &_STRV_2) ) {
_tmp_vab_16->list = g_list_append ( _tmp_vab_16->list , _tmp_vab_20);
}
}
assign_operator_list ( & (l_l18_s0) , &(_tmp_vab_16) ) ;

} // END_OF_MAIN 
