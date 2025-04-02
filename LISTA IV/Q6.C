/******************************************************************************

Considere uma loja que mantém em uma
matriz o total vendido por cada funcionário
pelos diversos meses do ano. Ou seja, uma
matriz de 12 linhas (uma por mês) e 10 colunas (10 funcionários). 

Pede-se o desenvolvimento
de uma função para cada item abaixo:

a. Calcular o total vendido durante o ano; FOI

b. Dado um mês fornecido pelo usuário,
determinar o total vendido nesse mês;

c. Dado um funcionário fornecido pelo
usuário, determinar o total vendido por ele
durante o ano;

d. Determinar o mês com maior índice de
vendas;

e. Determinar o funcionário que menos
vendeu durante o ano.

*******************************************************************************/
#include <stdio.h>


void somatot (int linhas, int colunas, int matriz[linhas][colunas]){
    
    int soma=0;
    for(int i=0; i< linhas; i++){
        
        for (int j=0; j< colunas; j++){
            
            soma+= matriz[i][j];
        }
        
    }
    printf("A soma foi: %d", soma);
    
}

//letra b 
int mesfornecido (int meses, int func, int matriz[meses][func], int mes){
    
    int somames;
   for (int j=0; j < func; j++){
       somames += matriz[mes-1][j];
   } 
    return somames;
}

//letra C
int mesmaiorindice(int meses, int func, int matriz[meses][func]) {
    int mes, maior, maiorMes, total;

    maior = mesfornecido(meses, func, matriz, 1);
    maiorMes = 1;

    for (mes = 2; mes <= meses; mes++) {
        total = mesfornecido(meses, func, matriz, mes);
        if (total > maior) {
            maior = total;
            maiorMes = mes;
        }
    }

    return maiorMes;
}


int main()
{
    
int resultado =0;
int mesescolhido;
int meses;
int matriz[12][10] = {
        {98, 69, 3, 22, 21, 86, 12, 32, 37, 46},
        {55, 6, 36, 94, 0, 7, 6, 4, 32, 25},
        {100, 33, 86, 0, 22, 71, 65, 67, 56, 86},
        {71, 88, 80, 22, 67, 79, 56, 98, 47, 22},
        {29, 66, 37, 41, 19, 46, 93, 94, 24, 46},
        {81, 15, 20, 80, 73, 91, 14, 83, 60, 18},
        {78, 82, 3, 0, 27, 41, 56, 45, 2, 12},
        {48, 77, 95, 32, 33, 46, 39, 51, 85, 29},
        {51, 2, 84, 0, 62, 53, 26, 59, 53, 62},
        {37, 73, 26, 52, 16, 61, 57, 21, 99, 0},
        {95, 8, 36, 81, 77, 49, 82, 82, 5, 20},
        {37, 14, 4, 68, 36, 24, 47, 50, 82, 70}
    };
    
//letra a 
somatot (12, 10,matriz);
 
//letrab
printf("\n");
printf("Informe um mês:");
scanf("%d", &mesescolhido);

resultado= mesfornecido (meses, 10, matriz, mesescolhido);
printf("%d", resultado);

    return 0;
}
