#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csvlib.h"
#include "matrizlib.h"

int main(int argc, char const *argv[]){
	int funcionalidade = 0;
	int numeroRegistros = 0;
	char *nomeCampo;
	char *valorCampo;
	char* nome;


	char palavra1[MATRIZBUFFERLEN] = "aaaaaaaaaaa";
	char palavra2[MATRIZBUFFERLEN] = "bbbbbbbbbbbb";
	char palavra3[MATRIZBUFFERLEN] = "ccccccccccccc";
	char palavra4[MATRIZBUFFERLEN] = "dddddddddddddd";

	MATRIZ* mat = allocaMatriz(2,2);


	scanf("%d", &funcionalidade);

	switch(funcionalidade) { //verifica qual funcionalidade inserida e chama a função que a executa
		case 1:
			//criaBinarioVeiculo();
			break;

		case 2:
			//criaBinarioLinha();
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

			//leVeiculo(parametro, valor);
			break;

		case 6:
			scanf("%s", nomeCampo);//Lendo com /0 no final
			scanf("%s", valorCampo);//Lendo com /0 no final

			//leLinha(parametro, valor);
			break;

		case 7:
			scanf("%d", &numeroRegistros);
			//leNRegistros(numeroRegistros);
			//insereVeiculo();
			break;

		case 8:
			scanf("%d", &numeroRegistros);
			//leNRegistros(numeroRegistros);
			//insereLinha();
			break;
		case 22: //testes
			
			// nome = (char*)malloc(100*sizeof(char));
			// scanf("%s",nome);
			// FILE* fp;
			// fp = open_csv(nome);

			// csvToMatrix(fp);

			// free(nome);
			// close_csv(fp);
			
			inserePalavra(mat,0,0,palavra1);
			inserePalavra(mat,0,1,palavra2);
			inserePalavra(mat,1,0,palavra3);
			inserePalavra(mat,1,1,palavra4);
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