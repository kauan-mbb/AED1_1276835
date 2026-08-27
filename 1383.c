/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Kauan Bócoli
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 24/08/2026
Objetivo    : Ler n instancias de um sudoku, averiguando se a resolucao esta correta
Dificuldade : Salto ENORME de dificuldade em relacao ao exercicio anterior. Confesso que foi mais dificil que 90%
              dos algoritimos que criei com a Ana Luiza ano passado.
Uso de IA   : Precisei da IA para compreender a logica da verificacao 3x3.
-------------------------------------------------------------------------- */

#include <stdio.h>

int grupoValido(int v[9]) {
    int visitado[10] = {0};

    for (int i = 0; i < 9; i++) {
        int num = v[i];

        if (num < 1 || num > 9 || visitado[num] == 1) {
            return 0;
        }

        visitado[num] = 1;
    }

    return 1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int k = 1; k <= n; k++) {
        int matriz[9][9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        int valido = 1;

        for (int l = 0; l < 9; l++) {
            if (grupoValido(matriz[l]) == 0) {
                valido = 0;
            }
        }

        for (int c = 0; c < 9; c++) {
            int temp[9];
            for (int l = 0; l < 9; l++) {
                temp[l] = matriz[l][c];
            }

            if (grupoValido(temp) == 0) {
                valido = 0;
            }
        }

        for (int bi = 0; bi < 9; bi += 3) {
            for (int bj = 0; bj < 9; bj += 3) {
                int temp[9];
                int k_temp = 0;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        temp[k_temp] = matriz[bi + i][bj + j];
                        k_temp++;
                    }
                }

                if (grupoValido(temp) == 0) {
                    valido = 0;
                }
            }
        }

        printf("Instancia %d\n", k);
        if (valido) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}