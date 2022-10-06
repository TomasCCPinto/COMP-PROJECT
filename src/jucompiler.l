
%{
    #include <string.h>
    #include <stdbool.h>

    #define TOKEN(flag, ...) if (flag) printf(__VA_ARGS__); if (flag) printf("\n")
    #define ERROR(...) printf(__VA_ARGS__);printf("\n")
    
    int col=1, line=1,linecom=0, colcom;
    int savecol, saveline;
    bool l;
%}


%X COMMENT STR


boollit                                 "true"|"false"
and                                     "&&"
assign                                  "="
star                                    "*"
comma                                   ","
div                                     "/"
eq                                      "=="
ge                                      ">="
gt                                      ">"
lbrace                                  "{"
le                                      "<="
lpar                                    "("
lsq                                     "["
lt                                      "<"
minus                                   "-"
mod                                     "%"
ne                                      "!="
not                                     "!"
or                                      "||"
plus                                    "+"
rbrace                                  "}"
rpar                                    ")"
rsq                                     "]"
semicolon                               ";"
arrow                                   "->"
lshift                                  "<<"
rshift                                  ">>"
xor                                     "^"
quote                                   \"
bool                                    "boolean"
class                                   "class"
dotlength                               ".length"
double                                  "double"
else                                    "else"
if                                      "if"
int                                     "int"
print                                   "System.out.print"
parseint                                "Integer.parseInt"
public                                  "public"
return                                  "return"
static                                  "static"
string                                  "String"
void                                    "void"
while                                   "while"

reserved                                ("Integer"|"System"|"--"|"++"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"null"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile")



LETTER                                  [a-z]|[A-Z]
NUMBER                                  [1-9]
NUMBER0                                 [0-9]
END_LINE                                (\n|\r\n|\r)
comment                                 "//".*
begin_comment                           "/*"
end_comment                             "*/"


ID                                      ({LETTER}|"_"|"$")({LETTER}|{NUMBER0}|"_"|"$")*
INTLIT                                  0|{NUMBER}({NUMBER0}|"_"+{NUMBER0})*
INTLIT0                                 {NUMBER0}({NUMBER0}|"_"+{NUMBER0})*
REALLIT                                 (({INTLIT0}"."{INTLIT0}?|"."({INTLIT0}))([eE][-+]?{INTLIT0})?)|({INTLIT0}([eE][-+]?{INTLIT0}))
STRLIT                                  ([^\n\r\"\\.?]|"\\n"|"\\f"|"\\r"|"\\t"|"\\\\"|"\\\"")


%%

{and}                                   {TOKEN(l, "AND");                    col+=yyleng;}
{assign}                                {TOKEN(l, "ASSIGN");                 col+=yyleng;}
{star}                                  {TOKEN(l, "STAR");                   col+=yyleng;}
{comma}                                 {TOKEN(l, "COMMA");                  col+=yyleng;}
{div}                                   {TOKEN(l, "DIV");                    col+=yyleng;}
{eq}                                    {TOKEN(l, "EQ");                     col+=yyleng;}
{ge}                                    {TOKEN(l, "GE");                     col+=yyleng;}
{gt}                                    {TOKEN(l, "GT");                     col+=yyleng;}
{lbrace}                                {TOKEN(l, "LBRACE");                 col+=yyleng;}
{le}                                    {TOKEN(l, "LE");                     col+=yyleng;}
{lpar}                                  {TOKEN(l, "LPAR");                   col+=yyleng;}
{lsq}                                   {TOKEN(l, "LSQ");                    col+=yyleng;}
{lt}                                    {TOKEN(l, "LT");                     col+=yyleng;}
{minus}                                 {TOKEN(l, "MINUS");                  col+=yyleng;}
{mod}                                   {TOKEN(l, "MOD");                    col+=yyleng;}
{ne}                                    {TOKEN(l, "NE");                     col+=yyleng;}
{not}                                   {TOKEN(l, "NOT");                    col+=yyleng;}
{or}                                    {TOKEN(l, "OR");                     col+=yyleng;}
{plus}                                  {TOKEN(l, "PLUS");                   col+=yyleng;}
{rbrace}                                {TOKEN(l, "RBRACE");                 col+=yyleng;}
{rpar}                                  {TOKEN(l, "RPAR");                   col+=yyleng;}
{rsq}                                   {TOKEN(l, "RSQ");                    col+=yyleng;}
{semicolon}                             {TOKEN(l, "SEMICOLON");              col+=yyleng;}
{arrow}                                 {TOKEN(l, "ARROW");                  col+=yyleng;}
{lshift}                                {TOKEN(l, "LSHIFT");                 col+=yyleng;}
{rshift}                                {TOKEN(l, "RSHIFT");                 col+=yyleng;}
{xor}                                   {TOKEN(l, "XOR");                    col+=yyleng;}
{bool}                                  {TOKEN(l, "BOOL");                   col+=yyleng;}
{class}                                 {TOKEN(l, "CLASS");                  col+=yyleng;}
{dotlength}                             {TOKEN(l, "DOTLENGTH");              col+=yyleng;}
{double}                                {TOKEN(l, "DOUBLE");                 col+=yyleng;}
{else}                                  {TOKEN(l, "ELSE");                   col+=yyleng;}
{if}                                    {TOKEN(l, "IF");                     col+=yyleng;}
{int}                                   {TOKEN(l, "INT");                    col+=yyleng;}
{print}                                 {TOKEN(l, "PRINT");                  col+=yyleng;}
{parseint}                              {TOKEN(l, "PARSEINT");               col+=yyleng;}
{public}                                {TOKEN(l, "PUBLIC");                 col+=yyleng;}
{return}                                {TOKEN(l, "RETURN");                 col+=yyleng;}
{static}                                {TOKEN(l, "STATIC");                 col+=yyleng;}
{string}                                {TOKEN(l, "STRING");                 col+=yyleng;}
{void}                                  {TOKEN(l, "VOID");                   col+=yyleng;}
{while}                                 {TOKEN(l, "WHILE");                  col+=yyleng;}
{reserved}                              {TOKEN(l, "RESERVED(%s)", yytext);   col+=yyleng;}
{boollit}                               {TOKEN(l, "BOOLLIT(%s)", yytext);    col+=yyleng;}


{ID}                                    {TOKEN(l, "ID(%s)", yytext);         col+=yyleng;}
{INTLIT}                                {TOKEN(l, "INTLIT(%s)", yytext);     col+=yyleng;}
{REALLIT}                               {TOKEN(l, "REALLIT(%s)", yytext);    col+=yyleng;}


{comment}                               {;}

{begin_comment}                         {colcom = col; col+= yyleng; BEGIN COMMENT;}
<COMMENT>{END_LINE}                     {col=1;linecom++;}
<COMMENT>.                              {col+= yyleng;}
<COMMENT>{end_comment}                  {col+= yyleng;line+=linecom; linecom = 0;BEGIN 0;}
<COMMENT><<EOF>>                        {ERROR("Line %d, col %d: unterminated comment", line, colcom); BEGIN 0;}


{quote}                                 {savecol = col; saveline = line; col+= yyleng; BEGIN STR;}
<STR>{STRLIT}*{quote}                   {TOKEN(l, "STRLIT(\"%s)", yytext); col += yyleng; BEGIN 0;}
<STR>"\\"[^\n\f\r\t]?                   {ERROR("Line %d, col %d: invalid escape sequence (%s)", line, col, yytext);col += yyleng;}
<STR>.                                  {col += yyleng;}
<STR>{END_LINE}                         {ERROR("Line %d, col %d: unterminated string literal", saveline, savecol); line++; col = 1; BEGIN 0;}


{END_LINE}                              {line++; col=1;}
[ \t]                                   {col+= 1;}
.                                       {ERROR("Line %d, col %d: illegal character (%c)", line, col, *yytext); col+=yyleng;}


%%
int main(int argc, char *argv[]) {

    for (int i = 0; i < argc; ++i) {
        if (!strcmp(argv[i], "-l"))
            l = true;
        else l = false;
    }

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