%{
    #include <stdio.h>
%}

 //INTLIT
 //REALLIT
 //STRLIT


boollit         "true"|"false"
and             "&&"
assign          "="
star            "*"
comma           ","
div             "/"
eq              "=="
ge              ">="
gt              ">"
lbrace          "{"
le              "<="
lpar            "("
lsq             "["
lt              "<"
minus           "-"
mod             "%"
ne              "!="
not             "!"
or              "||"
plus            "+"
rbrace          "}"
rpar            ")"
rsq             "]"
semicolon       ";"
arrow           "->"
lshift          "<<"
rshift          ">>"
xor             "^"
bool            "boolean"
class           "class"
dotlength       ".length"
double          "double"
else            "else"
if              "if"
int             "int"
print           "System.out.print"
parseint        "Interger.parseInt"
public          "public"
return          "return"
static          "static"
string          "String"
void            "void"
while           "while"

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


%X STRING




%%

{boollit}                              {printf("BOOLLIT\n");}
{and}                                  {printf("AND\n");}
{assign}                               {printf("ASSIGN\n");}
{star}                                 {printf("STAR\n");}
{comma}                                {printf("COMMA\n");}
{div}                                  {printf("DIV\n");}
{eq}                                   {printf("EQ\n");}
{ge}                                   {printf("GE\n");}
{gt}                                   {printf("GT\n");}
{lbrace}                               {printf("LBRACE\n");}
{le}                                   {printf("LE\n");}
{lpar}                                 {printf("LPAR\n");}
{lsq}                                  {printf("LSQ\n");}
{lt}                                   {printf("LT\n");}
{minus}                                {printf("MINUS\n");}
{mod}                                  {printf("MOD\n");}
{ne}                                   {printf("NE\n");}
{not}                                  {printf("NOT\n");}
{or}                                   {printf("OR\n");}
{plus}                                 {printf("PLUS\n");}
{rbrace}                               {printf("RBRACE\n");}
{rpar}                                 {printf("RPAR\n");}
{rsq}                                  {printf("RSQ\n");}
{semicolon}                            {printf("SEMICOLON\n");}
{arrow}                                {printf("ARROW\n");}
{lshift}                               {printf("LSHIFT\n");}
{rshift}                               {printf("RSHIFT\n");}
{xor}                                  {printf("XOR\n");}
{bool}                                 {printf("BOOL\n");}
{class}                                {printf("CLASS\n");}
{dotlength}                            {printf("DOTLENGTH\n");}
{double}                               {printf("DOUBLE\n");}
{else}                                 {printf("ELSE\n");}
{if}                                   {printf("IF\n");}
{int}                                  {printf("INT\n");}
{print}                                {printf("PRINT\n");}
{parseint}                             {printf("PARSEINT\n");}
{public}                               {printf("PUBLIC\n");}
{return}                               {printf("RETURN\n");}
{static}                               {printf("STATIC\n");}
{string}                               {printf("STRING\n");}
{void}                                 {printf("VOID\n");}
{while}                                {printf("WHILE\n");}


{ID}            {printf("ID(%s)\n", yytext);}
{INTLIT}        {printf("INTLIT(%s)\n", yytext);}
{REALLIT}       {printf("REALLIT(%s)\n", yytext);}


"\""               {BEGIN STRING;}
<STRING>.*"\""       {printf("STRLIT: \"%s\n", yytext); BEGIN 0;}
<STRING>(\r|\n|"\"".)  {printf("Error (%s)\n", yytext); BEGIN 0;}

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
