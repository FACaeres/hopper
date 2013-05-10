#! /bin/bash

FILE_EXEMPLOS=../exemplos 

for i in $(seq $1 $2)
do
    ./hopper.lex.o $FILE_EXEMPLOS/questao_$i.alg >> $FILE_EXEMPLOS/saida/questao_$i.txt
done
exit 0
