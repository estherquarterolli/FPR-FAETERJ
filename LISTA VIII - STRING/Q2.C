#include <stdio.h>
#include <string.h>

void cria_s3(const char s1[], const char s2[], char s3[]) {
    int index = 0;
    int usados[256] = {0}; // Vetor auxiliar para marcar caracteres já adicionados

    for (int i = 0; s1[i] != '\0'; i++) {
        int encontrado = 0;

        // Verifica se o caractere s1[i] está em s2
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                encontrado = 1;
                break;
            }
        }

        // Se NÃO está em s2 e ainda não foi adicionado a s3, adicionamos
        if (!encontrado && !usados[(char)s1[i]]) {
            s3[index++] = s1[i];
            usados[(char)s1[i]] = 1; // Marca o caractere como já adicionado
        }
    }

    // Finaliza s3
    s3[index] = '\0';
}

int main() {
    char s1[100], s2[100], s3[100];

    printf("Digite a primeira string (s1): ");
    gets(s1); 

    printf("Digite a segunda string (s2): ");
    gets(s2);

    cria_s3(s1, s2, s3);

    printf("String resultante (s3): %s\n", s3);

    return 0;
}
