#include "btree_algoritimos.h"

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
    }else if (rnnPag == -1)
    {
        return -1; // nao encontrou
    }else{
        BTREE_REGISTRO* reg = criaRegistroBtree();
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