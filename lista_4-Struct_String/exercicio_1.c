/*
Desenvolver um gerador de Piglatin. Piglatin é uma forma codificada do português
freqüentemente utilizada por crianças como um jogo. Uma palavra piglatin é formada a partir
de uma palavra em português transpondo a primeira letra para o fim da palavra e, então,
adicionando a letra “a “. Dessa forma, a palavra “dia” fica “iada”, “computador” fica
“omputadorca” e assim por diante.
Para desenvolver o gerador de piglatin serão necessárias duas strings de caracteres. Uma
conterá a linha de texto original e a outra o texto codificado em piglatin.
A estratégia de processamento é formada pelos seguintes passos:
a) Ler uma linha de texto inteira (várias palavras, ou seja, uma frase)
b) Determinar o número de palavras na linha
c) Rearranjar as palavras em piglatin, palavra por palavra, da seguinte forma:
- Localizar o fim da palavra,
- Transportar a primeira letra para o fim da palavra e adicionar um “a”.
- Localizar o início da próxima palavra
d) Exibir a linha inteira em piglatin
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char original[100];
    char piglatin[100];
} Piglatin;

void transform_word(char *word, char *piglatin_word) {
    int len = strlen(word);
    if (len <= 0) return;
    /**
     * exemplo: rato
     * len = 4
     * word[0] = 'r'
     * 1. copia da primeira letra em diante:
     * word + 1 = "ato" (aponta para o segundo caractere)
     * piglatin_word = "ato" (após a cópia)
     * 2. adiciona a primeira letra no final:
     * piglatin_word[len - 1] = word[0] -> piglatin_word[3] = 'r' -> piglatin_word = "ator"
     * 3. adiciona 'a' no final:
     * piglatin_word[len] = 'a' -> piglatin_word[4] = 'a' -> piglatin_word = "atora"
    */

    // 1. copia da primeira letra em diante
    strcpy(piglatin_word, word + 1);

    // 
    // 2. adiciona a primeira letra no final
    piglatin_word[len - 1] = word[0]; // move a primeira letra para o final

    // 3. adiciona 'a' no final
    piglatin_word[len] = 'a';
    piglatin_word[len + 1] = '\0'; // termina a string
}


int main() {
    Piglatin p;
    p.piglatin[0] = '\0'; // Inicializa a string piglatin como vazia
    char delimiter[] = " ";
    int count = 0;

    // 1.Lógica para ler a frase
    printf("Digite uma frase: ");
    fgets(p.original, sizeof(p.original), stdin);

    // Remove o \n do final da string lida pelo fgets
    p.original[strcspn(p.original, "\n")] = '\0';

    // Lógica usando strtok para quebrar a frase
    char *token = strtok(p.original, delimiter); // Remove o newline do final da string

    // Loop chamando transformar_palavra para cada pedaço
    while (token != NULL) {
        count++;
        char piglatin_word[100];
        transform_word(token, piglatin_word);
        strcat(p.piglatin, piglatin_word); // Adiciona a palavra transformada ao resultado final
        strcat(p.piglatin, delimiter); // Adiciona um espaço entre as palavras
        token = strtok(NULL, delimiter); // Pega a próxima palavra
    }

    printf("Número de palavras: %d\n", count);
    printf("Texto em Piglatin: %s\n", p.piglatin);

    return 0;
}

