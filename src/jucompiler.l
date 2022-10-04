
%{
    #define PRINT(...) printf(__VA_ARGS__);printf("\n")
    
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
END_LINE        (\n|\r\n|\r)

ID              ({LETTER}|"_"|"$")({LETTER}|{NUMBER0}|"_"|"$")*
INTLIT          0|{NUMBER}({NUMBER0}|"_"+{NUMBER0})*
INTLIT0         {NUMBER0}({NUMBER0}|"_"+{NUMBER0})*
REALLIT         (({INTLIT}"."{INTLIT0}?|"."({INTLIT0}))([eE][-+]?{INTLIT0})?)|({INTLIT0}([eE][-+]?{INTLIT0}))



%%

{and}                                  {PRINT("AND");}
{assign}                               {PRINT("ASSIGN");}
{star}                                 {PRINT("STAR");}
{comma}                                {PRINT("COMMA");}
{div}                                  {PRINT("DIV");}
{eq}                                   {PRINT("EQ");}
{ge}                                   {PRINT("GE");}
{gt}                                   {PRINT("GT");}
{lbrace}                               {PRINT("LBRACE");}
{le}                                   {PRINT("LE");}
{lpar}                                 {PRINT("LPAR");}
{lsq}                                  {PRINT("LSQ");}
{lt}                                   {PRINT("LT");}
{minus}                                {PRINT("MINUS");}
{mod}                                  {PRINT("MOD");}
{ne}                                   {PRINT("NE");}
{not}                                  {PRINT("NOT");}
{or}                                   {PRINT("OR");}
{plus}                                 {PRINT("PLUS");}
{rbrace}                               {PRINT("RBRACE");}
{rpar}                                 {PRINT("RPAR");}
{rsq}                                  {PRINT("RSQ");}
{semicolon}                            {PRINT("SEMICOLON");}
{arrow}                                {PRINT("ARROW");}
{lshift}                               {PRINT("LSHIFT");}
{rshift}                               {PRINT("RSHIFT");}
{xor}                                  {PRINT("XOR");}
{bool}                                 {PRINT("BOOL");}
{class}                                {PRINT("CLASS");}
{dotlength}                            {PRINT("DOTLENGTH");}
{double}                               {PRINT("DOUBLE");}
{else}                                 {PRINT("ELSE");}
{if}                                   {PRINT("IF");}
{int}                                  {PRINT("INT");}
{print}                                {PRINT("PRINT");}
{parseint}                             {PRINT("PARSEINT");}
{public}                               {PRINT("PUBLIC");}
{return}                               {PRINT("RETURN");}
{static}                               {PRINT("STATIC");}
{string}                               {PRINT("STRING");}
{void}                                 {PRINT("VOID");}
{while}                                {PRINT("WHILE");}
{reserved}                             {PRINT("RESERVED(%s)", yytext);}
{boollit}                              {PRINT("BOOLLIT(%s)", yytext);}


{ID}                                   {PRINT("ID(%s)", yytext);}
{INTLIT}                               {PRINT("INTLIT(%s)", yytext);}
{REALLIT}                              {PRINT("REALLIT(%s)", yytext);}


{END_LINE}                                   {;}
[ \t]                                  {;}
.                                       {;}


%%
int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
