#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *casas, int n, int destino) {
    int esq = 0;
    int dir = n - 1;
    
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        
        if (casas[meio] == destino) {
            return meio;
        }
        if (casas[meio] < destino) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    return -1;
}

int main() {
    int n, m;

    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    int *casas = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &casas[i]);
    }
    
    long long int tempo_total = 0;
    int atual = 0;                
    int destino;
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &destino);
        
        int indice_destino = busca_binaria(casas, n, destino);
        
        tempo_total += abs(atual - indice_destino);
        
        atual = indice_destino;
    }
    
    printf("%lld\n", tempo_total);
    
    free(casas);
    return 0;
}