/*
  Existem 2 candidatos para uma vaga no Senado e 20 eleitores, cada eleitor tem
  direito a 1 voto, onde este pode ser:
  0 - voto em branco
  1 - candidato 1
  2 - candidato 2
  outro - voto nulo
  Fazer um programa que detecte a contagem de votos,i e, quantos brancos, nulos,
  candidato 1 e 2.
*/

#include <stdio.h>
#define TOTAL_VOTERS 20

void read_vote(int *value) {
  printf("Digite o voto: ");
  if (scanf("%d", value) != 1) {
    // Limpa o buffer caso o usuário digite uma letra
    while (getchar() != '\n')
      ;
  }
}

int main() {

  int cand1 = 0, cand2 = 0, blank = 0, null_votes = 0;
  int current_vote;

  printf("=== Eleições Senado ===\n");
  printf("0: Branco | 1: Cand 1 | 2: Cand 2 | Outro: Nulo\n\n");

  for (int i = 0; i < TOTAL_VOTERS; i++) {
    printf("Eleitor %d/%d - ", i + 1, TOTAL_VOTERS);
    read_vote(&current_vote);

    switch (current_vote) {
    case 0:
      blank++;
      break;
    case 1:
      cand1++;
      break;
    case 2:
      cand2++;
      break;
    default:
      null_votes++;
      break;
    }
  }

  printf("\n--- Resultado Final ---\n");
  printf("Candidato 1: %d\n", cand1);
  printf("Candidato 2: %d\n", cand2);
  printf("Brancos:     %d\n", blank);
  printf("Nulos:       %d\n", null_votes);

  return 0;
}
