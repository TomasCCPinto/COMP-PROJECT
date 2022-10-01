%{
    #include <stdio.h>


%}

 //ID
 //INTLIT
 //REALLIT
 //STRLIT

BOOLLIT         "true"|"false"
AND             "&&"
ASSIGN          "="
STAR            "*"
COMMA           ","
DIV             "/"
EQ              "=="
GE              ">="
GT              ">"
LBRACE          "{"
LE              "<="
LPAR            "("
LSQ             "["
LT              "<"
MINUS           "-"
MOD             "%"
NE              "!="
NOT             "!"
OR              "||"
PLUS            "+"
RBRACE          "}"
RPAR            ")"
RSQ             "]"
SEMICOLON       ";"
ARROW           "->"
LSHIFT          "<<"
RSHIFT          ">>"
XOR             "^"


BOOL            "boolean"
CLASS           "class"
DOTLENGTH       ".length"
DOUBLE          "double"
ELSE            "else"
IF              "if"
INT             "int"
PRINT           "System.out.print"
PARSEINT        "Interger.parseInt"
PUBLIC          "public"
RETURN          "return"
STATIC          "static"
STRING          "String"
VOID            "void"
WHILE           "while"

 //RESERVED


%%


%%
int main()
{
yylex();
return 0;
}

int yywrap()
{
return 1;
}

