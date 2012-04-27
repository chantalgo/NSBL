#include "Derivedtype.h"
#include "NSBLio.h"
#include "FileReadWrite.h"
bool u_b0_s0 , v_b1_s0 , w_b2_s0;
int i_i3_s0 , j_i4_s0 , k_i5_s0;
float a_f6_s0 , b_f7_s0 , c_f8_s0;
GString * r_s9_s0 , * s_s10_s0 , * t_s11_s0;
VertexType * v1_v12_s0 , * v2_v13_s0 , * v3_v14_s0;
EdgeType * e1_e15_s0 , * e2_e16_s0 , * e3_e17_s0;
ListType * la_vl18_s0 , * lb_vl19_s0 , * lc_vl20_s0;
ListType * ll_vl21_s0 , * l0_vl22_s0;
struct _STR_tmp_match_0 {
};
bool _tmp_match_0 ( void * _obj, int _obj_type, struct _STR_tmp_match_0 * _str ) {
  return  *(bool *) get_attr_value(  binary_operator (  binary_operator ( object_get_attribute( _obj, _obj_type, "::age" )  ,  new_attr_INT_T( 25 ) , OP_GT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 51 ) , unary_operator (object_get_attribute( _obj, _obj_type, "::male" )  , OP_NOT , FLAG_KEEP_ATTR , 51 ) , OP_OR, FLAG_NO_REVERSE , FLAG_DESTROY_ATTR , FLAG_DESTROY_ATTR , 51 ) , BOOL_T )  ;
} // END_MATCH_FUNC 

int main() {

u_b0_s0 = true , v_b1_s0 = false , w_b2_s0;
i_i3_s0 , j_i4_s0 = 1 , k_i5_s0 = 2;
a_f6_s0 = 10. , b_f7_s0 = 1. , c_f8_s0;
r_s9_s0 = g_string_new ( "Hello" );
s_s10_s0 = g_string_new ( "World" );
t_s11_s0 = g_string_new("");
w_b2_s0 = u_b0_s0 && ! ( v_b1_s0 ) || v_b1_s0;
i_i3_s0 = j_i4_s0 + k_i5_s0;
c_f8_s0 = - ( a_f6_s0 ) * b_f7_s0 / a_f6_s0;
print_STRING_T ( g_string_new ( " w=" ) );
print_BOOL_T ( w_b2_s0 );
print_STRING_T ( g_string_new ( "\t i=" ) );
print_INT_T ( i_i3_s0 );
print_STRING_T ( g_string_new ( "\t c=" ) );
print_FLOAT_T ( c_f8_s0 );
print_STRING_T ( t_s11_s0 );
print_STRING_T ( g_string_new ( "\n" ) );
v1_v12_s0 = new_vertex();
v2_v13_s0 = new_vertex();
v3_v14_s0 = new_vertex();
e1_e15_s0 = new_edge();
e2_e16_s0 = new_edge();
e3_e17_s0 = new_edge();
assign_operator (vertex_get_attribute( v1_v12_s0 ,  "::name", 1 ) ,  new_attr_STRING_T( g_string_new ( "Joe" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 26 ) ;
assign_operator (vertex_get_attribute( v1_v12_s0 ,  "::age", 1 ) ,  new_attr_INT_T( 20 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 27 ) ;
assign_operator (vertex_get_attribute( v1_v12_s0 ,  "::w", 1 ) ,  new_attr_INT_T( 100 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 28 ) ;
assign_operator (vertex_get_attribute( v1_v12_s0 ,  "::male", 1 ) ,  new_attr_BOOL_T( true ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 29 ) ;
assign_operator (vertex_get_attribute( v2_v13_s0 ,  "::name", 1 ) ,  new_attr_STRING_T( g_string_new ( "Tom" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 31 ) ;
assign_operator (vertex_get_attribute( v2_v13_s0 ,  "::age", 1 ) ,  new_attr_INT_T( 30 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 32 ) ;
assign_operator (vertex_get_attribute( v2_v13_s0 ,  "::w", 1 ) ,  new_attr_INT_T( 150 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 33 ) ;
assign_operator (vertex_get_attribute( v2_v13_s0 ,  "::male", 1 ) ,  new_attr_BOOL_T( true ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 34 ) ;
assign_operator (vertex_get_attribute( v3_v14_s0 ,  "::name", 1 ) ,  new_attr_STRING_T( g_string_new ( "Rosie" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 36 ) ;
assign_operator (vertex_get_attribute( v3_v14_s0 ,  "::age", 1 ) ,  new_attr_INT_T( 15 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 37 ) ;
assign_operator (vertex_get_attribute( v3_v14_s0 ,  "::w", 1 ) ,  new_attr_INT_T( 80 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 38 ) ;
assign_operator (vertex_get_attribute( v3_v14_s0 ,  "::male", 1 ) ,  new_attr_BOOL_T( false ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 39 ) ;
print_VERTEX_T ( v1_v12_s0 );
print_VERTEX_T ( v2_v13_s0 );
print_VERTEX_T ( v3_v14_s0 );
vertex_remove_attribute ( v1_v12_s0 , "::name" );
vertex_remove_attribute ( v2_v13_s0 , "::w" );
vertex_remove_attribute ( v3_v14_s0 , "::male" );
print_VERTEX_T ( v1_v12_s0 );
print_VERTEX_T ( v2_v13_s0 );
print_VERTEX_T ( v3_v14_s0 );
ListType * la_vl18_s0 = list_declaration( VERTEX_T , 0 );
ListType * lb_vl19_s0 = list_declaration( VERTEX_T , 0 );
ListType * lc_vl20_s0 = list_declaration( VERTEX_T , 0 );
ListType * ll_vl21_s0 = list_declaration( VERTEX_T , 3 , v1_v12_s0 , v2_v13_s0 , v3_v14_s0);
ListType * l0_vl22_s0 = list_declaration( VERTEX_T , 0 );
print_ELIST_T ( ll_vl21_s0 );
struct _STR_tmp_match_0 _STRV_0 = {};
ListType* _tmp_vab_0 = new_list ();
_tmp_vab_0->type = (ll_vl21_s0)->type;
int _tmp_vab_1 = g_list_length( (ll_vl21_s0)->list );
int _tmp_vab_2;
bool _tmp_vab_3;
void *_tmp_vab_4;
for (_tmp_vab_2=0; _tmp_vab_2<_tmp_vab_1; _tmp_vab_2++) {
_tmp_vab_4= g_list_nth_data( (ll_vl21_s0)->list, _tmp_vab_2);
if ( _tmp_vab_3 = _tmp_match_0( _tmp_vab_4, ( ll_vl21_s0)->type, &_STRV_0) ) {
_tmp_vab_0->list = g_list_append ( _tmp_vab_0->list , _tmp_vab_4);
}
}
assign_operator_list ( & (la_vl18_s0) , &(_tmp_vab_0) ) ;
print_ELIST_T ( la_vl18_s0 );

} // END_OF_MAIN 
