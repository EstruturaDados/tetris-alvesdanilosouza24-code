#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    int id;
} Peça;


#define MAX 5

typedef struct {
    fila itens[MAX];
    int inicio;
    int fim;
    total;
} fila;

void inicializarfila(fila *f) { 
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int filacheia(fila *f) {
    return f->total == MAX;
}

int filacheia(fila *f) {
    return f->total == 0;
}

void inserir(fila *f, Peça p) {
    if (filacheia(f)) {
        printf("fila cheia. não é possível inserir.\n");
        return;
    }

    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;

}


void remover(fila *f, Peça *p) {
    if (filavazia(f)) {
        printf("fila vazia. não é possivel remover.\n");
        return;
    }
    *p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
}


int main() {

}

