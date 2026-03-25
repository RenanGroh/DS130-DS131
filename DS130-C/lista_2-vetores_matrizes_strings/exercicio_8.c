/*
Escreva um programa que leia uma linha de caracteres do teclado e
converta o primeiro caracter de cada palavra para maiúsculas. Assuma
que as palavras são sempre separadas por um branco.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char linha[100]; // Buffer para armazenar a linha de entrada
    int i;

    // Solicita ao usuário que digite uma linha de texto
    printf("Digite uma linha de texto:\n");
    fgets(linha, sizeof(linha), stdin); // Lê a linha de entrada

    // Remove o caractere de nova linha, se presente
    linha[strcspn(linha, "\n")] = '\0';
    
    /**
    * Converte o primeiro caractere de cada palavra para maiúscula
    */
    for (i = 0; linha[i] != '\0'; i++) {
        // Verifica se é o início da string ou se o caractere anterior é um espaço
        if (i == 0 || linha[i - 1] == ' ') {
            // Converte para maiúscula se for uma letra minúscula
            if (linha[i] >= 'a' && linha[i] <= 'z') {
                linha[i] = linha[i] - ('a' - 'A'); // Converte para maiúscula
            }
        }
    }

    // Exibe a linha modificada
    printf("\nLinha com as primeiras letras em maiúsculas:\n%s\n", linha);

    return 0;
}   