#include "veiculo_cabecalho.h"

struct _veiculo_cabecalho {
    char status;
    int byteProxReg;
    int nroRegistros;
    int nroRegRemovidos;
    char descrevePrefixo[18];
    char descreveData[35];
    char descreveLugares[42];
    char descreveLinha[26];
    char descreveModelo[17];
    char descreveCategoria[20];
};

/*
    Descricao:
        essa func cria um cabecalho do arquivo linha
    
    Argumentos:
        [in]arquivoBin: arquivo binário que foi criado
                OBS: Não realiza fopen nem fclose
        [in]cabecalho: struct de cabecalho que foi criado e preenchido

    Retorno:
        se tudo der certo retorna 1 se algo der errado retorna 0
*/
int create_veiculo_cabecalho(FILE *arquivoBin, VEICULO_CABECALHO *cabecalho) {
    if (arquivoBin == NULL) return 0;

    fseek(arquivoBin, 0, SEEK_SET);
    fwrite(&cabecalho->status, sizeof(char), 1, arquivoBin);
    fwrite(&cabecalho->byteProxReg, sizeof(int), 1, arquivoBin);
    fwrite(&cabecalho->nroRegistros, sizeof(int), 1, arquivoBin);
    fwrite(&cabecalho->nroRegRemovidos, sizeof(int), 1, arquivoBin);
    fwrite(&cabecalho->descrevePrefixo, sizeof(char), 18, arquivoBin);
    fwrite(&cabecalho->descreveData, sizeof(char), 35, arquivoBin);
    fwrite(&cabecalho->descreveLugares, sizeof(char), 42, arquivoBin);
    fwrite(&cabecalho->descreveLinha, sizeof(char), 26, arquivoBin);
    fwrite(&cabecalho->descreveModelo, sizeof(char), 17, arquivoBin);
    fwrite(&cabecalho->descreveCategoria, sizeof(char), 20, arquivoBin);
    return 1;
}

/*
    Descricao:
        Lê o cabeçalho
    
    Argumentos:
        [in]arquivoBin: arquivo binário que foi criado
                OBS: Não realiza fopen, nem fclose, nem muda o status
        [in]cabecalho: struct de cabecalho que foi criado e preenchido

    Retorno:
        se tudo der certo retorna 1 se algo der errado retorna 0
        após a leitura ele retorna o que foi lido pelo 'cabecalho'
*/
int read_veiculo_cabecalho(FILE *arquivoBin, VEICULO_CABECALHO *cabecalho) {
    if (arquivoBin == NULL) return 0;

    fseek(arquivoBin, 0, SEEK_SET);
    fread(&cabecalho->status, sizeof(char), 1, arquivoBin);
    fread(&cabecalho->byteProxReg, sizeof(int), 1, arquivoBin);
    fread(&cabecalho->nroRegistros, sizeof(int), 1, arquivoBin);
    fread(&cabecalho->nroRegRemovidos, sizeof(int), 1, arquivoBin);
    fread(&cabecalho->descrevePrefixo, sizeof(char), 18, arquivoBin);
    fread(&cabecalho->descreveData, sizeof(char), 35, arquivoBin);
    fread(&cabecalho->descreveLugares, sizeof(char), 42, arquivoBin);
    fread(&cabecalho->descreveLinha, sizeof(char), 26, arquivoBin);
    fread(&cabecalho->descreveModelo, sizeof(char), 17, arquivoBin);
    fread(&cabecalho->descreveCategoria, sizeof(char), 20, arquivoBin);
    
    return 1;
}

/*
    Descrição:
        Imprime o cabeçalho na tela

    Argumentos:
        [in]arquivoBin: arquivo binário que foi criado
            OBS: Não realiza fopen, nem fclose
        [in]cabecalho: struct de cabecalho que foi criado e preenchido
    
    Retorno:
        se tudo der certo retorna 1 se algo der errado retorna 0
        após a leitura ele imprime o que foi lido pelo 'cabecalho'
*/
int mostrarCabecalhoVeiculo(FILE *arquivoBin, VEICULO_CABECALHO *cabecalho) {
    if (arquivoBin == NULL) return 0;

    printf("%c\n", cabecalho->status);
    printf("%d\n", cabecalho->byteProxReg);
    printf("%d\n", cabecalho->nroRegistros);
    printf("%d\n", cabecalho->nroRegRemovidos);
    printf("%s\n", cabecalho->descrevePrefixo);
    printf("%s\n", cabecalho->descreveData);
    printf("%s\n", cabecalho->descreveLugares);
    printf("%s\n", cabecalho->descreveLinha);
    printf("%s\n", cabecalho->descreveModelo);
    printf("%s\n", cabecalho->descreveCategoria);

    return 1;
}

/*
    Descricao:
        Muda o status do cabeçalho
    
    Argumentos:
        [in]arquivoBin: arquivo binário que foi criado
                OBS: Não realiza fopen, nem fclose
        [in]status: o status que será passado ao cabeçalho

    Retorno:
        se tudo der certo retorna 1 se algo der errado retorna 0
*/
int mudaStatus(FILE *arquivoBin, char status) {
    if (arquivoBin == NULL) return 0;
    VEICULO_CABECALHO cabecalho;

    read_veiculo_cabecalho(arquivoBin, &cabecalho);
    cabecalho.status = status;
    
    //Salvar novamente no binário fseek = 0; pois inicio do arquivo
    fseek(arquivoBin, 0, SEEK_SET);
    fwrite(&cabecalho.status, sizeof(char), 1, arquivoBin);
    return 1;
}

/*
    Descricao:
        Muda o byteProxReg do cabeçalho
    
    Argumentos:
        [in]arquivoBin: arquivo binário que foi criado
                OBS: Não realiza fopen, nem fclose
        [in]byteOffset: o byteProxReg que será passado ao cabeçalho

    Retorno:
        se tudo der certo retorna 1 se algo der errado retorna 0
*/
int setByteOffset(FILE *arquivoBin, int byteOffset) {
    if (arquivoBin == NULL) return 0;
    VEICULO_CABECALHO cabecalho;

    read_veiculo_cabecalho(arquivoBin, &cabecalho);
    cabecalho.byteProxReg = byteOffset;
    
    //Salvar novamente no binário fseek = 1; pois inicio do arquivo + sizeof(char)
    fseek(arquivoBin, 1, SEEK_SET);
    fwrite(&cabecalho.byteProxReg, sizeof(int), 1, arquivoBin);
    return 1;
}

/*
    Descricao:
        Muda o nroRegistros do cabeçalho
    
    Argumentos:
        [in]arquivoBin: arquivo binário que foi criado
                OBS: Não realiza fopen, nem fclose
        [in]nRegistros: o nroRegistros que será passado ao cabeçalho

    Retorno:
        se tudo der certo retorna 1 se algo der errado retorna 0
*/
int setNRegistros(FILE *arquivoBin, int nRegistros) {
    if (arquivoBin == NULL) return 0;
    VEICULO_CABECALHO cabecalho;

    read_veiculo_cabecalho(arquivoBin, &cabecalho);
    cabecalho.nroRegistros = nRegistros;
    
    //Salvar novamente no binário fseek = 5; pois inicio do arquivo + sizeof(char) + sizeof(int)
    fseek(arquivoBin, 5, SEEK_SET);
    fwrite(&cabecalho.nroRegistros, sizeof(int), 1, arquivoBin);
    return 1;
} 

/*
    Descricao:
        Muda o nroRegRemovidos do cabeçalho
    
    Argumentos:
        [in]arquivoBin: arquivo binário que foi criado
                OBS: Não realiza fopen, nem fclose
        [in]nRemovidos: o nroRegRemovidos que será passado ao cabeçalho

    Retorno:
        se tudo der certo retorna 1 se algo der errado retorna 0
*/
int setNRemovidos(FILE *arquivoBin, int nRemovidos) {
    if (arquivoBin == NULL) return 0;
    VEICULO_CABECALHO cabecalho;

    read_veiculo_cabecalho(arquivoBin, &cabecalho);
    cabecalho.nroRegRemovidos = nRemovidos;

    //Salvar novamente no binário fseek = 5; pois inicio do arquivo + sizeof(char) + sizeof(int)
    fseek(arquivoBin, 9, SEEK_SET);
    fwrite(&cabecalho.nroRegRemovidos, sizeof(int), 1, arquivoBin);
    return 1;
}