#include "menu.h"

/* 
CD C:\Users\Augusto\Desktop\Trab\Alg2SistemaBancario

gcc *.c -o trab.exe -pedantic -Wall 

*/

int main(){
	
	char op, subop;

	cliente *lista_clientes;
	conta *lista_contas;


	lista_clientes = NULL;
	lista_contas = NULL;

	op = menu_principal();

	/* Enquanto não pressionar 'ESC', 'S' ou 's' */
	while (op != 27 && op != 'S' && op != 's'){
		switch(op){
			case '1':
			subop = submenu1();
				/* Enquanto n�o pressionar '0' */
			while (subop != '0'){
				switch(subop){

						/* PESQUISAR CLIENTE POR CPF */
					case '1':
					
					

					break;

						/* PESQUISAR CLIENTE POR NOME */
					case '2': 

					listar_clientes(lista_clientes);
					system("PAUSE");

					break;

						/* CADASTRAR CLIENTE */
					case '3':

					cadastrar_cliente(&lista_clientes);
					system("PAUSE");

					break;

					default:
					break;
				}
				subop = submenu1();
			}
			break;

			case '2':
			subop = submenu2();

				/* Enquanto não pressionar '0' */

			while (subop != '0'){
				switch(subop){

					/* PESQUISAR CONTA POR CPF DO CLIENTE */
					case '1':

					

					break;

					/* PESQUISAR CONTA PELO NUMERO DA CONTA */
					case '2':		

					//listar_contas(lista_contas);

					break;

					/* CADASTRAR CONTA */
					case '3':		

					//cadastrar_conta(&lista_contas);

					break;
					default:
					break;
				}
				subop = submenu2();
			}
			break;

			case '3':
			subop = submenu3();
				/* Enquanto n�o pressionar '0' */
			while (subop != '0'){
				switch(subop){

					/* REGISTRAR SENHA PARA CLIENTE */
					case '1':
					


					break;

					/* EMITIR SENHA DE CLIENTE PARA O CAIXA */
					case '2':
					


					break;

					/* EMITIR SENHA DE CLIENTE PARA A MESA */
					case '3':


					break;
					default:
					break;
				}
				subop = submenu3();
			}
			break;

			default:
			break;
		}
		op = menu_principal();
	}


	printf("\n");
	gravarCliente(lista_clientes);
	return 0;
}
