#include "btree_algoritimos.h"


#define grau 5 
//possivel struct para retorno de busca


// struct searchResponse
// {
//     int rnnPag; //rnn no arquivo da btree
//     int byteoffsetChave;
//     int indexChave; //index da chave no registro
//     int indexSubtree; 
// };

//por enquanto retorna o rnn do registro que a chave foi encontrada
int search(FILE* arquivoBtree,int chave,int rnnPag,int* achouFlag){
    if (rnnPag == -2)
    {
        //condicao de entrada
        BTREE_CABECALHO cabecalho;
        readBtreeCabecalho(arquivoBtree,&cabecalho);
        search(arquivoBtree,chave,cabecalho.noRaiz,achouFlag); //chama a func para o no raiz
    }else{
        BTREE_REGISTRO* reg = criaRegistroBtree(grau);
        readRegistroBtree(reg,arquivoBtree,rnnPag);
        int resultadoBusca = searchChaveRegistroBtree(reg,chave,achouFlag);
        freeRegistroBtree(reg);
        if(*achouFlag == 1){
            return resultadoBusca; // se achou, retorna o byteoffset do registro no arquivo de dados
        }else if(*achouFlag == -1 && resultadoBusca == -1){
            return rnnPag; // se não achou e terminou a busca, retorna o rnn da pag atual 
        }
        else
        {
            search(arquivoBtree,chave,resultadoBusca,achouFlag); //caso a busca ainda não tenha terminado e não achou, vai para o prox ponteiro
        }
        
    }
    
}


/*
    descricao:
    
    argumentos:
    
    retono:
    -3: chave encontrada
    1: chave inserida
    2: promocao de
*/


int insert(FILE* arquivoBtree,int chave,llint ponteiroArquivoDados,int rnnPagAtual,int* achouFlag,int *rnnFilhoDireitoPromovida, int *chavePromovida,llint *ponteiroArqDadosPromovida){
    int valorRetorno = -1;


    if (rnnPagAtual == -1)
    {
        *chavePromovida = chave;
        *ponteiroArqDadosPromovida = ponteiroArquivoDados;
        *rnnFilhoDireitoPromovida = -1;
        return 2;
    }else
    {
        BTREE_REGISTRO* reg = criaRegistroBtree(grau);
        readRegistroBtree(reg,arquivoBtree,rnnPagAtual);
        int resultadoBusca = searchChaveRegistroBtree(reg,chave,achouFlag);    
        
        

        if(*achouFlag == 1){
            // printf("chave encontrada!!!!\n");
            return -3; //chave encontrada
        }
        
        valorRetorno = insert(arquivoBtree,chave,ponteiroArquivoDados,resultadoBusca,achouFlag,rnnFilhoDireitoPromovida,chavePromovida,ponteiroArqDadosPromovida); //caso a busca ainda não tenha terminado e não achou, vai para o prox ponteiro
        
        if (valorRetorno == 1 || valorRetorno == -3)
        {
            return valorRetorno;
        }else
        {
            int insert = -1;
            insert = insertChaveRegistroEPonteiroArquivoBtreeEFilhoDireito(reg,*chavePromovida,*rnnFilhoDireitoPromovida,*ponteiroArqDadosPromovida);
        
            if (insert == 1) //achou espaco no registro e colocou a chave
            {
                TESTEescreveRegistroBtree(reg,arquivoBtree,rnnPagAtual);
                freeRegistroBtree(reg);
                valorRetorno = 1;
                return 1;
            }else{
                BTREE_REGISTRO* novoRegistro = criaRegistroBtree(grau);

                split(*chavePromovida,*rnnFilhoDireitoPromovida,*ponteiroArqDadosPromovida, reg,chavePromovida,rnnFilhoDireitoPromovida,ponteiroArqDadosPromovida,novoRegistro);
                BTREE_CABECALHO cabecalho;
                readBtreeCabecalho(arquivoBtree,&cabecalho);

                TESTEescreveRegistroBtree(reg,arquivoBtree,rnnPagAtual);

                setRNNdoNoBtree(novoRegistro,cabecalho.RNNProx);
                mudaFolhaBtree(novoRegistro,returnFolha(reg));
                TESTEescreveRegistroBtree(novoRegistro,arquivoBtree,cabecalho.RNNProx);
                
                *rnnFilhoDireitoPromovida = cabecalho.RNNProx;
                
                cabecalho.RNNProx++;
                insereBtreeCabecalho(arquivoBtree,&cabecalho);
                fflush(arquivoBtree);

                freeRegistroBtree(reg);
                free(novoRegistro);
                return 2;
            }
        }
        freeRegistroBtree(reg);
    }     
    
    
}


int split(int chave, int filhoDireitoChaveInserida,llint ponteiroArquivoDeDadosChaveInserida, BTREE_REGISTRO* registroAtual,int *chavePromovida,int *filhoDireitoChavePromovida,llint *ponteiroArquivoDeDadosChavePromovida,BTREE_REGISTRO* novoRegistro){


    BTREE_REGISTRO* registroTrabalho = criaRegistroBtree(grau+1);
    setnroChavesBtree(registroTrabalho,grau-1); // o registro trabalho copia um registro chei pra dentro de si, logo ele tem grau-1 chaves

    copyKeysAndPointersFromIndex(registroAtual,registroTrabalho,0,grau-1);
    
    // printf("copia no regtrabalho:\n");
    // TESTEprintRegistroBtree(registroTrabalho);
    insertChaveRegistroEPonteiroArquivoBtreeEFilhoDireito(registroTrabalho,chave,filhoDireitoChaveInserida,ponteiroArquivoDeDadosChaveInserida);
    // printf("inserida a chave no regtrabalho:\n");
    // TESTEprintRegistroBtree(registroTrabalho);


    


    setPonteiroSubArvoreBtree(novoRegistro,0,returnBtreeChildPointerAtIndex(registroTrabalho,3));
    for (int i = 3; i < grau; i++)
    {
        insertChaveRegistroEPonteiroArquivoBtreeEFilhoDireito(novoRegistro,returnKeyAtIndex(registroTrabalho,i),returnBtreeChildPointerAtIndex(registroTrabalho,i+1),returnDataPointerAtIndex(registroTrabalho,i));
    }

    // printf("\nNOVO REGISTRO:\n");
    // TESTEprintRegistroBtree(novoRegistro);
    
    deleteKeysFromIndex(registroAtual,0);
    deleteBtreePointersFromIndex(registroAtual,0);
     for (int i = 0; i < grau/2; i++)
    {
        insertChaveRegistroEPonteiroArquivoBtreeEFilhoDireito(registroAtual,returnKeyAtIndex(registroTrabalho,i),returnBtreeChildPointerAtIndex(registroTrabalho,i+1),returnDataPointerAtIndex(registroTrabalho,i));
    }


    // printf("\nNOVO ATUAL:\n");
    // TESTEprintRegistroBtree(registroAtual);
    
    *chavePromovida = returnKeyAtIndex(registroTrabalho,2);
    *ponteiroArquivoDeDadosChavePromovida = returnDataPointerAtIndex(registroTrabalho,2);
    
    freeRegistroBtree(registroTrabalho);
}

int driver_insert(FILE* arquivoIndiceFP, int chave,llint ponteiro ){
    
    
    
    
    
    
    //condicao de entrada
    BTREE_CABECALHO cabecalho;
    readBtreeCabecalho(arquivoIndiceFP,&cabecalho);

    int achouFlag = -1;
    int chavePromovida = -1;
    int rnnFilhoDireitoChavePromovida = -1;
    llint ponteiroChvePromovida = -1;

    int promo = -1;
    promo = insert(arquivoIndiceFP,chave,ponteiro,cabecalho.noRaiz,&achouFlag,&rnnFilhoDireitoChavePromovida,&chavePromovida,&ponteiroChvePromovida); //chama a func para o no raiz


    if (promo == 2)
    {
        BTREE_REGISTRO* raizNova = criaRegistroBtree(grau);
        readBtreeCabecalho(arquivoIndiceFP,&cabecalho);
        setPonteiroSubArvoreBtree(raizNova,0,cabecalho.noRaiz);
        cabecalho.noRaiz = cabecalho.RNNProx;
        cabecalho.RNNProx++;
        setRNNdoNoBtree(raizNova,cabecalho.noRaiz);
        insertChaveRegistroEPonteiroArquivoBtreeEFilhoDireito(raizNova,chavePromovida,rnnFilhoDireitoChavePromovida,ponteiroChvePromovida);

        TESTEescreveRegistroBtree(raizNova,arquivoIndiceFP,cabecalho.noRaiz);
        insereBtreeCabecalho(arquivoIndiceFP,&cabecalho);
        fflush(arquivoIndiceFP);
    }
}
