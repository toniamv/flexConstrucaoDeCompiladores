
/* ===== Arquivo exp.h ===== */
// constantes para nome de token
#define LEXMAX 81 //define o tamanho maximo do lexema como string de 80 caracteres + \0

// estrutura de um token
typedef struct
{
    char tipo[LEXMAX];
    char atributo[LEXMAX]; //agora retorna um lexema
} Token;

// funcao para criar um token
extern Token *token();
// funcao do analisador lexico
extern Token *yylex();