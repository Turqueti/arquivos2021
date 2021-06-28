#ifndef BTREE_REGISTRO_H
#define BTREE_REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _btree_registro  BTREE_REGISTRO;

BTREE_REGISTRO* criaRegistroBtree();
int mudaFolhaBtree(BTREE_REGISTRO* reg,char folha);
int setChaveBtree(BTREE_REGISTRO* reg,int indexChave, int valorChave);
int setPonteiroSubArvoreBtree(BTREE_REGISTRO* reg,int indexPonteiroSubArvore, int valorPonteiroSubArvore);
int setPonteiroRegistroBtree(BTREE_REGISTRO* reg,int indexPonteiroRegistro, int valorPonteiroRegistro);
int setRNNdoNoBtree(BTREE_REGISTRO* reg, int valorRNNdoNo);
int setnroChavesBtree(BTREE_REGISTRO* reg, int valornroChaves);
void freeRegistroBtree(BTREE_REGISTRO* reg);
int readRegistroBtree(BTREE_REGISTRO* reg,FILE* arquivoBtree,int rnn);
int insertChaveRegistroBtree(int RNNAtual,int chave,int RNNFilhoDireitoPromo, int chavePromovida);
int searchChaveRegistroBtree(BTREE_REGISTRO* reg, int chave);
void TESTEescreveRegistroBtree(BTREE_REGISTRO* reg,FILE* arquivoBtree, int rnn);
void TESTEprintRegistroBtree(BTREE_REGISTRO* reg);

#endif
