#ifndef BTREE_ALGORITIMOS_H
#define BTREE_ALGORITIMOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree_cabecalho.h"
#include "btree_registro.h"

int search(FILE* arquivoBtree,int chave,int rnnPag,int* achouFlag);

#endif
