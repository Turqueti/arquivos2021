#include "linha_registro.h"
#include "linha_cabecalho.h"

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
int insereRegistroLinha(FILE *arquivoBin, LINHA_REGISTRO *registro) {
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
	registro->nomeLinha = (char*) malloc(sizeof(char) * registro->tamanhoNome);
	fread(&registro->nomeLinha, sizeof(char), registro->tamanhoNome, arquivoBin);

	fread(&registro->tamanhoCor, sizeof(int), 1, arquivoBin);
	registro->corLinha = (char*) malloc(sizeof(char) * registro->tamanhoCor);
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
	printf("\n");

	/*printf("removido %c\n", registro->removido);
	printf("tamanhoRegistro %d\n", registro->tamanhoRegistro);
	printf("codLinha %d\n", registro->codLinha);
	printf("aceitaCartao %c\n", registro->aceitaCartao);
	printf("tamanhoNome %d\n", registro->tamanhoNome);
	printf("nomeLinha %s\n", registro->nomeLinha); //sem \0
	printf("tamanhoCor %d\n", registro->tamanhoCor);
	printf("corLinha %s\n", registro->corLinha); //sem \0*/

	return 1;
}

int insereNRegistrosLinha(FILE *arquivoBin, int numeroNovosRegistros) {
	LINHA_CABECALHO cabecalho = createLinhaCabecalho();
	readLinhaCabecalho(arquivoBin, &cabecalho);

	mudaStatusCabecalhoLinha(arquivoBin, '0');

	int proxByte = cabecalho.byteProxReg;
	int nRegistros = cabecalho.nroRegistros;

	int codLinha;
	char aceitaCartao;
	char nomeLinha[150];
	char corLinha[150];

	LINHA_REGISTRO registro;
	fseek(arquivoBin, proxByte, SEEK_SET);
	for (int i = 0; i < numeroNovosRegistros; ++i){//verificar nulos e retirar aspas
		LINHA_REGISTRO registro2;
		scanf("%d %c %s %s", &codLinha, &aceitaCartao, nomeLinha, corLinha);

		int nomeTam = strlen(nomeLinha);
		int corTam = strlen(corLinha);

		registro.removido = '@';
		registro.tamanhoRegistro = sizeof(char) + sizeof(int) + sizeof(int) + sizeof(char) + sizeof(int) + sizeof(int) + nomeTam + corTam;
		registro.codLinha = codLinha;
		registro.aceitaCartao = aceitaCartao;

		registro.tamanhoNome = nomeTam;
		registro.nomeLinha = (char*) malloc(sizeof(char) * nomeTam);
		strcpy(registro.nomeLinha, nomeLinha);

		registro.tamanhoCor = corTam;
		registro.corLinha = (char*) malloc(sizeof(char) * corTam);
		strcpy(registro.corLinha, corLinha);

		mostrarRegistroLinha(arquivoBin, &registro);
		insereRegistroLinha(arquivoBin, &registro);
		
		proxByte += registro.tamanhoRegistro;
	}

	setByteOffsetLinha(arquivoBin, proxByte);
	setNRegistrosLinha(arquivoBin, nRegistros+numeroNovosRegistros);
	mudaStatusCabecalhoLinha(arquivoBin, '1');
}