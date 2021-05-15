#include "linha_cabecalho.h"

struct _linha_cabecalho {
    char status;
    long long int byteProxReg;
    int nroRegistros;
    int nroRegRemovidos;
    char descreveCodigo[15];
    char descreveCartao[13];
    char descreveNome[13];
    char descreveCor[24];
};

/*
    Descricao:
    	essa func cria um cabecalho do arquivo linha
    
    Argumentos:
	    [in]arquivoBin: arquivo binário que foi criado
	    		OBS: Não realiza fopen nem fclose
		[in]cabecalho: struct de cabecalho que foi criado e preenchido

    Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
*/
int create_linha_cabecalho(FILE *arquivoBin, LINHA_CABECALHO *cabecalho) {
	if (arquivoBin == NULL) return 0;

	fseek(arquivoBin, 0, SEEK_SET);
	fwrite(&cabecalho->status, sizeof(char), 1, arquivoBin);
	fwrite(&cabecalho->byteProxReg, sizeof(long long int), 1, arquivoBin);
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
int read_linha_cabecalho(FILE *arquivoBin, LINHA_CABECALHO *cabecalho) {
	if (arquivoBin == NULL) return 0;

	fseek(arquivoBin, 0, SEEK_SET);
	fread(&cabecalho->status, sizeof(char), 1, arquivoBin);
	fread(&cabecalho->byteProxReg, sizeof(long long int), 1, arquivoBin);
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

	printf("%c\n", cabecalho->status);
	printf("%lld\n", cabecalho->byteProxReg);
	printf("%d\n", cabecalho->nroRegistros);
	printf("%d\n", cabecalho->nroRegRemovidos);
	printf("%s\n", cabecalho->descreveCodigo);
	printf("%s\n", cabecalho->descreveCartao);
	printf("%s\n", cabecalho->descreveNome);
	printf("%s\n", cabecalho->descreveCor);

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
int mudaStatus(FILE *arquivoBin, char status) {
	if (arquivoBin == NULL) return 0;
	LINHA_CABECALHO cabecalho;

	read_linha_cabecalho(arquivoBin, &cabecalho);
	cabecalho.status = status;
	
	//Salvar novamente no binário fseek = 0; pois inicio do arquivo
	fseek(arquivoBin, 0, SEEK_SET);
	fwrite(&cabecalho.status, sizeof(char), 1, arquivoBin);
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
int setByteOffset(FILE *arquivoBin, long long int byteOffset) {
	if (arquivoBin == NULL) return 0;
	LINHA_CABECALHO cabecalho;

	read_linha_cabecalho(arquivoBin, &cabecalho);
	cabecalho.byteProxReg = byteOffset;
	
	//Salvar novamente no binário fseek = 1; pois inicio do arquivo + sizeof(char)
	fseek(arquivoBin, 1, SEEK_SET);
	fwrite(&cabecalho.byteProxReg, sizeof(long long int), 1, arquivoBin);
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
int setNRegistros(FILE *arquivoBin, int nRegistros) {
	if (arquivoBin == NULL) return 0;
	LINHA_CABECALHO cabecalho;

	read_linha_cabecalho(arquivoBin, &cabecalho);
	cabecalho.nroRegistros = nRegistros;
	
	//Salvar novamente no binário fseek = 5; pois inicio do arquivo + sizeof(char) + sizeof(int)
	fseek(arquivoBin, 9, SEEK_SET);
	fwrite(&cabecalho.nroRegistros, sizeof(int), 1, arquivoBin);
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
int setNRemovidos(FILE *arquivoBin, int nRemovidos) {
	if (arquivoBin == NULL) return 0;
	LINHA_CABECALHO cabecalho;

	read_linha_cabecalho(arquivoBin, &cabecalho);
	cabecalho.nroRegRemovidos = nRemovidos;

	//Salvar novamente no binário fseek = 5; pois inicio do arquivo + sizeof(char) + sizeof(int)
	fseek(arquivoBin, 13, SEEK_SET);
	fwrite(&cabecalho.nroRegRemovidos, sizeof(int), 1, arquivoBin);
	return 1;
}

int criaBinarioLinha(char nomeArquivoCSV[30], char nomeArquivoBIN[30]) {
	char linha[150];
	char *b = linha;
	size_t i = 150;

	LINHA_CABECALHO cabecalho;
	LINHA_CABECALHO cabecalho2;

	FILE *arquivoCSV = NULL;
	FILE *arquivoBIN = NULL;

	//abre arquivo csv
	arquivoCSV = fopen(nomeArquivoCSV, "r");
	if(arquivoCSV == NULL) return 0;


	arquivoBIN = fopen(nomeArquivoBIN, "w+b");
	if(arquivoBIN == NULL) return 0;

	cabecalho.status = '0';
	cabecalho.byteProxReg = 1;
	cabecalho.nroRegistros = 2;
	cabecalho.nroRegRemovidos = 3;
	strcpy(cabecalho.descreveCodigo, "abc1");
	strcpy(cabecalho.descreveCartao, "abc2");
	strcpy(cabecalho.descreveNome, "abc3");
	strcpy(cabecalho.descreveCor, "abc4");
	
	create_linha_cabecalho(arquivoBIN, &cabecalho);
	read_linha_cabecalho(arquivoBIN, &cabecalho2);


	//JOGAR ISSO NUMA FUNÇÃO
		//lê a primeira linha do arquivo
		//getline(&b, &i, arquivoCSV);//Pega 1B a mais?
		//separa a linha em 4 strings
		//joga a primeira linha na struct
		
	//abre o arquivo binário
	//escreve a primeira linha no arquivo binário
	//fecha o arquivo binário
	fclose(arquivoBIN);

	//fecha o arquivo csv
	fclose(arquivoCSV);

	return 1;
}