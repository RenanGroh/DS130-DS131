/*
Escrever   a   função  int   testavalores(int   inicio,   int   fim,   int   *pares,   int
*impares) que retorna quantos números inteiros existem no intervalo definido
pelos parâmetros inicio e fim (inclusive ambos) e armazena, nos parâmetros
pares e impares (passados por referência) quantos destes valores são pares e
impares, respectivamente. Implemente a chamada da função na main.
*/

#include <stdio.h>


int testavalores(int inicio, int fim, int *pares, int *impares) {
    int total = 0;
    *pares = 0;
    *impares = 0;

    for (int i = inicio; i <= fim; i++) {
        total++;
        if (i % 2 == 0) {
            (*pares)++;
        } else {
            (*impares)++;
        }
    }

    return total;
}

int main() {

    int inicio = 1;
    int fim = 10;
    int pares, impares;

    int total = testavalores(inicio, fim, &pares, &impares);

    printf("Total: %d\n", total);
    printf("Pares: %d\n", pares);
    printf("Impares: %d\n", impares);


    return 0;
}