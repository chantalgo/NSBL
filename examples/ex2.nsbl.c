#include "Derivedtype.h"
#include "NSBLio.h"
#include "FileReadWrite.h"
int add_fc2_s0 ( int a_i0_s1 , int b_i1_s1 ) {
  return a_i0_s1 + b_i1_s1;
}

float mul_fc5_s0 ( float a_f3_s2 , float b_f4_s2 ) {
  return a_f3_s2 * b_f4_s2;
}

int vmul_fc8_s0 ( VertexType * a_v6_s3 , VertexType * b_v7_s3 ) {
  return get_attr_value_INT_T (  binary_operator( vertex_get_attribute( a_v6_s3 ,  "::i", 0, 7) , vertex_get_attribute( b_v7_s3 ,  "::i", 0, 7) , OP_MUL, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_KEEP_ATTR , 7 ) , 7 ) ;
}

StringType * vs_fc11_s0 ( VertexType * a_v9_s4 , VertexType * b_v10_s4 ) {
  return get_attr_value_STRING_T ( vertex_get_attribute( a_v9_s4 ,  "::s", 0, 8) , 8 ) ;
}

int fact_fc13_s0 ( int a_i12_s5 ) {
  if ( a_i12_s5 == 0 || a_i12_s5 == 1 ) 
  return 1;
  else
  return a_i12_s5 * fact_fc13_s0 ( a_i12_s5 - 1  );
   // END_IF
}

int main_fc14_s0 (  ) {
  int i_i15_s6 = 1 , j_i16_s6 = 2;
  float a_f17_s6 = (float) 1 , b_f18_s6 = 1.9;
  VertexType* v1_v19_s6 = new_vertex();
  VertexType* v2_v20_s6 = new_vertex();
  assign_operator (vertex_get_attribute( v1_v19_s6 ,  "::i", 1, 19 ) ,  new_attr_FLOAT_T( a_f17_s6 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 19 ) ;
  assign_operator (vertex_get_attribute( v2_v20_s6 ,  "::i", 1, 20 ) ,  new_attr_FLOAT_T( b_f18_s6 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 20 ) ;
  assign_operator (vertex_get_attribute( v1_v19_s6 ,  "::s", 1, 21 ) ,  new_attr_STRING_T( g_string_new ( "J" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 21 ) ;
  print_INT_T ( add_fc2_s0 ( i_i15_s6 , j_i16_s6  ) );
  print_STRING_T ( g_string_new ( "\n" ) );
  print_FLOAT_T ( mul_fc5_s0 ( a_f17_s6 , b_f18_s6  ) );
  print_STRING_T ( g_string_new ( "\n" ) );
  print_INT_T ( vmul_fc8_s0 ( v1_v19_s6 , v2_v20_s6  ) );
  print_STRING_T ( g_string_new ( "\n" ) );
  print_STRING_T ( vs_fc11_s0 ( v1_v19_s6 , v2_v20_s6  ) );
  print_STRING_T ( g_string_new ( "\n" ) );
  vertex_remove_attribute ( v1_v19_s6 , "::i" );
  vertex_remove_attribute ( v2_v20_s6 , "::i" );
  // START_OF_FOR
  assign_operator (vertex_get_attribute( v1_v19_s6 ,  "::i", 1, 30 ) ,  new_attr_INT_T( 0 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 30 )  , j_i16_s6 = 0;
  Attribute* _tmp_attr_0 =  binary_operator ( vertex_get_attribute( v1_v19_s6 ,  "::i", 0, 30) ,  new_attr_INT_T( 10 ) , OP_LE, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 30 ) ;
  while (get_attr_value_BOOL_T ( _tmp_attr_0 , 30 )  ) {
    print_attr ( vertex_get_attribute( v1_v19_s6 ,  "::i", 0, 31) );
    print_STRING_T ( g_string_new ( " : " ) );
    print_INT_T ( fact_fc13_s0 ( get_attr_value_INT_T ( vertex_get_attribute( v1_v19_s6 ,  "::i", 0, 31) , 31 )   ) + j_i16_s6 );
    print_STRING_T ( g_string_new ( "\n" ) );
  assign_operator (vertex_get_attribute( v1_v19_s6 ,  "::i", 1, 30 ) ,  binary_operator( vertex_get_attribute( v1_v19_s6 ,  "::i", 0, 30) ,  new_attr_INT_T( 1 ) , OP_ADD, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 30 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 30 )  , j_i16_s6 = j_i16_s6 + 3;
  destroy_attr( _tmp_attr_0 );
  _tmp_attr_0 =  binary_operator ( vertex_get_attribute( v1_v19_s6 ,  "::i", 0, 30) ,  new_attr_INT_T( 10 ) , OP_LE, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 30 ) ;
} 
  destroy_attr( _tmp_attr_0 ); // END_OF_FOR
  return 0;
}

int main() {

main_fc14_s0 ();

} // END_OF_MAIN 
