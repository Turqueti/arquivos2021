#ifndef LINHA_CABECALHO_H
#define LINHA_CABECALHO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _linha_cabecalho LINHA_CABECALHO;

int create_linha_cabecalho(FILE *arquivoBin, LINHA_CABECALHO *cabecalho);

int read_linha_cabecalho(FILE *arquivoBin, LINHA_CABECALHO *cabecalho);

int delete_linha_cabecalho();

int mudaStatus(FILE *arquivoBin, char status);

int setByteOffset(FILE *arquivoBin, long long int byteOffset);

int setNRegistros(FILE *arquivoBin, int nRegistros);

int setNRemovidos(FILE *arquivoBin, int nRemovidos);

int criaBinarioLinha(char nomeArquivoCSV[30], char nomeArquivoBIN[30]);

#endif
