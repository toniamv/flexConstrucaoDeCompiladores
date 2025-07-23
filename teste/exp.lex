%option noyywrap
%option nodefault
%option outfile="lexer.c" header-file="lexer.h"

%{

#include <stdlib.h>
#include "exp.h"

%}

NUM [0-9]+

%%

[[:space:]]           { }
{NUM}                 { return token(TOK_NUM, atoi(yytext)); }
\+                    { return token(TOK_OP, SOMA); }
-                     { return token(TOK_OP, SUB); }
\*                    { return token(TOK_OP, MULT); }
\/                    { return token(TOK_OP, DIV); }
\(                    { return token(TOK_PONT, PARESQ); }
\)                    { return token(TOK_PONT, PARDIR); }
.                     { return token(TOK_ERRO, 0); }

%%

/* Variável global para um token */
Token tok;

Token *token(int tipo, int valor) {
    tok.tipo = tipo;
    tok.atributo = valor;
    return &tok;
}