#ifndef BTREE_CABECALHO_H
#define BTREE_CABECALHO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _btree_cabecalho {
    char status;
    int noRaiz;
    int RNNProx;
} BTREE_CABECALHO;


BTREE_CABECALHO createBtreeCabecalho();
int readBtreeCabecalho(FILE *arquivoBin, BTREE_CABECALHO *cabecalho);
int mudaStatusCabecalhoBtree(FILE *arquivoBin, char status);
int insereBtreeCabecalho(FILE *arquivoBin, BTREE_CABECALHO *cabecalho);
int escreveLixo(FILE *arquivoBin, int qtd,int byteOffSet);

#endif
