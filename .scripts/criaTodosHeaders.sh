#!/bin/bash

for f in *.c
do
if [ ! $f == "main.c" ]
    then
        ./.tools/criaHeader.sh $f

fi
done