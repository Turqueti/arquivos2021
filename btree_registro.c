#include "btree_registro.h"

#define grau 5 

struct _btree_registro {
    char folha;
    int nroChaves;
    int RNNdoNO;
    int ponteirosSubArvores[grau];
    int chaves[grau-1];
    int ponteirosRegistros[grau-1];
};

BTREE_REGISTRO* criaRegistroBtree(){
    BTREE_REGISTRO* reg;
    reg = (BTREE_REGISTRO*)malloc(sizeof(BTREE_REGISTRO));
    reg->folha = '0';
    reg->nroChaves = 0;
    for (int i = 0; i < grau-1; i++)
    {
        reg->ponteirosSubArvores[i] = -1;
        reg->chaves[i] = -1;
        reg->ponteirosRegistros[i] = -1;
    }
    reg->ponteirosSubArvores[grau] = -1;
    return reg;
}

int mudaFolhaBtree(BTREE_REGISTRO* reg,char folha){
    reg->folha = folha;
    return 1;
}

int SetChaveBtree(BTREE_REGISTRO* reg,int indexChave, int valorChave){
    reg->chaves[indexChave] = valorChave;
    return 1;
}

int SetPonteiroSubArvoreBtree(BTREE_REGISTRO* reg,int indexPonteiroSubArvore, int valorPonteiroSubArvore){
    reg->ponteirosSubArvores[indexPonteiroSubArvore] = valorPonteiroSubArvore;
    return 1;
}

int SetPonteiroRegistroBtree(BTREE_REGISTRO* reg,int indexPonteiroRegistro, int valorPonteiroRegistro){
    reg->ponteirosRegistros[indexPonteiroRegistro] = valorPonteiroRegistro;
    return 1;
}

int SetRNNdoNoBtree(BTREE_REGISTRO* reg, int valorRNNdoNo){
    reg->RNNdoNO = valorRNNdoNo;
    return 1;
}

int SetnroChavesBtree(BTREE_REGISTRO* reg, int valornroChaves){
    reg->nroChaves = valornroChaves;
    return 1;
}

