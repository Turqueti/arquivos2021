#ifndef MATRIZLIB_H
#define MATRIZLIB_H
#define MATRIZBUFFERLEN 1024

typedef struct _matriz MATRIZ;

MATRIZ* allocaMatriz(int numLinhas, int numColunas);
void freeMatriz(MATRIZ* matrix);
int inserePalavra(MATRIZ* matrix,int linha,int coluna,char palavra[MATRIZBUFFERLEN]);
int checkBoundaries(MATRIZ* matrix, int linha, int coluna);

#endif
