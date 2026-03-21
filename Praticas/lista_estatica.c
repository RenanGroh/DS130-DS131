/*
 * 1. Inicializar Lista
 * 2. Insere no início
 * 3. Insere no fim
 * 4. Insere no meio
 * 5. Remove do início
 * 6. Remove do fim
 * 7. Remove um elemento qualquer
 * 8. Busca um elemento qualquer
 * 9. Imprime os elementos da Lista
 * 10. Deleta a Lista
 */

#include <stdio.h>

#define SIZE 5

typedef struct Array {
  int list_data[SIZE];
  int first, last;
} List;

void menu() {

  int option;

  while (option != 0) {
  }
}

void startList(List *L) {
  L->last = 0;
  L->first = 0;
}

int insertAtFirstPosition(List *L, int data) {
  // verifica se o vetor ja esta cheio
  if (L->first < SIZE) {
    // pega o endereço que esta no fim e usa ele para atribuir o valor nessa
    // posição
    L->list_data[L->first] = data;
    // incrementa o valor de fim
    (L->last)++;
    // incrementa o valor do inicio
    (L->first)++;
    return 1;
  } else
    return 0;
}

int insertAtMiddlePosition(List *L, int data, int *index) {
  // verifica se o vetor ja esta cheio
  if (L->first < SIZE) {
    // pega o endereço que esta no fim e usa ele para atribuir o valor nessa
    // posição
    L->list_data[L->first] = data;
    // incrementa o valor de fim
    (L->last)++;
    return 1;
  } else
    return 0;
}

int insertAtLastPosition(List *L, int data) {
  // verifica se o vetor ja esta cheio
  if (L->last < SIZE) {
    // pega o endereço que esta no fim e usa ele para atribuir o valor nessa
    // posição
    L->list_data[L->last] = data;
    // incrementa o valor de fim
    (L->last)++;
    return 1;
  } else
    return 0;
}

int findInList(List *L, int data, int *index) {
  int i, found = 0;

  for (i = 0; i < L->last; i++) {
    if (L->list_data[i] == data) {
      *index = i;
      found = i;
    }
  }
  if (found)
    return 1;
  return 0;
}

int deleteDataFromList(List *L, int index) {
  if (index >= 0 && index < SIZE) {
    for (int i = index; i < L->last - 1; i++) {
      L->list_data[i] = L->list_data[i + 1];
    }
    (L->last)--;
    return 1;
  }
  return 0;
}

int main() {
  List list;

  startList(&list);

  insertAtFirstPosition(&list, 7);
  insertAtFirstPosition(&list, 5);
  insertAtFirstPosition(&list, 3);
  insertAtLastPosition(&list, 9);
  // print
  for (int i = 0; i < SIZE; i++) {
    printf("%d: %d\n", i, list.list_data[i]);
  }

  return 0;
}
