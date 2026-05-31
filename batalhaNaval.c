#include <stdio.h>

int main() {

    int tabuleiro[10][10] = {0};

    // Criar os vetores dos navios

    int navioVertical[3] = {3, 3, 3};
    int navioHorizontal[3] = {3, 3, 3};
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};

    // Definir as coordenadas iniciais

    int linhaVertical = 0;
    int colunaVertical = 9;

    int linhaHorizontal = 0;
    int colunaHorizontal = 5;

    int linhaDiagonal1 = 3;
    int colunaDiagonal1 = 7;

    int linhaDiagonal2 = 7;
    int colunaDiagonal2 = 4;

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


    // Criar as matrizes das habilidades

    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Construir a matriz Cone

    for (int i = 0; i < 5; i++) 
    {
        for(int j = 0; j < 5; j++)
        {
            if (
                (i == 0 && j == 2) ||
                (i == 1 && j >= 1 && j <= 3) ||
                (i == 2)
            ) {
                cone[i][j] = 1; 
            }    
        }
                
    }

    // Construir a matriz Cruz   
    
    for (int i = 0; i < 5; i++) 
    {
        for(int j = 0; j < 5; j++)
        {
            if (
                (i == 2 || j == 2)
            ) {
                cruz[i][j] = 1; 
            }    
        }
                
    } 
    
    // Construir a matriz Octaedro

    for (int i = 0; i < 5; i++) 
    {
        for(int j = 0; j < 5; j++)
        {
            if (
                (i == 0 && j == 2) ||
                (i == 1 && j >= 1 && j <= 3) ||
                (i == 2) || 
                (i == 3 && j >= 1 && j <= 3) || 
                (i == 4 && j == 2))
            {
                octaedro[i][j] = 1; 
            }    
        }
                
    } 
    
    //Definir origem das habilidades
    
    int origemConeLinha = 2;
    int origemConeColuna = 2;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (cone[i][j] == 1)
            {
                int linhaTabuleiro = origemConeLinha + (i - 2);
                int colunaTabuleiro = origemConeColuna + (j - 2);

                if (
                    linhaTabuleiro >= 0 &&
                    linhaTabuleiro < 10 &&
                    colunaTabuleiro >= 0 &&
                    colunaTabuleiro < 10 &&
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0
                )
                {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }

    int origemCruzLinha = 6;
    int origemCruzColuna = 7;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (cruz[i][j] == 1)
            {
                int linhaTabuleiro = origemCruzLinha + (i - 2);
                int colunaTabuleiro = origemCruzColuna + (j - 2);

                if (
                    linhaTabuleiro >= 0 &&
                    linhaTabuleiro < 10 &&
                    colunaTabuleiro >= 0 &&
                    colunaTabuleiro < 10 &&
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0
                )
                {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }    

    int origemOctaedroLinha = 6;
    int origemOctaedroColuna = 2;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (octaedro[i][j] == 1)
            {
                int linhaTabuleiro = origemOctaedroLinha + (i - 2);
                int colunaTabuleiro = origemOctaedroColuna + (j - 2);

                if (
                    linhaTabuleiro >= 0 &&
                    linhaTabuleiro < 10 &&
                    colunaTabuleiro >= 0 &&
                    colunaTabuleiro < 10 &&
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0
                )
                {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
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