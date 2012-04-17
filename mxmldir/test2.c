#include "config.h"
#include "mxml.h"

int main (int argc, char *argv[])
{
  FILE *fp; /*File to write*/

  mxml_node_t *xml;    /* <?xml ... ?> */
  mxml_node_t *data;   /* <data> */
  mxml_node_t *node;   /* <node> */
  mxml_node_t *group;  /* <group> */

  xml = mxmlNewXML("1.0");

  data = mxmlNewElement(xml, "data");

  node = mxmlNewElement(data, "node");
  mxmlNewText(node, 1, "val1");
  node = mxmlNewElement(data, "node");
  mxmlNewText(node, 1, "val2");
  node = mxmlNewElement(data, "node");
  mxmlNewText(node, 1, "val3");

  group = mxmlNewElement(data, "group");

  node = mxmlNewElement(group, "node");
  mxmlNewText(node, 1, "val4");
  node = mxmlNewElement(group, "node");
  mxmlNewText(node, 1, "val5");
  node = mxmlNewElement(group, "node");
  mxmlNewText(node, 1, "val6");

  node = mxmlNewElement(data, "node");
  mxmlNewText(node, 1, "val7");
  node = mxmlNewElement(data, "node");
  mxmlNewText(node, 1, "val8");

  fp = fopen("filename.xml", "w");
  mxmlSaveFile(xml, fp, MXML_NO_CALLBACK);
  fclose(fp);

}
