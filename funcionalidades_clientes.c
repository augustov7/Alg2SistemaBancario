#include "menu.h"

void cadastrar_cliente(cliente **lista_clientes){

	limpar();

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


	if(inserir_cliente(nome,cpf_usuario, data_nascimento, endereco, bairro, cidade_estado, telefone,lista_clientes) == 1){
		limpar();
		printf("CADASTRADO !!!\n");
	}else{
		limpar();
		printf("CADASTRADO !!!\n");
	}


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
}

void listar_cliente_cpf(cliente *lst_clientes){

	limpar();

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

	limpar();

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

char* nome_cliente_cpf(char *cpf_usuario, cliente *lst_clientes){

	cliente *lst;

	lst = lst_clientes;

	while(lst != NULL){
		if (comparaString(cpf_usuario,lst->cpf_usuario) == 1){
			
			return lst->nome;
		}

		lst = lst->prox;
	}

	return NULL;
}

int obtem_idade(char *cpf_usuario, cliente *lst_clientes){

	struct tm *data_hora_atual;     
	time_t segundos;
	data_t data01;
	data_t data02;

	char *dia_str;
	char *mes_str;
	char *ano_str;

	cliente *lst;

	time(&segundos);     
	data_hora_atual = localtime(&segundos);

	data01.dia = data_hora_atual->tm_mday;
	data01.mes = data_hora_atual->tm_mon+1;
	data01.ano = data_hora_atual->tm_year+1900;

	lst = lst_clientes;

	while(lst != NULL){

		if (comparaString(cpf_usuario,lst->cpf_usuario) == 1){
			
			dia_str = strtok(lst->data_nascimento,"/");
			mes_str = strtok(NULL,"/");
			ano_str = strtok(NULL,"");
			
			data02.dia = atoi(dia_str);
			data02.mes = atoi(mes_str);
			data02.ano = atoi(ano_str);

			return retorna_idade(data01,data02);

		}
		lst = lst->prox;

	}

	return -1;

}

int retorna_idade(data_t data01, data_t data02){

	int idade;

	idade = data01.ano - data02.ano;

	if(data01.mes == data02.mes ){

		if (data01.dia < data02.dia){
			idade--;	
		}		
	}

	if(data01.mes < data02.mes ){

		idade--;		
	}

	return idade;

}
