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
#include <stdlib.h>

#define MAX_CURSOS 10

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
int igc (char nomeArquivo[], Tcursos curso[], int *totCursos);

void printarCurso(Tcursos curso); //testar o struch

// MAIN ----------------------------------
int main(){

    // declaração de variáveis
    int resultado, totcursos=0,count=0;
    Tcursos curso[10];

    // lendo o arquivo
    resultado = lerArq("EnadeCursos.txt", curso, &totcursos);
   //testando se o vetor foi preenchido corretamente
    while (count<totcursos ) {
    // Imprime o primeiro curso lido
    printarCurso(curso[count]);
    count++;

}
    // exibindo o resultado
    switch (resultado)
    {
    case -1:
        printf("\n\nErro na abertura do arquivo!\n");
        break;

    case 0:
        printf("\n\nArquivo vazio!\n");
        break;
    };
    
/*
    // menu de navegação após leitura

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
        */

    return 0;
}

/// Implementação das funções:
void printarCurso(Tcursos curso) {
    printf("Código do curso: %d\n", curso.codigo);
    printf("Nota ENADE: %.2f\n", curso.nota_enade);
    printf("IDD: %.2f\n", curso.idd);
    printf("Percentual de doutores: %.2f\n", curso.doutores);
    printf("Percentual de mestres: %.2f\n", curso.mestres);
    printf("Regime de trabalho: %.2f\n", curso.regime_trabalho);
    printf("Organização didático-pedagógica: %.2f\n", curso.organizacao_didatica);
    printf("Infraestrutura: %.2f\n", curso.infraestrutura);
    printf("Oportunidades acadêmicas/profissionais: %.2f\n", curso.oportunidades);
    printf("Número de alunos: %d\n", curso.num_alunos);
    printf("CPC contínuo: %.2f\n", curso.cpc_continuo);
    printf("CPC faixa: %d\n", curso.cpc_faixa);
    printf("---------------------------------------\n");
}



// ler cursos no arquivo
int lerArq(char nomeArquivo[], Tcursos curso[], int *totCursos){ //----------------------------------


FILE *arq = fopen(nomeArquivo, "r"); //leitura do arquivo do enade
  *totCursos = 0;
    if (!arq){ //erro de abertura    
        return -1; 
        
    }
  
 //lendo os dados do arquivo e promovendo
 char linha[256];   // vetor que le os arquivos
 int i=0;
	while (fgets (linha, 256, arq) != NULL && *totCursos < MAX_CURSOS){
        
     int campo = 0, k=0, j=0; // campo prenche cada espaço corretamento no struch 
    
     char temp[30]; // para armazenar cada linha do arquivo separadamente
        
    
        for ( /*k=0 */  ; linha[k] != '\0' && linha[k] != '\n'; k++) {
            if (linha[k] != '|') {
                temp[j++] = linha[k];
            } else {
                temp[j] = '\0'; // fecha string
                
                j = 0; //zera o j para contagem do proximo curso.

                switch (campo) {
                    case 0: curso[i].codigo = atoi(temp); break;
                    case 1: curso[i].nota_enade = atof(temp); break;
                    case 2: curso[i].idd = atof(temp); break;
                    case 3: curso[i].doutores = atof(temp); break;
                    case 4: curso[i].mestres = atof(temp); break;
                    case 5: curso[i].regime_trabalho = atof(temp); break;
                    case 6: curso[i].organizacao_didatica = atof(temp); break;
                    case 7: curso[i].infraestrutura = atof(temp); break;
                    case 8: curso[i].oportunidades = atof(temp); break;
                }

                campo++;
            }
        }

        // Último campo (num_alunos), após o último '|'
        temp[j] = '\0';
        curso[i].num_alunos = atoi(temp);

        i++; // próximo curso
        *totCursos=i;
    }

        
fclose(arq);
return 1;

} // --------------------------------------------------------------------------------------





/*
int addCurso(char nomeArquivo[], Tcursos curso[], int *totCursos){

        FILE *arq = fopen(nomeArquivo, "a"); //leitura do arquivo do enade

 if (!arq){ //erro de abertura
    
        printf("Deu erro na abertura");
        fclose(arq);
        Return 0; //Retorna 0 cursos lidos
    }
    }
    
    */