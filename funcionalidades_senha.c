#include "menu.h"

void registra_senha(){
	char possui_conta;
	char cpf_conta[15];
	char tipo_conta[10];
	char numero_conta[15];
	char conta_preferencial[15];
	double saldo;

	printf("\nPossui CONTA NESSE BANCO ?  S OU N");
	scanf(" %[^\n]",possui_conta);

	if (possui_conta == 's' || possui_conta == 'S'){

		printf("\nInforme o CPF:");
		scanf(" %[^\n]",cpf_conta);


		printf("\nInforme o TIPO DE ATENDIMENTO: MESA = M OU CAIXA = C:");
		scanf(" %[^\n]",numero_conta);
	}else{
		printf("\nInforme o TIPO DE ATENDIMENTO: MESA = M OU CAIXA = C:");
		scanf(" %[^\n]",numero_conta);
	}


	

	
}