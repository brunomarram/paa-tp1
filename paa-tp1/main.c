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

void resetVetor(int *vetor){
    //gerar números aleatórios entre 0 e 1000
    for(int i=0;i<N;i++)
        vetor[i] = i+1;    
}

void imprimeVetor(int *vetor){
    for(int i=0;i<N;i++)
        printf("%d\n", vetor[i]);
}

void verificaSoma(int *vetor, int numero){
    int fixI = -1, fixJ = -1;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(vetor[i] + vetor[j] == numero){
                fixI = i;
                fixJ = j;
                break;
            }
        }
        if(fixI != -1 || fixJ != -1)
            break;
    }
    
    if(fixI != -1 || fixJ != -1)
        printf("%d + %d = %d\n", vetor[fixI], vetor[fixJ], numero);
    else
        printf("Nao foi encontrado um somatorio que de o numero solicitado\n");
}

/*
 * 
 */
int main(int argc, char** argv) {
    int vetor[N], numero = 199;
    
    while(1){
        resetVetor(vetor);
        //Chamar a ordenação para o vetor
        bubbleSort(vetor);
        
        printf("Digite um numero para checar se existe soma valida: ");
        scanf("%d", &numero);
        verificaSoma(vetor, numero);
    }

    return 0;
}

