VertexType* v1_v0_s0;
int i_i1_s0;
int main() {

v1_v0_s0 = new_vertex();
i_i1_s0;
{ int v1::age = 18; vertex_assign_attribute(v1_v0_s0, "v1::age", &v1::age, INT); }
{ float v1::weight = (float)100; vertex_assign_attribute(v1_v0_s0, "v1::weight", &v1::weight, FLOAT); }
{ GString* v1::name = g_string_new("tom"); vertex_assign_attribute(v1_v0_s0, "v1::name", v1::name->str, STRING); }
vertex_remove_attribute ( v1_v0_s0 , "v1::age" );
vertex_remove_attribute ( v1_v0_s0 , "v1::name" );
destroy_vertex ( v1_v0_s0 );

} // END_OF_MAIN 
