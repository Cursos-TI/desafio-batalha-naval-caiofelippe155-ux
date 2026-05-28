#include <stdio.h>

int main() {

    int tabuleiro[10][10] = {0};

    // Criar os vetores dos navios

    int navioVertical[3] = {3, 3, 3};
    int navioHorizontal[3] = {3, 3, 3};
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};

    // Definir as coordenadas iniciais

    int linhaVertical = 2;
    int colunaVertical = 1;

    int linhaHorizontal = 5;
    int colunaHorizontal = 6;

    int linhaDiagonal1 = 5;
    int colunaDiagonal1 = 2;

    int linhaDiagonal2 = 3;
    int colunaDiagonal2 = 6;

    // =========================
    // NAVIO VERTICAL
    // =========================

    if (linhaVertical + 3 <= 10) {

        // Verifica sobreposição
        int sobreposicao = 0;

        for (int i = 0; i < 3; i++) {

            if (tabuleiro[linhaVertical + i][colunaVertical] != 0) {
                sobreposicao = 1;
            }
        }

        // Posiciona o navio
        if (sobreposicao == 0) {

            for (int i = 0; i < 3; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            }

        } else {
            printf("Sobreposição no navio vertical.\n");
        }

    } else {
        printf("Posição inválida para o navio vertical.\n");
    }

    // =========================
    // NAVIO HORIZONTAL
    // =========================

    if (colunaHorizontal + 3 <= 10) {

        // Verifica sobreposição
        int sobreposicao = 0;

        for (int i = 0; i < 3; i++) {

            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != 0) {
                sobreposicao = 1;
            }
        }

        // Posiciona o navio
        if (sobreposicao == 0) {

            for (int i = 0; i < 3; i++) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
            }

        } else {
            printf("Sobreposição no navio horizontal.\n");
        }

    } else {
        printf("Posição inválida para o navio horizontal.\n");
    }

    // =========================
    // NAVIO DIAGONAL PRINCIPAL
    // =========================

    if (colunaDiagonal1 + 3 <= 10 && linhaDiagonal1 + 3 <= 10) {

        // Verifica sobreposição
        int sobreposicao = 0;

        for (int i = 0; i < 3; i++) {

            if (tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] != 0) {
                sobreposicao = 1;
            }
        }

        // Posiciona o navio
        if (sobreposicao == 0) {

            for (int i = 0; i < 3; i++) {
                tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = navioDiagonal1[i];
            }

        } else {
            printf("Sobreposição no navio diagonal principal.\n");
        }

    } else {
        printf("Posição inválida para o navio diagonal principal.\n");
    }

    // =========================
    // NAVIO DIAGONAL SECUNDÁRIO
    // =========================

    if (colunaDiagonal2 - 2 >= 0 && linhaDiagonal2 + 3 <= 10) {

        // Verifica sobreposição
        int sobreposicao = 0;

        for (int i = 0; i < 3; i++) {

            if (tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] != 0) {
                sobreposicao = 1;
            }
        }

        // Posiciona o navio
        if (sobreposicao == 0) {

            for (int i = 0; i < 3; i++) {
                tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = navioDiagonal2[i];
            }

        } else {
            printf("Sobreposição no navio diagonal secundário.\n");
        }

    } else {
        printf("Posição inválida para o navio diagonal secundário.\n");
    }

    // =========================
    // EXIBIR TABULEIRO
    // =========================

    printf("TABULEIRO BATALHA NAVAL\n\n");

    for (int linha = 0; linha < 10; linha++) {

        for (int coluna = 0; coluna < 10; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }

    return 0;
}