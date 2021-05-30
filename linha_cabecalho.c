#include "linha_cabecalho.h"

/*
    Descricao:
    	essa func cria um cabecalho do arquivo linha

    Retorno:
    	Um cabecalho prenchido com dados falsos que devem ser alterados
*/
LINHA_CABECALHO createLinhaCabecalho() {
	LINHA_CABECALHO cabecalho;

	cabecalho.status = '0';
	cabecalho.byteProxReg = 0;
	cabecalho.nroRegistros = 0;
	cabecalho.nroRegRemovidos = 0;

	return cabecalho;
}

/*
    Descricao:
    	essa func insere um cabecalho do arquivo linha
    
    Argumentos:
	    [in]arquivoBin: arquivo binário que foi criado
	    		OBS: Não realiza fopen nem fclose
		[in]cabecalho: struct de cabecalho que foi criado e preenchido

    Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
*/
int insereLinhaCabecalho(FILE *arquivoBin, LINHA_CABECALHO *cabecalho) {
	if (arquivoBin == NULL) return 0;

	fseek(arquivoBin, 0, SEEK_SET);
	fwrite(&cabecalho->status, sizeof(char), 1, arquivoBin);
	fwrite(&cabecalho->byteProxReg, sizeof(long int), 1, arquivoBin);
	fwrite(&cabecalho->nroRegistros, sizeof(int), 1, arquivoBin);
	fwrite(&cabecalho->nroRegRemovidos, sizeof(int), 1, arquivoBin);
	fwrite(&cabecalho->descreveCodigo, sizeof(char), 15, arquivoBin);
	fwrite(&cabecalho->descreveCartao, sizeof(char), 13, arquivoBin);
	fwrite(&cabecalho->descreveNome, sizeof(char), 13, arquivoBin);
	fwrite(&cabecalho->descreveCor, sizeof(char), 24, arquivoBin);
	return 1;
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
int readLinhaCabecalho(FILE *arquivoBin, LINHA_CABECALHO *cabecalho) {
	if (arquivoBin == NULL) return 0;

	fseek(arquivoBin, 0, SEEK_SET);
	fread(&cabecalho->status, sizeof(char), 1, arquivoBin);
	fread(&cabecalho->byteProxReg, sizeof(long int), 1, arquivoBin);
	fread(&cabecalho->nroRegistros, sizeof(int), 1, arquivoBin);
	fread(&cabecalho->nroRegRemovidos, sizeof(int), 1, arquivoBin);
	fread(&cabecalho->descreveCodigo, sizeof(char), 15, arquivoBin);
	fread(&cabecalho->descreveCartao, sizeof(char), 13, arquivoBin);
	fread(&cabecalho->descreveNome, sizeof(char), 13, arquivoBin);
	fread(&cabecalho->descreveCor, sizeof(char), 24, arquivoBin);
	
	return 1;
}

/*
	Descrição:
		Imprime o cabeçalho na tela

	Argumentos:
		[in]arquivoBin: arquivo binário que foi criado
	    	OBS: Não realiza fopen, nem fclose
	    [in]cabecalho: struct de cabecalho que foi criado e preenchido
	
	Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
    	após a leitura ele imprime o que foi lido pelo 'cabecalho'
*/
int mostrarCabecalhoLinha(FILE *arquivoBin, LINHA_CABECALHO *cabecalho) {
	if (arquivoBin == NULL) return 0;

	printf("status %c\n", cabecalho->status);
	printf("byteProxReg %ld\n", cabecalho->byteProxReg);
	printf("nroRegistros %d\n", cabecalho->nroRegistros);
	printf("nroRegRemovidos %d\n", cabecalho->nroRegRemovidos);
	printf("descreveCodigo %s\n", cabecalho->descreveCodigo);
	printf("descreveCartao %s\n", cabecalho->descreveCartao);
	printf("descreveNome %s\n", cabecalho->descreveNome);
	printf("descreveCor %s\n", cabecalho->descreveCor);

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
int mudaStatusCabecalhoLinha(FILE *arquivoBin, char status) {
	if (arquivoBin == NULL) return 0;
	LINHA_CABECALHO cabecalho;

	fseek(arquivoBin, 0, SEEK_SET);
	fwrite(&status, sizeof(char), 1, arquivoBin);

	fseek(arquivoBin, 0, SEEK_SET);
	return 1;
}

/*
    Descricao:
    	Muda o byteProxReg do cabeçalho
    
    Argumentos:
	    [in]arquivoBin: arquivo binário que foi criado
	    		OBS: Não realiza fopen, nem fclose
		[in]byteOffset: o byteProxReg que será passado ao cabeçalho

    Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
*/
int setByteOffsetLinha(FILE *arquivoBin, long int byteOffset) {
	if (arquivoBin == NULL) return 0;
	fseek(arquivoBin, 1, SEEK_SET);
	fwrite(&byteOffset, sizeof(long int), 1, arquivoBin);

	fseek(arquivoBin, 0, SEEK_SET);
	return 1;
}

/*
    Descricao:
    	Muda o nroRegistros do cabeçalho
    
    Argumentos:
	    [in]arquivoBin: arquivo binário que foi criado
	    		OBS: Não realiza fopen, nem fclose
		[in]nRegistros: o nroRegistros que será passado ao cabeçalho

    Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
*/
int setNRegistrosLinha(FILE *arquivoBin, int nRegistros) {
	if (arquivoBin == NULL) return 0;
	fseek(arquivoBin, 9, SEEK_SET);
	fwrite(&nRegistros, sizeof(int), 1, arquivoBin);

	fseek(arquivoBin, 0, SEEK_SET);
	return 1;
}

/*
    Descricao:
    	Muda o nroRegRemovidos do cabeçalho
    
    Argumentos:
	    [in]arquivoBin: arquivo binário que foi criado
	    		OBS: Não realiza fopen, nem fclose
		[in]nRemovidos: o nroRegRemovidos que será passado ao cabeçalho

    Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
*/
int setNRemovidosLinha(FILE *arquivoBin, int nRemovidos) {
	if (arquivoBin == NULL) return 0;
	fseek(arquivoBin, 13, SEEK_SET);
	fwrite(&nRemovidos, sizeof(int), 1, arquivoBin);

	fseek(arquivoBin, 0, SEEK_SET);
	return 1;
}