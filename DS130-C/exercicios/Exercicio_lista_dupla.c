#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dpessoa
{
    char nome[30];
    int idade;
    char sexo;
} Pessoa;

typedef struct No
{
    Pessoa p;
    struct No *ant, *prox;
} No;

typedef struct ListaDE
{
    No *cabeca;
} ListaDE;

void inicializaLista(ListaDE *l)
{
    l->cabeca = (No *) malloc(sizeof(No));
    if (l->cabeca == NULL)
    {
       printf("Erro de memoria!\n");
       exit(1);
    }
    l->cabeca->ant = l->cabeca;
    l->cabeca->prox = l->cabeca;
}

int listaVazia(ListaDE *l)
{
    return (l->cabeca->prox == l->cabeca);
}

No *criaNo(Pessoa p)
{
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Erro de memoria!\n");
        return NULL;
    }

    novo->p = p;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

void lerPessoa(Pessoa *p)
{
    printf("Nome: ");
    scanf(" %29s", p->nome);

    printf("Idade: ");
    scanf("%d", &p->idade);

    printf("Sexo (F ou M): ");
    scanf("%c", &p->sexo);
}

void inserirAntes(ListaDE *l, No *ref, Pessoa p)
{
    No *novo = criaNo(p);
    if (novo == NULL) return;

    novo->prox = ref;
    novo->ant = ref->ant;
    ref->ant->prox = novo;
    ref->ant = novo;
}

void insereInicio (ListaDE *l)
{
    Pessoa p;
    lerPessoa(&p);
    inserirAntes(l, l->cabeca->prox, p);
}

void insereFim(ListaDE *l)
{
    Pessoa p;
    lerPessoa(&p);
    inserirAntes(l, l->cabeca, p);
}

int tamanhoLista(ListaDE *l)
{
    int tam = 0;
    No *atual = l->cabeca->prox;

    while (atual != l->cabeca)
    {
        tam++;
        atual = atual->prox;
    }

    return tam;
}

void insereMeio(ListaDE *l)
{
    Pessoa p;
    int tam, pos, i;
    No *atual;

    lerPessoa(&p);

    tam = tamanhoLista(l);
    pos = tam / 2;

    atual = l->cabeca->prox;
    for (i = 0; i < pos; i++)
    {
        atual = atual->prox;
    }

    inserirAntes(l, atual, p);
}

void percorreInicioFim(ListaDE *l)
{
    No *atual = l->cabeca->prox;

    if (listaVazia(l))
    {
        printf("Lista vazia.\n");
        return;
    }

    printf("\nPercurso do inicio ao fim:\n");
    while (atual != l->cabeca)
    {
        printf("%s - %d - %c\n", atual->p.nome, atual->p.idade, atual->p.sexo);
        atual = atual->prox;
    }
}

void percorreFimInicio(ListaDE *l)
{
    No *atual = l->cabeca->ant;

    if (listaVazia(l))
    {
        printf("Lista vazia.\n");
        return;
    }

    printf("\nPercurso do fim ao inicio:\n");
    while (atual != l->cabeca)
    {
        printf("%s - %d - %c\n", atual->p.nome, atual->p.idade, atual->p.sexo);
        atual = atual->ant;
    }
}

int removeNo(ListaDE *l, No *no)
{
    if (listaVazia(l) || no == l->cabeca)
    {
        return 0;
    }

    no->ant->prox = no->prox;
    no->prox->ant = no->ant;
    free(no);
    return 1;
}

int removeInicio(ListaDE *l)
{
    if (listaVazia(l))
    {
        printf("Lista vazia.\n");
        return 0;
    }

    return removeNo(l, l->cabeca->prox);
}

int removeFim(ListaDE *l)
{
    if (listaVazia(l))
    {
        printf("Lista vazia.\n");
        return 0;
    }

    return removeNo(l, l->cabeca->ant);
}

int removePorNome(ListaDE *l)
{
    char nome[30];
    No *atual;

    if (listaVazia(l))
    {
        printf("Lista vazia.\n");
        return 0;
    }

    printf("Nome a remover: ");
    scanf(" %29s", nome);

    atual = l->cabeca->prox;
    while (atual != l->cabeca && strcmp(atual->p.nome, nome) != 0)
    {
        atual = atual->prox;
    }

    if (atual == l->cabeca)
    {
        printf("Elemento nao encontrado.\n");
        return 0;
    }

    return removeNo(l, atual);
}

void liberaLista(ListaDE *l)
{
    No *atual = l->cabeca->prox;
    No *aux;

    while (atual != l->cabeca)
    {
        aux = atual->prox;
        free(atual);
        atual = aux;
    }

    free(l->cabeca);
    l->cabeca = NULL;
}

int main()
{
    ListaDE l;
    int opcao;

    inicializaLista(&l);

    do
    {
        printf("\n--- MENU LISTA DUPLAMENTE ENCADEADA COM CABECALHO ---\n");
        printf("1. Insercao no inicio\n");
        printf("2. Insercao no meio\n");
        printf("3. Insercao no fim\n");
        printf("4. Percurso do inicio ao fim\n");
        printf("5. Percurso do fim ao inicio\n");
        printf("6. Remocao do inicio\n");
        printf("7. Remocao do fim\n");
        printf("8. Remocao de um elemento qualquer\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                insereInicio(&l);
                break;
            case 2:
                insereMeio(&l);
                break;
            case 3:
                insereFim(&l);
                break;
            case 4:
                percorreInicioFim(&l);
                break;
            case 5:
                percorreFimInicio(&l);
                break;
            case 6:
                if (removeInicio(&l))
                    printf("Elemento removido do inicio.\n");
                break;
            case 7:
                if (removeFim(&l))
                    printf("Elemento removido do fim.\n");
                break;
            case 8:
                if (removePorNome(&l))
                    printf("Elemento removido.\n");
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    liberaLista(&l);
    return 0;
}
