#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linha_cabecalho.h"
#include "veiculo_cabecalho.h"
#include "linha_registro.h"
#include "veiculo_registro.h"
#include "csvlib.h"
#include "matrizlib.h"

int main(int argc, char const *argv[]){
	int funcionalidade = 0;
	int numeroNovosRegistros = 0;

	//char nomeCampo[30];
	//char valorCampo[30];
	char arquivoCSV[30];
	char arquivoBIN[30];
	char nomeCampo[30];
	char valorCampo[30];
	char *nome;


	char palavra1[MATRIZBUFFERLEN] = "aaaaaaaaaaa";
	char palavra2[MATRIZBUFFERLEN] = "bbbbbbbbbbbb";
	char palavra3[MATRIZBUFFERLEN] = "ccccccccccccc";
	char palavra4[MATRIZBUFFERLEN] = "dddddddddddddd";
	MATRIZ* mat;


	scanf("%d", &funcionalidade);

	switch(funcionalidade) { //verifica qual funcionalidade inserida e chama a função que a executa
		case 1:
			scanf("%s", arquivoCSV);//Lendo com /0 no final
			scanf("%s", arquivoBIN);//Lendo com /0 no final
			teste_veic(arquivoCSV, arquivoBIN);
			break;

		case 2:
			scanf("%s", arquivoCSV);//Lendo com /0 no final
			scanf("%s", arquivoBIN);//Lendo com /0 no final
			break;

		case 3:
			//leVeiculo("", "");
			break;

		case 4:
			//lelinha("", "");
			break;

		case 5:
			scanf("%s", nomeCampo);//Lendo com /0 no final
			scanf("%s", valorCampo);//Lendo com /0 no final
			break;

		case 6:
			scanf("%s", nomeCampo);//Lendo com /0 no final
			scanf("%s", valorCampo);//Lendo com /0 no final
			//leLinha(parametro, valor);
			break;

		case 7:
			scanf("%s", arquivoBIN);
			scanf("%d", &numeroNovosRegistros);

			int codLinha;
			char aceitaCartao;
			char nomeLinha[200];
			char corLinha[200];

			FILE* arquivoBin;
			arquivoBin = fopen(arquivoBIN, "w+b");

			//insereNRegistrosVeiculo(arquivoBin, numeroNovosRegistros);

			fclose(arquivoBin);
			break;

		case 8:
			scanf("%s", arquivoBIN);
			scanf("%d", &numeroNovosRegistros);

			int codLinha;
			char aceitaCartao;
			char nomeLinha[200];
			char corLinha[200];

			FILE* arquivoBin;
			arquivoBin = fopen(arquivoBIN, "w+b");

			insereNRegistrosLinha(arquivoBin, numeroNovosRegistros);

			fclose(arquivoBin);
			break;

		case 22: //testes
			nome = (char*)malloc(100*sizeof(char));
			scanf("%s",nome);
			FILE* fp;
			fp = open_csv(nome);

			mat = csvToMatrix(fp);
			printMatriz(mat);

			free(nome);
			close_csv(fp);
			freeMatriz(mat);

			break;
	}

	return 0;
}

/*
leNRegistros {
	numeroRegistros: número de registros a serem lidos
	
	retorna uma matriz de strings, cada linha é um registro, cada coluna é um campo
}
*/