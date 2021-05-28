#ifndef LINHA_CABECALHO_H
#define LINHA_CABECALHO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _linha_cabecalho {
    char status;
    long int byteProxReg;
    int nroRegistros;
    int nroRegRemovidos;
    char descreveCodigo[15];
    char descreveCartao[13];
    char descreveNome[13];
    char descreveCor[24];
} LINHA_CABECALHO;

LINHA_CABECALHO createLinhaCabecalho();
int insereLinhaCabecalho(FILE *arquivoBin, LINHA_CABECALHO *cabecalho);
int readLinhaCabecalho(FILE *arquivoBin, LINHA_CABECALHO *cabecalho);
int mostrarCabecalhoLinha(FILE *arquivoBin, LINHA_CABECALHO *cabecalho);
int mudaStatusCabecalhoLinha(FILE *arquivoBin, char status);
int setByteOffsetLinha(FILE *arquivoBin, long int byteOffset);
int setNRegistrosLinha(FILE *arquivoBin, int nRegistros);
int setNRemovidosLinha(FILE *arquivoBin, int nRemovidos);

#endif
