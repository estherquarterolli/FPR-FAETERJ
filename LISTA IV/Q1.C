/*
	QUESTÃO 01:
	Faça uma função que, dada uma matriz Mm×n de reais, gere a 
	matriz Mt, sua transposta.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void gerarTransposta (int lin, int col, int m[lin][col], int mt[col][lin]);

void exibirMatriz (int lin, int col, int m[lin][col]);
void preencherMatrizAleatorio (int lin, int col, int m[lin][col], int limite);

//main
void main ()
{
	//declaração de variáveis
	int matriz1[5][3], matriz2[3][5];
	
	//preenchendo a matriz1 de forma aleatória
	preencherMatrizAleatorio (5, 3, matriz1, 100);

	//exibindo a matriz1
	printf ("Matriz Original:\n\n");
	exibirMatriz (5, 3, matriz1);
	
	//gerando a matriz transposta
	gerarTransposta (5, 3, matriz1, matriz2);

	//exibindo a matriz transposta
	printf ("\n\nMatriz Transposta:\n\n");
	exibirMatriz (3, 5, matriz2);	
}

//implementação das funções
void gerarTransposta (int lin, int col, int m[lin][col], int mt[col][lin])
{
	//declaração de variáveis
	int i, j;
	
	for (i=0;i<lin;i++)
	{
		for (j=0;j<col;j++)
		{
			mt[j][i] = m[i][j];
		}
	}
}

void exibirMatriz (int lin, int col, int m[lin][col])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo as linhas da matriz
	for (i=0;i<lin;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<col;j++)
		{
			printf ("%3d ", m[i][j]);
		}
		
		printf ("\n");
	}
}

void preencherMatrizAleatorio (int lin, int col, int m[lin][col], int limite)
{
	//declaração de variáveis
	int i, j;
	
	srand(time(NULL));
	
	//percorrendo as linhas da matriz
	for (i=0;i<lin;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<col;j++)
		{
			m[i][j] = rand()%limite;
		}
	}	
}