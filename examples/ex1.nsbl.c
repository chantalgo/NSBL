#include "Derivedtype.h"
#include "NSBLio.h"
#include "FileReadWrite.h"
bool u_b0_s0 , v_b1_s0 , w_b2_s0;
int i_i3_s0 , j_i4_s0 , k_i5_s0;
float a_f6_s0 , b_f7_s0 , c_f8_s0;
GString * r_s9_s0 , * s_s10_s0 , * t_s11_s0;
VertexType * v1_v12_s0 , * v2_v13_s0 , * v3_v14_s0;
EdgeType * e1_e15_s0 , * e2_e16_s0 , * e3_e17_s0;
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
assign_operator (vertex_get_attribute( v1_v12_s0 ,  "::attr" ) ,  new_attr_STRING_T( g_string_new ( "attr" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 26 ) ;
print_VERTEX_T ( v1_v12_s0 );
vertex_remove_attribute ( v1_v12_s0 , "::attr" );
print_VERTEX_T ( v1_v12_s0 );
assign_operator (vertex_get_attribute( v1_v12_s0 ,  "::name" ) ,  new_attr_STRING_T( g_string_new ( "Joe" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 31 ) ;
assign_operator (vertex_get_attribute( v1_v12_s0 ,  "::age" ) ,  new_attr_INT_T( 20 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 32 ) ;
assign_operator (vertex_get_attribute( v1_v12_s0 ,  "::w" ) ,  new_attr_INT_T( 100 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 33 ) ;
assign_operator (vertex_get_attribute( v1_v12_s0 ,  "::male" ) ,  new_attr_BOOL_T( true ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 34 ) ;
assign_operator (vertex_get_attribute( v2_v13_s0 ,  "::name" ) ,  new_attr_STRING_T( g_string_new ( "Tom" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 36 ) ;
assign_operator (vertex_get_attribute( v2_v13_s0 ,  "::age" ) ,  new_attr_INT_T( 30 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 37 ) ;
assign_operator (vertex_get_attribute( v2_v13_s0 ,  "::w" ) ,  new_attr_INT_T( 150 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 38 ) ;
assign_operator (vertex_get_attribute( v2_v13_s0 ,  "::male" ) ,  new_attr_BOOL_T( true ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 39 ) ;
assign_operator (vertex_get_attribute( v3_v14_s0 ,  "::name" ) ,  new_attr_STRING_T( g_string_new ( "Rosie" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 41 ) ;
assign_operator (vertex_get_attribute( v3_v14_s0 ,  "::age" ) ,  new_attr_INT_T( 15 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 42 ) ;
assign_operator (vertex_get_attribute( v3_v14_s0 ,  "::w" ) ,  new_attr_INT_T( 80 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 43 ) ;
assign_operator (vertex_get_attribute( v3_v14_s0 ,  "::male" ) ,  new_attr_BOOL_T( false ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 44 ) ;
print_VERTEX_T ( v1_v12_s0 );
print_VERTEX_T ( v2_v13_s0 );
print_VERTEX_T ( v3_v14_s0 );

} // END_OF_MAIN 
