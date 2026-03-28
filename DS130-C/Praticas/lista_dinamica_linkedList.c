/**  Lembar de limpar os nodos quando for excluido
 * 
 * Implementação de lista encadeada - Linked List
 * 
 * 
 * 1. Inicializar Lista
 * 2. Insere no início
 * 3. Insere no fim
 * 4. Insere no meio | insero de forma ordenada (USO EXCLUSIVO)
 * 5. Remove do início
 * 6. Remove do fim
 * 7. Remove um elemento qualquer
 * 8. Busca um elemento qualquer
 * 9. Imprime os elementos da Lista
 * 10. Deleta a Lista
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Node structure: Representa cada "caixinha" na memoria.
 */
typedef struct Node {
    int data;           // O valor armazenado
    struct Node *next;  // Ponteiro para o proximo Nó
} Node;

/**
 * Estrutura LinkedList(Lista Encadeada): Guarda a referencia do primeiro elemento (Head).
 */
typedef struct LinkedList {
    Node *head;         // Ponteiro para o inicio da lista
    int size;           // guarda o tamanho atual para performance
} LinkedList;


Node* createNode(int value) {

    // 1. Aloca memoria no heap
    Node *newNode = (Node*) malloc(sizeof(Node));

    // 2. verificacao de seguraça
    if (newNode == NULL){
        printf("Erro de memoria!\n");
        return NULL;
    }

    // 3. Inicialização
    newNode->data = value;
    newNode->next = NULL;// sempre começa com NULL

    return newNode;
}

// 1. Inicializa a lista
void initList(LinkedList *list) {
        list->head = NULL;
        list->size = 0;
};

// 2. Insere no inicio
int insertAtFront(LinkedList *list,int value){
    Node *node = createNode(value);
    if (node == NULL) return 0; // erro
    // 1. O proximo do novo NÓ aponta aponta para onde a lista começava
    node->next = list->head;
    // 2. A "cabeça" da lista passa a ser o novo NÓ
    list->head = node;
    // 3. Aumenta o tamanho da lista
    list->size++;
    return 1;
}

int insereAtEnd(LinkedList *list, int value) {
    // 1. Crio o novo nodo e insiro o valor
    Node *node = createNode(value);
    if (node == NULL) return 0;

    // 2. CASO ESPECIAL: Se a lista estiver vazia, o fim é o próprio início
    if (list->head == NULL) {
        list->head = node;
    } else {
        // 3. Caso contrário, precisamos navegar até o último nó
        Node *current = list->head;
        // O loop para no nó que aponta para NULL (o último atual)
        while (current->next != NULL) {
            current = current->next;
        }
        // 4. Conectamos o novo nó ao fim da linha
        current->next = node;
    }
    list->size++;
    return 1;
}

// 3. Insere no meio, deforma ordenada | USO EXCLUSIVO
int insertAtMiddle(LinkedList *list, int value){
    // Cria o nodo e insere o valor
    Node *node = createNode(value);
    if (node == NULL) return 0;

    // CASO 1: lista vazia ou menor valor por primeiro
    if (list->head == NULL || list->head->data >= value) {
        node->next = list->head;
        list->head = node; 
    } else {
        // CASO 2: Inserir no meio ou no fim
        Node *current = list->head;
        // Percorre ate achar o no cujo PROXIMO seja maior que o nosso valor
        // Ou ate chegar no ultimo no (next == NULL)
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
    list->size++;
    return 1;
 }

// remove do inicio
int removeAtFront(LinkedList *list) {
    // 1. pega o primeiro nó e anota o endereço
    // [0][dsadas,1] ->[1][dasdsa,2]-> [2][dasdas,null]
    //
    // 2. Apaga o nó
}

// Imprime a lista
void printList(LinkedList *L) {
    // 1. Verificamos se a lista existe e se não está vazia
    if (L == NULL || L->head == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    // 2. Criamos um ponteiro auxiliar para percorrer a lista
    // IMPORTANTE: Nunca use o L->head diretamente para navegar, 
    // ou você perderá a referência do início da lista!
    Node *current = L->head;
    printf("Lista Encadeada: ");
    // 3. Enquanto o ponteiro não for NULL, continuamos imprimindo
    while (current != NULL) {
        printf("[%d] -> ", current->data);
        
        // O "pulo": o ponteiro atual passa a ser o próximo
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * MAIN
 */
int main() {

    LinkedList linkedlist;
    initList(&linkedlist);

    // insere no inicio e fim test 
    //insertAtFront(&linkedlist, 10);
    //insertAtFront(&linkedlist, 20);
    //insertAtFront(&linkedlist, 30);
    //insereAtEnd(&linkedlist,50);
    //insereAtEnd(&linkedlist,80)
    
    insertAtMiddle(&linkedlist, 7);
    insertAtMiddle(&linkedlist, 5);
    insertAtMiddle(&linkedlist, 2);
    insertAtMiddle(&linkedlist, 9);
    
    printList(&linkedlist);

    return 0;
}



