#include <stdio.h>    // Para operações de entrada/saída (printf, scanf, fopen, fclose, etc.)
#include <stdlib.h>   // Para funções gerais (malloc, free, exit, etc.)
#include <string.h>   // Para manipulação de strings (strcpy, strlen, strcspn, etc.)

// --- Definições de Constantes ---
#define MAX_CURSOS 100  // Capacidade máxima do vetor de cursos em memória
#define TAM_LINHA 256   // Tamanho máximo esperado para uma linha no arquivo de entrada

// --- Estrutura (Struct) para armazenar os dados de cada curso ---
typedef struct {
    char codigo[10]; // Código do curso (ex: "1234")
    float nota_enade;
    float idd;
    float doutores;
    float mestres;
    float regime_trabalho;
    float organizacao_didatico_pedagogica;
    float infraestrutura;
    float oportunidades_ampliacao;
    int num_alunos;
    float cpc_continuo; // Conceito Preliminar de Curso (valor exato)
    int cpc_faixa;      // Conceito Preliminar de Curso (faixa de 1 a 5)
} Curso;

// --- Protótipos das Funções ---
// Funções de Interação com o Usuário
int menu();

// Funções de Manipulação de Arquivos e Dados
void criar_arquivo_se_nao_existe(const char *nome_arquivo);
void ler_cursos_do_arquivo(const char *nome_arquivo, Curso cursos[], int *total_cursos);
void escrever_curso_no_arquivo(FILE *arquivo, const Curso *curso);
void incluir_novo_curso(Curso cursos[], int *total_cursos, const char *nome_arquivo);

// Funções de Cálculo e Processamento
void calcular_cpc_continuo(Curso *curso);
void determinar_cpc_faixa(Curso *curso);
const char* classificar_cpc(int cpc_faixa);
void calcular_e_exibir_igc(const Curso cursos[], int total_cursos);

// Funções de Exibição
void exibir_detalhes_curso(const Curso *curso);
void exibir_cursos_por_cpc_faixa(const Curso cursos[], int total_cursos);

// --- Função Principal do Programa (main) ---
int main() {
    Curso cursos[MAX_CURSOS];
    int total_cursos = 0;
    const char *nome_arquivo = "cursos.txt";

    // Garante que o arquivo exista antes de tentar ler ou escrever nele.
    criar_arquivo_se_nao_existe(nome_arquivo);

    // Tenta carregar os cursos existentes do arquivo.
    ler_cursos_do_arquivo(nome_arquivo, cursos, &total_cursos);

    int opcao;

    do {
        opcao = menu();
        printf("\n");

        switch (opcao) {
            case 1: // Incluir novo(s) curso(s)
                incluir_novo_curso(cursos, &total_cursos, nome_arquivo);
                break;
            case 2: // Processar dados
                if (total_cursos == 0) {
                    printf("Nenhum curso carregado para processar. Adicione cursos primeiro ou verifique o conteúdo do arquivo '%s'.\n", nome_arquivo);
                    break;
                }

                printf("--- Processamento dos Dados dos Cursos ---\n");

                // Calcula CPC para todos os cursos
                for (int i = 0; i < total_cursos; i++) {
                    calcular_cpc_continuo(&cursos[i]);
                    determinar_cpc_faixa(&cursos[i]);
                }

                // 1) Exibir detalhes de cada curso
                printf("\n1) Detalhes de cada curso:\n");
                printf("----------------------------------------------------------------------------------\n");
                printf("%-10s %-15s %-10s %-15s\n", "Código", "CPC Contínuo", "CPC Faixa", "Classificação");
                printf("----------------------------------------------------------------------------------\n");
                for (int i = 0; i < total_cursos; i++) {
                    exibir_detalhes_curso(&cursos[i]);
                }
                printf("----------------------------------------------------------------------------------\n");

                // 2) Exibir cursos por CPC faixa
                printf("\n2) Cursos agrupados por CPC Faixa:\n");
                exibir_cursos_por_cpc_faixa(cursos, total_cursos);

                // 3) Calcular e exibir IGC
                printf("\n3) Índice Geral de Cursos (IGC) da Instituição:\n");
                calcular_e_exibir_igc(cursos, total_cursos);
                break;
            case 0: // Sair
                printf("Saindo do programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Por favor, digite um número válido do menu.\n");
        }
        printf("\n");
    } while (opcao != 0);

    return 0;
}

// --- Implementação das Funções ---

/**
 * @brief Exibe o menu de opções para o usuário e lê a escolha.
 * @return int A opção numérica escolhida pelo usuário.
 */
int menu() {
    int opcao;
    printf("--- Avaliação de Cursos ENADE ---\n");
    printf("1. Incluir novo(s) curso(s)\n");
    printf("2. Processar dados dos cursos\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    while (getchar() != '\n'); // Limpa o buffer do teclado
    return opcao;
}

/**
 * @brief Garante que o arquivo de dados exista. Se não existir, ele é criado vazio.
 * Se houver um erro grave (ex: permissões), o programa é encerrado.
 * @param nome_arquivo O nome do arquivo a ser verificado/criado.
 */
void criar_arquivo_se_nao_existe(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "a+");
    if (arquivo == NULL) {
        printf("ERRO GRAVE: Não foi possível criar ou abrir o arquivo '%s'. Verifique as permissões da pasta.\n", nome_arquivo);
        exit(1);
    }
    fclose(arquivo);
}

/**
 * @brief Lê os dados dos cursos de um arquivo de texto e preenche o vetor de structs.
 * @param nome_arquivo O nome do arquivo a ser lido.
 * @param cursos O vetor de structs Curso a ser preenchido.
 * @param total_cursos Ponteiro para o contador de cursos.
 */
void ler_cursos_do_arquivo(const char *nome_arquivo, Curso cursos[], int *total_cursos) {
    FILE *arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("ERRO: Não foi possível abrir o arquivo '%s' para leitura. O programa continuará com 0 cursos.\n", nome_arquivo);
        *total_cursos = 0;
        return;
    }

    char linha[TAM_LINHA];
    *total_cursos = 0;

    while (fgets(linha, TAM_LINHA, arquivo) != NULL && *total_cursos < MAX_CURSOS) {
        linha[strcspn(linha, "\n")] = 0;

        int resultado_sscanf = sscanf(linha, "%[^|]|%f|%f|%f|%f|%f|%f|%f|%f|%d",
               cursos[*total_cursos].codigo,
               &cursos[*total_cursos].nota_enade,
               &cursos[*total_cursos].idd,
               &cursos[*total_cursos].doutores,
               &cursos[*total_cursos].mestres,
               &cursos[*total_cursos].regime_trabalho,
               &cursos[*total_cursos].organizacao_didatico_pedagogica,
               &cursos[*total_cursos].infraestrutura,
               &cursos[*total_cursos].oportunidades_ampliacao,
               &cursos[*total_cursos].num_alunos);

        if (resultado_sscanf == 10) {
            (*total_cursos)++;
        } else {
            printf("AVISO: Linha com formato inválido no arquivo (ou dados incompletos), ignorada: '%s'\n", linha);
        }
    }

    printf("Cursos carregados do arquivo '%s': %d\n", nome_arquivo, *total_cursos);
    fclose(arquivo);
}

/**
 * @brief Escreve os dados de um curso formatados em uma linha no arquivo.
 * @param arquivo Ponteiro para o arquivo onde o curso será escrito.
 * @param curso Ponteiro constante para a struct Curso a ser escrita.
 */
void escrever_curso_no_arquivo(FILE *arquivo, const Curso *curso) {
    fprintf(arquivo, "%s|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%.2f|%d\n",
            curso->codigo,
            curso->nota_enade,
            curso->idd,
            curso->doutores,
            curso->mestres,
            curso->regime_trabalho,
            curso->organizacao_didatico_pedagogica,
            curso->infraestrutura,
            curso->oportunidades_ampliacao,
            curso->num_alunos);
}

/**
 * @brief Permite ao usuário incluir um novo curso, adicionando-o ao vetor e ao arquivo.
 * @param cursos O vetor de structs Curso.
 * @param total_cursos Ponteiro para o contador de cursos.
 * @param nome_arquivo O nome do arquivo onde o curso será salvo.
 */
void incluir_novo_curso(Curso cursos[], int *total_cursos, const char *nome_arquivo) {
    if (*total_cursos >= MAX_CURSOS) {
        printf("Limite máximo de cursos (%d) atingido. Não é possível adicionar mais cursos em memória.\n", MAX_CURSOS);
        return;
    }

    Curso novo_curso;

    printf("\n--- Inclusão de Novo Curso ---\n");

    printf("Código do Curso (max 9 caracteres): ");
    scanf("%9s", novo_curso.codigo);
    while (getchar() != '\n');

    printf("Nota ENADE (0.00-5.00): ");
    scanf("%f", &novo_curso.nota_enade);
    while (getchar() != '\n');

    printf("IDD (0.00-5.00): ");
    scanf("%f", &novo_curso.idd);
    while (getchar() != '\n');

    printf("Doutores (0.00-5.00): ");
    scanf("%f", &novo_curso.doutores);
    while (getchar() != '\n');

    printf("Mestres (0.00-5.00): ");
    scanf("%f", &novo_curso.mestres);
    while (getchar() != '\n');

    printf("Regime de Trabalho (0.00-5.00): ");
    scanf("%f", &novo_curso.regime_trabalho);
    while (getchar() != '\n');

    printf("Organização Didático-pedagógica (0.00-5.00): ");
    scanf("%f", &novo_curso.organizacao_didatico_pedagogica);
    while (getchar() != '\n');

    printf("Infraestrutura (0.00-5.00): ");
    scanf("%f", &novo_curso.infraestrutura);
    while (getchar() != '\n');

    printf("Oportunidades de Ampliação Acadêmica e Profissional (0.00-5.00): ");
    scanf("%f", &novo_curso.oportunidades_ampliacao);
    while (getchar() != '\n');

    printf("Número de Alunos Matriculados: ");
    scanf("%d", &novo_curso.num_alunos);
    while (getchar() != '\n');

    cursos[*total_cursos] = novo_curso;
    (*total_cursos)++;

    FILE *arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL) {
        printf("ERRO: Não foi possível abrir o arquivo '%s' para escrita. O curso foi adicionado em memória, mas não foi salvo permanentemente.\n", nome_arquivo);
        return;
    }

    escrever_curso_no_arquivo(arquivo, &novo_curso);
    fclose(arquivo);

    printf("Curso '%s' adicionado com sucesso e salvo no arquivo '%s'.\n", novo_curso.codigo, nome_arquivo);
}

/**
 * @brief Calcula o Conceito Preliminar de Curso (CPC) contínuo para um dado curso.
 * @param curso Ponteiro para a struct Curso cujos dados serão usados.
 */
void calcular_cpc_continuo(Curso *curso) {
    curso->cpc_continuo = (curso->nota_enade * 0.20) +
                          (curso->idd * 0.35) +
                          (curso->doutores * 0.15) +
                          (curso->mestres * 0.075) +
                          (curso->regime_trabalho * 0.075) +
                          (curso->organizacao_didatico_pedagogica * 0.075) +
                          (curso->infraestrutura * 0.05) +
                          (curso->oportunidades_ampliacao * 0.025);
}

/**
 * @brief Determina o CPC faixa (1 a 5) com base no CPC contínuo de um curso.
 * @param curso Ponteiro para a struct Curso cujo CPC faixa será atualizado.
 */
void determinar_cpc_faixa(Curso *curso) {
    if (curso->cpc_continuo < 0.945) {
        curso->cpc_faixa = 1;
    } else if (curso->cpc_continuo < 1.945) {
        curso->cpc_faixa = 2;
    } else if (curso->cpc_continuo < 2.945) {
        curso->cpc_faixa = 3;
    } else if (curso->cpc_continuo < 3.945) {
        curso->cpc_faixa = 4;
    } else {
        curso->cpc_faixa = 5;
    }
}

/**
 * @brief Retorna a classificação (Satisfatório ou Insatisfatório) do CPC faixa.
 * @param cpc_faixa O valor do CPC faixa.
 * @return const char* "Satisfatório" se CPC faixa >= 3, "Insatisfatório" caso contrário.
 */
const char* classificar_cpc(int cpc_faixa) {
    if (cpc_faixa >= 3) {
        return "Satisfatório";
    } else {
        return "Insatisfatório";
    }
}

/**
 * @brief Exibe os detalhes de um único curso (código, CPC contínuo, CPC faixa, classificação).
 * @param curso Ponteiro constante para a struct Curso a ser exibida.
 */
void exibir_detalhes_curso(const Curso *curso) {
    printf("%-10s %-15.3f %-10d %-15s\n",
           curso->codigo,
           curso->cpc_continuo,
           curso->cpc_faixa,
           classificar_cpc(curso->cpc_faixa));
}

/**
 * @brief Exibe os cursos agrupados por CPC faixa.
 * @param cursos O vetor de structs Curso.
 * @param total_cursos O número total de cursos no vetor.
 */
void exibir_cursos_por_cpc_faixa(const Curso cursos[], int total_cursos) {
    for (int faixa = 1; faixa <= 5; faixa++) {
        printf("  CPC Faixa %d:\n", faixa);
        int encontrou_cursos_na_faixa = 0;
        for (int i = 0; i < total_cursos; i++) {
            if (cursos[i].cpc_faixa == faixa) {
                printf("    - %s\n", cursos[i].codigo);
                encontrou_cursos_na_faixa = 1;
            }
        }
        if (!encontrou_cursos_na_faixa) {
            printf("    (Nenhum curso nesta faixa)\n");
        }
    }
}

/**
 * @brief Calcula e exibe o Índice Geral de Cursos (IGC) da instituição.
 * O IGC é uma média ponderada dos CPCs dos cursos, onde o peso é o número de alunos.
 * @param cursos O vetor de structs Curso.
 * @param total_cursos O número total de cursos no vetor.
 */
void calcular_e_exibir_igc(const Curso cursos[], int total_cursos) {
    if (total_cursos == 0) {
        printf("Não é possível calcular o IGC: Nenhum curso disponível.\n");
        return;
    }

    float soma_cpc_ponderado = 0.0;
    int soma_alunos = 0;

    for (int i = 0; i < total_cursos; i++) {
        soma_cpc_ponderado += (cursos[i].cpc_continuo * cursos[i].num_alunos);
        soma_alunos += cursos[i].num_alunos;
    }

    if (soma_alunos == 0) {
        printf("Não é possível calcular o IGC: Nenhum aluno matriculado nos cursos cadastrados.\n");
        return;
    }

    float igc_continuo = soma_cpc_ponderado / soma_alunos;
    int igc_faixa;

    if (igc_continuo < 0.945) {
        igc_faixa = 1;
    } else if (igc_continuo < 1.945) {
        igc_faixa = 2;
    } else if (igc_continuo < 2.945) {
        igc_faixa = 3;
    } else if (igc_continuo < 3.945) {
        igc_faixa = 4;
    } else {
        igc_faixa = 5;
    }

    printf("  IGC Contínuo: %.3f\n", igc_continuo);
    printf("  IGC Faixa: %d\n", igc_faixa);
    printf("  Classificação IGC: %s\n", classificar_cpc(igc_faixa));
}