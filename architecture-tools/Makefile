CC = gcc
CFLAGS = -Wall -Wextra -O1 -std=c11 -pedantic -g
LCFLAGS = -O1
LEX = lex
YACC = yacc -d

all: sim asm

lex.yy.c: asm_lexer.l
	$(LEX) asm_lexer.l

y.tab.c: asm_parser.y
	$(YACC) asm_parser.y

asm: lex.yy.c y.tab.c isa_* asm_*
	$(CC) $(CFLAGS) lex.yy.c y.tab.c asm*.c -o asm

sim: sim_* isa_* ano_*
	$(CC) $(CFLAGS) ano*.c sim*.c -o sim

clean:
	rm -f *.o lex.yy.c y.tab.h y.tab.c asm sim
