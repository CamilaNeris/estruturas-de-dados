#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<windows.h>
#include <time.h>

#include "FilaPex7.h"

/*
7:-) Com o arquivo "DadosVeiculos.CSV", realize a simulação 
de uma Fila com Prioridades (A=Alta; B=Média; C=Baixa) onde, 
as inserções ou remoções da Fila devem acontecer por sorteio, 
e a cada ação efetuada deve-se exibi-la inteiramente. Não há 
interação com Usuário.
*/

int main(void){
	TpFilaP Fila;
	TpElemento elem, retirado;
	char cabecalho[100];
	int sorteio, qtdCampos;
	
	Inicializar(Fila);
	srand(time(NULL));
	
	FILE *PtrArq = fopen("DadosVeiculos.csv","r");
	
	if(PtrArq == NULL){
		printf("Erro ao abrir o arquivo!\n");
	}else{
		// Descartando o cabecalho do CSV
		fgets(cabecalho, 100, PtrArq);
		
		while(!feof(PtrArq)){
			// 0 = inserir
			// 1 = retirar
			
			sorteio = rand() % 2;
			
			// Se estiver vazia, obrigatoriamente insere
			if(FilaVazia(Fila.FIM))
				sorteio = 0;

			// Se estiver cheia, obrigatoriamente retira
			if(FilaCheia(Fila.FIM))
				sorteio = 1;
				
			if(sorteio == 0){
				qtdCampos = fscanf(PtrArq, "%[^,],%[^,],%[^,],%c\n", elem.id,
                       elem.cor,
                       elem.fab,
                       &elem.prioridade);
                if(qtdCampos == 4){
                	Inserir(Fila, elem);
                	
                	printf("\n=============================\n");
					printf("ACAO SORTEADA: INSERIR\n");
					printf("=============================\n");
					
					printf("Veiculo inserido:\n");
					printf("ID: %s\n", elem.id);
					printf("Cor: %s\n", elem.cor);
					printf("Fabricante: %s\n", elem.fab);
					printf("Prioridade: %c\n", elem.prioridade);

					printf("\nFILA ATUAL:\n");
					ExibirFila(Fila);
					
					Sleep(1500);
				}
			} else{
				retirado = Retirar(Fila);
				
				printf("\n=============================\n");
				printf("ACAO SORTEADA: RETIRAR\n");
				printf("=============================\n");

				printf("Veiculo retirado:\n");
				printf("ID: %s\n", retirado.id);
				printf("Cor: %s\n", retirado.cor);
				printf("Fabricante: %s\n", retirado.fab);
				printf("Prioridade: %c\n", retirado.prioridade);

				printf("\nFILA ATUAL:\n");
				ExibirFila(Fila);
				
				Sleep(1500);	
			}
		}
		
		fclose(PtrArq);
	}
	return 0;
}
