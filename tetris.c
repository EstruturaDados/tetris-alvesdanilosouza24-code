#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    int id;
} Peça;


#define MAX 5

typedef struct {
    Peça itens[MAX];
    int inicio;
    int fim;
    int total;
} fila;

void inicializarfila(fila *f) { 
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int filacheia(fila *f) {
    return f->total == MAX;
}

int filavazia(fila *f) {
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

void mostrarfila(fila *f) {
    printf("fila: ");

    for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % MAX) {
        printf("[%s, %d]", f->itens[idx].nome, f->itens[idx].id);
    }

    printf("\n");
}

int main() {
    fila f;
    inicializarfila(&f); // incializa a fila

   
    Peça p1 = {"T", 0};
    Peça p2 = {"O", 1};
    Peça p3 = {"L", 2};
    Peça p4 = {"I", 3};
    Peça p5 = {"I", 4};

    // inserir algumas peças na  fila
    inserir(&f, p1);
    inserir(&f, p2);
    inserir (&f, p3);
    inserir(&f, p4);
    inserir(&f, p5);

    mostrarfila(&f); // mostrar fila antes da remoção

 // Remover peça da fila
 Peça removida;
 remover(&f, &removida); // aqui usamos a função de removeção
 printf("peça removida: %s, %d\n", removida.nome, removida.id);

 return 0;
}

