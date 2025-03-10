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

    densidade_invertida2 = area2 *10000000/ populacao2;
    printf("Densidade Populacional Invertida %.3f habitantes/Km²\n", densidade_invertida2);

    superpoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibporcapital2 + densidade_invertida2;
    printf("Super Poder: %f\n", superpoder2);

    printf("\nComparando as Cartas\n");
    
    // Comparando valores
    int comp_populacao1_maior = populacao1 > populacao2;
    int comp_populacao1_menor = populacao1 < populacao2;
    int comp_area1_maior = area1 > area2;
    int comp_area1_menor = area1 < area2;
    int comp_pib1_maior = pib1 > pib2;
    int comp_pib1_menor = pib1 < pib2;
    int comp_pontos_turisticos1_maior = pontosTuristicos1 > pontosTuristicos2;
    int comp_pontos_turisticos1_menor = pontosTuristicos1 < pontosTuristicos2;
    int comp_densidade_invertida1_maior = densidade_invertida1 > densidade_invertida2;
    int comp_densidade_invertida1_menor = densidade_invertida1 < densidade_invertida2;

    printf("População 1(%u): é maior que População 2(%u):\n", populacao1, populacao2,comp_populacao1_maior);
    
    printf("População 1(%u): é menor que População 2(%u):\n", populacao1, populacao2,comp_populacao1_menor);
    

    printf("Área 1 (%.3f) é maior que Área 2 (%.3f)\n", area1, area2,comp_area1_maior);
    printf("Área 1 (%.3f) é menor que Área 2 (%.3f)\n", area1, area2,comp_area1_menor);
        
    printf("PIB 1 (%.3f) é maior que PIB 2 (%.3f)\n", pib1, pib2,comp_pib1_maior);
    printf("PIB 1 (%.3f) é menor que PIB 2 (%.3f)\n", pib1, pib2,comp_area1_menor);

    printf("Pontos Turísticos 1 (%d) é maiores que Pontos Turísticos 2 (%d)\n", pontosTuristicos1, comp_pontos_turisticos1_maior);
    printf("Pontos Turísticos 1 (%d) é menor que Pontos Turísticos 2 (%d)\n", pontosTuristicos1, comp_pontos_turisticos1_menor);


    printf("Densidade Populacional Invertida 1 (%.6f) é maior que Densidade Populacional Invertida 2 (%.6f)\n", densidade_invertida1, densidade_invertida2, comp_densidade_invertida1_maior);
    printf("Densidade Populacional Invertida 1 (%.6f) é menor que Densidade Populacional Invertida 2 (%.6f)\n", densidade_invertida1, densidade_invertida2, comp_area1_menor);



    
    return 0;
}