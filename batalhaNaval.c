#include <stdio.h>

int main() {
    int tabuleiro [10][10] = {0};

    //Criar os vetores dos navios

    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    //Definir as coordenadas iniciais

    int linhaHorizontal = 2;
    int colunaHorizontal = 1;

    int linhaVertical = 5;
    int colunaVertical = 7;

    //Validar os limites do navio horizontal

    if (colunaHorizontal + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaHorizontal ][colunaHorizontal + i] = navioHorizontal[i];
        }
    } else {
        printf("Posição inválida para o navio horizontal.\n");
    }

    //Validar os limites do navio vertical
    
    printf("TABULEIRO BATALHA NAVAL\n\n");
    if (linhaVertical + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
        }
    } else {
        printf("Posição inválida para o navio vertical.\n");
    }

    //Exibir o tabuleiro

        // Exibição do tabuleiro
    printf("TABULEIRO BATALHA NAVAL\n\n");

    for (int linha = 0; linha < 10; linha++) {

        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }

    return 0;
}