#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMP 20

typedef struct {
    char nome[30];     // ex: "chip central"
    char tipo[20];     // ex: "controle", "suporte", "propulsao"
    int prioridade;    // de 1 a 10
} Componente;

// Vetor principal
Componente comps[MAX_COMP];
int n = 0;

// Contadores de comparações (resetados por operação)
long compsBubble = 0;
long compsInsertion = 0;
long compsSelection = 0;
long compsBuscaBinaria = 0;

// Flags de estado
int estaOrdenadoPorNome = 0; // habilita busca binária apenas quando ordenado por nome

// ------------------------- Utilidades -------------------------

// Remove '\n' do final lido por fgets
void trimnl(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') s[len-1] = '\0';
}

// Troca dois componentes
void swap(Componente *a, Componente *b) {
    Componente t = *a; *a = *b; *b = t;
}

// Exibe vetor de componentes
void mostrarComponentes(Componente v[], int m) {
    printf("\n=== Componentes (%d) ===\n", m);
    for (int i = 0; i < m; i++) {
        printf("%2d) Nome: %-20s | Tipo: %-12s | Prioridade: %d\n",
               i+1, v[i].nome, v[i].tipo, v[i].prioridade);
    }
    printf("=========================\n\n");
}

// Reseta contadores
void resetContadores() {
    compsBubble = compsInsertion = compsSelection = compsBuscaBinaria = 0;
}

// ------------------------- Cadastro -------------------------

void cadastrarComponentes() {
    int qtd;
    printf("Quantos componentes deseja cadastrar (1-%d)? ", MAX_COMP);
    scanf("%d", &qtd); getchar(); // consome '\n'

    if (qtd < 1 || qtd > MAX_COMP) {
        printf("Quantidade invalida.\n");
        return;
    }
    n = 0;
    for (int i = 0; i < qtd; i++) {
        Componente c;
        printf("\nComponente #%d\n", i+1);

        printf("Nome: "); fgets(c.nome, sizeof(c.nome), stdin); trimnl(c.nome);
        printf("Tipo: "); fgets(c.tipo, sizeof(c.tipo), stdin); trimnl(c.tipo);

        printf("Prioridade (1-10): ");
        scanf("%d", &c.prioridade); getchar();

        if (c.prioridade < 1) c.prioridade = 1;
        if (c.prioridade > 10) c.prioridade = 10;

        comps[n++] = c;
    }
    estaOrdenadoPorNome = 0;
    mostrarComponentes(comps, n);
}

// ------------------------- Ordenações -------------------------

// Bubble sort por NOME (string)
void bubbleSortNome(Componente v[], int m) {
    resetContadores();
    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < m-1-i; j++) {
            compsBubble++;
            if (strcmp(v[j].nome, v[j+1].nome) > 0) swap(&v[j], &v[j+1]);
        }
    }
    estaOrdenadoPorNome = 1;
}

// Insertion sort por TIPO (string)
void insertionSortTipo(Componente v[], int m) {
    resetContadores();
    for (int i = 1; i < m; i++) {
        Componente key = v[i];
        int j = i - 1;
        while (j >= 0) {
            compsInsertion++;
            if (strcmp(v[j].tipo, key.tipo) > 0) {
                v[j+1] = v[j]; j--;
            } else break;
        }
        v[j+1] = key;
    }
    estaOrdenadoPorNome = 0;
}

// Selection sort por PRIORIDADE (int)
void selectionSortPrioridade(Componente v[], int m) {
    resetContadores();
    for (int i = 0; i < m-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < m; j++) {
            compsSelection++;
            if (v[j].prioridade < v[minIdx].prioridade) minIdx = j;
        }
        if (minIdx != i) swap(&v[i], &v[minIdx]);
    }
    estaOrdenadoPorNome = 0;
}

// ------------------------- Busca Binária -------------------------

int buscaBinariaPorNome(Componente v[], int m, const char alvo[]) {
    compsBuscaBinaria = 0;
    if (!estaOrdenadoPorNome) {
        printf("Aviso: vetor nao esta ordenado por nome. Ordene com Bubble Sort antes.\n");
        return -1;
    }

    int ini = 0, fim = m - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        compsBuscaBinaria++;
        int c = strcmp(v[meio].nome, alvo);
        if (c == 0) return meio;
        else if (c < 0) ini = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

// ------------------------- Medição de tempo -------------------------

// Executa um algoritmo de ordenação e mede tempo (em ms)
double medirTempoOrdenacao(void (*alg)(Componente[], int), Componente v[], int m) {
    clock_t start = clock();
    alg(v, m);
    clock_t end = clock();
    return ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;
}

// ------------------------- Menu -------------------------

void menuOrdenar() {
    int op;
    do {
        printf("\n--- Ordenacao ---\n");
        printf("1) Bubble sort (por nome)\n");
        printf("2) Insertion sort (por tipo)\n");
        printf("3) Selection sort (por prioridade)\n");
        printf("0) Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op); getchar();

        if (op == 1) {
            // Copia de trabalho para medir tempo (opcional usar o próprio vetor)
            double ms = medirTempoOrdenacao(bubbleSortNome, comps, n);
            mostrarComponentes(comps, n);
            printf("Comparacoes (Bubble/Nome): %ld | Tempo: %.3f ms\n", compsBubble, ms);
        } else if (op == 2) {
            double ms = medirTempoOrdenacao(insertionSortTipo, comps, n);
            mostrarComponentes(comps, n);
            printf("Comparacoes (Insertion/Tipo): %ld | Tempo: %.3f ms\n", compsInsertion, ms);
        } else if (op == 3) {
            double ms = medirTempoOrdenacao(selectionSortPrioridade, comps, n);
            mostrarComponentes(comps, n);
            printf("Comparacoes (Selection/Prioridade): %ld | Tempo: %.3f ms\n", compsSelection, ms);
        }
    } while (op != 0);
}

void menuBuscaBinaria() {
    if (n == 0) { printf("Nenhum componente cadastrado.\n"); return; }
    char alvo[30];
    printf("Nome do componente-chave para buscar: ");
    fgets(alvo, sizeof(alvo), stdin); trimnl(alvo);

    int idx = buscaBinariaPorNome(comps, n, alvo);
    if (idx >= 0) {
        printf("Componente-chave ENCONTRADO!\n");
        printf("Nome: %s | Tipo: %s | Prioridade: %d\n",
               comps[idx].nome, comps[idx].tipo, comps[idx].prioridade);
    } else {
        printf("Componente-chave NAO encontrado.\n");
    }
    printf("Comparacoes (Busca Binaria/Nome): %ld\n", compsBuscaBinaria);
}

int main() {
    int op;
    do {
        printf("\n=== Torre de Fuga: Organizacao Avancada ===\n");
        printf("1) Cadastrar componentes\n");
        printf("2) Mostrar componentes\n");
        printf("3) Ordenar (escolher estrategia)\n");
        printf("4) Buscar binaria por NOME (requer ordenar por nome)\n");
        printf("0) Sair\n");
        printf("Escolha: ");
        scanf("%d", &op); getchar();

        if (op == 1) cadastrarComponentes();
        else if (op == 2) mostrarComponentes(comps, n);
        else if (op == 3) menuOrdenar();
        else if (op == 4) menuBuscaBinaria();
    } while (op != 0);

    printf("Encerrado.\n");
    return 0;
}
