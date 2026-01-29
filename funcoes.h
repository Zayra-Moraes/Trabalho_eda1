#ifndef funcoes_h
#define funcoes_h

typedef struct produto{
    int codigo;
    char *nome;
    float preco;
    int quantidade;
    struct produto *prox;
} Produto;

typedef struct carrinho{
    int codigo_prod;
    int qtd;
    struct carrinho *prox;
} Carrinho;

typedef struct cliente{
    int cpf;
    char *nome;
    char *email;
    char telefone[15];
    char nascimento[11];
    struct cliente *prox;
}Cliente;

void cadastrar_cliente(Cliente **lista);
void listar_cliente(Cliente *lista);
void buscar_cliente(Cliente *lista, int cpf);
void editar_cliente(Cliente *lista, int cpf);
void remover_cliente(Cliente **lista, int cpf);

void cadastrar_produto(Produto **lista);
void listar_produtos(Produto *lista);
void buscar_produtos(Produto *lista, int codigo);
void editar_produtos(Produto *lista, int codigo);
void remover_produtos(Produto **lista, int codigo);




#endif