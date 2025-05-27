#include <stdio.h> // Para printf

void bubbleSortSimples(int arr[], int n) {
    
    /*n - 1: O j sempre precisa ir até o penúltimo elemento a ser comparado,
    porque ele compara arr[j] com arr[j + 1]. Se j chegasse a n - 1, j + 1 
    estaria fora dos limites do array.
    
    
    - i: Esta parte é a otimização. Em cada passagem do laço externo (i aumenta),
    os maiores elementos já foram movidos para as posições finais do array. 
    Isso significa que não precisamos mais comparar esses elementos já ordenados.
    O - i reduz o limite superior do laço interno, fazendo com que ele compare
    apenas a parte "não ordenada" do array.*/

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // Se o elemento atual for maior que o próximo, troca
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// Exemplo de uso:
int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSortSimples(arr, n);
    printf("Array ordenado (Bubble Sort Simples): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Saída: 1 2 4 5 8
    return 0;
}