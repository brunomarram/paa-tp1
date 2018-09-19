/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ordenacao.h"

void bubbleSort(int *vetor, int tam)
{
    clock_t begin = clock();

    int temp;
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (vetor[i] < vetor[j])
            {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    clock_t final = clock() - begin;
    double total = ((double)final) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao: %lf\n", total);
    registraTempo("log.txt", total, "Tempo de ordenacao usando BubbleSort", -1);
}

// https://pt.wikipedia.org/wiki/Heapsort
void heapSort(int *vetor, int tam)
{
    clock_t begin = clock();

    int n = tam;
    int i = n / 2, pai, filho, t;
    while (1)
    {
        if (i > 0)
        {
            i--;
            t = vetor[i];
        }
        else
        {
            n--;
            if (n == 0)
                break;
            t = vetor[n];
            vetor[n] = vetor[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n)
        {
            if ((filho + 1 < n) && (vetor[filho + 1] > vetor[filho]))
                filho++;
            if (vetor[filho] > t)
            {
                vetor[pai] = vetor[filho];
                pai = filho;
                filho = pai * 2 + 1;
            }
            else
            {
                break;
            }
        }
        vetor[pai] = t;
    }

    clock_t final = clock() - begin;
    double total = ((double)final) / CLOCKS_PER_SEC;
    printf("Tempo de ordenacao: %lf\n", total);
    registraTempo("log.txt", total, "Tempo de ordenacao usando HeapSort", -1);
}
