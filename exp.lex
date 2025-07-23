/* ===== Arquivo exp.lex ===== */

%option noyywrap
%option nodefault
%option outfile="lexer.c" header-file="lexer.h"
%{ 
    #include "exp.h" 
%}

NUM [0-9]
NUMS {NUM}+
ABREC \/\*
FECHAC \*\/
LETRA [A-Za-z]
LETRAS {LETRA}+

%%
[[:space:]\n\t] { } /* ignora espaços e separadores*/
{ABREC}([^*]|\*+[^/])*{FECHAC} { } /* ignora comentarios */ 

{NUMS}\.{NUMS}(E[\+\-]?{NUMS})?  {return token(TOK_NUMF, yytext);}
{NUM}+ { return token("NUM_INT", yytext); }
<= {return token("RELOP", "none")}
< {return token("RELOP", "none")}
>= {return token("RELOP", "none")}
> {return token("RELOP", "none")}
== {return token("RELOP", "none")}
!= {return token("RELOP", "none")}
:= {return token("ATRIB", "none")}
if {return token("IF", "none")}
then {return token("THEN", "none")}
else {return token("ELSE", "none")}
while {return token("WHILE", "none")}
repeat {return token("REPEAT", "none")}
until {return token("UNTIL", "none")}
[{LETRAS}_][{LETRA}{NUM}_]* {return token("ID", yytext)}
<<EOF>> {return token("EOF", "none")}

/* Tratamento para token desconhecido */
. { return token("ERRO", "none"); } 

%%
// variavel global para um token
Token tok;

Token *token(const char *tipo_v, const char *valor) {
    strncpy(tok.tipo, tipo_v, LEXMAX-1);
    tok.tipo[LEXMAX-1] = '\0'; //fecha string tipo
    strncpy(tok.atributo, valor, LEXMAX-1);
    tok.atributo[LEXMAX-1] = '\0'; //fecha string atributo
    return &tok;
}
