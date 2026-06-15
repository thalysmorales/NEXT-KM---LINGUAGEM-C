/*Loja de Corrida.
O projeto deve conter: alteração de cor, moldura ao redor de toda a tela usando caracter ASCII, tela de entrada apresentar um Desenho,
Menu principal (opções mínimas Cadastro, Lançamentos ou Vendas ou Movimentação, Relatório e Sair) usando
switch e while ou do-while, devendo executar várias vezes até selecionar a opção Sair. Proibido uso de Modularização e Arquivo, pois os conceitos ainda não
foram lecionados em sala de aula. Pontuação Apresentação Individual para Professor. Bibliografia recomendada: Victorine Mizhari Treinamento em Linguagem C,
apresentar no dia da apresentação os livros utilizados para o desenvolvimento do Trabalho.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Usado para o programa respeitar as configurações de pontuação do teclado windowns
#include <locale.h>

/*Usando para definir uma função que o DEV C++ não reconhece por ser uma versão inferior e não consegue distinguir
elementos da tabela ASCII dos caracteres do alfabeto.*/
/*#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#include <windows.h>
*/
#define pisca printf("\x1B[5m")
#define fim printf("\x1B[0m")

/*
//codigos de cores ANSI
 roxo printf("\033[35m")
 verde printf("\033[32m")
 vermelho printf("\033[31m")
 amarelo printf("\033[33m")
 branco printf("\033[37m")
 zero printf("\033[0m")
*/

int main() {


	//Usado para o programa respeitar as configurações de pontuação do teclado windows
	setlocale(LC_ALL, "");

	/*Usando para definir uma função que o DEV C++ não reconhece por ser uma versão inferior
	e não consegue distinguir elementos da tabela ASCII dos caracteres do alfabeto.*/
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//DWORD dwMode = 0;
	//Habilita a tabela ASCII
	//GetConsoleMode(hOut, &dwMode);
	//SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	char entrarMenu;
	int menu = 0;

	//variáveis de cadastro
	char produto[100][30] = {0};
	char descontoP;
	char perguntaA;
	char perguntaM;
	char novoProduto;
	float valorP[100] = {0};
	float valorCompra[100]= {0};
	float valorDesconto[100]= {0};
	float valorcomDesconto[100]= {0};
	int qtdproduto[100]= {0};
	int codigoP[100]= {0};
	int contadorProdutos = 0;
	int i;
	//variáveis de vendas
	int qtdV[100]= {0};
	char descontoA[100]= {0};
	char opcaoCompra;
	char novaV;
	float totalP[100]= {0};
	float soma = 0;
	float somasD = 0;
	float descontoT = 0;
	//variáveis de estoque
	char perguntaE;
	//variáveis de alterações
	int numeroProduto = 0;
	int alteracao = 0;
	int tipoOpera = 0;
	int qtdOpera = 0;
	char novaAlteracao;
	//variáveis de relatório
	float valorEstoqueAtual = 0;
	int totalItensVendidos = 0;
	char perguntaR;

	system("color 70");
	pisca;
	printf("\n        ==============================\033[32;107m  NEXT KM: O seu próximo KM começa aqui!  \033[30;47m=============================\n");
	printf("        ||\033[32;107m                                                                                                 \033[30;47m||");
	printf("\n        ||\033[32;107m                                      __________                                                 \033[30;47m||");
	printf("\n        ||\033[32;107m                                      |________|                                                 \033[30;47m||");
	printf("\n        ||\033[32;107m                                      |        \\                                                 \033[30;47m||");
	printf("\n        ||\033[32;107m                                      |    *    \\_________                                       \033[30;47m||");
	printf("\n        ||\033[32;107m                                      |    *     / / / / /\\                                      \033[30;47m||");
	printf("\n        ||\033[32;107m                                      |  *   *  / / / / /  \\                                     \033[30;47m||");
	printf("\n        ||\033[32;107m                                      |=====================)                                    \033[30;47m||\n");
	printf("        ||\033[32;107m                                                                                                 \033[30;47m||");
	printf("\n        ||\033[32;107m         __     __  ______  __     __  ________           _    __  __     __                     \033[30;47m||");
	printf("\n        ||\033[32;107m        |  \\   / / |  ____| \\ \\   / / |__    __|         | |  / / |  \\   /  |                    \033[30;47m||");
	printf("\n        ||\033[32;107m        |   \\_/ /  | |____   \\ \\_/ /     |  |            | |_/ /  |   \\_/   |                    \033[30;47m||");
	printf("\n        ||\033[32;107m        | |\\   /   |  ____|   | _ |      |  |            |  _ |   | |\\   /| |                    \033[30;47m||");
	printf("\n        ||\033[32;107m        | | \\_/    | |____   / / \\ \\     |  |            | | \\ \\  | | \\_/ | |                    \033[30;47m||");
	printf("\n        ||\033[32;107m        |_|        |______| /_/   \\_\\    |__|            |_|  \\_\\ |_|     |_|                    \033[30;47m||");
	printf("\n        ||\033[32;107m                                                                                                 \033[30;47m||\n");
	printf("        ||\033[32;107m                                                                                                 \033[30;47m||");
	fim;
	printf("\033[30;47m");

	do {
		printf("\n\t===========================================   MENU   ================================================");
		printf("\n\t||                                                                                                 ||");
		printf("\n\t||\t=========================== Escolha a opção desejada =========================             ||");
		printf("\n\t||\t||                                                                          ||             ||");
		printf("\n\t||\t||                                                                          ||             ||");
		printf("\n\t||\t|| 1- Cadastro ");
		printf(" 2- Vendas ");
		printf(" 3- Estoque ");
		printf(" 4- Alterações ");
		printf(" 5- Relatório ");
		printf(" 6- Sair ||\t           ||");
		printf("\n\t||\t||                                                                          ||             ||\n");
		printf("\t||\t||                                 Opção: ");
		scanf("%i",&menu);
		printf("\t||\t||                                                                          ||             ||\n");
		printf("\t||\t||==========================================================================||             ||\n");

		switch(menu) {
		case 1: { //Cadastro
			printf("        ||                                                                                                 ||\n");
			printf("\t||==========================================  Cadastro  ===========================================||\n");
			do {
				printf("\t||                                                                                                 ||\n");
				printf("\t||                                                                                                 ||\n");
				printf("\t||\t\t|  Nome do produto: ");
				scanf(" %29[^\n]",produto[contadorProdutos]);

				printf("\t||                                                                                                 ||\n");
				printf("\t||\t\t|  Valor de compra do produto: R$");
				scanf("%f",&valorCompra[contadorProdutos]);

				printf("\t||                                                                                                 ||\n");
				printf("\t||\t\t|  Código do produto:");
				scanf("%i",&codigoP[contadorProdutos]);

				printf("        ||                                                                                                 ||\n");
				printf("\t||\t\t|  Quantidade do produto: ");
				scanf("%i",&qtdproduto[contadorProdutos]);

				printf("        ||                                                                                                 ||\n");
				printf("\t||\t\t|  Valor do produto: R$");
				scanf("%f",&valorP[contadorProdutos]);

				printf("        ||                                                                                                 ||\n");
				printf("\t||\t\t|  Produto possui desconto? S-[SIM] / N-[NÃO] ");
				scanf(" %c",&descontoP);


				if(descontoP == 'S' || descontoP =='s') {
					printf("        ||                                                                                                 ||\n");
					printf("\t||\t\t|  Insira o valor do desconto em porcentagem: ");
					scanf("%f",&valorDesconto[contadorProdutos]);

					if(valorDesconto[contadorProdutos] > 0) {
						valorcomDesconto[contadorProdutos] = valorP[contadorProdutos]	- (valorP[contadorProdutos] * (valorDesconto[contadorProdutos]/100.0)	);
						printf("        ||                                                                                                 ||\n");
						printf("\t||\t\t|  O valor do produto com desconto é de R$%.2f\n",valorcomDesconto[contadorProdutos]);
					} else {
						valorDesconto[contadorProdutos] = 0;
						valorcomDesconto[contadorProdutos] = valorP[contadorProdutos];
					}
				} else {
					valorDesconto[contadorProdutos] = 0;
					valorcomDesconto[contadorProdutos] = valorP[contadorProdutos];
				}

				contadorProdutos++;

				printf("        ||                                                                                                 ||\n");
				printf("\t||\t\t|  Deseja cadastrar um novo produto? S-[SIM] / N-[NÃO] ");
				scanf(" %c",&novoProduto);
				//printf("\t||\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t \t\t\t   ||");
			} while(novoProduto == 's' || novoProduto == 'S');
			printf("        ||                                                                                                 ||\n");
			break;
		}
		case 2: { //Vendas

			printf("        ||                                                                                                 ||\n");
			printf("\t||==========================================    Vendas    =========================================||\n");
			printf("        ||                                                                                                 ||\n");
			do {
				printf("        ||                                                                                                 ||\n");

				for(i=0; i<contadorProdutos; i++) {
					printf("\t||                                                                                                 ||\n");
					printf("\t||\t\t|  Produto nº %i:                                                                   ||",i+1);
					printf("\n\t||                                                                                                 ||\n");
					printf("\t||\t\t\t| Produto: %s ",produto[i]);
					printf("\n\t||\t\t\t| Valor de compra do produto: R$%.2f", valorCompra[i]);
					printf("\n\t||\t\t\t| Código do produto: %i ",codigoP[i]);
					printf("\n\t||\t\t\t| Quantidade do produto: %i ",qtdproduto[i]);
					printf("\n\t||\t\t\t| Valor do produto: R$%.2f", valorP[i]);
					printf("\n\t||\t\t\t| Desconto do produto: %.2f ", valorDesconto[i]);
					printf("\n\t||\t\t\t| Valor do produto com desconto: R$%.2f ", valorcomDesconto[i]);
					printf("\n\t||                                                                                                 ||\n");
				}

				do {
					printf("\t||                                                                                                 ||\n");
					printf("\t||\t\t\t| Digite o número de série do produto: ");
					scanf("%i",&numeroProduto);
					printf("\t||                                                                                                 ||\n");
					numeroProduto--;

					if( numeroProduto >= 0 && numeroProduto < contadorProdutos ) {
						do {
							printf("\t||                                                                                                 ||\n");
							printf("\t||\t\t\t| Insira a quantidade do produto que foi vendida: ");
							scanf("%i",&qtdV[numeroProduto]);
							printf("\t||                                                                                                 ||\n");
							if (qtdV[numeroProduto] > qtdproduto[numeroProduto]) {
								printf("\t||                                                                                                 ||\n");
								printf("\t||\t\t\t\033[33m O produto selecionado não apresenta estoque disponível no momento.\033[30;47m\n");
								printf("\033[30;47m");
								printf("\t||                                                                                                 ||\n");
							}
						} while(qtdV[numeroProduto] > qtdproduto[numeroProduto]);
						qtdproduto[numeroProduto] = qtdproduto[numeroProduto] - qtdV[numeroProduto];
						totalItensVendidos += qtdV[numeroProduto];
						printf("\t||                                                                                                 ||\n");
						printf("\t||\t\t\t| O desconto será aplicado nesse item? S-[SIM] N-[NÃO] ");
						scanf(" %c",&descontoA[numeroProduto]);
						printf("\t||                                                                                                 ||\n");
						if(descontoA[numeroProduto] == 's' || descontoA[numeroProduto] == 'S') {

							if(valorDesconto[numeroProduto] == 0.0 || valorcomDesconto[numeroProduto] == 0.0) {
								totalP[numeroProduto] = qtdV[numeroProduto] * valorP[numeroProduto] ;
								printf("\t||                                                                                                 ||\n");
								printf("\t||\t\t\t| Total a pagar: R$%.2f \n",totalP[numeroProduto]);

							} else {
								totalP[numeroProduto] = qtdV[numeroProduto] * valorcomDesconto[numeroProduto];
								printf("\t||                                                                                                 ||\n");
								printf("\t||\t\t\t| Total a pagar: R$%.2f \n",totalP[numeroProduto]);
							}

						} else if( descontoA[numeroProduto] == 'n' || descontoA[numeroProduto] == 'N') {

							totalP[numeroProduto] = qtdV[numeroProduto] * valorP[numeroProduto] ;
							printf("\t||                                                                                                 ||\n");
							printf("\t||\t\t\t| Total a pagar: R$%.2f \n",totalP[numeroProduto]);

						} else {
							totalP[numeroProduto] = qtdV[numeroProduto] * valorP[numeroProduto] ;
							printf("\t||                                                                                                 ||\n");
							printf("\t||\t\t\t| Total a pagar: R$%.2f  \n",totalP[numeroProduto]);
						}
						soma = soma + totalP[numeroProduto];
						somasD = somasD + (qtdV[numeroProduto] * valorP[numeroProduto]);
					} else {
						printf("\t||                                                                                                 ||\n");
						printf("\t||\t\t\t| \033[33mProduto não cadastrado.\033[30;47m");
						printf("\n\t||                                                                                                 ||\n");
					}
					printf("\t||                                                                                                 ||\n");
					printf("\t||\t\t\t| Selecione o que deseja:                                                  || \n\t||\t\t\t  [F]-Finalizar venda                                                      || \n\t||\t\t\t  [A]-Começar outra venda                                                  || \n\t||\t\t\t");

					scanf(" %c",&opcaoCompra);
					printf("\t||                                                                                                 ||\n");
				} while( opcaoCompra == 'a' || opcaoCompra == 'A');
				printf("\t||                                                                                                 ||\n");
				printf("\t||\t\t\t| O valor total da venda diária foi de: R$%2.f \n",soma);
				descontoT = somasD - soma;
				printf("\t||                                                                                                 ||\n");
				printf("\t||\t\t\t| O desconto total da venda diária foi de: R$%2.f \n",descontoT);

				printf("\t||                                                                                                 ||\n");
				printf("\t||\t\t\t| Deseja abrir uma nova lista de vendas? S-[SIM] N-[NÃO] ");
				scanf(" %c",&novaV);
			} while( novaV == 's' || novaV == 'S');
			printf("\t||                                                                                                 ||\n");
			break;
		}
		case 3: { //Estoque

			printf("\t||                                                                                                 ||\n");
			printf("\t||========================================    Estoque     =========================================||\n");
			printf("\t||                                                                                                 ||\n");

			do {
				printf("\t||\t\t\t  Produtos cadastrados: ");

				for(i=0; i<contadorProdutos; i++) {
					printf("\n\t||                                                                                                 ||\n");
					printf("\t||\t\t|  Produto nº %i:                                                                   ||",i+1);
					printf("\n\t||                                                                                                 ||\n");
					printf("\t||\t\t\t| Produto: %s ",produto[i]);
					printf("\n\t||\t\t\t| Valor de compra do produto: R$%.2f", valorCompra[i]);
					printf("\n\t||\t\t\t| Código do produto: %i ",codigoP[i]);
					printf("\n\t||\t\t\t| Quantidade do produto: %i ",qtdproduto[i]);
					printf("\n\t||\t\t\t| Valor do produto: R$%.2f", valorP[i]);
					printf("\n\t||\t\t\t| Desconto do produto: %.2f ", valorDesconto[i]);
					printf("\n\t||\t\t\t| Valor do produto com desconto: R$%.2f ", valorcomDesconto[i]);
					printf("\n\t||                                                                                                 ||");
				}

				printf("\n\t||                                                                                                 ||");
				printf("\n\t||\t\t\t| Digite o número de série do produto: ");
				scanf("%i",&numeroProduto);
				printf("\t||                                                                                                 ||\n");
				numeroProduto--;

				if( numeroProduto >= 0 && numeroProduto < contadorProdutos ) {
					printf("\t||\t\t\t|  O que você deseja fazer no estoque?:\n\t||\t\t\t\t|  1- Acréscimo da quantidade de produtos disponíveis\n\t||\t\t\t\t|  2- Decréscimo da quantidade de produtos  disponíveis\n\t||\t\t\t\t|  ");
					scanf("%i",&tipoOpera);
					printf("\t||                                                                                                 ||\n");
					switch(tipoOpera) {
					case 1: {
						printf("\t||\t\t\t|  Qual a quantidade de produtos que você deseja acrescentar? ");
						scanf("%i",&qtdOpera);
						printf("\t||                                                                                                 ||\n");
						qtdproduto[numeroProduto] = qtdproduto[numeroProduto] + qtdOpera;
						break;
					}
					case 2: {
						printf("\t||\t\t\t|  Qual a quantidade de produtos que você deseja subtrair? ");
						scanf("%i",&qtdOpera);
						printf("\t||                                                                                                 ||\n");

						qtdproduto[numeroProduto] = qtdproduto[numeroProduto] - qtdOpera;
						break;
					}
					}
					printf("\t||\t\t\t  PRODUTOS APÓS MOVIMENTAÇÃO NO ESTOQUE:                            ||\n");
					for(i=0; i<contadorProdutos; i++) {
						printf("\t||                                                                                                 ||\n");
						printf("\t||\t\t|  Produto nº %i:                                                                   ||",i+1);
						printf("\n\t||                                                                                                 ||\n");
						printf("\t||\t\t\t| Produto: %s ",produto[i]);
						printf("\n\t||\t\t\t| Valor de compra do produto: R$%.2f", valorCompra[i]);
						printf("\n\t||\t\t\t| Código do produto: %i ",codigoP[i]);
						printf("\n\t||\t\t\t| Quantidade do produto: %i ",qtdproduto[i]);
						printf("\n\t||\t\t\t| Valor do produto: R$%.2f", valorP[i]);
						printf("\n\t||\t\t\t| Desconto do produto: %.2f ", valorDesconto[i]);
						printf("\n\t||\t\t\t| Valor do produto com desconto: R$%.2f ", valorcomDesconto[i]);
						printf("\n\t||                                                                                                 ||\n");
					}
				}


				printf("\t||\t\t\t|  Deseja realizar mais alguma alteração no estoque? \n\t||\t\t\t\t|  S-[SIM] / N-[NÃO] ");
				scanf(" %c",&perguntaE);
			} while(perguntaE == 's' || perguntaE == 'S');
			printf("\t||                                                                                                 ||\n");
			break;
		}
		case 4: { //Alterações
			printf("\t||                                                                                                 ||\n");
			printf("\t||========================================   Alterações   ========================================||\n");
			printf("\t||                                                                                                 ||\n");
			do {
				int i =0;
				for(i=0; i<contadorProdutos; i++) {
					printf("\t||                                                                                                 ||\n");
					printf("\t||\t\t|  Produto nº %i:                                                                   ||",i+1);
					printf("\n\t||                                                                                                 ||\n");
					printf("\t||\t\t\t| Produto: %s ",produto[i]);
					printf("\n\t||\t\t\t| Valor de compra do produto: R$%.2f", valorCompra[i]);
					printf("\n\t||\t\t\t| Código do produto: %i ",codigoP[i]);
					printf("\n\t||\t\t\t| Quantidade do produto: %i ",qtdproduto[i]);
					printf("\n\t||\t\t\t| Valor do produto: R$%.2f", valorP[i]);
					printf("\n\t||\t\t\t| Desconto do produto: %.2f ", valorDesconto[i]);
					printf("\n\t||\t\t\t| Valor do produto com desconto: R$%.2f ", valorcomDesconto[i]);
					printf("\n\t||                                                                                                 ||\n");
				}
				printf("\t||                                                                                                 ||\n");
				printf("\t||\t\t\t|  Qual o nº do produto que você deseja realizar a alteração? ");
				scanf("%i",&numeroProduto);
				printf("\t||                                                                                                 ||\n");
				numeroProduto--;

				if(numeroProduto >= 0 && numeroProduto < contadorProdutos) {
					do {
						printf("\t||\t\t\t|  O que você deseja alterar?\n\t||\t\t\t\t|  [1]-Nome do produto\n\t||\t\t\t\t|  [2]-Valor de compra do produto\n\t||\t\t\t\t|  [3]-Código do produto\n\t||\t\t\t\t|  [4]-Quantidade do produto\n\t||\t\t\t\t|  [5]-Valor do produto\n\t||\t\t\t\t|  [6]-Desconto do produto\n\t||\t\t\t\t|  ");
						scanf("%i",&alteracao);
						printf("\t||                                                                                                 ||");


						if(alteracao == 1) {
							printf("\n\t||\t\t\t|  Insira o novo nome do produto: ");

							scanf(" %29[^\n]",produto[numeroProduto]);
							printf("\t||                                                                                                 ||\n");
						} else if(alteracao == 2) {
							printf("\n\t||\t\t\t|  Insira o novo valor de compra do produto: R$");
							scanf("%f",&valorCompra[numeroProduto]);
							printf("\t||                                                                                                 ||\n");
						} else if(alteracao == 3) {
							printf("\n\t||\t\t\t|  Insira o novo código do produto: ");
							scanf("%i",&codigoP[numeroProduto]);
							printf("\t||                                                                                                 ||\n");
						} else if (alteracao == 4) {
							printf("\n\t||\t\t\t|  Você deseja fazer:\n\t||\t\t\t|  1- Adição da quantidade de produtos\n\t||\t\t\t|  2-Subtração da quantidade de produtos ");
							scanf("%i",&tipoOpera);
							printf("\t||                                                                                                 ||\n");

							switch(tipoOpera) {
							case 1: {
								printf("\t||\t\t\t|  Qual a quantidade de produtos que você deseja somar aos produtos existentes? ");
								scanf("%i",&qtdOpera);
								printf("\t||                                                                                                 ||\n");
								qtdproduto[numeroProduto] = qtdproduto[numeroProduto] + qtdOpera;
								break;
							}
							case 2: {
								printf("\t||\t\t\t|  Qual a quantidade de produtos que você deseja subtrair aos produtos existentes? ");
								scanf("%i",&qtdOpera);
								printf("\t||                                                                                                 ||\n");

								qtdproduto[numeroProduto] = qtdproduto[numeroProduto] - qtdOpera;
								break;
							}
							}
						} else if ( alteracao == 5) {
							printf("\n\t||\t\t\t|  Insira o novo valor do produto: R$");
							scanf("%f",&valorP[numeroProduto]);
							valorcomDesconto[numeroProduto] = valorP[numeroProduto] - (valorP[numeroProduto] * (valorDesconto[numeroProduto] / 100.0));
							printf("\t||                                                                                                 ||\n");
						} else if ( alteracao == 6) {
							printf("\n\t||\t\t\t|  Insira o novo desconto em porcentagem do produto: ");
							scanf("%f",&valorDesconto[numeroProduto]);
							valorcomDesconto[numeroProduto] = valorP[numeroProduto] - (valorP[numeroProduto] * (valorDesconto[numeroProduto] / 100.0));
							printf("\t||                                                                                                 ||\n");

						}
						printf("\t||\t\t\t|  Deseja realizar a alteração em mais algum item do produto (%s) ?\n\t||\t\t\t| S-[SIM] / N-[NÃO] ",produto[numeroProduto]);
						scanf(" %c", &novaAlteracao);
						printf("\t||                                                                                                 ||\n");
					} while(novaAlteracao == 's' || novaAlteracao == 'S');
				} else {
					printf("\t||                                                                                                 ||\n");
					printf("\t||\t\t\t|  \033[33mNão foi possível encontrar o produto desejado, por favor insira a numeração do produto correta...\033[30;47m");
					printf("\n\t||                                                                                                 ||\n");
				}

				printf("\t||                                                                                                 ||\n");
				printf("\t||\t\t\t|  Deseja realizar outra movimentação nos produtos?  S-[SIM] / N-[NÃO] ");
				scanf(" %c",&perguntaM);
				printf("\t||                                                                                                 ||\n");

			} while(perguntaM == 's' || perguntaM == 'S');
			break;
		}
		case 5: { //Relatório
			printf("\t||                                                                                                 ||\n");
			printf("\t||========================================    Relatório   =========================================||\n");
			printf("\t||                                                                                                 ||\n");
			valorEstoqueAtual = 0;
			for(i = 0; i < contadorProdutos; i++) {
				if(qtdproduto[i] <= 10) {
					printf("\t||  \033[31m O estoque não possui quantidade suficiente de %s disponíveis!\033[30;47m \n\t||\t|\033[31m É recomendado fazer o pedido de novos produtos o quanto antes.\033[30;47m\n", produto[i]);
					printf("\t||                                                                                                 ||\n");
				}
			}

			printf("\t||                                                                                                 ||\n");
			for(i=0; i<contadorProdutos; i++) {
				valorEstoqueAtual = valorEstoqueAtual + (valorP[i] * qtdproduto[i]);
			}
			printf("\t||  \033[32mO valor monetário do estoque atual é de : R$%.2f\033[30;47m", valorEstoqueAtual);
			printf("\n\t||                                                                                                 ||\n");

			printf("\t||                                                                                                 ||\n");
			printf("\t||  \033[33mA quantidade total de itens vendidos foram %i\033[30;47m", totalItensVendidos);
			printf("\n\t||                                                                                                 ||\n");

			printf("\n\t||  Deseja visualizar a relação completa, com todas as informações dos produtos atualizadas?\n\t||   S-[SIM] N-[NÃO] ");
			scanf(" %c",&perguntaR);
			printf("\t||                                                                                                 ||\n");

			if (perguntaR == 's' || perguntaR == 'S') {
				for(i=0; i<contadorProdutos; i++) {
					printf("\t||                                                                                                 ||\n");
					printf("\t||\t\t|  Produto nº %i:                                                                   ||",i+1);
					printf("\n\t||                                                                                                 ||\n");
					printf("\t||\t\t\t| Produto: %s ",produto[i]);
					printf("\n\t||\t\t\t| Valor de compra do produto: R$%.2f", valorCompra[i]);
					printf("\n\t||\t\t\t| Código do produto: %i ",codigoP[i]);
					printf("\n\t||\t\t\t| Quantidade do produto: %i ",qtdproduto[i]);
					printf("\n\t||\t\t\t| Valor do produto: R$%.2f", valorP[i]);
					printf("\n\t||\t\t\t| Desconto do produto: %.2f ", valorDesconto[i]);
					printf("\n\t||\t\t\t| Valor do produto com desconto: R$%.2f ", valorcomDesconto[i]);
					printf("\n\t||                                                                                                 ||\n");
				}
			}
			break;
		}

		case 6: { //Sair
			printf("\t||                                                                                                 ||\n");
			printf("\t||=============================================   Sair  ===========================================||\n");
			printf("\t||                                                                                                 ||\n");
			break;
		}
		default: {
			printf("\t||                                                                                                 ||");
		}
		}
		printf("\t||                                                                                                 ||\n");
		printf("\t||\t\t\tDeseja visualizar o MENU novamente?  S-[SIM] / N-[NÃO] ");
		scanf(" %c",&entrarMenu);
		printf("\t||                                                                                                 ||\n");
		printf("\t||                                                                                                 ||\n");
		printf("\t||                                                                                                 ||\n");

	} while(entrarMenu == 'S' || entrarMenu == 's');
	pisca;
	printf("        ==============================\033[32;107m  NEXT KM: O seu próximo KM começa aqui!  \033[30;47m=============================\n");
	printf("\t||                                                                                                 ||\n");
	printf("        ||===============================   \033[32;107m\251 COPYRIGHT NEXT KM 2026\033[30;47m   ====================================||\n");
	printf("\t||                                                                                                 ||");
	printf("\n        ||\033[32;107m                                      __________                                                 \033[30;47m||");
	printf("\n        ||\033[32;107m                                      |________|                                                 \033[30;47m||");
	printf("\n        ||\033[32;107m                                      |        \\                                                 \033[30;47m||");
	printf("\n        ||\033[32;107m                                      |    *    \\_________                                       \033[30;47m||");
	printf("\n        ||\033[32;107m                                      |    *     / / / / /\\                                      \033[30;47m||");
	printf("\n        ||\033[32;107m                                      |  *   *  / / / / /  \\                                     \033[30;47m||");
	printf("\n        ||\033[32;107m                                      |=====================)                                    \033[30;47m||\n");
	printf("        ||\033[32;107m                                                                                                 \033[30;47m||");
	printf("\n        ||\033[32;107m         __     __  ______  __     __  ________           _    __  __     __                     \033[30;47m||");
	printf("\n        ||\033[32;107m        |  \\   / / |  ____| \\ \\   / / |__    __|         | |  / / |  \\   /  |                    \033[30;47m||");
	printf("\n        ||\033[32;107m        |   \\_/ /  | |____   \\ \\_/ /     |  |            | |_/ /  |   \\_/   |                    \033[30;47m||");
	printf("\n        ||\033[32;107m        | |\\   /   |  ____|   | _ |      |  |            |  _ |   | |\\   /| |                    \033[30;47m||");
	printf("\n        ||\033[32;107m        | | \\_/    | |____   / / \\ \\     |  |            | | \\ \\  | | \\_/ | |                    \033[30;47m||");
	printf("\n        ||\033[32;107m        |_|        |______| /_/   \\_\\    |__|            |_|  \\_\\ |_|     |_|                    \033[30;47m||");
	printf("\n        ||\033[32;107m                                                                                                 \033[30;47m||\n");
	printf("        ||\033[32;107m                                                                                                 \033[30;47m||\n");
	fim;

	printf("\033[30;47m");
	printf("        =====================================================================================================\n");

	return 0 ;
}