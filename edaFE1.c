#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int cabeca, cauda, capacidade;
	int v*;
} Fila;

Fila* criar(int capacidade) {
	Fila* f = malloc(sizeof(Fila));
	f->v = malloc(sizeof(int) * capacidade);
	f->capacidade = capacidade;
	f->cabeca = f->cauda = -1;
	
	return f;
}

int vazia(Fila* f) {
	return f->cabeca == -1 && f->cauda == -1;
}

int cheia(Fila* f) {
	return (f->cauda + 1) % capacidade == f->cabeca;
}

void adicionar(Fila* f, int v) {
	if (cheia(f)) {
		printf("Capacidade maxima da fila atingida.");
		exit(-1);
	} else {
		f->cauda = (f->cauda + 1) % capacidade;
		f->v[f->cauda] = v; // insere na proxima posicao livre
		
		if (f->cabeca == -1) {
			f->cabeca = f->cauda;
		}
	}
}

int remover(Fila* f) {
	int v;
	
	if (vazia(f)) {
		printf("Fila vazia.");
		exit(-1);
		
	} else {
		v = f->v[f->cabeca]; // recupera o valor da cabeca da fila
		if (f->cabeca == f->cauda) {
			f->cabeca = f->cauda = -1;
			
		} else {
			f->cabeca = (f->cabeca + 1) % capacidade;
		}
	}
	
	return v;
}

void limpar(Fila* f) {
	if (f != NULL) {
		free(f);
	}
	
	f = NULL;
}

void percorrer(Fila* f) {
	if (vazia(f)) {
		printf("Fila vazia.");
		exit(0);
		
	} else {
		int i;
		for (i = f->cabeca; i != f->cauda; i = (i + 1) % capacidade) {
			printf("%d ", f->v[i]);
		}
	}
}
int main (int argc, char const *argv[]) {
	int i, x;
	Fila* fila = criar();
	
	for (i = 1; i <= capacidade; i++) {
		adicionar(fila, i);
	}
	
	printf("\n");
	percorrer(fila);
	
	while (!vazia(fila)){
		remover(fila);
	}
	
	printf("\n");
	percorrer(fila);
	
	limpar(fila);
	
	return 0;
}

