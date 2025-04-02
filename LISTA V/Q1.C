// Considerando a existência de uma matriz de inteiros M, de ordem N (ou seja, o no de linhas e o no de colunas são iguais a
//     N), onde N é uma constante, desenvolver uma função que retorne 1 se a seguinte regra for atendida por M (caso contrário,
//     o valor 0 deverá ser retornado):
//      A soma dos elementos da diagonal principal deve ser igual à soma dos elementos que estão acima desta
//     diagonal, assim como à soma dos elementos abaixo da diagonal.

int ehigual(int num, int mat[num][num]){

    int somadiag=0, somasup=0, somainf==0;
    for (int i=0; i< num ; i++){
        for (int j=0; jj< num; j++){

            if(i==j){
                somadiag+=mat[i][j];
            }
            else if(i>j){
                somainf+=mat[i][j];
            }
            else{
                somasup+=mat[i][j];
            }
        }
    }
}