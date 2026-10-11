#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node* next;
}Node;

Node* top = NULL;

void push(char value) {
    
    Node* new_node= (Node*) malloc(sizeof(Node));

    new_node ->data = value;
    new_node->next = top;
    top = new_node;
}

char pop(){
    char temp;
    Node *aux;
    if( top == NULL) return '\0';
    else{
        temp = top->data;
        aux = top;
        top = top->next;
        free(aux);
        return temp;
    }
}

int priority(char c){
    switch(c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void convert(char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            printf("%c", c);
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != NULL && top->data != '(') {
                printf("%c", pop());
            }
            if (top != NULL) pop();
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (top != NULL && priority(top->data) >= priority(c)) {
                printf("%c", pop());
            }
            push(c);
        }
    }

    while (top != NULL) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    int N;
    char expression[305];

    if (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) { 
            scanf("%s", expression);
            convert(expression);
        }
    }
    return 0;
}
