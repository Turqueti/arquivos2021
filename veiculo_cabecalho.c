#include "veiculo_cabecalho.h"

struct _veiculo_cabecalho {
    char status;
    long long int byteProxReg;
    int nroRegistros;
    int nroRegRemovidos;
    char descrevePrefixo[18];
    char descreveData[35];
    char descreveLugares[42];
    char descreveLinha[26];
    char descreveModelo[17];
    char descreveCategoria[20];
};

/*
    Descricao:
    	essa func cria um cabecalho do arquivo veiculo
    
    Argumentos:
	    [in]arquivoBin: arquivo binário que foi criado
	    		OBS: Não realiza fopen nem fclose
		[in]cabecalho: struct de cabecalho que foi criado e preenchido

    Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
*/
int createVeiculoCabecalho(FILE *arquivoBin, VEICULO_CABECALHO *cabecalho) {
	if (arquivoBin == NULL) return 0;

	fseek(arquivoBin, 0, SEEK_SET);
	fwrite(&cabecalho->status, sizeof(char), 1, arquivoBin);
	fwrite(&cabecalho->byteProxReg, sizeof(long long int), 1, arquivoBin);
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
	fread(&cabecalho->byteProxReg, sizeof(long long int), 1, arquivoBin);
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
	printf("%lld\n", cabecalho->byteProxReg);
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

	readVeiculoCabecalho(arquivoBin, &cabecalho);
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
int setByteOffsetVeiculo(FILE *arquivoBin, long long int byteOffset) {
	if (arquivoBin == NULL) return 0;
	VEICULO_CABECALHO cabecalho;

	readVeiculoCabecalho(arquivoBin, &cabecalho);
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
int setNRegistrosVeiculo(FILE *arquivoBin, int nRegistros) {
	if (arquivoBin == NULL) return 0;
	VEICULO_CABECALHO cabecalho;

	readVeiculoCabecalho(arquivoBin, &cabecalho);
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
int setNRemovidosVeiculo(FILE *arquivoBin, int nRemovidos) {
	if (arquivoBin == NULL) return 0;
	VEICULO_CABECALHO cabecalho;

	readVeiculoCabecalho(arquivoBin, &cabecalho);
	cabecalho.nroRegRemovidos = nRemovidos;

	//Salvar novamente no binário fseek = 5; pois inicio do arquivo + sizeof(char) + sizeof(int)
	fseek(arquivoBin, 13, SEEK_SET);
	fwrite(&cabecalho.nroRegRemovidos, sizeof(int), 1, arquivoBin);
	return 1;
}

int criaBinarioVeiculo(char nomeArquivoCSV[30], char nomeArquivoBIN[30]) {
	char linha[150];
	char *b = linha;
	size_t i = 150;

	VEICULO_CABECALHO cabecalho;
	VEICULO_CABECALHO cabecalho2;

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
	strcpy(cabecalho.descrevePrefixo, "abc1");
	strcpy(cabecalho.descreveData, "abc2");
	strcpy(cabecalho.descreveLugares, "abc3");
	strcpy(cabecalho.descreveLinha, "abc4");
	strcpy(cabecalho.descreveModelo, "abc5");
	strcpy(cabecalho.descreveCategoria, "abc6");

	createVeiculoCabecalho(arquivoBIN, &cabecalho);
	setNRemovidosVeiculo(arquivoBIN, 5555);
	
	readVeiculoCabecalho(arquivoBIN, &cabecalho2);
	mostrarCabecalhoVeiculo(arquivoBIN, &cabecalho2);

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