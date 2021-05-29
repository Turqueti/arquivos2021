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


	char palavra1[MATRIZBUFFERLEN] = "aaaaaaaaaaa";
	char palavra2[MATRIZBUFFERLEN] = "bbbbbbbbbbbb";
	char palavra3[MATRIZBUFFERLEN] = "ccccccccccccc";
	char palavra4[MATRIZBUFFERLEN] = "dddddddddddddd";
	MATRIZ* mat;


	FILE* arquivoBinFP;


	scanf("%d", &funcionalidade);

	switch(funcionalidade) { //verifica qual funcionalidade inserida e chama a função que a executa
		case 1:
			scanf("%s", arquivoCsvPath);//Lendo com /0 no final
			scanf("%s", arquivoBinPath);//Lendo com /0 no final
			//teste_veic(arquivoCsvPath, arquivoBinPath);
			break;

		case 2:
			scanf("%s", arquivoCsvPath);//Lendo com /0 no final
			scanf("%s", arquivoBinPath);//Lendo com /0 no final
			break;

		case 3:
			scanf("%s", arquivoBinPath);
			
			arquivoBinFP = fopen(arquivoBinPath, "rb");

			//imprimeRegistrosVeiculo(arquivoBinFP);
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

			//buscaParametroVeiculo(arquivoBinFP);
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

			//insereNRegistrosVeiculo(arquivoBinFP, numeroNovosRegistros);

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