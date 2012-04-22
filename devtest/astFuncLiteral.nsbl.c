GraphType* g1_g14_s0 , g2_g15_s0;
EdgeType* e1_e16_s0 , e2_e17_s0;
VertexType* v1_v18_s0 , v2_v19_s0;
GString* s1_s20_s0 , s2_s21_s0 , s3_s22_s0;
int testv_i27_s0;
int i_i28_s0 , j_i29_s0;
float x_f30_s0 , z_f31_s0;
int ff_fc4_s0 (  ) {
  GraphType* g3_g5_s3 = new_graph();
  EdgeType* e3_e6_s3 = new_edge();
  EdgeType* e4_e7_s3 = new_edge();
  int e3_e6_s3_weight_e3_i8_s3 = 3;
  vertex_assign_attribute(e3_e6_s3, "weight", &e3_e6_s3_weight_e3_i8_s3, INT);
  int ffvar_i9_s3;
  GString* s4_s11_s3 = g_string_new("");
  GString* s5_s12_s3 = new_vertex("test s5");
  int castv_i13_s3 = (int) 15.6;
}

bool tt_fl2_s0 ( int i_i0_s1 , float x_f1_s1 ) {
  return (float) i_i0_s1 == x_f1_s1;
}

int dd_fl3_s0 ( int D_a , GString* D_b ) {
  return D_a;
}

  void xx_fl10_s3 (  ) { }

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
GString* v1_v18_s0_name_v1_s23_s0 = g_string_new("Tom");
vertex_assign_attribute(v1_v18_s0, "name", v1_v18_s0_name_v1_s23_s0->str ,STRING);
int v1_v18_s0_age_v1_i24_s0 = 18;
vertex_assign_attribute(v1_v18_s0, "age", &v1_v18_s0_age_v1_i24_s0, INT);
int v2_v19_s0_age_v2_i25_s0 = 19;
vertex_assign_attribute(v2_v19_s0, "age", &v2_v19_s0_age_v2_i25_s0, INT);
float v1_v18_s0_weight_v1_f26_s0 = (float)55;
vertex_assign_attribute(v1_v18_s0, "weight", &v1_v18_s0_weight_v1_f26_s0, FLOAT);
testv_i27_s0 = 2;
i_i28_s0 , j_i29_s0;
x_f30_s0 , z_f31_s0;
tt_fl2_s0 ( ( j_i29_s0 ) , ( z_f31_s0 ) );
dd_fl3_s0 ();

} // END_OF_MAIN 
