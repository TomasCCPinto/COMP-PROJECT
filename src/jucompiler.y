%{

    // Joao Emanuel Sousa Moreira 2020230563
    // Tomas Cerveira da Cruz Pinto 2020224069

    // C Standard library Includes
    
  // Yacc and other Includes...
  #include "ast.h"
 
  // Functions
  extern int yylex();
  extern void yyerror(const char *str);
  extern char *yytext;
  // extern int yylineno;
  extern int num_line;
  extern int num_col;

  ast_node_t *my_program;
  ast_node_t *aux;
  ast_node_t *aux2;
  ast_node_t *aux3;

  // Compiler Flags TODO
  int a = 0;
  bool l = false, e1 = false, e2 = true, t = false; 

%}

// Token types


%union {
    token_t token;
    ast_node_t *node;
}


%token <token> INTLIT STRLIT REALLIT ID
%token <token> IF ELSE WHILE RETURN  
%token <token> BOOL CLASS DOUBLE INT PUBLIC STATIC STRING VOID
%token <token> EQ GE GT LT LE NE
%token <token> DOTLENGTH PRINT PARSEINT
%token <token> BOOLLIT AND NOT OR XOR
%token <token> MOD DIV STAR MINUS PLUS
%token <token> ASSIGN COMMA LBRACE LPAR LSQ RBRACE RPAR RSQ SEMICOLON
%token <token> LSHIFT RSHIFT
%token <token> ARROW QUOTE RESERVED 


%type <node> Program Program2
%type <node> MethodDecl MethodInvocation MethodInvocation2 FieldDecl FieldDecl2 MethodHeader MethodBody MethodBody2
%type <node> Type Expr VarDecl VarDecl2 Expr1
%type <node> Assignment Statement ParseArgs Statement2
%type <node> FormalParams FormalParams2 Main 


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


%nonassoc NO_ELSE
%nonassoc ELSE 

   
%% 
Main: Program                                                                   { $$ = my_program = ast_node("Program", NULL); add_children($$, $1); }

Program: CLASS ID LBRACE Program2 RBRACE                                        { $$ = ast_node("Id", $2); add_brother($$, $4); }

Program2: MethodDecl Program2                                                   { $$ = $1; add_brother($$, $2); }
        | FieldDecl  Program2                                                   { $$ = $1; 
                                                                                    if ($1) {
                                                                                        aux3 = $1;
                                                                                        while(aux3->brother) {
                                                                                            aux3 = aux3->brother;
                                                                                        }
                                                                                        add_brother(aux3, $2);
                                                                                    } else {
                                                                                        add_brother($$, $2);
                                                                                    }
                                                                                }
        | SEMICOLON  Program2                                                   { $$ = $2; }
        |  /*empty*/                                                            { $$ = NULL; }
        ;


MethodDecl: PUBLIC STATIC MethodHeader MethodBody                               { $$ = ast_node("MethodDecl", NULL); add_children($$, $3); add_brother($3, $4); }


FieldDecl: PUBLIC STATIC Type ID FieldDecl2 SEMICOLON                           { $$ = ast_node("FieldDecl", NULL); add_children($$, $3); add_type($3, $5); 
                                                                                 aux = ast_node("Id", $4); add_brother($3, aux);  
                                                                                    add_brother($$, $5);
                                                                                } 
         | error SEMICOLON                                                      { $$ = NULL; }

FieldDecl2: COMMA ID FieldDecl2                                                 { $$ = ast_node("FieldDecl", NULL); aux = ast_node("Id", $2); add_children($$, aux); add_brother($$, $3); }
          |                                                                     { $$ = NULL; }
          ;


Type: BOOL                                                                      { $$ = ast_node("Bool", NULL); }
    | INT                                                                       { $$ = ast_node("Int", NULL); }
    | DOUBLE                                                                    { $$ = ast_node("Double", NULL); }
    ;


MethodHeader: Type ID LPAR FormalParams RPAR                                    { $$ = ast_node("MethodHeader", NULL); add_children($$, $1); aux = ast_node("Id", $2); add_brother($1, aux); add_brother(aux, $4); }
            | Type ID LPAR RPAR                                                 { $$ = ast_node("MethodHeader", NULL); add_children($$, $1); aux = ast_node("Id", $2); add_brother($1, aux); add_brother(aux, ast_node("MethodParams", NULL)); }
            | VOID ID LPAR FormalParams RPAR                                    { $$ = ast_node("MethodHeader", NULL); aux = ast_node("Void", NULL); add_children($$, aux);  
                                                                                aux2 = ast_node("Id", $2); add_brother(aux, aux2); add_brother(aux2, $4); }
            | VOID ID LPAR RPAR                                                 { $$ = ast_node("MethodHeader", NULL); aux = ast_node("Void", NULL); add_children($$, aux); aux2 = ast_node("Id", $2); add_brother(aux, aux2); add_brother(aux2, ast_node("MethodParams", NULL)); }

FormalParams: Type ID FormalParams2                                             { $$ = ast_node("MethodParams", NULL); add_children($$, $3); add_children($3, $1); aux = ast_node("Id", $2); add_brother($1, aux); }
            | STRING LSQ RSQ ID                                                 { $$ = ast_node("MethodParams", NULL); aux2 = ast_node("ParamDecl", NULL); add_children($$, aux2);
                                                                                 aux = ast_node("StringArray", NULL); add_children(aux2, aux);
                                                                                  add_brother(aux, ast_node("Id", $4));
                                                                                  }
            ;

FormalParams2: COMMA Type ID FormalParams2                                      { $$ = ast_node("ParamDecl", NULL); add_brother($$, $4); add_children($4, $2); aux = ast_node("Id", $3); add_brother($2, aux); }
             |                                                                  { $$ = ast_node("ParamDecl", NULL); }
             ;/*nada testado*/


MethodBody: LBRACE MethodBody2 RBRACE                                           { $$ = ast_node("MethodBody", NULL); if($2) {add_children($$, $2); }}

MethodBody2:  Statement MethodBody2                                             { $$ = $1; add_brother($$, $2); }
           |  VarDecl   MethodBody2                                             { $$ = $1; 
                                                                                    aux = $1;
                                                                                    while(aux->brother) {
                                                                                        aux = aux->brother;
                                                                                    }
                                                                                add_brother(aux, $2);}
           |                                                                    { $$ = NULL;}
           ;



VarDecl: Type ID VarDecl2 SEMICOLON                                             { $$ = ast_node("VarDecl", NULL); add_children($$, $1); add_type($1, $3); aux = ast_node("Id", $2); add_brother($1, aux); add_brother($$, $3);}

VarDecl2: COMMA ID VarDecl2                                                     { $$ = ast_node("VarDecl", NULL); aux = ast_node("Id", $2); add_children($$, aux); add_brother($$, $3); }
        |                                                                       { $$ = NULL; }
        ; 


Statement: LBRACE Statement2 RBRACE                                             { $$ = statement_list($2); print_ast($$); }
         | IF LPAR Expr RPAR Statement ELSE Statement                           { $$ = ast_node("If", NULL); add_children($$, $3); add_brother($3, $5);
                                                                                    if($5) {
                                                                                        aux2 = statement_list($5); add_brother($3, aux2); aux = ast_node("Block", NULL); add_brother(aux2, aux); add_children(aux, $7);
                                                                                    } else {
                                                                                        aux = ast_node("Block", NULL); add_brother($3, aux); aux2 = ast_node("Block", NULL); add_brother(aux, aux2); add_children(aux2, $7); 
                                                                                    }
                                                                                }
         | IF LPAR Expr RPAR Statement %prec NO_ELSE                            { $$ = ast_node("If", NULL); add_children($$, $3); add_brother($3, $5); 
                                                                                    if($5) {
                                                                                        aux2 = statement_list($5); add_brother($3, aux2); aux = ast_node("Block", NULL); add_brother(aux2, aux); 
                                                                                    } else {
                                                                                        aux = ast_node("Block", NULL); add_brother($3, aux); add_brother(aux, ast_node("Block", NULL));
                                                                                    }
                                                                                }
         | WHILE LPAR Expr RPAR Statement                                       { $$ = ast_node("While", NULL); add_children($$, $3); add_children($3, $5); }
         | RETURN Expr SEMICOLON                                                { $$ = ast_node("Return", NULL); add_children($$, $2); }
         | RETURN SEMICOLON                                                     { $$ = ast_node("Return", NULL); }
         | MethodInvocation SEMICOLON                                           { $$ = $1; }
         | Assignment SEMICOLON                                                 { $$ = $1; }
         | ParseArgs SEMICOLON                                                  { $$ = $1; }
         | error SEMICOLON                                                      { $$ = NULL; }
         | SEMICOLON                                                            { $$ = NULL; }
         | PRINT LPAR Expr RPAR SEMICOLON                                       { $$ = ast_node("Print", NULL); add_children($$, $3);  }
         | PRINT LPAR STRLIT RPAR SEMICOLON                                     { $$ = ast_node("Print", NULL); add_children($$, ast_node("StrLit", $3));  }
         ;

Statement2: Statement Statement2                                                { $$ = $1; add_brother($$, $2); }
          | { $$ = NULL;}

MethodInvocation: ID LPAR RPAR                                                  {  $$ = ast_node("Call", NULL); aux = ast_node("Id", $1); add_children($$, aux);  }
                | ID LPAR error RPAR                                            {  $$ = NULL; free($1);}
                | ID LPAR Expr MethodInvocation2 RPAR                           {  $$ = ast_node("Call", NULL); aux = ast_node("Id", $1); add_children($$, aux); add_brother(aux, $3); add_brother($3, $4);  }
                ;

MethodInvocation2: COMMA Expr MethodInvocation2                                 { $$ = $2; add_brother($$, $3); }
                 | error                                                        { $$ = NULL;}
                 |                                                              { $$ = NULL; }
                 ;


Assignment: ID ASSIGN Expr                                                      { $$ = ast_node("Assign", NULL); aux = ast_node("Id", $1); add_children($$, aux); add_brother(aux, $3); /*addicionar expr*/ }


ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                                   { $$ = ast_node("ParseArgs", NULL); aux = ast_node("Id", $3); add_children($$, aux); add_brother(aux, $5); }
         | PARSEINT LPAR error RPAR   {$$= NULL;}


Expr: Assignment   { $$ = $1; }
     | Expr1       { $$ = $1; }
     ;

Expr1: Expr1 PLUS   Expr1                                                            { $$ = ast_node("Add", NULL); add_children($$, $1); add_brother($1, $3);; }
    | Expr1 MINUS  Expr1                                                           { $$ = ast_node("Sub", NULL); add_children($$, $1); add_brother($1, $3);; }
    | Expr1 STAR   Expr1                                                            { $$ = ast_node("Mul", NULL); add_children($$, $1); add_brother($1, $3);; }
    | Expr1 DIV    Expr1                                                             { $$ = ast_node("Div", NULL); add_children($$, $1); add_brother($1, $3);; }
    | Expr1 MOD    Expr1                                                             { $$ = ast_node("Mod", NULL); add_children($$, $1); add_brother($1, $3);; }
    | Expr1 AND    Expr1                                                             { $$ = ast_node("And", NULL); add_children($$, $1); add_brother($1, $3);; }
    | Expr1 OR     Expr1                                                              { $$ = ast_node("Or", NULL); add_children($$, $1); add_brother($1, $3);; }
    | Expr1 XOR    Expr1                                                             { $$ = ast_node("Xor", NULL); add_children($$, $1); add_brother($1, $3);; }
    | Expr1 LSHIFT Expr1                                                          { $$ = ast_node("Lshift", NULL); add_children($$, $1); add_brother($1, $3);; }
    | Expr1 RSHIFT Expr1                                                          { $$ = ast_node("Rshift", NULL); add_children($$, $1); add_brother($1, $3);; }
    | Expr1 EQ     Expr1                                                              { $$ = ast_node("Eq", NULL); add_children($$, $1); add_brother($1, $3); }
    | Expr1 GE     Expr1                                                              { $$ = ast_node("Ge", NULL); add_children($$, $1); add_brother($1, $3); }
    | Expr1 GT     Expr1                                                              { $$ = ast_node("Gt", NULL); add_children($$, $1); add_brother($1, $3); }
    | Expr1 LE     Expr1                                                              { $$ = ast_node("Le", NULL); add_children($$, $1); add_brother($1, $3); }
    | Expr1 LT     Expr1                                                              { $$ = ast_node("Lt", NULL); add_children($$, $1); add_brother($1, $3); }
    | Expr1 NE     Expr1                                                              { $$ = ast_node("NE", NULL); add_children($$, $1); add_brother($1, $3); }
    | MINUS       Expr1                                                                     { $$ = ast_node("Minus", NULL); add_children($$, $2); }
    | NOT         Expr1                                                                  { $$ = ast_node("Not", NULL); add_children($$, $2); }
    | PLUS        Expr1                                                                 { $$ = ast_node("Plus", NULL); add_children($$, $2); }
    | LPAR        Expr1 RPAR                                                            { $$ = $2; }
    | LPAR error RPAR                                                           { $$ = NULL; }
    | MethodInvocation                                                          { $$ = $1; }
    | ParseArgs                                                                 { $$ = $1; }
    | ID DOTLENGTH                                                              { $$ = ast_node("Id", $1); }
    | ID                                                                        { $$ = ast_node("Id", $1); }
    | INTLIT                                                                    { $$ = ast_node("DecLit", $1); }
    | REALLIT                                                                   { $$ = ast_node("RealLit", $1); }
    | BOOLLIT                                                                   { $$ = ast_node("BoolLit", $1); }
    ;    
%%


void flags(int argc, char *argv[]) {
}


int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; ++i) {
      if (!strcmp(argv[i], "-l")) {
           e1 = t = e2 = false;
           l = true;  
      } else if (!strcmp(argv[i], "-e1")){
          t = l = e2 = false;
          e1 = true;
      } else if (!strcmp(argv[i], "-e2")) {
          e1 = t = l = false;
          e2 = true;
      } else if (!strcmp(argv[i], "-t")) {
          l = e2 = e1 = false;
          t = true; 
      }
  }

  if (l || e1) {
      return yylex();
  } 
 
  if (e2) {
      yyparse(); 
  } else if (t) {
      yyparse();
      print_ast(my_program);  
  }

  free_ast(my_program);
  return 0;
}


