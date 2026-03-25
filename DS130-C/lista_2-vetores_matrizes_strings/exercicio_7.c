/*
Faça um programa que leia uma matriz 5x5 de caracteres e imprima:
A diagonal principal
O triângulo superior à diagonal principal
O triângulo inferior à diagonal principal
Tudo exceto a diagonal principal
*/

#include <stdio.h>


int main() {
    char matriz[5][5];
    int i, j;

    // Leitura da matriz
    printf("Digite os caracteres para a matriz 5x5:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf(" %c", &matriz[i][j]); // O espaço antes de %c é para consumir qualquer whitespace
        }
    }

    // Imprime a diagonal principal
    printf("\nDiagonal Principal:\n");
    for (i = 0; i < 5; i++) {
        printf("%c ", matriz[i][i]);
    }
    printf("\n");

    // Imprime o triângulo superior à diagonal principal
    printf("\nTriangulo Superior:\n");
    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) { // j começa em i+1 para pegar apenas elementos acima da diagonal
            printf("%c ", matriz[i][j]);
        }
    }
    printf("\n");

    // Imprime o triângulo inferior à diagonal principal
    printf("\nTriangulo Inferior:\n");
    for (i = 1; i < 5; i++) { // i começa em 1 para pegar apenas elementos abaixo da diagonal
        for (j = 0; j < i; j++) { // j vai até i-1 para pegar apenas elementos abaixo da diagonal
            printf("%c ", matriz[i][j]);
        }
    }
    printf("\n");

    // Imprime tudo exceto a diagonal principal
    printf("\nTudo exceto a Diagonal Principal:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i != j) { // Imprime apenas se não estiver na diagonal principal
                printf("%c ", matriz[i][j]);
            }
        }
    }
    printf("\n");

    return 0;
}