#ifndef BOILERPLATES_H
#define BOILERPLATES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE* abreArquivoBin(char arquivoPath[30],char* mode);
int checkaIntegridade(FILE* arquivoBinFP);
void fechaArquivoBin(FILE* fp);
FILE* abrArquivoBinPrintaERRO(char arquivoPath[30],char* mode);

#endif
