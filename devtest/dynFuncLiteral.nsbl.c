#include "Derivedtype.h"
#include "NSBLio.h"
#include "FileReadWrite.h"
VertexType * v1_v3_s0 , * v2_v4_s0 , * v3_v5_s0 , * v4_v6_s0;
ListType * j_l7_s0;
ListType * l_l8_s0;
int iii_i11_s0;
bool axx_fl2_s0 ( void * _obj, int _obj_type , int k_i0_s1 ) {
  assign_operator (object_get_attribute( _obj, _obj_type, "::age" )  ,  new_attr_INT_T( 18 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 3 ) ;
  int i_i1_s1 = 0;
  ( assign_operator_to_static ( binary_operator( object_get_attribute( _obj, _obj_type, "::age" )  ,  new_attr_INT_T( k_i0_s1 ) , OP_ADD, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 6 ) , INT_T , (void *) i_i1_s1 , FLAG_DESTROY_ATTR , 6 ),  i_i1_s1 ) ;
  return i_i1_s1 > 3;
}  // END_OF_FUNC_LITERAL

struct _STR_tmp_match_1 {
};
bool _tmp_match_1 ( void * _obj, int _obj_type, struct _STR_tmp_match_1 * _str ) {
  return  *(bool *) get_attr_value(  binary_operator ( object_get_attribute( _obj, _obj_type, "::age" )  ,  new_attr_INT_T( 0 ) , OP_GT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 21 ) , BOOL_T )  ;
} // END_MATCH_FUNC 

struct _STR_tmp_match_0 {
};
bool _tmp_match_0 ( void * _obj, int _obj_type, struct _STR_tmp_match_0 * _str ) {
  return  *(bool *) get_attr_value(  binary_operator ( object_get_attribute( _obj, _obj_type, "::age" )  ,  new_attr_INT_T( - ( 100 ) ) , OP_GT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 21 ) , BOOL_T )  ;
} // END_MATCH_FUNC 

bool cond_fl10_s0 ( void * _obj, int _obj_type , int k_i9_s4 ) {
  return  *(bool *) get_attr_value(  binary_operator ( object_get_attribute( _obj, _obj_type, "::age" )  ,  new_attr_INT_T( k_i9_s4 ) , OP_GT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 24 ) , BOOL_T ) ;
}  // END_OF_FUNC_LITERAL

struct _STR_tmp_match_2 {
  int iii_i11_s0_match;
};
bool _tmp_match_2 ( void * _obj, int _obj_type, struct _STR_tmp_match_2 * _str ) {
  return  *(bool *) get_attr_value(  binary_operator (  binary_operator ( object_get_attribute( _obj, _obj_type, "::w" )  ,  new_attr_INT_T( _str->iii_i11_s0_match ) , OP_GT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 27 ) ,  new_attr_BOOL_T( cond_fl10_s0 ( _obj, _obj_type, 5 ) ) , OP_OR, FLAG_NO_REVERSE , FLAG_DESTROY_ATTR , FLAG_DESTROY_ATTR , 27 ) , BOOL_T )  ;
} // END_MATCH_FUNC 

int main() {

v1_v3_s0 = new_vertex();
v2_v4_s0 = new_vertex();
v3_v5_s0 = new_vertex();
v4_v6_s0 = new_vertex();
assign_operator (vertex_get_attribute( v1_v3_s0 ,  "::age" ) ,  new_attr_INT_T( 10 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 11 ) ;
assign_operator (vertex_get_attribute( v1_v3_s0 ,  "::w" ) ,  new_attr_FLOAT_T( 100.0 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 11 ) ;
assign_operator (vertex_get_attribute( v2_v4_s0 ,  "::age" ) ,  new_attr_INT_T( 2 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 12 ) ;
assign_operator (vertex_get_attribute( v2_v4_s0 ,  "::w" ) ,  new_attr_FLOAT_T( 1000.0 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 12 ) ;
assign_operator (vertex_get_attribute( v3_v5_s0 ,  "::age" ) ,  new_attr_INT_T( 4 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 13 ) ;
assign_operator (vertex_get_attribute( v3_v5_s0 ,  "::w" ) ,  new_attr_FLOAT_T( 200. ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 13 ) ;
assign_operator (vertex_get_attribute( v4_v6_s0 ,  "::age" ) ,  new_attr_INT_T( - ( 1 ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 14 ) ;
assign_operator (vertex_get_attribute( v4_v6_s0 ,  "::w" ) ,  new_attr_FLOAT_T( 300. ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 14 ) ;
print_VERTEX_T ( v1_v3_s0 );
print_VERTEX_T ( v2_v4_s0 );
print_VERTEX_T ( v3_v5_s0 );
print_VERTEX_T ( v4_v6_s0 );
j_l7_s0 = list_declaration(VERTEX_T, 4, v1_v3_s0 , v2_v4_s0 , v3_v5_s0 , v4_v6_s0);
l_l8_s0 = list_declaration(UNKNOWN_T, 0);
struct _STR_tmp_match_0 _STRV_0 = {};
ListType* _tmp_vab_0 = new_list ();
_tmp_vab_0->type = (j_l7_s0)->type;
int _tmp_vab_1 = g_list_length( (j_l7_s0)->list );
int _tmp_vab_2;
bool _tmp_vab_3;
void *_tmp_vab_4;
for (_tmp_vab_2=0; _tmp_vab_2<_tmp_vab_1; _tmp_vab_2++) {
_tmp_vab_4= g_list_nth_data( (j_l7_s0)->list, _tmp_vab_2);
if ( _tmp_vab_3 = _tmp_match_0( _tmp_vab_4, ( j_l7_s0)->type, &_STRV_0) ) {
_tmp_vab_0->list = g_list_append ( _tmp_vab_0->list , _tmp_vab_4);
}
}
struct _STR_tmp_match_1 _STRV_1 = {};
ListType* _tmp_vab_5 = new_list ();
_tmp_vab_5->type = (_tmp_vab_0)->type;
int _tmp_vab_6 = g_list_length( (_tmp_vab_0)->list );
int _tmp_vab_7;
bool _tmp_vab_8;
void *_tmp_vab_9;
for (_tmp_vab_7=0; _tmp_vab_7<_tmp_vab_6; _tmp_vab_7++) {
_tmp_vab_9= g_list_nth_data( (_tmp_vab_0)->list, _tmp_vab_7);
if ( _tmp_vab_8 = _tmp_match_1( _tmp_vab_9, ( _tmp_vab_0)->type, &_STRV_1) ) {
_tmp_vab_5->list = g_list_append ( _tmp_vab_5->list , _tmp_vab_9);
}
}
destroy_list ( _tmp_vab_0);
assign_operator_list ( & (l_l8_s0) , &(_tmp_vab_5) ) ;
print_LIST_T ( l_l8_s0 );
print_STRING_T ( g_string_new ( "xxxxxxx" ) );
iii_i11_s0 = 250;
struct _STR_tmp_match_2 _STRV_2 = {iii_i11_s0};
ListType* _tmp_vab_10 = new_list ();
_tmp_vab_10->type = (j_l7_s0)->type;
int _tmp_vab_11 = g_list_length( (j_l7_s0)->list );
int _tmp_vab_12;
bool _tmp_vab_13;
void *_tmp_vab_14;
for (_tmp_vab_12=0; _tmp_vab_12<_tmp_vab_11; _tmp_vab_12++) {
_tmp_vab_14= g_list_nth_data( (j_l7_s0)->list, _tmp_vab_12);
if ( _tmp_vab_13 = _tmp_match_2( _tmp_vab_14, ( j_l7_s0)->type, &_STRV_2) ) {
_tmp_vab_10->list = g_list_append ( _tmp_vab_10->list , _tmp_vab_14);
}
}
assign_operator_list ( & (l_l8_s0) , &(_tmp_vab_10) ) ;
print_LIST_T ( l_l8_s0 );

} // END_OF_MAIN 
