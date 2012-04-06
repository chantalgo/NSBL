BINDIR = ../bin
TESTDIR = ../devtest

CFLAGS = -D_DEBUG 
##### CFLAGS Options ############
# -D_AST_DEBUG
# -D_AST_DEBUG_ALL
# -D_NO_LOG
# -D_DEBUG
#################################  
XFLAGS = -7 
##### XFLAGS Options ############
# -7			: 7bit ASCII
# -D_MYECHO 	: for LEX DEBUG 
#################################  
YFLAGS =

GLIBINCLUDE = -I/usr/include/glib-2.0/ -I/usr/lib64/glib-2.0/include
GLIBLINK = `pkg-config --cflags --libs glib-2.0`

CC = gcc $(CFLAGS) $(GLIBINCLUDE) 
LEX = flex
YACC = yacc

OBJ = Parser.tab.o LexAly.yy.o ASTree.o SymbolTable.o SymbolTableUtil.o util.o Error.o

toy.exe : $(OBJ)
	$(CC) -o toy.exe $(OBJ) -lfl -ly $(GLIBLINK)
	mkdir -p $(BINDIR)
	mv toy.exe $(BINDIR)

Parser.tab.o: Parser.tab.c Parser.tab.h
	$(CC) -c Parser.tab.c
LexAly.yy.o: LexAly.yy.c Parser.tab.h
	$(CC) -c LexAly.yy.c

Parser.tab.c : Parser.y
	$(YACC) $(YFLAGS) -d Parser.y
	mv y.tab.c Parser.tab.c
Parser.tab.h : Parser.tab.c
	mv y.tab.h Parser.tab.h
LexAly.yy.c : LexAly.l
	$(LEX) $(XFLAGS) LexAly.l
	mv lex.yy.c LexAly.yy.c
ASTree.o : ASTree.c ASTree.h Parser.tab.h
	$(CC) -c ASTree.c
SymbolTable.o: SymbolTable.h SymbolTable.c
	$(CC) -c SymbolTable.c
SymbolTableUtil.o: SymbolTableUtil.c
	$(CC) -c SymbolTableUtil.c
util.o:	util.h util.c
	$(CC) -c util.c
Error.o: Error.c
	$(CC) -c Error.c

test : toy.exe
	$(BINDIR)/toy.exe $(TESTDIR)/syntax-test.nsbl 


testsm : SymbolTable.o testST.c
	$(CC) -c testST.c
	$(CC) -o $(BINDIR)/testsm.exe SymbolTable.o testST.o $(GLIBLINK)

clean :
	rm -f Parser.tab.c Parser.tab.h LexAly.yy.c y.output $(BINDIR)/toy.exe *.o
	rm -f SymbolTable.o testST.o $(BINDIR)/testsm.exe
