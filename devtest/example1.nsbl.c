#include "Derivedtype.h"
#include "NSBLio.h"
#include "FileReadWrite.h"
int x_i0_s0 , y_i1_s0;
VertexType * v1_v2_s0 , * v2_v3_s0 , * v3_v4_s0 , * v4_v5_s0 , * v5_v6_s0;
EdgeType * e1_e7_s0 , * e2_e8_s0 , * e3_e9_s0 , * e4_e10_s0;
ListType * lv_l11_s0;
ListType * le_l12_s0;
GraphType * g1_g13_s0;
void hello_fc14_s0 (  ) {
  VertexType* vtemp_v15_s1 = new_vertex();
  EdgeType* etemp_e16_s1 = new_edge();
  int i_i17_s1 = 0;
  int l_i18_s1 = 10;
  for (i_i17_s1;i_i17_s1 < l_i18_s1;i_i17_s1 = i_i17_s1 + 1) {
    print_attr ( vertex_get_attribute( vtemp_v15_s1 ,  "::name" ) );
    print_attr ( edge_get_attribute( etemp_e16_s1 ,  "::rel" ) );
    print_STRING_T ( g_string_new ( "Hello" ) );
} //END_OF_FOR
}

int main() {

x_i0_s0 = 0 , y_i1_s0 = 0;
v1_v2_s0 = new_vertex();
v2_v3_s0 = new_vertex();
v3_v4_s0 = new_vertex();
v4_v5_s0 = new_vertex();
v5_v6_s0 = new_vertex();
e1_e7_s0 = new_edge();
e2_e8_s0 = new_edge();
e3_e9_s0 = new_edge();
e4_e10_s0 = new_edge();
lv_l11_s0 = list_declaration(VERTEX_T, 4, v1_v2_s0 , v2_v3_s0 , v3_v4_s0 , v4_v5_s0);
le_l12_s0 = list_declaration(EDGE_T, 3, e1_e7_s0 , e2_e8_s0 , e3_e9_s0);
g1_g13_s0 = new_graph();
{ GString* _tmp_vab_0 = g_string_new ( "World" );vertex_assign_attribute(v1_v2_s0, "::project", (void *)_tmp_vab_0, STRING_T); }
{ GString* _tmp_vab_1 = g_string_new ( "Friend One" );vertex_assign_attribute(v2_v3_s0, "::name", (void *)_tmp_vab_1, STRING_T); }
{ GString* _tmp_vab_2 = g_string_new ( "Friend One" );vertex_assign_attribute(v3_v4_s0, "::name", (void *)_tmp_vab_2, STRING_T); }
print_VERTEX_T ( v1_v2_s0 );
print_VERTEX_T ( v2_v3_s0 );
print_VERTEX_T ( v3_v4_s0 );
assign_operator (vertex_get_attribute( v4_v5_s0 ,  "::name" ) ,  new_attr_STRING_T( g_string_new ( "Friend four" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 14 ) ;
print_VERTEX_T ( v4_v5_s0 );
assign_operator (edge_get_attribute( e1_e7_s0 ,  "::rel" ) ,  new_attr_STRING_T( g_string_new ( "says" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 17 ) ;
print_EDGE_T ( e1_e7_s0 );
assign_operator (edge_get_attribute( e2_e8_s0 ,  "::rel" ) , edge_get_attribute( e1_e7_s0 ,  "::rel" ) , FLAG_KEEP_ATTR , FLAG_KEEP_ATTR , 19 ) ;
assign_operator (edge_get_attribute( e4_e10_s0 ,  "::rel" ) ,  new_attr_STRING_T( g_string_new ( "says" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 20 ) ;
print_attr ( edge_get_attribute( e1_e7_s0 ,  "::rel" ) );
list_append(lv_l11_s0, VERTEX_T, v5_v6_s0);
list_append(le_l12_s0, EDGE_T, e4_e10_s0);
g_append_list(g1_g13_s0, lv_l11_s0);
g_append_list(g1_g13_s0, le_l12_s0);
hello_fc14_s0 ();

} // END_OF_MAIN 
