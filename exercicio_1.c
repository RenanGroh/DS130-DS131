/*
Escrever um programa que declara três variáveis int (a, b e c). Ler um valor
maior que zero para cada variável (se o valor digitado não é válido, mostrar
mensagem e ler novamente). Exibe o menor valor lido multiplicado pelo maior e o
maior valor dividido pelo menor.
*/

#include <stdio.h>

/**
 * Função para ler um inteiro positivo.
 * Usa um ponteiro para alterar o valor da variável original.
 */
void ler_positivo(int *num, char nome_var) {
  do {
    printf("Digite um valor maior que zero para %c: ", nome_var);
    scanf("%d", num);

    if (*num <= 0) {
      printf("Erro: O valor deve ser maior que zero.\n");
    }
  } while (*num <= 0);
}

int main() {
  int a, b, c;

  // Entrada de dados com validação
  ler_positivo(&a, 'a');
  ler_positivo(&b, 'b');
  ler_positivo(&c, 'c');

  // Lógica para encontrar o maior e o menor
  int maior = a;
  int menor = a;

  // Verificando o maior
  if (b > maior)
    maior = b;
  if (c > maior)
    maior = c;

  // Verificando o menor
  if (b < menor)
    menor = b;
  if (c < menor)
    menor = c;

  // Cálculos
  int produto = menor * maior;
  float divisao =
      (float)maior / menor; // Cast para float para não perder precisão

  // Saída
  printf("\n--- Resultados ---\n");
  printf("Menor (%d) * Maior (%d) = %d\n", menor, maior, produto);
  printf("Maior (%d) / Menor (%d) = %.2f\n", maior, menor, divisao);

  return 0;
}
