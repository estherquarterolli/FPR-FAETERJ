/*
	
	Questão 04:
	Implementar uma função que remova todas as ocorrências de 
	determinado caracter em uma string.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void removerCaracter (char string[], char caracter);

//main
void main ()
{
	//declaração de variáveis
	char s[20], letra;
	
	//lendo os dados de entrada
	printf ("Entre com uma string: ");
	gets (s);
	
	printf ("\nLetra a ser removida: ");
	scanf ("%c", &letra);

	//exibindo a string antes da remoção
	printf ("\n\ns = %s\n", s);	
	
	//chamando a função
	removerCaracter (s, letra);
	
	//exibindo a string após a remoção
	printf ("\n\ns rem = %s\n", s);	
}

//implementação das funções
void removerCaracter (char string[], char caracter)
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo a string
	for (i=0;string[i];)
	{
		//verificando se 'caracter' foi encontrado
		if (string[i] == caracter)
		{
			//deslocando os caracteres além da posição 'i' uma posição para a esquerda
			for (j=i;string[j];j++)
			{
				string[j] = string[j+1];
			}
		}
		else
		{
			i++;
		}
	}
}