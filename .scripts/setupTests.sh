#!/bin/bash

mv out .testes
./.scripts/resetTestCases.sh ./.testes
cd ./.testes
tester.sh out . -c