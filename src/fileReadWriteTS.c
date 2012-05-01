

#include "FileReadWrite.h"

int main()
{

  GraphType* g;
  GraphType* g1;

  VertexType* v1;
  VertexType* v2;
  VertexType* v3;
  VertexType* v4;
  VertexType* v5;
  VertexType* v6;
  VertexType* v7;
  VertexType* v8;
  VertexType* v9;
  VertexType* v10;

  EdgeType* e1;
  EdgeType* e2;
  EdgeType* e3;
  EdgeType* e4;
  EdgeType* e5;
  EdgeType* e6;
  EdgeType* e7;
  EdgeType* e8;
  EdgeType* e9;
  EdgeType* e10;
  EdgeType* e11;
  EdgeType* e12;
  EdgeType* e13;
  EdgeType* e14;
  EdgeType* e15;

  e1=new_edge();
  e2=new_edge();
  e3=new_edge();
  e4=new_edge();
  e5=new_edge();
  e6=new_edge();
  e7=new_edge();
  e8=new_edge();
  e9=new_edge();
  e10=new_edge();
  e11=new_edge();
  e12=new_edge();
  e13=new_edge();
  e14=new_edge();
  e15=new_edge();

  v1=new_vertex();
  v2=new_vertex();
  v3=new_vertex();
  v4=new_vertex();
  v5=new_vertex();
  v6=new_vertex();
  v7=new_vertex();
  v8=new_vertex();
  v9=new_vertex();
  v10=new_vertex();

  g=new_graph();
  int v1_age = 28;
  float v1_weight = 60.5;
  //edge_assign_attribute(EdgeType* e, char* attribute, void* value, int type)

  edge_assign_attribute(e1, "e1_testString", "40", 3);
  edge_assign_attribute(e1, "e1_weight_float", &v1_weight, 2);
  edge_assign_attribute(e1, "e1_weight_int", &v1_age, 1);
  edge_assign_attribute(e2, "e2_testFloat", &v1_weight, 2);
  edge_assign_attribute(e2, "e2_weight_float", &v1_weight, 2);
  edge_assign_attribute(e2, "e2_weight_int", &v1_age, 1);
  edge_assign_attribute(e3, "e3_weight_int", &v1_age, 1);
  edge_assign_attribute(e3, "e3_testFloat", &v1_weight, 2);
  edge_assign_attribute(e3, "e3_testString", "40", 3);
  edge_assign_attribute(e4, "e4_weight_int", &v1_age, 1);
  edge_assign_attribute(e4, "e4_testFloat", &v1_weight, 2);
  edge_assign_attribute(e4, "e4_testString", "40", 3);
  edge_assign_attribute(e5, "e5_weight_int", &v1_age, 1);
  edge_assign_attribute(e5, "e5_testFloat", &v1_weight, 2);
  edge_assign_attribute(e5, "e5_testString", "40", 3);
  edge_assign_attribute(e6, "e6_weight_int", &v1_age, 1);
  edge_assign_attribute(e6, "e6_testFloat", &v1_weight, 2);
  edge_assign_attribute(e6, "e6_testString", "40", 3);
  edge_assign_attribute(e7, "e7_weight_int", &v1_age, 1);
  edge_assign_attribute(e7, "e7_testFloat", &v1_weight, 2);
  edge_assign_attribute(e7, "e7_testString", "40", 3);
  edge_assign_attribute(e8, "e8_weight_int", &v1_age, 1);
  edge_assign_attribute(e8, "e8_testFloat", &v1_weight, 2);
  edge_assign_attribute(e8, "e8_testString", "40", 3);
  edge_assign_attribute(e9, "e9_weight_int", &v1_age, 1);
  edge_assign_attribute(e9, "e9_testFloat", &v1_weight, 2);
  edge_assign_attribute(e9, "e9_testString", "40", 3);
  edge_assign_attribute(e10, "e10_weight_int", &v1_age, 1);
  edge_assign_attribute(e10, "e10_testFloat", &v1_weight, 2);
  edge_assign_attribute(e10, "e10_testString", "40", 3);
  edge_assign_attribute(e11, "e11_weight_int", &v1_age, 1);
  edge_assign_attribute(e11, "e11_testFloat", &v1_weight, 2);
  edge_assign_attribute(e11, "e11_testString", "40", 3);
  edge_assign_attribute(e12, "e12_weight_int", &v1_age, 1);
  edge_assign_attribute(e12, "e12_testFloat", &v1_weight, 2);
  edge_assign_attribute(e12, "e12_testString", "40", 3);
  edge_assign_attribute(e13, "e13_weight_int", &v1_age, 1);
  edge_assign_attribute(e13, "e13_testFloat", &v1_weight, 2);
  edge_assign_attribute(e13, "e13_testString", "40", 3);
  edge_assign_attribute(e14, "e14_weight_int", &v1_age, 1);
  edge_assign_attribute(e14, "e14_testFloat", &v1_weight, 2);
  edge_assign_attribute(e14, "e14_testString", "40", 3);
  edge_assign_attribute(e15, "e15_weight_int", &v1_age, 1);
  edge_assign_attribute(e15, "e15_testFloat", &v1_weight, 2);
  edge_assign_attribute(e15, "e15_testString", "40", 3);

  //vertex_assign_attribute(VertexType* v, char* attribute, void* value, int type)

  vertex_assign_attribute(v1, "Name", "v1_vertex", 3);
  vertex_assign_attribute(v1, "Test_Int", &v1_age, 1);
  vertex_assign_attribute(v1, "TestFloat", &v1_weight, 2);
  vertex_assign_attribute(v2, "Name", "v2_vertex", 3);
  vertex_assign_attribute(v2, "Test_Int", &v1_age, 1);
  vertex_assign_attribute(v2, "TestFloat", &v1_weight, 2);
  vertex_assign_attribute(v3, "Name", "v3_vertex", 3);
  vertex_assign_attribute(v3, "Test_Int", &v1_age, 1);
  vertex_assign_attribute(v3, "TestFloat", &v1_weight, 2);  
  vertex_assign_attribute(v4, "Name", "v4_vertex", 3);
  vertex_assign_attribute(v4, "Test_Int", &v1_age, 1);
  vertex_assign_attribute(v4, "TestFloat", &v1_weight, 2);
  vertex_assign_attribute(v5, "Name", "v5_vertex", 3);
  vertex_assign_attribute(v5, "Test_Int", &v1_age, 1);
  vertex_assign_attribute(v5, "TestFloat", &v1_weight, 2);
  vertex_assign_attribute(v6, "Name", "v6_vertex", 3);
  vertex_assign_attribute(v6, "Test_Int", &v1_age, 1);
  vertex_assign_attribute(v6, "TestFloat", &v1_weight, 2);
  vertex_assign_attribute(v7, "Name", "v7_vertex", 3);
  vertex_assign_attribute(v7, "Test_Int", &v1_age, 1);
  vertex_assign_attribute(v7, "TestFloat", &v1_weight, 2);
  vertex_assign_attribute(v8, "Name", "v8_vertex", 3);
  vertex_assign_attribute(v8, "Test_Int", &v1_age, 1);
  vertex_assign_attribute(v8, "TestFloat", &v1_weight, 2);
  vertex_assign_attribute(v9, "Name", "v9_vertex", 3);
  vertex_assign_attribute(v9, "Test_Int", &v1_age, 1);
  vertex_assign_attribute(v9, "TestFloat", &v1_weight, 2);
  vertex_assign_attribute(v10, "Name", "v10_vertex", 3);
  vertex_assign_attribute(v10, "Test_Int", &v1_age, 1);
  vertex_assign_attribute(v10, "TestFloat", &v1_weight, 2);

  //edge_assign_direction(EdgeType* e, VertexType* v1, VertexType* v2)

  edge_assign_direction(e1,v1, v2);
  edge_assign_direction(e2,v2, v3);
  edge_assign_direction(e3,v3, v4);
  edge_assign_direction(e4,v4, v3);
  edge_assign_direction(e5,v4, v5);
  edge_assign_direction(e6,v5, v6);
  edge_assign_direction(e7,v6, v7);
  edge_assign_direction(e8,v7, v8);
  edge_assign_direction(e9,v8, v9);
  edge_assign_direction(e10,v9, v10);
  edge_assign_direction(e11,v1, v3);
  edge_assign_direction(e12,v10, v3);
  edge_assign_direction(e13,v2, v4);
  edge_assign_direction(e14,v6, v1);
  edge_assign_direction(e15,v7, v5);

  //g_insert_v(GraphType* g, VertexType* v)

  g_insert_v(g, v1);
  g_insert_v(g, v2);
  g_insert_v(g, v3);
  g_insert_v(g, v4);
  g_insert_v(g, v5);
  g_insert_v(g, v6);
  g_insert_v(g, v7);
  g_insert_v(g, v8);
  g_insert_v(g, v9);
  g_insert_v(g, v10);


  //g_insert_e(GraphType* g, EdgeType* e)


  g_insert_e(g, e1);
  g_insert_e(g, e2);
  g_insert_e(g, e3);
  g_insert_e(g, e4);
  g_insert_e(g, e5);
  g_insert_e(g, e6);
  g_insert_e(g, e7);
  g_insert_e(g, e8);
  g_insert_e(g, e9);
  g_insert_e(g, e10);
  g_insert_e(g, e11);
  g_insert_e(g, e12);
  g_insert_e(g, e13);
  g_insert_e(g, e14);
  g_insert_e(g, e15);


  //test xml creation
  //void saveGraph(GraphType* g, char* fileloc, char* filename)

  saveGraph(g,"try.xml");


  //test read xml
  //GraphType* readGraph(char* fileloc, char* filename)

  g1=readGraph("try.xml");
  VertexType* v;
  saveGraph(g1,"tryd.xml");
  GList* l=get_g_alle(g1);
  int le=g_list_length(l);
  int n=0;
  for (n;n<le;n++)
  {
        printf("+++++++++++++++++++++++++++++++++++++++++++\n");
	v=get_end_vertex(g_list_nth_data(l,n));
        printf("edge end vertex: %d\n",v->id);
	print_v_attr(v);
        v=get_start_vertex(g_list_nth_data(l,n));
        printf("edge start vertex: %d\n",v->id);
        print_e_attr(g_list_nth_data(l,n));
	print_v_attr(v);
	printf("++++++++++++++++++++++++++++++++++++++++++++\n");
        //print_e_attr(g_list_nth_data(l,n));
  }

  //checking how file name errors is handled in readGraph function
  g1=readGraph(""); 

  //checking if it handles reading non xml files
  g1=readGraph("graph_lib_test.c"); 
	

  return 0;
}

