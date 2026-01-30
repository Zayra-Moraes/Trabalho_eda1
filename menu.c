#include "menu.h"
#include "funcoes.h"
#include <stdio.h>

// menu nem comecei
int menuCompra()
{
  int entrada = -1;

  while (entrada != 0)
  {

    printf("--------------Menu de Compras--------------\n");
    // chamar o listar produtos
    printf("0 - Para voltar\n");
    printf("\nPor favor digite um numero:\n");
    printf("--------------------------------------------\n");
    if (scanf("%d", &entrada) != 1)
    {
      printf("entrada invalida\n");
      while (getchar() != '\n')
        ;
      continue;
    }
    while (getchar() != '\n')
      ;

    switch (entrada)
    {
    case 1:
      printf("cadastrar cliente...\n\n");
      break;

    case 2:
      printf("listar todos os clientes...\n\n");
      break;
    case 3:
      printf("buscar cliente por cpf...\n\n");
      break;
    case 4:
      printf("editar dados do cliente...\n\n");
      break;
    case 5:
      printf("remover cliente\n\n");
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

int menuProdutos()
{
  int entrada = -1;

  while (entrada != 0)
  {

    printf("--------------Menu de Produtos--------------\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar todos os produtos\n");
    printf("3 - Buscar produto pelo codigo\n");
    printf("4 - Editar dados de um produto\n");
    printf("5 - Remover produto\n");
    printf("0 - Para voltar\n");
    printf("\nPor favor digite um numero:\n");
    printf("--------------------------------------------\n");
    if (scanf("%d", &entrada) != 1)
    {
      printf("entrada invalida\n");
      while (getchar() != '\n')
        ;
      continue;
    }
    while (getchar() != '\n')
      ;

    switch (entrada)
    {
    case 1:
      printf("cadastrar produto...\n\n");
      break;

    case 2:
      printf("listar todos os produtos...\n\n");
      break;
    case 3:
      printf("buscar produto pelo codigo...\n\n");
      break;
    case 4:
      printf("editar dados do produto...\n\n");
      break;
    case 5:
      printf("remover produto\n\n");
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

int menuCliente(Cliente *le)
{
  int entrada = -1;

  while (entrada != 0)
  {

    printf("--------------Menu de Clientes--------------\n");
    printf("1 - Cadastrar Cliente\n");
    printf("2 - Listar todos os Clientes\n");
    printf("3 - Buscar clientes pelo CPF\n");
    printf("4 - Editar dados de um cliente\n");
    printf("5 - Remover Cliente\n");
    printf("0 - Para voltar\n");
    printf("--------------------------------------------\n");
    printf("\nPor favor digite um numero:\n");

    if (scanf("%d", &entrada) != 1)
    { // se ele nao conseguir ler um int o scanf vai retornar 0
      printf("entrada invalida\n");
      while (getchar() != '\n')
        ;
      continue;
    }
    while (getchar() != '\n')
      ;

    switch (entrada)
    {
    case 1:
      printf("cadastrar cliente...\n\n");
      cadastrar_cliente(le);
      break;

    case 2:
      printf("listar todos os clientes...\n\n");
      listar_clientes(le);
    case 3:
      printf("buscar cliente pelo cpf...\n\n");
      break;
    case 4:
      printf("editar dados do cliente...\n\n");
      break;
    case 5:
      printf("remover cliente\n\n");
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

int menuPrincipal()
{
  Cliente *le_cliente = cria_le_cliente();
  Produto *le_produto = cria_le_produto();
  Carrinho *le_carrinho = cria_le_carrinho();
  int entrada = -1;

  while (entrada != 0)
  {

    printf("\n              BEM VINDO A obelisco           \n");
    printf("----------------Menu Principal----------------\n");
    printf("1 - Gerenciamento de Clientes\n");
    printf("2 - Gerenciamento de Produtos\n");
    printf("3 - Modo Compra\n");
    printf("0 - Para sair\n");
    printf("------------------------------------------------\n");
    printf("\nPor favor digite um numero:\n");

    if (scanf("%d", &entrada) != 1)
    {
      printf("entrada invalida\n");
      while (getchar() != '\n')
        ;
      continue;
    }
    while (getchar() != '\n')
      ;

    switch (entrada)
    {
    case 1:
      printf("Entrando no Menu de clientes...\n\n");
      menuCliente(le_cliente);
      break;

    case 2:
      printf("Entrando no Menu de Produtos...\n\n");
      menuProdutos();
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
