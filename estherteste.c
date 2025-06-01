#include &lt;stdio.h&gt;
#include &lt;string.h&gt;

#define MAX_CURSOS 10

typedef struct {
    int codigo;
    float nota_enade;
    float idd;
    float doutores;
    float mestres;
    float regime_trabalho;
    float organizacao_didatica;
    float infraestrutura;
    float oportunidades;
    int num_alunos;
    float cpc_continuo;
    int cpc_faixa;
} Tcursos;

// Protótipos de funções
int lerArq(char nomeArquivo[], Tcursos curso[], int *totCursos);
int addCurso(char nomeArquivo[], Tcursos curso[], int *totCursos);
void calcularCPC(Tcursos *curso);
int converterCPCFaixa(float cpc);
void gerarRel(Tcursos curso[], int totCursos);

int main() {
    int resultado, menu, totCursos = 0;
    Tcursos curso[MAX_CURSOS];

    // Verifica se o arquivo existe, senão cria um arquivo vazio
    FILE *arqCheck = fopen("EnadeCursos.txt", "r");
    if (arqCheck == NULL) {
        printf("Arquivo EnadeCursos.txt não existe. Tentando criar...\n");
        arqCheck = fopen("EnadeCursos.txt", "w");
        if (arqCheck == NULL) {
            printf("Erro ao criar o arquivo EnadeCursos.txt! Verifique permissões e diretório.\n");
            return 1;
        } else {
            printf("Arquivo EnadeCursos.txt criado com sucesso.\n");
            fclose(arqCheck);
        }
    } else {
        fclose(arqCheck);
    }

    // Lendo o arquivo
    resultado = lerArq("EnadeCursos.txt", curso, &totCursos);
    if (resultado == -1) {
        printf("\nErro na abertura do arquivo!\n");
        return 1;
    } else if (resultado == 0) {
        printf("\nArquivo vazio!\n");
    } else {
        printf("\nForam lidos %d cursos do arquivo.\n", resultado);
    }

    do {
        printf("\n<<< Olá, seja bem-vindo(a) ao Enade >>>\n");
        printf("Selecione uma opção:\n");
        printf("1 - Adicionar curso\n");
        printf("2 - Gerar relatório\n");
        printf("0 - Sair do programa\n");
        printf("Opção: ");
        scanf("%d", &menu);

        switch (menu) {
            case 0:
                printf("Até a próxima!\n");
                break;
            case 1:
                addCurso("EnadeCursos.txt", curso, &totCursos);
                break;
            case 2:
                if (totCursos == 0) {
                    printf("Não há nenhum curso para processar.\n");
                } else {
                    gerarRel(curso, totCursos);
                }
                break;
            default:
                printf("Opção inválida! Por favor, digite uma opção válida.\n");
        }
    } while (menu != 0);

    return 0;
}

int lerArq(char nomeArquivo[], Tcursos curso[], int *totCursos) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (!arq) return -1;

    *totCursos = 0;
    while (*totCursos &lt; MAX_CURSOS &&
           fscanf(arq, "%d|%f|%f|%f|%f|%f|%f|%f|%f|%d",
                  &curso[*totCursos].codigo,
                  &curso[*totCursos].nota_enade,
                  &curso[*totCursos].idd,
                  &curso[*totCursos].doutores,
                  &curso[*totCursos].mestres,
                  &curso[*totCursos].regime_trabalho,
                  &curso[*totCursos].organizacao_didatica,
                  &curso[*totCursos].infraestrutura,
                  &curso[*totCursos].oportunidades,
                  &curso[*totCursos].num_alunos) == 10) {
        calcularCPC(&curso[*totCursos]);
        (*totCursos)++;
    }
    fclose(arq);
    return *totCursos;
}

int addCurso(char nomeArquivo[], Tcursos curso[], int *totCursos) {
    if (*totCursos >= MAX_CURSOS) {
        printf("Limite máximo de cursos atingido.\n");
        return 0;
    }
    Tcursos novo;
    printf("Digite o código do curso: ");
    scanf("%d", &novo.codigo);
    printf("Nota ENADE: ");
    scanf("%f", &novo.nota_enade);
    printf("IDD: ");
    scanf("%f", &novo.idd);
    printf("Número de doutores: ");
    scanf("%f", &novo.doutores);
    printf("Número de mestres: ");
    scanf("%f", &novo.mestres);
    printf("Regime de trabalho: ");
    scanf("%f", &novo.regime_trabalho);
    printf("Organização didático-pedagógica: ");
    scanf("%f", &novo.organizacao_didatica);
    printf("Infraestrutura: ");
    scanf("%f", &novo.infraestrutura);
    printf("Oportunidades de ampliação acadêmica: ");
    scanf("%f", &novo.oportunidades);
    printf("Número de alunos matriculados: ");
    scanf("%d", &novo.num_alunos);

    calcularCPC(&novo);
    curso[*totCursos] = novo;
    (*totCursos)++;

    FILE *arq = fopen(nomeArquivo, "a");
    if (!arq) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 0;
    }
    fprintf(arq, "%d|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%d\n",
            novo.codigo,
            novo.nota_enade,
            novo.idd,
            novo.doutores,
            novo.mestres,
            novo.regime_trabalho,
            novo.organizacao_didatica,
            novo.infraestrutura,
            novo.oportunidades,
            novo.num_alunos);
    fclose(arq);
    printf("Curso adicionado com sucesso!\n");
    return 1;
}

void calcularCPC(Tcursos *curso) {
    curso->cpc_continuo = (curso->nota_enade * 0.20f) +
                          (curso->idd * 0.35f) +
                          (curso->doutores * 0.15f) +
                          (curso->mestres * 0.075f) +
                          (curso->regime_trabalho * 0.075f) +
                          (curso->organizacao_didatica * 0.075f) +
                          (curso->infraestrutura * 0.05f) +
                          (curso->oportunidades * 0.025f);

    curso->cpc_faixa = converterCPCFaixa(curso->cpc_continuo);
}

int converterCPCFaixa(float cpc) {
    if (cpc < 0.945f)
        return 1;
    else if (cpc < 1.945f)
        return 2;
    else if (cpc < 2.945f)
        return 3;
    else if (cpc < 3.945f)
        return 4;
    else
        return 5;
}

void gerarRel(Tcursos curso[], int totCursos) {
    int i, faixa;
    int countFaixa[6] = {0};

    printf("\nRelatório dos Cursos:\n");
    for (i = 0; i < totCursos; i++) {
        printf("Código: %d, CPC Contínuo: %.2f, CPC Faixa: %d, Classificação: %s\n",
               curso[i].codigo,
               curso[i].cpc_continuo,
               curso[i].cpc_faixa,
               (curso[i].cpc_faixa < 3) ? "Insatisfatório" : "Satisfatório");
        countFaixa[curso[i].cpc_faixa]++;
    }

    printf("\nCursos por CPC Faixa:\n");
    for (faixa = 1; faixa <=5; faixa++) {
        printf("Faixa %d: ", faixa);
        if (countFaixa[faixa] == 0) {
            printf("Nenhum curso\n");
        } else {
            for (i = 0; i < totCursos; i++) {
                if (curso[i].cpc_faixa == faixa) {
                    printf("%d ", curso[i].codigo);
                }
            }
            printf("\n");
        }
    }

    float somaPonderada = 0;
    int totalAlunos = 0;
    for (i = 0; i < totCursos; i++) {
        somaPonderada += curso[i].cpc_continuo * curso[i].num_alunos;
        totalAlunos += curso[i].num_alunos;
    }
    float igc_continuo = (totalAlunos > 0) ? somaPonderada / totalAlunos : 0;
    int igc_faixa = converterCPCFaixa(igc_continuo);

    printf("\nIGC da Instituição - Contínuo: %.2f, Faixa: %d\n", igc_continuo, igc_faixa);
}

