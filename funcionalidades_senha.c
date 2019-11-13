#include "menu.h"

void registra_senha(fila_atendimento *lst_caixa, fila_atendimento *lst_mesa, conta *lst_contas){
	char possui_conta;
	char cpf_conta[15];
	char atendimento;
	char numero_conta[15];

	fila_atendimento *novo_atendimento = (fila_atendimento*) malloc(sizeof(fila_atendimento));

	novo_atendimento->ant = NULL;
	novo_atendimento->prox = NULL;

	novo_atendimento->senha = 1;

	//strcpy(novo_atendimento->data,'01');
	//novo_atendimento->data = '1';

	novo_atendimento->preferencial = 'N';

	printf("\nPossui CONTA NESSE BANCO ?  S OU N");
	scanf("%c",possui_conta);

	if (possui_conta == 's' || possui_conta == 'S'){

		printf("\nInforme o CPF:");
		scanf(" %[^\n]",cpf_conta);

		printf("\nInforme o NUMERO DA CONTA");
		scanf(" %[^\n]",numero_conta);	

		novo_atendimento->preferencial = pesquisar_cpf_preferencial(lst_contas,cpf_conta,numero_conta);

		if (novo_atendimento == NULL){
			printf("\n conta invalida");
		}else{

			printf("\nInforme o TIPO DE ATENDIMENTO: MESA = M OU CAIXA = C:");
			scanf(" %[^\n]",atendimento);	

			if(atendimento == 'm' || atendimento == 'M'){

				puts("inserindo senha mesa");
				printf("%c\n", atendimento);
				system("pause");
				//inserir_senha(lst_mesa,novo_atendimento);

			}else{

				puts("inserindo senha CAIXA");
				printf("%c\n", atendimento);
				system("pause");
				//inserir_senha(lst_caixa,novo_atendimento);

			}
		}
	}else{
		
		printf("\nInforme o TIPO DE ATENDIMENTO: MESA = M OU CAIXA = C:");
		scanf(" %[^\n]",numero_conta);

		if(atendimento == 'm' || atendimento == 'M'){

			puts("inserindo senha mesa sem conta");
				//inserir_senha(lst_mesa,novo_atendimento);

		}else{

			puts("inserindo senha CAIXA sem conta");
				//inserir_senha(lst_caixa,novo_atendimento);
			
		}
	}

	

	
}

void inserir_senha(fila_atendimento *lst_atendimento, fila_atendimento *novo_atendimento){
	
	fila_atendimento *percorre_lista;

	if (lst_atendimento == NULL){
		lst_atendimento = novo_atendimento;
	}else{

		// N DE NÃO PREFERENCIAL
		if(novo_atendimento->preferencial == 'n' || novo_atendimento->preferencial == 'N'){
			
			while(percorre_lista->prox != NULL){
				percorre_lista = percorre_lista->prox;
			}

			percorre_lista->prox = novo_atendimento;

		}else{
			/* ENTRARA NESSE ELSE QUANDO O NOVO ATENDIMENTO FOR ATENDIMENTO PREFERENCIAL*/

			/* EU VERIFICO SE O PRIMEIRO ATENDIMENTO É PREFERENCIAL */
			if (percorre_lista->preferencial == 'n' || percorre_lista->preferencial == 'N'){
				
				novo_atendimento->prox = percorre_lista;
				percorre_lista =novo_atendimento;
			}else{
				while((percorre_lista->preferencial == 'p' || percorre_lista->preferencial == 'P' )&& percorre_lista->prox != NULL )
					percorre_lista = percorre_lista->prox;
				
				if (percorre_lista->preferencial == 'n' || percorre_lista->preferencial == 'N'){
					
					/* INSERE NO FINAL DOS PREFERENCIAIS */

					novo_atendimento->prox = percorre_lista;
					percorre_lista->ant->prox = novo_atendimento;

				}else{

					/* CAIR AQUI QUANDO TODOS OS ATENDIMENTOS FOREM PREFERENCIAIS */

					percorre_lista->prox = novo_atendimento;

				}

			}
		}
	}

}