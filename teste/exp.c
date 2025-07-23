#include <stdio.h>
#include <string.h>
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

void imprime_token(Token *tok) {
    if (tok == NULL) return;

    switch (tok->tipo) {
        case TOK_NUM:
            printf("<TOK_NUM, %d>\n", tok->atributo);
            break;
        case TOK_OP:
            switch (tok->atributo) {
                case SOMA: printf("<TOK_OP, '+'>\n"); break;
                case SUB:  printf("<TOK_OP, '-'>\n"); break;
                case MULT: printf("<TOK_OP, '*'>\n"); break;
                case DIV:  printf("<TOK_OP, '/'>\n"); break;
            }
            break;
        case TOK_PONT:
            switch (tok->atributo) {
                case PARESQ: printf("<TOK_PONT, '('>\n"); break;
                case PARDIR: printf("<TOK_PONT, ')'>\n"); break;
            }
            break;
        case TOK_ERRO:
            printf("<TOK_ERRO, ?>\n");
            break;
        default:
            printf("<DESCONHECIDO, ?>\n");
    }
}

int main(int argc, char **argv) {
    Token *tok;
    char entrada[200];

    printf("\nAnálise Léxica da expressão: ");
    fgets(entrada, sizeof(entrada), stdin);

    inicializa(entrada);

    while ((tok = proximo_token()) != NULL) {
        imprime_token(tok);
    }

    return 0;
}