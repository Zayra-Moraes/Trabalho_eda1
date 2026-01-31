#ifndef funcoes_h
#define funcoes_h

typedef struct produto
{
    // fez produto como uma celula de uma le
    char codigo[13];
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
    Produto *produto;
    struct carrinho *prox;
} Carrinho;

typedef struct cliente
{
    // fez um cliente como uma celula de uma le
    char cpf[12];
    char *nome;
    char *email;
    char telefone[15];
    char nascimento[11];
    struct cliente *prox;
} Cliente;

Cliente * cria_le_cliente();
Produto * cria_le_produto();
Carrinho * cria_le_carrinho();
Cliente *acha_ultimo_leCliente(Cliente *le);

void insere_produto_le(Produto *inserido, Produto *anterior);
void insere_carrinho_le(Carrinho x, Carrinho *le);
void insere_cliente_le(Cliente *inserido, Cliente *anterior);

void free_cliente(Cliente *c);
Cliente  * cria_cliente();
void cadastrar_cliente(Cliente *le);
void listar_clientes(Cliente *lista);
Cliente *buscar_cliente(Cliente *lista, char *cpf);
void editar_cliente(Cliente *le, char *cpf);
void remover_cliente(Cliente *le, char *cpf);
int verifica_cpf(char *cpf);

void cadastrar_produto(Produto *le);
void listar_produtos(Produto *le);
Produto* acha_ultimo_leProduto(Produto *le);
Produto* buscar_produtos(Produto *lista, char *codigo);
void editar_produtos(Produto *le, char *codigo);
void remover_produtos(Produto *lista, char *codigo);

#endif