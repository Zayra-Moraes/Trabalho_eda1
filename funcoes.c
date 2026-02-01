#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LISTAS
/* Carrinho *cria_le_carrinho()
{
  Carrinho *le;
  le = malloc(sizeof(Carrinho));
  le->prox = NULL;
  le->codigo[0] = '\0';
  le->qtd = 0;
  return le;
} */
Cliente *cria_le_cliente()
{
  Cliente *le;
  le = malloc(sizeof(Cliente));
  le->prox = NULL;
  return le;
}
Produto *cria_le_produto()
{
  printf("criei lista produtos\n");
  Produto *le;
  le = malloc(sizeof(Produto));
  le->prox = NULL;
  return le;
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
  char *nome = malloc(100 * sizeof(char));
  scanf("%[^\n]", nome); // acesso por ponteiro
  strcpy(c1->nome, nome);
  free(nome);
  int n_cpf = 1;
  char cpf[14];
  do
  {
    printf("CPF:");

    scanf("%s", cpf);
    n_cpf = verifica_cpf(cpf);

  } while (n_cpf == 0);
  strcpy(c1->cpf, cpf);
  printf("Email:");
  char *email = malloc(100 * (sizeof(char)));
  scanf("%s", email);
  strcpy(c1->email, email);
  free(email);
  printf("TELEFONE:");
  scanf("%s", c1->telefone);
  printf("NASCIMENTO:");
  scanf("%s", c1->nascimento);
  c1->prox = NULL;
  c1->carrinho = cria_item_carrinho(cpf);

  return c1;
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
  /* if (c->carrinho != NULL)
  {
    esvaziar_carrinho(c->carrinho);
    free(c->carrinho);
  } */
  free(c->nome);
  free(c->email);
  free(c);
}

void listar_clientes(Cliente *le)
{
  Cliente *p;
  for (p = le->prox; p != NULL; p = p->prox)
  {
    printf("\n-----------------------------\n");
    printf("Nome:%s\n", p->nome);
    printf("Email:%s\n", p->email);
    printf("CPF:%s\n", p->cpf);
    printf("Numero:%s\n", p->telefone);
    printf("Data de nascimento:%s\n", p->nascimento);
  }
  printf("-----------------------------\n\n");
}

Cliente *buscar_cliente(Cliente *lista, char *cpf)
{
  if (lista == NULL)
    return NULL;
  if (strcmp(lista->cpf, cpf) == 0)
    return lista;
  return buscar_cliente(lista->prox, cpf);
}

void editar_cliente(Cliente *le, char *cpf)
{

  Cliente *p = buscar_cliente(le->prox, cpf);
  {
    printf("Cliente encontrado!\n");
    printf("--------------------------------\n");
    printf("Nome: %s\n", p->nome);
    printf("CPF: %s\n", p->cpf);
    printf("Email: %s\n", p->email);
    printf("Telefone: %s\n", p->telefone);
    printf("nascimento: %s\n", p->nascimento);
    printf("--------------------------------\n");
  }
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
    while (getchar() != '\n')
      ;

    switch (opcao)
    {
    case 1:
      printf("Novo Nome: ");
      scanf("%[^\n]", p->nome);
      while (getchar() != '\n')
        ;
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

void remover_cliente(Cliente *le, char *cpf)
{
  Cliente *ant, *atual;
  ant = le;
  atual = le->prox;

  while (atual != NULL && strcmp(atual->cpf, cpf) !=
                              0)
  { // Preciso do anterior para religar a lista;
    // a busca simples não olha pro anterior
    ant = atual;
    atual = atual->prox;
  }
  if (atual != NULL)
  {
    ant->prox = atual->prox; // retira o atual da lista
    // quando criarmos o carrinho, precisamos liberar a memoria do carrinho do
    // cliente, igual o professor fez com as diciplinas
    free_cliente(atual);
    printf("Cliente removido com sucesso!\n");
  }
  else
  {
    printf("Cliente não encontrado.\n");
  }
}

int verifica_cpf(char *cpf)
{
  // printf("%s\n", cpf);
  int n = (strlen(cpf));
  // printf("%d\n", n);
  if (n > 11)
  {
    printf("CPF inválido, por favor inserir novamente: ");
    return 0; // erro
  }
  return 1; // dentro do padrao
}

// PRODUTO
void listar_produtos_carrinho_short(Produto *le)
{
  Produto *p;
  printf("\n--- Lista de Produtos --- \n");
  for (p = le->prox; p != NULL; p = p->prox)
  {
    printf("Nome: %s   | Preço: %.2f   | Quantidade disp.: %d\n ----------------\n", p->nome, p->preco, p->quantidade);
  }
}

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

  p1->nome = malloc(50 * sizeof(char));
  if (p1->nome == NULL)
  {
    free(p1);
    return NULL;
  }

  printf("\n--- Cadastro de Produto ---\n");
  printf("Código do produto: ");
  char codigo[13];
  scanf("%s", codigo);
  strcpy(p1->codigo, codigo);
  printf("Nome do Produto: ");
  char *nome = malloc(50 * sizeof(char));
  scanf(" %[^\n]", nome);
  strcpy(p1->nome, nome);
  free(nome);
  printf("Preço: ");
  scanf("%f", &p1->preco);
  printf("Quantidade em estoque: ");
  scanf("%d", &p1->quantidade);
  p1->prox = NULL;

  return p1;
}
Produto *cria_produto_Pcarrinho(char codigo[13], char *nome, float preco, int quantidade)
{
  Produto *p1 = malloc(sizeof(Produto));
  if (!p1)
  {
    return NULL;
  }
  p1->nome = malloc(50 * sizeof(char));
  if (!p1->nome)
  {
    return NULL;
  }
  strcpy(p1->nome, nome);
  strcpy(p1->codigo, codigo);
  p1->preco = preco;
  p1->quantidade = quantidade;
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

void lista_produtos_short(Produto *le)
{
  printf("\n--- Lista de Produtos ---\n");
  for (Produto *p = le->prox; p != NULL; p = p->prox)
  {
    printf("\nNome: %s  |  Preço: R$%.2f  | Quantidade disp.: %d   | Cod: %s\n", p->nome, p->preco, p->quantidade, p->codigo);
    /* code */
  }
  printf("\n");
}
void listar_produtos(Produto *le)
{

  Produto *p;
  printf("\n--- Lista de Produtos ---\n");
  for (p = le->prox; p != NULL; p = p->prox)
  {
    printf("Código: %s   \nNome: %-20s\n", p->codigo, p->nome);
    printf("Preço: R$ %.2f   \nQuantidade: %d\n\n", p->preco, p->quantidade);
  }
}

Produto *buscar_produtos(Produto *lista, char *codigo)
{
  if (lista == NULL)
    return NULL;
  if (strcmp(lista->codigo, codigo) == 0)
    return lista;
  return buscar_produtos(lista->prox, codigo);
}

void editar_produtos(Produto *le, char *codigo)
{
  Produto *p = buscar_produtos(le->prox, codigo);

  if (p == NULL)
  {
    printf("Produto não encontrado.\n");
    return;
  }

  int opcao = -1;
  while (opcao != 0)
  {
    printf("\n--- Editando Produto ---\n");
    printf("1 - Editar Nome\n");
    printf("2 - Editar Preço\n");
    printf("3 - Editar Quantidade\n");
    printf("0 - Finalizar Edição\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    while (getchar() != '\n')
      ;

    switch (opcao)
    {
    case 1:
      printf("Novo Nome: ");
      p->nome = calloc(50, sizeof(char));
      scanf(" %[^\n]", p->nome);
      while (getchar() != '\n')
      {
        printf("entrei aq");
      }
      printf("cheguei aqui2 ");
      break;
    case 2:
      printf("Novo Preço: ");
      scanf("%f", &p->preco);
      break;
    case 3:
      printf("Nova Quantidade: ");
      scanf("%d", &p->quantidade);
      break;
    case 0:
      break;
    default:
      printf("Opção inválida!\n");
    }
  }
}

void remover_produtos(Produto *lista, char *codigo)
{

  Produto *ant = lista;
  Produto *atual = lista->prox;

  while (atual != NULL && strcmp(atual->codigo, codigo) != 0)
  {
    ant = atual;
    atual = atual->prox;
  }
  if (atual != NULL)
  {
    ant->prox = atual->prox;
    // free_produto(atual);
    free(atual->nome);
    free(atual);
    printf("Produto removido com sucesso!\n");
  }
  else
  {
    printf("Erro: Produto não encontrado.\n");
  }
}

// COMPRA
Cliente *login(char *cpf, Cliente *le)
{ // funcional
  Cliente *c1 = buscar_cliente(le, cpf);
  if (c1 != NULL)
  {
    printf("login feito com sucesso\n");
    printf("Bem vindo %s\n", c1->nome);
    return c1; // logou
  }
  return NULL;
}

/* Carrinho *acha_ultimo_leCarrinho(Carrinho *le)
{
  if (!le)
  {
    return NULL;
  }
  Carrinho *p = le;
  while (p->prox != NULL)
  {
    p = p->prox;
  }
  return p;
} */

Carrinho *cria_item_carrinho(const char *codigo)
{

  printf("criando meu carrinho\n");
  Carrinho *it = malloc(sizeof(Carrinho));
  if (!it)
    return NULL;
  strncpy(it->codigo, codigo, 12);
  it->codigo[12] = '\0';
  it->qtd = 0;
  it->le_produtos = cria_le_produto();
  return it;
}

/* void insere_item_carrinho(Carrinho *item, Carrinho *le)
{
  if (!item || !le)
  {
    return;
  }
  Carrinho *ultimo = acha_ultimo_leCarrinho(le);
  ultimo->prox = item;
} */

int adicionar_ao_carrinho(Cliente *c, char *codigo_produto, int qtd_desejada, Produto *le_produto)
{

  if (!c || !c->carrinho || c->carrinho->le_produtos == NULL)
  {
    return 0;
  }
  Produto *p = buscar_produtos(le_produto, codigo_produto); // na lista estoque
  if (!p)
  {
    printf("Produto não existe.\n");
    return 0;
  }
  if (qtd_desejada <= 0)
  {
    printf("Qauntidade inválida.\n");
    return 0;
  }
  if (qtd_desejada > p->quantidade)
  {
    printf("Apenas %d unidades disponíveis em estoque.\n", p->quantidade);
    return 0;
  }
  if (qtd_desejada <= p->quantidade)
  {

    p->quantidade -= qtd_desejada; // atualizo valor do estoque
    // se já existe no carrinho soma
    // ta duplicando o valor que eu coloco

    for (Produto *it = c->carrinho->le_produtos; it != NULL; it = it->prox) // adiciona mais um
    {
      printf("produto inserido com sucesso no carrinho");

      if (strcmp(it->codigo, codigo_produto) == 0) // se forem iguai, negativo se a 1°< 2° ou positivo se 1°>2°
      {
        printf("achei repetido");
        it->quantidade += qtd_desejada;
        return 1;
      }
    }
    Produto *inserido = cria_produto_Pcarrinho(p->codigo, p->nome, p->preco, qtd_desejada);
    Produto *ultimo = acha_ultimo_leProduto(c->carrinho->le_produtos);
    printf("achei original");
    insere_produto_le(inserido, ultimo);
    return 1;
  }

  /* Carrinho *novo = cria_item_carrinho(codigo, qtd);
  insere_item_carrinho(novo, c->carrinho); */

  return 1;
}

void listar_carrinho(Cliente *c)
{
  printf("\n---------------- Carrinho ----------------\n");
  if (!c || !c->carrinho || c->carrinho->le_produtos->prox == NULL)
  {
    printf("Carrinho vazio!!");
    return;
  }

  // int vazio = 1;

  for (Produto *p = c->carrinho->le_produtos->prox; p != NULL; p = p->prox)
  {
    // vazio = 0;
    // Produto *p = buscar_produtos(le_produto, it->codigo);
    // if (p)
    //{
    printf("COD: %s | Nome: %s | Preço: R$ %.2f | Qtd: %d\n", p->codigo, p->nome, p->preco, p->quantidade);
    //}
    /* else// nunca vai cair aqui pq ja verifica la em cima ne
    {
      printf("COD: %s | (produto removido do estoque) | Qtd: %d\n", p->codigo, p->quantidade);
    } */
  }
  /* if (vazio)
  {
    printf("Carrinho vazio.\n");
  } */
}

/* void esvaziar_carrinho(Carrinho *le)
{

  if (le == NULL)
  {
    return;
  }
  Carrinho *p = le->prox;
  Carrinho *tmp;
  while (p != NULL)
  {
    tmp = p;
    p = p->prox;
    free(tmp);
  }
  le->prox = NULL;
} */

// teste

void cria_produto_teste(Produto *le)
{
  Produto *p1 = malloc(sizeof(Produto));
  if (p1 == NULL)
  {
    free(p1);
    return;
  }

  p1->nome = malloc(50 * sizeof(char));
  if (p1->nome == NULL)
  {
    free(p1->nome);
    return;
    /* code */
  }
  strcpy(p1->codigo, "codigoTeste");
  strcpy(p1->nome, "roupa teste");
  p1->preco = 4.50;
  p1->prox = NULL;
  p1->quantidade = 10;
  Produto *ultimo = acha_ultimo_leProduto(le);
  insere_produto_le(p1, ultimo);
  printf("Produto teste cadastrado\n");
}

void cria_cliente_teste(Cliente *le)
{
  Cliente *c1 = malloc(sizeof(Cliente));

  if (c1 == NULL)
  {
    return;
  }

  c1->nome = malloc(100 * sizeof(char));
  c1->email = malloc(100 * sizeof(char));
  if (c1->nome == NULL || c1->email == NULL)
  { // senao alocar certo limpa
    free(c1->nome);
    free(c1->email);
    free(c1);
    return;
  }

  strcpy(c1->nome, "Zayra gostosa"); // acesso por ponteiro
  strcpy(c1->cpf, "12345");
  strcpy(c1->email, "email.teste");
  strcpy(c1->telefone, "telefone");
  strcpy(c1->nascimento, "12122005");
  c1->prox = NULL;
  c1->carrinho = cria_item_carrinho(c1->cpf);
  Cliente *ultimo = acha_ultimo_leCliente(le);
  insere_cliente_le(c1, ultimo);

  // cliente 2:

  Cliente *c2 = malloc(sizeof(Cliente));

  if (c2 == NULL)
  {
    return;
  }

  c2->nome = malloc(100 * sizeof(char));
  c2->email = malloc(100 * sizeof(char));
  if (c2->nome == NULL || c2->email == NULL)
  { // senao alocar certo limpa
    free(c2->nome);
    free(c2->email);
    free(c2);
    return;
  }
  // acesso por ponteiro

  strcpy(c2->nome, "gabriel");
  strcpy(c2->cpf, "1234");
  strcpy(c2->email, "email.teste");
  strcpy(c2->telefone, "telefone");
  strcpy(c2->nascimento, "12121222");
  c2->prox = NULL;
  c2->carrinho = cria_item_carrinho(c2->cpf);
  Cliente *ultimo_2 = acha_ultimo_leCliente(le);
  insere_cliente_le(c2, ultimo_2);

  Cliente *c3 = malloc(sizeof(Cliente));

  if (c3 == NULL)
  {
    return;
  }

  c3->nome = malloc(100 * sizeof(char));
  c3->email = malloc(100 * sizeof(char));
  if (c3->nome == NULL || c3->email == NULL)
  { // senao alocar certo limpa
    free(c3->nome);
    free(c3->email);
    free(c3);
    return;
  }

  strcpy(c3->nome, "Maria"); // acesso por ponteiro
  strcpy(c3->cpf, "123");
  strcpy(c3->email, "email.teste");
  strcpy(c3->telefone, "telefone");
  strcpy(c3->nascimento, "12121222");
  c3->prox = NULL;
  c3->carrinho = cria_item_carrinho(c3->cpf);
  Cliente *ultimo_3 = acha_ultimo_leCliente(le);
  insere_cliente_le(c3, ultimo_3);
}