#include "matrizlib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct _matriz
{
    int linhas;
    int colunas;
    char*** matriz;
};

/*
    descricao:
    alloca uma matriz de strings na memoria
    argumentos:
    [in] numLinhas numero de linhas da matriz
    [in] numColunas numero de colunas da matriz
    retono:
    retorna um ponteiro de MATRIZ caso tudo de certo caso contrario retorna NULL
    
*/
MATRIZ* allocaMatriz(int numLinhas, int numColunas){
    MATRIZ* matrix;
    matrix = (MATRIZ*)malloc(sizeof(MATRIZ));

    matrix->linhas = numLinhas;
    matrix->colunas = numColunas;
    matrix->matriz = (char***)malloc(numLinhas * sizeof(char**));
    for (int i = 0; i < numLinhas; i++)
    {
        matrix->matriz[i] = (char**)malloc(numColunas * sizeof(char*));

        for (int j = 0; j < numColunas; j++)
        {
            matrix->matriz[i][j] = NULL;
        }
        
    }
    
    return matrix;

}

/*
    descricao:
    desaloca uma matriz
    argumentos:
    [in] matrix: matriz a ser desalocada
    retono:
    void
*/
void freeMatriz(MATRIZ* matrix){
    for (int i = 0; i < matrix->linhas; i++)
    {
        for (int j = 0; j < matrix->colunas; j++)
        {
            free(matrix->matriz[i][j]);
        }
        
        free(matrix->matriz[i]);
    }
    free(matrix->matriz);
    free(matrix);
    
}

/*
    descricao:
    insere uma palavra numa matriz
    argumentos:
    [in] matrix: matriz allocada que vai receber a palavra
    [in] linha: linha onde a palavra vai ser inserida
    [in] coluna: coluna onde a palavra vai ser inserida
    [in] palavra: buffer na stack da palavra
    retono:
    1 caso sucesso
    -1 caso fracasso
*/
int inserePalavra(MATRIZ* matrix,int linha,int coluna,char palavra[]){
    if (checkBoundaries(matrix,linha,coluna) < 0)
    {
        return -1;
    }

    if (matrix->matriz[linha][coluna] == NULL)
    {
        int tamPalavra = strlen(palavra);
        char* palavraMallocada = (char*)malloc((tamPalavra+1)*sizeof(char));
        memset(palavraMallocada,'\0',(tamPalavra+1)*sizeof(char)); // inicializando a palavra com varios \0s
        strncpy(palavraMallocada,palavra,tamPalavra);
        matrix->matriz[linha][coluna] = palavraMallocada;
    }else
    {
        //todo: caso de substituir uma palavra
    }
    
    

    
    return 1;
    
}

/*
    descricao:
    verifica se os numeros estão dentro das boundaries de uma matriz
    argumentos:
    [in] matrix: matriz pra ser analisada
    [in] linha: numero da linha
    [in] coluna: numero da coluna
    retono:
    -10 linha menor que 0
    -11 linha maior que o maior valor
    -20 coluna menor que 0
    -21 coluna maior que o menor valor
*/
int checkBoundaries(MATRIZ* matrix, int linha, int coluna){
    if (linha < 0)
    {
        return -10;
    }
    if (linha > matrix->linhas)
    {
        return -11;
    }
    if (coluna < 0)
    {
        return -20;
    }
    if (coluna > matrix->colunas)
    {
        return -21;
    }
    
    
}

/*
    descricao:
    printa uma matriz com o separador // entre os itens
    argumentos:
    [in]MATRIZ* matrix: matriz a ser printada
    retono:
    void
*/
void printMatriz(MATRIZ* matrix){

    for (int i = 0; i < matrix->linhas; i++)
    {
        for (int j = 0; j < matrix->colunas; j++)
        {
            printf("%s//",matrix->matriz[i][j]);
        }
        printf("\n");
    }
    
}