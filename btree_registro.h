#ifndef BTREE_REGISTRO_H
#define BTREE_REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _btree_registro  BTREE_REGISTRO;

BTREE_REGISTRO* criaRegistroBtree();
int mudaFolhaBtree(BTREE_REGISTRO* reg,char folha);
int SetChaveBtree(BTREE_REGISTRO* reg,int indexChave, int valorChave);
int SetPonteiroSubArvoreBtree(BTREE_REGISTRO* reg,int indexPonteiroSubArvore, int valorPonteiroSubArvore);
int SetPonteiroRegistroBtree(BTREE_REGISTRO* reg,int indexPonteiroRegistro, int valorPonteiroRegistro);
int SetRNNdoNoBtree(BTREE_REGISTRO* reg, int valorRNNdoNo);
int SetnroChavesBtree(BTREE_REGISTRO* reg, int valornroChaves);
void freeRegistroBtree(BTREE_REGISTRO* reg);
int readRegistroBtree(BTREE_REGISTRO* reg,FILE* arquivoBtree,int rnn);
int insertChaveRegistroBtree(int RNNAtual,int chave,int RNNFilhoDireitoPromo, int chavePromovida);
void TESTEescreveRegistroBtree(BTREE_REGISTRO* reg,FILE* arquivoBtree, int rnn);
void TESTEprintRegistroBtree(BTREE_REGISTRO* reg);

#endif
