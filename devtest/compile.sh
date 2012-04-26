#!/bin/bash
../bin/toy.exe dynFuncLiteral.nsbl
gcc -c dynFuncLiteral.nsbl.c -I../src -I/usr/include/glib-2.0/ -I/usr/lib64/glib-2.0/include -I/usr/lib/glib-2.0/include
gcc -g -o a.out dynFuncLiteral.nsbl.o ../src/Derivedtype.o ../src/FileReadWrite.o ../src/NSBLio.o ../mxmldir/libmxml.a -lpthread `pkg-config --cflags --libs glib-2.0`
