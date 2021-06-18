#!/bin/bash

function uso() {
    echo "uso: resetTestCasese pasta_casos_de_teste [-options]"
}

if [ $# -eq 0 ];then
uso
exit
fi
if [ ! -d $1 ];then
    
    uso
    echo pasta_casos_de_teste nao eh uma pasta
    # echo $1
    exit

else
    # echo $1
    pathToTests=$1 #caminho para pasta dos casos de teste sendo $PWD a pasta em que o programa foi executado

fi
shift #passa para $1 para o prox arg

cd $pathToTests
find . -type f ! -name '*.zip' -a ! -name 'out' -delete
unzip -q ./*.zip
# echo $(pwd) resetada