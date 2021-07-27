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
#include "boilerPlates.h"

#define grau 5 


void printT3(VEICULO_REGISTRO* registroVeiculo, LINHA_REGISTRO* registroLinha){
	char vet[5];
	for (int i = 0; i < 5; ++i){
		vet[i] = registroVeiculo->prefixo[i];
	}

	printf("Prefixo do veiculo: %s\n", vet);


	registroVeiculo->modelo[registroVeiculo->tamanhoModelo] = '\0';
	if(strncmp(registroVeiculo->modelo, "",registroVeiculo->tamanhoModelo)) printf("Modelo do veiculo: %s\n", registroVeiculo->modelo);
	else printf("Modelo do veiculo: campo com valor nulo\n");

	registroVeiculo->categoria[registroVeiculo->tamanhoCategoria] = '\0';
	if(strncmp(registroVeiculo->categoria, "",registroVeiculo->tamanhoCategoria)) printf("Categoria do veiculo: %s\n", registroVeiculo->categoria);
	else printf("Categoria do veiculo: campo com valor nulo\n");

	//Rever data
	if(strcmp(registroVeiculo->data, "\0@@@@@@@@@")) printData(registroVeiculo->data); //printf("Data de entrada do veiculo na frota: %s\n", registro->data);
	else printf("Data de entrada do veiculo na frota: campo com valor nulo\n");

	if(registroVeiculo->quantidadeLugares != -1) printf("Quantidade de lugares sentados disponiveis: %d\n", registroVeiculo->quantidadeLugares);
	else printf("Quantidade de lugares sentados disponiveis: campo com valor nulo\n");

	printf("Codigo da linha: %d\n", registroLinha->codLinha);

	registroLinha->nomeLinha[registroLinha->tamanhoNome] = '\0';
	if(strncmp(registroLinha->nomeLinha, "",registroLinha->tamanhoNome)) printf("Nome da linha: %*s\n",registroLinha->tamanhoNome-1 , registroLinha->nomeLinha);
	else printf("Nome da linha: campo com valor nulo\n");

	registroLinha->corLinha[registroLinha->tamanhoCor] = '\0';
	if(strncmp(registroLinha->corLinha, "NULO",registroLinha->tamanhoCor)) printf("Cor que descreve a linha: %s\n", registroLinha->corLinha);
	else printf("Cor que descreve a linha: campo com valor nulo\n");

	if(registroLinha->aceitaCartao == 'S') printf("Aceita cartao: PAGAMENTO SOMENTE COM CARTAO SEM PRESENCA DE COBRADOR\n");
	else if(registroLinha->aceitaCartao == 'N') printf("Aceita cartao: PAGAMENTO EM CARTAO E DINHEIRO\n");
	else if(registroLinha->aceitaCartao == 'F') printf("Aceita cartao: PAGAMENTO EM CARTAO SOMENTE NO FINAL DE SEMANA\n");
	else if(registroLinha->aceitaCartao == '\0') printf("Aceita cartao: campo com valor nulo\n");
	printf("\n");

}

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
	printf("ponteiro: %p\n",arquivoIndiceFP);
	// fseek(arquivoIndiceFP,150,SEEK_SET);
	// llint ponteiro = (llint)ftell(arquivoIndiceFP);
	// printf("%lld",ponteiro);
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
		driver_insert(arquivoIndiceFP,chave,ponteiro);
		
		
		
		
		
	}
	
	fclose(arquivoIndiceFP);
	// split(chave,-2,reg,-1,-1);
	// freeRegistroBtree(reg);

}

//caso cria btree veiculo
void caso9(){
	char arquivoBinPath[30];
	FILE* arquivoBinFP;
	scanf("%s", arquivoBinPath);//Lendo com /0 no final
	arquivoBinFP = abreArquivoBin(arquivoBinPath,"rb");
	if (arquivoBinFP == NULL)
	{
		printf("Falha no processamento do arquivo.\n");
		return;
	}
	

	char arquivoIndicePath[30];
	FILE* arquivoIndiceFP;
	scanf("%s", arquivoIndicePath);//Lendo com /0 no final

    arquivoIndiceFP = fopen(arquivoIndicePath,"r+b");
	
	
	
    
    if (arquivoIndiceFP == NULL)
    {
        arquivoIndiceFP = fopen(arquivoIndicePath,"wb");
        BTREE_CABECALHO cabecalhoBtree = createBtreeCabecalho();
			
        cabecalhoBtree.noRaiz = 0;
        cabecalhoBtree.RNNProx = 1;
        insereBtreeCabecalho(arquivoIndiceFP,&cabecalhoBtree);
        escreveLixo(arquivoIndiceFP,68,9);
        BTREE_REGISTRO* reg = criaRegistroBtree(grau);
		
		
		VEICULO_CABECALHO cabecalho = createVeiculoCabecalho();
		readVeiculoCabecalho(arquivoBinFP, &cabecalho);
		
		
		
		VEICULO_REGISTRO* registroTemp = criaRegistroVeiculo();
		char* prefixTemp = (char*)malloc(sizeof(char)*5);
		int chaveTemp = -1;


		if (readRegistroVeiculo(arquivoBinFP, registroTemp) != 0)
		{
				retornaPrefixo(registroTemp,prefixTemp);
				chaveTemp = convertePrefixo(prefixTemp);
				setChaveBtree(reg,0,chaveTemp);
				setPonteiroRegistroBtree(reg,0,ftell(arquivoBinFP));
				setRNNdoNoBtree(reg,0);
				mudaFolhaBtree(reg,'0');
				TESTEescreveRegistroBtree(reg,arquivoIndiceFP,0);
			
		}
		
		free(prefixTemp);
		freeRegistroVeiculo(registroTemp);
		

    }else
	{
		VEICULO_CABECALHO cabecalho = createVeiculoCabecalho();
		readVeiculoCabecalho(arquivoBinFP, &cabecalho);
		if (!checkaIntegridade(arquivoIndiceFP))
		{
			printf("Falha no processamento do arquivo.\n");
			return;
		}
	}	
	

	int n = 0;
	llint ponteiroArquivoDados = ftell(arquivoBinFP);


	VEICULO_REGISTRO* registro = criaRegistroVeiculo();
	char* prefix = (char*)malloc(sizeof(char)*5);
	int chave = -1;

	while(readRegistroVeiculo(arquivoBinFP, registro) != 0) {
			if(registroVeiculoRemovido(registro)){
				// mostrarRegistroVeiculo(arquivoIndiceFP, &registro);
				retornaPrefixo(registro,prefix);
				chave = convertePrefixo(prefix);
				driver_insert(arquivoIndiceFP,chave,ponteiroArquivoDados);
				ponteiroArquivoDados = ftell(arquivoBinFP);
				n++;
			}
	}



	binarioNaTela(arquivoIndicePath);

	freeRegistroVeiculo(registro);
	free(prefix);
	fechaArquivoBin(arquivoIndiceFP);
	fechaArquivoBin(arquivoBinFP);
}

//caso cria btree linha
void caso10(){


	char arquivoBinPath[30];
	FILE* arquivoBinFP;
	scanf("%s", arquivoBinPath);//Lendo com /0 no final
	arquivoBinFP = abreArquivoBin(arquivoBinPath,"rb");
	if (arquivoBinFP == NULL)
	{
		printf("Falha no processamento do arquivo.\n");
		return;
	}
	

	char arquivoIndicePath[30];
	FILE* arquivoIndiceFP;
	scanf("%s", arquivoIndicePath);//Lendo com /0 no final

    arquivoIndiceFP = fopen(arquivoIndicePath,"r+b");
	
	
	
    
    if (arquivoIndiceFP == NULL)
    {
        arquivoIndiceFP = fopen(arquivoIndicePath,"wb");
        BTREE_CABECALHO cabecalhoBtree = createBtreeCabecalho();
			
        cabecalhoBtree.noRaiz = 0;
        cabecalhoBtree.RNNProx = 1;
        insereBtreeCabecalho(arquivoIndiceFP,&cabecalhoBtree);
        escreveLixo(arquivoIndiceFP,68,9);
        BTREE_REGISTRO* reg = criaRegistroBtree(grau);
		LINHA_CABECALHO cabecalho = createLinhaCabecalho();
		readLinhaCabecalho(arquivoBinFP, &cabecalho);
		LINHA_REGISTRO registro;
		if (readRegistroLinha(arquivoBinFP, &registro) != 0)
		{
				setChaveBtree(reg,0,registro.codLinha);
				setPonteiroRegistroBtree(reg,0,ftell(arquivoBinFP));
				setRNNdoNoBtree(reg,0);
				mudaFolhaBtree(reg,'0');
				TESTEescreveRegistroBtree(reg,arquivoIndiceFP,0);
			
		}
		

		

    }else
	{
		LINHA_CABECALHO cabecalho = createLinhaCabecalho();
		readLinhaCabecalho(arquivoBinFP, &cabecalho);
		if (!checkaIntegridade(arquivoIndiceFP))
		{
			printf("Falha no processamento do arquivo.\n");
			return;
		}
	}	
	
	LINHA_REGISTRO registro;

	int n = 0;
	llint ponteiroArquivoDados = ftell(arquivoBinFP);

	while(readRegistroLinha(arquivoBinFP, &registro) != 0) {
			if(registro.removido == '1'){
				// mostrarRegistroLinha(arquivoBinFP, &registro);
				driver_insert(arquivoIndiceFP,registro.codLinha,ponteiroArquivoDados);
				ponteiroArquivoDados = ftell(arquivoBinFP);
				n++;
			}
	}


	binarioNaTela(arquivoIndicePath);

	fechaArquivoBin(arquivoIndiceFP);
	fechaArquivoBin(arquivoBinFP);
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
	scan_quote_string(prefixo);

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

//caso insert registro novo Veiculo
void caso13(){
	char arquivoBinPath[30];
	FILE* arquivoBinFP;
	scanf("%s", arquivoBinPath);//Lendo com /0 no final
	arquivoBinFP = abreArquivoBin(arquivoBinPath,"rb");
	if (arquivoBinFP == NULL)
	{
		printf("Falha no processamento do arquivo.\n");
		return;
	}

	char arquivoIndicePath[30];
	FILE* arquivoIndiceFP;
	scanf("%s", arquivoIndicePath);//Lendo com /0 no final
    arquivoIndiceFP = abreArquivoBin(arquivoIndicePath,"r+b");
	if (arquivoIndiceFP == NULL){
		printf("Falha no processamento do arquivo.\n");
		return;
	}
	
	
	int numRegistros;
	scanf("%d\n",&numRegistros);

	int numeroNovosRegistros = numRegistros;

	int proxByte;
	int nRegistros = 0;
    
	VEICULO_CABECALHO cabecalho = createVeiculoCabecalho();
	readVeiculoCabecalho(arquivoBinFP, &cabecalho);
	proxByte = cabecalho.byteProxReg;
	nRegistros = cabecalho.nroRegistros;


	llint ponteiroArquivoDados = (llint)proxByte;



	char* prefix = (char*)malloc(sizeof(char)*5);
	int chave = -1;


	

	while(numRegistros != 0) {
			VEICULO_REGISTRO* registro = readRegistroVeiculoStdin();
			if(registroVeiculoRemovido(registro)){
				// mostrarRegistroVeiculo(arquivoIndiceFP, registro);
				retornaPrefixo(registro,prefix);
				chave = convertePrefixo(prefix);
				
				driver_insert(arquivoIndiceFP,chave,ponteiroArquivoDados);
				ponteiroArquivoDados += retornaTamanhoRegistroVeiculo(registro)+5;
				numRegistros--;

				insereRegistroVeiculo(arquivoBinFP, registro);
				proxByte += retornaTamanhoRegistroVeiculo(registro)+5;
			}
			freeRegistroVeiculo(registro);
	}
	setByteOffsetVeiculo(arquivoBinFP, proxByte);
	setNRegistrosVeiculo(arquivoBinFP, nRegistros+numeroNovosRegistros);
	mudaStatusCabecalhoVeiculo(arquivoBinFP, '1');


	

	
	free(prefix);
	fechaArquivoBin(arquivoIndiceFP);
	fechaArquivoBin(arquivoBinFP);

	binarioNaTela(arquivoIndicePath);
}

//caso insert registro novo Linha
void caso14(){
	char arquivoBinPath[30];
	FILE* arquivoBinFP;
	scanf("%s", arquivoBinPath);//Lendo com /0 no final
	arquivoBinFP = abreArquivoBin(arquivoBinPath,"rb");
	if (arquivoBinFP == NULL)
	{
		printf("Falha no processamento do arquivo.\n");
		return;
	}

	char arquivoIndicePath[30];
	FILE* arquivoIndiceFP;
	scanf("%s", arquivoIndicePath);//Lendo com /0 no final
    arquivoIndiceFP = abreArquivoBin(arquivoIndicePath,"r+b");
	if (arquivoIndiceFP == NULL){
		printf("Falha no processamento do arquivo.\n");
		return;
	}
	
	
	int numRegistros;
	scanf("%d\n",&numRegistros);

	int numeroNovosRegistros = numRegistros;

	int proxByte;
	int nRegistros = 0;
    
	LINHA_CABECALHO cabecalho = createLinhaCabecalho();
	readLinhaCabecalho(arquivoBinFP, &cabecalho);
	proxByte = cabecalho.byteProxReg;
	nRegistros = cabecalho.nroRegistros;


	llint ponteiroArquivoDados = (llint)proxByte;

	int chave = -1;

	while(numRegistros != 0) {
			LINHA_REGISTRO registro = readRegistroLinhaStdin();
			
			if(registro.removido == '1'){
				chave = registro.codLinha;
				
				// printf("chave: %d\n",chave);
				// mostrarRegistroLinha(arquivoBinFP,&registro);

				driver_insert(arquivoIndiceFP,chave,ponteiroArquivoDados);
				ponteiroArquivoDados += registro.tamanhoRegistro+5;
				

				insereRegistroLinha(arquivoBinFP, &registro);
				proxByte += registro.tamanhoRegistro+5;
			}
			numRegistros--;
	}
	setByteOffsetLinha(arquivoBinFP, proxByte);
	setNRegistrosLinha(arquivoBinFP, nRegistros+numeroNovosRegistros);
	mudaStatusCabecalhoLinha(arquivoBinFP, '1');


	fechaArquivoBin(arquivoIndiceFP);
	fechaArquivoBin(arquivoBinFP);

	binarioNaTela(arquivoIndicePath);
}

//15 veiculo1.bin linha2.bin codLinha codLinha
int mergeVeiculoLinha_15(FILE *veiculo, FILE *linha) {
	VEICULO_CABECALHO cabecalhoVeiculo = createVeiculoCabecalho();
	readVeiculoCabecalho(veiculo, &cabecalhoVeiculo);
	VEICULO_REGISTRO* registroVeiculo = criaRegistroVeiculo();
	if(cabecalhoVeiculo.status != '1') return 0;

	LINHA_CABECALHO cabecalhoLinha = createLinhaCabecalho();
	readLinhaCabecalho(linha, &cabecalhoLinha);
	LINHA_REGISTRO* registroLinha = criaRegistroLinha();
	if(cabecalhoLinha.status != '1') return 0;
	

	int qntd = 0;
	while(readRegistroVeiculo(veiculo, registroVeiculo) != 0) {
		LINHA_CABECALHO cabecalhoLinha = createLinhaCabecalho();
		readLinhaCabecalho(linha, &cabecalhoLinha);
		
		while(readRegistroLinha(linha, registroLinha) != 0) {
			if(registroVeiculo->codLinha == registroLinha->codLinha && registroVeiculo->removido == '1' && registroLinha->removido == '1') {
				
				char vet[5];
				for (int i = 0; i < 5; ++i){
					vet[i] = registroVeiculo->prefixo[i];
				}

				printf("Prefixo do veiculo: %s\n", vet);

				registroVeiculo->modelo[registroVeiculo->tamanhoModelo] = '\0';
				if(strcmp(registroVeiculo->modelo, "")) printf("Modelo do veiculo: %s\n", registroVeiculo->modelo);
				else printf("Modelo do veiculo: campo com valor nulo\n");

				registroVeiculo->categoria[registroVeiculo->tamanhoCategoria] = '\0';
				if(strcmp(registroVeiculo->categoria, "")) printf("Categoria do veiculo: %s\n", registroVeiculo->categoria);
				else printf("Categoria do veiculo: campo com valor nulo\n");

				//Rever data
				if(strcmp(registroVeiculo->data, "\0@@@@@@@@@")) printData(registroVeiculo->data); //printf("Data de entrada do veiculo na frota: %s\n", registro->data);
				else printf("Data de entrada do veiculo na frota: campo com valor nulo\n");

				if(registroVeiculo->quantidadeLugares != -1) printf("Quantidade de lugares sentados disponiveis: %d\n", registroVeiculo->quantidadeLugares);
				else printf("Quantidade de lugares sentados disponiveis: campo com valor nulo\n");

				printf("Codigo da linha: %d\n", registroLinha->codLinha);

				registroLinha->nomeLinha[registroLinha->tamanhoNome] = '\0';
				if(strcmp(registroLinha->nomeLinha, "")) printf("Nome da linha: %s\n", registroLinha->nomeLinha);
				else printf("Nome da linha: campo com valor nulo\n");

				registroLinha->corLinha[registroLinha->tamanhoCor] = '\0';
				if(strcmp(registroLinha->corLinha, "NULO")) printf("Cor que descreve a linha: %s\n", registroLinha->corLinha);
				else printf("Cor que descreve a linha: campo com valor nulo\n");

				if(registroLinha->aceitaCartao == 'S') printf("Aceita cartao: PAGAMENTO SOMENTE COM CARTAO SEM PRESENCA DE COBRADOR\n");
				else if(registroLinha->aceitaCartao == 'N') printf("Aceita cartao: PAGAMENTO EM CARTAO E DINHEIRO\n");
				else if(registroLinha->aceitaCartao == 'F') printf("Aceita cartao: PAGAMENTO EM CARTAO SOMENTE NO FINAL DE SEMANA\n");
				else if(registroLinha->aceitaCartao == '\0') printf("Aceita cartao: campo com valor nulo\n");
				printf("\n");

				qntd++;
			}
		}
		
		fseek(linha, 0, SEEK_SET);
	}

	if(qntd == 0) printf("Registro inexistente.\n");

	return 1;
}


int mergeVeiculoLinha_16(FILE* arquivoVeiculoFP, FILE* arquivoLinhaFP,FILE* arquivoIndiceLinhaFP){
	
	
	VEICULO_CABECALHO cabecalhoVeiculo = createVeiculoCabecalho();
	readVeiculoCabecalho(arquivoVeiculoFP, &cabecalhoVeiculo);
	VEICULO_REGISTRO* registroVeiculo = criaRegistroVeiculo();
	if(cabecalhoVeiculo.status != '1') return 0;

	LINHA_CABECALHO cabecalhoLinha = createLinhaCabecalho();
	readLinhaCabecalho(arquivoLinhaFP, &cabecalhoLinha);
	
	if(cabecalhoLinha.status != '1') return 0;
	

	int qntd = 0;
	while(readRegistroVeiculo(arquivoVeiculoFP, registroVeiculo) != 0) {
		

		LINHA_CABECALHO cabecalhoLinha = createLinhaCabecalho();
		readLinhaCabecalho(arquivoLinhaFP, &cabecalhoLinha);
		
		int achouFlag = -1;
		int chave = registroVeiculo->codLinha;
		if (chave != -1 && registroVeiculo->removido == '1')
		{
			int resultado = search(arquivoIndiceLinhaFP,chave,-2,&achouFlag);
			if (achouFlag == 1)
			{
				LINHA_REGISTRO* registroLinha = criaRegistroLinha();
				readRegistroLinhaByteOffSet(arquivoLinhaFP,registroLinha,resultado);
				
				// mostrarRegistroLinha(arquivoBinFP,&registroLinha);
				if (registroLinha->removido == '1')
				{
					printT3(registroVeiculo,registroLinha);
				}
				
				
			
				// freeRegistroLinha(registroLinha);
				qntd++;
			}
		}
		

		
		
		
		fseek(arquivoLinhaFP, 0, SEEK_SET);
		// freeRegistroVeiculo(registroVeiculo);
		registroVeiculo = criaRegistroVeiculo();
	}

	// if (registroVeiculo)
	// {
	// 	// freeRegistroVeiculo(registroVeiculo);
	// }
	

	if(qntd == 0) printf("Registro inexistente.\n");

	return 1;

}

//16 veiculo.bin linha.bin nomeCampoVeiculo nomeCampoLinha indice linha
int caso16(){
	char arquivoVeiculoPath[30];
	FILE* arquivoVeiculoFP;

	char arquivoLinhaPath[30];
	FILE* arquivoLinhaFP;

	char nomeCampoVeiculo[30];
	char nomeCampoLinha[30];

	char arquivoIndiceLinhaPath[30];
	FILE* arquivoIndiceLinhaFP;


	scanf("%s", arquivoVeiculoPath);
	arquivoVeiculoFP = abreArquivoBin(arquivoVeiculoPath,"rb");
	if (arquivoVeiculoFP == NULL){
		printf("Falha no processamento do arquivo.\n");
		return 0;
	}

	scanf("%s", arquivoLinhaPath);
	arquivoLinhaFP = abreArquivoBin(arquivoLinhaPath,"rb");
	if (arquivoLinhaFP == NULL){
		printf("Falha no processamento do arquivo.\n");
		return 0;
	}



	scanf("%s", nomeCampoVeiculo);
	scanf("%s", nomeCampoLinha);


	scanf("%s", arquivoIndiceLinhaPath);
	arquivoIndiceLinhaFP = abreArquivoBin(arquivoIndiceLinhaPath,"rb");
	if (arquivoIndiceLinhaFP == NULL){
		printf("Falha no processamento do arquivo.\n");
		return 0;
	}

	if(mergeVeiculoLinha_16(arquivoVeiculoFP, arquivoLinhaFP,arquivoIndiceLinhaFP) == 0) printf("Falha no processamento do arquivo.\n");

	if (arquivoVeiculoFP) fclose(arquivoVeiculoFP);
	if (arquivoLinhaFP) fclose(arquivoLinhaFP);
	if (arquivoIndiceLinhaFP) fclose(arquivoIndiceLinhaFP);



}

//compara os dados da struct linha funcao aux q sort
int compararLinha(const void *x, const void *y){
  int pri = ((LINHA_REGISTRO*)x)->codLinha;
  int seg = ((LINHA_REGISTRO*)y)->codLinha;
  return (pri - seg);
}

int compararVeiculo(const void *x, const void *y){
  int pri = ((VEICULO_REGISTRO*)x)->codLinha;
  int seg = ((VEICULO_REGISTRO*)y)->codLinha;
  return (pri - seg);
}

//17 veiculo3.bin veiculo3Ordenado.bin codLinha
int ordenaVeiculos_17(FILE *veiculo, FILE *ordenado) {
	//copia todos os registros para um vetor de registros
	VEICULO_CABECALHO cabecalho = createVeiculoCabecalho();
	readVeiculoCabecalho(veiculo, &cabecalho);
	if(cabecalho.status != '1') return 0;

	cabecalho.status = '0';
	cabecalho.byteProxReg = 175;
	cabecalho.nroRegRemovidos = 0;

	insereVeiculoCabecalho(ordenado, &cabecalho);

	VEICULO_REGISTRO* registroVeiculo = criaRegistroVeiculo();

	VEICULO_REGISTRO** vetorRegistros = malloc(cabecalho.nroRegistros * sizeof(VEICULO_REGISTRO));
	for (int i = 0; i < cabecalho.nroRegistros; ++i) {
		vetorRegistros[i] = criaRegistroVeiculo();
	}

	int i = 0, tam = 0;
	while(readRegistroVeiculo(veiculo, registroVeiculo) != 0) {
		if(registroVeiculo->removido == '1'){//Se não for removido então copia para vetor na RAM
		    vetorRegistros[i]->removido = registroVeiculo->removido;
		    vetorRegistros[i]->tamanhoRegistro = registroVeiculo->tamanhoRegistro;
		    strcpy(vetorRegistros[i]->prefixo, registroVeiculo->prefixo);
		    strcpy(vetorRegistros[i]->data, registroVeiculo->data);
		    vetorRegistros[i]->quantidadeLugares = registroVeiculo->quantidadeLugares;
		    vetorRegistros[i]->codLinha = registroVeiculo->codLinha;
		    vetorRegistros[i]->tamanhoModelo = registroVeiculo->tamanhoModelo;
		    vetorRegistros[i]->tamanhoCategoria = registroVeiculo->tamanhoCategoria;

			vetorRegistros[i]->modelo = (char*) malloc(sizeof(char) * registroVeiculo->tamanhoModelo+1);
			strcpy(vetorRegistros[i]->modelo, registroVeiculo->modelo);

			vetorRegistros[i]->categoria = (char*) malloc(sizeof(char) * registroVeiculo->tamanhoCategoria);
			strcpy(vetorRegistros[i]->categoria, registroVeiculo->categoria);

			tam++;
			i++;
		}
	}

	
	//ordena o vetor de registros por codLinha
	/*for (int i = 0; i < cabecalho.nroRegistros-1; ++i) {
		int min = i;
		for (int j = i+1; j < cabecalho.nroRegistros; ++j)
			if (vetorRegistros[j]->codLinha < vetorRegistros[min]->codLinha)  min = j;
		int x = vetorRegistros[i]->codLinha; vetorRegistros[i]->codLinha = vetorRegistros[min]->codLinha; vetorRegistros[min]->codLinha = x;
	}*/
	qsort(vetorRegistros, cabecalho.nroRegistros, sizeof(VEICULO_REGISTRO), compararVeiculo);

	//Escrever registro por registro no arquivo .bin ordenado
   	insereVeiculoCabecalho(ordenado, &cabecalho);
   	insereVeiculoCabecalho(ordenado, &cabecalho);
    for (int i = 0; i < tam; ++i) {
    	mostrarRegistroVeiculo(ordenado, vetorRegistros[i]);
    	cabecalho.byteProxReg += vetorRegistros[i]->tamanhoRegistro + 5;
    	insereRegistroVeiculo(ordenado, vetorRegistros[i]);
	}
	cabecalho.status = '1';
	insereVeiculoCabecalho(ordenado, &cabecalho);
	return 1;
}

int ordenaLinhas_18(FILE *linha, FILE *ordenado) {
	//copia todos os registros para um vetor de registros
	LINHA_CABECALHO cabecalho = createLinhaCabecalho();
	readLinhaCabecalho(linha, &cabecalho);
	if(cabecalho.status != '1') return 0;

	cabecalho.status = '0';
	cabecalho.byteProxReg = 82;
	cabecalho.nroRegRemovidos = 0;

	insereLinhaCabecalho(ordenado, &cabecalho);
	
	LINHA_REGISTRO* registroLinha = criaRegistroLinha();

	LINHA_REGISTRO** vetorRegistros = malloc(cabecalho.nroRegistros * sizeof(LINHA_REGISTRO));
	for (int i = 0; i < cabecalho.nroRegistros; ++i) {
		vetorRegistros[i] = criaRegistroLinha();
	}

	int i = 0, tam = 0;
	while(readRegistroLinha(linha, registroLinha) != 0) {
		if(registroLinha->removido == '1'){//Se não for removido então copia para vetor na RAM
			vetorRegistros[i]->removido = registroLinha->removido;
			vetorRegistros[i]->tamanhoRegistro = registroLinha->tamanhoRegistro;
			vetorRegistros[i]->codLinha = registroLinha->codLinha;
			vetorRegistros[i]->aceitaCartao = registroLinha->aceitaCartao;
			vetorRegistros[i]->tamanhoNome = registroLinha->tamanhoNome;
			vetorRegistros[i]->tamanhoCor = registroLinha->tamanhoCor;
			

			vetorRegistros[i]->corLinha = (char*) malloc(sizeof(char) * registroLinha->tamanhoCor);
			strcpy(vetorRegistros[i]->corLinha, registroLinha->corLinha);

			vetorRegistros[i]->nomeLinha = (char*) malloc(sizeof(char) * registroLinha->tamanhoNome+1);
			strcpy(vetorRegistros[i]->nomeLinha, registroLinha->nomeLinha);
			
			tam++;
			i++;
		}
	}

	
	//ordena o vetor de registros por codLinha
	/*for (int i = 0; i < cabecalho.nroRegistros-1; ++i) {
		int min = i;
		for (int j = i+1; j < cabecalho.nroRegistros; ++j)
			if (vetorRegistros[j]->codLinha < vetorRegistros[min]->codLinha)  min = j;
		int x = vetorRegistros[i]->codLinha; vetorRegistros[i]->codLinha = vetorRegistros[min]->codLinha; vetorRegistros[min]->codLinha = x;
	}*/
	qsort(vetorRegistros, cabecalho.nroRegistros, sizeof(LINHA_REGISTRO), compararLinha);

	//Escrever registro por registro no arquivo .bin ordenado
	insereLinhaCabecalho(ordenado, &cabecalho);
	insereLinhaCabecalho(ordenado, &cabecalho);
    for (int i = 0; i < tam; ++i) {
    	cabecalho.byteProxReg += vetorRegistros[i]->tamanhoRegistro + 5;
    	insereRegistroLinha(ordenado, vetorRegistros[i]);
    	//mostrarRegistroLinha(ordenado, vetorRegistros[i]);
    	free(vetorRegistros[i]->corLinha);
    	free(vetorRegistros[i]->nomeLinha);
	}

	cabecalho.status = '1';
	insereLinhaCabecalho(ordenado, &cabecalho);
	return 1;
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

	

	//Referentes ao T3
	char arquivoVeiculoPath[30];
	FILE* arquivoVeiculoFP;

	char arquivoLinhaPath[30];
	FILE* arquivoLinhaFP;

	char nomeCampoVeiculo[30];
	char nomeCampoLinha[30];



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

		case 9:
			caso9();
		break;
		case 10:
			caso10();
		break;

		case 11:
			caso11();
			break;
		
		case 12:
			caso12();
			break;
		case 13:
			caso13();
			break;
		case 14:
			caso14();
			break;
		case 15:
			scanf("%s", arquivoVeiculoPath);
			arquivoVeiculoFP = abreArquivoBin(arquivoVeiculoPath,"rb");
			if (arquivoVeiculoFP == NULL){
				printf("Falha no processamento do arquivo.\n");
				return 0;
			}

			scanf("%s", arquivoLinhaPath);
			arquivoLinhaFP = abreArquivoBin(arquivoLinhaPath,"rb");
			if (arquivoLinhaFP == NULL){
				printf("Falha no processamento do arquivo.\n");
				return 0;
			}

			scanf("%s", nomeCampoVeiculo);
			scanf("%s", nomeCampoLinha);

			if(mergeVeiculoLinha_15(arquivoVeiculoFP, arquivoLinhaFP) == 0) printf("Falha no processamento do arquivo.\n");

			if (arquivoVeiculoFP) fclose(arquivoVeiculoFP);
			if (arquivoLinhaFP) fclose(arquivoLinhaFP);

			break;
		case 16:
			caso16();

			break;
		case 17:
			scanf("%s", arquivoVeiculoPath);
			
			arquivoVeiculoFP = fopen(arquivoVeiculoPath, "rb");
			if (arquivoVeiculoFP == NULL){
				printf("Falha no processamento do arquivo.\n");
				return 0;
			}

			scanf("%s", arquivoLinhaPath);//Os testes com os casos abertos funcionam disponíveis, e no run.codes parece que ele não encontrou o arquivo. O que leva a crer que o run.codes está com os títulos diferentes do buscado(assim como os casos de teste) 
			arquivoLinhaFP = fopen(arquivoLinhaPath, "wb");
			if (arquivoLinhaFP == NULL){
				printf("Falha no processamento do arquivo.\n");
				return 0;
			}
			
			scanf("%s", nomeCampoVeiculo);

			if(ordenaVeiculos_17(arquivoVeiculoFP, arquivoLinhaFP) == 0) printf("Falha no processamento do arquivo.\n");

			if (arquivoVeiculoFP) fclose(arquivoVeiculoFP);
			if (arquivoLinhaFP) fclose(arquivoLinhaFP);

			binarioNaTela(arquivoLinhaPath);	

			break;
		case 18:
			//Ordene linhas em um novo arquivo
			scanf("%s", arquivoLinhaPath);
			arquivoLinhaFP = fopen(arquivoLinhaPath, "rb");
			if (arquivoLinhaFP == NULL){
				printf("Falha no processamento do arquivo.\n");
				return 0;
			}

			scanf("%s", arquivoVeiculoPath);//Os testes com os casos abertos funcionam disponíveis, e no run.codes parece que ele não encontrou o arquivo. O que leva a crer que o run.codes está com os títulos diferentes do buscado(assim como os casos de teste)
			arquivoVeiculoFP = fopen(arquivoVeiculoPath, "wb");
			if (arquivoVeiculoFP == NULL){
				printf("Falha no processamento do arquivo.\n");
				return 0;
			}

			
			scanf("%s", nomeCampoVeiculo);

			if(ordenaLinhas_18(arquivoLinhaFP, arquivoVeiculoFP) == 0) {
				printf("Falha no processamento do arquivo.\n");
				return 0;
			}

			if (arquivoVeiculoFP) fclose(arquivoVeiculoFP);
			if (arquivoLinhaFP) fclose(arquivoLinhaFP);

			binarioNaTela(arquivoVeiculoPath);
			break;
		case 19:
			//Procurar linha.cod = cod.cod
			//Use junção  ordenação-intercalação

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