/* ===== Arquivo exp.c ===== */

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
    printf("<%s, %s>\n", tok->tipo, tok->atributo);
    //leitura de token
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
 return 0;
}