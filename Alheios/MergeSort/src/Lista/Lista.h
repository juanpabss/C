#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Cel{
    int valor;
    struct Cel *prox;
}Celula;

typedef struct{
    Celula *inicio, *fim;
    int tam;
}Lista;

void Lista_initi(Lista *lista);
void Lista_inserir(Lista *lista, int valor);
Celula* Lista_pop_begin(Lista *lista);
void Lista_print(Lista *lista);
void Lista_organizar(Lista *lista);

#endif