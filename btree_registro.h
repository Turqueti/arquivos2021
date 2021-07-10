#ifndef BTREE_REGISTRO_H
#define BTREE_REGISTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define llint long long int

typedef struct _btree_registro  BTREE_REGISTRO;

BTREE_REGISTRO* criaRegistroBtree(int grau);
int mudaFolhaBtree(BTREE_REGISTRO* reg,char folha);
int setChaveBtree(BTREE_REGISTRO* reg,int indexChave, int valorChave);
int setPonteiroSubArvoreBtree(BTREE_REGISTRO* reg,int indexPonteiroSubArvore, int valorPonteiroSubArvore);
int setPonteiroRegistroBtree(BTREE_REGISTRO* reg,int indexPonteiroRegistro, llint valorPonteiroRegistro);
int setRNNdoNoBtree(BTREE_REGISTRO* reg, int valorRNNdoNo);
int setnroChavesBtree(BTREE_REGISTRO* reg, int valornroChaves);
void freeRegistroBtree(BTREE_REGISTRO* reg);
int readRegistroBtree(BTREE_REGISTRO* reg,FILE* arquivoBtree,int rnn);
int insertChaveRegistroBtree(BTREE_REGISTRO* reg,int chave);
void shiftRightVetPonteirosSubTree(BTREE_REGISTRO* reg,int indexStart);
void shiftRightVetPonteirosRegistros(BTREE_REGISTRO* reg,int indexStart);
void shiftRightVetChaves(BTREE_REGISTRO* reg,int indexStart);
int searchChaveRegistroBtree(BTREE_REGISTRO* reg, int chave, int* achouFlag);
void TESTEescreveRegistroBtree(BTREE_REGISTRO* reg,FILE* arquivoBtree, int rnn);
void TESTEprintRegistroBtree(BTREE_REGISTRO* reg);
void copyKeysAndPointersFromIndex(BTREE_REGISTRO* src, BTREE_REGISTRO* dest,int index);
void copyKeysAndPointersUntilIndex(BTREE_REGISTRO* src, BTREE_REGISTRO* dest,int index);
int returnKeyAtIndex(BTREE_REGISTRO* reg, int index);
int returnBtreeChildPointerAtIndex(BTREE_REGISTRO* reg, int index);
int insertChaveEFilhoDireitoRegistroBtree(BTREE_REGISTRO* reg,int chave,int rnnFilhoDireito);

#endif
