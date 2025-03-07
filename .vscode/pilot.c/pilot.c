#include <stdio.h>

int main() {
    // Declaração das variáveis
    char estado1[13] = "São Paulo", estado2[13] = "São Paulo";
    char codigoCarta1[4] = "SP1", codigoCarta2[4] = "SP2";
    char nomeCidade1[10] = "São Paulo", nomeCidade2[50] = "Olímpia";
    double populacao1 = 11.450000000, populacao2 = 54.037;
    float area1 = 1521.5, area2 = 803.2;
    float pib1 = 2.719751, pib2 = 2.55114467;
    int pontosTuristicos1 = 36, pontosTuristicos2 = 30;

    // Exibição dos dados da primeira carta
    printf("\nDados da Primeira Carta:\n");

    printf("Estado: %s\n", estado1);
    printf("Código da Carta: %s\n", codigoCarta1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %.2f habitantes\n", populacao1);
    printf("Área: %.2f Km\n", area1);
    printf("PIB: R$ %.2f\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);

    return 0;
}
