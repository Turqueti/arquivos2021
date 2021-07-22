#!/bin/bash

cp out .testes
cp out .testespt2
resetTestCases.sh ./.testespt2
./.scripts/resetTestCases.sh ./.testes
cd ./.testes
echo -e "\nparte 1:\n"
tester.sh out . -c
echo -e "\e[1;37m\nparte 2:\n"
find . -type f ! -name '*.zip' -delete
cd ../.testespt2
tester.sh out . -c
find . -type f ! -name '*.zip' -delete