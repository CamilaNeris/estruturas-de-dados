#define MAXFILA 10 

struct TpFila{
	int FIM;
	int FILA[MAXFILA];
};

void Inicializar(TpFila &F);
int FilaVazia(int fim);
int FilaCheia(int fim);
void Inserir(TpFila &F, int Elemento);
int Retirar(TpFila &F);
int ElementoInicio(TpFila F);
int ElementoFim(TpFila F);
void ExibirFila(TpFila F);

void Inicializar(TpFila &F){
	F.FIM = -1;
}
int FilaVazia(int fim){
	return fim == -1;
}
int FilaCheia(int fim){
	return fim == MAXFILA-1;
}
void Inserir(TpFila &F, int Elemento){
	F.FILA[++F.FIM] = Elemento;
}
int Retirar(TpFila &F){
	int elemento = F.FILA[0];
	
	for(int i = 0; i < F.FIM; i++)
		F.FILA[i] = F.FILA[i+1];
		
	F.FIM--;
	
	return elemento;
}
int ElementoInicio(TpFila F){
	return F.FILA[0];
}
int ElementoFim(TpFila F){
	return F.FILA[F.FIM];
}
void ExibirFila(TpFila F){
	while(!FilaVazia(F.FIM))
		printf("\n %d", Retirar(F));
}
