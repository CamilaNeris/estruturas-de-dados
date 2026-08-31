#define MAXPILHA 10

struct TpPilha{
	int TOPO;
	char PILHA[MAXPILHA];
};

void inicializa(TpPilha &p){
	p.TOPO = -1;
}

void PUSH(TpPilha &p, char Elemento){
	p.PILHA[++p.TOPO] = Elemento;
}

char POP(TpPilha &p){
	return p.PILHA[p.TOPO--];
}

char elementoTopo(TpPilha p){
	return p.PILHA[p.TOPO];
}

char cheia(int topo){
	return topo == MAXPILHA-1;
}

char vazia(int topo){
	return topo == -1;
}

int exibe(TpPilha p){
	while(!vazia(p.TOPO))
		printf("\n%c",POP(p));
}
