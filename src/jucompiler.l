
%{
    #define PRINT(...) printf(__VA_ARGS__);printf("\n")
    
    int col=1, line=1,linecom=0, colcom;
    int savecol, saveline;
%}


%X COMMENT STR


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
quote           \"
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
comment         "//".*
begin_comment   "/*"
end_comment     "*/"


ID              ({LETTER}|"_"|"$")({LETTER}|{NUMBER0}|"_"|"$")*
INTLIT          0|{NUMBER}({NUMBER0}|"_"+{NUMBER0})*
INTLIT0         {NUMBER0}({NUMBER0}|"_"+{NUMBER0})*
REALLIT         (({INTLIT}"."{INTLIT0}?|"."({INTLIT0}))([eE][-+]?{INTLIT0})?)|({INTLIT0}([eE][-+]?{INTLIT0}))
STRLIT          ([^\n\r\"]|"\\n"|"\\f"|"\\r"|"\\t"|"\\\\"|"\\\"")


%%

{and}                                  {PRINT("AND");                    col+=yyleng;}
{assign}                               {PRINT("ASSIGN");                 col+=yyleng;}
{star}                                 {PRINT("STAR");                   col+=yyleng;}
{comma}                                {PRINT("COMMA");                  col+=yyleng;}
{div}                                  {PRINT("DIV");                    col+=yyleng;}
{eq}                                   {PRINT("EQ");                     col+=yyleng;}
{ge}                                   {PRINT("GE");                     col+=yyleng;}
{gt}                                   {PRINT("GT");                     col+=yyleng;}
{lbrace}                               {PRINT("LBRACE");                 col+=yyleng;}
{le}                                   {PRINT("LE");                     col+=yyleng;}
{lpar}                                 {PRINT("LPAR");                   col+=yyleng;}
{lsq}                                  {PRINT("LSQ");                    col+=yyleng;}
{lt}                                   {PRINT("LT");                     col+=yyleng;}
{minus}                                {PRINT("MINUS");                  col+=yyleng;}
{mod}                                  {PRINT("MOD");                    col+=yyleng;}
{ne}                                   {PRINT("NE");                     col+=yyleng;}
{not}                                  {PRINT("NOT");                    col+=yyleng;}
{or}                                   {PRINT("OR");                     col+=yyleng;}
{plus}                                 {PRINT("PLUS");                   col+=yyleng;}
{rbrace}                               {PRINT("RBRACE");                 col+=yyleng;}
{rpar}                                 {PRINT("RPAR");                   col+=yyleng;}
{rsq}                                  {PRINT("RSQ");                    col+=yyleng;}
{semicolon}                            {PRINT("SEMICOLON");              col+=yyleng;}
{arrow}                                {PRINT("ARROW");                  col+=yyleng;}
{lshift}                               {PRINT("LSHIFT");                 col+=yyleng;}
{rshift}                               {PRINT("RSHIFT");                 col+=yyleng;}
{xor}                                  {PRINT("XOR");                    col+=yyleng;}
{bool}                                 {PRINT("BOOL");                   col+=yyleng;}
{class}                                {PRINT("CLASS");                  col+=yyleng;}
{dotlength}                            {PRINT("DOTLENGTH");              col+=yyleng;}
{double}                               {PRINT("DOUBLE");                 col+=yyleng;}
{else}                                 {PRINT("ELSE");                   col+=yyleng;}
{if}                                   {PRINT("IF");                     col+=yyleng;}
{int}                                  {PRINT("INT");                    col+=yyleng;}
{print}                                {PRINT("PRINT");                  col+=yyleng;}
{parseint}                             {PRINT("PARSEINT");               col+=yyleng;}
{public}                               {PRINT("PUBLIC");                 col+=yyleng;}
{return}                               {PRINT("RETURN");                 col+=yyleng;}
{static}                               {PRINT("STATIC");                 col+=yyleng;}
{string}                               {PRINT("STRING");                 col+=yyleng;}
{void}                                 {PRINT("VOID");                   col+=yyleng;}
{while}                                {PRINT("WHILE");                  col+=yyleng;}
{reserved}                             {PRINT("RESERVED(%s)", yytext);   col+=yyleng;}
{boollit}                              {PRINT("BOOLLIT(%s)", yytext);    col+=yyleng;}


{ID}                                   {PRINT("ID(%s)", yytext);         col+=yyleng;}
{INTLIT}                               {PRINT("INTLIT(%s)", yytext);     col+=yyleng;}
{REALLIT}                              {PRINT("REALLIT(%s)", yytext);    col+=yyleng;}


{comment}                               {;}

{begin_comment}                         {colcom = col; col+= yyleng; BEGIN COMMENT;}
<COMMENT>{END_LINE}                     {col=1;linecom++;}
<COMMENT>.                              {col+= yyleng;}
<COMMENT>{end_comment}                  {col+= yyleng;line+=linecom; linecom = 0;BEGIN 0;}
<COMMENT><<EOF>>                        {PRINT("Line %d, col %d: unterminated comment", line, colcom); BEGIN 0;}


{quote}                                 {savecol = col; saveline = line; col+= yyleng; BEGIN STR;}
<STR>{STRLIT}+{quote}                    {col+= yyleng; PRINT("STRLIT(\"%s)", yytext); BEGIN 0;}
<STR>.                                  {;}
<STR>{END_LINE}                         {PRINT("Line %d, col %d: unterminated string literal", saveline, savecol); line++; col = 1; BEGIN 0;}


{END_LINE}                             {line++; col=1;}
[ \t]+                                 {col+= yyleng;}
.                                      {PRINT("Line %d, col %d: illegal character (%c)", line, col, *yytext); col+=yyleng;}

%%
int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}




//  "nfkaewfh"
//  "afpo"odijw" -> "afpo"   odijw   "
//                  str       id      erro
//