#ifndef BTREE_ALGORITIMOS_H
#define BTREE_ALGORITIMOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree_cabecalho.h"
#include "btree_registro.h"

int search(FILE* arquivoBtree,int chave,int rnnPag,int* achouFlag);
int insert(FILE* arquivoBtree,int chave,int rnnPagAtual,int* achouFlag,int *rnnFilhoDireitoPromovida, int *chavePromovida);
int split(int chave, int filhoDireitoChaveInserida, BTREE_REGISTRO* registroAtual,int *chavePromovida,int *filhoDireitoChavePromovida,BTREE_REGISTRO* novoRegistro);
int btree_insert(FILE* arquivoBtree,int chave);

#endif
