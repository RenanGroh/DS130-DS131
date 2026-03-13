/**
 * Escrever um programa que cadastre o nome, a altura, o peso, o CPF e sexo de 10
 * pessoas. Com os dados cadastrados, em seguida localizar uma pessoas através do
 * seu CPF e imprimir o seu IMC.
 */

#include <stdio.h>
#include <string.h>

#define NUM_PESSOAS 1

typedef struct {
    char nome[100];
    float altura;
    float peso;
    char cpf[15];
    char sexo;
} Pessoa;

float calcular_imc(float peso, float altura) {
    return peso / (altura * altura);
}

int main() {
    Pessoa pessoas[NUM_PESSOAS];
    char cpf_busca[15];
    int i;

    // Cadastro de 10 pessoas
    for (i = 0; i < NUM_PESSOAS; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
        printf("Digite a altura da pessoa %d (em metros): ", i + 1);
        scanf("%f", &pessoas[i].altura);
        printf("Digite o peso da pessoa %d (em kg): ", i + 1);
        scanf("%f", &pessoas[i].peso);
        printf("Digite o CPF da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].cpf);
        printf("Digite o sexo da pessoa %d (M/F): ", i + 1);
        scanf(" %c", &pessoas[i].sexo);
        getchar(); // Limpar o buffer do teclado
    }

    // Busca por CPF
    printf("Digite o CPF para buscar: ");
    scanf("%s", cpf_busca);

    // Localizar a pessoa pelo CPF e calcular o IMC
    for (i = 0; i < 10; i++) {
        if (strcmp(pessoas[i].cpf, cpf_busca) == 0) {
            float imc = calcular_imc(pessoas[i].peso, pessoas[i].altura);
            printf("O IMC de %s é: %.2f\n", pessoas[i].nome, imc);
            return 0;
        }
    }

    printf("Pessoa com CPF %s não encontrada.\n", cpf_busca);
    return 0;
}