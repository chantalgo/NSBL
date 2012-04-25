#include <string.h>
#include <stdlib.h>
#include "NSBLio.h"

//function to print string
void print_STRING_T(GString* s)
{
	printf("%s",s->str);
}

//function to print float
void print_FLOAT_T(float val)
{
	printf("%f",val);
}

//function to print integer
void print_INT_T(int val)
{
	printf("%d",val);
}

void print(){}

//function to break line(newline)
void print_NEWLINE()
{
	printf("\n");
}

