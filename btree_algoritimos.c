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


int insert(FILE* arquivoBtree,int chave,int rnnPag,int* achouFlag,int rnnFilhoDireitoPromovida, int chavePromovida){
    int valorRetorno = -1;
    
    if (rnnPag == -2)
    {
        //condicao de entrada
        BTREE_CABECALHO cabecalho;
        readBtreeCabecalho(arquivoBtree,&cabecalho);
        insert(arquivoBtree,chave,cabecalho.noRaiz,achouFlag,rnnFilhoDireitoPromovida,chavePromovida); //chama a func para o no raiz
    }else{
        
        BTREE_REGISTRO* reg = criaRegistroBtree();
        readRegistroBtree(reg,arquivoBtree,rnnPag);
        int resultadoBusca = searchChaveRegistroBtree(reg,chave,achouFlag);
        freeRegistroBtree(reg);
        
        
        if(*achouFlag == 1){
            printf("chave encontrada!!!!\n");
            valorRetorno = -3;
            return -3; //chave encontrada
        }else if(*achouFlag == -1 && resultadoBusca == -1){
            // se não achou e terminou a busca, insere a chave

            BTREE_REGISTRO* registroInsert = criaRegistroBtree();
            readRegistroBtree(registroInsert,arquivoBtree,rnnPag);
            int insert = -1;
            insert = insertChaveRegistroBtree(registroInsert,chave);
            if (insert == 1) // se houver espaço insere e retorna 1
            {
                TESTEescreveRegistroBtree(registroInsert,arquivoBtree,rnnPag);
                freeRegistroBtree(registroInsert);
                valorRetorno = 1;
                return 1;
            }else
            {
                //split
            }
 
        }
        else
        {
            valorRetorno = insert(arquivoBtree,chave,resultadoBusca,achouFlag,rnnFilhoDireitoPromovida,chavePromovida); //caso a busca ainda não tenha terminado e não achou, vai para o prox ponteiro
        }
        
    }
    
}


int split(int posicaoInsercao,int chave, int filhoDireitoChaveInserida, BTREE_REGISTRO* registroAtual,int chavePromovida,int filhoDireitoChavePromovida,BTREE_REGISTRO* novaPagina){


    BTREE_REGISTRO* registroAux = criaRegistroBtree();
    
    if (posicaoInsercao == 2) //se a chave fosse ser inserida no meio do registro ela eh a chave promovida
    {
        chavePromovida = chave;
        filhoDireitoChavePromovida = filhoDireitoChaveInserida;
    }else if (posicaoInsercao > 2) // se a chave fosse ser inserida em uma posicao maior que 2 a chave promovida é a que esta na posicao 2 do registro
    {
        chavePromovida = returnKeyAtIndex(registroAtual,2);
        filhoDireitoChavePromovida = returnBtreeChildPointerAtIndex(registroAtual,3);
    }else // se a chave fosse ser inserida nas posicoes antes de 2 a chave promovida eh a chave na posicao 1 do refistro
    {
        chavePromovida = returnKeyAtIndex(registroAtual,1);
        filhoDireitoChavePromovida = returnBtreeChildPointerAtIndex(registroAtual,2);
    }





}

int btree_insert(FILE* arquivoBtree,int chave){
    int achouFlag = -1;

    int rnn = search(arquivoBtree,chave,-2,&achouFlag);

    if (achouFlag == 1)
    {
        printf("chave encontrada!!!!\n");
        return -3; //chave encontrada
    }else
    {
        BTREE_REGISTRO* reg = criaRegistroBtree();
        readRegistroBtree(reg,arquivoBtree,rnn);
        int insert = -1;
        insert = insertChaveRegistroBtree(reg,chave);
        if (insert == 1)
        {
            TESTEescreveRegistroBtree(reg,arquivoBtree,rnn);
            return 1;
        }else
        {
            
            insert = insert * -1;
            printf("insert: %d\n",insert);
            //encontra a melhor chave
            if (insert == 2) //se a chave fosse ser inserida no meio do registro ela é a melhor chave
            {
                /* code */
            }else if (insert > 2) // se a chave fosse ser inserida na posicao 3 a melhor chave eh a de posicao 2 atualmente obs: precisa de testes
            {
                
            }else // se a chave fosse ser inserida nas posicoes antes de 2 amelhor chave eh a chave 1
            {
                /* code */
            }
            
            //split
            BTREE_REGISTRO* regDireita = criaRegistroBtree();






            freeRegistroBtree(regDireita);
        }
        
        
        
        
        freeRegistroBtree(reg);
    }
    
    



}