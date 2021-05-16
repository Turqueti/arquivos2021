#ifndef LINHA_REGISTRO_H
#define LINHA_REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _linha_registro  LINHA_REGISTRO;

int insereRegistroLinha(FILE *arquivoBin, LINHA_REGISTRO *registro);
int readRegistroLinha(FILE *arquivoBin, LINHA_REGISTRO *registro);
int mostrarRegistroLinha(FILE *arquivoBin, LINHA_REGISTRO *registro);
int insereNRegistros(FILE *arquivoBin, int numeroNovosRegistros);

#endif
