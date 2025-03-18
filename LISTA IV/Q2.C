//Desenvolver uma função que, dada uma matriz
//Mm×n, determine se um número X se encontra
//na linha L da matriz.


#include <stdio.h>

void encontrarnum(int linhas, int colunas, int mat[linhas][colunas], int num, int L) {
   
    if (L < 0 || L >= linhas) {
        printf("Linha invalida!\n");
       
    }

    for (int j = 0; j < colunas; j++) {
        if (mat[L][j] == num) {
            printf("Achou\n");
            return; // SE ENCONTRAR, ENCERRA.
        }
    }

    printf("Nao encontrado\n");
}

int main() {
    int num, linhas = 4, colunas = 4, L;
    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Insira o numero a ser procurado: ");
    scanf("%d", &num);
    printf("Insira a linha: ");
    scanf("%d", &L);

    encontrarnum(linhas, colunas, mat, num, L);

    return 0;
}