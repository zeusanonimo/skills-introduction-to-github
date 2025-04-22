#include <stdio.h>

int main(){

    //Declaração das variáveis
    char estado1[20] = "São Paulo", estado2[20] = "São Paulo";

    char codigoCarta1[4] = "SP1", codigoCarta2[4] = "OL2";

    char nomeCidade1[50] = "São Paulo", nomeCidade2[50] = "Olímpia";

    unsigned int populacao1 = 11450000, populacao2 = 54037;

    float area1 = 1521.5, area2 = 803.2;

    float pib1 = 2.719751, pib2 = 2.55114467;

    int pontosTuristicos1 = 36, pontosTuristicos2 = 13;

    //Novas variaveis
    
    float densidadePopulacional1, densidadePopulacional2;

    float pibporcapital1, pibporcapital2;

    // Nova variavel; Densidade populacional invertida, simplicada por densidade_invertida

    float densidade_invertida1, densidade_invertida2;

    // Nova variavel; Super Poder, é a soma de todos os atributos numericos da carta

    float superpoder1, superpoder2;


    
    //Exibição dos dados da primeira carta
    printf("\n Dados da Primeira Carta:\n");

    printf("Estado: %s\n", estado1);

    printf("Código da Carta: %s\n", codigoCarta1);

    printf("Nome da Cidade: %s\n", nomeCidade1);

    printf("População: %u habitantes\n", populacao1);

    printf("Área: %.3f Km²\n", area1);

    printf("PIB: R$ %.3f bilhões\n",pib1);

    printf("Pontos Turísticos: %d\n", pontosTuristicos1);

    //Incluindo novos dado na carta 1

    densidadePopulacional1 = populacao1/ area1;
    printf("Densidade Pulacional 1: %2f habitantes/Km²\n", densidadePopulacional1);

    pibporcapital1 = pib1 *1000000000/ populacao1;
    printf("PIB por Capital 1: R$ %2f\n", pibporcapital1);

    densidade_invertida1 = area1 *1000000/ populacao1;
    printf("Densidade Populacional Invertida: %.3f habitantes/Km²\n", densidade_invertida1);

    superpoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibporcapital1 + densidade_invertida1;
    printf("Super Poder: %f\n", superpoder1);



    //Exibição dos dados da Segunda carta
    printf("\n Dados da Segunda Carta:\n");

    printf("Estado: %s\n", estado2);
    
    printf("Código da Carta: %s\n", codigoCarta2);
    
    printf("Nome da Cidade: %s\n", nomeCidade2);
    
    printf("População: %u habitantes\n", populacao2);
    
    printf("Área: %.3f Km²\n", area2);
    
    printf("PIB: R$ %.3f bilhões\n",pib2);
    
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);

    //Incluindo novos dados na carta 2
    
    densidadePopulacional2 = populacao2/ area2;
    printf("Densidade Populacional 2: %.3f habitantes/Km²\n", densidadePopulacional2);

    pibporcapital2 = pib2 *1000000000/ populacao2;
    printf("PIB por Capital 2: R$ %.2f\n", pibporcapital2);

    densidade_invertida2 = area2 *100/ populacao2;
    printf("Densidade Populacional Invertida %.6f habitantes/Km²\n", densidade_invertida2);

    superpoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibporcapital2 + densidade_invertida2;
    printf("Super Poder: %f\n", superpoder2);


    // Comparações usando switch
    printf("\nComparações entre as Cartas:\n");

    int opcao; // Opção para definir o tipo de comparação
    printf("Escolha uma comparação:\n");
    printf("1 - População\n2 - Área\n3 - Pontos Turísticos\n4 - Super Poder\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: // Comparação de população
            if (populacao1 > populacao2) {
                printf("População 1 (%u habitantes) é maior que População 2 (%u habitantes).\n", populacao1, populacao2);
            } else if (populacao1 < populacao2) {
                printf("População 1 (%u habitantes) é menor que População 2 (%u habitantes).\n", populacao1, populacao2);
            } else {
                printf("Ambas as cidades têm a mesma população (%u habitantes).\n", populacao1);
            }
            break;

        case 2: // Comparação de área
            if (area1 > area2) {
                printf("Área 1 (%.2f Km²) é maior que Área 2 (%.2f Km²).\n", area1, area2);
            } else if (area1 < area2) {
                printf("Área 1 (%.2f Km²) é menor que Área 2 (%.2f Km²).\n", area1, area2);
            } else {
                printf("Ambas as cidades têm a mesma área (%.2f Km²).\n", area1);
            }
            break;

        case 3: // Comparação de pontos turísticos
            if (pontosTuristicos1 > pontosTuristicos2) {
                printf("Carta 1 tem mais pontos turísticos (%d) que Carta 2 (%d).\n", pontosTuristicos1, pontosTuristicos2);
            } else if (pontosTuristicos1 < pontosTuristicos2) {
                printf("Carta 1 tem menos pontos turísticos (%d) que Carta 2 (%d).\n", pontosTuristicos1, pontosTuristicos2);
            } else {
                printf("Ambas as cartas têm o mesmo número de pontos turísticos (%d).\n", pontosTuristicos1);
            }
            break;

        case 4: // Comparação de super poder
            if (superpoder1 > superpoder2) {
                printf("Super Poder da Carta 1 (%.2f) é maior que o da Carta 2 (%.2f).\n", superpoder1, superpoder2);
            } else if (superpoder1 < superpoder2) {
                printf("Super Poder da Carta 1 (%.2f) é menor que o da Carta 2 (%.2f).\n", superpoder1, superpoder2);
            } else {
                printf("Ambas as cartas têm o mesmo Super Poder (%.2f).\n", superpoder1);
            }
            break;

        default: // Caso a opção seja inválida
            printf("Opção inválida. Por favor, escolha entre 1 e 4.\n");
            break;
    }

    return 0;
}