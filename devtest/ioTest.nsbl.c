int j_i0_s0;
GraphType* g_g1_s0;
EdgeType* e_e2_s0;
VertexType* v_v3_s0;
float f_f4_s0;
GString* x_s5_s0;
int i_i6_s0;
int k_i7_s0;
int u_i8_s0;
int kkk_i9_s0;
int main() {

j_i0_s0 = 10;
print_INT_T ( j_i0_s0 );
g_g1_s0 = new_graph();
e_e2_s0 = new_edge();
v_v3_s0 = new_vertex();
f_f4_s0 = 12.35;
x_s5_s0 = g_string_new("try.xml");
i_i6_s0 = 10;
k_i7_s0 = 10;
u_i8_s0 = 10;
print_INT_T ( i_i6_s0 );
print_INT_T ( k_i7_s0 );
print_INT_T ( u_i8_s0 );
print_GRAPH_T ( g_g1_s0 );
print_VERTEX_T ( v_v3_s0 );
print_EDGE_T ( e_e2_s0 );
print_VERTEX_T ( v_v3_s0 );
print_GRAPH_T ( g_g1_s0 );
print_EDGE_T ( e_e2_s0 );
print_FLOAT_T ( f_f4_s0 );
print_STRING_T ( x_s5_s0 );
destroy_graph( g_g1_s0 );
g_g1_s0 = readGraph( x_s5_s0 );
;
kkk_i9_s0;
saveGraph( g_g1_s0 , (x_s5_s0)->str );
print_STRING_T ( x_s5_s0 );
print_GRAPH_T ( g_g1_s0 );
print_INT_T ( i_i6_s0 );
print_VERTEX_T ( v_v3_s0 );
print_INT_T ( k_i7_s0 );

} // END_OF_MAIN 
