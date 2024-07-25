SRC = ./src
OBJ = ./obj
INCLUDES = ./includes
BIN = ./bin
MAIN = $(SRC)/main.c

STRING = $(SRC)/String/String.c
DATE = $(SRC)/Date/Date.c
INGRESSO = $(SRC)/Ingresso/Ingresso.c
LISTA = $(SRC)/Lista/Lista.c

all:
	gcc -c $(STRING)   -I $(INCLUDES)/ -o $(OBJ)/String.o
	gcc -c $(DATE)     -I $(INCLUDES)/ -o $(OBJ)/Date.o
	gcc -c $(INGRESSO) -I $(INCLUDES)/ -o $(OBJ)/Ingresso.o
	gcc -c $(LISTA)    -I $(INCLUDES)/ -o $(OBJ)/Lista.o
	gcc $(MAIN) $(OBJ)/*.o -I $(INCLUDES) -o $(BIN)/main

run:
	./bin/main.exe

