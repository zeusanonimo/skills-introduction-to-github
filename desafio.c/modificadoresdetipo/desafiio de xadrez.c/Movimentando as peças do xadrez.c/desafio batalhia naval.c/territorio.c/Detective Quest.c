#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_SIZE 17 // primo pequeno para distribuir chaves

// =========================
// Estruturas de dados
// =========================

typedef struct Sala {
    char nome[50];
    char pista[100];    // pista associada à sala (string estática definida no código)
    struct Sala* e;     // esquerda
    struct Sala* d;     // direita
} Sala;

typedef struct BSTPista {
    char pista[100];
    struct BSTPista* esq;
    struct BSTPista* dir;
} BSTPista;

typedef struct SusNode {
    char pista[100];         // chave
    char suspeito[50];       // valor
    struct SusNode* next;    // encadeamento para colisões
} SusNode;

typedef struct {
    SusNode* buckets[HASH_SIZE];
} HashTable;

// =========================
// Utilidades
// =========================

void toLowerStr(char* s) {
    for (; *s; ++s) *s = (char)tolower((unsigned char)*s);
}

unsigned long hashFunc(const char* key) {
    // djb2 simplificado
    unsigned long h = 5381;
    for (const unsigned char* p = (const unsigned char*)key; *p; ++p)
        h = ((h << 5) + h) + *p; // h*33 + c
    return h % HASH_SIZE;
}

// =========================
// Árvore binária (Mapa)
// =========================

Sala* criarSala(const char* nome, const char* pista) {
    Sala* s = (Sala*)malloc(sizeof(Sala));
    if (!s) { printf("Falha ao alocar Sala.\n"); exit(1); }
    strcpy(s->nome, nome);
    strcpy(s->pista, pista);
    s->e = s->d = NULL;
    return s;
}

// =========================
// BST de Pistas
// =========================

BSTPista* inserirPista(BSTPista* raiz, const char* pista) {
    if (!raiz) {
        BSTPista* n = (BSTPista*)malloc(sizeof(BSTPista));
        if (!n) { printf("Falha ao alocar BSTPista.\n"); exit(1); }
        strcpy(n->pista, pista);
        n->esq = n->dir = NULL;
        return n;
    }
    int c = strcmp(pista, raiz->pista);
    if (c < 0) raiz->esq = inserirPista(raiz->esq, pista);
    else if (c > 0) raiz->dir = inserirPista(raiz->dir, pista);
    // se igual, não duplica (pistas repetidas podem ser ignoradas para o set)
    return raiz;
}

void exibirPistasInOrder(BSTPista* raiz) {
    if (!raiz) return;
    exibirPistasInOrder(raiz->esq);
    printf("- %s\n", raiz->pista);
    exibirPistasInOrder(raiz->dir);
}

// Conta pistas da BST que apontam para um suspeito consultando a hash
int contarPistasPorSuspeito(BSTPista* raiz, HashTable* ht, const char* suspeito);

// =========================
// Tabela Hash (pista -> suspeito)
// =========================

void initHash(HashTable* ht) {
    for (int i = 0; i < HASH_SIZE; i++) ht->buckets[i] = NULL;
}

void inserirNaHash(HashTable* ht, const char* pista, const char* suspeito) {
    unsigned long idx = hashFunc(pista);
    SusNode* n = (SusNode*)malloc(sizeof(SusNode));
    if (!n) { printf("Falha ao alocar SusNode.\n"); exit(1); }
    strcpy(n->pista, pista);
    strcpy(n->suspeito, suspeito);
    n->next = ht->buckets[idx];
    ht->buckets[idx] = n;
}

const char* encontrarSuspeito(HashTable* ht, const char* pista) {
    unsigned long idx = hashFunc(pista);
    SusNode* cur = ht->buckets[idx];
    while (cur) {
        if (strcmp(cur->pista, pista) == 0) return cur->suspeito;
        cur = cur->next;
    }
    return NULL;
}

// =========================
// Exploração e julgamento
// =========================

void explorarSalas(Sala* atual, BSTPista** pistas, HashTable* ht) {
    char escolha;
    while (atual) {
        printf("\nVocê está na sala: %s\n", atual->nome);
        if (strlen(atual->pista) > 0) {
            printf("Pista encontrada: %s\n", atual->pista);
            *pistas = inserirPista(*pistas, atual->pista);
            // a hash já está populada com associações pista->suspeito (estáticas)
            const char* sus = encontrarSuspeito(ht, atual->pista);
            if (sus) printf("Associação registrada: [%s] -> Suspeito [%s]\n", atual->pista, sus);
        }
        printf("Escolha (e = esquerda, d = direita, s = sair): ");
        scanf(" %c", &escolha);
        if (escolha == 'e') {
            if (atual->e) atual = atual->e;
            else printf("Não há sala à esquerda.\n");
        } else if (escolha == 'd') {
            if (atual->d) atual = atual->d;
            else printf("Não há sala à direita.\n");
        } else if (escolha == 's') {
            printf("Exploração encerrada.\n");
            break;
        } else {
            printf("Opção inválida.\n");
        }
    }
}

int contarPistasPorSuspeito(BSTPista* raiz, HashTable* ht, const char* suspeito) {
    if (!raiz) return 0;
    int left = contarPistasPorSuspeito(raiz->esq, ht, suspeito);
    int right = contarPistasPorSuspeito(raiz->dir, ht, suspeito);
    const char* s = encontrarSuspeito(ht, raiz->pista);
    int match = (s && strcmp(s, suspeito) == 0) ? 1 : 0;
    return left + right + match;
}

void verificarSuspeitoFinal(BSTPista* pistas, HashTable* ht) {
    char acusado[50];
    printf("\n=== Fase final: acusação ===\n");
    printf("Suspeitos disponíveis (exemplo): Alice, Bruno, Carla\n");
    printf("Acuse um suspeito: ");
    scanf(" %49[^\n]", acusado);

    int evidencias = contarPistasPorSuspeito(pistas, ht, acusado);
    printf("Total de pistas que apontam para %s: %d\n", acusado, evidencias);
    if (evidencias >= 2) {
        printf("Veredito: acusação sustentada. Caso encerrado!\n");
    } else {
        printf("Veredito: evidências insuficientes. Continue investigando.\n");
    }
}

// =========================
// Montagem e execução
// =========================

int main() {
    // Mapa fixo da mansão (árvore binária)
    Sala* hall       = criarSala("Hall de Entrada", "Pegadas misteriosas");
    Sala* estar      = criarSala("Sala de Estar",   "Copo quebrado");
    Sala* cozinha    = criarSala("Cozinha",         "Faca ensanguentada");
    Sala* jardim     = criarSala("Jardim",          "Pegada de sapato");
    Sala* biblioteca = criarSala("Biblioteca",      "Carta rasgada");
    Sala* escritorio = criarSala("Escritório",      "Agenda com horários");

    // Estrutura da árvore:
    //           hall
    //        /        \
    //     estar      cozinha
    //    /    \           \
    // jardim  biblioteca   escritorio
    hall->e = estar;        hall->d = cozinha;
    estar->e = jardim;      estar->d = biblioteca;
    cozinha->d = escritorio;

    // Tabela hash: pista -> suspeito (estática para o desafio)
    HashTable ht; initHash(&ht);
    inserirNaHash(&ht, "Pegadas misteriosas", "Bruno");
    inserirNaHash(&ht, "Copo quebrado", "Alice");
    inserirNaHash(&ht, "Faca ensanguentada", "Bruno");
    inserirNaHash(&ht, "Pegada de sapato", "Carla");
    inserirNaHash(&ht, "Carta rasgada", "Alice");
    inserirNaHash(&ht, "Agenda com horários", "Carla");

    // BST de pistas coletadas
    BSTPista* pistas = NULL;

    // Exploração
    printf("Bem-vindo ao Detective Quest (nível mestre)!\n");
    explorarSalas(hall, &pistas, &ht);

    // Listar pistas coletadas
    printf("\n=== Pistas coletadas (ordem alfabética) ===\n");
    exibirPistasInOrder(pistas);

    // Julgamento final
    verificarSuspeitoFinal(pistas, &ht);

    // Observação: liberação de memória dos nós poderia ser implementada (free em árvore e hash).
    return 0;
}
