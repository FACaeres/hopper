FILE=hopper
BIN_DIR=bin
SAIDA_DIR=../exemplos/saida
SCRIPT_FILE=executa_teste

.PHONY: clean

compile:
	@ bison -d $(FILE).y
	@ flex -o $(FILE).lex.c $(FILE).lex
	@ gcc  -o $(FILE).o $(FILE).lex.c $(FILE).tab.c -lfl -lm
	@ echo "done"
	
teste: 	compile
	@ echo Executando testes.. 
	bash ./$(SCRIPT_FILE).sh 1
	@ echo Testes finalizados.

clean:
	@ echo Cleaning...
	@ rm -rf *.o
	@ rm -rf *.tab.h
	@ rm -rf *.py
	@ rm -rf *.*~ 
	@ rm -rf *~
	@ rm -rf *.swp
	@ echo "done"
