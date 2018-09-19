#include "arquivo.h"

int inicializaArquivo(char *nomeArquivo)
{
    FILE *arquivo = NULL; // Arquivo TXT lido
    arquivo = fopen(nomeArquivo, "a");

    time_t tempo = time(NULL);

    fprintf(arquivo, "\n\n***************************\n");
    fprintf(arquivo, "Nova execucao - %s", ctime(&tempo));
    fprintf(arquivo, "***************************\n");
    fclose(arquivo);
    return 1;
}

int registraArquivo(char *nomeArquivo, int *vetor, int tam)
{
    FILE *arquivo = NULL; // Arquivo TXT lido
    arquivo = fopen(nomeArquivo, "a");

    fprintf(arquivo, "\n-------------------------------\n");
    for (int i = 0; i < tam; i++)
        fprintf(arquivo, "%d ", vetor[i]);
    fclose(arquivo);
    printf("Arquivo de log salvo com sucesso em %s!\n", nomeArquivo);
    return 1;
}

int registraTempo(char *nomeArquivo, double tempo, char *texto, int numero)
{
    FILE *arquivo = NULL; // Arquivo TXT lido
    arquivo = fopen(nomeArquivo, "a");
    if (numero == -1)
        fprintf(arquivo, "\n%s: %lf", texto, tempo);
    else
        fprintf(arquivo, "\n%d - %s: %lf", numero, texto, tempo);
    fclose(arquivo);
    return 1;
}
