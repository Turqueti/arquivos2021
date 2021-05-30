#include "veiculo_cabecalho.h"

/*
    Descricao:
    	essa func cria um cabecalho do arquivo veiculo

    Retorno:
    	Um cabecalho prenchido com dados falsos que devem ser alterados
*/
VEICULO_CABECALHO createVeiculoCabecalho() {
	VEICULO_CABECALHO cabecalho;

	cabecalho.status = '0';
	cabecalho.byteProxReg = 0;
	cabecalho.nroRegistros = 0;
	cabecalho.nroRegRemovidos = 0;

	return cabecalho;
}

/*
    Descricao:
    	essa func insere um cabecalho do arquivo veiculo
    
    Argumentos:
	    [in]arquivoBin: arquivo binário que foi criado
	    		OBS: Não realiza fopen nem fclose
		[in]cabecalho: struct de cabecalho que foi criado e preenchido

    Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
*/
int insereVeiculoCabecalho(FILE *arquivoBin, VEICULO_CABECALHO *cabecalho) {
	if (arquivoBin == NULL) return 0;

	fseek(arquivoBin, 0, SEEK_SET);
	fwrite(&cabecalho->status, sizeof(char), 1, arquivoBin);
	fwrite(&cabecalho->byteProxReg, sizeof(long int), 1, arquivoBin);
	fwrite(&cabecalho->nroRegistros, sizeof(int), 1, arquivoBin);
	fwrite(&cabecalho->nroRegRemovidos, sizeof(int), 1, arquivoBin);
	fwrite(&cabecalho->descrevePrefixo, sizeof(char), 18, arquivoBin);
	fwrite(&cabecalho->descreveData, sizeof(char), 35, arquivoBin);
	fwrite(&cabecalho->descreveLugares, sizeof(char), 42, arquivoBin);
	fwrite(&cabecalho->descreveLinha, sizeof(char), 26, arquivoBin);
	fwrite(&cabecalho->descreveModelo, sizeof(char), 17, arquivoBin);
	fwrite(&cabecalho->descreveCategoria, sizeof(char), 20, arquivoBin);
	
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
int readVeiculoCabecalho(FILE *arquivoBin, VEICULO_CABECALHO *cabecalho) {
	if (arquivoBin == NULL) return 0;

	fseek(arquivoBin, 0, SEEK_SET);
	fread(&cabecalho->status, sizeof(char), 1, arquivoBin);
	fread(&cabecalho->byteProxReg, sizeof(long int), 1, arquivoBin);
	fread(&cabecalho->nroRegistros, sizeof(int), 1, arquivoBin);
	fread(&cabecalho->nroRegRemovidos, sizeof(int), 1, arquivoBin);
	fread(&cabecalho->descrevePrefixo, sizeof(char), 18, arquivoBin);
	fread(&cabecalho->descreveData, sizeof(char), 35, arquivoBin);
	fread(&cabecalho->descreveLugares, sizeof(char), 42, arquivoBin);
	fread(&cabecalho->descreveLinha, sizeof(char), 26, arquivoBin);
	fread(&cabecalho->descreveModelo, sizeof(char), 17, arquivoBin);
	fread(&cabecalho->descreveCategoria, sizeof(char), 20, arquivoBin);
	
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
int mostrarCabecalhoVeiculo(FILE *arquivoBin, VEICULO_CABECALHO *cabecalho) {
	if (arquivoBin == NULL) return 0;

	printf("%c\n", cabecalho->status);
	printf("%ld\n", cabecalho->byteProxReg);
	printf("%d\n", cabecalho->nroRegistros);
	printf("%d\n", cabecalho->nroRegRemovidos);
	printf("%s\n", cabecalho->descrevePrefixo);
	printf("%s\n", cabecalho->descreveData);
	printf("%s\n", cabecalho->descreveLugares);
	printf("%s\n", cabecalho->descreveLinha);
	printf("%s\n", cabecalho->descreveModelo);
	printf("%s\n", cabecalho->descreveCategoria);

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
int mudaStatusCabecalhoVeiculo(FILE *arquivoBin, char status) {
	if (arquivoBin == NULL) return 0;
	VEICULO_CABECALHO cabecalho;

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
int setByteOffsetVeiculo(FILE *arquivoBin, long  int byteOffset) {
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
int setNRegistrosVeiculo(FILE *arquivoBin, int nRegistros) {
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
int setNRemovidosVeiculo(FILE *arquivoBin, int nRemovidos) {
	if (arquivoBin == NULL) return 0;
	
	fseek(arquivoBin, 13, SEEK_SET);
	fwrite(&nRemovidos, sizeof(int), 1, arquivoBin);

	fseek(arquivoBin, 0, SEEK_SET);
	return 1;
}
