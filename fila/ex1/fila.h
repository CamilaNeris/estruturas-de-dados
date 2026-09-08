#define MAXFILA 10 

struct TpFila{
	int FIM;
	char FILA[MAXFILA];
};

void Inicializar(TpFila &F);
char FilaVazia(int fim);
char FilaCheia(int fim);
void Inserir(TpFila &F, char Elemento);
char Retirar(TpFila &F);
char ElementoInicio(TpFila F);
char ElementoFim(TpFila F);
void ExibirFila(TpFila F);

void Inicializar(TpFila &F){
	F.FIM = -1;
}
char FilaVazia(int fim){
	return fim == -1;
}
char FilaCheia(int fim){
	return fim == MAXFILA-1;
}
void Inserir(TpFila &F, char Elemento){
	F.FILA[++F.FIM] = Elemento;
}
char Retirar(TpFila &F){
	char elemento = F.FILA[0];
	
	for(int i = 0; i < F.FIM; i++)
		F.FILA[i] = F.FILA[i+1];
		
	F.FIM--;
	
	return elemento;
}
char ElementoInicio(TpFila F){
	return F.FILA[0];
}
char ElementoFim(TpFila F){
	return F.FILA[F.FIM];
}
void ExibirFila(TpFila F){
	while(!FilaVazia(F.FIM))
		printf("\n %c", Retirar(F));
}
