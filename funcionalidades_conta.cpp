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
	scanf(" %d",&saldo);

	inserir_conta(cpf_conta,Agencia_bancaria,tipo_conta,numero_conta,conta_preferencial,saldo,lista_contas);

}

int inserir_conta(char cpf_conta[],char Agencia_bancaria[], char tipo_conta[], char numero_conta[], char conta_preferencial[], double saldo, conta **lista_contas){

	conta *novo_conta = (conta *) malloc(sizeof(conta));

	strcpy(novo_conta->cpf_conta,cpf_conta);
	strcpy(novo_conta->Agencia_bancaria,Agencia_bancaria);
	strcpy(novo_conta->tipo_conta,tipo_conta);
	strcpy(novo_conta->numero_conta,numero_conta);
	strcpy(novo_conta->conta_preferencial,conta_preferencial);
	strcpy(novo_conta->cidade_estado,cidade_estado);
	
	novo_conta->saldo = saldo;
	novo_conta->prox = NULL;

	if (*lista_clientes == NULL)
	{
		*lista_clientes = novo_conta;
		return 0;
	}else{

		novo_conta->prox = *lista_clientes;
		*lista_clientes = novo_conta;
		return 1;

	}

	return -1;
}

void listar_contas(conta *lista_contas){

	cliente *lst = lista_contas;

	while(lst != NULL){
		printf(" %s \n", lst->nome);

		lst = lst->prox;
	}

	puts("-- FIM --");

}