/*
    Crie uma função que recebe uma string e um caractere,
    e retorne o número de vezes que esse caractere aparece na string.
*/

#include <stdio.h>
#include <string.h>

// 'const' indica que a função não vai alterar o conteúdo da string
int count_character_occurrences(const char str[], char character) {
    int count = 0; // Inicializa o contador
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == character) {
            count++; // Incrementa o contador se o caractere for encontrado
        }
    }
    return count; // Retorna o número de ocorrências
}

int main () {
    char str[100];
    char target;
    int count;

    printf("Digite uma string: ");
    // %99 evita buffer overflow (estouro de memória)
    scanf(" %99[^\n]", str); 

    printf("Digite o caractere a ser contado: ");
    scanf(" %c", &target);

    count = count_character_occurrences(str, target);
    printf("O caractere '%c' aparece %d vezes na string.\n", target, count);

    return 0;
}