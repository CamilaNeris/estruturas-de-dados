#define MAXFILA 10

struct TpElemento
{
	char id[20];
	char cor[20];
	char fab[30];
	char prioridade;
};

struct TpFilaP
{
	int FIM;
	TpElemento Fila[MAXFILA];
};

void Inicializar(TpFilaP &fp)
{
	fp.FIM = -1;
}

char FilaVazia(int FIM)
{
	return FIM == -1;
}

char FilaCheia(int FIM)
{
	return FIM == MAXFILA - 1;
}

TpElemento ElementoInicio(TpFilaP fp)
{
	return fp.Fila[0];
}

TpElemento ElementoFim(TpFilaP fp)
{
	return fp.Fila[fp.FIM];
}

TpElemento Retirar(TpFilaP &fp)
{
	TpElemento aux;
	int i;

	aux = fp.Fila[0];

	for(i = 0; i < fp.FIM; i++)
		fp.Fila[i] = fp.Fila[i + 1];

	fp.FIM--;

	return aux;
}

void Inserir(TpFilaP &fp, TpElemento elem)
{
	TpElemento aux;
	int i;

	fp.Fila[++fp.FIM] = elem;

	i = fp.FIM;

	while(i > 0 && fp.Fila[i].prioridade < fp.Fila[i - 1].prioridade)
	{
		aux = fp.Fila[i];
		fp.Fila[i] = fp.Fila[i - 1];
		fp.Fila[i - 1] = aux;

		i--;
	}
}

void ExibirFila(TpFilaP fp)
{
	TpElemento aux;

	if(FilaVazia(fp.FIM))
	{
		printf("FILA VAZIA!\n");
	}
	else
	{
		while(!FilaVazia(fp.FIM))
		{
			aux = Retirar(fp);

			printf("%s | %s | %s | %c\n",
				aux.id,
				aux.cor,
				aux.fab,
				aux.prioridade);
		}
	}
}
