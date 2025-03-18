/******************************************************************************
Implementar uma função que, dada uma matriz
Mm×n, gere um vetor V de tamanho n, onde
cada elemento do vetor consiste na soma dos
elementos de uma coluna de M. Ou seja, o
elemento V[0] consiste na soma dos elementos
da primeira coluna de M, o elemento V[1]
consiste na soma dos elementos da segunda
coluna de M, e assim por diante.

*******************************************************************************/

#include <stdio.h>

void vetordamatriz(int linhas, int colunas, int matriz[linhas][colunas], int vet[]) {
    int i, j;

    // Soma os elementos de cada coluna
    for (j = 0; j < colunas; j++) {
          vet[j] = 0;
        for (i = 0; i < linhas; i++) {
            vet[j] += matriz[i][j];
        }
    }
}

void exibir(int vetor[], int tamanho) {
    int i; 
    printf("\nElementos:");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]); 
    }
    printf("\n");
}

int main() {
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    int vet[4];
    
    vetordamatriz(4, 4, matriz, vet);
    exibir(vet, 4);
    
    return 0;
}