/*Fazer uma função que, dada uma matriz Mn×n,
determine se ela é simétrica.*/

#include <stdio.h>

int ehsimetrica(int num, int matriz[num][num]){
    
  int i, j;
  
    for(int i=0; i< num - 1; i++){ //num-1 pra eliminar a analise da ultima linha. 
        
        for (int j= i+1; j< num; j++){
            
        if(matriz[i][j] != matriz[j][i]){
            return 0;//n é ehsimetrica
        }
            
        }
    }
     return 1;// é ehsimetrica
}

void main() {

    int matriz[3][3] = 
    {{1, 2, 3}, 
    {6, 4, 5},
    {3, 5, 6}
        
    };

  
    if (ehsimetrica(3, matriz)) {
        printf("\nA matriz é simétrica.\n");
    } else {
        printf("\nA matriz não é simétrica.\n");
    }


}
