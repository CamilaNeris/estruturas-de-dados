#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include<windows.h>

#include "TADFila.h"

/*
1:-) Implemente um programa que simule a execução de uma Fila qualquer, 
onde as inserções e remoções são realizadas a partir de sorteios, e ainda, 
a cada iteração a Fila deve ser exibida. O processo deve ser repetido até 
o usuário pressionar uma tecla qualquer.
*/

int main(void){
	TpFila Fila;
	char tecla;
	int Elemento, opcao;
	// Inicializa a semente aleatória com o tempo atual
    srand(time(NULL));
    
    Inicializar(Fila);
    
    while(!kbhit()){
    	opcao = rand() % 2; //sorteia 0 ou 1
    	
    	if(opcao == 0){
    		printf("Inserir elemento: \n");
    		if(!FilaCheia(Fila.FIM)){
    			Elemento = rand() % 100 + 1; // + 1 para sortear entre 1 e 100
    			Inserir(Fila, Elemento);
				printf("Elemento inserido na fila: %d\n", Elemento);
			} else 
				printf("Fila cheia!\n");
		} else{
			printf("Remover elemento: \n");
			if(!FilaVazia(Fila.FIM)){
				Elemento = Retirar(Fila);
				printf("Elemento removido da fila: %d\n", Elemento);
			} else
				printf("Fila vazia!\n");	
		}
		printf("Fila atual:");
		ExibirFila(Fila);
		printf("\n\n");
		Sleep(1000);
	}
	
	
	return 0;
}
