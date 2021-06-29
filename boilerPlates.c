#include "boilerPlates.h"

/*
    descricao:
        abre um arquivo binario e checa a integridade dele, caso ele não esteja consistente ou não exista retona NULL

    argumentos:
        [in] - char[30] - ArquivoPath

    retono:
        caso sucesso retorna o ponteiro do arquivo, caso não retorna NULL
*/
FILE* abreArquivoBin(char arquivoPath[30],char* mode){
    FILE*  arquivoBinFP;
    arquivoBinFP = fopen(arquivoPath,mode);
    if (arquivoBinFP != NULL)
    {
        fseek(arquivoBinFP,0,SEEK_SET);
        char consistente = '0';
        fread(consistente,1,1,arquivoBinFP);
        if (consistente == '0')
        {
            arquivoBinFP = NULL;
        }
        
    }
    return arquivoBinFP;
}

/*
    descricao:
        verifica se o ponteiro arquivo existe e fecha
    argumentos:
        [in] - FILE* - fp
    retono:
        void
*/  
void fechaArquivoBin(FILE* fp){
    if (fp)
    {
        fclose(fp);
    }
    
}

FILE* abrArquivoBinPrintaERRO(char arquivoPath[30],char* mode){
    FILE* fp = abreArquivoBin(arquivoPath,mode);
    if (!fp)
    {
           printf("Falha no processamento do arquivo.\n"); 
    }
    return fp;
}
