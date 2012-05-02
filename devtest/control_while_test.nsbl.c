#include "Derivedtype.h"
#include "NSBLio.h"
#include "FileReadWrite.h"
VertexType * v0_v0_s0 , * v1_v1_s0 , * v2_v2_s0 , * v3_v3_s0 , * v4_v4_s0 , * v5_v5_s0 , * v6_v6_s0;
EdgeType * e0_e7_s0 , * e1_e8_s0 , * e2_e9_s0 , * e3_e10_s0 , * e4_e11_s0 , * e5_e12_s0;
ListType * vl1_vl13_s0;
ListType * vl2_vl14_s0 , * vl3_vl15_s0 , * vl4_vl16_s0;
ListType * el1_el17_s0 , * el2_el18_s0;
int elistlength_fc20_s0 ( ListType * l_el19_s1 ) {
  int i_i21_s1 = 0;
  EdgeType * et_e22_s1;
  int _tmp_vab_0 = g_list_length(l_el19_s1->list);
  int _tmp_vab_1;
  for (_tmp_vab_1=0; _tmp_vab_1<_tmp_vab_0; _tmp_vab_1++) {
  et_e22_s1 = g_list_nth_data ( l_el19_s1->list, _tmp_vab_1 );
    i_i21_s1 = i_i21_s1 + 1;
  } //END_OF_FOREACH
  return i_i21_s1;
}

struct _STR_tmp_match_0 {
  VertexType * v0_v0_s0_match;
};
bool _tmp_match_0 ( void * _obj, int _obj_type, struct _STR_tmp_match_0 * _str ) {
  return get_attr_value_BOOL_T (  binary_operator ( object_get_attribute( _obj, _obj_type, "::level", 0, 59 )  , vertex_get_attribute( _str->v0_v0_s0_match ,  "::itr", 0, 59) , OP_GT, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_KEEP_ATTR , 59 ) , 59 )  ;
} // END_MATCH_FUNC 

int main() {

v0_v0_s0 = new_vertex();
v1_v1_s0 = new_vertex();
v2_v2_s0 = new_vertex();
v3_v3_s0 = new_vertex();
v4_v4_s0 = new_vertex();
v5_v5_s0 = new_vertex();
v6_v6_s0 = new_vertex();
assign_operator (vertex_get_attribute( v1_v1_s0 ,  "::name", 1, 2 ) ,  new_attr_STRING_T( g_string_new ( "Va" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 2 ) ;
assign_operator (vertex_get_attribute( v2_v2_s0 ,  "::name", 1, 3 ) ,  new_attr_STRING_T( g_string_new ( "Vb" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 3 ) ;
assign_operator (vertex_get_attribute( v3_v3_s0 ,  "::name", 1, 4 ) ,  new_attr_STRING_T( g_string_new ( "Vc" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 4 ) ;
assign_operator (vertex_get_attribute( v4_v4_s0 ,  "::name", 1, 5 ) ,  new_attr_STRING_T( g_string_new ( "Vd" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 5 ) ;
assign_operator (vertex_get_attribute( v5_v5_s0 ,  "::name", 1, 6 ) ,  new_attr_STRING_T( g_string_new ( "Ve" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 6 ) ;
assign_operator (vertex_get_attribute( v1_v1_s0 ,  "::age", 1, 8 ) ,  new_attr_INT_T( 10 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 8 ) ;
assign_operator (vertex_get_attribute( v2_v2_s0 ,  "::age", 1, 9 ) ,  new_attr_INT_T( 11 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 9 ) ;
assign_operator (vertex_get_attribute( v3_v3_s0 ,  "::age", 1, 10 ) ,  new_attr_INT_T( 12 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 10 ) ;
assign_operator (vertex_get_attribute( v4_v4_s0 ,  "::age", 1, 11 ) ,  new_attr_INT_T( 13 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 11 ) ;
assign_operator (vertex_get_attribute( v5_v5_s0 ,  "::age", 1, 12 ) ,  new_attr_INT_T( 14 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 12 ) ;
assign_operator (vertex_get_attribute( v1_v1_s0 ,  "::w", 1, 14 ) ,  new_attr_FLOAT_T( 100.1 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 14 ) ;
assign_operator (vertex_get_attribute( v2_v2_s0 ,  "::w", 1, 15 ) ,  new_attr_FLOAT_T( 200.1 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 15 ) ;
assign_operator (vertex_get_attribute( v3_v3_s0 ,  "::w", 1, 16 ) ,  new_attr_FLOAT_T( 300.1 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 16 ) ;
assign_operator (vertex_get_attribute( v4_v4_s0 ,  "::w", 1, 17 ) ,  new_attr_FLOAT_T( 400.1 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 17 ) ;
assign_operator (vertex_get_attribute( v5_v5_s0 ,  "::w", 1, 18 ) ,  new_attr_FLOAT_T( 500.1 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 18 ) ;
assign_operator (vertex_get_attribute( v1_v1_s0 ,  "::m", 1, 20 ) ,  new_attr_BOOL_T( true ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 20 ) ;
assign_operator (vertex_get_attribute( v2_v2_s0 ,  "::m", 1, 21 ) ,  new_attr_BOOL_T( false ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 21 ) ;
assign_operator (vertex_get_attribute( v3_v3_s0 ,  "::m", 1, 22 ) ,  new_attr_BOOL_T( true ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 22 ) ;
assign_operator (vertex_get_attribute( v4_v4_s0 ,  "::m", 1, 23 ) ,  new_attr_BOOL_T( true ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 23 ) ;
assign_operator (vertex_get_attribute( v5_v5_s0 ,  "::m", 1, 24 ) ,  new_attr_BOOL_T( false ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 24 ) ;
e0_e7_s0 = new_edge();
e1_e8_s0 = new_edge();
e2_e9_s0 = new_edge();
e3_e10_s0 = new_edge();
e4_e11_s0 = new_edge();
e5_e12_s0 = new_edge();
edge_assign_direction(e1_e8_s0, v1_v1_s0, v2_v2_s0);
edge_assign_direction(e2_e9_s0, v3_v3_s0, v2_v2_s0);
edge_assign_direction(e3_e10_s0, v4_v4_s0, v2_v2_s0);
edge_assign_direction(e4_e11_s0, v2_v2_s0, v3_v3_s0);
edge_assign_direction(e5_e12_s0, v5_v5_s0, v2_v2_s0);
assign_operator (edge_get_attribute( e1_e8_s0 ,  "::level", 1, 34 ) ,  new_attr_INT_T( 4 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 34 ) ;
assign_operator (edge_get_attribute( e2_e9_s0 ,  "::level", 1, 35 ) ,  new_attr_INT_T( 2 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 35 ) ;
assign_operator (edge_get_attribute( e3_e10_s0 ,  "::level", 1, 36 ) ,  new_attr_INT_T( 6 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 36 ) ;
assign_operator (edge_get_attribute( e4_e11_s0 ,  "::level", 1, 37 ) ,  new_attr_INT_T( 1 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 37 ) ;
assign_operator (edge_get_attribute( e5_e12_s0 ,  "::level", 1, 38 ) ,  new_attr_INT_T( 9 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 38 ) ;
vl1_vl13_s0 = list_declaration( VERTEX_T , 5 , v1_v1_s0 , v2_v2_s0 , v3_v3_s0 , v4_v4_s0 , v5_v5_s0);
vl2_vl14_s0 = list_declaration( VERTEX_T , 0);
vl3_vl15_s0 = list_declaration( VERTEX_T , 0 );
vl4_vl16_s0 = list_declaration( VERTEX_T , 1 , v3_v3_s0);
el1_el17_s0 = list_declaration( EDGE_T , 0 );
el2_el18_s0 = list_declaration( EDGE_T , 0 );
assign_operator (vertex_get_attribute( v0_v0_s0 ,  "::name", 1, 53 ) ,  new_attr_STRING_T( g_string_new ( "control" ) ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 53 ) ;
assign_operator (vertex_get_attribute( v0_v0_s0 ,  "::b", 1, 54 ) ,  new_attr_BOOL_T( true ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 54 ) ;
assign_operator (vertex_get_attribute( v0_v0_s0 ,  "::itr", 1, 55 ) ,  new_attr_INT_T( 0 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 55 ) ;
// START_OF_WHILE
Attribute* _tmp_attr_0 = vertex_get_attribute( v0_v0_s0 ,  "::b", 0, 57) ;
while ( get_attr_value_BOOL_T ( _tmp_attr_0 , 57 )  ) {
  ListType * el_in_for_el23_s3 = list_declaration( EDGE_T , 0 );
  ListType * _tmp_vab_2 = (ListType*) malloc(sizeof(ListType));
_tmp_vab_2->list = NULL;
_tmp_vab_2->type = EDGE_T;
int _tmp_vab_3 = g_list_length(vl1_vl13_s0->list);
int _tmp_vab_4;
for(_tmp_vab_4=0; _tmp_vab_4<_tmp_vab_3; _tmp_vab_4++){
switch(EDGE_T){
case EDGE_T:
if(OP_OUTE==OP_OUTE)
_tmp_vab_2 = list_append_gl(_tmp_vab_2, ((VertexType*)g_list_nth_data(vl1_vl13_s0->list, _tmp_vab_4))->outEdges, EDGE_T);
else if(OP_OUTE==OP_INE)
_tmp_vab_2 = list_append_gl(_tmp_vab_2, ((VertexType*)g_list_nth_data(vl1_vl13_s0->list, _tmp_vab_4))->inEdges, EDGE_T);
else die(59, "illeage pipe op for vlist\n");
break;
case VERTEX_T:
if(OP_OUTE==OP_SV)
_tmp_vab_2 = list_append(_tmp_vab_2, VERTEX_T, ((EdgeType*)g_list_nth_data(vl1_vl13_s0->list, _tmp_vab_4))->start);
else if(OP_OUTE==OP_EV)
_tmp_vab_2 = list_append(_tmp_vab_2, VERTEX_T,  ((EdgeType*)g_list_nth_data(vl1_vl13_s0->list, _tmp_vab_4))->end);
else die(59, "illeage pipe op for elist\n");
break;
}
}
struct _STR_tmp_match_0 _STRV_0 = {v0_v0_s0};
ListType* _tmp_vab_5 = new_list ();
_tmp_vab_5->type = (_tmp_vab_2)->type;
int _tmp_vab_6 = g_list_length( (_tmp_vab_2)->list );
int _tmp_vab_7;
bool _tmp_vab_8;
void *_tmp_vab_9;
for (_tmp_vab_7=0; _tmp_vab_7<_tmp_vab_6; _tmp_vab_7++) {
_tmp_vab_9= g_list_nth_data( (_tmp_vab_2)->list, _tmp_vab_7);
if ( _tmp_vab_8 = _tmp_match_0( _tmp_vab_9, ( _tmp_vab_2)->type, &_STRV_0) ) {
_tmp_vab_5->list = g_list_append ( _tmp_vab_5->list , _tmp_vab_9);
}
}
destroy_list ( _tmp_vab_2);
  assign_operator_list ( & (el_in_for_el23_s3) , &(_tmp_vab_5) ) ;
  if ( elistlength_fc20_s0 ( el_in_for_el23_s3  ) == 0 ) 
  break ;
   // END_IF 
  print_STRING_T ( g_string_new ( "leves greater then: " ) );
  print_attr ( vertex_get_attribute( v0_v0_s0 ,  "::itr", 0, 62) );
  print_STRING_T ( g_string_new ( "\n" ) );
  EdgeType * et_e24_s3;
  int _tmp_vab_10 = g_list_length(el_in_for_el23_s3->list);
  int _tmp_vab_11;
  for (_tmp_vab_11=0; _tmp_vab_11<_tmp_vab_10; _tmp_vab_11++) {
  et_e24_s3 = g_list_nth_data ( el_in_for_el23_s3->list, _tmp_vab_11 );
  print_EDGE_T ( et_e24_s3 );
  } //END_OF_FOREACH
  print_STRING_T ( g_string_new ( "EDN=========\n" ) );
  destroy_list ( el_in_for_el23_s3 );
  assign_operator (vertex_get_attribute( v0_v0_s0 ,  "::itr", 1, 66 ) ,  binary_operator( vertex_get_attribute( v0_v0_s0 ,  "::itr", 0, 66) ,  new_attr_INT_T( 1 ) , OP_ADD, FLAG_NO_REVERSE , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 66 ) , FLAG_KEEP_ATTR , FLAG_DESTROY_ATTR , 66 ) ;
_tmp_attr_0 = vertex_get_attribute( v0_v0_s0 ,  "::b", 0, 57) ;
} 
destroy_attr( _tmp_attr_0 ); //END_OF_WHILE
destroy_vertex ( v0_v0_s0 );
destroy_vertex ( v1_v1_s0 );
destroy_vertex ( v2_v2_s0 );
destroy_vertex ( v3_v3_s0 );
destroy_vertex ( v4_v4_s0 );
destroy_vertex ( v5_v5_s0 );
destroy_list ( vl1_vl13_s0 );
destroy_list ( vl2_vl14_s0 );
destroy_list ( vl3_vl15_s0 );
destroy_list ( vl4_vl16_s0 );
destroy_list ( el1_el17_s0 );
destroy_list ( el2_el18_s0 );

} // END_OF_MAIN 
