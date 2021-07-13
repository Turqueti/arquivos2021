#ifndef BTREE_ALGORITIMOS_H
#define BTREE_ALGORITIMOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree_cabecalho.h"
#include "btree_registro.h"

int search(FILE* arquivoBtree,int chave,int rnnPag,int* achouFlag);
int insert(FILE* arquivoBtree,int chave,llint ponteiroArquivoDados,int rnnPagAtual,int* achouFlag,int *rnnFilhoDireitoPromovida, int *chavePromovida,llint *ponteiroArqDadosPromovida);
int split(int chave, int filhoDireitoChaveInserida,llint ponteiroArquivoDeDadosChaveInserida, BTREE_REGISTRO* registroAtual,int *chavePromovida,int *filhoDireitoChavePromovida,llint *ponteiroArquivoDeDadosChavePromovida,BTREE_REGISTRO* novoRegistro);
int driver_insert(FILE* arquivoIndiceFP, int chave,llint ponteiro );

#endif
