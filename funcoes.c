#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
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
    while (p->prox != NULL && p != NULL)
    {
        p = p->prox;
    }
    return p;
}
// CLIENTE

Cliente cria_cliente()

{
    Cliente c1;
    printf("Nome:");
    scanf("%[^\n]", c1.nome);
    printf("CPF:");
    scanf("%d", &c1.cpf);
    printf("Email:");
    scanf("%s", c1.email);
    printf("TELEFONE:");
    scanf("%s", c1.telefone);
    printf("NASCIMENTO:");
    scanf("%s", c1.nascimento);
    c1.prox = NULL;

    return c1;
}

void insere_cliente_le(Cliente inserido, Cliente *anterior)
{
    Cliente *novo;
    novo = malloc(sizeof(Cliente));
    if (novo == NULL)
        return;
    *novo = inserido;
    novo->prox = anterior->prox;
    anterior->prox = novo;
}
void cadastrar_cliente(Cliente *le)
// adiciona cria cliente e adiciona cliente na lista;
{
    Cliente c1 = cria_cliente();
    Cliente *ultimo = acha_ultimo_leCliente(le);
    insere_cliente_le(c1, ultimo);
    printf("cliente cadastrado ");
}

void listar_clientes(Cliente *le)
{
    Cliente *p;
    for (p = le->prox; p != NULL; p = p->prox)
    {
        printf("/////////////////\n");
        printf("Nome:%s\n", p->nome);
        printf("Email:%s\n", p->email);
        printf("CPF:%d\n", p->cpf);
        printf("Numero:%s\n", p->telefone);
        printf("Data de nascimento:%s\n", p->nascimento);
    }
}

void buscar_cliente(Cliente *lista, int cpf)
{
    printf("teste");
}

void editar_cliente(Cliente *lista, int cpf)
{
    printf("teste");
}

void remover_cliente(Cliente **lista, int cpf)
{
    printf("teste");
}

// PRODUTO
void cadastrar_produto(Produto **lista)
{
    printf("teste");
}

void listar_produtos(Produto *lista)
{
    printf("teste");
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