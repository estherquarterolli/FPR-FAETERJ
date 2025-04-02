/*Questão 03:
	Desenvolver uma função que, dada uma string s, crie uma 
	substring que inicie na posição p de s  e contenha n 
	caracteres.

	Observações: se p e/ou n forem inválidos, a substring 
	será vazia; ii) se s não possuir n caracteres além de p, a 
	substring a ser criada começará em p e terminará no final de s.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void substring (char str[], int posicao, int quant, char subs[]);

//main
void main ()
{
	//declaração de variáveis
	char s1[20], s2[20];
	int pos, qtd;
	
	//lendo os dados de entrada
	printf ("Entre com uma string: ");
	gets (s1);
	
	printf ("\nPosicao inicial da substring: ");
	scanf ("%d", &pos);

	printf ("\nQuantidade de caracteres da substring: ");
	scanf ("%d", &qtd);
	
	//chamando a função
	substring (s1, pos, qtd, s2);
	
	//exibindo o resultado
	printf ("\n\ns1 = %s  -  s2 = %s\n", s1, s2);	
}

//implementação das funções
void substring (char str[], int posicao, int quant, char subs[])
{
	//declaração de variáveis
	int tam, i, j;
	
	//verificando se 'posicao' ou 'quant' são inválidos
	tam = strlen(str);
	if ((posicao < 0) || (posicao >= tam) || (quant < 1) || (quant > tam))
	{
		subs[0] = '\0';
		//ou:  strcpy (subs, "");
	}
	else
	{
		//copiando os caracteres para a substring
		for (i=posicao,j=0;(j<quant)&&(str[i]);i++,j++)
		{
			subs[j] = str[i];
		}
		
		//terminando a string 'subs'
		subs[j] = '\0';
	}
}