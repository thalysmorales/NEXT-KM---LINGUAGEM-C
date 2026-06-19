# NEXT KM - Sistema de Gerenciamento de Loja de Corrida

## Descrição

O projeto NEXT KM consiste em um sistema de gerenciamento para uma loja de artigos esportivos voltados para corrida, desenvolvido em linguagem C. O programa foi elaborado com o objetivo de aplicar os conceitos fundamentais estudados na disciplina de Algoritmos e Técnicas de Programação I.

Além das funcionalidades de gerenciamento, o sistema possui uma interface textual personalizada utilizando caracteres ASCII e códigos ANSI para alteração de cores no terminal.

---

# Objetivo

Desenvolver um sistema capaz de realizar o controle de produtos de uma loja de corrida, permitindo o cadastro de itens, registro de vendas, movimentação de estoque, alteração das informações dos produtos e geração de relatórios.

---

# Tecnologias Utilizadas

* Linguagem C;
* Biblioteca stdio.h;
* Biblioteca stdlib.h;
* Biblioteca string.h;
* Biblioteca locale.h;
* Biblioteca windows.h;
* Códigos ANSI para personalização da interface.

---

# Conceitos Aplicados

Durante o desenvolvimento do sistema foram utilizados os seguintes conceitos:

* Variáveis;
* Vetores;
* Estruturas de decisão;
* Estruturas de repetição;
* Entrada e saída de dados;
* Operações matemáticas;
* Manipulação de caracteres;
* Interface textual personalizada.

---

# Funcionalidades

## Cadastro de Produtos

Permite cadastrar até 100 produtos contendo:

* Nome do produto;
* Valor de compra;
* Código do produto;
* Quantidade em estoque;
* Valor de venda;
* Percentual de desconto;
* Valor final com desconto.

Quando houver desconto, o sistema calcula automaticamente o valor promocional do produto.

---

## Vendas

A funcionalidade de vendas permite:

* Visualizar os produtos cadastrados;
* Selecionar o produto desejado;
* Informar a quantidade vendida;
* Verificar disponibilidade em estoque;
* Aplicar descontos quando disponíveis;
* Calcular o valor total da compra;
* Atualizar automaticamente a quantidade restante em estoque.

Além disso, o sistema registra:

* O valor total das vendas realizadas;
* O valor total concedido em descontos;
* A quantidade total de itens vendidos.

---

## Controle de Estoque

O módulo de estoque possibilita:

* Consultar todos os produtos cadastrados;
* Acrescentar unidades ao estoque;
* Reduzir unidades do estoque;
* Visualizar as informações atualizadas após cada movimentação.

---

## Alteração de Dados

Permite modificar informações dos produtos já cadastrados, como:

* Nome;
* Valor de compra;
* Código;
* Quantidade disponível;
* Valor de venda;
* Percentual de desconto.

Sempre que necessário, o valor promocional é recalculado automaticamente.

---

## Relatórios

O sistema disponibiliza informações importantes para a administração da loja, tais como:

### Valor Total do Estoque

Calcula o valor monetário correspondente aos produtos disponíveis em estoque.

### Quantidade Total de Itens Vendidos

Exibe a quantidade total de produtos comercializados durante a utilização do sistema.

### Alerta de Estoque Baixo

Quando a quantidade de determinado produto é igual ou inferior a dez unidades, o programa informa a necessidade de reposição.

### Relação Completa dos Produtos

Permite a visualização de todas as informações atualizadas dos produtos cadastrados.

---

# Fluxo de Funcionamento

```text
Tela Inicial
      ↓
Menu Principal
      ↓
1 - Cadastro
2 - Vendas
3 - Estoque
4 - Alterações
5 - Relatório
6 - Sair
      ↓
Execução da operação escolhida
      ↓
Retorno ao menu principal
      ↓
Encerramento do programa
```

---

# Estruturas de Dados Utilizadas

Para armazenar as informações dos produtos foram utilizados vetores, permitindo o cadastro de até cem produtos.

```c
char produto[100][30];
float valorP[100];
float valorCompra[100];
float valorDesconto[100];
float valorcomDesconto[100];
int qtdproduto[100];
int codigoP[100];
```

---

# Estruturas de Controle Utilizadas

## Estruturas de Decisão

* if;
* else;
* switch.

Essas estruturas são responsáveis pelo controle das ações executadas pelo sistema de acordo com as escolhas realizadas pelo usuário.

## Estruturas de Repetição

* for;
* do-while.

Essas estruturas garantem a repetição das operações e a navegação contínua entre os menus do programa.

---

# Interface do Sistema

O programa apresenta:

* Tela inicial personalizada;
* Molduras utilizando caracteres ASCII;
* Alteração de cores por meio de códigos ANSI;
* Mensagens de alerta e destaque para melhorar a interação com o usuário.

---

# Intenção do Desenvolvimento

O projeto foi desenvolvido com a finalidade de aplicar, de forma prática, os conhecimentos adquiridos na disciplina de Algoritmos e Técnicas de Programação I. O sistema busca simular o funcionamento básico de uma loja de corrida, permitindo a realização de operações essenciais para o gerenciamento de produtos, estoque e vendas.

Além de atender aos requisitos propostos, procurou-se desenvolver uma interface diferenciada e uma organização lógica capaz de tornar a utilização do programa mais intuitiva e próxima de uma aplicação comercial real.

---

# Autor

Thalys Morales Costa Silva

Projeto desenvolvido para fins acadêmicos na disciplina de Algoritmos e Técnicas de Programação I.
