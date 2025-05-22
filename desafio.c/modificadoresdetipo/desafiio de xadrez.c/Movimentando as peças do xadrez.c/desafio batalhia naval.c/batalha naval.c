#include <stdio.h>

#define TAMANHO 10  // Define o tamanho do tabuleiro
#define HABILIDADE 5 // Valor que representa uma área de efeito

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar habilidades no tabuleiro
void posicionarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tipo) {
    switch(tipo) {
        case 1: // Cone
            for(int i = 0; i < 3; i++) {
                for(int j = -i; j <= i; j++) {
                    if (linha + i < TAMANHO && coluna + j >= 0 && coluna + j < TAMANHO) {
                        tabuleiro[linha + i][coluna + j] = HABILIDADE;
                    }
                }
            }
            break;
        case 2: // Cruz
            for(int i = -2; i <= 2; i++) {
                if (linha + i >= 0 && linha + i < TAMANHO) {
                    tabuleiro[linha + i][coluna] = HABILIDADE;
                }
                if (coluna + i >= 0 && coluna + i < TAMANHO) {
                    tabuleiro[linha][coluna + i] = HABILIDADE;
                }
            }
            break;
        case 3: // Octaedro
            for(int i = -2; i <= 2; i++) {
                for(int j = -2; j <= 2; j++) {
                    if (abs(i) + abs(j) <= 2) {
                        if (linha + i >= 0 && linha + i < TAMANHO && coluna + j >= 0 && coluna + j < TAMANHO) {
                            tabuleiro[linha + i][coluna + j] = HABILIDADE;
                        }
                    }
                }
            }
            break;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro:\n");
    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    inicializarTabuleiro(tabuleiro);
    
    // Posicionando habilidades especiais
    posicionarHabilidade(tabuleiro, 3, 3, 1); // Cone em (3,3)
    posicionarHabilidade(tabuleiro, 5, 5, 2); // Cruz em (5,5)
    posicionarHabilidade(tabuleiro, 7, 7, 3); // Octaedro em (7,7)

    exibirTabuleiro(tabuleiro);

    return 0;
}
