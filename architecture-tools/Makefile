CC = gcc
CFLAGS = -Wall -Wextra -O1 -std=c11 -pedantic -g
LEX = lex
YACC = yacc

all: sim asm

parser: y.tab.o lex.yy.o

y.tab.c: asm_parser.y
	$(YACC) -d asm_parser.y

lex.yy.c: asm_lexer.l asm_parser.y
	$(LEX) asm_lexer.l

lex.yy.o: lex.yy.c
	$(CC) -w -O3 -c lex.yy.c

y.tab.o: y.tab.c
	$(CC) -w -O3 -c y.tab.c

asm: y.tab.o lex.yy.o isa_* asm_*
	$(CC) $(CFLAGS) lex.yy.o y.tab.o asm*.c -o asm

sim: sim_* isa_*
	$(CC) $(CFLAGS) sim*.c -o sim

clean:
	rm -f *.o asm sim
