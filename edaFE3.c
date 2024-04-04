#include <stdio.h>
#include <stdlib.h>

#define MAX 5

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

void limpar(Fila* f) {
	if (f != NULL) {
		free(f);
	}
	
	f = NULL;
}

void percorrer(Fila* f, int valor) {
	int encontrou = 0;
	
	if (vazia(f)) {
		printf("Fila vazia.");
		exit(0);
		
	} else {
		int i;
		for (i = f->cabeca; i < MAX; i++) {
			printf("%d ", f->v[i]);

			if (f->v[i] == valor) {
				printf("\nValor %d encontrado!\n", valor);
				encontrou = 1;
			}
		}
	}
	
	if (encontrou == 0) {
		printf("\nValor %d nao encontrado.", valor);
	}
}


int main (int argc, char const *argv[]) {
	int i, valor = 3,;
	int vetor[]  = {1, 2, 3, 4, 5}; 
	Fila* fila   = criar();
	
	for (i = 0; i <
	 MAX; i++) {
		adicionar(fila, vetor[i]);
	}
	
	percorrer(fila, valor);

	limpar(fila);
	
	return 0;
}
