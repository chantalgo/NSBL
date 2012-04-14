  #include "config.h"
  #include "mxml.h"
  #include "Derivedtype.h"

  int main (int argc, char *argv[])
  {
    FILE *fp; /*File to write*/

    mxml_node_t *xml;    
    mxml_node_t *graph;   
    mxml_node_t *graph_id;   
    mxml_node_t *vertices_list; 
    mxml_node_t *edges_list;  
    mxml_node_t *vertices;
    mxml_node_t *vertex;
    mxml_node_t *vertex_id;
    mxml_node_t *outedges;
    mxml_node_t *inedges;
    mxml_node_t *Vertex_attributes;
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
    graph_id = mxmlNewElement(graph, "graph_id");
    mxmlNewText(graph_id, 1, g->id); 
    vertices_list = mxmlNewElement(graph, "vertices_list");
    mxmlNewText(vertices_list, 1, g->vertexIdList);
    edges_list = mxmlNewElement(graph, "edges_list");
    mxmlNewText(edges_list, 1, g->edgeIdList);
    vertices = mxmlNewElement(graph, "vertices");
    GList* listV=NULL;
    GList* listE=NULL;
    int lv = g_list_length(g->vertexIdList);
    int n = 0;
    for(n; n<lv; n++)
    {	
     VertexType* v = g_list_nth_data(listV,n);
     vertex = mxmlNewElement(vertices, "vertex");
     vertex_id=mxmlNewElemet(vertex,"vertex_id");
     mxmlNewText(vertex_id, 1, v->id);
     outedges = mxmlNewElement(vertex,"outedges");
     mxmlNewText(outedges, 1, v->outedges);
     inedges =  mxmlNewElement(vertex,"inedges");
     mxmlNewText(inedges, 1, v->inedges);
     vertex_attributes =  mxmlNewElement(vertex,"vertex_attributes");
     vertex_attribute = mxmlNewElement(vertex_attributes,"vertex_attribute");
     GList* v_attr=g_hash_table_get_keys(v->attributes);
     int a=g_list_length(v);
     int x=0;
     for(x;x<a;x++)
     {
      vertex_attribute_name=mxmlNewElement(vertex_attribute,"vertex_attribute_name");
      mxmlNewText(vertex_attribute_name, 1,g_list_nth_data(v_attr,x));
      vertex_attribute_name=mxmlNewElement(vertex_attribute, "vertex_attribute_value");
      mxmlNewElement(vertex_attribute_value, 1, vertex_get_attribute_value(v, g_list_nth_data(v_attr,x)));	
     } 		
    }

    int le = g_list_length(g->edgeIdList);
    int m=0;
    for(m; m<le; m++)
    {
      EdgeType* e= g_list_nth_data(listE,m);
      edge =mxmlNewElement(edges,"edge");
      edge_id=mxmlNewElement(edge, "edge_id");
      mxmlNewText(edge_id,1,e->id);
      startV = mxmlNewElement(edge, "startV");
      mxmlNewText(startV,1,e->start);
      endV = mxmlNewElement(edge,"endV");
      mxmlNewText(endV,1,e->end);
      edge_attributes = mxmlNewElement(edge, "edge_attributes");
      edge_attribute = mxmlNewElement(edge_attributes, "edge_attribute");
      GList* e_attr= g_hash_table_get_keys(e->attributes);
      int b=g_list_length(e);
      int y=0;
      for (y; y<b;y++)
      {
        edge_attribute_name=mxmlNewElement(edge_attribute,"edge_attribute_name");
        mxmlNewText(edge_attribute_name,1, g_list_nth_data(e_attr,y));
        edge_attribute_name=mxmlNewElement(edge_attribute,"edge_attribute_value");
        mxmlNewElement(edge_attribute_value,1, vertex_get_attribute_value(e, g_list_nth_data(e_attr,y)));
      }
    }
      fp = fopen("filename.xml", "w");
      mxmlSaveFile(xml, fp, MXML_NO_CALLBACK);
      fclose(fp);


  }
