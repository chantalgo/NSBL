CC = gcc
LEX = flex
YACC = yacc

CFLAGS = -Wall
XFLAGS = -7 -D_MYECHO
YFLAGS = --warnings=all

toy.exe : Parser.tab.c Parser.tab.h LexAly.yy.c
	$(CC) $(CFLAGS) -o toy.exe Parser.tab.c Parser.tab.h LexAly.yy.c -lfl -ly
	mv toy.exe ../
Parser.tab.c : Parser.y
	$(YACC) $(YFLAGS) -d Parser.y
	mv y.tab.c Parser.tab.c
Parser.tab.h : Parser.tab.c
	mv y.tab.h Parser.tab.h
LexAly.yy.c : LexAly.l
	$(LEX) $(XFLAGS) LexAly.l
	mv lex.yy.c LexAly.yy.c

clean :
	rm -f Parser.tab.c Parser.tab.h LexAly.yy.c toy.exe y.output
