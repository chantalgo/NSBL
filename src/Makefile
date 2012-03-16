CC = gcc
LEX = flex
YACC = yacc

BINDIR = ../bin
TESTDIR = ../devtest

CFLAGS = -Wall
XFLAGS = -7 -D_MYECHO
YFLAGS =

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

clean :
	rm -f Parser.tab.c Parser.tab.h LexAly.yy.c y.output $(BINDIR)/toy.exe
