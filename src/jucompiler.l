
%{
    #define print(...) printf(__VA_ARGS__);printf("\n")
    
%}


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
parseint        "Integer.parseInt"
public          "public"
return          "return"
static          "static"
string          "String"
void            "void"
while           "while"

reserved        ("Integer"|"System"|"--"|"++"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"null"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile")



LETTER          [a-z]|[A-Z]
NUMBER          [1-9]
NUMBER0         [0-9]

ID              ({LETTER}|"_"|"$")({LETTER}|{NUMBER0}|"_"|"$")*
INTLIT          0|{NUMBER}({NUMBER0}|"_"+{NUMBER0})*
REALLIT         (({INTLIT}"."{INTLIT}?|"."({INTLIT}))([eE][-+]?{INTLIT})?)|({INTLIT}([eE][-+]?{INTLIT}))



%%

{and}                                  {print("AND");}
{assign}                               {print("ASSIGN");}
{star}                                 {print("STAR");}
{comma}                                {print("COMMA");}
{div}                                  {print("DIV");}
{eq}                                   {print("EQ");}
{ge}                                   {print("GE");}
{gt}                                   {print("GT");}
{lbrace}                               {print("LBRACE");}
{le}                                   {print("LE");}
{lpar}                                 {print("LPAR");}
{lsq}                                  {print("LSQ");}
{lt}                                   {print("LT");}
{minus}                                {print("MINUS");}
{mod}                                  {print("MOD");}
{ne}                                   {print("NE");}
{not}                                  {print("NOT");}
{or}                                   {print("OR");}
{plus}                                 {print("PLUS");}
{rbrace}                               {print("RBRACE");}
{rpar}                                 {print("RPAR");}
{rsq}                                  {print("RSQ");}
{semicolon}                            {print("SEMICOLON");}
{arrow}                                {print("ARROW");}
{lshift}                               {print("LSHIFT");}
{rshift}                               {print("RSHIFT");}
{xor}                                  {print("XOR");}
{bool}                                 {print("BOOL");}
{class}                                {print("CLASS");}
{dotlength}                            {print("DOTLENGTH");}
{double}                               {print("DOUBLE");}
{else}                                 {print("ELSE");}
{if}                                   {print("IF");}
{int}                                  {print("INT");}
{print}                                {print("PRINT");}
{parseint}                             {print("PARSEINT");}
{public}                               {print("PUBLIC");}
{return}                               {print("RETURN");}
{static}                               {print("STATIC");}
{string}                               {print("STRING");}
{void}                                 {print("VOID");}
{while}                                {print("WHILE");}
{reserved}                             {print("RESERVED(%s)", yytext);}
{boollit}                              {print("BOOLLIT(%s)", yytext);}


{ID}                                   {print("ID(%s)", yytext);}
{INTLIT}                               {print("INTLIT(%s)", yytext);}
{REALLIT}                              {print("REALLIT(%s)", yytext);}


[\n]                                   {;}
.                                      {print("illegal character (%c)", *yytext);}



%%
int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
