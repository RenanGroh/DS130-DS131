/*
 * Faça um programa contendo um menu com as seguintes opções:
 * S - soma
 * P - produto
 * U - subtração
 * D - divisão
 * Q - sair
 * Utilize a estrutura switch-case. Quando o usuário teclar Q o programa deve
 * terminar.
 */

#include <ctype.h>
#include <stdio.h>

void calculate(char option) {
  float a, b;

  if (option == 'Q')
    return;

  printf("Digite dois números: ");
  if (scanf("%f %f", &a, &b) != 2) {
    printf("Erro na leitura.\n");
    return;
  }

  switch (option) {
  case 'S':
    printf("Resultado da soma: %.2f\n", a + b);
    break;
  case 'P':
    printf("Resultado do produto: %.2f\n", a * b);
    break;
  case 'U':
    printf("Resultado da subtração: %.2f\n", a - b);
    break;
  case 'D':
    if (b != 0)
      printf("Resultado da divisão: %.2f\n", a / b);
    else
      printf("Erro divisão por zero!\n");
    break;
  default:
    printf("opção inválida!");
  }
}

int main() {
  char option;

  do {
    printf("\n--- MENU ---\n");
    printf("S - Soma\nP - Produto\nU - Subtração\nD - Divisão\nQ - Sair\n");
    printf("Escolha uma opção: ");

    // o ' ' antes do %c serve para ignorar o '\n' (ENTER) deixado no buffer
    scanf(" %c", &option);
    option = toupper(option);

    if (option != 'Q') {
      calculate(option);
    }
  } while (option != 'Q');

  printf("Programa encerrado.\n");
  return 0;
}
