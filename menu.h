#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#ifndef _WIN32
	#include "getch.h" 
#else
	#include <conio.h>
#endif 

#define MAX_SIZE 30

typedef struct cliente{
	char nome[50];
	char cpf_usuario[15];
	char data_nascimento[20];
	char endereco[30];
	char bairro[30];
	char cidade_estado[50];
	char telefone[15];
	struct cliente *prox;
}cliente;

typedef struct conta{
	char cpf_conta[15];
	char Agencia_bancaria[10];
	char tipo_conta[10];
	char numero_conta[15];
	char conta_preferencial[15];
	double saldo;
	struct conta *prox;
}conta;

typedef struct venda{
	char codigo_produto[10];
	char cpf_cliente[14];
	int quantidade_venda;
	struct venda *prox;
}venda;

int menu_principal();

int submenu1();

int submenu2();

int submenu3();

int comparaString(char str1[], char str2[]);

void pausa();

void limpar();

/* CLIENTES */

void cadastrar_cliente(cliente **lista_clientes);

int inserir_cliente(char nome[],char cpf_usuario[], char data_nascimento[], char endereco[], char bairro[], char cidade_estado[], char telefone[], cliente **lista_clientes);

void listar_clientes(cliente *lista_clientes);

void gravarCliente(cliente *lst_cliente);

void lerClientes(cliente **lst_clientes);

void listar_cliente_cpf(cliente *lst_clientes);

void listar_cliente_nome(cliente *lst_clientes);

/* CONTA */

void cadastrar_conta(conta **lista_contas);

int inserir_conta(char cpf_conta[],char Agencia_bancaria[], char tipo_conta[], char numero_conta[], char conta_preferencial[], double saldo, conta **lista_contas);


void pesquisar_numero_contas(conta *lista_contas);

void pesquisar_cpf_contas(conta *lista_contas);

void lerContas(conta **lista_contas);

void gravarConta(conta *lst_contas);