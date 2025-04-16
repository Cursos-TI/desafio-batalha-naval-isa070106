#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe dentro dos limites
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Navio horizontal não cabe no tabuleiro!\n");
        return 0;
    }

    // Verifica se o navio irá sobrepor outras partes
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            printf("Há sobreposição com outro navio horizontal!\n");
            return 0;
        }
    }

    // Posiciona o navio no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }

    return 1;
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe dentro dos limites
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Navio vertical não cabe no tabuleiro!\n");
        return 0;
    }

    // Verifica se o navio irá sobrepor outras partes
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            printf("Há sobreposição com outro navio vertical!\n");
            return 0;
        }
    }

    // Posiciona o navio no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }

    return 1;
}

int main() {
    // Criando o tabuleiro 10x10 e inicializando com água (valor 0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas de onde os navios serão posicionados (definidos no código)
    int linhaNavioHorizontal = 3, colunaNavioHorizontal = 1;
    int linhaNavioVertical = 2, colunaNavioVertical = 6;

    // Posicionando os navios no tabuleiro
    if (posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        printf("Navio horizontal posicionado com sucesso!\n");
    }

    if (posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        printf("Navio vertical posicionado com sucesso!\n");
    }

    // Exibindo o tabuleiro
    printf("\nTabuleiro do Jogo:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
