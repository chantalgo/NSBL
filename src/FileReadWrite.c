#include <string.h>
#include <stdlib.h>
#include "FileReadWrite.h"


//Function to write graph in xml format
  void saveGraph(GraphType* g, char* fileloc, char* filename)
  {
    FILE *fp; /*File to write*/
	char *delim="/";

    mxml_node_t *xml;    
    mxml_node_t *graph;   
    mxml_node_t *graph_id;   
    mxml_node_t *vertices_list; 
    mxml_node_t *edges_list;  
    mxml_node_t *vertices;
    mxml_node_t *vertex;
    mxml_node_t *vertex_id;
    mxml_node_t *outedges;
	mxml_node_t *outedge;
    mxml_node_t *inedges;
	mxml_node_t *inedge;
    mxml_node_t *vertex_attributes;
    mxml_node_t *vertex_attribute;
    mxml_node_t *vertex_attribute_name;
    mxml_node_t *vertex_attribute_value;
    mxml_node_t *vertex_attribute_value_type;
    mxml_node_t *edges;
    mxml_node_t *edge;
    mxml_node_t *edge_id;
    mxml_node_t *startV;
    mxml_node_t *endV;
    mxml_node_t *edge_attributes;
    mxml_node_t *edge_attribute;
    mxml_node_t *edge_attribute_name;
    mxml_node_t *edge_attribute_value;
    mxml_node_t *edge_attribute_value_type;

    xml = mxmlNewXML("1.0");
    //graph = mxmlNewElement(xml, "graph"); 
    //graph_id = mxmlNewElement(graph, "graph_id");
    //mxmlNewText(graph_id, 1, g->id); 
    //vertices_list = mxmlNewElement(graph, "vertices_list");
    //mxmlNewText(vertices_list, 1, g->vertexIdList);
    //edges_list = mxmlNewElement(graph, "edges_list");
    //mxmlNewText(edges_list, 1, g->edgeIdList);
    vertices = mxmlNewElement(graph, "vertices");
    GList* listV=NULL;
    GList* listE=NULL;
    int lv = g_list_length(g->vertexIdList);
    int n = 0;
    for(n; n<lv; n++)
    {	
     VertexType* v = g_list_nth_data(listV,n);
     vertex = mxmlNewElement(vertices, "vertex");
     vertex_id=mxmlNewElement(vertex,"vertex_id");
     mxmlNewText(vertex_id,1,(const char *)(v->id));
     outedges = mxmlNewElement(vertex,"outedges");
	 int loe= g_list_length(v->outEdges);
	 int y=0;
	 for (y;y<loe;y++)
	 {
		outedge=mxmlNewElement(outedges,"outedge");
		EdgeType* e_temp = g_list_nth_data(v->outEdges,y);
		mxmlNewText(outedge, 1, (const char *)e_temp->id);
	 }
  
     inedges =  mxmlNewElement(vertex,"inedges");

     int lie= g_list_length(v->inEdges);
	 int d=0;
	 for (d;d<lie;d++)
	 {
		inedge=mxmlNewElement(inedges,"inedge");
		EdgeType* e_temp = g_list_nth_data(v->inEdges,d);
		mxmlNewText(inedge, 1, (const char *)e_temp->id);
	 }
     vertex_attributes =  mxmlNewElement(vertex,"vertex_attributes");
     vertex_attribute = mxmlNewElement(vertex_attributes,"vertex_attribute");
     GList* v_attr=g_hash_table_get_keys(v->attributes);
     int a=g_list_length(listV);
     int x=0;
     for(x;x<a;x++)
     {
      vertex_attribute_name=mxmlNewElement(vertex_attribute,"vertex_attribute_name");
      mxmlNewText(vertex_attribute_name, 1,g_list_nth_data(v_attr,x));
      vertex_attribute_name=mxmlNewElement(vertex_attribute, "vertex_attribute_value");
      mxmlNewText(vertex_attribute_value, 1, (char*)vertex_get_attribute_value(v, g_list_nth_data(v_attr,x)));//need to check if cast works as returns void*
	  vertex_attribute_value_type=mxmlNewElement(vertex_attribute, "vertex_attribute_value_type");
	  mxmlNewText(vertex_attribute_name, 1,
	  	(const char *)(g_hash_table_lookup(v->attributes,(gconstpointer)((Attribute* )g_list_nth_data(v_attr,x))->type)
	  		));
     } 		
    }

    int le = g_list_length(g->edgeIdList);
    int m=0;
    for(m; m<le; m++)
    {
      EdgeType* e= g_list_nth_data(listE,m);
      edge =mxmlNewElement(edges,"edge");
      edge_id=mxmlNewElement(edge, "edge_id");
      mxmlNewText(edge_id,1,(const char *)e->id);
      startV = mxmlNewElement(edge, "startV");
      mxmlNewText(startV,1,(const char *)(e->start->id));
      endV = mxmlNewElement(edge,"endV");
      mxmlNewText(endV,1,(const char *)(e->end->id));
      edge_attributes = mxmlNewElement(edge, "edge_attributes");
      edge_attribute = mxmlNewElement(edge_attributes, "edge_attribute");
      GList* e_attr= g_hash_table_get_keys(e->attributes);
      int b=g_list_length(listE);
      int y=0;
      for (y; y<b;y++)
      {
        edge_attribute_name=mxmlNewElement(edge_attribute,"edge_attribute_name");
        mxmlNewText(edge_attribute_name,1, g_list_nth_data(e_attr,y));
        edge_attribute_name=mxmlNewElement(edge_attribute,"edge_attribute_value");
        mxmlNewText(edge_attribute_value,1, (char*)edge_get_attribute_value(e, g_list_nth_data(e_attr,y)));//need to check if cast works as returns void*
		edge_attribute_value_type=mxmlNewElement(edge_attribute, "edge_attribute_value_type");
	    mxmlNewText(edge_attribute_name, 1,
	    	(const char *)(g_hash_table_lookup(e->attributes,(gconstpointer)((Attribute*)g_list_nth_data(e_attr,y))->type)
	    	));
      }
    }
	  strcat(fileloc, delim);
	  strcat(fileloc, filename);
      fp = fopen(fileloc, "w");
      mxmlSaveFile(xml, fp, MXML_NO_CALLBACK);
      fclose(fp);


  }

  //Function to read a saved xml graph
  GraphType* readGraph(char* fileloc, char* filename)
  {
	FILE *fp;
    mxml_node_t *tree;
    mxml_node_t *node;
	mxml_node_t *node_temp1;
	mxml_node_t *node_temp2;
	char *delim="/";
	char *temp_eID;
	char *temp_vID;
	GraphType* g;
	VertexType* v;
	EdgeType* e;
	GList* edge_list;
	GList* vertices_list;
	GList* check_edgesID;
	GList* check_verticesID;

	strcat(fileloc,delim);
	strcat(fileloc,filename);
    
    fp = fopen(fileloc, "r");
    tree = mxmlLoadFile(NULL, fp,MXML_TEXT_CALLBACK);
    fclose(fp);

	//set new VERTEX IDs
    for (node = mxmlFindElement(tree, tree,
                                "vertex",
                                NULL, NULL,
                                MXML_DESCEND);
         node != NULL;
         node = mxmlFindElement(node, tree,
                                "vertex",
                                NULL, NULL,
                                MXML_DESCEND))
		 {
			 node = mxmlGetFirstChild(node);//vertex id
			 char *old_vID=(char *)mxmlGetText(node,NULL);
			 char *new_vID=(char *)((long int)new_vertexId());
			 mxmlSetText(node, 1, new_vID);

			 //updating new vertexID at every startV node
			 for (node = mxmlFindElement(tree, tree,
										"startV",
										NULL, NULL,
										MXML_DESCEND);
				node != NULL;
				node = mxmlFindElement(node, tree,
										"startV",
										NULL, NULL,
										MXML_DESCEND))
				{
						if (mxmlGetText(node,NULL)==old_vID)
						{
							mxmlSetText(node, 1, new_vID);
						}
				}

             //updating new vertexID at every endV node  
			 for (node = mxmlFindElement(tree, tree,
										"endV",
										NULL, NULL,
										MXML_DESCEND);
				node != NULL;
				node = mxmlFindElement(node, tree,
										"endV",
										NULL, NULL,
										MXML_DESCEND))
				{
						if (mxmlGetText(node,NULL)==old_vID)
						{
							mxmlSetText(node, 1, new_vID);
						}
				}
		 }

	//set new EDGE IDs
    for (node = mxmlFindElement(tree, tree,
                                "edge",
                                NULL, NULL,
                                MXML_DESCEND);
         node != NULL;
         node = mxmlFindElement(node, tree,
                                "edge",
                                NULL, NULL,
                                MXML_DESCEND))
    {
			 node = mxmlGetFirstChild(node);//edge id
			 char *old_eID=(char *)mxmlGetText(node,NULL);
			 char *new_eID=(char *)((long int)new_edgeId());
			 mxmlSetText(node, 1, new_eID);

			 //updating new edgeID at every outedge node
			 for (node = mxmlFindElement(tree, tree,
										"outedge",
										NULL, NULL,
										MXML_DESCEND);
				node != NULL;
				node = mxmlFindElement(node, tree,
										"outedge",
										NULL, NULL,
										MXML_DESCEND))
				{
						if (mxmlGetText(node,NULL)==old_eID)
						{
							mxmlSetText(node, 1, new_eID);
						}
				}

             //updating new edgeID at every inedge node  
			 for (node = mxmlFindElement(tree, tree,
										"inedge",
										NULL, NULL,
										MXML_DESCEND);
				node != NULL;
				node = mxmlFindElement(node, tree,
										"inedge",
										NULL, NULL,
										MXML_DESCEND))
				{
						if (mxmlGetText(node,NULL)==old_eID)
						{
							mxmlSetText(node, 1, new_eID);
						}
				}
		 }
		 
		 
		 
    //creating a new graph so as to copy the old graph into it.
    g=new_graph();
	//creating vertex from the xml
    for (node = mxmlFindElement(tree, tree,
                                "vertex",
                                NULL, NULL,
                                MXML_DESCEND);
         node != NULL;
         node = mxmlFindElement(node, tree,
                                "vertex",
                                NULL, NULL,
                                MXML_DESCEND))
    {
        v=new_vertex();
		node = mxmlGetFirstChild(node);//vertex id
	    v->id=(long int)(mxmlGetText(node,NULL));
		node = mxmlGetNextSibling(node);//skip outedges
		node = mxmlGetNextSibling(node);//skip inedges
		node = mxmlGetNextSibling(node);//populate attributes for the vertex
		node_temp1 = mxmlGetLastChild(node);
		node_temp2 = mxmlGetFirstChild(node);
		while(node_temp1!=node_temp2)
		{
			char* attribute=(char*)mxmlGetText(node_temp2,NULL);//attr name
			node_temp2=mxmlGetNextSibling(node_temp2);//go to attr value
			void* value=(void*)mxmlGetText(node_temp2,NULL);//needs to be checked
			node_temp2=mxmlGetNextSibling(node_temp2);//go to attr value type
			int type=(long int)mxmlGetText(node_temp2,NULL);
			vertex_assign_attribute( v, attribute, value, type);//check if its correct as it returns int
            node_temp2=mxmlGetNextSibling(node_temp2);
		}
		//inserting vertex into graph
		 g_insert_v(g, v);//check if its correct as it returns int

    }
	//creating edge from the xml
    for (node = mxmlFindElement(tree, tree,
                                "edge",
                                NULL, NULL,
                                MXML_DESCEND);
         node != NULL;
         node = mxmlFindElement(node, tree,
                                "edge",
                                NULL, NULL,
                                MXML_DESCEND))
	{
	    VertexType* sv;
	    VertexType* ev;
		e=new_edge();
		node = mxmlGetFirstChild(node);//edge id
	    e->id=(int)(long int)(mxmlGetText(node,NULL));
		node = mxmlGetNextSibling(node);
		int startVId=(int)((long int)(mxmlGetText(node,NULL)));
		//have to check if the hash table lookup works or not
		sv=g_hash_table_lookup(g->vertices,(gconstpointer)(long int)startVId);
		node = mxmlGetNextSibling(node);
		int endVId=(int)((long int)(mxmlGetText(node,NULL)));
		//have to check if the hash table lookup works or not
		ev=g_hash_table_lookup(g->vertices,(gconstpointer)(long int)endVId);
		//the below code populates outedges and inedges as well
		edge_assign_direction(e, sv, ev);//check if its correct as it returns int
		//go to edge_attributes
		node = mxmlGetNextSibling(node);
		//go to edge_attribute(firstchild)
		node = mxmlGetFirstChild(node);
		//go to edge_attribute_name/value/type
		node_temp1 = mxmlGetLastChild(node);
		node_temp2 = mxmlGetFirstChild(node);
		while(node_temp1!=node_temp2)
		{
			char* attribute=(char*)mxmlGetText(node_temp2,NULL);//attr name
			node_temp2=mxmlGetNextSibling(node_temp2);//go to attr value
			void* value=(void*)mxmlGetText(node_temp2,NULL);//needs to be checked
			node_temp2=mxmlGetNextSibling(node_temp2);//go to attr value type
			int type=(int)(long int)mxmlGetText(node_temp2,NULL);
			edge_assign_attribute( e, attribute, value, type);//check if its correct as it returns int
            node_temp2=mxmlGetNextSibling(node_temp2);
		}
		//inserting vertex into graph
		 g_insert_e(g, e);//check if its correct as it returns int
		 
	}
  }

  
