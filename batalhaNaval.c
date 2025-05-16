#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código implementa os três níveis de complexidade do jogo Batalha Naval.

// Definições para facilitar a leitura do código
#define TABULEIRO_NOVATO_LINHAS 5
#define TABULEIRO_NOVATO_COLUNAS 5
#define TABULEIRO_AVENTUREIRO_LINHAS 10
#define TABULEIRO_AVENTUREIRO_COLUNAS 10

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[][TABULEIRO_AVENTUREIRO_COLUNAS], int linhas, int colunas) {
    printf("  ");
    for (int j = 0; j < colunas; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < linhas; i++) {
        printf("%d ", i);
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// *** Nível Novato ***
void nivelNovato() {
    printf("--- Nível Novato ---\n");
    int tabuleiro[TABULEIRO_NOVATO_LINHAS][TABULEIRO_NOVATO_COLUNAS] = {0};

    // Posicionamento do navio vertical (tamanho 3)
    int navioVerticalLinha = 1;
    int navioVerticalColuna = 1;
    int tamanhoNavioVertical = 3;

    printf("Posicionando navio vertical (tamanho %d) em (%d, %d) a (%d, %d):\n",
           tamanhoNavioVertical, navioVerticalLinha, navioVerticalColuna,
           navioVerticalLinha + tamanhoNavioVertical - 1, navioVerticalColuna);

    for (int i = 0; i < tamanhoNavioVertical; i++) {
        if (navioVerticalLinha + i < TABULEIRO_NOVATO_LINHAS) {
            tabuleiro[navioVerticalLinha + i][navioVerticalColuna] = 3;
            printf("Parte do navio em (%d, %d)\n", navioVerticalLinha + i, navioVerticalColuna);
        }
    }

    printf("\n");

    // Posicionamento do navio horizontal (tamanho 2)
    int navioHorizontalLinha = 3;
    int navioHorizontalColuna = 0;
    int tamanhoNavioHorizontal = 2;

    printf("Posicionando navio horizontal (tamanho %d) em (%d, %d) a (%d, %d):\n",
           tamanhoNavioHorizontal, navioHorizontalLinha, navioHorizontalColuna,
           navioHorizontalLinha, navioHorizontalColuna + tamanhoNavioHorizontal - 1);

    for (int j = 0; j < tamanhoNavioHorizontal; j++) {
        if (navioHorizontalColuna + j < TABULEIRO_NOVATO_COLUNAS) {
            tabuleiro[navioHorizontalLinha][navioHorizontalColuna + j] = 3;
            printf("Parte do navio em (%d, %d)\n", navioHorizontalLinha, navioHorizontalColuna + j);
        }
    }

    printf("\nTabuleiro Nível Novato:\n");
    imprimirTabuleiro(tabuleiro, TABULEIRO_NOVATO_LINHAS, TABULEIRO_NOVATO_COLUNAS);
}

// *** Nível Aventureiro ***
void nivelAventureiro() {
    printf("\n--- Nível Aventureiro ---\n");
    int tabuleiro[TABULEIRO_AVENTUREIRO_LINHAS][TABULEIRO_AVENTUREIRO_COLUNAS] = {0};

    // Posicionamento do navio horizontal (tamanho 4)
    for (int j = 1; j < 5; j++) tabuleiro[1][j] = 3;
    printf("Navio horizontal (tamanho 4) posicionado.\n");

    // Posicionamento do navio vertical (tamanho 3)
    for (int i = 6; i < 9; i++) tabuleiro[i][2] = 3;
    printf("Navio vertical (tamanho 3) posicionado.\n");

    // Posicionamento do navio diagonal (tamanho 2 - Top-Esquerda para Baixo-Direita)
    for (int k = 3; k < 5; k++) tabuleiro[k][k] = 3;
    printf("Navio diagonal (tamanho 2) posicionado (Top-Esquerda para Baixo-Direita).\n");

    // Posicionamento do navio diagonal (tamanho 2 - Top-Direita para Baixo-Esquerda)
    tabuleiro[7][5] = 3;
    tabuleiro[8][4] = 3;
    printf("Navio diagonal (tamanho 2) posicionado (Top-Direita para Baixo-Esquerda).\n");

    printf("\nTabuleiro Nível Aventureiro:\n");
    imprimirTabuleiro(tabuleiro, TABULEIRO_AVENTUREIRO_LINHAS, TABULEIRO_AVENTUREIRO_COLUNAS);
}

// *** Nível Mestre ***
void nivelMestre() {
    printf("\n--- Nível Mestre ---\n");
    int tabuleiro[TABULEIRO_AVENTUREIRO_LINHAS][TABULEIRO_AVENTUREIRO_COLUNAS] = {0};

    printf("Aplicando habilidades especiais:\n\n");

    // Habilidade em Cone (vértice em 2, 5)
    printf("Habilidade Cone (vértice em 2, 5):\n");
    int coneLinha = 2;
    int coneColuna = 5;
    for (int i = 0; i < TABULEIRO_AVENTUREIRO_LINHAS; i++) {
        for (int j = 0; j < TABULEIRO_AVENTUREIRO_COLUNAS; j++) {
            if (i >= coneLinha &&
                j >= (coneColuna - (i - coneLinha)) &&
                j <= (coneColuna + (i - coneLinha))) {
                tabuleiro[i][j] = 1;
            }
        }
    }
    imprimirTabuleiro(tabuleiro, TABULEIRO_AVENTUREIRO_LINHAS, TABULEIRO_AVENTUREIRO_COLUNAS);

    // Limpar o tabuleiro para a próxima habilidade
    for (int i = 0; i < TABULEIRO_AVENTUREIRO_LINHAS; i++) {
        for (int j = 0; j < TABULEIRO_AVENTUREIRO_COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Habilidade em Cruz (centro em 5, 5)
    printf("Habilidade Cruz (centro em 5, 5):\n");
    int cruzLinha = 5;
    int cruzColuna = 5;
    for (int i = 0; i < TABULEIRO_AVENTUREIRO_LINHAS; i++) {
        for (int j = 0; j < TABULEIRO_AVENTUREIRO_COLUNAS; j++) {
            if (i == cruzLinha || j == cruzColuna ||
                (i == cruzLinha - 1 && j == cruzColuna) ||
                (i == cruzLinha + 1 && j == cruzColuna) ||
                (i == cruzLinha && j == cruzColuna - 1) ||
                (i == cruzLinha && j == cruzColuna + 1)) {
                tabuleiro[i][j] = 1;
            }
        }
    }
    imprimirTabuleiro(tabuleiro, TABULEIRO_AVENTUREIRO_LINHAS, TABULEIRO_AVENTUREIRO_COLUNAS);

    // Limpar o tabuleiro para a próxima habilidade
    for (int i = 0; i < TABULEIRO_AVENTUREIRO_LINHAS; i++) {
        for (int j = 0; j < TABULEIRO_AVENTUREIRO_COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Habilidade em Octaedro (centro em 7, 3)
    printf("Habilidade Octaedro (centro em 7, 3):\n");
    int octaedroLinha = 7;
    int octaedroColuna = 3;
    for (int i = 0; i < TABULEIRO_AVENTUREIRO_LINHAS; i++) {
        for (int j = 0; j < TABULEIRO_AVENTUREIRO_COLUNAS; j++) {
            if (abs(i - octaedroLinha) + abs(j - octaedroColuna) <= 1) {
                tabuleiro[i][j] = 1;
            }
        }
    }
    imprimirTabuleiro(tabuleiro, TABULEIRO_AVENTUREIRO_LINHAS, TABULEIRO_AVENTUREIRO_COLUNAS);
}

int main() {
    nivelNovato();
    nivelAventureiro();
    nivelMestre();

    return 0;
}