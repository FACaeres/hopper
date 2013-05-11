FILE=hopper
BIN_DIR=bin
SAIDA_DIR=../exemplos/saida
SCRIPT_FILE=executa_teste

.PHONY: clean

compile:$(FILE).lex.c
	@ echo Compiling...
	@ gcc -o $(FILE).lex.o $(FILE).lex.c -lfl
	@ echo "done"

$(FILE).lex.c:
	@ flex -o $(FILE).lex.c $(FILE).lex
	
teste: 	compile
	@ echo Executando testes.. 
	bash ./$(SCRIPT_FILE).sh 1 30
	@ echo Testes finalizados.

clean:
	@ echo Cleaning...
	@ rm -rf *.o
	@ rm -rf *.c
	@ rm -rf *.*~ 
	@ rm -rf *~
	@ rm -rf *.swp
	@ rm -rf $(SAIDA_DIR)
	@ echo "done"
