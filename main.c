#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linha_cabecalho.h"
#include "veiculo_cabecalho.h"
#include "linha_registro.h"
#include "veiculo_registro.h"
#include "csvlib.h"
#include "matrizlib.h"
#include "binarioNaTela.h"

int main(int argc, char const *argv[]){
	int funcionalidade = 0;
	int numeroNovosRegistros = 0;

	//char nomeCampo[30];
	//char valorCampo[30];
	char arquivoCsvPath[30];
	char arquivoBinPath[30];
	char *nome;
	MATRIZ* mat;


	FILE* arquivoBinFP;
	FILE* arquivoCsvFP;


	scanf("%d", &funcionalidade);

	switch(funcionalidade) { //verifica qual funcionalidade inserida e chama a função que a executa
		case 1:
			scanf("%s", arquivoCsvPath);//Lendo com /0 no final
			scanf("%s", arquivoBinPath);//Lendo com /0 no final

			if (arquivoCsvFP == NULL)
			{
				printf("Falha no processamento do arquivo\n");
				return -1;
			}
			
			//teste_veic(arquivoCsvPath, arquivoBinPath);
			arquivoCsvFP = open_csv(arquivoCsvPath);
			mat = csvToMatrix(arquivoCsvFP);

			close_csv(arquivoCsvFP);
			break;

		case 2:
			scanf("%s", arquivoCsvPath);//Lendo com /0 no final
			scanf("%s", arquivoBinPath);//Lendo com /0 no final
			arquivoCsvFP = open_csv(arquivoCsvPath);

			if (arquivoCsvFP == NULL)
			{
				printf("Falha no processamento do arquivo\n");
				return -1;
			}
			
			mat = csvToMatrix(arquivoCsvFP);
			arquivoBinFP = fopen(arquivoBinPath, "wb");

			LINHA_CABECALHO cabecalho = createLinhaCabecalho();
			strncpy(cabecalho.descreveCodigo,retorna_elemento(mat,0,0),15);
			strncpy(cabecalho.descreveCartao,retorna_elemento(mat,0,1),13);
			strncpy(cabecalho.descreveNome,retorna_elemento(mat,0,2),13);
			strncpy(cabecalho.descreveCor,retorna_elemento(mat,0,3),24);
			cabecalho.nroRegistros = 0;
			insereLinhaCabecalho(arquivoBinFP,&cabecalho);
			insereNRegistrosLinhaMatriz(arquivoBinFP,mat);

			freeMatriz(mat);
			close_csv(arquivoCsvFP);
			binarioNaTela(arquivoBinPath);
			fclose(arquivoBinFP);
			
			break;

		case 3:
			scanf("%s", arquivoBinPath);
			
			arquivoBinFP = fopen(arquivoBinPath, "rb");

			imprimeRegistrosVeiculo(arquivoBinFP);
			fclose(arquivoBinFP);
			break;

		case 4:
			scanf("%s", arquivoBinPath);
			
			arquivoBinFP = fopen(arquivoBinPath, "rb");

			imprimeRegistrosLinha(arquivoBinFP);
			fclose(arquivoBinFP);
			break;

		case 5:
			scanf("%s", arquivoBinPath);
			
			arquivoBinFP = fopen(arquivoBinPath, "rb");

			buscaParametroVeiculo(arquivoBinFP);
			fclose(arquivoBinFP);
			break;

		case 6:
			scanf("%s", arquivoBinPath);
			
			arquivoBinFP = fopen(arquivoBinPath, "rb");

			buscaParametroLinha(arquivoBinFP);
			fclose(arquivoBinFP);
			break;

		case 7:
			scanf("%s", arquivoBinPath);
			scanf("%d", &numeroNovosRegistros);

			arquivoBinFP = fopen(arquivoBinPath, "r+b");

			if(insereNRegistrosVeiculo(arquivoBinFP, numeroNovosRegistros) == 0) printf("Falha no processamento do arquivo.\n");
			else binarioNaTela(arquivoBinPath);

			fclose(arquivoBinFP);
			break;

		case 8:
			scanf("%s", arquivoBinPath);
			scanf("%d", &numeroNovosRegistros);

			arquivoBinFP = fopen(arquivoBinPath, "r+b");

			if(insereNRegistrosLinha(arquivoBinFP, numeroNovosRegistros) == 0) printf("Falha no processamento do arquivo.\n");
			else binarioNaTela(arquivoBinPath);

			fclose(arquivoBinFP);
			break;
	}
	return 0;
}