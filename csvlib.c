#include "csvlib.h"
#include "matrizlib.h"


/*
    descricao:
    Abre o arquivo csv e retorna o ponteiro pro arquivo

    argumentos:
    [in] fileName: nome do arquivo a ser aberto

    retorno:
    caso de certo retorna um ponteiro de leitura para o arquivo.
    caso de errado retorna NULL

*/
FILE* open_csv(char* fileName){

    FILE* filePointer = NULL;
    filePointer = fopen(fileName,"r");
    return filePointer;
}

/*
    descricao:
    Fecha o arquivo
    argumentos:
    [in] filePointer: ponteiro do arquivo a ser fechado
    retono:
    void
*/
void close_csv(FILE* filePointer){
    fclose(filePointer);
}

/*
    descricao:
    transforma um ponteiro pra csv em uma matriz(numLinhas x numCampos) de strings(MATRIZ*)
    argumentos:
    [in] filePointer: ponteiro do arquivo aberto para leitura
    retono:
    Em sucesso: MATRIZ* matrizRetorno
    Em erro:    NULL
*/
MATRIZ* csvToMatrix(FILE* filePointer){
    MATRIZ* matrizRetorno;
    int numeroLinhas = numLinhas(filePointer);
    int numeroColunas = numCampos(filePointer);
    matrizRetorno = allocaMatriz(numeroLinhas,numeroColunas);
    
    fseek(filePointer,0,SEEK_SET);

    char line[99999];

    int linhaAtual = 0;
    while(fgets(line, sizeof(line), filePointer) != NULL) {
        line[strcspn(line, "\n")] = 0;
        picotadora(line,matrizRetorno,linhaAtual);
        linhaAtual++;
    }


   return matrizRetorno;

}

/*
    descricao:
    Conta o num de linhas em um arquivo
    argumentos:
    [in] filePointer: ponteiro do arquivo aberto para leitura
    retono:
    Em sucesso: int numLinhas
    Em erro:   int 0
*/
int numLinhas(FILE* filePointer){
    int count = 0;
    char c;
    fseek(filePointer,0,SEEK_SET);
    
    for (c = getc(filePointer); c != EOF; c = getc(filePointer))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

    return count;
}

/*
    descricao:
    Conta o num de campos em um csv com base no cabecalho
    argumentos:
    [in] filePointer: ponteiro do arquivo aberto para leitura
    retono:
    Em sucesso: int numCampos
    Em erro:   int 0
*/
int numCampos(FILE* filePointer){
    int count = 0;
    char c;
    fseek(filePointer,0,SEEK_SET);

    for (c = getc(filePointer); c != EOF; c = getc(filePointer)){
        if (c == ',')
        {
            count = count + 1;
        }
        else if (c == '\n')
        {
            break;
        }
    }

    if (count != 0)
    {
        count++;
    }
    
    return count;
}

/*
    descricao:
    recebe uma linha csv e retorna um vetor de strings(char**)
    argumentos:
    [in] char* line: linha
    retono:
    caso sucesso retorna um char** com as strings
    caso fracasso retorna NULL
*/
char** picotadora(char* line,MATRIZ* matrix,int linha){

    // char** retorno;
    // int num_elementos = 3; //todo: func que pega o numero de elementos em uma linha
    char delimitadores[] = ",";
    // retorno = (char**)malloc(num_elementos*sizeof(char*));
    char* token;

    token = strsep(&line, delimitadores);
    int itemAtual = 0;
   /* walk through other tokens */
   while( token != NULL ) {
        // printf( "valor:%s tamanho:%ld\n", token,strlen(token) );
        inserePalavra(matrix,linha,itemAtual,token);
        itemAtual++;
        token = strsep(&line, delimitadores);
   }

    return NULL;
}
