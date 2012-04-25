GraphType* g1_g14_s0 , g2_g15_s0;
EdgeType* e1_e16_s0 , e2_e17_s0;
VertexType* v1_v18_s0 , v2_v19_s0;
GString* s1_s20_s0 , s2_s21_s0 , s3_s22_s0;
int testv_i23_s0;
int i_i24_s0 , j_i25_s0;
float x_f26_s0 , z_f27_s0;
ListType* lv_l28_s0;
ListType* lv2_l29_s0;
int ff_fc4_s0 (  ) {
  GraphType* g3_g5_s3 = new_graph();
  EdgeType* e3_e6_s3 = new_edge();
  EdgeType* e4_e7_s3 = new_edge();
  { int e3::weight = 3; vertex_assign_attribute(e3_e6_s3, "e3::weight", &e3::weight, INT); }
  int ffvar_i8_s3;
  GString* s4_s10_s3 = g_string_new("");
  GString* s5_s11_s3 = new_vertex("test s5");
  int castv_i12_s3 = (int) 15.6;
  ListType* le_l13_s3 = list_declaration(EDGE, 2, e3_e6_s3 , e4_e7_s3);
  list_append(le_l13_s3, EDGE_T, e4_e7_s3);
}

bool tt_fl2_s0 ( int i_i0_s1 , float x_f1_s1 ) 
int dd_fl3_s0 ( int D_a , GString* D_b ) 
  void xx_fl9_s3 (  ) { }

int main() {

g1_g14_s0 = new_graph();
g2_g15_s0 = new_graph();
e1_e16_s0 = new_edge();
e2_e17_s0 = new_edge();
v1_v18_s0 = new_vertex();
v2_v19_s0 = new_vertex();
s1_s20_s0 = g_string_new("test s1");
s2_s21_s0 = g_string_new("test s2");
s3_s22_s0 = g_string_new("");
{ GString* v1::name = g_string_new("Tom"); vertex_assign_attribute(v1_v18_s0, "v1::name", v1::name->str, STRING); }
{ int v1::age = 18; vertex_assign_attribute(v1_v18_s0, "v1::age", &v1::age, INT); }
{ int v2::age = 19; vertex_assign_attribute(v2_v19_s0, "v2::age", &v2::age, INT); }
{ float v1::weight = (float)55; vertex_assign_attribute(v1_v18_s0, "v1::weight", &v1::weight, FLOAT); }
testv_i23_s0 = 2;
i_i24_s0 , j_i25_s0;
x_f26_s0 , z_f27_s0;
tt_fl2_s0 ( ( j_i25_s0 ) , ( z_f27_s0 ) );
lv_l28_s0 = list_declaration(VERTEX, 2, v1_v18_s0 , v2_v19_s0);
lv2_l29_s0 = list_declaration(-1, 0);
g_insert_v(g1_g14_s0, v1_v18_s0);
g_insert_e(g1_g14_s0, e2_e17_s0);
g_append_list(g1_g14_s0, lv_l28_s0);
list_append(lv_l28_s0, VERTEX_T, v1_v18_s0);
dd_fl3_s0 ();

} // END_OF_MAIN 
