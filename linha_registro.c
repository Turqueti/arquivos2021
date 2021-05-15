#include "linha_registro.h"

struct _linha_registro {
    char removido;
    int tamanhoRegistro;
    int codLinha;
    char aceitaCartao;
    int tamanhoNome;
    char *nomeLinha;
    int tamanhoCor;
    char *corLinha;
};

/*
    Descricao:
    	essa func cria um registro do arquivo linha
    
    Argumentos:
	    [in]arquivoBin: arquivo binário que foi criado
	    		OBS: Não realiza fopen, nem fclose, nem muda o status, nem o fseek
		[in]cabecalho: struct de cabecalho que foi criado e preenchido

    Retorno:
    	se tudo der certo retorna 1 se algo der errado retorna 0
*/
int createRegistroLinha(FILE *arquivoBin, LINHA_REGISTRO *registro) {
	if (arquivoBin == NULL) return 0;

	fwrite(&registro->removido, sizeof(char), 1, arquivoBin);
	fwrite(&registro->tamanhoRegistro, sizeof(int), 1, arquivoBin);
	fwrite(&registro->codLinha, sizeof(int), 1, arquivoBin);
	fwrite(&registro->aceitaCartao, sizeof(char), 1, arquivoBin);
	fwrite(&registro->tamanhoNome, sizeof(int), 1, arquivoBin);
	fwrite(&registro->nomeLinha, sizeof(char), registro->tamanhoNome, arquivoBin);
	fwrite(&registro->tamanhoCor, sizeof(int), 1, arquivoBin);
	fwrite(&registro->corLinha, sizeof(char), registro->tamanhoCor, arquivoBin);

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
int readRegistroLinha(FILE *arquivoBin, LINHA_REGISTRO *registro) {
	if (arquivoBin == NULL) return 0;

	fread(&registro->removido, sizeof(char), 1, arquivoBin);
	fread(&registro->tamanhoRegistro, sizeof(int), 1, arquivoBin);
	fread(&registro->codLinha, sizeof(int), 1, arquivoBin);
	fread(&registro->aceitaCartao, sizeof(char), 1, arquivoBin);
	fread(&registro->tamanhoNome, sizeof(int), 1, arquivoBin);
	fread(&registro->nomeLinha, sizeof(char), registro->tamanhoNome, arquivoBin);
	fread(&registro->tamanhoCor, sizeof(int), 1, arquivoBin);
	fread(&registro->corLinha, sizeof(char), registro->tamanhoCor, arquivoBin);
	
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
int mostrarRegistroLinha(FILE *arquivoBin, LINHA_REGISTRO *registro) {
	if (arquivoBin == NULL) return 0;

	if(registro->codLinha != -1) printf("Codigo da linha: %d\n", registro->codLinha);
	else printf("Codigo da linha: campo com valor nulo\n");

	if(registro->nomeLinha != "NULO") printf("Nome da linha: %s\n", registro->nomeLinha);
	else printf("Nome da linha: campo com valor nulo\n");

	if(registro->corLinha != "NULO") printf("Cor que descreve a linha: %s\n", registro->corLinha);
	else printf("Cor que descreve a linha: campo com valor nulo\n");

	if(registro->aceitaCartao == 'S') printf("Aceita cartao: PAGAMENTO  SOMENTE  COM  CARTAO  SEM  PRESENCA  DECOBRADOR\n");
	else if(registro->aceitaCartao == 'N') printf("Aceita cartao: PAGAMENTO EM CARTAO E DINHEIRO\n");
	else if(registro->aceitaCartao == 'F') printf("Aceita cartao: PAGAMENTO EM CARTAO SOMENTE NO FINAL DE SEMANA\n");

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