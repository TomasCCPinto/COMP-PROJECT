
    // Joao Emanuel Sousa Moreira 2020230563
    // Tomas Cerveira da Cruz Pinto 2020224069
%{

    // Yacc includes
    #include "ast.h"
    #include "y.tab.h"
    

    #define TOKEN(flag, ...) if (flag) printf(__VA_ARGS__); if (flag) printf("\n")
    #define ERROR(...) printf(__VA_ARGS__);printf("\n")

    int col=1, line=1;
    int savecol, saveline;
    extern bool l;

    #define findAsciiChars(character, line, col) { if (character <= 126 && character >= 33) printf("Line %d, col %d: illegal character (%c)\n", line, col, character); }
    #define SEND_TOKEN(...) {  yylval.token = token(yytext, line, col - yyleng, __VA_ARGS__); /*printf("%d - %d - %s\n", yylval.token.line, yylval.token.col, yylval.token.value);*/ return __VA_ARGS__; }
    
    extern bool syntax_error; 

%}


%X COMMENT STR INVALID_STR COM


boollit                                                    "true"|"false"
and                                                        "&&"
assign                                                     "="
star                                                       "*"
comma                                                      ","
div                                                        "/"
eq                                                         "=="
ge                                                         ">="
gt                                                         ">"
lbrace                                                     "{"
le                                                         "<="
lpar                                                       "("
lsq                                                        "["
lt                                                         "<"
minus                                                      "-"
mod                                                        "%"
ne                                                         "!="
not                                                        "!"
or                                                         "||"
plus                                                       "+"
rbrace                                                     "}"
rpar                                                       ")"
rsq                                                        "]"
semicolon                                                  ";"
arrow                                                      "->"
lshift                                                     "<<"
rshift                                                     ">>"
xor                                                        "^"
quote                                                      \"
bool                                                       "boolean"
class                                                      "class"
dotlength                                                  ".length"
double                                                     "double"
else                                                       "else"
if                                                         "if"
int                                                        "int"
print                                                      "System.out.print"
parseint                                                   "Integer.parseInt"
public                                                     "public"
return                                                     "return"
static                                                     "static"
string                                                     "String"
void                                                       "void"
while                                                      "while"

reserved                                                   ("Integer"|"System"|"--"|"++"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"do"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"null"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile")



letter                                                     [a-z]|[A-Z]
number                                                     [1-9]
number0                                                    [0-9]
end_line                                                   (\n|\r\n|\r)
comment                                                    "//"
begin_comment                                              "/*"
end_comment                                                "*/"


id                                                         ({letter}|"_"|"$")({letter}|{number0}|"_"|"$")*
intlit                                                     0|{number}({number0}|"_"+{number0})*
intlit0                                                    {number0}({number0}|"_"+{number0})*
reallit                                                    (({intlit0}"."{intlit0}?|"."({intlit0}))([Ee][-+]?{intlit0})?)|({intlit0}([Ee][-+]?{intlit0}))
strlit                                                     ([^\n\r\"\\]|"\\n"|"\\f"|"\\r"|"\\t"|"\\\\"|"\\\"")


%%

{and}                                                      { TOKEN(l, "AND");                    col+=yyleng; SEND_TOKEN(AND      ); }
{assign}                                                   { TOKEN(l, "ASSIGN");                 col+=yyleng; SEND_TOKEN(ASSIGN   ); }
{star}                                                     { TOKEN(l, "STAR");                   col+=yyleng; SEND_TOKEN(STAR     ); }
{comma}                                                    { TOKEN(l, "COMMA");                  col+=yyleng; SEND_TOKEN(COMMA    ); }
{div}                                                      { TOKEN(l, "DIV");                    col+=yyleng; SEND_TOKEN(DIV      ); }
{eq}                                                       { TOKEN(l, "EQ");                     col+=yyleng; SEND_TOKEN(EQ       ); }
{ge}                                                       { TOKEN(l, "GE");                     col+=yyleng; SEND_TOKEN(GE       ); }
{gt}                                                       { TOKEN(l, "GT");                     col+=yyleng; SEND_TOKEN(GT       ); }
{lbrace}                                                   { TOKEN(l, "LBRACE");                 col+=yyleng; SEND_TOKEN(LBRACE   ); }
{le}                                                       { TOKEN(l, "LE");                     col+=yyleng; SEND_TOKEN(LE       ); }
{lpar}                                                     { TOKEN(l, "LPAR");                   col+=yyleng; SEND_TOKEN(LPAR     ); }
{lsq}                                                      { TOKEN(l, "LSQ");                    col+=yyleng; SEND_TOKEN(LSQ      ); }
{lt}                                                       { TOKEN(l, "LT");                     col+=yyleng; SEND_TOKEN(LT       ); }
{minus}                                                    { TOKEN(l, "MINUS");                  col+=yyleng; SEND_TOKEN(MINUS    ); }
{mod}                                                      { TOKEN(l, "MOD");                    col+=yyleng; SEND_TOKEN(MOD      ); }
{ne}                                                       { TOKEN(l, "NE");                     col+=yyleng; SEND_TOKEN(NE       ); }
{not}                                                      { TOKEN(l, "NOT");                    col+=yyleng; SEND_TOKEN(NOT      ); }
{or}                                                       { TOKEN(l, "OR");                     col+=yyleng; SEND_TOKEN(OR       ); }
{plus}                                                     { TOKEN(l, "PLUS");                   col+=yyleng; SEND_TOKEN(PLUS     ); }
{rbrace}                                                   { TOKEN(l, "RBRACE");                 col+=yyleng; SEND_TOKEN(RBRACE   ); }
{rpar}                                                     { TOKEN(l, "RPAR");                   col+=yyleng; SEND_TOKEN(RPAR     ); }
{rsq}                                                      { TOKEN(l, "RSQ");                    col+=yyleng; SEND_TOKEN(RSQ      ); }
{semicolon}                                                { TOKEN(l, "SEMICOLON");              col+=yyleng; SEND_TOKEN(SEMICOLON); }
{arrow}                                                    { TOKEN(l, "ARROW");                  col+=yyleng; SEND_TOKEN(ARROW    ); }
{lshift}                                                   { TOKEN(l, "LSHIFT");                 col+=yyleng; SEND_TOKEN(LSHIFT   ); }
{rshift}                                                   { TOKEN(l, "RSHIFT");                 col+=yyleng; SEND_TOKEN(RSHIFT   ); }
{xor}                                                      { TOKEN(l, "XOR");                    col+=yyleng; SEND_TOKEN(XOR      ); }
{bool}                                                     { TOKEN(l, "BOOL");                   col+=yyleng; SEND_TOKEN(BOOL     ); }
{class}                                                    { TOKEN(l, "CLASS");                  col+=yyleng; SEND_TOKEN(CLASS    ); }
{dotlength}                                                { TOKEN(l, "DOTLENGTH");              col+=yyleng; SEND_TOKEN(DOTLENGTH); }
{double}                                                   { TOKEN(l, "DOUBLE");                 col+=yyleng; SEND_TOKEN(DOUBLE   ); }
{else}                                                     { TOKEN(l, "ELSE");                   col+=yyleng; SEND_TOKEN(ELSE     ); }
{if}                                                       { TOKEN(l, "IF");                     col+=yyleng; SEND_TOKEN(IF       ); }
{int}                                                      { TOKEN(l, "INT");                    col+=yyleng; SEND_TOKEN(INT      ); }
{print}                                                    { TOKEN(l, "PRINT");                  col+=yyleng; SEND_TOKEN(PRINT    ); }
{parseint}                                                 { TOKEN(l, "PARSEINT");               col+=yyleng; SEND_TOKEN(PARSEINT ); }
{public}                                                   { TOKEN(l, "PUBLIC");                 col+=yyleng; SEND_TOKEN(PUBLIC   ); }
{return}                                                   { TOKEN(l, "RETURN");                 col+=yyleng; SEND_TOKEN(RETURN   ); }
{static}                                                   { TOKEN(l, "STATIC");                 col+=yyleng; SEND_TOKEN(STATIC   ); }
{string}                                                   { TOKEN(l, "STRING");                 col+=yyleng; SEND_TOKEN(STRING   ); }
{void}                                                     { TOKEN(l, "VOID");                   col+=yyleng; SEND_TOKEN(VOID     ); }
{while}                                                    { TOKEN(l, "WHILE");                  col+=yyleng; SEND_TOKEN(WHILE    ); }
{reserved}                                                 { TOKEN(l, "RESERVED(%s)", yytext);   col+=yyleng; SEND_TOKEN(RESERVED ); }
{boollit}                                                  { TOKEN(l, "BOOLLIT(%s)", yytext);    col+=yyleng; SEND_TOKEN(BOOLLIT  ); }
                                                                                                                         
                                                                                                                         
{id}                                                       { TOKEN(l, "ID(%s)", yytext);         col+=yyleng; SEND_TOKEN(ID       ); }
{intlit}                                                   { TOKEN(l, "INTLIT(%s)", yytext);     col+=yyleng; SEND_TOKEN(INTLIT   ); }
{reallit}                                                  { TOKEN(l, "REALLIT(%s)", yytext);    col+=yyleng; SEND_TOKEN(REALLIT  ); }



{comment}                                                  { BEGIN COM; }
<COM>{end_line}                                            { BEGIN 0; line++; col = 1; }
<COM><<EOF>>                                               { BEGIN 0; }
<COM>.                                                     { ; }

{begin_comment}                                            { savecol = col; saveline = line; col+= yyleng; BEGIN COMMENT; }
<COMMENT>{end_line}                                        { col = 1; line++; }
<COMMENT>.                                                 { col += yyleng; }
<COMMENT>{end_comment}                                     { col += yyleng; BEGIN 0; }
<COMMENT><<EOF>>                                           { ERROR("Line %d, col %d: unterminated comment", saveline, savecol); BEGIN 0; }


{quote}                                                    { savecol = col; saveline = line; col+= yyleng; BEGIN STR; }
<STR>{strlit}*{quote}                                      { TOKEN(l, "STRLIT(\"%s)", yytext); col += yyleng; BEGIN 0; SEND_TOKEN(STRLIT); }
<STR>"\\n"|"\\f"|"\\r"|"\\t"|"\\\\"|"\\\""                 { col += yyleng; }
<STR>"\\"|("\\"[^\n\r])                                    { ERROR("Line %d, col %d: invalid escape sequence (%s)", line, col, yytext); col += yyleng; BEGIN INVALID_STR; }
<STR><<EOF>>                                               { ERROR("Line %d, col %d: unterminated string literal", saveline, savecol); line++; col = 1; BEGIN 0; }
<STR>{end_line}                                            { ERROR("Line %d, col %d: unterminated string literal", saveline, savecol); line++; col = 1; BEGIN 0; }
<STR>.                                                     { col += yyleng; }

<INVALID_STR>{quote}                                       { BEGIN 0; col+= yyleng; }
<INVALID_STR>"\\n"|"\\f"|"\\r"|"\\t"|"\\\\"|"\\\""         { col += yyleng; }
<INVALID_STR>"\\"|("\\"[^\n\r])                            { ERROR("Line %d, col %d: invalid escape sequence (%s)", line, col, yytext);col += yyleng; }
<INVALID_STR>.                                             { col += yyleng; }
<INVALID_STR>{end_line}                                    { ERROR("Line %d, col %d: unterminated string literal", saveline, savecol); line++; col = 1; BEGIN 0; }
<INVALID_STR><<EOF>>                                       { ERROR("Line %d, col %d: unterminated string literal", saveline, savecol); line++; col = 1; BEGIN 0; }



{end_line}                                                 { line++; col=1; }
[ \t]                                                      { col+= 1; }
.                                                          { findAsciiChars(*yytext, line, col) col+=yyleng; }
<<EOF>>                                                    { return 0; }


%%

int yywrap() {
    return 1;
}


extern void yyerror (const char *s ) {
    if (!yytext[0]) {
        printf ("Line %d, col %d: %s: %s\n", line, col, s , yytext);
    } else if (yytext[yyleng-1] == '"') {
        printf ("Line %d, col %d: %s: \"%s\n", line, col - yyleng-1, s , yytext );
    } else {
        printf ("Line %d, col %d: %s: %s\n", line, col - yyleng, s , yytext );
    }
    syntax_error = true;
}
