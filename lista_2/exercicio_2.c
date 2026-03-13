/*
    Crie um vetor com 10 elementos e:
    • Verifique se um valor digitado pelo usuário é um elemento do vetor. Se
    sim, informe a posição em que o elemento ocorre.
    • Percorrendo o vetor uma única vez, determine o menor e o maior
    elemento do vetor, e as posições em que ocorrem.
    • Informe para cada elemento se ele é par ou ímpar
    • Calcule a soma de todos os elementos do vetor.
    • Calcule a soma de todos os elementos positivos do vetor.
    • Calcule a soma de todos os elementos negativos do vetor.
    • Crie outro vetor com 10 elementos gerados aleatoriamente e informe os
    elementos que aparecem nos dois vetores. (pesquise a função rand da
    biblioteca stdlib.h)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10


void verify_value(int array[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            printf("Valor encontrado na posição: %d\n", i);
            return;
        }
    }
    printf("Valor não encontrado no vetor.\n");
}

// Uso de * para indicar que estamos recebendo endereços (ponteiros)
void min_max(int array[], int size, int *min, int *max, int *min_pos, int *max_pos) {
    // Usamos o operador de desreferenciação (*) para alterar o valor no endereço apontado
    *min = array[0];
    *max = array[0];
    *min_pos = 0;
    *max_pos = 0;

    for (int i = 1; i < size; i++) {
        if (array[i] < *min) {
            *min = array[i];
            *min_pos = i;
        }
        if (array[i] > *max) {
            *max = array[i];
            *max_pos = i;
        }
    }
}

void positive_negative_sum(int array[], int size, int *positive_sum, int *negative_sum) {
    *positive_sum = 0;
    *negative_sum = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            *positive_sum += array[i];
        } else if (array[i] < 0) {
            *negative_sum += array[i];
        }
    }
}

void generate_random_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        // valor = (rand() %  (Max - Min + 1)) + Min
        array[i] = (rand() % (20 - (-20) + 1)) + (-20); // Gera números entre -20 e 20
    }
}

void compare_arrays(int array1[], int array2[], int size) {
    printf("Elementos comuns nos dois vetores:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array1[i] == array2[j]) {
                printf("%d ", array1[i]);
                break; // Evita imprimir o mesmo elemento mais de uma vez
            }
        }
    }
    printf("\n");
}   

int main() {

    srand(time(NULL));

    int array[10] = {4, 7, 13, 19, -18, -5, 9, -14, -8, -17};
    int rand_vet[10];
    int value;
    int min, max, p_min, p_max, positive_sum, negative_sum;

    int rand_array[SIZE];

    printf("Digite um valor: ");
    scanf("%d", &value);

    // 1. Verificar se o valor digitado é um elemento do vetor
    verify_value(array, SIZE, value);

    // 2. Determinar o menor e o maior elemento do vetor, e as posições em que ocorrem
    // Passamos o endereço das variáveis usando o operador &
    min_max(array, SIZE, &min, &max, &p_min, &p_max);
    printf("Menor: %d na posicao %d\n", min, p_min);
    printf("Maior: %d na posicao %d\n", max, p_max);

    // 3. Calcular a soma de todos os elementos positivos e negativos do vetor
    positive_negative_sum(array, SIZE, &positive_sum, &negative_sum);
    printf("Soma dos positivos: %d\n", positive_sum);
    printf("Soma dos negativos: %d\n", negative_sum);

    // 4. Gerar outro vetor com 10 elementos aleatórios e informar os elementos que aparecem nos dois vetores
    generate_random_array(rand_vet, SIZE);

    //5. Comparar os dois vetores e mostrar os elementos comuns
    // print random array
    printf("Vetor aleatório gerado:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", rand_vet[i]);
    }
    printf("\n");
    compare_arrays(array, rand_vet, SIZE);

    return 0;
}