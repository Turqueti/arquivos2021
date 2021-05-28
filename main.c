#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linha_cabecalho.h"
#include "veiculo_cabecalho.h"
#include "linha_registro.h"
#include "veiculo_registro.h"
#include "csvlib.h"
#include "matrizlib.h"

void binarioNaTela(char *nomeArquivoBinario) { /* Você não precisa entender o código dessa função. */

	/* Use essa função para comparação no run.codes. Lembre-se de ter fechado (fclose) o arquivo anteriormente.
	*  Ela vai abrir de novo para leitura e depois fechar (você não vai perder pontos por isso se usar ela). */

	unsigned long i, cs;
	unsigned char *mb;
	size_t fl;
	FILE *fs;
	if(nomeArquivoBinario == NULL || !(fs = fopen(nomeArquivoBinario, "rb"))) {
		fprintf(stderr, "ERRO AO ESCREVER O BINARIO NA TELA (função binarioNaTela): não foi possível abrir o arquivo que me passou para leitura. Ele existe e você tá passando o nome certo? Você lembrou de fechar ele com fclose depois de usar?\n");
		return;
	}
	fseek(fs, 0, SEEK_END);
	fl = ftell(fs);
	fseek(fs, 0, SEEK_SET);
	mb = (unsigned char *) malloc(fl);
	fread(mb, 1, fl, fs);

	cs = 0;
	for(i = 0; i < fl; i++) {
		cs += (unsigned long) mb[i];
	}
	printf("%lf\n", (cs / (double) 100));
	free(mb);
	fclose(fs);
}

int main(int argc, char const *argv[]){
	int funcionalidade = 0;
	int numeroNovosRegistros = 0;

	//char nomeCampo[30];
	//char valorCampo[30];
	char arquivoCSV[30];
	char arquivoBIN[30];
	char *nome;


	char palavra1[MATRIZBUFFERLEN] = "aaaaaaaaaaa";
	char palavra2[MATRIZBUFFERLEN] = "bbbbbbbbbbbb";
	char palavra3[MATRIZBUFFERLEN] = "ccccccccccccc";
	char palavra4[MATRIZBUFFERLEN] = "dddddddddddddd";
	MATRIZ* mat;


	FILE* arquivoBin;


	scanf("%d", &funcionalidade);

	switch(funcionalidade) { //verifica qual funcionalidade inserida e chama a função que a executa
		case 1:
			scanf("%s", arquivoCSV);//Lendo com /0 no final
			scanf("%s", arquivoBIN);//Lendo com /0 no final
			//teste_veic(arquivoCSV, arquivoBIN);
			break;

		case 2:
			scanf("%s", arquivoCSV);//Lendo com /0 no final
			scanf("%s", arquivoBIN);//Lendo com /0 no final
			break;

		case 3:
			scanf("%s", arquivoBIN);
			
			arquivoBin = fopen(arquivoBIN, "rb");

			//imprimeRegistrosVeiculo(arquivoBin);
			fclose(arquivoBin);
			break;

		case 4:
			scanf("%s", arquivoBIN);
			
			arquivoBin = fopen(arquivoBIN, "rb");

			imprimeRegistrosLinha(arquivoBin);
			fclose(arquivoBin);
			break;

		case 5:
			scanf("%s", arquivoBIN);
			
			arquivoBin = fopen(arquivoBIN, "rb");

			//buscaParametroVeiculo(arquivoBin);
			fclose(arquivoBin);
			break;

		case 6:
			scanf("%s", arquivoBIN);
			
			arquivoBin = fopen(arquivoBIN, "rb");

			buscaParametroLinha(arquivoBin);
			fclose(arquivoBin);
			break;

		case 7:
			scanf("%s", arquivoBIN);
			scanf("%d", &numeroNovosRegistros);

			arquivoBin = fopen(arquivoBIN, "r+b");

			//insereNRegistrosVeiculo(arquivoBin, numeroNovosRegistros);

			fclose(arquivoBin);
			break;

		case 8:
			scanf("%s", arquivoBIN);
			scanf("%d", &numeroNovosRegistros);

			arquivoBin = fopen(arquivoBIN, "r+b");

			if(insereNRegistrosLinha(arquivoBin, numeroNovosRegistros) == 0) printf("Falha no processamento do arquivo.\n");
			else binarioNaTela(arquivoBIN);

			fclose(arquivoBin);
			break;
	}
	return 0;
}