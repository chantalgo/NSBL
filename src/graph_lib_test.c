#include "Derivedtype.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
int main(int argc, char** argv){
	GraphType* g1 = new_graph();
	new_vertex();
	new_edge();
	//create node for Jack
	VertexType* v1 = new_vertex();
	char* v1_name = "Jack";
	int v1_age = 28;
	float v1_weight = 60.5;
	vertex_assign_attribute(v1, "name", v1_name, STRING);
	vertex_assign_attribute(v1, "age", &v1_age, INT);
	vertex_assign_attribute(v1, "weight", &v1_weight, FLOAT);
	char* tss = "namechanged";
	vertex_assign_attribute(v1, "name", tss, STRING);
	print_v(v1);
	print_v_attr(v1);
	

	//create node for Tom
	VertexType* v2 = new_vertex();
	char* v2_name = "Tom";
	int v2_age = 29;
	float v2_weight = 80.9;
	vertex_assign_attribute(v2, "name", v2_name, STRING);
	vertex_assign_attribute(v2, "age", &v2_age, INT);
	vertex_assign_attribute(v2, "weight", &v2_weight, FLOAT);
	print_v(v2);
	print_v_attr(v2);

	//create node for Jim
	VertexType* v3 = new_vertex();
	char* v3_name = "Jim";
	int v3_age = 26;
	float v3_weight = 62.5;
	vertex_assign_attribute(v3, "name", v3_name, STRING);
	vertex_assign_attribute(v3, "age", &v3_age, INT);
	vertex_assign_attribute(v3, "weight", &v3_weight, FLOAT);
	print_v(v3);
	print_v_attr(v3);

	//create node for Kate
	VertexType* v4 = new_vertex();
	char* v4_name = "Kate";
	int v4_age = 24;
	float v4_weight = 54.5;
	vertex_assign_attribute(v4, "name", v4_name, STRING);
	vertex_assign_attribute(v4, "age", &v4_age, INT);
	vertex_assign_attribute(v4, "weight", &v4_weight, FLOAT);
	print_v(v4);
	print_v_attr(v4);

	//create node for Lily
	VertexType* v5 = new_vertex();
	char* v5_name = "Lily";
	int v5_age = 25;
	float v5_weight = 52.5;
	vertex_assign_attribute(v5, "name", v5_name, STRING);
	vertex_assign_attribute(v5, "age", &v5_age, INT);
	vertex_assign_attribute(v5, "weight", &v5_weight, FLOAT);
	print_v(v5);
	print_v_attr(v5);

	//create node for Sarah
	VertexType* v6 = new_vertex();
	char* v6_name = "Sarah";
	int v6_age = 25;
	float v6_weight = 55.5;
	vertex_assign_attribute(v6, "name", v6_name, STRING);
	vertex_assign_attribute(v6, "age", &v6_age, INT);
	vertex_assign_attribute(v6, "weight", &v6_weight, FLOAT);
	print_v(v6);
	print_v_attr(v6);

	//create node for John
	VertexType* v7 = new_vertex();
	char* v7_name = "John";
	int v7_age = 29;
	float v7_weight = 64.5;
	vertex_assign_attribute(v7, "name", v7_name, STRING);
	vertex_assign_attribute(v7, "age", &v7_age, INT);
	vertex_assign_attribute(v7, "weight", &v7_weight, FLOAT);
	print_v(v7);
	print_v_attr(v7);

	//create node for Jerry
	VertexType* v8 = new_vertex();
	char* v8_name = "Jerry";
	int v8_age = 26;
	float v8_weight = 61.5;
	vertex_assign_attribute(v8, "name", v8_name, STRING);
	vertex_assign_attribute(v8, "age", &v8_age, INT);
	vertex_assign_attribute(v8, "weight", &v8_weight, FLOAT);
	print_v(v8);
	print_v_attr(v8);

	//create node for Jack -> Tom
	EdgeType* e1 = new_edge();
	edge_assign_direction(e1, v1, v2);
	char* e1_relation = "friends";
	edge_assign_attribute(e1, "relation", e1_relation, STRING);
	print_e(e1);
	print_e_attr(e1);

	//create node for Jim -> Tom
	EdgeType* e2 = new_edge();
	edge_assign_direction(e2, v3, v2);
	char* e2_relation = "friends";
	edge_assign_attribute(e2, "relation", e2_relation, STRING);
	print_e(e2);
	print_e_attr(e2);

	//create node for Tom -> Lily
	EdgeType* e3 = new_edge();
	edge_assign_direction(e3, v2, v5);
	char* e3_relation = "friends";
	edge_assign_attribute(e3, "relation", e3_relation, STRING);
	print_e(e3);
	print_e_attr(e3);

	//create node for Jim -> Sarah
	EdgeType* e4 = new_edge();
	edge_assign_direction(e4, v3, v6);
	char* e4_relation = "brother_sister";
	edge_assign_attribute(e4, "relation", e4_relation, STRING);
	print_e(e4);
	print_e_attr(e4);

	//create node for Jim -> Kate
	EdgeType* e5 = new_edge();
	edge_assign_direction(e5, v3, v4);
	char* e5_relation = "friends";
	edge_assign_attribute(e5, "relation", e5_relation, STRING);
	print_e(e5);
	print_e_attr(e5);

	//create node for Kate -> Lily
	EdgeType* e6 = new_edge();
	edge_assign_direction(e6, v4, v5);
	char* e6_relation = "sisters";
	edge_assign_attribute(e6, "relation", e6_relation, STRING);
	print_e(e6);
	print_e_attr(e6);

	//create node for Lily -> Jack
	EdgeType* e7 = new_edge();
	edge_assign_direction(e7, v5, v1);
	char* e7_relation = "friends";
	edge_assign_attribute(e7, "relation", e7_relation, STRING);
	print_e(e7);
	print_e_attr(e7);

	//create node for Jack -> John
	EdgeType* e8 = new_edge();
	edge_assign_direction(e8, v1, v7);
	char* e8_relation = "friends";
	edge_assign_attribute(e8, "relation", e8_relation, STRING);
	print_e(e8);
	print_e_attr(e8);

	//create node for Jerry -> Jack
	EdgeType* e9 = new_edge();
	edge_assign_direction(e9, v8, v1);
	char* e9_relation = "brothers";
	edge_assign_attribute(e9, "relation", e9_relation, STRING);
	print_e(e9);
	print_e_attr(e9);

	//create node for Lily -> Sarah
	EdgeType* e10 = new_edge();
	edge_assign_direction(e10, v7, v6);
	char* e10_relation = "friends";
	edge_assign_attribute(e10, "relation", e10_relation, STRING);
	print_e(e10);
	print_e_attr(e10);

	//create node for John -> Jerry
	EdgeType* e11 = new_edge();
	edge_assign_direction(e11, v7, v8);
	char* e11_relation = "friends";
	edge_assign_attribute(e11, "relation", e11_relation, STRING);
	print_e(e11);
	print_e_attr(e11);

	//create node for Jerry -> Sarah
	EdgeType* e12 = new_edge();
	edge_assign_direction(e12, v8, v6);
	char* e12_relation = "siblings";
	edge_assign_attribute(e12, "relation", e12_relation, STRING);
	print_e(e12);
	print_e_attr(e12);

	g_insert_v(g1, v1);
	g_insert_v(g1, v2);
	g_insert_v(g1, v3);
	g_insert_v(g1, v4);
	g_insert_v(g1, v5);
	g_insert_v(g1, v6);
	g_insert_v(g1, v7);
	g_insert_v(g1, v8);

	g_insert_e(g1, e1);
	g_insert_e(g1, e2);
	g_insert_e(g1, e3);
	g_insert_e(g1, e4);
	g_insert_e(g1, e5);
	g_insert_e(g1, e6);
	g_insert_e(g1, e7);
	g_insert_e(g1, e8);
	g_insert_e(g1, e9);
	g_insert_e(g1, e10);
	g_insert_e(g1, e11);
	g_insert_e(g1, e12);
	
	
	print_g(g1);
	ListType* lv = list_declaration(VERTEX,3, v1, v2, v3);
	print_list(lv);
	list_append(lv, VERTEX, v4);
	print_list(lv);
	list_append(lv, EDGE, e1);
	print_list(lv);
	list_assign(lv, VERTEX, 2, v6);
	print_list(lv);
	ListType* le = list_declaration(EDGE, 0);
	print_list(le);
	list_append(le, EDGE, e1);
	print_list(le);
	list_assign(le, EDGE, 4, e2);
	print_list(le);
}

