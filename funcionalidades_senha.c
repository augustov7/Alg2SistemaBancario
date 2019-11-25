#include "menu.h"

void registra_senha(fila_atendimento **lst_caixa_inicio, fila_atendimento **lst_caixa_final, fila_atendimento **lst_mesa_inicio, fila_atendimento **lst_mesa_final, conta *lst_contas, cliente *lst_clientes){
	
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
	novo_atendimento->senha = -1;


	novo_atendimento->preferencial = 'N';

	limpar();

	printf("\nPossui CONTA NESSE BANCO ?  S OU N");
	scanf(" %c", &possui_conta);
	


	if (possui_conta == 's' || possui_conta == 'S'){

		printf("\nInforme o CPF: ");
		scanf(" %[^\n]",cpf_conta);

		printf("\nInforme o NUMERO DA CONTA: ");
		scanf(" %[^\n]",numero_conta);	

		obtem_idade(cpf_conta,lst_clientes);


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
				inserir_senha(lst_mesa_inicio, lst_mesa_final,novo_atendimento);

			}else{

				if(atendimento == 'c' || atendimento == 'C'){
					puts("inserindo senha CAIXA");				
					novo_atendimento->tipo_fila = atendimento;

					printf("preferencial: %c\n", novo_atendimento->preferencial);

					inserir_senha(lst_caixa_inicio,lst_caixa_final,novo_atendimento);
					system("pause");
				}
			}
		}
	}else{
		
		printf("\nInforme o TIPO DE ATENDIMENTO: MESA = M OU CAIXA = C :");
		scanf(" %[^\n]",&atendimento);

		if(atendimento == 'm' || atendimento == 'M'){

			puts("inserindo senha mesa sem conta");
			inserir_senha(lst_mesa_inicio, lst_mesa_final,novo_atendimento);

		}else{
			if (atendimento == 'c' || atendimento == 'C'){				
				
				novo_atendimento->tipo_fila = 'C';

				puts("inserindo senha CAIXA sem conta");

				inserir_senha(lst_caixa_inicio,lst_caixa_final,novo_atendimento);
			}
			
		}
	}

	system("PAUSE");	
}

void inserir_senha(fila_atendimento **lista_inicio, fila_atendimento **lista_final, fila_atendimento *novo_atendimento){	

	fila_atendimento *percorre_lista, *lst_inicio, *lst_final;

	percorre_lista = *lista_inicio;

	lst_inicio = *lista_inicio;
	lst_final = *lista_final;

	/* PARTE EXTRA 

	if (novo_atendimento->idade >= 65){
		
	}*/

	//obtem_idade(lst_clientes, novo_a);

	if (lst_inicio == NULL){
		
		novo_atendimento->senha=1;
		*lista_inicio = novo_atendimento;
		*lista_final = novo_atendimento;

		puts("primeira posicao");

	}else{

		// N DE NÃO PREFERENCIAL
		if(novo_atendimento->preferencial == 'n' || novo_atendimento->preferencial == 'N'){
			
			if (lst_final->preferencial == 'n' || lst_final->preferencial == 'N'){
				
				if (novo_atendimento->senha == -1){
					if(compara_data(lst_final->data,novo_atendimento->data) == 1){						

						novo_atendimento->senha = lst_final->senha + 1;

					}else{
						novo_atendimento->senha = 1;	
					}
				}
				
				
			}else{

				if (novo_atendimento->senha == -1){				

					novo_atendimento->senha = 1;					
				}
			}
			
			lst_final->prox = novo_atendimento;
			printf("%d\n", lst_final->senha);
			novo_atendimento->ant = lst_final;
			lst_final = lst_final->prox;

			printf("%d\n", lst_final->senha);

			pausa();

		}else{/* ENTRARA NESSE ELSE QUANDO O NOVO ATENDIMENTO FOR ATENDIMENTO PREFERENCIAL*/			

			/* EU VERIFICO SE O PRIMEIRO OU ULTIMO ATENDIMENTO É OU NÃO É PREFERENCIAL */

			if (lst_inicio->preferencial == 'n' || lst_inicio->preferencial == 'N'){
				

				if (novo_atendimento->senha == -1){

					novo_atendimento->senha = 1;
					novo_atendimento->prox = lst_inicio;
					lst_inicio->ant = novo_atendimento;
					*lista_inicio = novo_atendimento;
				}

				
			}else{


				/* ENTRA NESSE IF CASO TODOS OS ATENDIMENTOS FOREM PREFERENCIAIS PARA EVITAR
				 FICAR PERCORRENDO SEMPRE A  LISTA*/

				if(lst_final->preferencial == 's' || lst_final->preferencial == 'S'){

					/* CASO A DATA DA ULTIMA SENHA FOR A ATUAL ELE ADICIONA +1 A SENHA, 
					SENÃO ELE RESETA A CONTAGEM SENHA  */
					
					if (novo_atendimento->senha == -1){
						if (compara_data(lst_final->data, novo_atendimento->data) == 1){

							novo_atendimento->senha = lst_final->senha + 1;
						}else{
							novo_atendimento->senha = 1;
							puts("linha 198 ++++++++++++++");
						}
					}
					puts("linha 200 ++++++++++++++");

					novo_atendimento->ant = *lista_final;
					(*lista_final)->prox = novo_atendimento;
					*lista_final = (*lista_final)->prox;

					//printf("%d\n", lst_final->senha);

				}else{

					/* O WHILE IRA PARAR QUANDO ENCONTRAR O PRIMEIRO ATENDIMENTO NÃO PREFERENCIAL, 
					SEI QUE EXISTE ATENDIMENTOS NÃO PREFERENCIAL POIS NÃO ENTROU NO ULTIMO IF */
					while(percorre_lista->preferencial == 's' || percorre_lista->preferencial == 'S'  )
						percorre_lista = percorre_lista->prox;


					if (percorre_lista->preferencial == 'n' || percorre_lista->preferencial == 'N'){

					/* INSERE NO FINAL DOS PREFERENCIAIS */
						if (novo_atendimento->senha == -1){
							if(compara_data(percorre_lista->ant->data,novo_atendimento->data) == 1){
								novo_atendimento->senha = percorre_lista->ant->senha + 1;
							}else{
								novo_atendimento->senha = 1;	
							}
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