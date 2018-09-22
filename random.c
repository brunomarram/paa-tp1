#include "random.h"

void inicializaSrand() {
    srand((unsigned)time(NULL) );
}

int geraRandom(int limite){
    return ((rand() % (limite)) + 1);
}
