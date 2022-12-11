/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTLIT = 258,                  /* INTLIT  */
    STRLIT = 259,                  /* STRLIT  */
    REALLIT = 260,                 /* REALLIT  */
    ID = 261,                      /* ID  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    WHILE = 264,                   /* WHILE  */
    RETURN = 265,                  /* RETURN  */
    BOOL = 266,                    /* BOOL  */
    CLASS = 267,                   /* CLASS  */
    DOUBLE = 268,                  /* DOUBLE  */
    INT = 269,                     /* INT  */
    PUBLIC = 270,                  /* PUBLIC  */
    STATIC = 271,                  /* STATIC  */
    STRING = 272,                  /* STRING  */
    VOID = 273,                    /* VOID  */
    EQ = 274,                      /* EQ  */
    GE = 275,                      /* GE  */
    GT = 276,                      /* GT  */
    LT = 277,                      /* LT  */
    LE = 278,                      /* LE  */
    NE = 279,                      /* NE  */
    DOTLENGTH = 280,               /* DOTLENGTH  */
    PRINT = 281,                   /* PRINT  */
    PARSEINT = 282,                /* PARSEINT  */
    BOOLLIT = 283,                 /* BOOLLIT  */
    AND = 284,                     /* AND  */
    NOT = 285,                     /* NOT  */
    OR = 286,                      /* OR  */
    XOR = 287,                     /* XOR  */
    MOD = 288,                     /* MOD  */
    DIV = 289,                     /* DIV  */
    STAR = 290,                    /* STAR  */
    MINUS = 291,                   /* MINUS  */
    PLUS = 292,                    /* PLUS  */
    ASSIGN = 293,                  /* ASSIGN  */
    COMMA = 294,                   /* COMMA  */
    LBRACE = 295,                  /* LBRACE  */
    LPAR = 296,                    /* LPAR  */
    LSQ = 297,                     /* LSQ  */
    RBRACE = 298,                  /* RBRACE  */
    RPAR = 299,                    /* RPAR  */
    RSQ = 300,                     /* RSQ  */
    SEMICOLON = 301,               /* SEMICOLON  */
    LSHIFT = 302,                  /* LSHIFT  */
    RSHIFT = 303,                  /* RSHIFT  */
    ARROW = 304,                   /* ARROW  */
    QUOTE = 305,                   /* QUOTE  */
    RESERVED = 306,                /* RESERVED  */
    NO_ELSE = 307                  /* NO_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INTLIT 258
#define STRLIT 259
#define REALLIT 260
#define ID 261
#define IF 262
#define ELSE 263
#define WHILE 264
#define RETURN 265
#define BOOL 266
#define CLASS 267
#define DOUBLE 268
#define INT 269
#define PUBLIC 270
#define STATIC 271
#define STRING 272
#define VOID 273
#define EQ 274
#define GE 275
#define GT 276
#define LT 277
#define LE 278
#define NE 279
#define DOTLENGTH 280
#define PRINT 281
#define PARSEINT 282
#define BOOLLIT 283
#define AND 284
#define NOT 285
#define OR 286
#define XOR 287
#define MOD 288
#define DIV 289
#define STAR 290
#define MINUS 291
#define PLUS 292
#define ASSIGN 293
#define COMMA 294
#define LBRACE 295
#define LPAR 296
#define LSQ 297
#define RBRACE 298
#define RPAR 299
#define RSQ 300
#define SEMICOLON 301
#define LSHIFT 302
#define RSHIFT 303
#define ARROW 304
#define QUOTE 305
#define RESERVED 306
#define NO_ELSE 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "src/jucompiler.y"

    token_t token;
    ast_node_t *node;

#line 176 "src/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
