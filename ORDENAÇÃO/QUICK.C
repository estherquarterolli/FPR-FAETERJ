#include <stdio.h> // Para printf

// Função auxiliar para trocar elementos
void swapSimples(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função de particionamento (escolhe o último elemento como pivô)
int partitionSimples(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivô
    int i = (low - 1);     // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            swapSimples(&arr[i], &arr[j]);
        }
    }
    swapSimples(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função principal do Quick Sort
void quickSortSimples(int arr[], int low, int high) {
    if (low < high) {
        // pi é o índice de particionamento
        int pi = partitionSimples(arr, low, high);

        // Ordena recursivamente as sub-arrays
        quickSortSimples(arr, low, pi - 1);
        quickSortSimples(arr, pi + 1, high);
    }
}


// Exemplo de uso:
int main() {
    int arr[] = {5, 1, 4, 2, 8, 3, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSortSimples(arr, 0, n - 1);
    printf("Array ordenado (Quick Sort Simples): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Saída: 1 2 3 4 5 6 7 8
    return 0;
}
