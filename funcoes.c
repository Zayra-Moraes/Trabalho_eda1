#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// LISTAS
Carrinho *cria_le_carrinho()
{
    Carrinho *le;
    le = malloc(sizeof(Carrinho));
    le->prox = NULL;
    return le;
}
Cliente *cria_le_cliente()
{
    Cliente *le;
    le = malloc(sizeof(Cliente));
    le->prox = NULL;
    return le;
}
Produto *cria_le_produto()
{
    Produto *le;
    le = malloc(sizeof(Produto));
    le->prox = NULL;
    return le;
}
Cliente *acha_ultimo_leCliente(Cliente *le)
{
    Cliente *p = le;
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    return p;
}
// CLIENTE

Cliente *cria_cliente()
// crio uma celula cliente com o prox apontado pra null
// aloco a memoria e armazeno o valor nos campos
{
    Cliente *c1 = malloc(sizeof(Cliente));
    if (c1 == NULL)
    {
        return NULL;
    }

    c1->nome = malloc(100 * sizeof(char));
    c1->email = malloc(100 * sizeof(char));
    if (c1->nome == NULL || c1->email == NULL)
    { // senao alocar certo limpa
        free(c1->nome);
        free(c1->email);
        free(c1);
        return NULL;
    }

    printf("Nome:");
    scanf("%[^\n]", c1->nome); // acesso por ponteiro
    int n_cpf = 1;
    long int cpf = 0;
    do
    {
        printf("CPF:");

        scanf("%ld", &cpf);
        n_cpf = verifica_cpf(cpf);

    } while (n_cpf == 0);
    c1->cpf = cpf;
    printf("Email:");
    scanf("%s", c1->email);
    printf("TELEFONE:");
    scanf("%s", c1->telefone);
    printf("NASCIMENTO:");
    scanf("%s", c1->nascimento);
    c1->prox = NULL;

    return c1;
}

void insere_cliente_le(Cliente *inserido, Cliente *anterior)
// jogo de ponteiros
{
    if (inserido == NULL || anterior == NULL)
        return;
    inserido->prox = anterior->prox;
    anterior->prox = inserido;
}
void cadastrar_cliente(Cliente *le)
// adiciona cria cliente e adiciona cliente na lista;
{
    Cliente *c1 = cria_cliente();
    if (c1 == NULL)
    {
        printf("erro ao criar novo cliente\n");
        return;
    }
    Cliente *ultimo = acha_ultimo_leCliente(le);

    insere_cliente_le(c1, ultimo);
    printf("cliente cadastrado\n");
}

void free_cliente(Cliente *c)
{
    if (c == NULL)
    {
        return;
    }
    free(c->nome);
    free(c->email);
    free(c);
}

void listar_clientes(Cliente *le)
{
    Cliente *p;
    for (p = le->prox; p != NULL; p = p->prox)
    {
        printf("/////////////////\n");
        printf("Nome:%s\n", p->nome);
        printf("Email:%s\n", p->email);
        printf("CPF:%ld\n", p->cpf);
        printf("Numero:%s\n", p->telefone);
        printf("Data de nascimento:%s\n", p->nascimento);
    }
}

Cliente *buscar_cliente(Cliente *lista, long int cpf)
{
    if (lista == NULL)
        return NULL;
    if (lista->cpf == cpf)
        return lista;
    return buscar_cliente(lista->prox, cpf);
}

void editar_cliente(Cliente *le, long int cpf)
{

    Cliente *p = buscar_cliente(le->prox, cpf);

    if (p == NULL)
    {
        printf("Cliente com CPF não encontrado. \n");
        return;
    }
    int opcao = -1;
    while (opcao != 0)
    {
        printf("\n--- Editando Cliente ---\n");
        printf("1 - Editar Nome\n");
        printf("2- Editar email\n");
        printf("3- Ediatr Telefone\n");
        printf("4- Editar Nascimento\n");
        printf("0- Finalizar Edição\n");
        printf("EScolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Novo Nome: ");
            scanf("%[^\n]", p->nome);
            break;
        case 2:
            printf("Novo email: ");
            scanf("%s", p->email);
            break;
        case 3:
            printf("Novo Telefone: ");
            scanf("%s", p->telefone);
            break;
        case 4:
            printf("Nova Data de nascimento: ");
            scanf("%s", p->nascimento);
            break;
        case 0:
            printf("Edição Finalizada.\n ");
            break;
        default:
            printf("Opção invalida!");
        }
    }
}

void remover_cliente(Cliente **lista, int cpf)
{
    printf("teste");
}

int verifica_cpf(long int cpf)
{
    char str_cpf[13];
    snprintf(str_cpf, sizeof(str_cpf), "%ld", cpf);
    printf("%s\n", str_cpf);
    int n = (strlen(str_cpf));
    printf("%d\n", n);
    // if (digitos > 11)
    // {
    //     printf("CPF inválido, por favor inserir novamente: ");
    //     return 0; // erro
    // }
    // return 1; // dentro do padrao
}

// PRODUTO

Produto *acha_ultimo_leProduto(Produto *le)
{
    Produto *p = le;
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    return p;
}

Produto *cria_produto()
{
    Produto *p1 = malloc(sizeof(Produto));
    if (p1 == NULL)
        return NULL;

    printf("\n--- Cadastro de Produto ---\n");
    printf("Código do produto: ");
    scanf("%d", &p1->codigo);
    printf("Nome do Produto: ");
    scanf("%[^\n]", p1->nome);
    printf("Preço: ");
    scanf("%f", &p1->preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &p1->quantidade);
    p1->prox = NULL;

    return p1;
}

void insere_produto_le(Produto *inserido, Produto *anterior)

{
    if (inserido == NULL || anterior == NULL)
        return;
    inserido->prox = anterior->prox;
    anterior->prox = inserido;
}

void cadastrar_produto(Produto *le)
{
    Produto *novo = cria_produto();
    if (novo == NULL)
    {
        printf("Erro ao cadastrar novo produto");
        return;
    }
    Produto *ultimo = acha_ultimo_leProduto(le);
    insere_produto_le(novo, ultimo);
    printf("Produto [%s] cadastrado com sucesso!\n", novo->nome);
}

void free_produto(Produto *p)
{

    if (p == NULL)
        return;
    free(p->nome);
    free(p);
}

void listar_produtos(Produto *le)
{

    Produto *p;
    printf("\n--- Lista de Produtos ---\n");
    for (p = le->prox; p != NULL; p = p->prox)
    {
        printf("Código: %d   | Nome: %-20s\n", p->codigo, p->nome);
        printf("Preço: R$ %.2f   | Quantidade: %d\n", p->preco, p->quantidade);
    }
}

void buscar_produtos(Produto *lista, int codigo)
{
    printf("teste");
}

void editar_produtos(Produto *lista, int codigo)
{
    printf("teste");
}

void remover_produtos(Produto **lista, int codigo)
{
    printf("teste");
}

// COMPRA