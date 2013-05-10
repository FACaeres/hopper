FILE_EXEMPLOS=../exemplos 

for ((i=1; i<=$1; i++))
do
    ./hopper.o $FILE_EXEMPLOS/questao_$i.alg >> $FILE_EXEMPLOS/saida/questao_$i.txt
done
