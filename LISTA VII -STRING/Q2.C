/*
Questão 02:
Dada uma string s, desenvolver uma função que determine se s é 
ou não um palíndromo.

Observação: uma string s será um palíndromo quando seus 
caracteres formarem a mesma sequência, independente se s 
é percorrida da esquerda para direita ou vice-versa.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
int palindromo (char s[]);

//main
void main ()
{
//declaração de variáveis
char str[10];

//lendo a string
printf ("Entre com uma string: ");
gets (str);

//chamando a função
//if (palindromo(str)==1)
if (palindromo(str))
{
    printf ("\nA string %s e um palindromo!\n", str);
}
else
{
    printf ("\nA string %s NAO e um palindromo!\n", str);
}
}

//implementação das funções
int palindromo (char s[])
{
//declaração de variáveis
int i, j;

//comparando os caracteres
for (i=0,j=strlen(s)-1;i<j;i++,j--)
{
    //se dois caracteres diferentes forem encontrados, 's' não é palíndromo
    if (s[i] != s[j])
    {
        return 0;
    }
}

return 1;
}