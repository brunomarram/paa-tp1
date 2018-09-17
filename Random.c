#include "Random.h"

void randomSeed(){
    // retirado de http://pubs.opengroup.org/onlinepubs/000095399/functions/gettimeofday.html
    struct timeval tv;
    gettimeofday(&tv, NULL);
    
    // pega o time atual em ms
    // desempenho melhor que o time() que atualiza em segs
    double milliseconds = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;    
    srand(milliseconds);
}

/**
 * Gera um número randômico dentro do intervalo passado como parâmetro
 * Baseado em:
 * https://stackoverflow.com/questions/361363/how-to-measure-time-in-milliseconds-using-ansi-c
 * http://linguagemc.com.br/valores-aleatorios-em-c-com-a-funcao-rand/
 */
int randomGenerate(int min, int limit){
    int number = rand() % (limit - 1) + min;
    if(number >= limit) number -= min;
    if(number < 0) number *= -1;
    return (number == 0) ? 1 : number;
}