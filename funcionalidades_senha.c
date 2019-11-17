#include "menu.h"

void registra_senha(fila_atendimento **lst_caixa, fila_atendimento **lst_mesa, conta *lst_contas){
	
	char possui_conta;
	char cpf_conta[15];
	char atendimento;
	char numero_conta[15];
	struct tm *data_hora_atual;     
	time_t segundos;

	fila_atendimento *novo_atendimento = (fila_atendimento*) malloc(sizeof(fila_atendimento));

	time(&segundos);     
	data_hora_atual = localtime(&segundos);

	/* SETANDO VALORES DENTRO DE UM NOVO ATENDIMENTO*/

	novo_atendimento->data.dia = data_hora_atual->tm_mday;
	novo_atendimento->data.mes = data_hora_atual->tm_mon+1;
	novo_atendimento->data.ano = data_hora_atual->tm_year+1900;
	novo_atendimento->ant = NULL;
	novo_atendimento->prox = NULL;
	novo_atendimento->senha = 1;


	novo_atendimento->preferencial = 'N';

	printf("\nPossui CONTA NESSE BANCO ?  S OU N");
	scanf(" %c", &possui_conta);
	


	if (possui_conta == 's' || possui_conta == 'S'){

		printf("\nInforme o CPF: ");
		scanf(" %[^\n]",cpf_conta);

		printf("\nInforme o NUMERO DA CONTA: ");
		scanf(" %[^\n]",numero_conta);	

		/* RETORNA SE A CONTA É PREFERENCIAL */
		novo_atendimento->preferencial = pesquisar_cpf_preferencial(lst_contas,cpf_conta,numero_conta);

		//printf("%c", novo_atendimento->preferencial);

		if (novo_atendimento == NULL){
			printf("\n conta invalida");
		}else{

			printf("\nInforme o TIPO DE ATENDIMENTO: MESA = M OU CAIXA = C: \n");

			scanf(" %c", &atendimento);	

			if(atendimento == 'm' || atendimento == 'M'){

				puts("inserindo senha mesa");

				novo_atendimento->tipo_fila = atendimento;
				inserir_senha(lst_mesa,novo_atendimento);

			}else{

				if(atendimento == 'c' || atendimento == 'C'){
					puts("inserindo senha CAIXA");				
					novo_atendimento->tipo_fila = atendimento;

					printf("preferencial: %c\n", novo_atendimento->preferencial);

					inserir_senha(lst_caixa,novo_atendimento);
					system("pause");
				}

			}
		}
	}else{
		
		printf("\nInforme o TIPO DE ATENDIMENTO: MESA = M OU CAIXA = C :");
		scanf(" %[^\n]",&atendimento);

		if(atendimento == 'm' || atendimento == 'M'){

			puts("inserindo senha mesa sem conta");
			inserir_senha(lst_mesa,novo_atendimento);

		}else{
			if (atendimento == 'c' || atendimento == 'C'){
				
				
				novo_atendimento->tipo_fila = 'C';

				puts("inserindo senha CAIXA sem conta");

				inserir_senha(lst_caixa,novo_atendimento);
			}
			
		}
	}

	system("PAUSE");

	
}

void inserir_senha(fila_atendimento **lst_atendimento, fila_atendimento *novo_atendimento){
	
	
	fila_atendimento *percorre_lista;

	percorre_lista = *lst_atendimento;



	if (*lst_atendimento == NULL){
		
		novo_atendimento->senha=1;
		*lst_atendimento = novo_atendimento;
		puts("primeira posição");

	}else{

		// N DE NÃO PREFERENCIAL
		if(novo_atendimento->preferencial == 'n' || novo_atendimento->preferencial == 'N'){
			
			while(percorre_lista->prox != NULL){				
				
				percorre_lista = percorre_lista->prox;

			}

			if (percorre_lista->preferencial == 'n' || percorre_lista->preferencial == 'N'){
				novo_atendimento->senha = percorre_lista->senha + 1;
			}
			
			percorre_lista->prox = novo_atendimento;
			novo_atendimento->ant = percorre_lista;

		}else{
			/* ENTRARA NESSE ELSE QUANDO O NOVO ATENDIMENTO FOR ATENDIMENTO PREFERENCIAL*/

			/* EU VERIFICO SE O PRIMEIRO ATENDIMENTO É PREFERENCIAL */
			if (percorre_lista->preferencial == 'n' || percorre_lista->preferencial == 'N'){
				
				puts("não preferencial no primeiro");
				novo_atendimento->prox = percorre_lista;
				percorre_lista->ant = novo_atendimento;
				*lst_atendimento = novo_atendimento;

				
			}else{
				while((percorre_lista->preferencial == 's' || percorre_lista->preferencial == 'S' )&& percorre_lista->prox != NULL )
					percorre_lista = percorre_lista->prox;

				if (percorre_lista->preferencial == 'n' || percorre_lista->preferencial == 'N'){

					/* INSERE NO FINAL DOS PREFERENCIAIS */

					novo_atendimento->prox = percorre_lista;
					percorre_lista->ant->prox = novo_atendimento;
					novo_atendimento->ant = percorre_lista->ant;
					percorre_lista->ant = novo_atendimento;

					novo_atendimento->senha = novo_atendimento->ant->senha + 1;

				}else{

					novo_atendimento->ant = percorre_lista;
					percorre_lista->prox = novo_atendimento;
					novo_atendimento->senha = percorre_lista->senha + 1;

				}

			}
		}
	}

}

int compara_data(data_senha data01, data_senha data02){
	
	if(data01.dia == data02.dia){
		if(data01.mes == data02.mes){
			if(data01.ano == data02.ano){
				return 1;
			}
		}
	}	
	
	return 0;
}