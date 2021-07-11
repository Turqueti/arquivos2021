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

#define grau 5 


//caso de teste printa 3 registros hardcoded em um arquivo bin
void caso23(char arquivoBinPath[30]){
			
			
			FILE* arquivoBinFP = fopen(arquivoBinPath, "rb");


			BTREE_REGISTRO* reg = criaRegistroBtree(grau);
			BTREE_REGISTRO* reg1 = criaRegistroBtree(grau);
			BTREE_REGISTRO* reg2 = criaRegistroBtree(grau);
			readRegistroBtree(reg,arquivoBinFP,0);
			readRegistroBtree(reg1,arquivoBinFP,1);
			readRegistroBtree(reg2,arquivoBinFP,2);

			TESTEprintRegistroBtree(reg);
			printf("-----------------------------------------------------------------------\n");
			// TESTEprintRegistroBtree(reg1);
			// printf("-----------------------------------------------------------------------\n");

			// TESTEprintRegistroBtree(reg2);
			// printf("-----------------------------------------------------------------------\n");

			freeRegistroBtree(reg);
			freeRegistroBtree(reg1);
			freeRegistroBtree(reg2);
			fclose(arquivoBinFP);
}

//caso de teste de busca de chave
void caso24(char arquivoBinPath[30], int chaveProcurada){
	FILE* arquivoBinFP = fopen(arquivoBinPath, "rb");
	
	int achouFlag = -1;
	int resultado = search(arquivoBinFP,chaveProcurada,-2,&achouFlag);

	printf("achou flag: %d\n",achouFlag);
	printf("resultado da busca: %d\n",resultado);

	fclose(arquivoBinFP);
}

//caso de teste de insercao
void caso25(){
	// BTREE_REGISTRO* reg = criaRegistroBtree(grau);
	// int res = 0;

	// TESTEprintRegistroBtree(reg);
	// printf("---------------------------------------------------\n");

	// res = insertChaveRegistroBtree(reg,1);
	// TESTEprintRegistroBtree(reg);
	// printf("res: %d\n",res);
	// printf("---------------------------------------------------\n");
	// res = insertChaveRegistroBtree(reg,4);
	// TESTEprintRegistroBtree(reg);
	// printf("res: %d\n",res);
	// printf("---------------------------------------------------\n");
	// res = insertChaveRegistroBtree(reg,2);
	// TESTEprintRegistroBtree(reg);
	// printf("res: %d\n",res);
	// printf("---------------------------------------------------\n");
	// res = insertChaveRegistroBtree(reg,3);
	// TESTEprintRegistroBtree(reg);
	// printf("res: %d\n",res);
	// printf("---------------------------------------------------\n");
	// res = insertChaveRegistroBtree(reg,5);
	// TESTEprintRegistroBtree(reg);
	// printf("res: %d\n",res);
	// printf("---------------------------------------------------\n");
	// freeRegistroBtree(reg);

	char arquivoIndicePath[30];
	FILE* arquivoIndiceFP;
	int chave;


	
	scanf("%s", arquivoIndicePath);//Lendo com /0 no final
	scanf("%d", &chave);
	arquivoIndiceFP = fopen(arquivoIndicePath,"r+b");
	// btree_insert(arquivoIndiceFP,chave);
	fclose(arquivoIndiceFP);

}

//caso teste split
void caso26(){
	// BTREE_REGISTRO* reg = criaRegistroBtree(grau);

	// for (int i = 0; i < grau-1; i++)
	// {
	// 	setChaveBtree(reg,i,(i+1)*10);
	// 	setPonteiroSubArvoreBtree(reg,i,i);
		
	// }
	// setPonteiroSubArvoreBtree(reg,4,4);
	// setnroChavesBtree(reg,grau-1);


	char arquivoIndicePath[30];
	FILE* arquivoIndiceFP;
	scanf("%s", arquivoIndicePath);//Lendo com /0 no final
	arquivoIndiceFP = fopen(arquivoIndicePath,"r+b");


	int numChaves;
	scanf("%d",&numChaves);


	for (int i = 0; i < numChaves; i++)
	{
		int chave;
		scanf("%d\n", &chave);
		llint ponteiro;
		scanf("%lld\n",&ponteiro);
		
		
		
		
		int achouFlag = -1;
		//condicao de entrada
		BTREE_CABECALHO cabecalho;
		readBtreeCabecalho(arquivoIndiceFP,&cabecalho);


		int chavePromovida = -1;
		int rnnFilhoDireitoChavePromovida = -1;
		llint ponteiroChvePromovida = -1;

		int promo = -1;
		promo = insert(arquivoIndiceFP,chave,ponteiro,cabecalho.noRaiz,&achouFlag,&rnnFilhoDireitoChavePromovida,&chavePromovida,&ponteiroChvePromovida); //chama a func para o no raiz


		if (promo == 2)
		{
			BTREE_REGISTRO* raizNova = criaRegistroBtree(grau);
			readBtreeCabecalho(arquivoIndiceFP,&cabecalho);
			setPonteiroSubArvoreBtree(raizNova,0,cabecalho.noRaiz);
			cabecalho.noRaiz = cabecalho.RNNProx;
			cabecalho.RNNProx++;
			setRNNdoNoBtree(raizNova,cabecalho.noRaiz);
			insertChaveRegistroEPonteiroArquivoBtreeEFilhoDireito(raizNova,chavePromovida,rnnFilhoDireitoChavePromovida,ponteiroChvePromovida);

			TESTEescreveRegistroBtree(raizNova,arquivoIndiceFP,cabecalho.noRaiz);
			insereBtreeCabecalho(arquivoIndiceFP,&cabecalho);
			fflush(arquivoIndiceFP);
		}
	}
	
	fclose(arquivoIndiceFP);
	// split(chave,-2,reg,-1,-1);
	// freeRegistroBtree(reg);

}



//caso search btree Veiculo
void caso11(){
	char arquivoBinPath[30];
	char arquivoIndicePath[30];


	FILE* arquivoBinFP;
	FILE* arquivoIndiceFP;
	VEICULO_REGISTRO* reg = criaRegistroVeiculo();

	LINHA_REGISTRO registroLinha;

	
	scanf("%s", arquivoBinPath);//Lendo com /0 no final
	scanf("%s", arquivoIndicePath);//Lendo com /0 no final
	arquivoIndiceFP = fopen(arquivoIndicePath,"rb");
	arquivoBinFP = fopen(arquivoBinPath,"rb");
	char prefixoPadding[30];
	scanf("%s", prefixoPadding);//Lendo com /0 no final
	
	char prefixo[5] = "\0";
	scanf("%s", prefixo);

	int chaveProcurada = -1;
	chaveProcurada = convertePrefixo(prefixo);
	
	

	int achouFlag = -1;
	int resultado = search(arquivoIndiceFP,chaveProcurada,-2,&achouFlag);

	// printf("resultado da busca: %d\n",resultado);
	if (achouFlag == 1)
	{
		readRegistroVeiculoByteOffSet(arquivoBinFP,reg,resultado);
		mostrarRegistroVeiculo(arquivoBinFP,reg);
	}else
	{
		printf("Registro inexistente.\n");
	}
	

	freeRegistroVeiculo(reg);
	fclose(arquivoIndiceFP);
	fclose(arquivoBinFP);
}

//caso search btree linha
void caso12(){
	char arquivoBinPath[30];
	char arquivoIndicePath[30];


	FILE* arquivoBinFP;
	FILE* arquivoIndiceFP;
	LINHA_REGISTRO registroLinha;

	
	scanf("%s", arquivoBinPath);//Lendo com /0 no final
	scanf("%s", arquivoIndicePath);//Lendo com /0 no final
	arquivoIndiceFP = fopen(arquivoIndicePath,"rb");
	arquivoBinFP = fopen(arquivoBinPath,"rb");
	char codLinha[30];
	scanf("%s", codLinha);//Lendo com /0 no final
	
	int chaveProcurada;
	scanf("%d",&chaveProcurada);
	

	int achouFlag = -1;
	int resultado = search(arquivoIndiceFP,chaveProcurada,-2,&achouFlag);

	// printf("resultado da busca: %d\n",resultado);
	if (achouFlag == 1)
	{
		readRegistroLinhaByteOffSet(arquivoBinFP,&registroLinha,resultado);
		mostrarRegistroLinha(arquivoBinFP,&registroLinha);
	}else
	{
		printf("Registro inexistente.\n");
	}
	


	fclose(arquivoIndiceFP);
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
		case 11:
			caso11();
			break;
		
		case 12:
			caso12();
			break;

		
		case 22:
			// caso de teste
			scanf("%s", arquivoBinPath);
			arquivoBinFP = fopen(arquivoBinPath, "wb");
			BTREE_CABECALHO cabecalhoBtree = createBtreeCabecalho();
			
			cabecalhoBtree.noRaiz = 0;
			cabecalhoBtree.RNNProx = 1;
			insereBtreeCabecalho(arquivoBinFP,&cabecalhoBtree);
			escreveLixo(arquivoBinFP,68,9);
			BTREE_REGISTRO* reg = criaRegistroBtree(grau);
			BTREE_REGISTRO* reg1 = criaRegistroBtree(grau);
			BTREE_REGISTRO* reg2 = criaRegistroBtree(grau);


			for (int i = 0; i < 5; i++)
			{
				setChaveBtree(reg,i,(i+1)*10);
				setPonteiroRegistroBtree(reg,i,(llint)(i+1)*1000);
				
			}
			setChaveBtree(reg1,0,40);
			setChaveBtree(reg1,1,50);
			setRNNdoNoBtree(reg,0);
			setRNNdoNoBtree(reg1,1);
			setRNNdoNoBtree(reg2,2);
			mudaFolhaBtree(reg,'1');
			mudaFolhaBtree(reg1,'1');
			setnroChavesBtree(reg,4);
			setnroChavesBtree(reg1,2);
			setnroChavesBtree(reg2,1);



			setChaveBtree(reg2,0,30);
			setPonteiroSubArvoreBtree(reg2,0,0);
			setPonteiroSubArvoreBtree(reg2,1,1);
			
			
			TESTEescreveRegistroBtree(reg,arquivoBinFP,0);
			// TESTEescreveRegistroBtree(reg1,arquivoBinFP,1);
			// TESTEescreveRegistroBtree(reg2,arquivoBinFP,2);

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
			break;

		case 25:
			caso25();
			break;

		case 26:
			caso26();
			break;

	}
	return 0;
}