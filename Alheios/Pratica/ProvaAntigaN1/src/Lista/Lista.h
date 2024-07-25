#ifndef LISTA_H
#define LISTA_H

#include "../Ingresso/Ingresso.h"

typedef struct Cel {
	Ingresso* conteudo;
	struct Cel* prox;
} Celula;

typedef struct {
	Celula* inicio;
} Lista;

void Lista_init(Lista* lista);

bool Lista_push(Lista* lista, Ingresso* novo);

int Lista_quant_itens(Lista *lista);
void Lista_print_CPF(Lista *lista, char CPF[]);
void Lista_print(Lista* lista);
void Lista_print_quant_ingres_date(Lista *lista);
void Lista_organ_Date(Lista* lista);

#endif