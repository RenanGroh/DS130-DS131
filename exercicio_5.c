// Calcular e imprimir o total da soma obtida dos
// cem primeiros números inteiros (1+2+3+...+98+99+100).

#include <stdio.h>

/**
 * Calcula a soma de uma PA de 1 até n.
 * Formula: Sn = (n * (a1 + an)) / 2
 */
int calculate_sum_up_to(int n) {
  // a1 é sempre 1 nesta regra de negócio
  int sum = (n * (1 + n)) / 2;
  return sum;
}

int main() {
  int limit = 100;
  int result = calculate_sum_up_to(limit);

  printf("A soma dos primeiros %d numeros é: %d\n", limit, result);

  return 0;
}
