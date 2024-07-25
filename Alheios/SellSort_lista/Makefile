SRC = ./src
OBJ = ./obj
INCLUDES = ./includes
BIN = ./bin
MAIN = $(SRC)/main.c

LISTA = $(SRC)/Lista/Lista.c

all:
	gcc -c $(LISTA)    -I $(INCLUDES)/ -o $(OBJ)/Lista.o
	gcc $(MAIN) $(OBJ)/*.o -I $(INCLUDES) -o $(BIN)/main

run:
	./bin/main.exe

