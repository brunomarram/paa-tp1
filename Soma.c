#include "soma.h"

void pesquisaSequencial(int *vetor, int numero, int tam)
{
    clock_t begin = clock();

    int fixI = -1, fixJ = -1;
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (vetor[i] + vetor[j] == numero)
            {
                fixI = i;
                fixJ = j;
                break;
            }
        }
        if (fixI != -1 && fixJ != -1)
            break;
    }

    if (fixI != -1 && fixJ != -1)
        printf("\n\n%d + %d = %d\n\n", vetor[fixI], vetor[fixJ], numero);
    else
        printf("\nNao foi encontrado um somatorio que de o numero solicitado\n");

    clock_t final = clock() - begin;
    double total = ((double)final) / CLOCKS_PER_SEC;
    printf("Tempo de pesquisa sequencial: %lf\n", total);
    registraTempo("log.txt", total, "Tempo de pesquisa sequencial", numero);
}

void buscaBinaria(int *vetor, int numero, int tam)
{
    clock_t begin = clock();

    int indiceI = 0, indiceF = tam, media;
    int indTermo1 = -1, indTermo2 = -1;

    while ((indiceF - indiceI) != 1)
    {
        //imprimeVetor(vetor, indiceI, indiceF);
        media = (indiceI + indiceF) / 2;
        if (numero < (vetor[media - 1] + vetor[media]))
            indiceF = media;
        else if (numero > (vetor[media - 1] + vetor[media]))
            indiceI = media;
        else if (numero == (vetor[media - 1] + vetor[media]))
        {
            indTermo1 = media - 1;
            indTermo2 = media;
            break;
        }
    }
    verificaSoma(vetor, indiceI, indiceF, &indTermo1, &indTermo2, numero);
    if (indTermo1 == -1 && indTermo2 == -1)
        printf("\nSoma não encontrada!\n");
    else
        printf("\n>> %d + %d = %d\n\n", vetor[indTermo1], vetor[indTermo2], numero);

    clock_t final = clock() - begin;
    double total = ((double)final) / CLOCKS_PER_SEC;
    printf("Tempo de busca binaria: %lf\n", total);
    registraTempo("log.txt", total, "Tempo de busca binaria", numero);
}

int verificaSoma(int *vetor, int indiceI, int indiceF, int *indTermo1, int *indTermo2, int numero)
{
    int i, j;
    //imprimeVetor(vetor, indiceI, indiceF);
    if (indiceI == indiceF)
        return 0;

    for (i = indiceI; i < indiceF; i++)
    {
        for (j = i + 1; j < indiceF; j++)
        {
            if ((vetor[i] + vetor[j]) == numero)
            {
                *indTermo1 = i;
                *indTermo2 = j;
                break;
            }
        }
    }
    if (*indTermo1 != -1 && *indTermo2 != -1)
        return 1;
    else
        return 0;
}

void imprimeVetor(int *vetor, int indiceI, int indiceF)
{
    int i;
    for (i = indiceI; i < indiceF; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}
