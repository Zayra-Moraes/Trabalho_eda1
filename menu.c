#include "menu.h"
#include "funcoes.h"
// #include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int menuCompra(Cliente *cliente, Produto *le_produtos)
{

  int entrada = -1;

  while (entrada != 0)
  {
    
    listar_carrinho(cliente);
    printf("\n\n");
    Sleep(1000);
    printf("--------------Menu de Compras--------------\n");
    // chamar o listar produtos
    printf("1 - Listar Produtos no estoque\n");
    printf("2 - Adicionar Produto ao carrinho\n");
    printf("3 - Remover produto do carrinho\n");
    printf("4 - Esvaziar Carrinho\n");
    printf("5 - Finalizar Compra\n");
    printf("0 - Sair\n");
    printf("--------------------------------------------\n");
    printf("\nPor favor digite um numero: ");
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
      printf("listar produtos\n");
      lista_produtos_short(le_produtos);
      Sleep(1000);
      break;
    case 2:
      printf("Adicionar produto ao carrinho\n\n");
      lista_produtos_short(le_produtos);
      printf("insira o codigo do produto que deseja inserir\n");
      char *EntradaCod = malloc(13 * sizeof(char));
      int EntradaQtd;
      scanf("%s", EntradaCod);
      printf("insira a quantidade desse produto que deseja adicionar ao carrinho\n");
      scanf("%d", &EntradaQtd);
      adicionar_ao_carrinho(cliente, EntradaCod, EntradaQtd, le_produtos);
      free(EntradaCod);
      break;
    case 3:
      printf("Remover produto do carrinho\n\n");
      printf("Por favor digite o codigo do produto que deseja remover: ");
      char *codigo = malloc(13 * sizeof(char));
      scanf("%s", codigo);
      Produto *p = busca_item(cliente->carrinho->le_produtos, codigo);
      free(codigo);
      if (p != NULL)
      {
        if (p->quantidade == 1){
          remove_item(cliente->carrinho->le_produtos, p, 1, le_produtos);
          printf("Produto removido com sucesso!");}
        else
        {
          int q;
          printf("Digite a quantidade qque deseja remover: ");
          scanf("%d", &q);
          remove_item(cliente->carrinho->le_produtos, p, q, le_produtos);
          printf("Produto removido com sucesso!");
        }
      }
      else
      {
        printf("Produto nao encontrado");
      }
      break;
    case 4:
      printf("Esvaziar Carrinho\n\n");
      if (!cliente || !cliente->carrinho || cliente->carrinho->le_produtos->prox == NULL)
      {
        printf("Carrinho já está vazio.\n");
      }
      else
      {
        esvaziar_carrinho(cliente->carrinho, le_produtos);
        printf("Carrinho esvaziado com sucesso.\n");
      }
      break;

    case 5:
      printf("finalizar compra\n\n");
      float valor = calcula_valor(cliente->carrinho->le_produtos);
      printf("->Resultado final do carrinho: R$%.2f com %d itens.", valor, calcula_itens(cliente->carrinho->le_produtos));
      int i = 0;
      while (i == 0)
      {
        printf("\nTem certeza que deseja finalizar a compra? (S/N) ");
        char resposta;
        scanf(" %c", &resposta);
        if (resposta == 'S' || resposta == 's')
        {
          printf("\nDigite sua senha: ");
          char *senha_dgt=malloc(100*sizeof(char));
          scanf(" %s",senha_dgt);
          int validacao=verifica_senha(cliente,senha_dgt);
          if(validacao==1){
            printf("Sua compra foi finalizada! Volte sempre!");
            i = 1;
            finalizar(cliente->carrinho, le_produtos);
            Sleep(1500);
            system("cls");
          }
          else{
            printf("\nSenha incorreta!\n");
            printf("Compra cancelada...\n\n");
            i=1;
          }
        }
        else if (resposta == 'N' || resposta == 'n')
        {
          printf("\nCompra cancelada! Seu carrinho ainda esta salvo se quiser tentar de novo depois!\n");
          i = 1;
        }
        else
        {
          printf("Por favor digite uma resposta valida...");
        }
      }

      break;
    case 0:
      printf("saindo...\n\n");
      break;
    default:
      printf("opcao invalida\n");
      return 0;
      break;
    }
  }
  return 0;
}

int menuProdutos(Produto *le_produto)
{
  int entrada = -1;

  while (entrada != 0)
  {
    Sleep(1000);
    printf("\n--------------Menu de Produtos--------------\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar todos os produtos\n");
    printf("3 - Buscar produto pelo codigo\n");
    printf("4 - Editar dados de um produto\n");
    printf("5 - Remover produto\n");
    printf("0 - Para voltar\n");
    printf("--------------------------------------------\n");
    printf("\nPor favor digite um numero: ");
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
      cadastrar_produto(le_produto); // funcional
      break;
    case 2:
      printf("listar todos os produtos...\n\n");
      listar_produtos(le_produto); // funcinal
      break;
    case 3:
    {
      char *entradaFind = malloc(13 * sizeof(char));
      if (entradaFind == NULL)
      {
        printf("erro na inicialização de ponteiro");
      }

      printf("buscar produto pelo codigo...\n\n");
      printf("Insira o codigo do produto\n");
      scanf("%s", entradaFind);
      Produto *p1 = buscar_produtos(le_produto, entradaFind);
      free(entradaFind);
      if (p1)
      {
        printf("Produto encontrado!\n");
        printf("--------------------------------\n");
        printf("COD: %s\n", p1->codigo);
        printf("NOME: %s\n", p1->nome);
        printf("PREÇO: %.02f\n", p1->preco);
        printf("QUANTIDADE: %d\n", p1->quantidade);
        printf("--------------------------------\n");
        break;
      }
      printf("Produto nao encontrado!");

      break;
    }
    case 4:
      printf("editar dados do produto...\n\n");
      char *entradaEdit = malloc(13 * sizeof(char));
      if (entradaEdit == NULL)
      {
        printf("erro na inicializacao de ponteiro");
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
      if (codigo == NULL)
      {
        printf("nao inicializaei");
      }
      listar_produtos(le_produto);
      printf("Por favor digite o codigo do produto que deseja remover: ");
      scanf("%s", codigo);

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

int menuCliente(Cliente *le)
{

  int entrada = -1;

  while (entrada != 0)
  {
    Sleep(1000);
    printf("--------------Menu de Clientes--------------\n");
    printf("1 - Cadastrar Cliente\n");
    printf("2 - Listar todos os Clientes\n");
    printf("3 - Buscar clientes\n");
    printf("4 - Editar dados de um cliente\n");
    printf("5 - Remover Cliente\n");
    printf("0 - Para voltar\n");
    printf("--------------------------------------------\n");
    printf("\nPor favor digite um numero: ");

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
      Sleep(1000);
      break;
    case 3:
      printf("Buscar cliente...\n\n");
      printf("Por favor digite o cpf ou o nome do cliente que deseja pesquisar:  ");
      // char cpf[12];
      char *cpf = malloc(12 * (sizeof(char)));
      scanf("%s", cpf);
      // Sleep(1.5);
      Cliente *c1 = buscar_cliente(le->prox, cpf);
      if (c1)
      {
        printf("Cliente encontrado!\n");
        printf("--------------------------------\n");
        printf("Nome: %s\n", c1->nome);
        printf("CPF: %s\n", c1->cpf);
        printf("Email: %s\n", c1->email);
        printf("Telefone: %s\n", c1->telefone);
        printf("nascimento: %s\n", c1->nascimento);
        printf("--------------------------------\n");
        Sleep(1000);
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
      Cliente *c = buscar_cliente(le->prox, cpf_digitado);
      if (c)
        editar_cliente(le, cpf_digitado);
      else
      {
        printf("Nenhum cliente encontrado com esse cpf!");
      }
      break;
    case 5:
      printf("remover cliente...\n\n");
      printf("Por favor digite o cpf do cliente que deseja remover: ");
      char *cpf_digitado2 = malloc(12 * sizeof(char));
      scanf("%s", cpf_digitado2);
      Cliente *c2 = buscar_cliente(le->prox, cpf_digitado2);
      if (c2)
      {
        printf("Cliente encontrado!\n");
        printf("--------------------------------\n");
        printf("Nome: %s\n", c2->nome);
        printf("CPF: %s\n", c2->cpf);
        printf("Email: %s\n", c2->email);
        printf("Telefone: %s\n", c2->telefone);
        printf("nascimento: %s\n", c2->nascimento);
        printf("--------------------------------\n");
        Sleep(1000);
        
        int i = 0;
        while (i == 0)
        {
          printf("Deseja reamente remover? (S/N) ");
          char resposta;
          scanf(" %c", &resposta);
          if (resposta == 'S' || resposta == 's')
          {
            i = 1;
            remover_cliente(le, cpf_digitado2);
          }
          else if (resposta == 'N' || resposta == 'n')
          {
            printf("Remocao cancelada!\n");
            i = 1;
          }
          else
          {
            printf("Por favor digite uma resposta valida...");
          }
        }
        free(cpf_digitado2);
        break;
      case 0:
        printf("saindo...\n\n");
        return 0;
      default:
        printf("opcao invalida\n");
        break;
      }
    }

  }
  return 0;
}

int menuPrincipal()
{
  Cliente *le_cliente = cria_le_cliente();
  Produto *le_produto = cria_le_produto();
  // Carrinho *le_carrinho = cria_le_carrinho();
  cria_cliente_teste(le_cliente);
  cria_produto_teste(le_produto);

  int entrada = -1;

  while (entrada != 0)
  {
    system("cls");
    printf("\n              BEM VINDO AO OBELISCO           \n");
    printf("----------------Menu Principal----------------\n");
    printf("1 - Gerenciamento de Clientes\n");
    printf("2 - Gerenciamento de Produtos\n");
    printf("3 - Modo Compra\n");
    printf("0 - Para sair\n");
    printf("------------------------------------------------\n");
    printf("\nPor favor digite um numero: ");

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
      menuProdutos(le_produto);
      break;
    case 3:
    {
      char *EntradaCPF = malloc(13 * sizeof(char));
      printf("\nEntrando no Modo Compra...\n\n");
      printf("por favor entre com seu CPF\n");
      scanf("%s", EntradaCPF);

      Cliente *_c = buscar_cliente(le_cliente->prox, EntradaCPF);
      if (_c == NULL) {
        printf("\n login nao realizado! Usuario nao encontrado...\n");
        free(EntradaCPF);
        break;
      }

      char *senha_digitada = malloc(100 * sizeof(char));
      printf("Por favor digite a senha: ");
      scanf(" %s", senha_digitada);

      int validacao = verifica_senha(_c, senha_digitada);
      if (validacao == 1) {
        printf("login feito com sucesso\n");
        printf("Bem vindo!\n");
        menuCompra(_c, le_produto);   // usa o cliente já encontrado
      } else {
        printf("Senha invalida!");
        Sleep(1000);
      }

      free(senha_digitada);
      free(EntradaCPF);
      break;
    }

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
