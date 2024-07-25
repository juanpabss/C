#include "Ingresso.h"

Ingresso* Ingresso_new(char nome[], char CPF[], Date date_evento) {
	Ingresso* novo = (Ingresso*)malloc(sizeof(Ingresso));
	strcpy(novo->nome, nome);
	strcpy(novo->CPF, CPF);
	novo->date_evento = date_evento;

	return novo;
}

Ingresso* Ingresso_receber(){
    char CPF[13] = {};
    char nome[50] = {};

    String_receber("\nDigite seu nome: ", nome, 50);
    String_receber("Digite o CPF: ", CPF, 13);
    Ingresso_new(nome, CPF, Date_receber());
}

void Ingresso_print(Ingresso* ingres) {
	printf("\nNome: %s.\n", ingres->nome);
	printf("CPF: %s.\n", ingres->CPF);
	printf("Date: ");
	Date_print(&ingres->date_evento);
	printf("\n");
}

bool Ingresso_igual(Ingresso* this, Ingresso* ingres) {
	if (Ingresso_get_int_CPF(this) != Ingresso_get_int_CPF(ingres)) {
		return false;
	}

	if (!Date_igual(&this->date_evento, &ingres->date_evento)) {
		return false;
	}

	return true;
}

unsigned int Ingresso_get_int_CPF(Ingresso* ingres) {
	return atoi(ingres->CPF);
}

Date* Ingresso_get_date(Ingresso *ingres){
	return &ingres->date_evento;
}