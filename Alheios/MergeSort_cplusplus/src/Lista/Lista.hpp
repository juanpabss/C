#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

struct Celula {
	int valor;
	Celula* prox;

	void print();
};

struct Lista {
	Celula* inicio;

	void initi();
	void initi(Celula*);
	void inserir(int);
	void inserir(Celula*);
	Celula* pop_begin();
	void print();
	void organizar();
};

int Lista_len(Celula*);
Celula* Lista_dividir(Celula*, int);

#endif