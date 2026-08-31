#include<stdio.h>
#include<conio2.h>
#include "pilha.h"

int main(void){
	TpPilha p1, p2, pAux;
	char opcao, elemento;
	
	inicializa(p1);
	inicializa(p2);
	inicializa(pAux);
	
	printf("\nPilhas inicializadas!\n");
	printf("Escolha uma das opcoes: \n");
	printf("\n1 - Insere P1 (PUSH)");
	printf("\n2 - Insere P2 (PUSH)");
	printf("\n3 - Exibe P1");
	printf("\n4 - Exibe P2");
	printf("\n5 - Concatenar");
	printf("\n[ESC] - Sair\n");
	
	
	do{
		printf("\nDigite a opcao desejada: ");
		opcao = getche();
		
		switch(opcao){
			case '1':
				if(!cheia(p1.TOPO)){
					printf("\nDigite o elemento: ");
					fflush(stdin);
					scanf("%c", &elemento);
					PUSH(p1,elemento);
					printf("\n\nElemento inserido!\n");
				}
				else
					printf("\nNao e possivel inserir, Pilha esta cheia!\n");
				break;
			case '2':
				if(!cheia(p2.TOPO)){
					printf("\nDigite o elemento: ");
					fflush(stdin);
					scanf("%c", &elemento);
					PUSH(p2, elemento);
					printf("\n\nElemento inserido!\n");
				}
				else
					printf("\nNao e possivel inserir, Pilha esta cheia!\n");
				break;
			case '3':
				if(!vazia(p1.TOPO))
					exibe(p1);
				else
					printf("\nA pilha esta vazia!\n");
				break;
			case '4':
				if(!vazia(p2.TOPO))
					exibe(p2);
				else
					printf("\nA pilha esta vazia!\n");
				break;
			case '5':
				while(!vazia(p2.TOPO))
					PUSH(pAux, POP(p2));
				while(!vazia(pAux.TOPO) && !cheia(p1.TOPO))
						PUSH(p1, POP(pAux));
				printf("\nPilha concatenada (p1):\n");		
				exibe(p1);
				getch();
				break;
		}
		
	}while(opcao != 27);
	
	return 0;
}
