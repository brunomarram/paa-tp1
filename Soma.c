#include "Soma.h"

void metodo1(int *vetor, int numero){
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