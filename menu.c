#include "menu.h"
#include "funcoes.h"
#include <stdio.h>
#include <windows.h>

void cria_cliente_teste(Cliente *le)
{
  Cliente *c1 = malloc(sizeof(Cliente));

  if (c1 == NULL)
  {
    return ;
  }

  c1->nome = malloc(100 * sizeof(char));
  c1->email = malloc(100 * sizeof(char));
  if (c1->nome == NULL || c1->email == NULL)
  { // senao alocar certo limpa
    free(c1->nome);
    free(c1->email);
    free(c1);
    return ;
  }

  c1->nome = "Zayra gostosa"; // acesso por ponteiro
  c1->cpf = 789456;
  c1->email = "email.teste";
  strcpy(c1->telefone, "telefone");
  strcpy(c1->nascimento , "12122005");
  c1->prox = NULL;
  Cliente * ultimo =acha_ultimo_leCliente(le);
  insere_cliente_le(c1,ultimo);
}
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
      printf("Editar dados do cliente...\n\n");
      long int cpf_digitado;
      if (verifica_cpf(cpf_digitado))
        editar_cliente(le, cpf_digitado);
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
      break;
    case 3:
      printf("buscar cliente pelo cpf...\n\n");
      printf("Por favor digite o cpf do cliente que deseja pesquisar:  ");
      int cpf = 0;
      scanf("%d", &cpf);
      Sleep(1.5);
      Cliente *c1 = buscar_cliente(le, cpf);
      if (c1)
      {
        printf("Cliente encontrado!\n");
        printf("--------------------------------\n");
        printf("Nome: %s\n", c1->nome);
        printf("CPF: %ld\n", c1->cpf);
        printf("Email: %s\n", c1->email);
        printf("Telefone: %s\n", c1->telefone);
        printf("nascimento: %s\n", c1->nascimento);
        printf("--------------------------------\n");
        break;
      }
      printf("Cliente nao encontrado!");
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
  cria_cliente_teste(le_cliente);

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
