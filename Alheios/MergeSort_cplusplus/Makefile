OBJ = ./obj
BIN = ./bin
SRC = ./src
INCLUDES = ./includes/
LISTA = ./src/Lista/Lista.cpp


all:
	g++ -c $(LISTA) -I $(INCLUDES) -o $(OBJ)/Lista.o
	g++ main.cpp $(OBJ)/*.o -I  ./includes -o $(BIN)/main

run:
	./bin/main.exe

debug:
	g++ -g -c $(LISTA) -I $(INCLUDES) -o $(OBJ)/Lista.o
	g++ -g main.cpp $(OBJ)/*.o -I $(INCLUDES) -o $(BIN)/main
	gdb ./bin/main