#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
	int funcionalidade = 0;
	int numeroRegistros = 0;
	char *nomeCampo;
	char *valorCampo;


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
	}

	return 0;
}

/*
leNRegistros {
	numeroRegistros: número de registros a serem lidos
	
	retorna uma matriz de strings, cada linha é um registro, cada coluna é um campo
}
*/