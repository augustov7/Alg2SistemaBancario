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

	FILE *ptArq;


	ptArq = fopen("Fila.csv", "a");

	if(ptArq == NULL){
		printf("Erro ao abrir arquivo de Filas");
		return 0;
	}else{
		while(fila != NULL){
			
			fprintf(ptArq, "%d;", fila->senha);
			fprintf(ptArq, "%d;", fila->data.dia);
			fprintf(ptArq, "%d;", fila->data.mes);
			fprintf(ptArq, "%d;", fila->data.ano);        
			fprintf(ptArq, "%c;", fila->preferencial);
			fprintf(ptArq, "%c;\n", fila->tipo_fila);
			
			fila = fila->prox;
		}
	}
	
	fclose(ptArq);
	return 1;
}

void lerAtendimentos(fila_atendimento **lst_caixa_inicio, fila_atendimento **lst_caixa_final, fila_atendimento **lst_mesa_inicio, fila_atendimento **lst_mesa_final){

	fila_atendimento *novo_atendimento;

	FILE *ptArquivo = fopen("Fila.csv", "r");

	if (ptArquivo == NULL){
		puts("Erro ao abrir arquivo");
	}else{

		char linha[110];

		char *senha_str;
		char *diaStr;
		char *mesStr;
		char *anoStr;
		char *preferencial;
		char *tipo_fila;

		fila_atendimento *lst;

		while(fgets(linha,110,ptArquivo) != NULL){

			lst = *lst_caixa_inicio;			

			novo_atendimento = (fila_atendimento*) malloc(sizeof(fila_atendimento));

			senha_str = strtok(linha,";");
			diaStr = strtok(NULL,";");
			mesStr = strtok(NULL,";");
			anoStr = strtok(NULL,";");
			preferencial =  strtok(NULL,";");
			tipo_fila = strtok(NULL,";");
			
			novo_atendimento->senha = atoi(senha_str);

			novo_atendimento->ant = NULL;
			novo_atendimento->prox = NULL;

			novo_atendimento->data.dia = atoi(diaStr);
			novo_atendimento->data.mes = atoi(mesStr);
			novo_atendimento->data.ano = atoi(anoStr);

			novo_atendimento->preferencial = preferencial[0];
			novo_atendimento->tipo_fila = tipo_fila[0];
			
			

			printf("%d\n", novo_atendimento->senha);
			printf("%d\n", novo_atendimento->data.dia);
			printf("%d\n", novo_atendimento->data.mes);
			printf("%d\n", novo_atendimento->data.ano);
			printf("%c\n", novo_atendimento->preferencial);
			printf("%c\n", novo_atendimento->tipo_fila);

			

			if (novo_atendimento->tipo_fila == 'c' || novo_atendimento->tipo_fila == 'C' ){

				inserir_senha(lst_caixa_inicio,lst_caixa_final,novo_atendimento);

			}else{
				inserir_senha(lst_mesa_inicio,lst_mesa_final,novo_atendimento);
			}


			while(lst != NULL){				

				printf("\n %d/%d/%d -  ", lst->data.dia,lst->data.mes,lst->data.ano);

				printf("%c - %d ", lst->preferencial, lst->senha);						

				lst = lst->prox;
			}
			
		}
		
	}

	fclose(ptArquivo);
}