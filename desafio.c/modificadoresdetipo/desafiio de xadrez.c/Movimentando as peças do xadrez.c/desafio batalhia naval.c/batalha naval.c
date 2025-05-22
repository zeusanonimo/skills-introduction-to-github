#include <stdio.h>

#define TAMANHO 10  // Define o tamanho do tabuleiro
#define NAVIO 3      // Valor que representa um navio no tabuleiro

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    // Inicializa o tabuleiro preenchendo com água (0)
    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    // Posiciona um navio horizontalmente
    int linha_horizontal = 2, coluna_horizontal = 4;  
    for(int i = 0; i < 3; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
    }

    // Posiciona um navio verticalmente
    int linha_vertical = 6, coluna_vertical = 7;  
    for(int i = 0; i < 3; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
    }

    // Posiciona um navio diagonal crescente (\)
    int linha_diagonal1 = 1, coluna_diagonal1 = 1;
    for(int i = 0; i < 3; i++) {
        tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] = NAVIO;
    }

    // Posiciona um navio diagonal decrescente (/)
    int linha_diagonal2 = 5, coluna_diagonal2 = 8;
    for(int i = 0; i < 3; i++) {
        tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] = NAVIO;
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    // Exibe o tabuleiro na tela
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
    posicionarNavios(tabuleiro);
    exibirTabuleiro(tabuleiro);

    return 0;
}
