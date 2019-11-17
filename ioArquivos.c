#include "menu.h"

void gravarCliente(cliente *lst_cliente){

	FILE *ptArquivo = fopen("cliente.csv", "w");

	if (ptArquivo == NULL){
		puts("Erro ao abrir arquivo");
	}else{

		while(lst_cliente != NULL){

			fprintf(ptArquivo, "%s;", lst_cliente->nome);
			fprintf(ptArquivo, "%s;", lst_cliente->cpf_usuario);
			fprintf(ptArquivo, "%s;", lst_cliente->data_nascimento);
			fprintf(ptArquivo, "%s;", lst_cliente->endereco);
			fprintf(ptArquivo, "%s;", lst_cliente->bairro);
			fprintf(ptArquivo, "%s;", lst_cliente->cidade_estado);
			fprintf(ptArquivo, "%s;\n", lst_cliente->telefone);

			lst_cliente = lst_cliente->prox;
		}
		
	}

	fclose(ptArquivo);
}

void gravarConta(conta *lst_contas){

	FILE *ptArquivo = fopen("Contas.csv", "w");

	if (ptArquivo == NULL){
		puts("Erro ao abrir arquivo");
	}else{

		while(lst_contas != NULL){

			fprintf(ptArquivo, "%s;", lst_contas->cpf_conta);
			fprintf(ptArquivo, "%s;", lst_contas->Agencia_bancaria);
			fprintf(ptArquivo, "%s;", lst_contas->tipo_conta);
			fprintf(ptArquivo, "%s;", lst_contas->numero_conta);
			fprintf(ptArquivo, "%c;", lst_contas->conta_preferencial);
			fprintf(ptArquivo, "%lf;\n", lst_contas->saldo);

			lst_contas = lst_contas->prox;
		}
		
	}

	fclose(ptArquivo);
}

void lerClientes(cliente **lst_clientes){

	FILE *ptArquivo = fopen("cliente.csv", "r");

	if (ptArquivo == NULL){
		puts("Erro ao abrir arquivo");
	}else{

		char linha[210];

		char *nome;
		char *cpf_usuario;
		char *data_nascimento;
		char *endereco;
		char *bairro;
		char *cidade_estado;
		char *telefone;

		while(fgets(linha,210,ptArquivo) != NULL){
			nome = strtok(linha,";");
			cpf_usuario = strtok(NULL,";");
			data_nascimento = strtok(NULL,";");
			endereco = strtok(NULL,";");
			bairro = strtok(NULL,";");
			cidade_estado = strtok(NULL,";");
			telefone = strtok(NULL,";");

			inserir_cliente(nome,cpf_usuario, data_nascimento, endereco, bairro, cidade_estado, telefone,lst_clientes);
		}
		
	}

	fclose(ptArquivo);
}

void lerContas(conta **lista_contas){

	FILE *ptArquivo = fopen("Contas.csv", "r");

	if (ptArquivo == NULL){
		puts("Erro ao abrir arquivo");
	}else{

		char linha[210];

		char *cpf_conta;
		char *Agencia_bancaria;
		char *tipo_conta;
		char *numero_conta;
		char *conta_preferencial;
		char *saldo_str;
		double saldo;


		while(fgets(linha,210,ptArquivo) != NULL){

			cpf_conta = strtok(linha,";");
			Agencia_bancaria = strtok(NULL,";");
			tipo_conta = strtok(NULL,";");
			numero_conta = strtok(NULL,";");
			conta_preferencial = strtok(NULL,";");
			saldo_str = strtok(NULL,";");

			saldo = atof(saldo_str);

			inserir_conta(cpf_conta,Agencia_bancaria,tipo_conta,numero_conta,*conta_preferencial,saldo,lista_contas);
		}
		
	}

	fclose(ptArquivo);
}

int salvarFila(fila_atendimento *fila){

	fila_atendimento *lst;
	FILE *ptArq;

	lst = fila;

	ptArq = fopen("fila.csv", "w");

	if(ptArq == NULL){
		printf("erro");
		return 0;
	}
	while(lst != NULL){

		fprintf(ptArq, "%d;", lst->data.dia);
		fprintf(ptArq, "%d;", lst->data.mes);
		fprintf(ptArq, "%d;", lst->data.ano);        
		fprintf(ptArq, "%c;", lst->preferencial);
		fprintf(ptArq, "%c;\n", lst->tipo_fila);

		lst = lst->prox;
	}
	fclose(ptArq);
	return 1;
}

void lerAtendimentos(fila_atendimento **lst_caixa, fila_atendimento **lst_mesa){

	FILE *ptArquivo = fopen("fila.csv", "r");

	if (ptArquivo == NULL){
		puts("Erro ao abrir arquivo");
	}else{

		char linha[110];

		char *diaStr;
		char *mesStr;
		char *anoStr;
		char *preferencial;
		char *tipo_fila;

		puts("test 01");

		fila_atendimento *novo_atendimento = (fila_atendimento*) malloc(sizeof(fila_atendimento));


		while(fgets(linha,110,ptArquivo) != NULL){

			puts("--");
			

			diaStr = strtok(NULL,";");
			mesStr = strtok(NULL,";");
			anoStr = strtok(NULL,";");
			preferencial =  strtok(NULL,";");
			tipo_fila = strtok(NULL,";");


			puts("test 02");
			novo_atendimento->senha = 1;

			novo_atendimento->data.dia = atoi(diaStr);
			novo_atendimento->data.mes = atoi(mesStr);
			novo_atendimento->data.ano = atoi(anoStr);

			puts("test 03");
			printf("%s\n", preferencial);
			novo_atendimento->preferencial = preferencial[0];
			novo_atendimento->tipo_fila = tipo_fila[0];

			puts("test 04");

			novo_atendimento->ant = NULL;
			novo_atendimento->prox = NULL;

			puts("++");
			
			/*
			printf("%d\n", novo_atendimento->senha);
			printf("%d\n", novo_atendimento->data.dia);
			printf("%d\n", novo_atendimento->data.mes);
			printf("%d\n", novo_atendimento->data.ano);
			printf("%c\n", novo_atendimento->preferencial);
			printf("%c\n", novo_atendimento->tipo_fila);

			*/


			if (novo_atendimento->tipo_fila == 'c' || novo_atendimento->tipo_fila == 'C' ){

				inserir_senha(lst_caixa,novo_atendimento);

			}

			
		}
		
	}
	system("pause");

	fclose(ptArquivo);
}