%{
    #include <stdio.h>
%}

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

RESERVED        ("--"|"++"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"null"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile")



LETTER          [a-z]|[A-Z]
NUMBER          [1-9]
NUMBER0         [0-9]


    // TODO pode comecar com os simbolos?
    // TODO numeros tambem contam?
ID              ({LETTER}|"_"|"$")+


    // 0
    // 12304
    // a = 1_123_123
INTLIT          0|{NUMBER}{NUMBER0}*|({NUMBER}+_{NUMBER}+)+


    // 0.(123)
    // 1.(e123)
    // .123(e-1)
    // 123e2

REALLIT         (({INTLIT}"."{INTLIT}?|"."({INTLIT}))([eE][-+]?{INTLIT})?)|({INTLIT}([eE][-+]?{INTLIT}))


    // "\"

%%

{ID}            {printf("ID(%s)\n", yytext);}
{INTLIT}        {printf("INTLIT(%s)\n", yytext);}
{REALLIT}       {printf("REALLIT(%s)\n", yytext);}



.               {printf("illegal character (%c)\n", *yytext);}


%%
int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}

    // STRLIT
    // comment
    // prints about tokens
    // errors
