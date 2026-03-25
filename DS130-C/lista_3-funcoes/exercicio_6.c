/*
Escrever   uma   função  int   multmm(int   *vetor,   int   tamanho),   que   recebe   como
parâmetros um vetor int e o seu tamanho. A função deve retornar o maior valor
do vetor multiplicado pelo menor.
*/

#include <stdio.h>

int multmm(int *vetor, int tamanho) {
    if (tamanho <= 0) {
        return 0; // Retorna 0 para vetores vazios
    }

    int maior = vetor[0];
    int menor = vetor[0];

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    return maior * menor;
}


int main() {

    int vetor[] = {3, 10, 4, 2, 5, 9};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int resultado = multmm(vetor, tamanho);

    printf("Resultado: %d\n", resultado);

    return 0;
}