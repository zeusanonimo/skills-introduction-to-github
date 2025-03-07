#include <stdio.h>

int main(){

    //Declaração das variáveis
    char estado1[9] = "São Paulo", estado2[9] = "São Paulo";

    char codigoCarta1[4] = "SP1", codigoCarta2[4] = "OL2";

    char nomeCidade1[50] = "São Paulo", nomeCidade2[50] = "Olímpia";

    int populacao1 = 11450000, populacao2 = 54037;

    float area1 = 1521.5, area2 = 803.2;

    float pib1 = 2.719751, pib2 = 2.55114467;

    int pontosTuristicos1 = 36, pontosTuristicos2 = 13;

    //Exibição dos dados da primeira carta
    printf("\n Dados da Primeira Carta:\n");

    printf("Estado: %s\n", estado1);

    printf("Código da Carta: %s\n", codigoCarta1);

    printf("Nome da Cidade: %s\n", nomeCidade1);

    printf("População: %d habitantes\n", populacao1);

    printf("Área: %.3f Km\n", area1);

    printf("PIB: R$ %.3f\n",pib1);

    printf("Pontos Turísticos: %d\n", pontosTuristicos1);


    //Exibição dos dados da Segunda carta
    printf("\n Dados da Segunda Carta:\n");

    printf("Estado: %s\n", estado2);
    
    printf("Código da Carta: %s\n", codigoCarta2);
    
    printf("Nome da Cidade: %s\n", nomeCidade2);
    
    printf("População: %d habitantes\n", populacao2);
    
    printf("Área: %.3f Km\n", area2);
    
    printf("PIB: R$ %.3f\n",pib2);
    
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    
    
    

    return 0;
}