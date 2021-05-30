#ifndef VEICULO_CABECALHO_H
#define VEICULO_CABECALHO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _veiculo_cabecalho {
    char status;
    long long int byteProxReg;
    int nroRegistros;
    int nroRegRemovidos;
    char descrevePrefixo[18];
    char descreveData[35];
    char descreveLugares[42];
    char descreveLinha[26];
    char descreveModelo[17];
    char descreveCategoria[20];
} VEICULO_CABECALHO;


VEICULO_CABECALHO createVeiculoCabecalho();
int insereVeiculoCabecalho(FILE *arquivoBin, VEICULO_CABECALHO *cabecalho);
int readVeiculoCabecalho(FILE *arquivoBin, VEICULO_CABECALHO *cabecalho);
int mostrarCabecalhoVeiculo(FILE *arquivoBin, VEICULO_CABECALHO *cabecalho);
int mudaStatusCabecalhoVeiculo(FILE *arquivoBin, char status);
int setByteOffsetVeiculo(FILE *arquivoBin, long long int byteOffset);
int setNRegistrosVeiculo(FILE *arquivoBin, int nRegistros);
int setNRemovidosVeiculo(FILE *arquivoBin, int nRemovidos);
int criaBinarioVeiculo(char nomeArquivoCSV[30], char nomeArquivoBIN[30]);

#endif
