FILE_EXEMPLOS=../exemplos 

for i in {1..30}
do
    ./hopper.o $FILE_EXEMPLOS/questao_$i.alg >> $FILE_EXEMPLOS/saida/questao_$i.txt
done
