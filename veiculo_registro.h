#ifndef VEICULO_REGISTRO_H
#define VEICULO_REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _veiculo_registro  VEICULO_REGISTRO;

int insereRegistroVeiculo(FILE *arquivoBin, VEICULO_REGISTRO *registro);
int readRegistroVeiculo(FILE *arquivoBin, VEICULO_REGISTRO *registro);
int mostrarRegistroVeiculo(FILE *arquivoBin, VEICULO_REGISTRO *registro);
int	imprimeRegistrosVeiculo(FILE *arquivoBin);
int buscaParametroVeiculo(FILE *arquivoBin);
int insereNRegistrosVeiculo(FILE *arquivoBin, int numeroNovosRegistros);

#endif
