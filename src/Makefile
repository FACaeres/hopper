FILE=hopper
BIN_DIR=bin
SAIDA_DIR=../exemplos/saida
SCRIPT_FILE=script

.PHONY: clean

compile:	$(FILE).lex.c
	@ echo Compiling...
	@ gcc -o $(FILE).o $(FILE).lex.c -lfl
	@ echo "done"

$(FILE).lex.c:
	@ flex -o $(FILE).lex.c $(FILE).lex
	
teste: compile
	./$(FILE).o teste.txt

clean:
	@ echo Cleaning...
	@ rm -rf *.o
	@ rm -rf *.c
	@ rm -rf *.*~ 
	@ rm -rf *~
	@ rm -rf $(SAIDA_DIR)
	@ mkdir $(SAIDA_DIR)
	@ echo "done"
