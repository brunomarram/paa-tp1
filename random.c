#include "random.h"

void inicializaSrand() {
    srand((unsigned)time(NULL) );
}

int geraRandom(int limite){
    int numero = ( rand() % (limite));
    return (numero == 0) ? 1 : numero;
}
