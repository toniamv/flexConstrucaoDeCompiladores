#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "exp.h"

/* Carrega uma string como entrada */
// YY_BUFFER_STATE buffer;
extern FILE *yyin;
extern Token *yylex();

// void inicializa(char *str) {
//     buffer = yy_scan_string(str);
// }

int filend = 0;

Token *proximo_token() {
    return yylex();
}

void imprime_token(Token *tok) {
    char tipo[LEXMAX] = "";

    switch (tok->tipo) {
    case TOK_NUMF:
        strcpy(tipo, "TOK_NUMF");
        break;
    case NUM_INT:
        strcpy(tipo, "NUM_INT");
        break;
    case RELOP:
        strcpy(tipo, "RELOP");
        break;
    case ATRIB:
        strcpy(tipo, "ATRIB");
        break;
    case IF:
        strcpy(tipo, "IF");
        break;
    case THEN:
        strcpy(tipo, "THEN");
        break;
    case ELSE:
        strcpy(tipo, "ELSE");
        break;
    case WHILE:
        strcpy(tipo, "WHILE");
        break;
    case REPEAT:
        strcpy(tipo, "REPEAT");
        break;
    case UNTIL:
        strcpy(tipo, "UNTIL");
        break;
    case ID:
        strcpy(tipo, "ID");
        break;
    case TOK_PARENT:
	strcpy(tipo, "TOK_PARENT");
	break;
    case TOK_PONT:
	strcpy(tipo, "TOK_PONT");
	break;
    case TOK_EOF:
        strcpy(tipo, "EOF");
	filend = 1;
	break;
    case ERRO:
        printf("Erro na captura de token");
        break;
    }
    printf("<%s, %s>\n", tipo, tok->atributo);
}

int main(int argc, char **argv) {
    Token *tok;
    // Definicao da entrada
    FILE *fp;
    char filename[50];
    printf("Entre nome do arquivo: \n");
    scanf("%s", filename);

    yyin = fopen(filename, "r");

    tok = proximo_token();
    while (filend != 1 && tok != NULL) {
        imprime_token(tok);
        tok = proximo_token();
    }

 return 0;
}
