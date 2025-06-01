/*
        Testar no terminal compartilhado <jefferson>
             ./AV2
------------------------------------------------------------------O que terá no struch
typedef struct {

    int codigo;

    float nota_enade;
    float idd;
    float doutores;
    float mestres;                  //principais dados que ser printado depois.
    float regime_trabalho;
    float organizacao_didatica;
    float infraestrutura;
    float oportunidades;

    int num_alunos;

    float cpc_continuo;  // calculado depois
    int cpc_faixa;      // calculado depois

} Tcurso;

--------------------------------------------------------------Funções que serão utilizadas
 Calcular CPC CONTINUO (média ponderada) - função int

 Converter para CPC FAIXA - função int ()

 Ler os dados do arquivo e passar para o vetor de struct - função int (ARQUIVO READ)

 Usuario cadastra novo curso




Existe limite de curso????


 



 */

#include <stdio.h>
#include <string.h>


#define MAX_CURSOS 10

// STRUTCH -------------------------------
typedef struct
{

    int codigo[5];

    float nota_enade;
    float idd;
    float doutores;
    float mestres; // principais dados que ser printado depois.
    float regime_trabalho;
    float organizacao_didatica;
    float infraestrutura;
    float oportunidades;

    int num_alunos;

    float cpc_continuo; // calculado depois na função 
    int cpc_faixa;      // calculado depois na função

} Tcursos;
/*Perguntas para o Leo:----------------------------------------

- é necessario criar um arquivo caso ele não exista inicialmente?
- Há necessidade de criar funções específicas ou trabalhar de forma mais abrangente?
 (Isso economiza memória, faz ser mais rápido??)

 - desafio até então passo a passo do algoritmo
   1  . ler o arquivo
   Ao ler o arquivo deve transformar ele em inteiro e depois float para novamente inteiro.
   o passo a passo para transformar outros tipos são bem complexos 
   e alguns que não podemos utilizar
   isso nos atrapalhou e nao sabemos por onde começar basicamente, 
   se é necessario uma função para leitura ou se é necessario 
   abrir ela diretamente na main. 
    

   2. é necessario , salvar nas informações os valores de cpc continuo e faixa no struch?

*/



// FUNÇÕES CABEÇALHO----------------------------------
//ler e converte a string do arquivo para o vetor de struch.
int lerArq(char nomeArquivo[], Tcursos curso[], int *totCursos);
//Adiciona um curso novo manualmente e passa para o arquivo original (gerar arquivo temporario) 
int addCurso(char nomeArquivo[], Tcursos curso[], int *totCursos);
//Calcula o CPC continuo e CPC Faixa e mostra os resultados
int gerarRel(char nomeArquivo[], Tcursos curso[], int *totCursos);

//Função auxiliar para class CPC continuo e IGC
int cpcCONT(int cpc_FAIXA);
int igc ();


// MAIN ----------------------------------
int main(){

    // declaração de variáveis
    int resultado, menu, i, j;
    Tcursos curso[10];

    // lendo o arquivo
    resultado = lerArq("EnadeCursos.txt", Tcursos curso[], int *totcursos);

    // exibindo o resultado
    switch (resultado)
    {
    case -1:
        printf("\n\nErro na abertura do arquivo!\n");
        break;

    case 0:
        printf("\n\nArquivo vazio!\n");
        break;

    default:
        printf("\n\nHa %d caracteres no arquivo %s\n", resultado, nomeArquivo);
    }
    return 0;

    // menu de navegação após leitura

    printf("<<< <Olá, seja bem vindo(a) ao Enade:>>>>> \n Selecione uma escolha:\n 1-Adicionar curso \n 2-Gerar relatorio \n0- Sair do programa \n\n");
    scanf("%d", &menu);
    // while(getchar()!='\n');  Limpa buffer do teclado

    switch (menu)
    {
    case 0: // sair do codigo
        printf("Até a próxima!!");
        break;

    case 1: // Adicionar curso
        adicionarcurso(parametros);
        break;

    case 2: // Processar dados
        if (totcursos == 0)
        {
            printf("Não há nenhum curso para processar");
            break;
        }
        //
        for (int i = 0; i < totcursos; i++)
        {
            /// calcular cpc continuo e faixa
            relatorio(vetor e struch);
            break;
        }

    default:
        printf("Opção Invalida! Por favor, digite uma opção valida:");
        break;
    }
}
/// Implementação das funções:

// ler cursos no arquivo
int lerArq(char nomeArquivo[], Tcursos curso[], int *totCursos){


FILE *arq = fopen(nomeArquivo, "r"); //leitura do arquivo do enade
  *totCursos = 0;
    if (!arq){ //erro de abertura
    
        printf("Deu erro na abertura");
        Return 0; //Retorna 0 cursos lidos
        
    }
  
//lendo os dados do arquivo e promovendo
char linha[256] // array de tamanho fixo

	while (fgets (linha, 256, arq) != EOF && *totCursos < MAX_CURSOS) {
       // linha[strcspn(linha, "\n")] = 0;  Serve para remover o '\n' no final da string
    
        conferir se todos os dados forma lidos corretamente
/* 
if (str=="/n"){    //toda vez que mudar a linha , anda do vetor de struch (curso)
     i++;
     totCursos++;
}
     */

        }
    
    
    }



    int addCurso(char nomeArquivo[], Tcursos curso[], int *totCursos){

        FILE *arq = fopen(nomeArquivo, "a"); //leitura do arquivo do enade

 if (!arq){ //erro de abertura
    
        printf("Deu erro na abertura");
        Return 0; //Retorna 0 cursos lidos
    }
    }
