CC = gcc
LEX = flex
YACC = yacc

BINDIR = ../bin
TESTDIR = ../devtest

CFLAGS = -Wall
XFLAGS = -7 -D_MYECHO
YFLAGS =

GLIBINCLUDE = -I/usr/include/glib-2.0/ -I/usr/lib64/glib-2.0/include
GLIBLINK = `pkg-config --cflags --libs glib-2.0`

toy.exe : Parser.tab.c Parser.tab.h LexAly.yy.c
	$(CC) $(CFLAGS) -o toy.exe Parser.tab.c Parser.tab.h LexAly.yy.c -lfl -ly
	mkdir -p $(BINDIR)
	mv toy.exe $(BINDIR)
Parser.tab.c : Parser.y
	$(YACC) $(YFLAGS) -d Parser.y
	mv y.tab.c Parser.tab.c
Parser.tab.h : Parser.tab.c
	mv y.tab.h Parser.tab.h
LexAly.yy.c : LexAly.l
	$(LEX) $(XFLAGS) LexAly.l
	mv lex.yy.c LexAly.yy.c

test : toy.exe
	$(BINDIR)/toy.exe $(TESTDIR)/syntax-test.nsbl 


testsm : SymbolTable.h SymbolTable.c testST.c
	$(CC) -c $(GLIBINCLUDE) SymbolTable.c
	$(CC) -c $(GLIBINCLUDE) testST.c
	$(CC) -o $(BINDIR)/testsm.exe SymbolTable.o testST.o $(GLIBLINK)

clean :
	rm -f Parser.tab.c Parser.tab.h LexAly.yy.c y.output $(BINDIR)/toy.exe
	rm -f SymbolTable.o testST.o $(BINDIR)/testsm.exe
