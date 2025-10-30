#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome;
    int id;
} Peca;


#define MAX 5
#define MAX 3

typedef struct {
    Peca itens[MAX];
    int inicio;
    int fim;
    int total;
} fila;

typedef struct {
    Peca itens[MAX];
    int topo;
}Pilha;

// Função da Filha 
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

void enfileirar(fila *f, Peca p) {
    if (filaCheia(f)) return;
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

Peca desenfileirar(fila *f) {
    Peca p = {'-', -1};
    if (filaVazia(f)) return p;
    p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
    return p;
}

// função da Pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhavazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, Peca x) { // = PUSH
    if (pilhaCheia(p)) return;
    p->itens[++p->topo] = x;
}

Peca desempilhar(Pilha *p) { // = POP
    Peca x = {'-', -1};
    if (pilhaVazia(p)) return x;
    return p->itens[p->topo--];
}

// função geraPeca
Peca gerarPeca(int id) {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca p;
    p.nome = tipos[rand() % 4];
    p.id = id;
    return p;
}

// =====================
// Exibir estado atual
// =====================
void exibirEstado(fila f, Pilha p) {
    printf("\n===============================\n");
    printf("ESTADO ATUAL:\n");

    // Exibir fila
    printf("Fila de peças\t");
    if (filaVazia(&f))
        printf("(vazia)");
    else {
        for (int i = 0; i < f.total; i++) {
            int idx = (f.inicio + i) % MAX;
            printf("[%c %d] ", f.itens[idx].nome, f.itens[idx].id);
        }
    }

    // Exibir pilha
    printf("\nPilha de reserva\t(Topo -> Base): ");
    if (pilhaVazia(&p))
        printf("(vazia)");
    else {
        for (int i = p.topo; i >= 0; i--) {
            printf("[%c %d] ", p.itens[i].nome, p.itens[i].id);
        }
    }

    printf("\n===============================\n");
}

// =====================
// Programa principal
// =====================
int main() {
    srand(time(NULL));
    fila fila;
    Pilha pilha;
    int id = 0;
    char opcao;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    // Inicializa fila com 5 peças
    for (int i = 0; i < MAX; i++)
        enfileirar(&fila, gerarPeca(id++));

    do {
        exibirEstado(fila, pilha);
        printf("\nEscolha uma ação:\n");
        printf("[J] Jogar peça\n");
        printf("[R] Reservar peça\n");
        printf("[U] Usar peça reservada\n");
        printf("[S] Sair\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'J':
            case 'j': {
                if (!filaVazia(&fila)) {
                    Peca jogada = desenfileirar(&fila);
                    printf("Peça [%c %d] jogada!\n", jogada.nome, jogada.id);
                    enfileirar(&fila, gerarPeca(id++)); // mantém fila cheia
                } else {
                    printf("Fila vazia!\n");
                }
                break;
            }

            case 'R':
            case 'r': {
                if (pilhaCheia(&pilha)) {
                    printf("Pilha cheia! Não é possível reservar.\n");
                } else if (filaVazia(&fila)) {
                    printf("Fila vazia! Não há peça para reservar.\n");
                } else {
                    Peca reservada = desenfileirar(&fila);
                    empilhar(&pilha, reservada);
                    printf("Peça [%c %d] reservada!\n", reservada.nome, reservada.id);
                    enfileirar(&fila, gerarPeca(id++));
                }
                break;
            }

            case 'U':
            case 'u': {
                if (!pilhaVazia(&pilha)) {
                    Peca usada = desempilhar(&pilha);
                    printf("Peça [%c %d] usada!\n", usada.nome, usada.id);
                } else {
                    printf("Nenhuma peça reservada!\n");
                }
                break;
            }

            case 'S':
            case 's':
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 'S' && opcao != 's');

    return 0;
}



