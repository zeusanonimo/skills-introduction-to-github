#include <stdio.h>

int main(){

    //Declaração das variáveis
    char estado1[20] = "São Paulo", estado2[20] = "São Paulo";

    char codigoCarta1[4] = "SP1", codigoCarta2[4] = "OL2";

    char nomeCidade1[50] = "São Paulo", nomeCidade2[50] = "Olímpia";

    int populacao1 = 11450000, populacao2 = 54037;

    float area1 = 1521.5, area2 = 803.2;

    float pib1 = 2.719751, pib2 = 2.55114467;

    int pontosTuristicos1 = 36, pontosTuristicos2 = 13;

    //Novas variaveis
    
    float densidadePopulacional1, densidadePopulacional2;

    float pibporcapital1, pibporcapital2;


    
    //Exibição dos dados da primeira carta
    printf("\n Dados da Primeira Carta:\n");

    printf("Estado: %s\n", estado1);

    printf("Código da Carta: %s\n", codigoCarta1);

    printf("Nome da Cidade: %s\n", nomeCidade1);

    printf("População: %d habitantes\n", populacao1);

    printf("Área: %.3f Km\n", area1);

    printf("PIB: R$ %.3f\n",pib1);

    printf("Pontos Turísticos: %d\n", pontosTuristicos1);

    //Incluindo novos dado na carta 1

    densidadePopulacional1 = populacao1/ area1;
    printf("Densidade Pulacional 1: %2f habitantes/Km²\n", densidadePopulacional1);

    pibporcapital1 = pib1 *1000000000/ populacao1;
    printf("PIB por Capital 1: R$ %2f\n", pibporcapital1);



    //Exibição dos dados da Segunda carta
    printf("\n Dados da Segunda Carta:\n");

    printf("Estado: %s\n", estado2);
    
    printf("Código da Carta: %s\n", codigoCarta2);
    
    printf("Nome da Cidade: %s\n", nomeCidade2);
    
    printf("População: %d habitantes\n", populacao2);
    
    printf("Área: %.3f Km\n", area2);
    
    printf("PIB: R$ %.3f\n",pib2);
    
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);

    //Incluindo novos dados na carta 2
    
    densidadePopulacional2 = populacao2/ area2;
    printf("Densidade Populacional 2: %2f habitantes/Km²\n", densidadePopulacional2);

    pibporcapital2 = pib2 *1000000000/ populacao2;
    printf("PIB por Capital 2: R$ %2f\n", pibporcapital2);



    return 0;
}