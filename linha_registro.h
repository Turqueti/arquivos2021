#ifndef LINHA_REGISTRO_H
#define LINHA_REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrizlib.h"

typedef struct _linha_registro  LINHA_REGISTRO;

int insereRegistroLinha(FILE *arquivoBin, LINHA_REGISTRO *registro);
int readRegistroLinha(FILE *arquivoBin, LINHA_REGISTRO *registro);
int mostrarRegistroLinha(FILE *arquivoBin, LINHA_REGISTRO *registro);
int insereNRegistrosLinha(FILE *arquivoBin, int numeroNovosRegistros);
int buscaParametroLinha(FILE *arquivoBin);
int	imprimeRegistrosLinha(FILE *arquivoBin);
int insereNRegistrosLinhaMatriz(FILE *arquivoBin,MATRIZ* matrix);

#endif
