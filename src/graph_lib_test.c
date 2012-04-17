#include "Derivedtype.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){
	GraphType* g1 = new_graph();
	VertexType* v1 = new_vertex();
	VertexType* v2 = new_vertex();
	char* v1_name = "Jack";
	int v1_age = 28;
	float v1_weight = 60.5;
	vertex_assign_attribute(v1, "name", v1_name, 3);
	vertex_assign_attribute(v1, "age", &v1_age, 1);
	vertex_assign_attribute(v1, "weight", &v1_weight, 2);
	print_v(v1);
	print_v_attr(v1);

	char* v2_name = "Tom";
	int v2_age = 29;
	float v2_weight = 80.9;
	vertex_assign_attribute(v2, "name", v2_name, 3);
	vertex_assign_attribute(v2, "age", &v2_age, 1);
	vertex_assign_attribute(v2, "weight", &v2_weight, 2);
	print_v(v2);
	print_v_attr(v2);

	EdgeType* e1 = new_edge();
	edge_assign_direction(e1, v1, v2);
	char* e1_relation = "friends";
	edge_assign_attribute(e1, "relation", e1_relation, 3);
	print_e(e1);
	print_e_attr(e1);

	g_insert_v(g1, v1);
	g_insert_v(g1, v2);
	g_insert_e(g1, e1);

	print_g(g1);
}

