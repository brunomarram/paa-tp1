#ifndef arquivo_h
#define arquivo_h

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int inicializaArquivo(char *nomeArquivo);
int registraArquivo(char *fileName, int *vetor, int tam);
int registraTempo(char *nomeArquivo, double tempo, char *texto, int numero);

#endif /* arquivo_h */
