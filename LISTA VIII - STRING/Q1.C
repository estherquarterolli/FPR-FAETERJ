// Implementar uma função que, dada uma string
// s, determine a quantidade de caracteres
// distintos em s.

#include <stdio.h>
#include <string.h>

int conta_distintos(const char s[]) {
    int distintos = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int ja_contado = 0;
        
        // Verifica se o caractere já apareceu antes na string
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                ja_contado = 1;
                break;
            }
        }

        // Se não foi contado antes, aumenta o contador de distintos
        if (!ja_contado) {
            distintos++;
        }
    }
    
    return distintos;
}

int main() {
    char s[100];

    printf("Digite uma string: ");
    gets(s); 

    printf("Caracteres distintos: %d\n", conta_distintos(s));
    return 0;
}