#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 10
#define NAVIO 3

// Função para inicializar o tabuleiro com zeros
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se há espaço para o navio horizontal/vertical
int podePosicionarHV(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    if (direcao == 'H') {
        if (coluna + NAVIO > TAMANHO) return 0;
        for (int i = 0; i < NAVIO; i++)
            if (tabuleiro[linha][coluna + i] != 0) return 0;
    } else if (direcao == 'V') {
        if (linha + NAVIO > TAMANHO) return 0;
        for (int i = 0; i < NAVIO; i++)
            if (tabuleiro[linha + i][coluna] != 0) return 0;
    }
    return 1;
}

// Função para posicionar o navio horizontal ou vertical
void posicionarHV(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    if (podePosicionarHV(tabuleiro, linha, coluna, direcao)) {
        for (int i = 0; i < NAVIO; i++) {
            if (direcao == 'H')
                tabuleiro[linha][coluna + i] = 3;
            else if (direcao == 'V')
                tabuleiro[linha + i][coluna] = 3;
        }
    }
}

// Função para verificar se há espaço para o navio diagonal
int podePosicionarDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char tipo) {
    if (tipo == 'D') { // diagonal descendente '\'
        if (linha + NAVIO > TAMANHO || coluna + NAVIO > TAMANHO) return 0;
        for (int i = 0; i < NAVIO; i++)
            if (tabuleiro[linha + i][coluna + i] != 0) return 0;
    } else if (tipo == 'A') { // diagonal ascendente '/'
        if (linha - NAVIO + 1 < 0 || coluna + NAVIO > TAMANHO) return 0;
        for (int i = 0; i < NAVIO; i++)
            if (tabuleiro[linha - i][coluna + i] != 0) return 0;
    }
    return 1;
}

// Função para posicionar navio diagonal
void posicionarDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char tipo) {
    if (podePosicionarDiagonal(tabuleiro, linha, coluna, tipo)) {
        for (int i = 0; i < NAVIO; i++) {
            if (tipo == 'D')
                tabuleiro[linha + i][coluna + i] = 3;
            else if (tipo == 'A')
                tabuleiro[linha - i][coluna + i] = 3;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa com água
    inicializarTabuleiro(tabuleiro);

    // Posiciona dois navios horizontais/verticais
    posicionarHV(tabuleiro, 0, 0, 'H');   // Horizontal a partir de (0,0)
    posicionarHV(tabuleiro, 5, 2, 'V');   // Vertical a partir de (5,2)

    // Posiciona dois navios diagonais
    posicionarDiagonal(tabuleiro, 2, 2, 'D'); // Diagonal descendente (\) a partir de (2,2)
    posicionarDiagonal(tabuleiro, 9, 0, 'A'); // Diagonal ascendente (/) a partir de (9,0)

    // Mostra o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
