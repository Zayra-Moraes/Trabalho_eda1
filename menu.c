#include "menu.h"
#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <windows.h>

// void cria_cliente_teste(Cliente *le)
// {
//   Cliente *c1 = malloc(sizeof(Cliente));

//   if (c1 == NULL)
//   {
//     return ;
//   }

//   c1->nome = malloc(100 * sizeof(char));
//   c1->email = malloc(100 * sizeof(char));
//   if (c1->nome == NULL || c1->email == NULL)
//   { // senao alocar certo limpa
//     free(c1->nome);
//     free(c1->email);
//     free(c1);
//     return ;
//   }

//   c1->nome = "Zayra gostosa"; // acesso por ponteiro
//   strcpy(c1->cpf, "12345");
//   c1->email = "email.teste";
//   strcpy(c1->telefone, "telefone");
//   strcpy(c1->nascimento , "12122005");
//   c1->prox = NULL;
//   Cliente * ultimo =acha_ultimo_leCliente(le);
//   insere_cliente_le(c1,ultimo);
// }

int menuCompra() {
  int entrada = -1;

  while (entrada != 0) {

    printf("--------------Menu de Compras--------------\n");
    // chamar o listar produtos
    printf("0 - Para voltar\n");
    printf("\nPor favor digite um numero:\n");
    printf("--------------------------------------------\n");
    if (scanf("%d", &entrada) != 1) {
      printf("entrada invalida\n");
      while (getchar() != '\n')
        ;
      continue;
    }
    while (getchar() != '\n')
      ;

    switch (entrada) {
    case 1:
      printf("cadastrar Produto...\n\n");
      break;

    case 2:
      printf("listar carrinho\n\n");
      break;
    case 3:
      printf("Adicionar produto ao carrinho\n\n");
      break;
    case 4:
      printf("Remover produto\n\n");
      break;
    case 5:
      printf("finalizar compra\n\n");
      break;
    case 0:
      printf("saindo...\n\n");
      return 0;
    default:
      printf("opcao invalida\n");
      break;
    }
  }
  return 0;
}

int menuProdutos(Produto *le_produto) {
  cria_produto_teste(le_produto);
  int entrada = -1;

  while (entrada != 0) {

    printf("--------------Menu de Produtos--------------\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar todos os produtos\n");
    printf("3 - Buscar produto pelo codigo\n");
    printf("4 - Editar dados de um produto\n");
    printf("5 - Remover produto\n");
    printf("0 - Para voltar\n");
    printf("\nPor favor digite um numero:\n");
    printf("--------------------------------------------\n");
    if (scanf("%d", &entrada) != 1) {
      printf("entrada invalida\n");
      while (getchar() != '\n')
        ;
      continue;
    }
    while (getchar() != '\n')
      ;

    switch (entrada) {
    case 1:
      printf("cadastrar produto...\n\n");
      cadastrar_produto(le_produto); // funcional
      break;
    case 2:
      printf("listar todos os produtos...\n\n");
      listar_produtos(le_produto); // funcinal
      break;
    case 3:
      char *entradaFind = malloc(13 * sizeof(char));
      if (entradaFind == NULL) {
        printf("erro na inicialização de ponteiro");
      }

      printf("buscar produto pelo codigo...\n\n");
      printf("Insira o codigo do produto\n");
      scanf("%s", entradaFind);
      Produto *p1 = buscar_produtos(le_produto, entradaFind);
      free(entradaFind);
      if (p1) {
        printf("Produto encontrado!\n");
        printf("--------------------------------\n");
        printf("COD: %s\n", p1->codigo);
        printf("NOME: %s\n", p1->nome);
        printf("PREÇO: %.02f\n", p1->preco);
        printf("QUANTIDADE EM ESTOQUE: %d\n", p1->quantidade);
        printf("--------------------------------\n");
        break;
      }
      printf("Produto nao encontrado!");

      break;
    case 4:
      printf("editar dados do produto...\n\n");
      char *entradaEdit = malloc(13 * sizeof(char));
      if (entradaEdit == NULL) {
        printf("erro na inicialização de ponteiro");
      }
      listar_produtos(le_produto);
      printf("Digite o codigo do produto que deseja editar: ");
      scanf("%s", entradaEdit);
      editar_produtos(le_produto, entradaEdit);
      free(entradaEdit);

      break;
    case 5:
      printf("remover produto\n\n");
      char *codigo = calloc(50, sizeof(char));
      if(codigo == NULL){
        printf("nao inicializaei");
      }
      listar_produtos(le_produto);
      printf("Por favor digite o codigo do produto que deseja remover: ");
      scanf("%s", codigo) ;  
            
      remover_produtos(le_produto, codigo);
      // free(codigo);

      break;
    case 0:
      printf("saindo...\n\n");
      return 0;
    default:
      printf("opcao invalida\n");
      break;
    }
  }
  return 0;
}

int menuCliente(Cliente *le) {
  int entrada = -1;

  while (entrada != 0) {

    printf("--------------Menu de Clientes--------------\n");
    printf("1 - Cadastrar Cliente\n");
    printf("2 - Listar todos os Clientes\n");
    printf("3 - Buscar clientes pelo CPF\n");
    printf("4 - Editar dados de um cliente\n");
    printf("5 - Remover Cliente\n");
    printf("0 - Para voltar\n");
    printf("--------------------------------------------\n");
    printf("\nPor favor digite um numero:\n");

    if (scanf("%d", &entrada) !=1) { // se ele nao conseguir ler um int o scanf vai retornar 0
      printf("entrada invalida\n");
      while (getchar() != '\n')
        ;
      continue;
    }
    while (getchar() != '\n')
      ;

    switch (entrada) {
    case 1:
      printf("cadastrar cliente...\n\n");
      cadastrar_cliente(le);
      break;

    case 2:
      printf("listar todos os clientes...\n\n");
      listar_clientes(le);
      break;
    case 3:
      printf("buscar cliente pelo cpf...\n\n");
      printf("Por favor digite o cpf do cliente que deseja pesquisar:  ");
      // char cpf[12];
      char *cpf = malloc(12 * (sizeof(char)));
      scanf("%s", cpf);
      // Sleep(1.5);
      Cliente *c1 = buscar_cliente(le, cpf);
      if (c1) {
        printf("Cliente encontrado!\n");
        printf("--------------------------------\n");
        printf("Nome: %s\n", c1->nome);
        printf("CPF: %s\n", c1->cpf);
        printf("Email: %s\n", c1->email);
        printf("Telefone: %s\n", c1->telefone);
        printf("nascimento: %s\n", c1->nascimento);
        printf("--------------------------------\n");
        break;
      }
      printf("Cliente nao encontrado!");
      free(cpf);
      break;
    case 4:
      printf("editar dados do cliente...\n\n");
      char cpf_digitado[12];
      printf("Por favor digite o cpf do cliente que deseja alterar os dados: ");
      scanf("%s", cpf_digitado);
      Cliente *c = buscar_cliente(le, cpf_digitado);
      if (c)
        editar_cliente(le, cpf_digitado);
      else {
        printf("Nenhum cliente encontrado com esse cpf!");
      }
      break;
    case 5:
      printf("remover cliente...\n\n");
      printf("Por favor digite o cpf do cliente que deseja remover: ");
      scanf("%s", cpf_digitado);
      remover_cliente(le, cpf_digitado);
      break;
    case 0:
      printf("saindo...\n\n");
      return 0;
    default:
      printf("opcao invalida\n");
      break;
    }
  }
  return 0;
}

int menuPrincipal() {
  Cliente *le_cliente = cria_le_cliente();
  Produto *le_produto = cria_le_produto();
  Carrinho *le_carrinho = cria_le_carrinho();
  cria_teste(le_cliente);

  int entrada = -1;

  while (entrada != 0) {

    printf("\n              BEM VINDO A obelisco           \n");
    printf("----------------Menu Principal----------------\n");
    printf("1 - Gerenciamento de Clientes\n");
    printf("2 - Gerenciamento de Produtos\n");
    printf("3 - Modo Compra\n");
    printf("0 - Para sair\n");
    printf("------------------------------------------------\n");
    printf("\nPor favor digite um numero:\n");

    if (scanf("%d", &entrada) != 1) {
      printf("entrada invalida\n");
      while (getchar() != '\n')
        ;
      continue;
    }
    while (getchar() != '\n')
      ;

    switch (entrada) {
    case 1:
      printf("Entrando no Menu de clientes...\n\n");
      menuCliente(le_cliente);
      break;

    case 2:
      printf("Entrando no Menu de Produtos...\n\n");
      menuProdutos(le_produto);
      break;
    case 3:
      printf("Entrando no Modo Compra...\n\n");
      break;
    case 0:
      printf("saindo...\n\n");
      return 0;
    default:
      printf("opcao invalida\n\n");
      break;
    }
  }

  return 0;
}
