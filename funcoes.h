#ifndef funcoes_h
#define funcoes_h

typedef struct produto
{
    // fez produto como uma celula de uma le
    int codigo;
    char *nome;
    float preco;
    int quantidade;
    struct produto *prox;
} Produto;

typedef struct carrinho
{
    // fez carrinho como uma celula de le
    int codigo_prod;
    int qtd;
    struct carrinho *prox;
} Carrinho;

typedef struct cliente
{
    // fez um cliente como uma celula de uma le
    int cpf;
    char nome[100];
    char email[100];
    char telefone[15];
    char nascimento[11];
    struct cliente *prox;
} Cliente;

Cliente * cria_le_cliente();
Produto * cria_le_produto();
Carrinho * cria_le_carrinho();
void insere_produto_le(Produto x, Produto *le);
void insere_carrinho_le(Carrinho x, Carrinho *le);
void insere_cliente_le(Cliente x, Cliente *le);
Cliente  cria_cliente();
void cadastrar_cliente(Cliente *le);
void listar_clientes(Cliente *lista);
void buscar_cliente(Cliente *lista, int cpf);
void editar_cliente(Cliente *lista, int cpf);
void remover_cliente(Cliente **lista, int cpf);

void cadastrar_produto(Produto **lista);
void listar_produtos(Produto *lista);
void buscar_produtos(Produto *lista, int codigo);
void editar_produtos(Produto *lista, int codigo);
void remover_produtos(Produto **lista, int codigo);

#endif