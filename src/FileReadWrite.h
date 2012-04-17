#ifndef NSBL_IO_H_NSBL
#define NSBL_IO_H_NSBL


#include "../mxmldir/mxml.h"
#include "../mxmldir/config.h"
#include "Derivedtype.h"
#include <stdio.h>
#include <string.h>

//function to save a graph in XML format on disk
void saveGraph(GraphType* g, char* fileloc, char* filename);

//function to read a graph in XML format and convert it to GraphType
GraphType* readGraph(char* fileLoc, char* filename);


#endif