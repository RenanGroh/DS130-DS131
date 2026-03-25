/*
    Crie   uma   função   que   transforma   todos   os   caracteres   de   uma   string   em
    minúsculos.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h> // Biblioteca para funções como tolower e toupper

// Função solicitada pelo enunciado
void to_lowercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main () {

    char str[100];
    printf("Digite uma string: ");
    scanf(" %[^\n]", str); // Lê a linha inteira, permitindo espaços

    printf("String original: %s\n", str);

    // outra forma usando tabela ASCII 'A' = 65 e 'a' = 97, a diferença é de 32
    // Transformar a string em minúsculos
    /*
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    */

    // Transformar a string em minúsculos
    to_lowercase(str);
    
    printf("String em minúsculos: %s\n", str);

    return 0;
}