#include "linha_registro.h"
#include "linha_cabecalho.h"
#include "binarioNaTela.h"

struct _linha_registro {
    char removido;//1
    int tamanhoRegistro;//4
    int codLinha;//4
    char aceitaCartao;//1
    int tamanhoNome;//4
    char *nomeLinha;
    int tamanhoCor;//4
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
	if(registro->tamanhoNome > 0)
		fwrite(registro->nomeLinha, sizeof(char), registro->tamanhoNome, arquivoBin);
	
	fwrite(&registro->tamanhoCor, sizeof(int), 1, arquivoBin);
	if(registro->tamanhoCor > 0)
		fwrite(registro->corLinha, sizeof(char), registro->tamanhoCor, arquivoBin);

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
	fread(registro->nomeLinha, sizeof(char), registro->tamanhoNome, arquivoBin);

	fread(&registro->tamanhoCor, sizeof(int), 1, arquivoBin);
	registro->corLinha = (char*) malloc(sizeof(char) * registro->tamanhoCor);
	if(fread(registro->corLinha, sizeof(char), registro->tamanhoCor, arquivoBin) == 0) return 0;
	
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

	/*printf("Codigo da linha: %d\n", registro->codLinha);

	if(strcmp(registro->nomeLinha, "")) printf("Nome da linha: %s\n", registro->nomeLinha);
	else printf("Nome da linha: campo com valor nulo\n");

	if(strcmp(registro->corLinha, "NULO")) printf("Cor que descreve a linha: %s\n", registro->corLinha);
	else printf("Cor que descreve a linha: campo com valor nulo\n");

	if(registro->aceitaCartao == 'S') printf("Aceita cartao: PAGAMENTO SOMENTE COM CARTAO SEM PRESENCA DE COBRADOR\n");
	else if(registro->aceitaCartao == 'N') printf("Aceita cartao: PAGAMENTO EM CARTAO E DINHEIRO\n");
	else if(registro->aceitaCartao == 'F') printf("Aceita cartao: PAGAMENTO EM CARTAO SOMENTE NO FINAL DE SEMANA\n");
	else if(registro->aceitaCartao == '\0') printf("Aceita cartao: campo com valor nulo\n");
	printf("\n");*/

	printf("removido %c\n", registro->removido);
	printf("tamanhoRegistro %d\n", registro->tamanhoRegistro);
	printf("codLinha %d\n", registro->codLinha);
	printf("aceitaCartao %c\n", registro->aceitaCartao);
	printf("tamanhoNome %d\n", registro->tamanhoNome);
	printf("nomeLinha %s\n", registro->nomeLinha); //sem \0
	printf("tamanhoCor %d\n", registro->tamanhoCor);
	printf("corLinha %s\n\n", registro->corLinha); //sem \0

	return 1;
}

int insereNRegistrosLinha(FILE *arquivoBin, int numeroNovosRegistros) {
	LINHA_CABECALHO cabecalho = createLinhaCabecalho();
	readLinhaCabecalho(arquivoBin, &cabecalho);
	if(cabecalho.status == '0') return 0;

	mudaStatusCabecalhoLinha(arquivoBin, '0');
	readLinhaCabecalho(arquivoBin, &cabecalho);

	long int proxByte = cabecalho.byteProxReg;
	int nRegistros = cabecalho.nroRegistros;

	int codLinha;
	char aceitaCartao[4];
	char nomeLinha[150];
	char corLinha[150];

	fseek(arquivoBin, proxByte, SEEK_SET);
	for (int i = 0; i < numeroNovosRegistros; ++i) {
		LINHA_REGISTRO registro;

		scanf("%d", &codLinha);

		scan_quote_string(aceitaCartao);
		scan_quote_string(nomeLinha);
		scan_quote_string(corLinha);

		int nomeTam = strlen(nomeLinha);
		int corTam = strlen(corLinha);

		registro.removido = '1';

		registro.codLinha = codLinha;

		if(!strcmp(aceitaCartao, "NULO")) registro.aceitaCartao = '\0';
		else registro.aceitaCartao = aceitaCartao[0];

		registro.tamanhoNome = nomeTam;
		if(!strcmp(nomeLinha, "NULO")) {
			strcpy(registro.nomeLinha, "");
			registro.tamanhoNome = 0;
		} else {
			registro.nomeLinha = (char*) malloc(sizeof(char) * nomeTam);
			strcpy(registro.nomeLinha, nomeLinha);
		}

		registro.tamanhoCor = corTam;
		if(!strcmp(corLinha, "NULO")) {
			strcpy(registro.corLinha, "");
			registro.tamanhoCor = 0;
		} else {
			registro.corLinha = (char*) malloc(sizeof(char) * corTam);
			strcpy(registro.corLinha, corLinha);
		}

		registro.tamanhoRegistro = sizeof(char) + sizeof(int) + sizeof(int) + sizeof(char) + sizeof(int) + sizeof(int) + (sizeof(char) * nomeTam) + (sizeof(char) * corTam) -5;

		insereRegistroLinha(arquivoBin, &registro);

		free(registro.nomeLinha);
		free(registro.corLinha);
		
		proxByte += registro.tamanhoRegistro+5;
	}

	setByteOffsetLinha(arquivoBin, proxByte);
	setNRegistrosLinha(arquivoBin, nRegistros+numeroNovosRegistros);
	mudaStatusCabecalhoLinha(arquivoBin, '1');

	return 1;
}

int buscaParametroLinha(FILE *arquivoBin) {
	char nomeCampo[30];
	char valorCampo[30];
	char buffer;
	scan_quote_string(nomeCampo);
	scan_quote_string(valorCampo);

	LINHA_CABECALHO cabecalho = createLinhaCabecalho();
	readLinhaCabecalho(arquivoBin, &cabecalho);

	LINHA_REGISTRO registro;
	
	//6 linha3_saida_esperada.bin "codLinha" "500"
	if(!strcmp(nomeCampo, "codLinha")) {
		int cod = atoi(valorCampo);

		while(readRegistroLinha(arquivoBin, &registro) != 0) {
			if(registro.codLinha == cod) {
				mostrarRegistroLinha(arquivoBin, &registro);
			}	
		}
	} else if(!strcmp(nomeCampo, "aceitaCartao")) {
		char val = valorCampo[0];

		while(readRegistroLinha(arquivoBin, &registro) != 0) {
			if(registro.aceitaCartao == val) {
				mostrarRegistroLinha(arquivoBin, &registro);
			}
		}
	} else if(!strcmp(nomeCampo, "nomeLinha")) {
		while(readRegistroLinha(arquivoBin, &registro) != 0) {
			if(!strcmp(registro.nomeLinha, valorCampo)) {
				mostrarRegistroLinha(arquivoBin, &registro);
			}
		}
	} else if(!strcmp(nomeCampo, "corLinha")) {
		while(readRegistroLinha(arquivoBin, &registro) != 0) {
			if(!strcmp(registro.corLinha, valorCampo)) {
				mostrarRegistroLinha(arquivoBin, &registro);
			}
		}
	}

	return 1;
}

int	imprimeRegistrosLinha(FILE *arquivoBin) {
	LINHA_CABECALHO cabecalho = createLinhaCabecalho();
	readLinhaCabecalho(arquivoBin, &cabecalho);

	LINHA_REGISTRO registro;

	int n = 0;
	while(readRegistroLinha(arquivoBin, &registro) != 0) {
			mostrarRegistroLinha(arquivoBin, &registro);
			n++;
	}

	if(n == 0) printf("Registro inexistente.\n");

	return 1;
}