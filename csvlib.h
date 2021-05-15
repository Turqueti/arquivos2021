#ifndef CSVLIB_H
#define CSVLIB_H
#include <stdio.h>

FILE* open_csv(char* fileName);
void close_csv(FILE* filePointer);
char*** csvToMatrix(FILE* filePointer);
int numLinhas(FILE* filePointer);
int numCampos(FILE* filePointer);

#endif
