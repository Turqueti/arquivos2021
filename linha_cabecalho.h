#ifndef LINHA_CABECALHO_H
#define LINHA_CABECALHO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _linha_cabecalho  LINHA_CABECALHO;

int createLinhaCabecalho(FILE *arquivoBin, LINHA_CABECALHO *cabecalho);
int readLinhaCabecalho(FILE *arquivoBin, LINHA_CABECALHO *cabecalho);
int mostrarCabecalhoLinha(FILE *arquivoBin, LINHA_CABECALHO *cabecalho);
int mudaStatusCabecalhoLinha(FILE *arquivoBin, char status);
int setByteOffsetLinha(FILE *arquivoBin, long long int byteOffset);
int setNRegistrosLinha(FILE *arquivoBin, int nRegistros);
int setNRemovidosLinha(FILE *arquivoBin, int nRemovidos);
int criaBinarioLinha(char nomeArquivoCSV[30], char nomeArquivoBIN[30]);

#endif
