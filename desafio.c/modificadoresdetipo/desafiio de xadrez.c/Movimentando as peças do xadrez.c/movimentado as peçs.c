#include <stdio.h>

// Função recursiva para movimentação da Torre (5 casas para a direita)
void moverTorre(int casas) {
    if (casas > 0) {
        printf("Direita\n");
        moverTorre(casas - 1);
    }
}

// Função recursiva para movimentação da Rainha (8 casas para a esquerda)
void moverRainha(int casas) {
    if (casas > 0) {
        printf("Esquerda\n");
        moverRainha(casas - 1);
    }
}

// Função recursiva para movimentação do Bispo (5 casas na diagonal para cima e à direita)
void moverBispo(int casas, int movimentosVerticais) {
    if (casas > 0) {
        printf("Cima, Direita\n");
        moverBispo(casas - 1, movimentosVerticais);
    }
}

// Movimento do Cavalo: 2 casas para cima e 1 para a direita, com loops aninhados e controle de fluxo
void moverCavalo() {
    printf("\nMovimento do Cavalo:\n");
    
    for (int i = 0; i < 2; i++) {  // Duas casas para cima
        printf("Cima\n");
    }
    
    for (int j = 0; j < 1; j++) {  // Uma casa para a direita
        printf("Direita\n");
    }
}

int main() {
    printf("Movimento da Torre:\n");
    moverTorre(5);

    printf("\nMovimento do Bispo:\n");
    moverBispo(5, 5);

    printf("\nMovimento da Rainha:\n");
    moverRainha(8);

    moverCavalo();

    return 0;
}
