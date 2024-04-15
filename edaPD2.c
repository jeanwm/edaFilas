#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

FilaEstatica* criarFila() {
    FilaEstatica* fila = malloc(sizeof(FilaEstatica));
    fila->tamanho      = 0;
    return fila;
}

void adicionar(FilaEstatica* fila, int valor) {
    if (fila->tamanho >= TAMANHO_MAX) {
        printf("Erro: Fila estática cheia.\n");
        exit(EXIT_FAILURE);
    }
    fila->itens[fila->tamanho++] = valor;
}

bool contem(FilaEstatica* fila, int valor) {
    for (int i = 0; i < fila->tamanho; i++) {
        if (fila->itens[i] == valor) {
            return true;
        }
    }
    return false;
}

int contarExclusivos(FilaEstatica* fila1, FilaEstatica* fila2) {
    int exclusivos = 0;
    for (int i = 0; i < fila1->tamanho; i++) {
        int valor = fila1->itens[i];
        if (!contem(fila2, valor)) {
            exclusivos++;
        }
    }
    return exclusivos;
}

int main() {
    int n, m;

    printf("Digite o tamanho do primeiro conjunto de números inteiros (max %d): ", TAMANHO_MAX);
    scanf("%d", &n);
    FilaEstatica* fila1 = criarFila();
    printf("Digite os números inteiros para o primeiro conjunto:\n");
    for (int i = 0; i < n; i++) {
        int valor;
        scanf("%d", &valor);
        adicionar(fila1, valor);
    }

    printf("Digite o tamanho do segundo conjunto de números inteiros (max %d): ", TAMANHO_MAX);
    scanf("%d", &m);
    FilaEstatica* fila2 = criarFila();
    printf("Digite os números inteiros para o segundo conjunto:\n");
    for (int i = 0; i < m; i++) {
        int valor;
        scanf("%d", &valor);
        adicionar(fila2, valor);
    }

    int exclusivos = contarExclusivos(fila1, fila2);
    printf("Quantidade total de números exclusivos na interseção: %d\n", exclusivos);

    free(fila1);
    free(fila2);

    return 0;
}
