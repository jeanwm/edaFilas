#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct {
	int cabeca, cauda;
	int v[MAX];
} Fila;

Fila* criar() {
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->cabeca = f->cauda = -1;
	
	return f;
}

int vazia(Fila* f) {
	return f->cabeca == -1 && f->cauda == -1;
}

int cheia(Fila* f) {
	return (f->cauda + 1) % MAX == f->cabeca;
}

void adicionar(Fila* f, int v) {
	if (cheia(f)) {
		printf("Capacidade maxima da fila atingida.");
		exit(-1);
	} else {
		f->cauda = (f->cauda + 1) % MAX;
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
			f->cabeca = (f->cabeca + 1) % MAX;
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


int main (int argc, char const *argv[]) {
	int i, valor;
	int vetor[] = {10, 15, 3, 7};
	Fila* fila = criar();
	
	for (i = 0; i < MAX; i++) {
		adicionar(fila, vetor[i]);
	}
	
	printf("\n");
	while (!vazia(fila)){
		valor = remover(fila);
		printf("%d ", valor);
	}

	limpar(fila);
	
	return 0;
}
