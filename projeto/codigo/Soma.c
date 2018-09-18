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

void metodo2(int *vetor, int numero){

    int indiceI = 0, indiceF = N, media;
    int indTermo1 = -1, indTermo2 = -1;

    while(indiceI != indiceF) {

        media = (indiceI+indiceF)/2;
        //printf("%d\n", media);
        if(media==0 || media==N-1)
            break;

        imprimeVetor(vetor, indiceI, indiceF);
        if(numero < (vetor[media-1]+vetor[media])) {
            indiceF = media;
            if(verificaSoma(vetor, indiceI, indiceF, &indTermo1, &indTermo2, numero)) {
                //printf("%d + %d = %d\n", vetor[indTermo1], vetor[indTermo2], numero);
                break;
            }
        }
        else if(numero > (vetor[media-1]+vetor[media])) {
            indiceI = media;
            if(verificaSoma(vetor, indiceI, indiceF, &indTermo1, &indTermo2, numero)) {
                //printf("%d + %d = %d\n", vetor[indTermo1], vetor[indTermo2], numero);
                break;
            }
        } else if (numero == (vetor[media-1]+vetor[media])){
            //printf(">> %d + %d = %d\n", vetor[media-1], vetor[media], numero);
            indTermo1 = media-1;
            indTermo2 = media;
            break;
        }
    }
    if(indTermo1 == -1 && indTermo2 == -1)
        printf("Soma não encontrada!\n");
    else
        printf(">> %d + %d = %d\n", vetor[indTermo1], vetor[indTermo2], numero);

}

int verificaSoma(int *vetor, int indiceI, int indiceF, int *indTermo1, int *indTermo2, int numero){
    int i, j;
    //imprimeVetor(vetor, indiceI, indiceF);
    if(indiceI==indiceF)
        return 0;

    for(i = indiceI; i<indiceF; i++){
        for(j=i+1; j<indiceF; j++){
            if((vetor[i]+vetor[j]) == numero) {
                *indTermo1 = i;
                *indTermo2 = j;
                break;
            }
        }
    }
    if(*indTermo1 != -1 && *indTermo2 != -1)
        return 1;
    else
        return 0;
}

void imprimeVetor(int *vetor, int indiceI, int indiceF){
    int i;
    for(i=indiceI; i< indiceF; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

int main() {

    int i;
    int vetor[N];
    for(i=0;i<N;i++)
        vetor[i] = i+1;

    metodo2(vetor, 3);

    return 0;
}
