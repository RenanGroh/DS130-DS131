/*
    Escreva um programa em C que leia um vetor de 15 elementos inteiros.
    Ordene o vetor em ordem decrescente e exiba-o.
*/
#include <stdio.h>


int main() {
    int array[15];
    printf("Digite 15 numeros inteiros:\n");
    for (int i = 0; i < 15; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &array[i]);
    }

    // Ordenação usando Bubble Sort (decrescente)
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14 - i; j++) {
            if (array[j] < array[j + 1]) {
                // Troca os elementos
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Exibe o vetor ordenado
    printf("Vetor ordenado em ordem decrescente:\n");
    for (int i = 0; i < 15; i++) {
        printf("%d ", array[i]);
    }   

    return 0;
}