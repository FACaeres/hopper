FILE=hopper
BIN_DIR=bin
SAIDA_DIR=../exemplos/saida
SCRIPT_FILE=executa_teste

.PHONY: clean

compile:$(FILE).lex.c
	@ bison -d $(FILE).y
	@ flex  -o $(FILE).flex.c $(FILE).lex
	@ gcc  -o $(FILE) $(FILE).lex.c $(FILE).tab.c -lfl -lm
	@ echo "done"

$(FILE).lex.c:
	@ flex -o $(FILE).lex.c $(FILE).lex
	
teste: 	compile
	@ echo Executando testes.. 
	@ mkdir -p $(SAIDA_DIR)
	bash ./$(SCRIPT_FILE).sh 1 19
	@ echo Testes finalizados.

clean:
	@ echo Cleaning...
	@ rm -rf *.o
	@ rm -rf *.tab.h
	@ rm -rf *.c
	@ rm -rf *.*~ 
	@ rm -rf *~
	@ rm -rf *.swp
	@ rm -rf $(SAIDA_DIR)
	@ echo "done"
