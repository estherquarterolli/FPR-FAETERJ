#include <stdio.h> // Para printf

void insertionSortSimples(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i]; // Elemento a ser inserido
        int j = i - 1;

        // Move os elementos maiores para a direita
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave; // Insere a chave na posição correta
    }
}


// Exemplo de uso:
int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSortSimples(arr, n);
    printf("Array ordenado (Insertion Sort   Simples): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Saída: 1 2 4 5 8
    return 0;
}
