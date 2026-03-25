/*
Sabe-se que uma multiplicação de uma matriz numérica A por outra
matriz numérica B só é definida se o número de colunas de A for igual ao
número de linhas de B. Sabe-se ainda que o resultado é uma terceira
matriz com o mesmo número de linhas de A e mesmo número de colunas
de B. Faça um programa que:
Leia duas matrizes com 5 linhas e 5 colunas (5 x 5) de números reais
(valores inseridos pelo usuário). Leia índices (inferiores e superiores) que
delimite m submatrizes de A e B. Termine avisando o usuário se os
índices forem inválidos, ou seja:
• Não delimitam uma submatriz, ou
• Não permitem a multiplicação da submatriz de A pela sub matriz de
B
Caso os índices sejam válidos, calcule e escreva a multiplicação da
submatriz de A pela submatriz de B
*/

#include <stdio.h>

int main() {
    float A[5][5], B[5][5], C[5][5];
    int i, j, k;
    int linha_inf_A, linha_sup_A, col_inf_A, col_sup_A;
    int linha_inf_B, linha_sup_B, col_inf_B, col_sup_B;

    // Leitura da Matriz A
    printf("Digite os valores para a Matriz A (5x5):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Leitura da Matriz B
    printf("Digite os valores para a Matriz B (5x5):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%f", &B[i][j]);
        }
    }

    // Leitura dos limites da submatriz A
    printf("\nIndices da submatriz de A (linha_inf linha_sup col_inf col_sup): ");
    scanf("%d %d %d %d", &linha_inf_A, &linha_sup_A, &col_inf_A, &col_sup_A);

    // Leitura dos limites da submatriz B
    printf("Indices da submatriz de B (linha_inf linha_sup col_inf col_sup): ");
    scanf("%d %d %d %d", &linha_inf_B, &linha_sup_B, &col_inf_B, &col_sup_B);

    // 1. Validar se delimitam uma submatriz (indices de 0 a 4 e inferior <= superior)
    if (linha_inf_A < 0 || linha_sup_A > 4 || linha_inf_A > linha_sup_A ||
        col_inf_A < 0 || col_sup_A > 4 || col_inf_A > col_sup_A ||
        linha_inf_B < 0 || linha_sup_B > 4 || linha_inf_B > linha_sup_B ||
        col_inf_B < 0 || col_sup_B > 4 || col_inf_B > col_sup_B) {
        
        printf("\nErro: Os indices informados nao delimitam submatrizes validas.\n");
        return 1;
    }

    // Calcula o tamanho real das submatrizes (quantidade de linhas e colunas)
    int linhas_sub_A = linha_sup_A - linha_inf_A + 1;
    int colunas_sub_A = col_sup_A - col_inf_A + 1;
    int linhas_sub_B = linha_sup_B - linha_inf_B + 1;
    int colunas_sub_B = col_sup_B - col_inf_B + 1;

    // 2. Validar se permitem a multiplicacao (colunas de A == linhas de B)
    if (colunas_sub_A != linhas_sub_B) {
        printf("\nErro: O numero de colunas da submatriz de A (%d) e diferente do numero de linhas da submatriz de B (%d).\n", colunas_sub_A, linhas_sub_B);
        printf("Nao e possivel realizar a multiplicacao.\n");
        return 1;
    }

    // 3. Calcular a multiplicacao das submatrizes
    // A matriz resultante C terá as 'linhas da sub_A' e as 'colunas da sub_B'
    for (i = 0; i < linhas_sub_A; i++) {
        for (j = 0; j < colunas_sub_B; j++) {
            C[i][j] = 0; // Inicializa a posição com 0 antes do somatório
            for (k = 0; k < colunas_sub_A; k++) { // k vai iterar sobre os elementos internos (poderia ser ate linhas_sub_B)
                // Acessamos os elementos de A e B com o respectivo deslocamento 'inf'
                C[i][j] += A[linha_inf_A + i][col_inf_A + k] * B[linha_inf_B + k][col_inf_B + j];
            }
        }
    }

    // Exibe o resultado da nova submatriz
    printf("\nMatriz Resultante da multiplicacao da submatriz A x submatriz B:\n");
    for (i = 0; i < linhas_sub_A; i++) {
        printf("| ");
        for (j = 0; j < colunas_sub_B; j++) {
            // Utilizamos %.2f para formatar em duas casas decimais
            printf("%6.2f ", C[i][j]);
        }
        printf("|\n");
    }
    printf("\n");

    return 0;
}