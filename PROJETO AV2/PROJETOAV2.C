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

// STRUTCH -------------------------------
typedef struct
{

    int codigo;

    float nota_enade;
    float idd;
    float doutores;
    float mestres; // principais dados que ser printado depois.
    float regime_trabalho;
    float organizacao_didatica;
    float infraestrutura;
    float oportunidades;

    int num_alunos;

    float cpc_continuo; // calculado depois
    int cpc_faixa;      // calculado depois

} Tcursos;

// FUNÇÕES CABEÇALHO----------------------------------

int lerArq(char nomeArquivo[], Tcursos curso[]);

// MAIN ----------------------------------
int main()
{

    // declaração de variáveis
    int resultado, menu;
    char nomeArquivo[30] Tcursos curso[10];

    // lendo o nome do arquivo
    printf("Nome do arquivo: ");
    gets(nomeArquivo);

    // lendo o arquivo
    resultado = lerArq(char nomeArquivo[], Tcursos curso[], int *totcursos);

    do
    {
        printf("<<< <Olá, seja bem vindo(a) ao Enade:>>>>> \n Selecione uma escolha:\n 1-Adicionar curso \n 2-Gerar relatorio \n0- Sair do programa \n\n");
        scanf("%d", &menu);
       // while(getchar()!='\n');  Limpa buffer do teclado

        
    
        switch (menu){
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

    } while (menu != 0);

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
}



///Implementação das funções:

//ler cursos no arquivo
int lerArq(char nomeArquivo[], Tcursos curso[], int *totcursos){

FILE *arquivo = fopen(nomeArquivo, "r");

    if (!arq){
      *totcursos = 0;
        printf("Deu erro na abertura :(");
    }
}