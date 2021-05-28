#ifndef CSVLIB_H
#define CSVLIB_H
#include <stdio.h>
#include <string.h>
#include "matrizlib.h"

FILE* open_csv(char* fileName);
void close_csv(FILE* filePointer);
MATRIZ* csvToMatrix(FILE* filePointer);
int numLinhas(FILE* filePointer);
int numCampos(FILE* filePointer);
char** picotadora(char* line,MATRIZ* matrix,int linha);

#endif
