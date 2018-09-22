#include "soma.h"

void pesquisaSequencial(int *vetor, int numero, int tam, double *tempoMedio) {
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
        printf("Soma encontrada: %d + %d = %d\n", vetor[fixI], vetor[fixJ], numero);
    else
        printf("Não foi encontrado um somatório que dê o número solicitado\n");

    clock_t final = clock() - begin;
    double total = ((double)final) / CLOCKS_PER_SEC;
    *tempoMedio += total;
    // printf("Tempo de pesquisa sequencial: %lf\n", total);
    registraTempo("log.txt", total, "Tempo de pesquisa sequencial", numero);
}

void verificaSomaBinaria(int *vetor, int numero, int tam, double *tempoMedio){
    int i, indiceTermoEncontrado = -1;
    clock_t begin = clock();

    //imprimeVetor(vetor, 0, tam);
    for(i=0;i<tam; i++){
        indiceTermoEncontrado = buscaBinaria(vetor, numero-vetor[i], tam);
        if(indiceTermoEncontrado == i)
            indiceTermoEncontrado = -1;
        if(numero < vetor[i]+vetor[i+1])
            break;
        if(indiceTermoEncontrado!=-1) {
            printf("Soma encontrada: %d + %d = %d\n", vetor[i], vetor[indiceTermoEncontrado], numero);
            break;
        }
    }

    if (indiceTermoEncontrado == -1)
        printf("Não foi encontrado um somatório que dê o número solicitado\n");

    clock_t final = clock() - begin;
    double total = ((double)final) / CLOCKS_PER_SEC;
    *tempoMedio += total;
    // printf("Tempo de busca binaria: %lf\n", total);
    registraTempo("log.txt", total, "Tempo de busca binaria", numero);

}

int buscaBinaria(int *vetor, int numero, int tam) {
    int indiceI = 0, indiceF = tam, media;

    while ((indiceF - indiceI) != 1) {

        media = (indiceI + indiceF) / 2;

        if (numero < vetor[media])
            indiceF = media;
        else if (numero > vetor[media])
            indiceI = media;
        else if (numero == vetor[media])
            return media;

    }

    return -1;
}

void imprimeVetor(int *vetor, int indiceI, int indiceF) {
    int i;
    for (i = indiceI; i < indiceF; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}
