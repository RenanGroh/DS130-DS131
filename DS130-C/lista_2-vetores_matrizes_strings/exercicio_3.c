/*
    Criar um meno com as funcionalidades do programa citadas acima para
    que o usuário possa escolher a opção desejada. A última opção do menu
    deve ser Sair do Progama.
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

void even_odd(int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            printf("Elemento %d (posicao %d) e PAR.\n", array[i], i);
        } else {
            printf("Elemento %d (posicao %d) e IMPAR.\n", array[i], i);
        }
    }
}

int total_sum(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
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
    int option;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Verificar valor no vetor\n");
        printf("2. Mostrar menor e maior elemento\n");
        printf("3. Mostrar se os elementos sao pares ou impares\n");
        printf("4. Calcular a soma de todos os elementos\n");
        printf("5. Calcular a soma dos elementos positivos e negativos\n");
        printf("6. Gerar vetor aleatorio e comparar elementos comuns\n");
        printf("0. Sair do Programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &value);
                verify_value(array, SIZE, value);
                break;
            case 2:
                min_max(array, SIZE, &min, &max, &p_min, &p_max);
                printf("Menor: %d na posicao %d\n", min, p_min);
                printf("Maior: %d na posicao %d\n", max, p_max);
                break;
            case 3:
                even_odd(array, SIZE);
                break;
            case 4:
                printf("Soma de todos os elementos: %d\n", total_sum(array, SIZE));
                break;
            case 5:
                positive_negative_sum(array, SIZE, &positive_sum, &negative_sum);
                printf("Soma dos positivos: %d\n", positive_sum);
                printf("Soma dos negativos: %d\n", negative_sum);
                break;
            case 6:
                generate_random_array(rand_vet, SIZE);
                printf("Vetor aleatorio gerado:\n");
                for (int i = 0; i < SIZE; i++) {
                    printf("%d ", rand_vet[i]);
                }
                printf("\n");
                compare_arrays(array, rand_vet, SIZE);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (option != 0);

    return 0;
}