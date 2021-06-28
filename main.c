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
#include "btree_cabecalho.h"
#include "btree_registro.h"
#include "btree_algoritimos.h"


//caso de teste prinra 3 registros hardcoded em um arquivo bin
void caso23(char arquivoBinPath[30]){
			
			
			FILE* arquivoBinFP = fopen(arquivoBinPath, "rb");


			BTREE_REGISTRO* reg = criaRegistroBtree();
			BTREE_REGISTRO* reg1 = criaRegistroBtree();
			BTREE_REGISTRO* reg2 = criaRegistroBtree();
			readRegistroBtree(reg,arquivoBinFP,1);
			readRegistroBtree(reg1,arquivoBinFP,2);
			readRegistroBtree(reg2,arquivoBinFP,3);

			TESTEprintRegistroBtree(reg);
			printf("-----------------------------------------------------------------------\n");
			TESTEprintRegistroBtree(reg1);
			printf("-----------------------------------------------------------------------\n");

			TESTEprintRegistroBtree(reg2);
			printf("-----------------------------------------------------------------------\n");

			freeRegistroBtree(reg);
			freeRegistroBtree(reg1);
			freeRegistroBtree(reg2);
			fclose(arquivoBinFP);
}


//caso de teste de busca de chave
void caso24(char arquivoBinPath[30], int chaveProcurada){
	FILE* arquivoBinFP = fopen(arquivoBinPath, "rb");

	int resultado = search(arquivoBinFP,chaveProcurada,-2);

	printf("resultado da busca: %d\n",resultado);

	fclose(arquivoBinFP);
}

int main(int argc, char const *argv[]){
	int funcionalidade = 0;
	int numeroNovosRegistros = 0;

	//char nomeCampo[30];
	//char valorCampo[30];
	char arquivoCsvPath[30];
	char arquivoBinPath[30];
	char *nome;
	MATRIZ* mat;
	int chaveBuscada;


	FILE* arquivoBinFP;
	FILE* arquivoCsvFP;


	scanf("%d", &funcionalidade);

	switch(funcionalidade) { //verifica qual funcionalidade inserida e chama a função que a executa
		case 1:
			scanf("%s", arquivoCsvPath);//Lendo com /0 no final
			scanf("%s", arquivoBinPath);//Lendo com /0 no final
			arquivoCsvFP = open_csv(arquivoCsvPath);

			//arquivoCsvFP = open_csv(arquivoCsvPath);

			arquivoCsvFP = fopen(arquivoCsvPath, "r");	

			if (arquivoCsvFP == NULL)
			{
				printf("Falha no processamento do arquivo.\n");
				return 0;
			}
			
			//teste_veic(arquivoCsvPath, arquivoBinPath);
			mat = csvToMatrix(arquivoCsvFP);
			arquivoBinFP = fopen(arquivoBinPath, "wb");
			VEICULO_CABECALHO cabecalhoV = createVeiculoCabecalho();
			strncpy(cabecalhoV.descrevePrefixo,retorna_elemento(mat,0,0),18);
			strncpy(cabecalhoV.descreveData,retorna_elemento(mat,0,1),35);
			strncpy(cabecalhoV.descreveLugares,retorna_elemento(mat,0,2),42);
			strncpy(cabecalhoV.descreveLinha,retorna_elemento(mat,0,3),26);
			strncpy(cabecalhoV.descreveModelo,retorna_elemento(mat,0,4),17);
			strncpy(cabecalhoV.descreveCategoria,retorna_elemento(mat,0,5),20);
			insereVeiculoCabecalho(arquivoBinFP,&cabecalhoV);
			insereNRegistrosVeiculoMatriz(arquivoBinFP,mat);

			freeMatriz(mat);
			close_csv(arquivoCsvFP);
			binarioNaTela(arquivoBinPath);
			if (arquivoBinFP)
			{
				fclose(arquivoBinFP);
			}
			break;

		case 2:
			scanf("%s", arquivoCsvPath);//Lendo com /0 no final
			scanf("%s", arquivoBinPath);//Lendo com /0 no final
			//arquivoCsvFP = open_csv(arquivoCsvPath);

			arquivoCsvFP = fopen(arquivoCsvPath, "r");	


			if (arquivoCsvFP == NULL)
			{
				printf("Falha no processamento do arquivo.\n");
				return 0;
			}
			
			mat = csvToMatrix(arquivoCsvFP);
			arquivoBinFP = fopen(arquivoBinPath, "wb");

			LINHA_CABECALHO cabecalho = createLinhaCabecalho();
			strncpy(cabecalho.descreveCodigo,retorna_elemento(mat,0,0),15);
			strncpy(cabecalho.descreveCartao,retorna_elemento(mat,0,1),13);
			strncpy(cabecalho.descreveNome,retorna_elemento(mat,0,2),13);
			strncpy(cabecalho.descreveCor,retorna_elemento(mat,0,3),24);
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
			if (arquivoBinFP)
			{
				fclose(arquivoBinFP);
			}
			
			
			break;

		case 4:
			scanf("%s", arquivoBinPath);
			
			arquivoBinFP = fopen(arquivoBinPath, "rb");

			imprimeRegistrosLinha(arquivoBinFP);
			if (arquivoBinFP)
			{
				fclose(arquivoBinFP);
			}
			break;

		case 5:
			scanf("%s", arquivoBinPath);
			
			arquivoBinFP = fopen(arquivoBinPath, "rb");

			buscaParametroVeiculo(arquivoBinFP);
			if (arquivoBinFP)
			{
				fclose(arquivoBinFP);
			}
			break;

		case 6:
			scanf("%s", arquivoBinPath);
			
			arquivoBinFP = fopen(arquivoBinPath, "rb");

			buscaParametroLinha(arquivoBinFP);
			if (arquivoBinFP)
			{
				fclose(arquivoBinFP);
			}
			break;

		case 7:
			scanf("%s", arquivoBinPath);
			scanf("%d", &numeroNovosRegistros);

			arquivoBinFP = fopen(arquivoBinPath, "r+b");

			if(insereNRegistrosVeiculo(arquivoBinFP, numeroNovosRegistros) == 0) printf("Falha no processamento do arquivo.\n");
			else binarioNaTela(arquivoBinPath);

			if (arquivoBinFP)
			{
				fclose(arquivoBinFP);
			}
			break;

		case 8:
			scanf("%s", arquivoBinPath);
			scanf("%d", &numeroNovosRegistros);

			arquivoBinFP = fopen(arquivoBinPath, "r+b");

			if(insereNRegistrosLinha(arquivoBinFP, numeroNovosRegistros) == 0) printf("Falha no processamento do arquivo.\n");
			else binarioNaTela(arquivoBinPath);

			if (arquivoBinFP)
			{
				fclose(arquivoBinFP);
			}
			break;

		case 22:
			// caso de teste
			scanf("%s", arquivoBinPath);
			arquivoBinFP = fopen(arquivoBinPath, "wb");
			BTREE_CABECALHO cabecalhoBtree = createBtreeCabecalho();
			
			cabecalhoBtree.noRaiz = 3;
			cabecalhoBtree.RNNProx = 6;
			insereBtreeCabecalho(arquivoBinFP,&cabecalhoBtree);
			escreveLixo(arquivoBinFP,68,9);
			BTREE_REGISTRO* reg = criaRegistroBtree();
			BTREE_REGISTRO* reg1 = criaRegistroBtree();
			BTREE_REGISTRO* reg2 = criaRegistroBtree();


			for (int i = 0; i < 2; i++)
			{
				setChaveBtree(reg,i,i+1);
				
			}
			setChaveBtree(reg1,0,4);
			setChaveBtree(reg1,1,5);
			setRNNdoNoBtree(reg,1);
			setRNNdoNoBtree(reg1,2);
			setRNNdoNoBtree(reg2,3);
			mudaFolhaBtree(reg,'1');
			mudaFolhaBtree(reg1,'1');
			setnroChavesBtree(reg,2);
			setnroChavesBtree(reg1,2);
			setnroChavesBtree(reg2,1);



			setChaveBtree(reg2,0,3);
			setPonteiroSubArvoreBtree(reg2,0,1);
			setPonteiroSubArvoreBtree(reg2,1,2);
			
			
			TESTEescreveRegistroBtree(reg,arquivoBinFP,1);
			TESTEescreveRegistroBtree(reg1,arquivoBinFP,2);
			TESTEescreveRegistroBtree(reg2,arquivoBinFP,3);

			if (reg)
			{
				freeRegistroBtree(reg);

			}
			freeRegistroBtree(reg1);
			freeRegistroBtree(reg2);

			
			if (arquivoBinFP)
			{
				fclose(arquivoBinFP);
			}
			break;

		case 23:
			//test read
			scanf("%s", arquivoBinPath);
			caso23(arquivoBinPath);
			break;

		case 24:
			
			scanf("%s", arquivoBinPath);
			scanf("%d",&chaveBuscada);
			caso24(arquivoBinPath,chaveBuscada);



	}
	return 0;
}