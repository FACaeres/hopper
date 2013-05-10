FILE=hopper
BIN_DIR=bin
SAIDA_DIR=../exemplos/saida
SCRIPT_FILE=executa_teste

.PHONY: clean

compile: $(FILE).lex.c
	@ echo Compiling...
	@ gcc -o $(FILE).lex.o $(FILE).lex.c -lfl
	@ echo "done"

$(FILE).lex.c:
	@ flex -o $(FILE).lex.c $(FILE).lex
	
teste: compile
	bash ./$(SCRIPT_FILE).sh $(N)

clean:
	@ echo Cleaning...
	@ rm -rf *.o
	@ rm -rf *.c
	@ rm -rf *.*~ 
	@ rm -rf *~
	@ rm -rf *.swp
	@ rm -rf $(SAIDA_DIR)
	@ mkdir $(SAIDA_DIR)
	@ echo "done"
