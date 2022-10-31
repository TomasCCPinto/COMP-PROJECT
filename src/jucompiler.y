%{


// C Standard library Includes
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   #include <stdbool.h>
   
   // Yacc and other Includes...
   #include "ast.h"
 
   // Functions
   extern int yylex();
   extern void yyerror(char *str);

   // Compiler Flags TODO
    

    // o que sao os formalparams????
%}

// Token types


%token  INTLIT STRLIT REALLIT ID
%token  IF ELSE WHILE RETURN  
%token  BOOL CLASS DOUBLE INT PUBLIC STATIC STRING VOID
%token  EQ GE GT LT LE NE
%token  DOTLENGTH PRINT PARSEINT
%token  BOOLLIT AND NOT OR XOR
%token  MOD DIV STAR MINUS PLUS
%token  ASSIGN COMMA LBRACE LPAR LSQ RBRACE RPAR RSQ SEMICOLON
%token  LSHIFT RSHIFT
//ARROw QUOTE


%type  Program Program2
%type  MethodDecl MethodInvocation MethodInvocation2 FieldDecl FieldDecl2 MethodHeader MethodBody MethodBody2
%type  Type Expr VarDecl VarDecl2
%type  Assignment Statement ParseArgs
%type  FormalParams FormalParams2 


%right ASSIGN
%left  OR
%left  AND
%left  XOR
%left  EQ NE
%left  LT GT LE GE
%left  LSHIFT RSHIFT 
%left  PLUS MINUS
%left  STAR DIV MOD
%right  NOT
%left  LPAR RPAR 


%nonassoc ELSE

   
%% 

Program: CLASS ID LBRACE Program2 RBRACE

Program2: Program2 MethodDecl
        | Program2 FieldDecl
        | Program2 SEMICOLON
        | 
        ;


MethodDecl: PUBLIC STATIC MethodHeader MethodBody


FieldDecl: PUBLIC STATIC Type ID FieldDecl2 SEMICOLON

FieldDecl2: FieldDecl2 COMMA ID
          | 
          ;


Type: BOOL
    | INT
    | DOUBLE
    ;


MethodHeader: Type ID LPAR FormalParams RPAR
            | Type ID LPAR RPAR
            | VOID ID LPAR FormalParams RPAR
            | VOID ID LPAR RPAR

FormalParams: Type ID FormalParams2
            | STRING LSQ RSQ ID
            ;

FormalParams2: COMMA Type ID FormalParams2 
             | 
             ;


MethodBody: LBRACE MethodBody2 RBRACE

MethodBody2: MethodBody2 Statement 
           | MethodBody2 VarDecl
           | 
           ;


VarDecl: Type ID VarDecl2 SEMICOLON

VarDecl2: VarDecl2 COMMA ID
        | 
        ;

Statement: LBRACE Statement RBRACE
         | IF LPAR Expr RPAR Statement ELSE Statement 
         | IF LPAR Expr RPAR Statement
         | WHILE LPAR Expr RPAR Statement
         | RETURN Expr  SEMICOLON
         | RETURN SEMICOLON
         | MethodInvocation SEMICOLON
         | Assignment SEMICOLON
         | ParseArgs SEMICOLON
         | SEMICOLON
         | PRINT LPAR Expr RPAR SEMICOLON
         | PRINT LPAR STRLIT RPAR SEMICOLON
         ;



MethodInvocation: ID LPAR RPAR
                | ID LPAR Expr MethodInvocation2 RPAR
                ;
            
MethodInvocation2: MethodInvocation2 COMMA Expr
                 |
                 ;


Assignment: ID ASSIGN Expr


ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR


Expr: Expr PLUS Expr
    | Expr MINUS Expr
    | Expr STAR Expr
    | Expr DIV Expr
    | Expr MOD Expr
    | Expr AND Expr
    | Expr OR Expr
    | Expr XOR Expr
    | Expr LSHIFT Expr
    | Expr RSHIFT Expr
    | Expr EQ Expr
    | Expr GE Expr
    | Expr GT Expr
    | Expr LE Expr
    | Expr LT Expr
    | Expr NE Expr
    | MINUS Expr
    | NOT Expr
    | PLUS Expr
    | LPAR Expr RPAR
    | MethodInvocation 
    | Assignment 
    | ParseArgs
    | ID DOTLENGTH
    | ID
    | INTLIT
    | REALLIT
    | BOOLLIT
    ;
    
%%


int main() {
  yyparse();
  return 0;
}

void yyerror (const char *s) {
  printf("Sintax Error\n");
}
