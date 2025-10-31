#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura que representa um território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função que exibe todos os territórios
void exibirMapa(Territorio* mapa, int tamanho) {
    printf("\n=== Mapa Atual ===\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Território %d: %s | Cor: %s | Tropas: %d\n", i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Função que realiza um ataque entre dois territórios
void atacar(Territorio* atacante, Territorio* defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Ataque inválido: territórios da mesma cor.\n");
        return;
    }

    int dadoA = rand() % 6 + 1;
    int dadoD = rand() % 6 + 1;

    printf("\nAtaque: %s (dado %d) vs %s (dado %d)\n", atacante->nome, dadoA, defensor->nome, dadoD);

    if (dadoA > dadoD) {
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas /= 2;
        printf("Vitória do atacante! Território conquistado.\n");
    } else {
        if (atacante->tropas > 0) atacante->tropas--;
        printf("Defesa bem-sucedida! Atacante perdeu uma tropa.\n");
    }
}

// Função que atribui uma missão aleatória ao jogador
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
}

// Função que verifica se a missão foi cumprida (lógica simples)
int verificarMissao(char* missao, Territorio* mapa, int tamanho) {
    if (strcmp(missao, "Conquistar 2 territórios da cor azul") == 0) {
        int cont = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "azul") == 0) cont++;
        }
        return cont >= 2;
    } else if (strcmp(missao, "Controlar 3 territórios") == 0) {
        char* cor = mapa[0].cor;
        int cont = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, cor) == 0) cont++;
        }
        return cont >= 3;
    }
    return 0;
}

// Função que libera memória alocada
void liberarMemoria(Territorio* mapa, char* missao1, char* missao2) {
    free(mapa);
    free(missao1);
    free(missao2);
}

int main() {
    srand(time(NULL));

    int total;
    printf("Quantos territórios deseja cadastrar? ");
    scanf("%d", &total);

    // Alocação dinâmica do mapa
    Territorio* mapa = (Territorio*)malloc(total * sizeof(Territorio));
    if (!mapa) {
        printf("Erro de alocação.\n");
        return 1;
    }

    // Cadastro dos territórios
    for (int i = 0; i < total; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", mapa[i].nome);
        printf("Cor do exército: ");
        scanf(" %[^\n]", mapa[i].cor);
        printf("Tropas: ");
        scanf("%d", &mapa[i].tropas);
    }

    // Missões disponíveis
    char* missoes[] = {
        "Conquistar 2 territórios da cor azul",
        "Controlar 3 territórios",
        "Eliminar todas as tropas do território 1",
        "Conquistar o território 2",
        "Ter pelo menos 10 tropas em um território"
    };

    // Alocação e atribuição de missões
    char* missaoJogador1 = (char*)malloc(100 * sizeof(char));
    char* missaoJogador2 = (char*)malloc(100 * sizeof(char));
    atribuirMissao(missaoJogador1, missoes, 5);
    atribuirMissao(missaoJogador2, missoes, 5);

    printf("\nMissão do Jogador 1: %s\n", missaoJogador1);
    printf("Missão do Jogador 2: %s\n", missaoJogador2);

    // Simulação de um turno
    int atacante, defensor;
    printf("\nJogador 1, escolha território atacante (1 a %d): ", total);
    scanf("%d", &atacante);
    printf("Jogador 1, escolha território defensor (1 a %d): ", total);
    scanf("%d", &defensor);
    atacar(&mapa[atacante - 1], &mapa[defensor - 1]);

    exibirMapa(mapa, total);

    // Verificação de vitória
    if (verificarMissao(missaoJogador1, mapa, total)) {
        printf("\n🎉 Jogador 1 venceu! Missão cumprida.\n");
    } else if (verificarMissao(missaoJogador2, mapa, total)) {
        printf("\n🎉 Jogador 2 venceu! Missão cumprida.\n");
    } else {
        printf("\nNenhum jogador cumpriu sua missão ainda.\n");
    }

    liberarMemoria(mapa, missaoJogador1, missaoJogador2);
    return 0;
}



