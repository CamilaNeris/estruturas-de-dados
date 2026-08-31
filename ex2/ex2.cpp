#include<stdio.h>
#include<conio2.h>
#include "pilha.h"

int main(void){
	TpPilha p, pAux;
	int elemento, npilha;
	
	inicializa(p);
	inicializa(pAux);
	
	printf("Insira os valore na pilha:\n");
	scanf("%d", &elemento);
	while(!cheia(p.TOPO) && elemento != 0){
		PUSH(p,elemento);
		printf("Elemento inserido!\n");
		
		printf("Insira o valore na pilha:\n");
		scanf("%d", &elemento);
	}
	
	printf("Pilha Atual: \n");
	if(!vazia(p.TOPO))
		exibe(p);
	
	printf("\nEscolha o elemento que deseja retirar: \n");
	scanf("%d", &elemento);
	while(!vazia(p.TOPO)){
		if(!cheia(pAux.TOPO)){
			npilha = POP(p);
			if(npilha != elemento)
				PUSH(pAux,npilha);
		}
	}
	while(!vazia(pAux.TOPO)){
		if(!cheia(p.TOPO))
			PUSH(p,POP(pAux));
	}
	printf("Elemento excluido com sucesso!\n");
	
	printf("Pilha Atual: \n");
	if(!vazia(p.TOPO))
		exibe(p);
	
	return 0;
}
