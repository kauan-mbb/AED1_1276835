/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Kauan Bócoli
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 04/09/2026
Objetivo    : Jogando Cartas Fora
Dificuldade : 8.5/10
Uso de IA   : Foi necessária para eu entender o esqueleto do algoítimo e parte da lógica
              além de necessária para adequar a formatacao da saida para que o beecrowd aceitasse
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *next;
} Node;

int main(int argc, char const *argv[])
{
    int n;

    while (scanf("%d", &n) && n != 0)
    {
        if (n == 1)
        {
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
            continue;
        }

        Node *start = NULL;
        Node *end = NULL;

        for (int i = 0; i < n; i++)
        {
            Node *new = (Node*) malloc(sizeof(Node));

            new->valor = i + 1;
            new->next = NULL;

            if(start == NULL) {
                start = new;
                end = new;
            }else{
                end->next = new;
                end = new;
            }
        }

        printf("Discarded cards: ");
        int first = 1;

        while (start != end)
        {
            Node *discard = start;
            start = start->next;

            if (!first) {
                printf(", ");
            }
            printf("%d", discard->valor);
            first = 0;

            free(discard);

            if (start == end) break;

            Node *moved = start;
            start = start->next;
            moved -> next = NULL;
            end->next = moved;
            end = end->next;
        }

        printf("\nRemaining card: %d\n", start->valor);
        free(start);
    }
    
    return 0;
}
