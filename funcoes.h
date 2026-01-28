#ifndef funcoes_h
#define funcoes_h

typedef struct produto{
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
    struct produto *prox;
} Produto;

typedef struct cliente{
    int cpf;
    char nome[100];
    char email[50];
    char telefone[15];
    char nascimento[11];
    struct cliente *prox;
}Cliente;



#endif