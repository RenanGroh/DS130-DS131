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
    struct Node *prev, *next;  // Ponteiro para o proximo Nó e para o anterior
} Node;

/**
 * Estrutura LinkedList(Lista Encadeada): Guarda a referencia do primeiro elemento (Head).
 */
typedef struct DoublyLinkedList {
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
    newNode->prev = NULL;

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
    
    // lista vazia: o novo nó é o head
    // 1. O próximo do novo nó aponta para onde a lista começava (antigo head)
    node->next = list->head;
    
    // 2. Se a lista não estiver vazia, o 'prev' do antigo head aponta para o novo nó
    if (list->head != NULL) {
        list->head->prev = node;
    }
    
    // 3. A "cabeça" da lista passa a ser o novo nó
    list->head = node;
    // 4. Aumenta o tamanho da lista
    list->size++;
    return 1;
}

// 3. insere no fim
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

// 4. Insere no meio, deforma ordenada | USO EXCLUSIVO
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

// 5. remove do inicio
int removeAtFront(LinkedList *list) {
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
int removeAtEnd(LinkedList *list) {
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
int removeByValue(LinkedList *list, int value) {
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
int searchByValue(LinkedList *list, int value) {
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
        printf("[%d] <-> ", current->data);
        
        // O "pulo": o ponteiro atual passa a ser o próximo
        current = current->next;
    }
    printf("NULL\n");
}

// 9.1 Imprime a lista de trás para frente (Para testar o ponteiro prev)
void printListReverse(LinkedList *L) {
    if (L == NULL || L->head == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    
    // 1. Navega até o último nó da lista
    Node *current = L->head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // 2. Percorre a lista de trás para frente usando o prev
    printf("Lista Reversa:   ");
    while (current != NULL) {
        printf("[%d] <-> ", current->data);
        current = current->prev; // O "pulo" agora é para trás!
    }
    printf("NULL\n");
}

// 10. Deletar a lissta
int deleteLinkedList(LinkedList *L) {
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

    LinkedList linkedlist;
    initList(&linkedlist);
    int option, value, index;

    do {
        printf("\n--- MENU LISTA DUPLAMENTE ENCADEADA ---\n");
        printf("1. Inserir Inicio  | 2. Inserir Meio | 3. Inserir Fim\n");
        printf("4. Remover Inicio  | 5. Remover Fim  | 6. Remover do Indice\n");
        printf("7. Buscar Elemento | 8. Imprimir (Normal) | 88. Imprimir (Reverso) | 9. Deletar Lista\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Valor: "); scanf("%d", &value);
                insertAtFront(&linkedlist, value);
                break;
            case 2:
                printf("Valor: "); scanf("%d", &value);
                insertAtMiddle(&linkedlist, value);
                break;
            case 3:
                printf("Valor: "); scanf("%d", &value);
                insertAtFront(&linkedlist, value);
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
            case 88:
                printListReverse(&linkedlist);
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
