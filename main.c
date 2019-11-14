#include "menu.h"

/* 
CD C:\Users\Augusto\Desktop\Trab\Alg2SistemaBancario

gcc *.c -o trab.exe -pedantic -Wall
*/

int main(){
	
	char op, subop;

	cliente *lst_clientes;
	conta *lst_contas;
	fila_atendimento *lst_mesa;
	fila_atendimento *lst_caixa;


	lst_clientes = NULL;
	lst_contas = NULL;
	lst_mesa = NULL;
	lst_caixa = NULL;	


	lerClientes(&lst_clientes);
	lerContas(&lst_contas);

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
					
					listar_cliente_cpf(lst_clientes);

					break;

						/* PESQUISAR CLIENTE POR NOME */
					case '2': 

					listar_cliente_nome(lst_clientes);

					break;

						/* CADASTRAR CLIENTE */
					case '3':

					cadastrar_cliente(&lst_clientes);
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

					pesquisar_cpf_contas(lst_contas,lst_clientes);
					system("PAUSE");

					break;

					/* PESQUISAR CONTA PELO NUMERO DA CONTA */
					case '2':		

					pesquisar_numero_contas(lst_contas);

					break;

					/* CADASTRAR CONTA */
					case '3':		

					cadastrar_conta(&lst_contas);

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
					
						registra_senha(lst_caixa,lst_mesa,lst_contas);

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
	gravarCliente(lst_clientes);
	gravarConta(lst_contas);
	
	return 0;
}
