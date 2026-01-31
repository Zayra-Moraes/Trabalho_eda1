#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {

    system("color 0A");

/*
//testizinho do editar cliente
    Cliente *le = cria_le_cliente();
    Cliente *c = malloc(sizeof(Cliente));
    c->nome = malloc(100);
    strcpy(c->nome, "Maria");
    strcpy(c->cpf, "12345678901");
    c->email = malloc(100);
    strcpy(c->email, "maria@email.com");
    strcpy(c->telefone, "123456789");
    strcpy(c->nascimento, "01/01/2000");
    c->prox = NULL;
    insere_cliente_le(c, acha_ultimo_leCliente(le));
    listar_clientes(le);
    editar_cliente(le, c->cpf);
    listar_clientes(le);
*/

/*
//teste criar produto
    Produto *le = cria_le_produto();
    Produto *p = malloc(sizeof(Produto));
    p->nome = malloc(100);
    strcpy(p->nome, "Notebook");
    p->codigo = 101;
    p->preco = 3500.00;
    p->quantidade = 10;
    p->prox = NULL;
    insere_produto_le(p, acha_ultimo_leProduto(le));
    listar_produtos(le);    
    return 0;
*/

/*

Cliente *le = cria_le_cliente();

    char nomes[3][20] = {"Maria Primeira", "Maria Segunda", "Maria Terceira"};
    char cpfs[3][12] = {"111", "222", "333"};

    for(int i = 0; i < 3; i++) {
        Cliente *novo = malloc(sizeof(Cliente));
        novo->nome = malloc(100);
        novo->email = malloc(100);
        strcpy(novo->nome, nomes[i]);
        strcpy(novo->cpf, cpfs[i]);
        strcpy(novo->email, "teste@email.com");
        novo->prox = NULL;
        insere_cliente_le(novo, acha_ultimo_leCliente(le));
    }

    printf("\nlista antes de remover:\n");
    listar_clientes(le);

    // teste de remover a segunda: 
    remover_cliente(le, "222");

    //apos remover a 2
    listar_clientes(le);

    // alguem que n existe
    remover_cliente(le, "999");

    remover_cliente(le, "111");

    //lista final
    listar_clientes(le);

*/

//teste produtos

    Produto *le_p = cria_le_produto();

    char codigos[2][10] = {"A100", "B200"};
    for(int i = 0; i < 2; i++) {
        Produto *novo_p = malloc(sizeof(Produto));
        novo_p->nome = malloc(100);
        sprintf(novo_p->nome, "Produto Teste %d", i+1);
        strcpy(novo_p->codigo, codigos[i]); 
        novo_p->preco = 50.0 * (i+1);
        novo_p->quantidade = 10;
        novo_p->prox = NULL;
        insere_produto_le(novo_p, acha_ultimo_leProduto(le_p));
    }

    listar_produtos(le_p);
    editar_produtos(le_p, "B200");

    remover_produtos(le_p, "A100");

    listar_produtos(le_p);

    return 0;

}
    