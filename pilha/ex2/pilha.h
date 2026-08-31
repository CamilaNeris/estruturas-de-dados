#define MAXPILHA 10

struct TpPilha{
	int TOPO;
	int PILHA[MAXPILHA];
};

void inicializa(TpPilha &p){
	p.TOPO = -1;
}

void PUSH(TpPilha &p, int Elemento){
	p.PILHA[++p.TOPO] = Elemento;
}

int POP(TpPilha &p){
	return p.PILHA[p.TOPO--];
}

int ElementoTopo(TpPilha p){
	return p.PILHA[p.TOPO];
}

int cheia(int topo){
	return topo == MAXPILHA-1;
}

int vazia(int topo){
	return topo==-1;
}

int exibe(TpPilha p){
	while(!vazia(p.TOPO))
		printf("\n%d",POP(p));
}
