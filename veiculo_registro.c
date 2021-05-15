#include "veiculo_registro.h"

struct _veiculo_registro {
    char removido;
    int tamanhoRegistro;
    char prefixo[5];
    char data[10];
    int quantidadeLugares;
    int codLinha;
    int tamanhoModelo;
    char *modelo;
    int tamanhoCategoria;
    char *categoria;
};

/*
    Descricao:
    	essa func cria um registro do arquivo veiculo
    
    Argumentos:
	    [in]arquivoBin: arquivo binário que foi criado
	    		OBS: Não realiza fopen, nem fclose, nem muda o status, nem o fseek
		[in]cabecalho: struct de cabecalho que foi criado e preenchido

    Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
*/
int createRegistroVeiculo(FILE *arquivoBin, VEICULO_REGISTRO *registro) {
	if (arquivoBin == NULL) return 0;

	fwrite(&registro->removido, sizeof(char), 1, arquivoBin);
	fwrite(&registro->tamanhoRegistro, sizeof(int), 1, arquivoBin);
	fwrite(&registro->prefixo, sizeof(char), 5, arquivoBin);
	fwrite(&registro->data, sizeof(char), 10, arquivoBin);
	fwrite(&registro->quantidadeLugares, sizeof(int), 1, arquivoBin);
	fwrite(&registro->codLinha, sizeof(int), 1, arquivoBin);
	fwrite(&registro->tamanhoModelo, sizeof(int), 1, arquivoBin);
	fwrite(&registro->modelo, sizeof(char), registro->tamanhoModelo, arquivoBin);
	fwrite(&registro->tamanhoCategoria, sizeof(int), 1, arquivoBin);
	fwrite(&registro->categoria, sizeof(char), registro->tamanhoCategoria, arquivoBin);

	return 1;
}

/*
    Descricao:
    	Lê o um registro
    
    Argumentos:
	    [in]arquivoBin: arquivo binário que foi criado
	    		OBS: Não realiza fopen, nem fclose, nem muda o status, nem o fseek
		[in]cabecalho: struct de cabecalho que foi criado e preenchido

    Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
    	após a leitura ele retorna o que foi lido pelo 'cabecalho'
*/
int readRegistroVeiculo(FILE *arquivoBin, VEICULO_REGISTRO *registro) {
	if (arquivoBin == NULL) return 0;

	fread(&registro->removido, sizeof(char), 1, arquivoBin);
	fread(&registro->tamanhoRegistro, sizeof(int), 1, arquivoBin);
	fread(&registro->prefixo, sizeof(char), 5, arquivoBin);
	fread(&registro->data, sizeof(char), 10, arquivoBin);
	fread(&registro->quantidadeLugares, sizeof(int), 1, arquivoBin);
	fread(&registro->codLinha, sizeof(int), 1, arquivoBin);
	fread(&registro->tamanhoModelo, sizeof(int), 1, arquivoBin);
	fread(&registro->modelo, sizeof(char), registro->tamanhoModelo, arquivoBin);
	fread(&registro->tamanhoCategoria, sizeof(int), 1, arquivoBin);
	fread(&registro->categoria, sizeof(char), registro->tamanhoCategoria, arquivoBin);
	
	return 1;
}

/*
	Descrição:
		Imprime um registro na tela

	Argumentos:
		[in]arquivoBin: arquivo binário que foi criado
	    	OBS: Não realiza fopen, nem fclose
	    [in]cabecalho: struct de cabecalho que foi criado e preenchido
	
	Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
    	após a leitura ele imprime o que foi lido pelo 'cabecalho'
*/
int mostrarRegistroVeiculo(FILE *arquivoBin, VEICULO_REGISTRO *registro) {
	if (arquivoBin == NULL) return 0;

	if(registro->prefixo != "NULO") printf("Prefixo do veiculo:: %s\n", registro->prefixo);
	else printf("Prefixo do veiculo: campo com valor nulo\n");

	if(registro->modelo != "NULO") printf("Modelo do veiculo: %s\n", registro->modelo);
	else printf("Modelo do veiculo: campo com valor nulo\n");

	if(registro->categoria != "NULO") printf("Categoria do veiculo: %s\n", registro->categoria);
	else printf("Categoria do veiculo: campo com valor nulo\n");

	//Rever data
	if(registro->data != "NULO") printf("Data de entrada do veiculo na frota: %s\n", registro->data);
	else printf("Data de entrada do veiculo na frota: campo com valor nulo\n");

	if(registro->quantidadeLugares != -1) printf("Data de entrada do veiculo na frota: %d\n", registro->quantidadeLugares);
	else printf("Data de entrada do veiculo na frota: campo com valor nulo\n");
	printf("\n");

	/*printf("%c\n", registro->removido);
	printf("%d\n", registro->tamanhoRegistro);
	printf("%d\n", registro->codLinha);
	printf("%c\n", registro->aceitaCartao);
	printf("%d\n", registro->tamanhoNome);
	printf("%s\n", registro->nomeLinha); //sem \0
	printf("%d\n", registro->tamanhoCor);
	printf("%s\n", registro->corLinha); //sem \0*/

	return 1;
}

int teste(char nomeArquivoCSV[30], char nomeArquivoBIN[30]) {
	char linha[150];
	char *b = linha;
	size_t i = 150;

	LINHA_REGISTRO registro;
	LINHA_REGISTRO registro2;

	FILE *arquivoCSV = NULL;
	FILE *arquivoBIN = NULL;

	//abre arquivo csv
	arquivoCSV = fopen(nomeArquivoCSV, "r");
	if(arquivoCSV == NULL) return 0;


	arquivoBIN = fopen(nomeArquivoBIN, "w+b");
	if(arquivoBIN == NULL) return 0;

	registro.removido = '0';
    registro.tamanhoRegistro = 1;
    registro.codLinha = 2;
    registro.aceitaCartao = 'S';

    registro.tamanhoNome = 80;
    registro.nomeLinha = (char*) malloc(sizeof(char) * 80);
    strcpy(registro.nomeLinha, "too");
    
    registro.tamanhoCor = 80;
	registro.corLinha = (char*) malloc(sizeof(char) * 80);
    strcpy(registro.corLinha, "sooo");

    createRegistroLinha(arquivoBIN, &registro);

	fseek(arquivoBIN, 0, SEEK_SET);
    readRegistroLinha(arquivoBIN, &registro2);
    mostrarRegistroLinha(arquivoBIN, &registro2);

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
}