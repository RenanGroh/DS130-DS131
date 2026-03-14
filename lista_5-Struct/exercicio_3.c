/**
 * Defina uma estrutura que irá representar bandas de música. Essa estrutura deve ter o
 * nome da banda, que tipo de música ela toca, o número de integrantes e em que
 * posição do ranking essa banda está dentre as suas 5 bandas favoritas.
    a) Crie um looping para preencher as 5 estruturas de bandas criadas no exemplo
    passado. Após criar e preencher, exiba todas as informações das bandas/estruturas.
    b) Crie uma função que peça ao usuário um número de 1 até 5.
    Em seguida, seu programa deve exibir informações da banda cuja posição no seu ranking
    é a que foi solicitada pelo usuário.
    c) Crie uma função em C que peça ao usuário um tipo de música e exiba as bandas com
    esse tipo de música no seu ranking. Que função da string.h você usaria para comparar as
    strings que representam o tipo de banda?
    d) Crie uma função que peça o nome de uma banda ao usuário e diga se ela está entre
    suas bandas favoritas ou não.
    e) Crie uma aplicação que exibe um menu com as opções de preencher as estruturas e
    todas as opções das questões passadas.
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NUM_BANDAS 5

typedef struct {
    char name[100];
    char genere[100];
    int member_num;
    int rank_pos;
} Band;

bool is_rank_available(Band bands[], int total, int rank_pretendido) {
    if (rank_pretendido < 1 || rank_pretendido > 5) return false;
    for (int i = 0; i < total; i++) {
        if (bands[i].rank_pos == rank_pretendido) {
            return false; // Já existe uma banda com esse rank
        }
    }
    return true;
}   

void add_band(Band bands[], int current_index) {
    Band *band = &bands[current_index]; // ponteiro para facilitar a escrita
    int rank;

    printf("Digite o nome da banda: ");
    scanf(" %[^\n]", band->name);

    printf("Digite o genero da banda: ");
    scanf(" %[^\n]", band->genere);

    printf("Digite o numero de integrantes da banda: ");
    scanf("%d", &band->member_num);

    // Loop de validação do Rank
    do {
        printf("Digite o rank da banda: ");
        scanf("%d", &rank);

        if (!is_rank_available(bands, current_index, rank)) {
            printf("[ERRO] Rank invalido ou ja ocupado! Tente novamente.\n");
        }
    } while (!is_rank_available(bands, current_index, rank));

    band->rank_pos = rank;
    printf("Banda '%s' cadastrada com Rank %d!\n", band->name, band->rank_pos);
}

void show_band_by_rank () {
    int rank = 0;
    printf("Digite o rank(1-5) da banda para consultar:");
    scanf("%d", &rank);
}

int main() {
    Band bands[NUM_BANDAS];

    //  #### A ###
    // Inicializamos os rankings com 0 para evitar lixo de memória 
    // que possa bugar a nossa função de validação
    for (int i = 0; i < NUM_BANDAS; i++) {
        bands[i].rank_pos = 0;
    }

    printf("=== SISTEMA DE CADASTRO DE BANDAS ===\n");

    // 2. Loop para preencher as 5 estruturas (Item A do exercício)
    for (int i = 0; i < NUM_BANDAS; i++) {
        // Passamos o array e o índice da banda que estamos cadastrando agora
        add_band(bands, i);
    }
    // mostrar as bandas
    for (int i = 0; i < NUM_BANDAS; i++) {
        printf("--- Informações da banda %d ---\n", i + 1);
        printf("Banda: %s\n", bands[i].name);
        printf("Genero: %s\n", bands[i].genere);
        printf("Numero de membros: %d\n", bands[i].member_num);
        printf("Rank: %d\n", bands[i].rank_pos);
        printf(" \n");
    }
    

    

    return 0;
}