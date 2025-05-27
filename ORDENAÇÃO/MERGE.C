#include <stdio.h> // Para printf
#include <stdlib.h> // Para malloc e free

// Função auxiliar para intercalar duas partes ordenadas
void mergeSimples(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria arrays temporários
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copia dados para os arrays temporários
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Intercala de volta para o array original
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia elementos restantes, se houver
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }

    free(L);
    free(R);
}

// Função principal do Merge Sort
void mergeSortSimples(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Ponto médio
        mergeSortSimples(arr, l, m); // Ordena primeira metade
        mergeSortSimples(arr, m + 1, r); // Ordena segunda metade
        mergeSimples(arr, l, m, r); // Intercala as duas metades
    }
}


// Exemplo de uso:
int main() {
    int arr[] = {5, 1, 4, 2, 8, 3, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSortSimples(arr, 0, n - 1);
    printf("Array ordenado (Merge Sort Simples): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Saída: 1 2 3 4 5 6 7 8
    return 0;
}
