GraphType* g_g0_s0;
GString* file_s1_s0;
int main() {

g_g0_s0 = new_graph();
file_s1_s0 = g_string_new ( "dsfdsa" );
destroy_graph( g_g0_s0 );
g_g0_s0 = readGraph( file_s1_s0->str );
saveGraph( g_g0_s0 , (file_s1_s0)->str );

} // END_OF_MAIN 
