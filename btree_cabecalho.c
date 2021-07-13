#include "btree_cabecalho.h"


/*
    Descricao:
    	essa func cria um cabecalho do arquivo Btree

    Retorno:
    	Um cabecalho prenchido com dados falsos que devem ser alterados
*/
BTREE_CABECALHO createBtreeCabecalho() {
	BTREE_CABECALHO cabecalho;

	cabecalho.status = '0';
	cabecalho.noRaiz = 0;
	cabecalho.RNNProx = 0;

	return cabecalho;
}

/*
    Descricao:
    	Lê o cabeçalho
    
    Argumentos:
	    [in]arquivoBin: arquivo binário que foi criado
	    		OBS: Não realiza fopen, nem fclose, nem muda o status
		[in]cabecalho: struct de cabecalho que foi criado e preenchido

    Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
    	após a leitura ele retorna o que foi lido pelo 'cabecalho'
*/
int readBtreeCabecalho(FILE *arquivoBin, BTREE_CABECALHO *cabecalho) {
	if (arquivoBin == NULL) return 0;

	fseek(arquivoBin, 0, SEEK_SET);
	fread(&cabecalho->status, sizeof(char), 1, arquivoBin);
	fread(&cabecalho->noRaiz, sizeof(int), 1, arquivoBin);
	fread(&cabecalho->RNNProx, sizeof(int), 1, arquivoBin);
	
	return 1;
}

/*
    Descricao:
    	Muda o status do cabeçalho
    
    Argumentos:
	    [in]arquivoBin: arquivo binário que foi criado
	    		OBS: Não realiza fopen, nem fclose
		[in]status: o status que será passado ao cabeçalho

    Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
*/
int mudaStatusCabecalhoBtree(FILE *arquivoBin, char status) {
	if (arquivoBin == NULL) return 0;

	fseek(arquivoBin, 0, SEEK_SET);
	fwrite(&status, sizeof(char), 1, arquivoBin);

	fseek(arquivoBin, 0, SEEK_SET);
	return 1;
}

/*
    Descricao:
    	essa func insere um cabecalho do arquivo Btree
    
    Argumentos:
	    [in]arquivoBin: arquivo binário que foi criado
	    		OBS: Não realiza fopen nem fclose
		[in]cabecalho: struct de cabecalho que foi criado e preenchido

    Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
*/
int insereBtreeCabecalho(FILE *arquivoBin, BTREE_CABECALHO *cabecalho) {
	if (arquivoBin == NULL) return 0;

	fseek(arquivoBin, 0, SEEK_SET);
	fwrite(&cabecalho->status, sizeof(char), 1, arquivoBin);
	fwrite(&cabecalho->noRaiz, sizeof(int), 1, arquivoBin);
    fwrite(&cabecalho->RNNProx, sizeof(int), 1, arquivoBin);
    
	return 1;
}


int escreveLixo(FILE *arquivoBin, int qtd,int byteOffSet){
    if (arquivoBin == NULL) return 0;

    char lixo = '@';

	fseek(arquivoBin, byteOffSet, SEEK_SET);
    for (int i = 0; i < qtd; i++)
    {
        fwrite(&lixo,1,1,arquivoBin);
    }
    
    
    return 1;

}