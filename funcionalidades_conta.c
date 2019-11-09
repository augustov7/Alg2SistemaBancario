#include "menu.h"

void cadastrar_conta(conta **lista_contas){

	char cpf_conta[15];
	char Agencia_bancaria[10];
	char tipo_conta[10];
	char numero_conta[15];
	char conta_preferencial[15];
	double saldo;

	printf("\nInforme o CPF:");
	scanf(" %[^\n]",cpf_conta);
	printf("\nInforme a AGENCIA BANCARIA:");
	scanf(" %[^\n]",Agencia_bancaria);
	printf("\nInforme a TIPO DA CONTA:");
	scanf(" %[^\n]",tipo_conta);
	printf("\nInforme o NUMERO DA CONTA:");
	scanf(" %[^\n]",numero_conta);
	printf("\nInforme o CONTA PREFERENCIAL:");
	scanf(" %[^\n]",conta_preferencial);
	printf("\nInforme o SALDO:");
	scanf(" %lf",&saldo);

	inserir_conta(cpf_conta,Agencia_bancaria,tipo_conta,numero_conta,conta_preferencial,saldo,lista_contas);

}

int inserir_conta(char cpf_conta[],char Agencia_bancaria[], char tipo_conta[], char numero_conta[], char conta_preferencial[], double saldo, conta **lista_contas){

	conta *novo_conta = (conta *) malloc(sizeof(conta));

	strcpy(novo_conta->cpf_conta,cpf_conta);
	strcpy(novo_conta->Agencia_bancaria,Agencia_bancaria);
	strcpy(novo_conta->tipo_conta,tipo_conta);
	strcpy(novo_conta->numero_conta,numero_conta);
	strcpy(novo_conta->conta_preferencial,conta_preferencial);
	
	novo_conta->saldo = saldo;
	novo_conta->prox = NULL;

	if (*lista_contas == NULL)
	{
		*lista_contas = novo_conta;
		return 0;
	}else{

		novo_conta->prox = *lista_contas;
		*lista_contas = novo_conta;
		return 1;

	}

	return -1;
}


void pesquisar_numero_contas(conta *lista_contas){

	char numero_conta[15];
	printf("Digite o Numero da Conta: ");
	scanf(" %s", numero_conta);

	conta *lst;

	lst = lista_contas;

	while(lst != NULL){
		
		if (comparaString(numero_conta,lst->numero_conta) == 1){
			
			puts("---------------- CONTA -----------------");

			printf(" NUMERO %s \n", lst->numero_conta);
			printf(" CPF: %s \n", lst->cpf_conta);
			printf(" AGENCIA: %s \n", lst->Agencia_bancaria);
			printf(" TIPO: %s \n", lst->tipo_conta);
			printf(" PREFERENCIAL: %s \n", lst->conta_preferencial);
			printf(" SALDO: %.2lf \n", lst->saldo);

			puts("----------------------------------------");
		}

		lst = lst->prox;

	}

	puts("-- FIM --");
	system("PAUSE");

}

void pesquisar_cpf_contas(conta *lista_contas){

	char cpf_conta[15];
	printf("Digite o CPF: ");
	scanf(" %s", cpf_conta);

	conta *lst;

	lst = lista_contas;

	while(lst != NULL){
		
		if (comparaString(cpf_conta,lst->cpf_conta) == 1){
			puts("---------------- CONTA -----------------");

			printf(" NUMERO %s \n", lst->numero_conta);
			printf(" CPF: %s \n", lst->cpf_conta);
			printf(" AGENCIA: %s \n", lst->Agencia_bancaria);
			printf(" TIPO: %s \n", lst->tipo_conta);
			printf(" PREFERENCIAL: %s \n", lst->conta_preferencial);
			printf(" SALDO: %.2lf \n", lst->saldo);

			puts("----------------------------------------");

		}

		lst = lst->prox;

	}

	system("PAUSE");

}