#include "lexer.h"
#include "exp.h"

/* Carrega uma string como entrada */
YY_BUFFER_STATE buffer;

void inicializa(char *str) {
    buffer = yy_scan_string(str);
}

Token *proximo_token() {
    return yylex();
}

void imprime_token( Token *tok) {
    char tipo[LEXMAX];

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
    case ERRO:
        printf("Erro na captura de token");
        return 0;
        break;
    default:
        strcpy(tipo, "");
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

    fp = fopen(filename, "r");
    yyin = fp;
    
    tok = proximo_token();
    while (tok != NULL) {
        imprime_token(tok);
        tok = proximo_token();
    }
    printf("<EOF, none>\n");
 return 0;
}