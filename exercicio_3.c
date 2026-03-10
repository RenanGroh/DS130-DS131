/*
 * Ler 2 notas. Calcular a média e verificar:
 * a. se média >= 7 imprimir APROVADO
 * b. se 4 <= média < 7 imprimir EXAME
 * c. se média < 4 imprimir REPROVADO.
 */

#include <stdio.h>

void read_grade(float *grade_value, char grade_name[7]) {
  printf("Digite o valor da nota %s:", grade_name);
  scanf("%f", grade_value);
}

int main() {
  float nota_1, nota_2, avg;

  read_grade(&nota_1, "nota 1");
  read_grade(&nota_2, "nota 2");

  avg = (nota_1 + nota_2) / 2;

  // Lógica otimizada (Clean Code)
  if (avg >= 7.0) {
    printf("APROVADO! Media: %.2f\n", avg);
  } else if (avg >= 4.0) {
    // Se chegou aqui, o C já sabe que é menor que 7
    printf("EXAME! Media: %.2f\n", avg);
  } else {
    // Se não é >= 7 e não é >= 4, só pode ser < 4
    printf("REPROVADO! Media: %.2f\n", avg);
  }

  return 0;
}
