#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

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
	char conta_preferencial;/* S = PREFERENCIAL   N = NÃO PREFERENCIAL S/N*/
	double saldo;
	struct conta *prox;
}conta;

typedef struct data_senha{
	int dia;
	int mes;
	int ano;
}data_senha;

typedef struct fila_atendimento{
	int senha;
	char preferencial;/* SE É PREFERENCIAL S/N */
	struct data_senha data; 
	char tipo_fila; /* MESA OU CAIXA*/
	struct fila_atendimento *ant;
	struct fila_atendimento *prox;
}fila_atendimento;



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

char* nome_cliente_cpf(char *cpf_usuario, cliente *lst_clientes);

/* CONTA */

void cadastrar_conta(conta **lista_contas);

int inserir_conta(char cpf_conta[],char Agencia_bancaria[], char tipo_conta[], char numero_conta[], char conta_preferencial, double saldo, conta **lista_contas);


void pesquisar_numero_contas(conta *lista_contas);

void pesquisar_cpf_contas(conta *lista_contas,cliente *lst_clientes);

void lerContas(conta **lista_contas);

void gravarConta(conta *lst_contas);

char pesquisar_cpf_preferencial(conta *lst_contas, char cpf_conta[], char numero_conta[]);

/*FILA DE ATENDIMENTO */

void registra_senha(fila_atendimento **lst_caixa, fila_atendimento **lst_mesa, conta *lst_contas);

void inserir_senha(fila_atendimento **lst_atendimento, fila_atendimento *novo_atendimento);

int salvarFila(fila_atendimento *fila); 

void lerAtendimentos(fila_atendimento **lst_caixa, fila_atendimento **lst_mesa);