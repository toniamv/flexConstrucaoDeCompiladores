%option noyywrap
%option nodefault
%option outfile="lexer.c" header-file="lexer.h"



%{
    #include "exp.h"
    #include <string.h>
    #include <stdlib.h>
    #define YY_DECL Token *yylex(void)
%}

NUM [0-9]
NUMS {NUM}+
ABREC \/\*
FECHAC \*\/
LETRA [A-Za-z]
LETRAS {LETRA}+


%%


[[:space:]\n\t] { }
{ABREC}([^*]|\*+[^/])*{FECHAC} { }
{NUMS}\.{NUMS}(E[\+\-]?{NUMS})? {return token(TOK_NUMF, yytext); }
{NUM}+ {return token(NUM_INT, yytext); }
\<\= { return token(RELOP, "<="); }
\< { return token(RELOP, "<"); }
\>\= { return token(RELOP, ">="); }
\> { return token(RELOP, ">"); }
\=\= { return token(RELOP, "=="); }
\!\= { return token(RELOP, "!="); }
\:\= { return token(ATRIB, ":="); }
if { return token(IF, "none"); }
then { return token(THEN, "none"); }
else { return token(ELSE, "none"); }
while { return token(WHILE, "none"); }
repeat { return token(REPEAT, "none"); }
until { return token(UNTIL, "none"); }
[{LETRAS}_][{LETRA}{NUM}_]* { return token(ID, yytext); }
. { return token(ERRO, yytext); }
<<EOF>> {return token(TOK_EOF, "none")}


%%

// variavel global para um token
Token tok;

Token *token(int tipo, const char *valor) {
    tok.tipo = tipo;
    strncpy(tok.atributo, valor, LEXMAX-1);
    tok.atributo[LEXMAX-1] = '\0'; //fecha string atributo
    return &tok;
}
