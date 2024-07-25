#include "Lista.h"

void Lista_init(Lista* lista) {
	lista->inicio = NULL;
}

void Lista_push_cel(Lista* lista, Celula* nova) {
	if (!lista->inicio) {
		lista->inicio = nova;
		return;
	}

	Celula* auxi = lista->inicio;
	Celula* ant = NULL;

	while (auxi) {
		ant = auxi;
		auxi = auxi->prox;
	}
	ant->prox = nova;
	return;
}

void Lista_push(Lista* lista, int novo) {
	Celula* nova = (Celula*)malloc(sizeof(Celula));
	nova->conteudo = novo;
	nova->prox = NULL;

	Lista_push_cel(lista, nova);
}

int Lista_tam(Celula* inicio) {
	if (!inicio) {
		return 0;
	}
	Celula* auxi = inicio;

	int conta = 0;
	for (; auxi; auxi = auxi->prox) {
		conta++;
	}
	return conta;
}

int Lista_quant_itens(Lista* lista) {
	return Lista_tam(lista->inicio);
}

void Lista_print(Lista* lista) {
	Celula* auxi = lista->inicio;

	while (auxi) {
		printf("%d ", auxi->conteudo);
		auxi = auxi->prox;
	}
}

Celula* Lista_get_cel_position(Celula* inicio, int position) {
	if (!inicio || position == 0) {
		return NULL;
	}
	Celula* auxi = inicio;

	int conta = 1;
	for (; auxi; auxi = auxi->prox) {
		if (conta == position)
			return auxi;
		conta++;
	}
	return NULL;
}

Celula* Lista_sell_sort(Celula* inicio, int tam) {
	int gap = 0;

	while (gap < tam) {
		gap = 3 * gap + 1;
	}
	gap = (gap - 1) / 3;

	//Celula *auxi = inicio;
	Celula *new_inicio = inicio;

	int i = 0;
	while (gap > 0) {

		

		if (gap == 2)
			gap = 1;
		else if (gap == 4 || gap == 3)
			gap = 2;
		else
			gap = (gap - 1) / 3;
	}
}

void Lista_organ(Lista* lista) {
	lista->inicio = Lista_sell_sort(lista->inicio, Lista_quant_itens(lista));
}