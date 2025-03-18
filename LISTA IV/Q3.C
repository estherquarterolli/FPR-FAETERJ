/*Desenvolver uma função que gere uma matriz
Mnn, nos moldes do exemplo apresentado a
seguir (que consiste em uma matriz de ordem
5)*/

#include <stdio.h>

void matrizordem(int num, int mat[num][num]){
    
        for(int i=1; i<=num;i++){
            for(int j=0; j< num; j++){
                printf("%d", i+j);
            }
            printf("\n");
        }
}

int main()
{
    int num;
    int mat[num][num];
    
    printf("Informe um num");
    scanf("%d", &num);
   
matrizordem(num,mat);
    return 0;
}
