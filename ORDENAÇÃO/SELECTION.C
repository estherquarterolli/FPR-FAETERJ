#include <stdio.h> // Para printf

void selectionSortSimples(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int indice_min = i; // Assume que o primeiro elemento é o menor
        for (int j = i + 1; j < n; j++) {
            // Encontra o menor elemento na parte não ordenada
            if (arr[j] < arr[indice_min]) {
                indice_min = j;
            }
        }
        // Troca o menor elemento encontrado com o elemento na posição 'i'
        int temp = arr[indice_min];
        arr[indice_min] = arr[i];
        arr[i] = temp;
    }
}


// Exemplo de uso:
int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSortSimples(arr, n);
    printf("Array ordenado (Selection Sort Simples): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Saída: 1 2 4 5 8
    return 0;
}
