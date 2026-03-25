/*
Crie um programa que compara duas strings de mesmo tamanho,
informadas pelo usuá rio. Caso as string sejam diferentes, mostre a
posição da primeira letra diferente. Não utilize o comando strcmp().
*/

#include <stdio.h>
#include <string.h>

int main() {

    char str1[100], str2[100];
    int i;
    int iguais = 1; // Flag de controle: assumimos inicialmente que são iguais (1)

    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove o "enter" (\n) do final

    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove o "enter" (\n) do final

    // Percorremos os caracteres até o final de uma das strings
    for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
        // Se os caracteres na posição 'i' forem diferentes
        if (str1[i] != str2[i]) {
            printf("\nAs strings sao diferentes!\n");
            printf("A primeira diferenca ocorre na posicao %d (indice %d).\n", i + 1, i);
            iguais = 0; // Marcamos que não são iguais
            break;      // Interrompemos o laço, pois só queremos a primeira diferença
        }
    }

    if (iguais == 1) {
        printf("\nAs strings sao perfeitamente iguais!\n");
    }

    return 0;
}