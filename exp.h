
/* ===== Arquivo exp.h ===== */
// constantes para nome de token
#define LEXMAX 101 //define o tamanho maximo do lexema como string de 80 caracteres + \0

#define TOK_NUMF 1
#define NUM_INT 2
#define RELOP 3
#define ATRIB 4
#define IF 5
#define THEN 6
#define ELSE 7
#define WHILE 8
#define REPEAT 9
#define UNTIL 10
#define ID 11
#define ERRO 12
#define TOK_EOF 13

// estrutura de um token
typedef struct
{
    int tipo;
    char atributo[LEXMAX]; //agora retorna um lexema
} Token;

// funcao para criar um token
Token *token(int tipo, char* valor);