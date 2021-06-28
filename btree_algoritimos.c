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
int search(FILE* arquivoBtree,int chave,int rnnPag){
    if (rnnPag == -2)
    {
        //condicao de entrada
        BTREE_CABECALHO cabecalho;
        readBtreeCabecalho(arquivoBtree,&cabecalho);
        search(arquivoBtree,chave,cabecalho.noRaiz); //chama a func para o no raiz
    }else if (rnnPag == -1)
    {
        return -1; // nao encontrou
    }else{
        BTREE_REGISTRO* reg = criaRegistroBtree();
        readRegistroBtree(reg,arquivoBtree,rnnPag);
        int resultadoBusca = searchChaveRegistroBtree(reg,chave);
        freeRegistroBtree(reg);
        if(resultadoBusca == -3){
            return rnnPag;
        }else
        {
            search(arquivoBtree,chave,resultadoBusca);
        }
        
    }
    
}