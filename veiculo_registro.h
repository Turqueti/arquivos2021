#ifndef VEICULO_REGISTRO_H
#define VEICULO_REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _veiculo_registro  VEICULO_REGISTRO;

int createRegistroVeiculo(FILE *arquivoBin, VEICULO_REGISTRO *registro);
int readRegistroVeiculo(FILE *arquivoBin, VEICULO_REGISTRO *registro);
int mostrarRegistroVeiculo(FILE *arquivoBin, VEICULO_REGISTRO *registro);
int teste(char nomeArquivoCSV[30], char nomeArquivoBIN[30]);

#endif
