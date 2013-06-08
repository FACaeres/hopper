#! /bin/bash

FILE_EXEMPLOS=../exemplos 

for i in $(seq $1 $2)
do
	./hopper.o $FILE_EXEMPLOS/questao_$i.alg
done
exit 0
