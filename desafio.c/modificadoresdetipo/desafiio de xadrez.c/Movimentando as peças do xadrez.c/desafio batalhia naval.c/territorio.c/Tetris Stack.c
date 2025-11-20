#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILA 5
#define MAX_PILHA 3

// Struct que representa uma peça
typedef struct {
    char nome; // tipo da peça ('I','O','T','L')
    int id;    // identificador único
} Peca;

// Variáveis globais da fila
Peca fila[MAX_FILA];
int frente = 0, tras = 0, qtdFila = 0;
int contadorID = 0;

// Variáveis globais da pilha
Peca pilha[MAX_PILHA];
int topo = -1;

// Função que gera peça aleatória
Peca gerarPeca() {
    Peca nova;
    char tipos[] = {'I','O','T','L'};
    nova.nome = tipos[rand() % 4];
    nova.id = contadorID++;
    return nova;
}

// Enfileirar peça
void enqueue() {
    if (qtdFila == MAX_FILA) return;
    Peca nova = gerarPeca();
    fila[tras] = nova;
    tras = (tras + 1) % MAX_FILA;
    qtdFila++;
}

// Desenfileirar peça
Peca dequeue() {
    Peca removida = {'X', -1};
    if (qtdFila == 0) return removida;
    removida = fila[frente];
    frente = (frente + 1) % MAX_FILA;
    qtdFila--;
    enqueue(); // mantém fila cheia
    return removida;
}

// Empilhar peça
void push(Peca p) {
    if (topo == MAX_PILHA - 1) {
        printf("Pilha cheia!\n");
        return;
    }
    pilha[++topo] = p;
}

// Desempilhar peça
Peca pop() {
    Peca removida = {'X', -1};
    if (topo == -1) {
        printf("Pilha vazia!\n");
        return removida;
    }
    removida = pilha[topo--];
    return removida;
}

// Trocar peça atual (frente da fila com topo da pilha)
void trocarAtual() {
    if (qtdFila == 0 || topo == -1) {
        printf("Não há peças suficientes para troca.\n");
        return;
    }
    Peca temp = fila[frente];
    fila[frente] = pilha[topo];
    pilha[topo] = temp;
    printf("Troca realizada entre frente da fila e topo da pilha.\n");
}

// Troca múltipla (3 primeiras da fila com 3 da pilha)
void trocaMultipla() {
    if (qtdFila < 3 || topo < 2) {
        printf("Não há peças suficientes para troca múltipla.\n");
        return;
    }
    for (int i = 0; i < 3; i++) {
        int idxFila = (frente + i) % MAX_FILA;
        Peca temp = fila[idxFila];
        fila[idxFila] = pilha[topo - i];
        pilha[topo - i] = temp;
    }
    printf("Troca múltipla realizada!\n");
}

// Mostrar estado atual
void mostrarEstado() {
    printf("\n=== Estado atual ===\n");
    printf("Fila de peças: ");
    if (qtdFila == 0) printf("[vazia]");
    else {
        int i = frente;
        for (int c = 0; c < qtdFila; c++) {
            printf("[%c %d] ", fila[i].nome, fila[i].id);
            i = (i + 1) % MAX_FILA;
        }
    }
    printf("\nPilha de reserva (Topo -> Base): ");
    if (topo == -1) printf("[vazia]");
    else {
        for (int i = topo; i >= 0; i--) {
            printf("[%c %d] ", pilha[i].nome, pilha[i].id);
        }
    }
    printf("\n====================\n\n");
}

// Função principal
int main() {
    srand(time(NULL));
    for (int i = 0; i < MAX_FILA; i++) enqueue();

    int opcao;
    do {
        mostrarEstado();
        printf("Opções:\n");
        printf("1 - Jogar peça da frente da fila\n");
        printf("2 - Reservar peça (fila -> pilha)\n");
        printf("3 - Usar peça reservada (pilha)\n");
        printf("4 - Trocar peça atual (fila <-> pilha)\n");
        printf("5 - Troca múltipla (3 da fila <-> 3 da pilha)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Peca jogada = dequeue();
                if (jogada.id != -1)
                    printf("Peça [%c %d] jogada!\n", jogada.nome, jogada.id);
                break;
            }
            case 2: {
                if (qtdFila > 0) {
                    Peca reservada = dequeue();
                    push(reservada);
                    printf("Peça [%c %d] reservada!\n", reservada.nome, reservada.id);
                }
                break;
            }
            case 3: {
                Peca usada = pop();
                if (usada.id != -1)
                    printf("Peça [%c %d] usada da reserva!\n", usada.nome, usada.id);
                break;
            }
            case 4: trocarAtual(); break;
            case 5: trocaMultipla(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}