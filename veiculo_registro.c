#include "veiculo_registro.h"
#include "veiculo_cabecalho.h"
#include "binarioNaTela.h"

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
int insereRegistroVeiculo(FILE *arquivoBin, VEICULO_REGISTRO *registro) {
	if (arquivoBin == NULL) return 0;

	fwrite(&registro->removido, sizeof(char), 1, arquivoBin);
	fwrite(&registro->tamanhoRegistro, sizeof(int), 1, arquivoBin);
	fwrite(registro->prefixo, sizeof(char), 5, arquivoBin);
	fwrite(registro->data, sizeof(char), 10, arquivoBin);
	fwrite(&registro->quantidadeLugares, sizeof(int), 1, arquivoBin);
	fwrite(&registro->codLinha, sizeof(int), 1, arquivoBin);
	
	fwrite(&registro->tamanhoModelo, sizeof(int), 1, arquivoBin);
	if(registro->tamanhoModelo > 0)
		fwrite(registro->modelo, sizeof(char), registro->tamanhoModelo, arquivoBin);
	
	fwrite(&registro->tamanhoCategoria, sizeof(int), 1, arquivoBin);
	if(registro->tamanhoCategoria > 0)
		fwrite(registro->categoria, sizeof(char), registro->tamanhoCategoria, arquivoBin);

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
	registro->modelo = (char*) malloc(sizeof(char) * registro->tamanhoModelo);
	fread(registro->modelo, sizeof(char), registro->tamanhoModelo, arquivoBin);
	
	fread(&registro->tamanhoCategoria, sizeof(int), 1, arquivoBin);
	registro->categoria = (char*) malloc(sizeof(char) * registro->tamanhoCategoria);
	if(fread(registro->categoria, sizeof(char), registro->tamanhoCategoria, arquivoBin) == 0) return 0;
	
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

	char vet[5];
	for (int i = 0; i < 5; ++i){
		vet[i] = registro->prefixo[i];
	}

	printf("Prefixo do veiculo: %s\n", vet);

	registro->modelo[registro->tamanhoModelo] = '\0';
	if(strcmp(registro->modelo, "")) printf("Modelo do veiculo: %s\n", registro->modelo);
	else printf("Modelo do veiculo: campo com valor nulo\n");

	registro->categoria[registro->tamanhoCategoria] = '\0';
	if(strcmp(registro->categoria, "")) printf("Categoria do veiculo: %s\n", registro->categoria);
	else printf("Categoria do veiculo: campo com valor nulo\n");

	//Rever data
	if(registro->data != "NULO") printf("Data de entrada do veiculo na frota: %s\n", registro->data);
	else printf("Data de entrada do veiculo na frota: campo com valor nulo\n");

	if(registro->quantidadeLugares != -1) printf("Quantidade de lugares sentados disponiveis: %d\n", registro->quantidadeLugares);
	else printf("Quantidade de lugares sentados disponiveis: campo com valor nulo\n");
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

int	imprimeRegistrosVeiculo(FILE *arquivoBin) {
	VEICULO_CABECALHO cabecalho = createVeiculoCabecalho();
	readVeiculoCabecalho(arquivoBin, &cabecalho);

	VEICULO_REGISTRO registro;

	int n = 0;
	while(readRegistroVeiculo(arquivoBin, &registro) != 0) {
			if(registro.removido == '1')mostrarRegistroVeiculo(arquivoBin, &registro);
			n++;
	}

	if(n == 0) printf("Registro inexistente.\n");

	return 1;
}

int buscaParametroVeiculo(FILE *arquivoBin) {
	char nomeCampo[50];
	char valorCampo[50];
	char buffer;
	scan_quote_string(nomeCampo);
	scan_quote_string(valorCampo);

	VEICULO_CABECALHO cabecalho = createVeiculoCabecalho();
	readVeiculoCabecalho(arquivoBin, &cabecalho);

	VEICULO_REGISTRO registro;
	
	//prefixo, data, quantidadeLugares, modelo, categoria.

	if(!strcmp(nomeCampo, "prefixo")) {
		char vet[5];
		for (int i = 0; i < 5; ++i){
			vet[i] = registro.prefixo[i];
		}

		while(readRegistroVeiculo(arquivoBin, &registro) != 0) {
			if(!strcmp(registro.prefixo, vet)) {
				if(registro.removido == '1') mostrarRegistroVeiculo(arquivoBin, &registro);
			}	
		}
	} else if(!strcmp(nomeCampo, "data")) {
		while(readRegistroVeiculo(arquivoBin, &registro) != 0) {
			if(!strcmp(registro.data, valorCampo)) {
				if(registro.removido == '1') mostrarRegistroVeiculo(arquivoBin, &registro);
			}	
		}
	} else if(!strcmp(nomeCampo, "quantidadeLugares")) {
		int cod = atoi(valorCampo);

		while(readRegistroVeiculo(arquivoBin, &registro) != 0) {
			if(registro.quantidadeLugares == cod) {
				if(registro.removido == '1') mostrarRegistroVeiculo(arquivoBin, &registro);
			}	
		}
	} else if(!strcmp(nomeCampo, "modelo")) {
		while(readRegistroVeiculo(arquivoBin, &registro) != 0) {
			if(!strcmp(registro.modelo, valorCampo)) {
				if(registro.removido == '1') mostrarRegistroVeiculo(arquivoBin, &registro);
			}
		}
	} else if(!strcmp(nomeCampo, "categoria")) {
		while(readRegistroVeiculo(arquivoBin, &registro) != 0) {
			if(!strcmp(registro.categoria, valorCampo)) {
				if(registro.removido == '1') mostrarRegistroVeiculo(arquivoBin, &registro);
			}
		}
	}

	return 1;
}

int insereNRegistrosVeiculo(FILE *arquivoBin, int numeroNovosRegistros) {
	VEICULO_CABECALHO cabecalho = createVeiculoCabecalho();
	readVeiculoCabecalho(arquivoBin, &cabecalho);
	if(cabecalho.status == '0') return 0;

	mudaStatusCabecalhoVeiculo(arquivoBin, '0');
	readVeiculoCabecalho(arquivoBin, &cabecalho);

	long int proxByte = cabecalho.byteProxReg;
	int nRegistros = cabecalho.nroRegistros;

	char prefixo[5];
    char data[10];
	char quantidadeLugares[5];
	char codLinha[10];
	char modelo[150];
	char categoria[150];

	fseek(arquivoBin, proxByte, SEEK_SET);
	for (int i = 0; i < numeroNovosRegistros; ++i) {
		VEICULO_REGISTRO registro;

		scan_quote_string(prefixo);
		scan_quote_string(data);
		scan_quote_string(quantidadeLugares);
		scan_quote_string(codLinha);
		scan_quote_string(modelo);
		scan_quote_string(categoria);

		int tamanhoModelo = strlen(modelo);
		int tamanhoCategoria= strlen(categoria);

		registro.removido = '1';

		strcpy(registro.prefixo, prefixo);

		if(!strcmp(quantidadeLugares, "NULO")) registro.quantidadeLugares = -1;
		else registro.quantidadeLugares = atoi(quantidadeLugares);	

		if(!strcmp(data, "NULO")) {
			//strcpy(registro.data, "\0@@@@@@@@@");
			registro.data[0] = '\0';
			registro.data[1] = '@';
			registro.data[2] = '@';
			registro.data[3] = '@';
			registro.data[4] = '@';
			registro.data[5] = '@';
			registro.data[6] = '@';
			registro.data[7] = '@';
			registro.data[8] = '@';
			registro.data[9] = '@';
		}
		else strcpy(registro.data, data);

		if(!strcmp(codLinha, "NULO")) registro.codLinha = -1;
		else registro.codLinha = atoi(codLinha);

		registro.tamanhoModelo = tamanhoModelo;
		if(!strcmp(modelo, "NULO")) {
			strcpy(registro.modelo, "");
			registro.tamanhoModelo = 0;
		} else {
			registro.modelo = (char*) malloc(sizeof(char) * tamanhoModelo);
			strcpy(registro.modelo, modelo);
		}

		registro.tamanhoCategoria = tamanhoCategoria;
		if(!strcmp(categoria, "NULO")) {
			strcpy(registro.categoria, "");
			registro.tamanhoCategoria = 0;
		} else {
			registro.categoria = (char*) malloc(sizeof(char) * tamanhoCategoria);
			strcpy(registro.categoria, categoria);
		}

		registro.tamanhoRegistro = sizeof(char) + sizeof(int) + sizeof(char)*5 + sizeof(char)*10 + sizeof(int) + sizeof(int) + sizeof(int) + (sizeof(char) * tamanhoModelo) + sizeof(int) + (sizeof(char) * tamanhoCategoria) -5;

		insereRegistroVeiculo(arquivoBin, &registro);

		free(registro.modelo);
		free(registro.categoria);
		
		proxByte += registro.tamanhoRegistro+5;
	}

	setByteOffsetVeiculo(arquivoBin, proxByte);
	setNRegistrosVeiculo(arquivoBin, nRegistros+numeroNovosRegistros);
	mudaStatusCabecalhoVeiculo(arquivoBin, '1');

	return 1;
}