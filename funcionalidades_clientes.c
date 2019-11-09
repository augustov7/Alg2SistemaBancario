#include "menu.h"

void cadastrar_cliente(cliente **lista_clientes){

	char nome[50];
	char cpf_usuario[15];
	char data_nascimento[20];
	char endereco[30];
	char bairro[30];
	char cidade_estado[50];
	char telefone[15];

	printf("\nInforme o NOME:");
	scanf(" %[^\n]",nome);
	printf("\nInforme o CPF:");
	scanf(" %[^\n]",cpf_usuario);
	printf("\nInforme a DATA DE NASCIMENTO:");
	scanf(" %[^\n]",data_nascimento);
	printf("\nInforme o ENDEREÇO:");
	scanf(" %[^\n]",endereco);
	printf("\nInforme o BAIRRO:");
	scanf(" %[^\n]",bairro);
	printf("\nInforme a CIDADE/ESTADO:");
	scanf(" %[^\n]",cidade_estado);
	printf("\nInforme o TELEFONE de Contato:");
	scanf(" %[^\n]", telefone);

	int i = inserir_cliente(nome,cpf_usuario, data_nascimento, endereco, bairro, cidade_estado, telefone,lista_clientes);

	printf("%d\n", i);

}

int inserir_cliente(char nome[],char cpf_usuario[], char data_nascimento[], char endereco[], char bairro[], char cidade_estado[], char telefone[], cliente **lista_clientes){

	cliente *novo_cliente = (cliente *) malloc(sizeof(cliente));

	strcpy(novo_cliente->nome,nome);
	strcpy(novo_cliente->cpf_usuario,cpf_usuario);
	strcpy(novo_cliente->data_nascimento,data_nascimento);
	strcpy(novo_cliente->endereco,endereco);
	strcpy(novo_cliente->bairro,bairro);
	strcpy(novo_cliente->cidade_estado,cidade_estado);
	strcpy(novo_cliente->telefone,telefone);

	novo_cliente->prox = NULL;


	if (*lista_clientes == NULL)
	{
		*lista_clientes = novo_cliente;
		return 0;
	}else{

		novo_cliente->prox = *lista_clientes;
		*lista_clientes = novo_cliente;
		return 1;

	}

	return -1;

}

void listar_clientes(cliente *lista_clientes){

	cliente *lst = lista_clientes;

	while(lst != NULL){
		printf(" %s \n", lst->nome);

		lst = lst->prox;
	}

	puts("-- FIM --");

}

void listar_cliente_cpf(cliente *lst_clientes){

	cliente *lst;

	lst = lst_clientes;

	char cpf_usuario[15];
	printf("Digite o CPF do Cliente: ");
	scanf(" %s", cpf_usuario);

	while(lst != NULL){
		if (comparaString(cpf_usuario,lst->cpf_usuario) == 1){
			
			puts("---------------- CLIENTES -----------------");
			printf(" NOME: %s \n", lst->nome);
			printf(" CPF: %s \n", lst->cpf_usuario);
			printf(" DATA DE NASCIMENTO: %s \n", lst->data_nascimento);
			printf(" ENDERECO: %s \n", lst->endereco);
			printf(" BAIRRO: %s \n", lst->bairro);
			printf(" CIDADE/ESTADO: %s \n", lst->cidade_estado);
			printf(" TELEFONE: %s \n", lst->telefone);

			puts("-------------------------------------------");

		}

		lst = lst->prox;
	}

	system("PAUSE");

}

void listar_cliente_nome(cliente *lst_clientes){

	cliente *lst;

	lst = lst_clientes;

	char nome[50];
	printf("Digite o NOME do Cliente: ");
	scanf(" %s", nome);

	while(lst != NULL){
		if (comparaString(nome,lst->nome) == 0){
			
			puts("---------------- CLIENTES -----------------");
			printf(" NOME: %s \n", lst->nome);
			printf(" CPF: %s \n", lst->cpf_usuario);
			printf(" DATA DE NASCIMENTO: %s \n", lst->data_nascimento);
			printf(" ENDERECO: %s \n", lst->endereco);
			printf(" BAIRRO: %s \n", lst->bairro);
			printf(" CIDADE/ESTADO: %s \n", lst->cidade_estado);
			printf(" TELEFONE: %s \n", lst->telefone);

			puts("-------------------------------------------");
		}

		lst = lst->prox;
	}

	system("PAUSE");

}