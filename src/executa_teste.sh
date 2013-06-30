#! /bin/bash

FILE_EXEMPLOS=../exemplos 

total=`ls ../exemplos/*.alg | wc -l`

for i in $(seq $1 $total)
do
	echo "$i"
	./hopper.o $FILE_EXEMPLOS/questao_$i.alg
done
exit 0
