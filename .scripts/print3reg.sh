#!/bin/bash

dumpRegistroRNN.sh test.bin 1 | python3 .scripts/formataRegistro.py
echo "--------------------------------------------------------"
dumpRegistroRNN.sh test.bin 2 | python3 .scripts/formataRegistro.py
echo "--------------------------------------------------------"
dumpRegistroRNN.sh test.bin 3 | python3 .scripts/formataRegistro.py
echo "--------------------------------------------------------"
dumpRegistroRNN.sh test.bin 4 | python3 .scripts/formataRegistro.py