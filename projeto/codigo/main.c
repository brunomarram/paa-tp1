/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: Bruno Marra
 *
 * Created on 11 de Setembro de 2018, 10:26
 */

#include "Ordenacao.h"
#include "Random.h"
#include "Soma.h"

void resetVetor(int *vetor){
    //gerar números aleatórios entre 0 e 100
    for(int i=0;i<N;i++)
        vetor[i] = geraRandom(N);
}

void imprimeVetorMain(int *vetor){
    for(int i=0;i<N;i++)
        printf("%d ", vetor[i]);
}

int main(int argc, char** argv) {
    system("clear");
    int vetor[N], numero = 199;
    inicializaSrand();
    resetVetor(vetor);
    printf("Vetor gerado: \n");
    imprimeVetorMain(vetor);
    printf("\n");

    while(numero!=-1){
        resetVetor(vetor);
        printf("\nDigite um numero para checar se existe soma valida: ");
        scanf("%d", &numero);
        if(numero!=-1) {
            heapSort(vetor);
            printf("Vetor ordenado: \n");
            imprimeVetorMain(vetor);
            metodo1(vetor, numero);
            metodo2(vetor, numero);
    }
    }

    return 0;
}
