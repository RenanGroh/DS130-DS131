/*
Uma   locadora   de   vídeos   tem   guardada,   em   um   vetor   A   de   500   posições,   a
quantidade   de   filmes   retirados   por   seus   clientes   durante   o   ano   de   1997.
Agora,   esta   locadora   está   fazendo   uma   promoção   e,   para   cada   15   filmes
retirados, o cliente tem direito a uma locação grátis. Faça um procedimento
que receba o vetor A por parâmetro e retorna, também por parâmetro, um vetor
contendo a quantidade de locações gratuitas a que cada cliente tem direito.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

#define TOTAL_CLIENTES 500
#define FILMES_PARA_PROMO 15
#define MAX_LOCACOES 100

/**
 * Procedimento que calcula locacoes gratuitas.
 * @param locacoes_feitas: vetor de entrada (A)
 * @param locacoes_gratis: vetor que sera preenchido (retorno por parametro)
 */
void calcular_promocao(int locacoes_feitas[], int locacoes_gratis[]) {
    for (int i = 0; i < TOTAL_CLIENTES; i++) {
        // Como ambos sao int, o C faz a divisao inteira automaticamente
        locacoes_gratis[i] = locacoes_feitas[i] / FILMES_PARA_PROMO;
    }
}

/**
 * Preenche o vetor com valores aleatórios.
 * v[] é recebido por referência (ponteiro).
 */
void preencher_dados_locacao(int v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        // Gera um número entre 0 e 99
        v[i] = rand() % MAX_LOCACOES;
    }
}

int main() {
    int array[TOTAL_CLIENTES];
    int gratuidade[TOTAL_CLIENTES];

    // Chamada da função de preenchimento
    preencher_dados_locacao(array, TOTAL_CLIENTES);

    // Chamada do procedimento passando os endereços dos vetores
    calcular_promocao(array, gratuidade);

    // Visualização dos resultados (Exemplo com os 10 primeiros)
    printf("ID\tLOCACOES\tGRATIS\n");
    printf("------------------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t%d\t\t%d\n", i, array[i], gratuidade[i]);
    }

    return 0;    
}