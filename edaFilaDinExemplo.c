#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
	struct elemento* proximo; 
	int valor; 
} Elemento;

typedef struct {
	Elemento* cabeca;
	Elemento* cauda;
} FilaDinamica;

FilaDinamica* criar() {
	FilaDinamica* f = malloc(sizeof(FilaDinamica));
	f->cabeca = f->cauda = NULL;
}

int vazia(FilaDinamica* f) {
	return f->cabeca == NULL;
}

void adicionar(FilaDinamica* f, int valor) {
	Elemento* elemento = malloc(sizeof(Elemento));
	elemento->valor = valor;
	elemento->proximo = NULL;
	
	if (!vazia(f)) {
		f->cauda->proximo = elemento;
		f->cauda = elemento;
	} else {
		f->cabeca = f->cauda = elemento;
	}
}

int retirar(FilaDinamica* f) {
	int valor;
	
	if (vazia(f)) {
		printf("Fila vazia.");
		exit(-1);
		
	} else {
		Elemento* elemento = f->cabeca;
		int valor = elemento->valor;
		f->cabeca = elemento->proximo;
		
		free(elemento);
		
		return valor;
	}	
}


int espiar(FilaDinamica* f) {
	if (vazia(f)) {
		printf("Fila vazia.");
		exit(-1);
	} else {
		//
	}
}

int main (int argc, char const *argv[]) {
	int n = 10, i;
	
	FilaDinamica* fila = criar();
	
	for (i = 1; i <= 10; i++) {
		adicionar(fila, i);
		printf("%d ", i);
	}
	printf("\n");
	
	while(!vazia(fila)) {
		printf("%d ", retirar(fila));
	}
	printf("\n");


	return 0;
}
