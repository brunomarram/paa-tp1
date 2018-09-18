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

#include <stdio.h>
#include <stdlib.h>
#include "Ordenacao.h"
#include "Random.h"
#include "Soma.h"

void resetVetor(int *vetor){
    //gerar números aleatórios entre 0 e 100
    for(int i=0;i<N;i++)
        vetor[i] = randomGenerate(0, 100);
}

void imprimeVetor(int *vetor){
    for(int i=0;i<N;i++)
        printf("%d\n", vetor[i]);
}

int main(int argc, char** argv) {
    int vetor[N], numero = 199;
    randomSeed();

    while(1){
        resetVetor(vetor);
        printf("Digite um numero para checar se existe soma valida: ");
        scanf("%d", &numero);
        metodo1(vetor, numero);
        metodo2(vetor, numero);
    }

    return 0;
}
