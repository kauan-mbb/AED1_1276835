#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, maior, pos;

    scanf("%d", &n);

    int *v = (int *) malloc(n * sizeof(int));

    if (v == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);

        if (i == 0 || v[i] > maior) {
            maior = v[i];
            pos = i + 1;
        }
    }

    printf("%d\n", maior);
    printf("%d\n", pos);

    free(v);

    return 0;
}