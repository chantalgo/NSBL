int i_i0_s0 , j_i1_s0 , k_i2_s0;
int p_i3_s0;
GString* s_s4_s0;
GraphType* g1_g9_s0 , g2_g10_s0;
EdgeType* e1_e11_s0 , e2_e12_s0;
VertexType* v1_v13_s0 , v2_v14_s0;
GString* s1_s15_s0 , s2_s16_s0 , s3_s17_s0;
int testv_i18_s0;
float x_f19_s0 , z_f20_s0;
int main() {

i_i0_s0 , j_i1_s0 , k_i2_s0 = 2;
p_i3_s0 = i_i0_s0;
s_s4_s0 = g_string_new("abcd");
{
  float a_f5_s1 = (float) 10 , b_f6_s1 = (float) 30 , i_f7_s1;
  s_s4_s0 = "";
  {
    (float) j_i1_s0 + i_f7_s1;
    int p_i8_s2;
  }
  p_i3_s0 = 1;
  a_f5_s1 += (float) 1;
}
k_i2_s0 += 2;
{
  j_i1_s0 *= 2;
}
g1_g9_s0 = new_graph();
g2_g10_s0 = new_graph();
e1_e11_s0 = new_edge();
e2_e12_s0 = new_edge();
v1_v13_s0 = new_vertex();
v2_v14_s0 = new_vertex();
s1_s15_s0 = g_string_new("test s1");
s2_s16_s0 = g_string_new("test s2");
s3_s17_s0 = g_string_new("");
{ GString* D_name_v1 = g_string_new("Tom"); vertex_assign_attribute(v1_v13_s0, "D_name_v1", D_name_v1->str, STRING); }
{ int D_age_v1 = 18; vertex_assign_attribute(v1_v13_s0, "D_age_v1", &D_age_v1, INT); }
{ int D_age_v2 = 19; vertex_assign_attribute(v2_v14_s0, "D_age_v2", &D_age_v2, INT); }
{ float D_weight_v1 = (float)55; vertex_assign_attribute(v1_v13_s0, "D_weight_v1", &D_weight_v1, FLOAT); }
testv_i18_s0 = 2;
x_f19_s0 , z_f20_s0;

} // END_OF_MAIN 
