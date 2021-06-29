#include "btree_registro.h"

#define grau 5 


struct _btree_registro {
    char folha;
    int nroChaves;
    int RNNdoNO;
    int ponteirosSubArvores[grau];
    int chaves[grau-1];
    llint ponteirosRegistros[grau-1];
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
    reg->ponteirosSubArvores[grau-1] = -1;
    return reg;
}

int mudaFolhaBtree(BTREE_REGISTRO* reg,char folha){
    reg->folha = folha;
    return 1;
}

int setChaveBtree(BTREE_REGISTRO* reg,int indexChave, int valorChave){
    reg->chaves[indexChave] = valorChave;
    return 1;
}

int setPonteiroSubArvoreBtree(BTREE_REGISTRO* reg,int indexPonteiroSubArvore, int valorPonteiroSubArvore){
    reg->ponteirosSubArvores[indexPonteiroSubArvore] = valorPonteiroSubArvore;
    return 1;
}

int setPonteiroRegistroBtree(BTREE_REGISTRO* reg,int indexPonteiroRegistro, llint valorPonteiroRegistro){
    reg->ponteirosRegistros[indexPonteiroRegistro] = valorPonteiroRegistro;
    return 1;
}

int setRNNdoNoBtree(BTREE_REGISTRO* reg, int valorRNNdoNo){
    reg->RNNdoNO = valorRNNdoNo;
    return 1;
}

int setnroChavesBtree(BTREE_REGISTRO* reg, int valornroChaves){
    reg->nroChaves = valornroChaves;
    return 1;
}

void freeRegistroBtree(BTREE_REGISTRO* reg){
    if (reg)
    {
        free(reg);
    }
    
}

int readRegistroBtree(BTREE_REGISTRO* reg,FILE* arquivoBtree,int rnn){

    if (arquivoBtree)
    {
        if (rnn == 0)
        {
            fseek(arquivoBtree,77,SEEK_SET);
        }else
        {
            fseek(arquivoBtree,(rnn+1)*77,SEEK_SET);
        }
        
        

        
        fread(&reg->folha,1,1,arquivoBtree);
        fread(&reg->nroChaves,1,4,arquivoBtree);
        fread(&reg->RNNdoNO,1,4,arquivoBtree);

        fread(&reg->ponteirosSubArvores[0],1,4,arquivoBtree);
        fread(&reg->chaves[0],1,4,arquivoBtree);
        fread(&reg->ponteirosRegistros[0],1,8,arquivoBtree);

        fread(&reg->ponteirosSubArvores[1],1,4,arquivoBtree);
        fread(&reg->chaves[1],1,4,arquivoBtree);
        fread(&reg->ponteirosRegistros[1],1,8,arquivoBtree);

        fread(&reg->ponteirosSubArvores[2],1,4,arquivoBtree);
        fread(&reg->chaves[2],1,4,arquivoBtree);
        fread(&reg->ponteirosRegistros[2],1,8,arquivoBtree);

        fread(&reg->ponteirosSubArvores[3],1,4,arquivoBtree);
        fread(&reg->chaves[3],1,4,arquivoBtree);
        fread(&reg->ponteirosRegistros[3],1,8,arquivoBtree);

        fread(&reg->ponteirosSubArvores[4],1,4,arquivoBtree);

    }
    


}

int insertChaveRegistroBtree(int RNNAtual,int chave,int RNNFilhoDireitoPromo, int chavePromovida){

}

int searchChaveRegistroBtree(BTREE_REGISTRO* reg, int chave, int* achouFlag){
    
    int i;
    for (i = 0; i < reg->nroChaves; i++)
    {
        if (reg->chaves[i] == chave)
        {
            *achouFlag = 1;
            return reg->ponteirosRegistros[i];
        }else if (reg->chaves[i] > chave || reg->chaves[i] == -1)
        {
            return reg->ponteirosSubArvores[i];
        }
        
    }

        return reg->ponteirosSubArvores[i]; // todas as chaves no registro são menores que a chave buscada logo retorna o ultimo ponteiro de subarvore 
    
}

void TESTEescreveRegistroBtree(BTREE_REGISTRO* reg,FILE* arquivoBtree, int rnn){

    if (arquivoBtree)
    {
        fseek(arquivoBtree,rnn*77,SEEK_SET);
        fwrite(&reg->folha,1,1,arquivoBtree);
        fwrite(&reg->nroChaves,1,4,arquivoBtree);
        fwrite(&reg->RNNdoNO,1,4,arquivoBtree);

        fwrite(&reg->ponteirosSubArvores[0],1,4,arquivoBtree);
        fwrite(&reg->chaves[0],1,4,arquivoBtree);
        fwrite(&reg->ponteirosRegistros[0],1,8,arquivoBtree);

        fwrite(&reg->ponteirosSubArvores[1],1,4,arquivoBtree);
        fwrite(&reg->chaves[1],1,4,arquivoBtree);
        fwrite(&reg->ponteirosRegistros[1],1,8,arquivoBtree);

        fwrite(&reg->ponteirosSubArvores[2],1,4,arquivoBtree);
        fwrite(&reg->chaves[2],1,4,arquivoBtree);
        fwrite(&reg->ponteirosRegistros[2],1,8,arquivoBtree);

        fwrite(&reg->ponteirosSubArvores[3],1,4,arquivoBtree);
        fwrite(&reg->chaves[3],1,4,arquivoBtree);
        fwrite(&reg->ponteirosRegistros[3],1,8,arquivoBtree);

        fwrite(&reg->ponteirosSubArvores[4],1,4,arquivoBtree);

    }
    

}

void TESTEprintRegistroBtree(BTREE_REGISTRO* reg){
    printf("folha: %c\n",reg->folha);
    printf("rnn: %d\n",reg->RNNdoNO);
    printf("numero de chaves: %d\n",reg->nroChaves);

    // for (int i = 0; i < grau; i++)
    // {
    //     printf("subArvore[%d]: %d\n",i,reg->ponteirosSubArvores[i]);
    // }
    // printf("\n\n\n");
    for (int i = 0; i < grau-1; i++)
    {
        printf("chave[%d]: %d\n",i,reg->chaves[i]);
    }
    // printf("\n\n\n");
    // for (int i = 0; i < grau-1; i++)
    // {
    //     printf("ponteiroReg[%d]: %d\n",i,reg->ponteirosRegistros[i]);
    // }
    
}

