#include "Derivedtype.h"
#include "NSBLio.h"
#include "FileReadWrite.h"
VertexType * v1_v0_s0 , * v2_v1_s0 , * v3_v2_s0;
ListType * l_vl3_s0 , * ll_vl4_s0;
int main() {

v1_v0_s0 = new_vertex();
v2_v1_s0 = new_vertex();
v3_v2_s0 = new_vertex();
ListType * l_vl3_s0 = list_declaration( VERTEX_T , 3 , v1_v0_s0 , v2_v1_s0 , v3_v2_s0);
ListType * ll_vl4_s0 = list_declaration( VERTEX_T , 0 );

} // END_OF_MAIN 
