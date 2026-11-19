#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dest;
    struct No *next;
} No;

No **adj;    
int *cor;     
int temCiclo;

void addAresta(int u, int v) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) { fprintf(stderr, "Erro de alocacao\n"); exit(1); }
    novo->dest = v;
    novo->next = adj[u];
    adj[u] = novo;
}

void dfs(int u) {
    cor[u] = 1;  
    for (No *p = adj[u]; p != NULL; p = p->next) {
        int v = p->dest;
        if (cor[v] == 1) {       
            temCiclo = 1;
            return;
        }
        if (cor[v] == 0) {
            dfs(v);
            if (temCiclo) return;
        }
    }
    cor[u] = 2;  
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        adj = (No **) malloc((N + 1) * sizeof(No *));
        cor = (int *)  malloc((N + 1) * sizeof(int));
        if (adj == NULL || cor == NULL) {
            fprintf(stderr, "Erro de alocacao\n");
            return 1;
        }

        for (int i = 1; i <= N; i++) {
            adj[i] = NULL;
            cor[i] = 0;
        }

        temCiclo = 0;

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            addAresta(A, B);
        }

        for (int i = 1; i <= N && !temCiclo; i++) {
            if (cor[i] == 0)
                dfs(i);
        }

        printf("%s\n", temCiclo ? "SIM" : "NAO");

        for (int i = 1; i <= N; i++) {
            No *p = adj[i];
            while (p) {
                No *tmp = p;
                p = p->next;
                free(tmp);
            }
        }
        free(adj);
        free(cor);
    }
    return 0;
}