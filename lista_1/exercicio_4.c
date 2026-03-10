// Ler 3 números e mostrá-los na ordem crescente.

#include <stdio.h>

void read_number(float *value, const char *label) {
  printf("Digite o %s: ", label);
  scanf("%f", value);
}

int main() {
  float n[3];

  read_number(&n[0], "primeiro numero");
  read_number(&n[1], "segundo numero");
  read_number(&n[2], "terceiro numero");

  // Lógica de Ordenação (Bubble Sort simplificado para 3 elementos)
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2 - i; j++) {
      if (n[j] > n[j + 1]) {
        // Swap (Troca) usando variável temporária
        float temp = n[j];
        n[j] = n[j + 1];
        n[j + 1] = temp;
      }
    }
  }

  printf("\nOrdem crescente: %.2f, %.2f, %.2f\n", n[0], n[1], n[2]);
  return 0;
}
