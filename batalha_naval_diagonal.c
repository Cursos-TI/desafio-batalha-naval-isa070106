#include <stdio.h>

// Definindo o tamanho do tabuleiro e dos navios
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para verificar se o navio pode ser posicionado horizontalmente
int podePosicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM_TABULEIRO) {
        return 0; // Não cabe na horizontal
    }

    // Verifica se o navio se sobrepõe a outro
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            return 0; // Já há um navio na posição
        }
    }
    return 1;
}

// Função para posicionar o navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3; // 3 representa parte do navio
    }
}

// Função para verificar se o navio pode ser posicionado verticalmente
int podePosicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO) {
        return 0; // Não cabe na vertical
    }

    // Verifica se o navio se sobrepõe a outro
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            return 0; // Já há um navio na posição
        }
    }
    return 1;
}

// Função para posicionar o navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; // 3 representa parte do navio
    }
}

// Função para verificar se o navio pode ser posicionado diagonalmente (da esquerda para direita)
int podePosicionarNavioDiagonal1(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO) {
        return 0; // Não cabe na diagonal
    }

    // Verifica se o navio se sobrepõe a outro
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) {
            return 0; // Já há um navio na posição
        }
    }
    return 1;
}

// Função para posicionar o navio diagonalmente (da esquerda para direita)
void posicionarNavioDiagonal1(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3; // 3 representa parte do navio
    }
}

// Função para verificar se o navio pode ser posicionado diagonalmente (da direita para esquerda)
int podePosicionarNavioDiagonal2(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna - TAM_NAVIO + 1 < 0) {
        return 0; // Não cabe na diagonal
    }

    // Verifica se o navio se sobrepõe a outro
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] != 0) {
            return 0; // Já há um navio na posição
        }
    }
    return 1;
}

// Função para posicionar o navio diagonalmente (da direita para esquerda)
void posicionarNavioDiagonal2(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3; // 3 representa parte do navio
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]); // Alinha as colunas
        }
        printf("\n");
    }
}

int main() {
    // Declaração do tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas para os navios
    int linhaNavioHorizontal = 2, colunaNavioHorizontal = 3;
    int linhaNavioVertical = 5, colunaNavioVertical = 6;
    int linhaNavioDiagonal1 = 0, colunaNavioDiagonal1 = 0;
    int linhaNavioDiagonal2 = 7, colunaNavioDiagonal2 = 9;

    // Posiciona os navios
    if (podePosicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal);
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
    }

    if (podePosicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical);
    } else {
        printf("Erro ao posicionar navio vertical!\n");
    }

    if (podePosicionarNavioDiagonal1(tabuleiro, linhaNavioDiagonal1, colunaNavioDiagonal1)) {
        posicionarNavioDiagonal1(tabuleiro, linhaNavioDiagonal1, colunaNavioDiagonal1);
    } else {
        printf("Erro ao posicionar navio diagonal 1!\n");
    }

    if (podePosicionarNavioDiagonal2(tabuleiro, linhaNavioDiagonal2, colunaNavioDiagonal2)) {
        posicionarNavioDiagonal2(tabuleiro, linhaNavioDiagonal2, colunaNavioDiagonal2);
    } else {
        printf("Erro ao posicionar navio diagonal 2!\n");
    }

    // Exibe o tabuleiro final
    printf("Tabuleiro Final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
