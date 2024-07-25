#ifndef INGRESSO_h
#define INGRESSO_h

#include "../Date/Date.h"
//#include "../String/String.h"

#include <string.h>

typedef struct {
	char CPF[13];
	char nome[50];
	Date date_evento;
} Ingresso;

Ingresso* Ingresso_new(char nome[], char CPF[], Date date_evento);
Ingresso* Ingresso_receber();

void Ingresso_print(Ingresso* ingres);
bool Ingresso_igual(Ingresso* this, Ingresso* ingres);
unsigned int Ingresso_get_int_CPF(Ingresso* ingres);
Date* Ingresso_get_date(Ingresso *ingres);

#endif