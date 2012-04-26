VertexType* v_v0_s0;
int j_i1_s0 , k_i2_s0;
int ii_i3_s0;
int jj_i4_s0;
bool f_b5_s0 , ff_b6_s0;
int main() {

v_v0_s0 = new_vertex();
{ int v::a = 10; vertex_assign_attribute(v_v0_s0, "v::a", &v::a, INT); }
{ float v::b = (float)3; vertex_assign_attribute(v_v0_s0, "v::b", &v::b, FLOAT); }
assign_operator (vertex_get_attribute( v_v0_s0 ,  "v::a" ) ,  binary_operator( vertex_get_attribute( v_v0_s0 ,  "v::b" ) , vertex_get_attribute( v_v0_s0 ,  "v::a" ) , OP_MUL, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_KEEP_ATTR , 6 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 6 ) ;
j_i1_s0 = 10 , k_i2_s0 = 0;
ii_i3_s0;
jj_i4_s0 = ( assign_operator_to_static ( binary_operator(  binary_operator( vertex_get_attribute( v_v0_s0 ,  "v::a" ) ,  binary_operator( vertex_get_attribute( v_v0_s0 ,  "v::b" ) ,  new_attr( INT_T , (void *) ( j_i1_s0 ) )  , OP_MUL, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 11 ) , OP_ADD, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 11 ) ,  new_attr( INT_T , (void *) ( k_i2_s0 ) )  , OP_ADD, FLAG_NO_REVERSE , FLAG_DESTROY_ATTR , FLAG_DESTROY_ATTR , 11 ) , INT_T , (void *) ii_i3_s0 , FLAG_DESTROY_ATTR , 11 ),  ii_i3_s0 ) ;
f_b5_s0 = true , ff_b6_s0;
// START_IF
Attribute* _tmp_attr_0 =  binary_operator (  binary_operator ( vertex_get_attribute( v_v0_s0 ,  "v::a" ) ,  new_attr( INT_T , (void *) ( 10 ) )  , OP_GT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 15 ) , unary_operator (cast_operator( vertex_get_attribute( v_v0_s0 ,  "v::f" ) , BOOL_T , FLAG_KEEP_ATTR , 15 ) , OP_NOT , FLAG_DESTROY_ATTR , 15 ) , OP_AND, FLAG_NO_REVERSE , FLAG_DESTROY_ATTR , FLAG_DESTROY_ATTR , 15 ) ;
if (  *(bool *) get_attr_value( _tmp_attr_0 , BOOL_T )  ) 
destory_attr( _tmp_attr_0 ); // END_IF
assign_operator (vertex_get_attribute( v_v0_s0 ,  "v::a" ) ,  new_attr( INT_T , (void *) ( 0 ) )  , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 19 ) ;
// START_OF_WHILE
Attribute* _tmp_attr_1 =  binary_operator ( vertex_get_attribute( v_v0_s0 ,  "v::a" ) ,  new_attr( INT_T , (void *) ( 10 ) )  , OP_LT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 20 ) ;
while (  *(bool *) get_attr_value( _tmp_attr_1 , BOOL_T )  ) {
  assign_operator (vertex_get_attribute( v_v0_s0 ,  "v::a" ) ,  binary_operator( vertex_get_attribute( v_v0_s0 ,  "v::a" ) ,  new_attr( INT_T , (void *) ( 1 ) )  , OP_ADD, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 21 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 21 ) ;
destory_attr( _tmp_attr_1 );
_tmp_attr_1 =  binary_operator ( vertex_get_attribute( v_v0_s0 ,  "v::a" ) ,  new_attr( INT_T , (void *) ( 10 ) )  , OP_LT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 20 ) ;
} 
destory_attr( _tmp_attr_1 ); //END_OF_WHILE
// START_OF_FOR
assign_operator (vertex_get_attribute( v_v0_s0 ,  "v::a" ) ,  new_attr( INT_T , (void *) ( 0 ) )  , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 23 ) ;
Attribute* _tmp_attr_2 =  binary_operator ( vertex_get_attribute( v_v0_s0 ,  "v::a" ) ,  new_attr( INT_T , (void *) ( 10 ) )  , OP_LT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 23 ) ;
while ( *(bool *) get_attr_value( _tmp_attr_2 , BOOL_T )  ) {
assign_operator (vertex_get_attribute( v_v0_s0 ,  "v::a" ) ,  binary_operator( vertex_get_attribute( v_v0_s0 ,  "v::a" ) ,  new_attr( INT_T , (void *) ( 1 ) )  , OP_ADD, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 23 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 23 ) ;
destory_attr( _tmp_attr_2 );
_tmp_attr_2 =  binary_operator ( vertex_get_attribute( v_v0_s0 ,  "v::a" ) ,  new_attr( INT_T , (void *) ( 10 ) )  , OP_LT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 23 ) ;
} 
destory_attr( _tmp_attr_2 ); // END_OF_FOR
assign_operator (vertex_get_attribute( v_v0_s0 ,  "v::xxx" ) ,  new_attr( INT_T , (void *) ( 19 ) )  , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 25 ) ;
// START_IF
Attribute* _tmp_attr_3 =  binary_operator (  new_attr( INT_T , (void *) ( ( assign_operator_to_static ( binary_operator( vertex_get_attribute( v_v0_s0 ,  "v::b" ) , vertex_get_attribute( v_v0_s0 ,  "v::a" ) , OP_ADD, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_KEEP_ATTR , 27 ) , INT_T , (void *) ii_i3_s0 , FLAG_DESTROY_ATTR , 27 ),  ii_i3_s0 )  ) )  , vertex_get_attribute( v_v0_s0 ,  "v::xxx" ) , OP_GT, FLAG_NO_REVERSE , FLAG_DESTROY_ATTR , FLAG_KEEP_ATTR , 27 ) ;
if (  *(bool *) get_attr_value( _tmp_attr_3 , BOOL_T )  ) 
destory_attr( _tmp_attr_3 ); // END_IF

} // END_OF_MAIN 
