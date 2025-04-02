/******************************************************************************
Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.

*******************************************************************************/
#include <stdio.h>

/*STRLEN*/
int minha_strlen(const char srt[]){
   int tam=0;
   
   while (srt[tam] !=0){
       tam ++;
   }
   return tam;
}
/*STRCY*/
int minha_strcpy( char str1[], char str2[]){
   int i;
   
  for(i=0; str2[i]!='\0'; i++){
      str1[i]=str2[i];
  }
  //finalizando srt1
   str1[i]='\0';
}

/*STRCAT*/
void strConcatenacao (char str1[], char str2[])
{
//declaração de variáveis
	int i, j;
	
	//percorrendo a string 'str2'
	for (i=0,j=minha_strlen(str1);str2[i]!='\0';i++,j++)
	{
		str1[j] = str2[i];
	}	
	
	//finalizando 'str1'
	str1[j] = '\0';
}


/*STRCMP*/ 
int minha_strcmp(const char str1[], const char str2[]){
    int i = 0;
    
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }
    
    return str1[i] - str2[i];
}

int main() {
   /*STRLEN*/ 
    char chara[]="Hello";
    printf("Tamanho: %d\n", minha_strlen(chara)); // Saída: 5

    
     /*STRLCY*/ 
    char destino[50];
    minha_strcpy(destino, "Olá, mundo!");
    printf("Destino: %s\n", destino); // Saída: Olá, mundo!
    
      /*STRcat*/ 
     char str1[20] = "Olá, ";
    strConcatenacao(str1, "mundo!");
    printf("%s\n", str1); // Saída: Olá, mundo!
 
 /*STRCMP*/ 
    
     printf("%d\n", minha_strcmp("banana", "abacaxi")); // Saída: > 0 (banana > abacaxi)
    printf("%d\n", minha_strcmp("abacaxi", "banana")); // Saída: < 0 (abacaxi < banana)
    printf("%d\n", minha_strcmp("maçã", "maçã")); // Saída: 0 (iguais)
    return 0;
}

