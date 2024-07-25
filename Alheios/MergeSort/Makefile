OBJ = ./obj
BIN = ./bin
SRC = ./src
INCLUDES = ./includes/
LISTA = ./src/Lista/Lista.c


all:
	gcc -c $(LISTA) -I $(INCLUDES) -o $(OBJ)/Lista.o
	gcc main.c $(OBJ)/*.o -I  ./includes -o $(BIN)/main

run:
	./bin/main.exe