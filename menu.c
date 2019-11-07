#include "menu.h"

int menu_principal(){
	char op;
	limpar();
	printf("\n1 CLIENTES\n2 CONTAS\n3 ATENDIMENTO AO CLIENTE \nS SAIR \n\nOPCAO: ");
	op = getch();
	return op;
}

int submenu1(){
	char op;
	limpar();
	printf("\n1 PESQUISAR POR CPF \n2 PESQUISAR POR NOME \n3 CADASTRAR CLIENTE \n0 Voltar \n\nOPCAO: ");
	op = getch();
	return op;
}

int submenu2(){
	char op;
	limpar();
	printf("\n1 PESQUISAR POR CPF DO CLIENTE \n2 PESQUISAR PELO NUMERO DA CONTA \n3 CADASTRAR CONTA \n0 Voltar \n\nOPCAO: ");
	op = getch();
	return op;
}

int submenu3(){
	char op;
	system("cls");
	printf("\n1 REGISTRAR SENHA PARA CLIENTE \n2 EMITIR SENHA DE CLIENTE PARA O CAIXA \n3 EMITIR SENHA DE CLIENTE PARA A MESA \n0 Voltar \n\nOPCAO: ");
	op = getch();
	return op;
}
