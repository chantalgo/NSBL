#include "FileReadWrite.h"



//Function to write graph in xml format
  void saveGraph(GraphType* g, char* fileloc)
  {
    FILE *fp; /*File to write*/
	char *delim="/";
	char filepath[100];
	char str[100];


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
    graph = mxmlNewElement(xml, "graph"); 
    //graph_id = mxmlNewElement(graph, "graph_id");
    //mxmlNewText(graph_id, 1, g->id); 
    //vertices_list = mxmlNewElement(graph, "vertices_list");
    //mxmlNewText(vertices_list, 1, g->vertexIdList);
    //edges_list = mxmlNewElement(graph, "edges_list");
    //mxmlNewText(edges_list, 1, g->edgeIdList);
    
    vertices = mxmlNewElement(graph, "vertices");
    GList* listV= g_hash_table_get_values(g->vertices);
    GList* listE= g_hash_table_get_values(g->edges) ;
    int lv = g_list_length(g->vertexIdList);
    int n = 0;
    
    for(n; n<lv; n++)
    {	
     VertexType* v = (VertexType*)(g_list_nth_data(listV,n));
     vertex = mxmlNewElement(vertices, "vertex");
     vertex_id=mxmlNewElement(vertex,"vertex_id");
     int len = snprintf(str, 100, "%ld",v->id );
     //printf("%s\n",str);
     mxmlNewText(vertex_id,0,str);
		
        outedges = mxmlNewElement(vertex,"outedges");
	 int loe= g_list_length(v->outEdges);
	 int y=0;
	 for (y;y<loe;y++)
	 {
		outedge=mxmlNewElement(outedges,"outedge");
		EdgeType* e_temp = g_list_nth_data(v->outEdges,y);
		int len = snprintf(str, 100, "%ld",e_temp->id );
		mxmlNewText(outedge, 0, str);
	 }
  
     inedges =  mxmlNewElement(vertex,"inedges");

     int lie= g_list_length(v->inEdges);
	 int d=0;
	 for (d;d<lie;d++)
	 {
		inedge=mxmlNewElement(inedges,"inedge");
		EdgeType* e_temp = g_list_nth_data(v->inEdges,d);
		int len = snprintf(str, 100, "%ld",e_temp->id );
		mxmlNewText(inedge, 0, str);
	 }
     vertex_attributes =  mxmlNewElement(vertex,"vertex_attributes");
     //vertex_attribute = mxmlNewElement(vertex_attributes,"vertex_attribute");
     GList* v_attr=g_hash_table_get_keys(v->attributes);
     GList* v_attr_value=g_hash_table_get_values(v->attributes);
     int a=g_list_length(v_attr);
     int x=0;

     for(x;x<a;x++)
     {
      vertex_attribute = mxmlNewElement(vertex_attributes,"vertex_attribute");
	vertex_attribute_name=mxmlNewElement(vertex_attribute,"vertex_attribute_name");
      mxmlNewText(vertex_attribute_name, 0,(char *)g_list_nth_data(v_attr,x));
      vertex_attribute_value=mxmlNewElement(vertex_attribute, "vertex_attribute_value");
        Attribute* a=(Attribute*)(g_list_nth_data(v_attr_value,x));
        int type=(int )a->type;
	if (type==INT_T)
	{

		len = snprintf(str, 100, "%d",((Attribute*)(g_list_nth_data(v_attr_value,x)))->value.iv);
                mxmlNewText(vertex_attribute_value,0,str);
        }
        if (type==FLOAT_T)
        {
                len = snprintf(str, 100, "%f",((Attribute*)(g_list_nth_data(v_attr_value,x)))->value.fv);
                mxmlNewText(vertex_attribute_value,0,str);
        }
        if (type==STRING_T)
        {
		 mxmlNewText(vertex_attribute_value, 0,
         ((Attribute*)(g_list_nth_data(v_attr_value,x)))->value.sv->str);

                //mxmlNewText(edge_attribute_value,1, (char*)(((Attribute*)(g_list_nth_data(e_attr_value,y)))->value));
        }

      //printf("%s\n",(char*)(((Attribute*)(g_list_nth_data(v_attr_value,x)))->value));

    /*  
	Attribute* attr = (Attribute*) malloc(sizeof(Attribute));
	attr = (Attribute*)g_list_nth_data(v_attr_value,x);
	long int abc = attr->type;
	void *t = attr->value;
	fprintf(stderr,"\n\n%d\n\n%d\n\n", abc,sizeof((char *)t));
	char* temp=(char*)g_list_nth_data(v_attr,x);
	void* t=(vertex_get_attribute_value(v, "Name"));
	*/

	//char *t1 = (char*)(attr->value);
      //char *temp=(char*)(((Attribute*)(g_list_nth_data(v_attr_value,x)))->value);
	//char *temp1 = (char *)malloc(sizeof(char *)* sizeof(temp));
      //printf("%s\n",temp);
      //int len = snprintf(str, 100, "%s",temp );
      //printf("%s %d\n",temp, sizeof(temp));
	//memcpy(temp1, temp,sizeof(temp));
//	mxmlNewText(vertex_attribute_value, 1, 
//	(char*)(((Attribute*)(g_list_nth_data(v_attr_value,x)))->value));
      //mxmlNewText(vertex_attribute_value, 1, temp1);
	//mxmlNewText(vertex_attribute_value, 1, (char *)(((Attribute*)(g_list_nth_data(v_attr_value,x)))->value));
      //mxmlNewText(vertex_attribute_value, 1, (char*)(vertex_get_attribute_value(v, g_list_nth_data(v_attr,x))));//need to check if cast works as returns void*

	  vertex_attribute_value_type=mxmlNewElement(vertex_attribute, "vertex_attribute_value_type");
	//mxmlNewText(vertex_attribute_value_type,1,  
	int len = snprintf(str, 100, "%d",((int)((Attribute*)(g_list_nth_data(v_attr_value,x)))->type));
	//printf("\nPrinting type of value in vertex by jing :: %s\n", str);
	//printf("\nVertex attr value derived by me : %d\n", type);
	//printf("\n INT value: %d\n", INT_T);
	//printf("\n FLOAT value: %d\n", FLOAT_T);
	//printf("\n STRING value: %d\n", STRING_T);
	mxmlNewText(vertex_attribute_value_type, 0, str);
	  	
	  		

     }		
    }

    edges = mxmlNewElement(graph, "edges");
    int le = g_list_length(g->edgeIdList);
    int m=0;
    for(m; m<le; m++)
    {
      EdgeType* e= g_list_nth_data(listE,m);
      edge =mxmlNewElement(edges,"edge");
      edge_id=mxmlNewElement(edge, "edge_id");
      int len = snprintf(str, 100, "%ld",(e->id) );
      mxmlNewText(edge_id,0,str);
      startV = mxmlNewElement(edge, "startV");
      len = snprintf(str, 100, "%ld",e->start->id );
      mxmlNewText(startV,0,str);
      endV = mxmlNewElement(edge,"endV");

     len = snprintf(str, 100, "%ld",(e->end->id) );
      mxmlNewText(endV,0,str);
      edge_attributes = mxmlNewElement(edge, "edge_attributes");
      //edge_attribute = mxmlNewElement(edge_attributes, "edge_attribute");
      
      GList* e_attr= g_hash_table_get_keys(e->attributes);
      GList* e_attr_value=g_hash_table_get_values(e->attributes);
      int b=g_list_length(e_attr);
      //printf("Just before seg fault1\n");
	int c=g_list_length(e_attr_value);
      //printf("just before seg fault\n");
      //printf("lengths %d   %d\n",b,c);	
      int y=0;
      for (y; y<b;y++)
      {
        edge_attribute = mxmlNewElement(edge_attributes, "edge_attribute");
	edge_attribute_name=mxmlNewElement(edge_attribute,"edge_attribute_name");
        mxmlNewText(edge_attribute_name,0, (char*)g_list_nth_data(e_attr,y));
        edge_attribute_value=mxmlNewElement(edge_attribute,"edge_attribute_value");
	//mxmlNewText(edge_attribute_value, 1,(char*)(((Attribute*)(g_list_nth_data(e_attr_value,y)))->value));
	Attribute* a=(Attribute*)(g_list_nth_data(e_attr_value,y)); 
	int type=(int )a->type;
	if (type==INT_T)
	{
		len = snprintf(str, 100, "%d",((Attribute*)(g_list_nth_data(e_attr_value,y)))->value.iv);
		mxmlNewText(edge_attribute_value,0,str);
	}
	if (type==FLOAT_T)
        {
        len = snprintf(str, 100, "%f",((Attribute*)(g_list_nth_data(e_attr_value,y)))->value.fv);
                mxmlNewText(edge_attribute_value,0,str);
        }
        if (type==STRING_T)
        {
                mxmlNewText(edge_attribute_value,0, ((Attribute*)(g_list_nth_data(e_attr_value,y)))->value.sv->str);
        }


	//mxmlNewText(edge_attribute_value, 1,
        //(char*)(((Attribute*)(g_list_nth_data(e_attr_value,y)))->value));

	//int len = snprintf(str, 100, "%d",(int)((Attribute*)(g_list_nth_data(e_attr_value,y)))->value);
//mxmlNewText(edge_attribute_value, 1,(char*)((Attribute*)(g_list_nth_data(e_attr_value,y)))->value);
	//Attribute* a=g_list_nth_data(e_attr_value,y);
	//printf("edge attribute value: %s\n",a->value);
	//(char*)(((Attribute*)(g_list_nth_data(e_attr_value,y)))->value));
        //mxmlNewText(edge_attribute_value,1, (char*)(((Attribute*)(g_list_nth_data(e_attr_value,y)))->value));
//need to check if cast works as returns void*
		edge_attribute_value_type=mxmlNewElement(edge_attribute, "edge_attribute_value_type");
	        len = snprintf(str, 100, "%d",((int)((Attribute*)(g_list_nth_data(e_attr_value,y)))->type));
		//printf("\nPrinting the attribute value of edge derived from jing: %s\n", str);
		//printf("\nEdge attr value derived by me: %d\n", type);
        mxmlNewText(edge_attribute_value_type, 0, str);
	    
     }
    }
	/*
	strcpy(filepath, fileloc);
		
    printf("%s\n", filepath );
B

    
    if((strcmp(fileloc,delim)!=0)&&(strcmp(fileloc,"./")!=0))
      {
      strcat(filepath, delim);
	  printf("%s\n", filepath );
      }

	  strcat(filepath, filename);
      printf("%s\n", filepath );
         */
      fp = fopen(fileloc, "w");
      mxmlSaveFile(xml, fp, MXML_NO_CALLBACK);
      fclose(fp);
 	//printf("%s xml file written\n\n",fileloc);


  }

  //Function to read a saved xml graph
  GraphType* readGraph(char* fileloc)
  {
	FILE *fp;
    mxml_node_t *tree;
    mxml_node_t *node;
	mxml_node_t *node_loop;
	mxml_node_t *node_v;
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
	char temp[100];
	char str[100];
/*		
	strcpy(filepath, fileloc);

    	printf("%s\n", filepath );


    	if((strcmp(fileloc,delim)!=0)&&(strcmp(fileloc,"./")!=0))
      	{
      		strcat(filepath, delim);
          	printf("%s\n", filepath );
      	}

        strcat(filepath, filename);
        printf("%s\n", filepath );
*/
    

    	fp = fopen(fileloc, "r");
  	/*invalid or empty file name check */
        if (fp==NULL)
        {
                printf("Error in provided file name. Please check file name again.\n");
                return 0;
        }
        tree = mxmlLoadFile(NULL, fp,MXML_TEXT_CALLBACK);
        /*xml file check */
        if (tree==NULL)
        {
                printf("The file provided is not an XML file.\n");
                return 0;
        }
        fclose(fp);



	//printf("xml loaded\n");

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
			 char *old_vID= (char*)malloc(sizeof(char));
			 strcpy(old_vID ,mxmlGetText(node,NULL));
			 //printf("old vertex id: %s\n", old_vID);
			 int len = snprintf(str, 100, "%ld",(long int)new_vertexId());
			 //printf("new vertex id: %s\n", str);  
			 //char *new_vID=(char *)((long int)new_vertexId());
			 mxmlSetText(node, 0, str);
			 //printf("vertex id updated\n");

			 //updating new vertexID at every startV node
			 for (node_loop = mxmlFindElement(tree, tree,
										"startV",
										NULL, NULL,
										MXML_DESCEND);
				node_loop != NULL;
				node_loop = mxmlFindElement(node_loop, tree,
										"startV",
										NULL, NULL,
										MXML_DESCEND))
				{
						//printf("node text: %s\n",mxmlGetText(node_loop,NULL));
						//printf("old vid: %s\n",old_vID); 
						//printf("str cmp%d\n", strcmp(old_vID,mxmlGetText(node_loop,NULL)));
						if ((strcmp(old_vID,mxmlGetText(node_loop,NULL))==0))
						{
							mxmlSetText(node_loop, 0, str);
							//printf("updated startV\n"); 
						}
						//else
							//printf("didnt update startV\n");
				}

             		 //updating new vertexID at every endV node  
			 for (node_loop = mxmlFindElement(tree, tree,
										"endV",
										NULL, NULL,
										MXML_DESCEND);
				node_loop != NULL;
				node_loop = mxmlFindElement(node_loop, tree,
										"endV",
										NULL, NULL,
										MXML_DESCEND))
				{
						if  ((strcmp(old_vID,mxmlGetText(node_loop,NULL))==0))
						{
							mxmlSetText(node_loop, 0, str);
							//printf("updated endV\n");
						}
                                                //else
                                                        //printf("didnt update endV\n");

						
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
			 char *old_eID= (char*)malloc(sizeof(char));
                         strcpy(old_eID ,mxmlGetText(node,NULL));
                         //printf("old edge id: %s\n", old_eID);
                         int len = snprintf(str, 100, "%ld",(long int)new_edgeId());
                         //printf("new edge id: %s\n", str);
                         //char *new_vID=(char *)((long int)new_vertexId());
                         mxmlSetText(node, 0, str);

			 //updating new edgeID at every outedge node
			 for (node_loop = mxmlFindElement(tree, tree,
										"outedge",
										NULL, NULL,
										MXML_DESCEND);
				node_loop != NULL;
				node_loop = mxmlFindElement(node_loop, tree,
										"outedge",
										NULL, NULL,
										MXML_DESCEND))
				{
						//printf("outedge node text: %s\n",mxmlGetText(node_loop,NULL));
                                                //printf("old eid: %s\n",old_eID);
                                                //printf("str cmp: %d\n", strcmp(old_eID,mxmlGetText(node_loop,NULL)));

						if ((strcmp(old_eID,mxmlGetText(node_loop,NULL))==0))

						{
							mxmlSetText(node_loop, 0, str);
							//printf("udpated outedge\n");
						}
						//else
							//printf("not updated outedge\n");
				}

             //updating new edgeID at every inedge node  

			 for (node_loop = mxmlFindElement(tree, tree,
										"inedge",
										NULL, NULL,
										MXML_DESCEND);
				node_loop != NULL;
				node_loop = mxmlFindElement(node_loop, tree,
										"inedge",
										NULL, NULL,
										MXML_DESCEND))
				{
                                                //printf("inedge node text: %s\n",mxmlGetText(node_loop,NULL));
                                                //printf("old eid: %s\n",old_eID);
                                                //printf("str cmp: %d\n", strcmp(old_eID,mxmlGetText(node_loop,NULL)));

						if ((strcmp(old_eID,mxmlGetText(node_loop,NULL))==0))

						{
							mxmlSetText(node_loop, 0, str);
							//printf("updated inedge\n");
						}
						//else
							//printf("not updated inedge\n");
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
		node_v = mxmlGetFirstChild(node);//vertex id
		 //printf("checkpoint node temp 2(attr name): %s\n", mxmlGetElement(node_v));
	    v->id=atoi(mxmlGetText(node_v,NULL));
		//printf("node vertex text: %s\n",mxmlGetText(node_v,NULL));
		//printf("new vertex id: %ld\n", v->id);
		node_v = mxmlGetNextSibling(node_v);//skip outedges
         	 //printf("checkpoint node temp 2(attr name): %s\n", mxmlGetElement(node_v));
		node_v = mxmlGetNextSibling(node_v);//skip inedges
		 //printf("checkpoint node temp 2(attr name): %s\n", mxmlGetElement(node_v));
		node_v = mxmlGetNextSibling(node_v);//populate attributes for the vertex
		 //printf("checkpoint node temp 2(attr name): %s\n", mxmlGetElement(node_v));
		//node_temp1 = mxmlGetLastChild(node_v);
		node_temp1 = mxmlGetFirstChild(node_v);
		// printf("checkpoint node temp 2(attr name): %s\n", mxmlGetElement(node_temp1));
		//node_temp2 = mxmlGetFirstChild(node_temp1);
		//printf("checkpoint node temp 2(attr name): %s\n", mxmlGetElement(node_temp2));
		 //printf("checkpoint node temp 2(attr name): %s\n", mxmlGetText(node_temp2,NULL));
		//int *v =(int*)malloc(sizeof(int));  
		while(node_temp1!=NULL)
		{
			node_temp2 = mxmlGetFirstChild(node_temp1);
                	//printf("checkpoint node temp 2(attr name): %s\n", mxmlGetElement(node_temp2));
                	//printf("checkpoint node temp 2(attr name): %s\n", mxmlGetText(node_temp2,NULL));
			char* attribute = (char *) mxmlGetText(node_temp2,NULL);//attr name
			node_temp2=mxmlGetNextSibling(node_temp2);//go to attr value
			mxml_node_t *n=node_temp2;
			//printf("checkpoint node temp 2(attr name): %s\n", mxmlGetElement(node_temp2));
			void* value;//=mxmlGetText(node_temp2,NULL);//needs to be checked
			node_temp2=mxmlGetNextSibling(node_temp2);//go to attr value type
			//printf("checkpoint node temp 2(attr name): %s\n", mxmlGetElement(node_temp2));
			int type=atoi(mxmlGetText(node_temp2,NULL));
                        if (type==INT_T)
                        {
                                int val=atoi(mxmlGetText(n,NULL));
				//printf("printing int val: %d\n",val);
				int *v1 =(int*)malloc(sizeof(int));
				*v1=val;
                                vertex_assign_attribute( v, attribute, v1, type);
                                //printf("\nattribute assigned to vertex\n");
                                //value=&val;
                        }
                        if (type==FLOAT_T)
                        {
                                float val=atof(mxmlGetText(n,NULL));
				//printf("printing float val: %f\n",val);
                                float* f1=(float*)malloc(sizeof(float));
				*f1=val;
				vertex_assign_attribute( v, attribute, f1, type);
                                //printf("\nattribute assigned to vertex\n");	
                                //value=&val;
                        }
                        if (type==STRING_T)
                        {
                                //value= (char *)mxmlGetText(n,NULL);
				char* c = (char*) malloc(sizeof(char));
				c = (char*)mxmlGetText(n,NULL);
				//printf("printing char val: %s\n",c);
				GString* s=g_string_new(c);   
                                vertex_assign_attribute( v, attribute, s, type);
                                //printf("\nattribute assigned to edge\n");
                        }

			//vertex_assign_attribute( v, attribute, value, type);//check if its correct as it returns int
            		//testing if vertex assigned attribute or not
			//printf("vertex attribute value: %d\n",vertex_get_attribute_value(v, attribute));
			node_temp1=mxmlGetNextSibling(node_temp1);
		}
		//testing if vetrex is assigned attrubute or not .
		//print_v_attr(v);		
		//inserting vertex into graph
		 g_insert_v(g, v);//check if its correct as it returns int
		//printf("vertex inserted\n");

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
		node_v = mxmlGetFirstChild(node);//edge id
	    	e->id=atoi(mxmlGetText(node_v,NULL));
		//printf("edge id: %d\n", e->id);
		node_v = mxmlGetNextSibling(node_v);
		//printf("check node name in edge: %s\n", mxmlGetElement(node_v));

		
		int startVId=atoi(mxmlGetText(node_v,NULL));
		//printf("startV id: %d\n",startVId);
		//have to check if the hash table lookup works or not
		GList* listV= g_hash_table_get_values(g->vertices);
		int loe= g_list_length(listV);
         	int y=0;
			for (y;y<loe;y++)
			{
				VertexType* v = (VertexType*)(g_list_nth_data(listV,y));
				if (v->id==startVId)
					sv=v;
			}
		//printf("sv->id: %d\n",sv->id); 
			
			//sv=(VertexType*)g_hash_table_lookup(g->vertices,startVId);
		node_v = mxmlGetNextSibling(node_v);
		//printf("check node name in edge: %s\n", mxmlGetElement(node_v));
		int endVId=atoi(mxmlGetText(node_v,NULL));
		//printf("endV id: %d\n",endVId);

		                 //y=0;
			for (y=0;y<loe;y++)
                        {
                                VertexType* v = (VertexType*)(g_list_nth_data(listV,y));
                                if (v->id==endVId)
                                        ev=v;
                        }
                //printf("ev->id: %d\n",ev->id);

		//have to check if the hash table lookup works or not
//		ev=g_hash_table_lookup(g->vertices,(gconstpointer)(long int)endVId);
		//the below code populates outedges and inedges as well
		edge_assign_direction(e, sv, ev);//check if its correct as it returns int
		//go to edge_attributes
		//printf("edge direction assigned\n");
		node_v = mxmlGetNextSibling(node_v);
		//printf("check node name in edge: %s\n", mxmlGetElement(node_v));
		//go to edge_attribute(firstchild)
		node_temp1 = mxmlGetFirstChild(node_v);
		//printf("check node name in edge: %s\n", mxmlGetElement(node_temp1));
		
		//go to edge_attribute_name/value/type
		//node_temp1 = mxmlGetLastChild(node_v);
		//printf("check node name in edge  node_temp1: %s\n", mxmlGetElement(node_v));

		//node_temp1 = mxmlGetFirstChild(node_temp1);
		//printf("check node name in edge: %s\n", mxmlGetElement(node_v));

		while(node_temp1!=NULL)
		{
			node_temp2 = mxmlGetFirstChild(node_temp1);
                        //printf("node_temp2: %s\n", mxmlGetElement(node_temp2));
                        //printf("checkpoint node temp 2(attr name): %s\n", mxmlGetText(node_temp2,NULL));
			char* attribute=(char *)mxmlGetText(node_temp2,NULL);//attr name
			node_temp2=mxmlGetNextSibling(node_temp2);//go to attr value
			mxml_node_t *n=node_temp2;
			void* value;//=mxmlGetText(node_temp2,NULL);//needs to be checked
 			node_temp2=mxmlGetNextSibling(node_temp2);//go to attr value type
			int type=atoi(mxmlGetText(node_temp2,NULL));
			if (type==INT_T)
			{
				int val=atoi(mxmlGetText(n,NULL));
				//printf("printing int val: %d\n", val); 
                                //printf("printing int val: %d\n",val);
                                int *v1 =(int*)malloc(sizeof(int));
                                *v1=val;
				edge_assign_attribute( e, attribute, v1, type);
				//printf("\nattribute assigned to edge\n");
				//value=&val;
			}
			if (type==FLOAT_T)
			{
				 //int len = snprintf(str, 100, "%f",(mxmlGetText(n,NULL))); 
				float val=atof(mxmlGetText(n,NULL));
				//printf("printing float val: %f\n",val);
                                float *v1 =(float*)malloc(sizeof(float));
                                *v1=val;		
                                edge_assign_attribute( e, attribute, v1, type);
                                //printf("\nattribute assigned to edge\n");
                                
                                
				//value=&val;
			}
			if (type==STRING_T)
			{
				//value=(char *)mxmlGetText(n,NULL);
                                char* c = (char*) malloc(sizeof(char));
                                c = (char*)mxmlGetText(n,NULL);
				GString* s=g_string_new(c);
                                edge_assign_attribute( e, attribute, s, type);
                                //printf("\nattribute assigned to edge\n");
			}	
			
			//edge_assign_attribute( e, attribute, value, type);//check if its correct as it returns int
            		//printf("\nattribute assigned to edge\n");
			node_temp1=mxmlGetNextSibling(node_temp1);
		}
		//inserting vertex into graph
		 g_insert_e(g, e);//check if its correct as it returns int
		 //printf("edge insrted\n");

	}

//test to see if graph getting changed
	//fp = fopen("tryc.xml", "w");
      	//mxmlSaveFile(tree, fp, MXML_NO_CALLBACK);
      	//fclose(fp);
	//printf("test xml written\n");
	return g;


  }

  
