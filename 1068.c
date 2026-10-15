#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char valor;
    struct Node *next;
} Node;

int main(int argc, char const *argv[])
{
    char expressao[1005];

    while (scanf("%s", expressao) != EOF)
    {
        Node *top = NULL;
        int erro = 0;

        for (int i = 0; expressao[i] != '\0'; i++)
        {
            if (expressao[i] == '(')
            {
                Node *new = (Node*) malloc(sizeof(Node));
                new->valor = '(';
                new->next = top;
                top = new;
            }
            else if (expressao[i] == ')')
            {
                if (top == NULL) 
                {
                    erro = 1;
                    break;
                }
                else 
                {
                    Node *discard = top;
                    top = top->next;
                    free(discard);
                }
            }
        }
        if (top != NULL)
        {
            erro = 1;
    
            while (top != NULL)
            {
                Node *discard = top;
                top = top->next;
                free(discard);
            }
        }

        if (erro)
        {
            printf("incorrect\n");
        }
        else
        {
            printf("correct\n");
        }
    }

    return 0;
}