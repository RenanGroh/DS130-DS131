/**  Lembar de limpar os nodos quando for excluido
 * 
 * Implementação de lista Circular - Circular Linked List
 * 
 *  - OPERAÇÕES - 
 * void inicializa_circular( );
 * void insere_esquerda(int dado);
 * void insere_direita(int dado);
 * void insere_ordenado(int dado);
 * void remove_nodo_esquerda(int *dado);
 * void remove_nodo_direita(int *dado);
 * int remove_nodo (int dado);
 * void imprime_lista_circular( );
 * int pesquisa_lista_circular(int dado);
 * void apaga_lista_circular( );
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
} CircularLinkedList;


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
void initList(CircularLinkedList *list) {
        list->head = NULL;
        list->size = 0;
};

// 2. Insere no inicio
int insertAtLeft(CircularLinkedList *list,int value){
    if (list == NULL) return 0; // erro

    Node *node = createNode(value);
    if (node == NULL) return 0; // erro

    // Caso 1: lista vazia
    if (list->head == NULL) {
        node->next = node;   // aponta para si mesmo (circular)
        list->head = node;
    } else {
        // Caso 2: lista com elementos -> achar o ultimo
        Node *tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next;
        }

        node->next = list->head; // novo aponta para antigo head
        tail->next = node;       // ultimo aponta para novo head
        list->head = node;       // atualiza head
    }

    list->size++;
    return 1;
}

// 3. insere no fim
int insereAtRight(CircularLinkedList *list, int value) {
    if (list == NULL) return 0;

    Node *node = createNode(value);
    if (node == NULL) return 0;

    // Caso 1: lista vazia
    if (list->head == NULL) {
        node->next = node;   // aponta para si mesmo (circular)
        list->head = node;
    } else {
        // Caso 2: lista com elementos -> achar o ultimo
        Node *tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next;
        }

        tail->next = node;       // antigo ultimo aponta para novo
        node->next = list->head; // novo ultimo aponta para head
    }

    list->size++;
    return 1;
}

// 4. Insere no meio, deforma ordenada | USO EXCLUSIVO
int insertByOrder(CircularLinkedList *list, int value){
    // Cria o nodo e insere o valor
    Node *node = createNode(value);
    if (node == NULL) return 0;

    // CASO 1: lista vazia
    if (list->head == NULL) {
        node->next = node;
        list->head = node;
        list->size++;
        return 1;
    }

    // Caso 2: inserir antes do head (novo menor)
    if (value <= list->head->data) {
        Node *tail = list->head;
        while (tail->next != list->head) {
            tail = tail->next;
        }
        node->next = list->head;
        tail->next = node;
        list->head = node;
        list->size++;
        return 1;
    }

    // Caso 3/4: meio ou fim
    Node *current = list->head;
    while (current->next != list->head && current->next->data < value) {
        current = current->next;
    }

    node->next = current->next;
    current->next = node;
    list->size++;
    return 1;

 }

// 5. remove do inicio
int removeAtFront(CircularLinkedList *list) {
    // 1. valida se a lista existe e não está vazia
    if (list == NULL || list->head == NULL) return 0;
    // 2. guarda o primeiro nó antes de avançar o head
    Node *aux = list->head;
    // 3. head passa a apontar para o próximo nó
    list->head = list->head->next;
    // 4. libera o nó removido
    free(aux);
    // 5. atualiza o tamanho da lista
    list->size--;
    return 1;
}

// 6. remove no fim
int removeAtEnd(CircularLinkedList *list) {
    // Caso a lista nao exista ou esja vazia
    if (list == NULL || list->head == NULL) return 0;
    // caso com apenas um nó
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        list->size--;
        return 1;
    }
    
    Node *current = list->head;
    // para no penultimo nó
    while (current->next->next != NULL){
        current = current->next;
    }
    
    Node *aux = current->next;
    current->next = NULL;
    free(aux);
    list->size--;
    return 1;
}

// 7. remove um elemento qualquer (por valor)
int removeByValue(CircularLinkedList *list, int value) {
    // Caso a lista nao exista ou esteja vazia
    if (list == NULL || list->head == NULL) return 0;

    // Caso 1: O elemento a ser removido e o primeiro da lista (Head)
    if (list->head->data == value) {
        // 1. Guardamos o endereco do primeiro no temporariamente em 'aux'
        // Se nao fizermos isso, perderemos a referencia dele ao mover o head
        Node *aux = list->head;
        
        // 2. O inicio da lista passa a ser o SEGUNDO elemento
        list->head = list->head->next;
        
        // 3. Agora que o primeiro no esta desconectado da lista, liberamos sua memoria
        free(aux);
        
        // 4. Reduzimos o tamanho total da lista
        list->size--;
        
        // 5. Retornamos 1 (sucesso) pois ja removemos o que queriamos
        return 1;
    }

    // Caso 2: O elemento esta no meio ou no fim
    Node *current = list->head;
    // Percorre ate achar o no cujo PROXIMO tenha o valor desejado
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    // Se chegou no final e nao encontrou o valor
    if (current->next == NULL) return 0;

    // Encontrou: o no a ser removido e current->next
    Node *aux = current->next;
    current->next = aux->next; // O no anterior "pula" o no removido
    free(aux);
    list->size--;

    return 1;
}

// 8. Busca um elemento qualquer
int searchByValue(CircularLinkedList *list, int value) {
    // 1. Verifica se a lista existe e nao esta vazia
    if (list == NULL || list->head == NULL) {
        return -1;
    }

    Node *current = list->head;
    int index = 0; // Usado para rastrear a posicao (0, 1, 2...)

    // 2. Percorre a lista ate o final
    while (current != NULL) {
        if (current->data == value) {
            printf("Valor %d encontrado na posicao %d da lista!\n", value, index);
            return index; // Retorna a posicao caso encontre
        }
        current = current->next;
        index++;
    }

    // 3. Se o laco terminar e nao retornar, e porque o valor nao existe na lista
    printf("Valor %d nao encontrado na lista.\n", value);
    return -1;
}

// 9. Imprime a lista
void printList(CircularLinkedList *L) {
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
// 10. Deletar a lissta
int deleteLinkedList(CircularLinkedList *L) {
    // 1. Valida se a lista existe
    if (L == NULL) return 0;
    
    // 2. Percorre a lista do início até o final
    Node *current = L->head;
    while (current != NULL) {
        // Guarda o próximo nó antes de liberar o atual
        Node *aux = current->next;
        // Libera a memória do nó atual
        free(current);
        // Avança para o próximo nó
        current = aux;
    }
    
    // 3. Reseta a lista
    L->head = NULL;
    L->size = 0;
    
    return 1;
}

/**
 * MAIN
 */
int main() {

    CircularLinkedList linkedlist;
    initList(&linkedlist);
    int option, value, index;

    do {
        printf("\n--- MENU LISTA ESTATICA ---\n");
        printf("1. Inserir na Direita  | 2. Inserir na Esquerda  | 3. Inserir Ordenado\n");
        printf("4. Remover da Direita  | 5. Remover da esquerda  | 6. Remover por Valor\n");
        printf("7. Buscar Elemento     | 8. Imprimir Lista       | 9. Deletar Lista\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Valor: "); scanf("%d", &value);
                insertAtLeft(&linkedlist, value);
                break;
            case 2:
                printf("Valor: "); scanf("%d", &value);
                insertByOrder(&linkedlist, value);
                break;
            case 3:
                printf("Valor: "); scanf("%d", &value);
                insertAtLeft(&linkedlist, value);
                break;
            case 4:
                removeAtFront(&linkedlist);
                break;
            case 5:
                removeAtEnd(&linkedlist);
                break;
            case 6:
                printf("Valor: "); scanf("%d", &value);
                removeByValue(&linkedlist, value);
                break;
            case 7:
                printf("Valor: "); scanf("%d", &value);
                index = searchByValue(&linkedlist, value);
                break;
            case 8:
                printList(&linkedlist);
                break;
            case 9:
                deleteLinkedList(&linkedlist);
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
