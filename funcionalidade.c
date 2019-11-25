#include "menu.h"

void limpar(){	

	#ifndef _WIN32
		 system("clear");
	#else
		system("cls");
	#endif 	
}

void pausa(){

	/* limpar buffer */
	fflush(stdin);
	getch();

}

int comparaString(char str1[50], char str2[50]){
	int i = 0,j = 0,aux = 0;

	while(str1[i] != '\0' && str2[j] != '\0'){
		if(str1[i] == str2[j]){
			i++;
			j++;
		}else{
			aux++;
			i = 0;
			j = aux;
		}
	}
    if(i == j && str1[i] == '\0' && str2[j] == '\0') return 1;/* RETORNA 1 CASO STR1 E STR2 SEJA IGUAIS */
    if(str1[i] == '\0') return 0;/* RETORNA 0 CASO STR2 CONTENHA STR1 */
    return -1;/* RETORNA -1 CASO STR1 E STR2 SEJA  DIFERENTE*/
}

int compara_data(data_t data01, data_t data02){

	if(data01.dia == data02.dia){
		if(data01.mes == data02.mes){
			if(data01.ano == data02.ano){
				return 1;
			}
		}
	}	

	return 0;
}