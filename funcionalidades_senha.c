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

	limpar();

	printf("\nPossui CONTA NESSE BANCO ?  S OU N");
	scanf(" %c", &possui_conta);
	


	if (possui_conta == 's' || possui_conta == 'S'){

		printf("\nInforme o CPF: ");
		scanf(" %[^\n]",cpf_conta);

		printf("\nInforme o NUMERO DA CONTA: ");
		scanf(" %[^\n]",numero_conta);	

		/* RETORNA SE A CONTA É PREFERENCIAL */
		novo_atendimento->preferencial = pesquisar_cpf_preferencial(lst_contas,cpf_conta,numero_conta);

		if (novo_atendimento->preferencial == 'R'){
			printf("\n CONTA INVALIDA!!!");
			free(novo_atendimento);
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

void inserir_senha(fila_atendimento **lst_inicio, fila_atendimento **lst_final, fila_atendimento *novo_atendimento){	
	
	fila_atendimento *percorre_lista;

	percorre_lista = *lst_inicio;

	if (*lst_inicio == NULL){
		
		novo_atendimento->senha=1;
		*lst_inicio = novo_atendimento;
		*lst_final = novo_atendimento;

		puts("primeira posição");

	}else{

		// N DE NÃO PREFERENCIAL
		if(novo_atendimento->preferencial == 'n' || novo_atendimento->preferencial == 'N'){
			
			if (lst_final->preferencial == 'n' || lst_final->preferencial == 'N'){
				
				if(compara_data(lst_final->data,novo_atendimento->data) == 1){
					novo_atendimento->senha = lst_final->senha + 1;
				}else{
					novo_atendimento->senha = 1;	
				}
				
			}
			
			lst_final->prox = novo_atendimento;
			novo_atendimento->ant = lst_final;
			lst_final = lst_final->prox;

		}else{
			/* ENTRARA NESSE ELSE QUANDO O NOVO ATENDIMENTO FOR ATENDIMENTO PREFERENCIAL*/

			/* EU VERIFICO SE O PRIMEIRO OU ULTIMO ATENDIMENTO É NÃO É PREFERENCIAL */

			if (lst_inicio->preferencial == 'n' || lst_inicio->preferencial == 'N'){
				
				if (lst_inicio->preferencial == 'n' || lst_inicio->preferencial == 'N' || ){

					novo_atendimento->prox = lst_inicio;
					lst_inicio->ant = novo_atendimento;
					*lst_inicio = novo_atendimento;

				}				
				
			}else{


				/* ENTRA NESSE IF CASO TODOS OS ATENDIMENTOS FOREM PREFERENCIAIS PARA EVITAR
				 FICAR PERCORRENDO SEMPRE A  LISTA*/

				if(lst_final>preferencial == 's' || lst_final->preferencial == 's'){

					/* CASO A DATA DA ULTIMA SENHA FOR A ATUAL ELE ADICIONA +1 A SENHA, 
					SENÃO ELE RESETA A CONTAGEM SENHA  */
					if (compara_data(lst_final->data, novo_atendimento->data) == ){

						novo_atendimento->senha = lst_final->senha + 1;

						novo_atendimento->ant = lst_inicio;
						lst_final->prox = novo_atendimento;
						*lst_inicio = novo_atendimento;

					}else{

						novo_atendimento->ant = lst_inicio;
						lst_final->prox = novo_atendimento;
						*lst_inicio = novo_atendimento;

					}

				}else{

					/* O WHILE IRA PARAR QUANDO ENCONTRAR O PRIMEIRO ATENDIMENTO NÃO PREFERENCIAL, 
					SEI QUE EXISTE ATENDIMENTOS NÃO PREFERENCIAL POIS NÃO ENTROU NO ULTIMO IF */
					while(percorre_lista->preferencial == 's' || percorre_lista->preferencial == 'S'  )
						percorre_lista = percorre_lista->prox;

					
					if (percorre_lista->preferencial == 'n' || percorre_lista->preferencial == 'N'){

					/* INSERE NO FINAL DOS PREFERENCIAIS */

						if(compara_data(percorre_lista->ant->data,novo_atendimento->data) == 1){
							novo_atendimento->senha = percorre_lista->ant->senha + 1;
						}else{
							novo_atendimento->senha = 1;	
						}

						novo_atendimento->prox = percorre_lista;
						percorre_lista->ant->prox = novo_atendimento;
						novo_atendimento->ant = percorre_lista->ant;
						percorre_lista->ant = novo_atendimento;
					}					

				}
/*
				else{

					novo_atendimento->ant = percorre_lista;
					percorre_lista->prox = novo_atendimento;

					if(compara_data(percorre_lista->data,novo_atendimento->data) == 1){
						novo_atendimento->senha = percorre_lista->senha + 1;
					}else{
						novo_atendimento->senha = 1;	
					}
					*/

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

void retirar_senha(fila_atendimento **lst){

	fila_atendimento *aux;

	aux = *lst;

	if(aux == NULL){
		limpar();
		puts("FILA VAZIA");
		pausa();
	}else{
		
		limpar();
		printf("Senha: %c-%d ", aux->preferencial, aux->senha);
		printf("\nData: %d/%d/%d \n", aux->data.dia,aux->data.mes,aux->data.ano);						

		*lst = aux->prox;
		free(aux);
		pausa();
	}
}