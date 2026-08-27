/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Kauan Bócoli
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 24/08/2026
Objetivo    : Leia 100 valores inteiros. Apresente então o maior valor lido e a posição dentre os 100 valores lidos.
Dificuldade : Foi um bom exercicio para relembrar sintaxe e aquecer.
Uso de IA   : Nenhum
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {
  int v[100], maior, pos;

  for (int i = 0; i < 100; i++)
  {
    scanf("%d", &v[i]);

    if (i == 0 || v[i] > maior)
    {
      maior = v[i];
      pos = i + 1;
    }

  }

  printf("%d\n", maior);
  printf("%d\n", pos);
}