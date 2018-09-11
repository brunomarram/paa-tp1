/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Ordenacao.h"

void bubbleSort(int *vetor){
    int temp;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(vetor[i] < vetor[j]){
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;                
            }
        }
    }
}