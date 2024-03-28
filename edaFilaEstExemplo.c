#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
	int cabeca, cauda;
	int v[MAX];
} Fila;

Fila* criar() {
	Fila* f = malloc(sizeof(Fila));
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

void limpa(Fila* f) {
	if (f != NULL) {
		free(f);
	}
	
	f = NULL;
}

void percorre(Fila* f) {
	int i;
	for (i = f->cabeca; i != f->cauda; i = (i + 1) % MAX) {
		printf("%d", f->v[i]);
	}
}

int espiar(Fila* f, int passo) {
	if (vazia(f)) {
		return -1;
	}
	
	return passo == -1? f->v[f->cabeca] : f->v[f->cauda];
}

int main (int argc, char const *argv[]) {
	int i;
	Fila* fila = criar();
	
	printf("Enfileirando...");
	for (i = 1; i <= MAX; i++) {
		adicionar(fila, i);
		printf("\nCabeca -> %d, ", (int) espiar(fila, -1));
		printf("Cauda -> %d ", (int) espiar(fila, 1));
	}
	
	printf("\nDesenfileirando -> ");
	while (!vazia(fila)){
		printf("%d ", remover(fila));
	}
	
	limpa(fila);
	
	printf("\n");

	return 0;
}
