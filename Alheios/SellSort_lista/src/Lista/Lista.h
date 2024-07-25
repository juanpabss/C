#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Cel {
	int conteudo;
	struct Cel* prox;
} Celula;

typedef struct {
	Celula* inicio;
} Lista;

void Lista_init(Lista* lista);

void Lista_push(Lista* lista, int novo);

int Lista_quant_itens(Lista *lista);
void Lista_print(Lista* lista);
void Lista_organ(Lista* lista);

#endif