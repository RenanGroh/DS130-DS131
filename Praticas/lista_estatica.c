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

// 1. Inicializar Lista
void startList(List *L) {
  L->last = 0;
  L->first = 0;
}


// 2. Insere no início
int insertAtFirstPosition(List *L, int data) {
  // 1. Verifica se a lista está cheia
  if (L->last >= SIZE) {
    printf("Erro: Lista cheia!\n");
    return 0;
  }

  // 2. SHIFTING: Move todos os elementos uma posição para a direita
  // Começamos do fim para não sobrescrever os dados
  for (int i = L->last; i > 0; i--) {
    L->list_data[i] = L->list_data[i - 1];
  }

  // 3. Insere o novo dado na primeira posição
  L->list_data[0] = data;

  // 4. Incrementa o contador de elementos
  L->last++;
  
  return 1;
}

// 3. Insere no fim
int insertAtLastPosition(List *L, int data) {
  // 1. Verifica se a lista está cheia
  if (L->last >= SIZE) {
    printf("Erro: Lista cheia!\n");
    return 0;
  }

  L->list_data[L->last] = data;
  // incrementa o valor de fim
  (L->last)++;
  return 1;
}


// 4. Insere no meio
int insertAtMiddlePosition(List *L, int data) {
  // verifica se o vetor ja esta cheio
  if (L->last >= SIZE) {
    printf("Erro: Lista cheia!\n");
    return 0;
  }

  // calcula a posição do meio
  int middle = L->last / 2;
  
  // Shifting (Deslocamento)
  // Começamos do fim para não sobrescrever os dados
  for (int i = L->last; i > middle; i--) {
      L->list_data[i] = L->list_data[i - 1];
  }

  // 4. Inserção
  L->list_data[middle] = data;
  L->last++;
  return 1;
}

// 5. Remove do início
int deleteDataFromFirstPosition(List *L) {
    // 1. Verifica se a lista está vazia
    if (L->last == 0) {
        printf("Erro: Lista Vazia!\n");
        return 0;
    }

    // 2. SHIFTING PARA A ESQUERDA:
    // Começamos do início (índice 0) e trazemos o vizinho da direita
    for (int i = 0; i < L->last - 1; i++) {
        L->list_data[i] = L->list_data[i + 1];
    }

    // 3. Decrementa o contador de elementos
    L->last--;

    return 1;
}

// 6. Remove do fim
int deleteDataFromLastPosition(List *L) {
  // 1. Verifica se a lista está vazia
  if (L->last == 0) {
    printf("Erro: Lista Vazia!\n");
    return 0;
  }

  // 2. Decrementa o contador de elementos
  L->last--;
  return 1;
}

// 7. Remove um elemento qualquer
/**
 * Duvida aqui seria deletar por index ou por valor?
 * tirar duvida com a professora
 */

int deleteDataFromIndex(List *L, int index) {
    if (index < 0 || index >= L->last) {
        printf("Posicao invalida!\n");
        return 0;
    }

    // Puxa os elementos a partir da posição deletada
    for (int i = index; i < L->last - 1; i++) {
        L->list_data[i] = L->list_data[i + 1];
    }

    L->last--;
    return 1;
}

// 8. Busca um elemento qualquer
int findInElementInList(List *L, int value) {
    for (int i = 0; i < L->last; i++) {
        if (L->list_data[i] == value) {
            return i; // Encontrou! Retorna a posição
        }
    }
    return -1;
}

// 9. Imprime os elementos da Lista
void printList(List *L) {
  if (L->last == 0) {
    printf("Lista Vazia!\n");
    return;
  } 
  printf("Elementos da Lista:\n");
  for (int i = 0; i < L->last; i++) {
      printf("%d ", L->list_data[i]);
    }
  printf("\n");
}

// 10. Deleta a Lista
void deleteList(List *L) {
  L->last = 0;
  L->first = 0;
}


int main() {
    List list;
    startList(&list);
    int option, value, index;

    do {
        printf("\n--- MENU LISTA ESTATICA ---\n");
        printf("1. Inserir Inicio  | 2. Inserir Meio | 3. Inserir Fim\n");
        printf("4. Remover Inicio  | 5. Remover Fim  | 6. Remover do Indice\n");
        printf("7. Buscar Elemento | 8. Imprimir     | 9. Deletar Lista\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Valor: "); scanf("%d", &value);
                insertAtFirstPosition(&list, value);
                break;
            case 2:
                printf("Valor: "); scanf("%d", &value);
                insertAtMiddlePosition(&list, value);
                break;
            case 3:
                printf("Valor: "); scanf("%d", &value);
                insertAtLastPosition(&list, value);
                break;
            case 4:
                deleteDataFromFirstPosition(&list);
                break;
            case 5:
                deleteDataFromLastPosition(&list);
                break;
            case 6:
                printf("Indice (1-5): "); scanf("%d", &index);
                deleteDataFromIndex(&list, index - 1);
                break;
            case 7:
                printf("Indice (1-5): "); scanf("%d", &value);
                index = findInElementInList(&list, value);
                if (index != -1) {
                    printf("Valor encontrado na posicao %d\n", index + 1);
                } else {
                    printf("Valor nao encontrado na lista.\n");
                }
                break;
            case 8:
                printList(&list);
                break;
            case 9:
                deleteList(&list);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(option != 0);

    return 0;
}
