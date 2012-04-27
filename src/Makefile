BINDIR = ../bin
TESTDIR = ../devtest
MXMLDIR = ../mxmldir
LIBDIR = ../lib
INCLUDEDIR = ../include

CFLAGS = -D_NO_LOG 
##### CFLAGS Options ############
# -D_AST_DEBUG
# -D_AST_DEBUG_ALL
# -D_NO_LOG
# -D_DEBUG
#################################
XFLAGS = -7
##### XFLAGS Options ############
# -7 : 7bit ASCII
# -D_MYECHO : for LEX DEBUG
#################################
YFLAGS =
##### CFLAGS Options ############
# -D_DEBUG
#################################

GLIBLINK = `pkg-config --cflags --libs glib-2.0`
YACCLIB = -ly -lfl
MXMLIB = $(MXMLDIR)/libmxml.a -lpthread

CC = gcc -g $(CFLAGS) $(GLIBLINK)
LEX = flex
YACC = yacc
AR = ar

OBJ = Parser.tab.o LexAly.yy.o ASTree.o SymbolTable.o SymbolTableUtil.o util.o Error.o CodeGen.o CodeGenUtil.o

all : n2c.exe runlibs includes nsbl

n2c.exe : $(OBJ)
	$(CC) -o n2c.exe $(OBJ) $(YACCLIB)
	mkdir -p $(BINDIR)
	mv n2c.exe $(BINDIR)
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
util.o: util.h util.c
	$(CC) -c util.c
Error.o: Error.c
	$(CC) -c Error.c
CodeGen.o: CodeGen.h CodeGen.c
	$(CC) -c CodeGen.c
CodeGenUtil.o: CodeGenUtil.c CodeGenUtil.h
	$(CC) -c CodeGenUtil.c
Derivedtype.o : Derivedtype.h Derivedtype.c
	$(CC) -c Derivedtype.c
NSBLio.o: NSBLio.c
	$(CC) -c NSBLio.c
FileReadWrite.o: FileReadWrite.h FileReadWrite.c libmxml.a 
	$(CC) -c FileReadWrite.c 
libmxml.a : 
	cd $(MXMLDIR); ./configure; make libmxml.a; cd -
	cp $(MXMLDIR)/libmxml.a .
runlibs: NSBLio.o Derivedtype.o FileReadWrite.o
	rm -f libnsblgraph.a
	$(AR) -cvq libnsblgraph.a NSBLio.o Derivedtype.o FileReadWrite.o libmxml.a
	mkdir -p $(LIBDIR)
	cp libnsblgraph.a $(LIBDIR)
nsbl : genScript.sh
	sh ./genScript.sh
	chmod +x ./nsbl
	cp nsbl $(BINDIR)

includes : NSBLio.h Derivedtype.h FileReadWrite.h type.h operator.h
	mkdir -p $(INCLUDEDIR)
	cp NSBLio.h Derivedtype.h FileReadWrite.h type.h operator.h $(INCLUDEDIR)

testglib : Derivedtype.o graph_lib_test.c
	$(CC) -c graph_lib_test.c
	$(CC) -o $(BINDIR)/graph_lib_test.exe Derivedtype.o graph_lib_test.o $(GLIBLINK)

clean-mxml :
	cd $(MXMLDIR) ; make distclean; cd -
	rm -f libmxml.a

clean :	clean-mxml
	rm -f Parser.tab.c Parser.tab.h LexAly.yy.c y.output *.o
	rm -f Derivedtype.o graph_lib_test.o $(BINDIR)/graph_lib_test.exe
	rm -f libnsblgraph.a

clean-include :
	rm -f $(INCLUDEDIR)/*

distclean : clean clean-include
	rm -f $(BINDIR)/n2c.exe $(BINDIR)/nsbl nsbl
	rm -f $(LIBDIR)/libnsblgraph.a
	rm -f -r $(BINDIR) $(LIBDIR) $(INCLUDEDIR)
