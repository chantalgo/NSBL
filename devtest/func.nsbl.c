int b_fc0_s0 (  ) {
  float c_f1_s1 = 1.0;
  VertexType* v_v2_s1 = new_vertex();
  assign_operator (vertex_get_attribute( v_v2_s1 ,  "v::a" ) ,  new_attr( INT_T , (void *) ( 10 ) )  , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 5 ) ;
  assign_operator (vertex_get_attribute( v_v2_s1 ,  "v::b" ) ,  new_attr( FLOAT_T , (void *) ( 20. ) )  , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 6 ) ;
  if ( c_f1_s1 > 0 ) 
  return  *(int *) get_attr_value( cast_operator(  binary_operator( vertex_get_attribute( v_v2_s1 ,  "v::a" ) , vertex_get_attribute( v_v2_s1 ,  "v::b" ) , OP_ADD, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_KEEP_ATTR , 8 ) , INT_T , FLAG_DESTROY_ATTR , 8 ) , INT_T ) ;
  else
  return ( int ) c_f1_s1;
   // END_IF
}

bool a_fl4_s0 ( void * _obj, int _obj_type ) {
  return true;
}  // END_OF_FUNC_LITERAL

bool b_fl3_s2 ( void * _obj, int _obj_type ) {
    return false;
}  // END_OF_FUNC_LITERAL

int main() {


} // END_OF_MAIN 
