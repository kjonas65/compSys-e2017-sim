/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     REGISTER = 258,
     MNM_HLT = 259,
     MNM_NOP = 260,
     MNM_MOVQ = 261,
     MNM_ADDQ = 262,
     MNM_SUBQ = 263,
     MNM_ANDQ = 264,
     MNM_XORQ = 265,
     MNM_CMPQ = 266,
     MNM_JMP = 267,
     MNM_JLE = 268,
     MNM_JL = 269,
     MNM_JE = 270,
     MNM_JNE = 271,
     MNM_JGE = 272,
     MNM_JG = 273,
     MNM_CMOVLE = 274,
     MNM_CMOVL = 275,
     MNM_CMOVE = 276,
     MNM_CMOVNE = 277,
     MNM_CMOVGE = 278,
     MNM_CMOVG = 279,
     MNM_CALL = 280,
     MNM_RET = 281,
     MNM_PUSHQ = 282,
     MNM_POPQ = 283,
     ALIGN = 284,
     POSITION = 285,
     QUAD = 286,
     RANDOM = 287,
     NEWLINE = 288,
     PERIOD = 289,
     COMMA = 290,
     COLON = 291,
     SEMICOLON = 292,
     LPAREN = 293,
     RPAREN = 294,
     DOLLAR = 295,
     INT_LITERAL = 296,
     IDENTIFIER = 297,
     DIRECTIVE = 298,
     DATA = 299,
     STRING_LITERAL = 300,
     UNKNOWN_REGISTER = 301,
     UNKNOWN_DIRECTIVE = 302,
     UNKNOWN_TOKEN = 303
   };
#endif
/* Tokens.  */
#define REGISTER 258
#define MNM_HLT 259
#define MNM_NOP 260
#define MNM_MOVQ 261
#define MNM_ADDQ 262
#define MNM_SUBQ 263
#define MNM_ANDQ 264
#define MNM_XORQ 265
#define MNM_CMPQ 266
#define MNM_JMP 267
#define MNM_JLE 268
#define MNM_JL 269
#define MNM_JE 270
#define MNM_JNE 271
#define MNM_JGE 272
#define MNM_JG 273
#define MNM_CMOVLE 274
#define MNM_CMOVL 275
#define MNM_CMOVE 276
#define MNM_CMOVNE 277
#define MNM_CMOVGE 278
#define MNM_CMOVG 279
#define MNM_CALL 280
#define MNM_RET 281
#define MNM_PUSHQ 282
#define MNM_POPQ 283
#define ALIGN 284
#define POSITION 285
#define QUAD 286
#define RANDOM 287
#define NEWLINE 288
#define PERIOD 289
#define COMMA 290
#define COLON 291
#define SEMICOLON 292
#define LPAREN 293
#define RPAREN 294
#define DOLLAR 295
#define INT_LITERAL 296
#define IDENTIFIER 297
#define DIRECTIVE 298
#define DATA 299
#define STRING_LITERAL 300
#define UNKNOWN_REGISTER 301
#define UNKNOWN_DIRECTIVE 302
#define UNKNOWN_TOKEN 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "asm_parser.y"
{
    unsigned char reg_val;
    isa_Long int_val;
    char str_val [256];
}
/* Line 1529 of yacc.c.  */
#line 151 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;
