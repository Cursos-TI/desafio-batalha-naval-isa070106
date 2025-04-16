#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5 // Tamanho das matrizes de habilidade (5x5)


// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(" 0 ");  // Água
            } else if (tabuleiro[i][j] == 3) {
                printf(" 3 ");  // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf(" 5 ");  // Área de efeito
            }
        }
        printf("\n");
    }
}

// Função para gerar a área de efeito em forma de Cone
void gerarHabilidadeCone(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Gerando o cone
    habilidade[0][2] = 1; // Ponto do topo do cone
    habilidade[1][1] = 1; habilidade[1][3] = 1; // Expansão para baixo
    habilidade[2][0] = 1; habilidade[2][1] = 1; habilidade[2][2] = 1; habilidade[2][3] = 1; habilidade[2][4] = 1; // Maior expansão

    // Sobrepondo a habilidade no tabuleiro
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                if (linha + i < TAM_TABULEIRO && coluna + j < TAM_TABULEIRO) {
                    tabuleiro[linha + i][coluna + j] = 5; // Marcando área de efeito
                }
            }
        }
    }
}

// Função para gerar a área de efeito em forma de Cruz
void gerarHabilidadeCruz(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Gerando a cruz
    habilidade[2][0] = 1; habilidade[2][1] = 1; habilidade[2][2] = 1; habilidade[2][3] = 1; habilidade[2][4] = 1; // Linha central
    habilidade[0][2] = 1; habilidade[1][2] = 1; habilidade[3][2] = 1; habilidade[4][2] = 1; // Coluna central

    // Sobrepondo a habilidade no tabuleiro
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                if (linha + i < TAM_TABULEIRO && coluna + j < TAM_TABULEIRO) {
                    tabuleiro[linha + i][coluna + j] = 5; // Marcando área de efeito
                }
            }
        }
    }
}

// Função para gerar a área de efeito em forma de Octaedro
void gerarHabilidadeOctaedro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Gerando o octaedro
    habilidade[0][2] = 1; 
    habilidade[1][1] = 1; habilidade[1][3] = 1; 
    habilidade[2][0] = 1; habilidade[2][1] = 1; habilidade[2][2] = 1; habilidade[2][3] = 1; habilidade[2][4] = 1; 
    habilidade[3][1] = 1; habilidade[3][3] = 1; 
    habilidade[4][2] = 1; 

    // Sobrepondo a habilidade no tabuleiro
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                if (linha + i < TAM_TABULEIRO && coluna + j < TAM_TABULEIRO) {
                    tabuleiro[linha + i][coluna + j] = 5; // Marcando área de efeito
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Definindo as coordenadas de origem para cada habilidade
    int linhaCone = 2, colunaCone = 4;
    int linhaCruz = 4, colunaCruz = 4;
    int linhaOctaedro = 3, colunaOctaedro = 3;

    // Posicionando navios
    tabuleiro[1][1] = 3; // Navio em (1,1)
    tabuleiro[7][7] = 3; // Navio em (7,7)

    // Aplicando as habilidades
    gerarHabilidadeCone(tabuleiro, linhaCone, colunaCone);
    gerarHabilidadeCruz(tabuleiro, linhaCruz, colunaCruz);
    gerarHabilidadeOctaedro(tabuleiro, linhaOctaedro, colunaOctaedro);

    // Exibindo o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
