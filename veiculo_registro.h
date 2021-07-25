#ifndef VEICULO_REGISTRO_H
#define VEICULO_REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrizlib.h"

struct _veiculo_registro {
    char removido;
    int tamanhoRegistro;
    char prefixo[5];
    char data[10];
    int quantidadeLugares;
    int codLinha;
    int tamanhoModelo;
    char *modelo;
    int tamanhoCategoria;
    char *categoria;
};
typedef struct _veiculo_registro  VEICULO_REGISTRO;

VEICULO_REGISTRO* criaRegistroVeiculo();
void freeRegistroVeiculo(VEICULO_REGISTRO* reg);
int insereRegistroVeiculo(FILE *arquivoBin, VEICULO_REGISTRO *registro);
int readRegistroVeiculo(FILE *arquivoBin, VEICULO_REGISTRO *registro);
void printData(char data[10]);
int mostrarRegistroVeiculo(FILE *arquivoBin, VEICULO_REGISTRO *registro);
int	imprimeRegistrosVeiculo(FILE *arquivoBin);
int buscaParametroVeiculo(FILE *arquivoBin);
int insereNRegistrosVeiculo(FILE *arquivoBin, int numeroNovosRegistros);
int insereNRegistrosVeiculoMatriz(FILE *arquivoBin, MATRIZ* matrix);
int readRegistroVeiculoByteOffSet(FILE *arquivoBin, VEICULO_REGISTRO *registro,int byteOffSet);
int registroVeiculoRemovido(VEICULO_REGISTRO *registro);
void retornaPrefixo(VEICULO_REGISTRO *registro,char* prefix);
int retornaTamanhoRegistroVeiculo(VEICULO_REGISTRO* reg);
VEICULO_REGISTRO* readRegistroVeiculoStdin();

#endif
