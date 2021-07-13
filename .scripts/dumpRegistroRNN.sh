#!/bin/bash

re='^[0-9]+$'

if [ -f $1 ] && [[ $2 =~ $re ]]
then
    hexdump $1 -n 77 -s $((77*$2)) -e '1/1 "%02X "' -v

else
    echo "uso: dumpRegistroRNN arquivoIndice.bin RNN(int)"
fi