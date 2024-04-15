#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100

typedef struct {
    int itens[TAMANHO_MAX];
    int tamanho;
} FilaEstatica;

typedef struct elemento {
    struct elemento* proximo; 
    int valor; 
} Elemento;

typedef struct {
    Elemento* cabeca;
    Elemento* cauda;
} FilaDinamica;

FilaEstatica* criarFilaEstatica() {
    FilaEstatica* fila = malloc(sizeof(FilaEstatica));
    fila->tamanho = 0;
    return fila;
}

void adicionarEstatica(FilaEstatica* fila, int valor) {
    if (fila->tamanho >= TAMANHO_MAX) {
        printf("Erro: Fila estática cheia.\n");
        exit(EXIT_FAILURE);
    }
    fila->itens[fila->tamanho++] = valor;
}

FilaDinamica* criarFilaDinamica() {
    FilaDinamica* f = malloc(sizeof(FilaDinamica));
    f->cabeca = f->cauda = NULL;
    return f;
}

void adicionarDinamica(FilaDinamica* f, int valor) {
    Elemento* elemento = malloc(sizeof(Elemento));
    elemento->valor = valor;
    elemento->proximo = NULL;

    if (f->cauda != NULL) {
        f->cauda->proximo = elemento;
        f->cauda = elemento;
    } else {
        f->cabeca = f->cauda = elemento;
    }
}

void moverPares(FilaEstatica* filaEstatica, FilaDinamica* filaDinamica) {
    for (int i = 0; i < filaEstatica->tamanho; i++) {
        int valor = filaEstatica->itens[i];
        if (valor % 2 == 0) {
            adicionarDinamica(filaDinamica, valor);
        }
    }
}

void exibirFilaDinamicaInversa(FilaDinamica* f) {
    printf("Dados da fila dinâmica na ordem inversa:\n");
    Elemento* atual = f->cabeca;
    int tamanho = 0;

    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        atual = f->cabeca;
        for (int j = 0; j < i; j++) {
            atual = atual->proximo;
        }
        printf("%d ", atual->valor);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Digite o tamanho do conjunto de números inteiros (max %d): ", TAMANHO_MAX);
    scanf("%d", &n);
    
    FilaEstatica* filaEstatica = criarFilaEstatica();
    printf("Digite os números inteiros:\n");
    
    for (int i = 0; i < n; i++) {
        int valor;
        scanf("%d", &valor);
        adicionarEstatica(filaEstatica, valor);
    }

    FilaDinamica* filaDinamica = criarFilaDinamica();
    moverPares(filaEstatica, filaDinamica);

    exibirFilaDinamicaInversa(filaDinamica);

    free(filaEstatica);
    free(filaDinamica);

    return 0;
}
