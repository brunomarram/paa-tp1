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

// https://pt.wikipedia.org/wiki/Shell_sort
void shellSort(int *vet) {
    int i , j , valor;
    int intervalo = 1;
    while(intervalo < N) {
        intervalo = 3*intervalo+1;
    }
    while ( intervalo > 1) {
        intervalo /= 3;
        for(i = intervalo; i < N; i++) {
            valor = vet[i];
            j = i;
            while (j >= intervalo && valor < vet[j - intervalo]) {
                vet[j] = vet [j - intervalo];
                j = j - intervalo;
            }
            vet [j] = valor;
        }
    }
}

// https://pt.wikipedia.org/wiki/Heapsort
void heapSort(int *vetor) {
   int n = N;
   int i = n / 2, pai, filho, t;
   while(1) {
      if (i > 0) {
          i--;
          t = vetor[i];
      } else {
          n--;
          if (n == 0) return;
          t = vetor[n];
          vetor[n] = vetor[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (vetor[filho + 1] > vetor[filho]))
              filho++;
          if (vetor[filho] > t) {
             vetor[pai] = vetor[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      vetor[pai] = t;
   }
}
