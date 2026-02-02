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
    char codigo[13];// o codigo sera o mesmo do cliente
    int qtd;// quantidade de itens no carrinho ?
    Produto *le_produtos;
} Carrinho;
//cliente tem um carrinho que tem uma lista de produtos
typedef struct cliente
{
    // fez um cliente como uma celula de uma le
    char cpf[12];
    char *nome;
    char *email;
    char telefone[15];
    char nascimento[11];
    struct carrinho *carrinho;
    struct cliente *prox;
} Cliente;

//Cria lista
Cliente * cria_le_cliente();
Produto * cria_le_produto();
//Carrinho * cria_le_carrinho();
Cliente *acha_ultimo_leCliente(Cliente *le);

//Insere produto
void insere_produto_le(Produto *inserido, Produto *anterior);
// void insere_carrinho_le(Carrinho x, Carrinho *le);
void insere_cliente_le(Cliente *inserido, Cliente *anterior);

//Cliente
void cria_cliente_teste(Cliente *le);
void free_cliente(Cliente *c);
Cliente  * cria_cliente();
void cadastrar_cliente(Cliente *le);
void listar_clientes(Cliente *lista);
Cliente *buscar_cliente(Cliente *lista, char *cpf);
void editar_cliente(Cliente *le, char *cpf);
void remover_cliente(Cliente *le, char *cpf);
int verifica_cpf(char *cpf);
void cria_teste(Cliente *le);

//Produto
void cria_produto_teste(Produto *le);
void cadastrar_produto(Produto *le);
void listar_produtos(Produto *le);
void lista_produtos_short(Produto *le);
Produto* acha_ultimo_leProduto(Produto *le);
Produto* buscar_produtos(Produto *lista, char *codigo);
void editar_produtos(Produto *le, char *codigo);
void remover_produtos(Produto *lista, char *codigo);

//Carrinho


Carrinho *acha_ultimo_leCarrinho(Carrinho *le);
Carrinho *cria_item_carrinho(const char *codigo);
void insere_item_carrinho(Carrinho *item, Carrinho *le);
int adicionar_ao_carrinho (Cliente *c,  char *codigo, int qtd, Produto *le_produto);
void listar_carrinho(Cliente *c);
void esvaziar_carrinho(Carrinho *c, Produto *le_produtos);
Cliente * login(char *cpf,Cliente *le_cliente);
Produto *busca_item(Produto *le, char *codigo);
void remove_item(Produto *le_carrinho, Produto *p_quero_remover, int qtd, Produto *le_produtos);


#endif