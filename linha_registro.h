#ifndef LINHA_REGISTRO_H
#define LINHA_REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrizlib.h"

struct _linha_registro {
    char removido;//1
    int tamanhoRegistro;//4
    int codLinha;//4
    char aceitaCartao;//1
    int tamanhoNome;//4
    char *nomeLinha;
    int tamanhoCor;//4
    char *corLinha;
};

typedef struct _linha_registro  LINHA_REGISTRO;

LINHA_REGISTRO* criaRegistroLinha();
int insereRegistroLinha(FILE *arquivoBin, LINHA_REGISTRO *registro);
int readRegistroLinha(FILE *arquivoBin, LINHA_REGISTRO *registro);
int mostrarRegistroLinha(FILE *arquivoBin, LINHA_REGISTRO *registro);
int insereNRegistrosLinha(FILE *arquivoBin, int numeroNovosRegistros);
int buscaParametroLinha(FILE *arquivoBin);
int	imprimeRegistrosLinha(FILE *arquivoBin);
int insereNRegistrosLinhaMatriz(FILE *arquivoBin,MATRIZ* matrix);
int readRegistroLinhaByteOffSet(FILE *arquivoBin, LINHA_REGISTRO *registro,int byteOffSet);
LINHA_REGISTRO readRegistroLinhaStdin();

#endif
