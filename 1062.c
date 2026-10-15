#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *prox;
} Node;

typedef struct {
    Node *topo;
} Stack;

void push(int x, Stack *p) {
    Node *novo = (Node *) malloc(sizeof(Node));
    novo->info = x;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(int *x, Stack *p) {
    if (p->topo == NULL) return 0;
    Node *aux = p->topo;
    *x = aux->info;
    p->topo = p->topo->prox;
    free(aux);
    return 1;
}

int main() {
    int n, x;
    int target[1005];

    while (scanf("%d", &n) && n != 0) {
        while (scanf("%d", &target[0]) && target[0] != 0) {
            
            for (int i = 1; i < n; i++) {
                scanf("%d", &target[i]);
            }

            Stack station = {NULL};
            int target_idx = 0;
            
            for (int i = 1; i <= n; i++) {
                push(i, &station);
                
                while (station.topo != NULL && station.topo->info == target[target_idx]) {
                    pop(&x, &station);
                    target_idx++;
                }
            }

            if (station.topo == NULL) {
                printf("Yes\n");
            } else {
                printf("No\n");
                while(pop(&x, &station)); 
            }
        }
        printf("\n");
    }

    return 0;
}