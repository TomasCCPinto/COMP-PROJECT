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
%union {
    token_t token;
    ast_node_t *node;
}


%token  <token>  INTLIT STRLIT REALLIT ID
%token  <token>  IF ELSE WHILE RETURN  
%token  <token>  BOOL CLASS DOUBLE INT PUBLIC STATIC STRING VOID
%token  <token>  EQ GE GT LT LE NE
%token  <token>  DOTLENGTH PRINT PARSEINT
%token  <token>  BOOLLIT AND NOT OR XOR
%token  <token>  MOD DIV STAR MINUS PLUS
%token  <token>  QUOTE ASSIGN COMMA LBRACE LPAR LSQ RBRACE RPAR RSQ SEMICOLON
%token  <token>  ARROW LSHIFT RSHIFT

%type  <node>  StartSymbol Program 
%type  <node>  MethodDecl MethodInvocation FieldDecl MethodHeader MethodBody
%type  <node>  Type Expr VarDecl
%type  <node>  Assignment Statement ParseArgs

%type  <node>  Program2
%type  <node>  FieldDecl2


   
%% 

StartSymbol: Program


Program: CLASS ID LBRACE Program2 RBRACE

Program2: Program2 MethodDecl
        | Program2 FieldDecl
        | Program2 SEMICOLON
        | /*empty*/
        ;


MethodDecl: PUBLIC STATIC MethodHeader MethodBody


FieldDecl: PUBLIC STATIC Type ID FieldDecl2 SEMICOLON

FieldDecl2: FieldDecl2 COMMA ID
          | /*empty*/
          ;


Type: BOOL
    | INT
    | DOUBLE
    ;


MethodHeader: ( Type | VOID ) ID LPAR [ FormalParams ] RPAR

Formalparams: Type ID MethodHeader2
            | STRING LSQ RSQ ID
            ;

MethodHeader2: COMMA
             | Type
             | ID
             | 
             ;

MethodBody: LBRACE { Statement | VarDecl } RBRACE


VarDecl: Type ID { COMMA ID } SEMICOLON


Statement: LBRACE { Statement } RBRACE
         | IF LPAR Expr RPAR Statement [ ELSE Statement ]
         | WHILE LPAR Expr RPAR Statement
         | RETURN [ Expr ] SEMICOLON
         | [ ( MethodInvocation | Assignment | ParseArgs ) ] SEMICOLON
         | PRINT LPAR ( Expr | STRLIT ) RPAR SEMICOLON
         ;

Statement2:    

MethodInvocation: ID LPAR [ Expr { COMMA Expr } ] RPAR


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
    