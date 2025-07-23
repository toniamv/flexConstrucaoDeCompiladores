// Constantes booleanas
#define TRUE 1
#define FALSE 0

// Constantes para nome de token
#define TOK_NUM   0
#define TOK_OP    1
#define TOK_PONT  2
#define TOK_ERRO  3

// Constantes para operadores
#define SOMA  0
#define SUB   1
#define MULT  2
#define DIV   3

// Constantes para parênteses
#define PARESQ  0
#define PARDIR  1

// Estrutura de um token
typedef struct {
    int tipo;
    int atributo;
} Token;

// Função para criar um token
extern Token *token(int tipo, int valor);

// Função do analisador léxico
extern Token *yylex();