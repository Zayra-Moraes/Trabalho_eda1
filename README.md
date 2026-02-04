# Trabalho_eda1

## Integrantes:

Gabriel Vieira Octacilio Pinheiro - 242004706

Maria Eduarda de Jezus Gimarães - 242015924

Zayra Batista Moraes - 242015989

# 🛒 Obelisco — Sistema de Comércio em C

Sistema acadêmico desenvolvido em **C** para gerenciamento de **clientes, produtos e compras**, utilizando listas encadeadas e alocação dinâmica de memória.

O projeto foi criado para a disciplina de Estrutura de Dados, simulando um ambiente de comércio via terminal com operações completas de CRUD e um modo de compra com carrinho individual por cliente.

##  Funcionalidades

###  Clientes
- Cadastro, listagem, busca, edição e remoção
- Validação de CPF
- Login por CPF e senha
- Carrinho individual

###  Produtos
- Cadastro e controle de estoque
- Busca por código ou nome
- Edição e remoção
- Atualização automática de quantidade

###  Modo Compra
- Login do cliente
- Adicionar produtos ao carrinho
- Remover itens ou esvaziar carrinho
- Cálculo automático de total e quantidade
- Finalização da compra

##  Conceitos Aplicados
- Listas simplesmente encadeadas
- Structs e ponteiros
- Alocação dinâmica (`malloc`, `calloc`, `free`)
- Modularização (`main.c`, `menu.c`, `funcoes.c`)
- Menus interativos em terminal



##  Compilação

```bash
gcc main.c menu.c funcoes.c -o prog.exe
```

## Execução

```bash
./prog.exe
```

