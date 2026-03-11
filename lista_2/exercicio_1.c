/*
  Faça um programa para corrigir provas de múltipla escolha. Cada prova
  tem oito questões, e cada questão vale um ponto, exceto as questões 3 e
  8 que valem 2.0 pontos cada uma. O primeiro conjunto de dados a ser
  lido é o gabarito da prova. Os outros dados são os números dos alunos, e
  as respostas que deram às questões. Existem 10 alunos matriculados.
  Calcule e mostre o número e a nota de cada aluno
*/

#include <stdio.h>
#include <wctype.h>

#define NUM_QUESTOES 8
#define NUM_ALUNOS 1

// Entidade Aluno
typedef struct {
  int id;
  char answers[NUM_QUESTOES];
  float final_grade;
} Aluno;

float calculate_grades(char answers[], char ans_template[], float weigth[]) {
  float sum = 0.0;
  for (int i = 0; i < NUM_QUESTOES; i++) {
    if (answers[i] == ans_template[i]) {
      sum += weigth[i];
    }
  }
  return sum;
}

int main() {
  char ans_template[NUM_QUESTOES];
  float weigth[NUM_QUESTOES] = {1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0};
  Aluno alunos[NUM_ALUNOS];

  // 1. Cadastro de gabarito
  printf("--- Cadastro do gabarito ---\n");
  for (int i = 0; i < NUM_QUESTOES; i++) {
    printf("questão %d ", i + 1);
    scanf(" %c", &ans_template[i]);
  }

  // 2. Leitura dos dados dos alunos
  for (int i = 0; i < NUM_ALUNOS; i++) {
    printf("\nDados do aluno %d\n", i + 1);
    printf("Insira o numero da matricula: ");
    scanf("%d", &alunos[i].id);

    for (int j = 0; j < NUM_QUESTOES; j++) {
      printf("Resposta Questão %d: ", j + 1);
      scanf(" %c", &alunos[j].answers[j]);
    }

    // 3. Calculo das notas
    alunos[i].final_grade =
        calculate_grades(alunos[i].answers, ans_template, weigth);
  }

  // 4. Motra os resultados
  printf("\n--- Resultados ---\n");
  printf("MATRICULA\tNOTA\n");
  for (int i = 0; i < NUM_ALUNOS; i++) {
    printf("%d\t\t%.1f\n", alunos[i].id, alunos[i].final_grade);
  }

  return 0;
}
