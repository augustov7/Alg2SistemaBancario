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

	novo_atendimento->data.dia = data_hora_atual->tm_mday;
	novo_atendimento->data.mes = data_hora_atual->tm_mon+1;
	novo_atendimento->data.ano = data_hora_atual->tm_year+1900;

	novo_atendimento->ant = NULL;
	novo_atendimento->prox = NULL;

	novo_atendimento->senha = 1;

	//strcpy(novo_atendimento->data,'01');
	//novo_atendimento->data = '1';

	novo_atendimento->preferencial = 'N';

	printf("\nPossui CONTA NESSE BANCO ?  S OU N");
	scanf(" %c", &possui_conta);
	


	if (possui_conta == 's' || possui_conta == 'S'){

		printf("\nInforme o CPF: ");
		scanf(" %[^\n]",cpf_conta);

		printf("\nInforme o NUMERO DA CONTA: ");
		scanf(" %[^\n]",numero_conta);	

		novo_atendimento->preferencial = pesquisar_cpf_preferencial(lst_contas,cpf_conta,numero_conta);

		printf("%c", novo_atendimento->preferencial);

		if (novo_atendimento == NULL){
			printf("\n conta invalida");
		}else{

			printf("\nInforme o TIPO DE ATENDIMENTO: MESA = M OU CAIXA = C: \n");

			scanf(" %c", &atendimento);	

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
		
		printf("\nInforme o TIPO DE ATENDIMENTO: MESA = M OU CAIXA = C :");
		scanf(" %[^\n]",&atendimento);

		if(atendimento == 'm' || atendimento == 'M'){

			puts("inserindo senha mesa sem conta");
			
			/*struct tm *data_hora_atual;     
			time_t segundos;
			time(&segundos);     
			data_hora_atual = localtime(&segundos);  

			printf("\n %d/%d/%d - %c \n", data_hora_atual->tm_mday,data_hora_atual->tm_mon+1,data_hora_atual->tm_year+1900, novo_atendimento->preferencial);
			*/
			inserir_senha(lst_mesa,novo_atendimento);

		}else{
			if (atendimento == 'c' || atendimento == 'C')
			{
				/* code */
			}
			puts("inserindo senha CAIXA sem conta");

			//printf("\n DATA: %d/%d/%d \n SENHA: %c-%d \n", data_hora_atual->tm_mday,data_hora_atual->tm_mon+1,data_hora_atual->tm_year+1900, novo_atendimento->preferencial,novo_atendimento->senha);

			
			inserir_senha(lst_caixa,novo_atendimento);
		}
	}

	system("PAUSE");

	
}

void inserir_senha(fila_atendimento **lst_atendimento, fila_atendimento *novo_atendimento){
	
	
	fila_atendimento *percorre_lista;

	percorre_lista = *lst_atendimento;



	if (*lst_atendimento == NULL){
		
		*lst_atendimento = novo_atendimento;
		puts("primeira posição");

	}else{

		// N DE NÃO PREFERENCIAL
		if(novo_atendimento->preferencial == 'n' || novo_atendimento->preferencial == 'N'){
			
			puts("teste 01");

			while(percorre_lista->prox != NULL){				
				percorre_lista = percorre_lista->prox;
			}

			novo_atendimento->senha += percorre_lista->senha;
			printf("%d\n", novo_atendimento->senha );
			percorre_lista->prox = novo_atendimento;
			puts("Segunda posição");
			system("pause");

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