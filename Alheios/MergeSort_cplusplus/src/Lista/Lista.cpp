#include "Lista.hpp"

void Celula::print() {
	printf("%d ", this->valor);
}

void Lista::initi() {
	this->inicio = NULL;
}

void Lista::initi(Celula* nova) {
	this->inicio = nova;
}

void Lista::inserir(int valor) {
	Celula* nova = (Celula*)malloc(sizeof(Celula));
	nova->valor = valor;
	nova->prox = NULL;

	this->inserir(nova);
}

void Lista::inserir(Celula* nova) {
	if (!this->inicio) {
		this->inicio = nova;
		return;
	}

	Celula* auxi = this->inicio;

	while (auxi->prox) {
		auxi = auxi->prox;
	}

	auxi->prox = nova;
}

void Lista::print() {
	for (Celula* auxi = this->inicio; auxi; auxi = auxi->prox) {
		auxi->print();
	}
}

Celula* Lista::pop_begin() {
	if (!this->inicio) {
		return NULL;
	}
	Celula* auxi = this->inicio;

	this->inicio = auxi->prox;

	auxi->prox = NULL;
	return auxi;
}

void Lista_inserir_auxi_de_juntar(Lista* lista, Celula** auxi) {
	Celula* ant = *auxi;
	*auxi = (*auxi)->prox;
	ant->prox = NULL;
	lista->inserir(ant);
}

Celula* Lista_juntar(Celula* inicioA, Celula* inicioB) {
	if (!inicioA) {
		return inicioB;
	}
	if (!inicioB) {
		return inicioA;
	}

	Lista lista;
	lista.initi();

	Celula *auxiA, *auxiB;
	auxiA = inicioA;
	auxiB = inicioB;

	auto Juntar = [&lista](Celula **auxi) {
		Celula* ant = *auxi;
		*auxi = (*auxi)->prox;
		ant->prox = NULL;
		lista.inserir(ant);
	};

	while (auxiA || auxiB) {
		if (auxiA && auxiB) {
			if (auxiA->valor < auxiB->valor) {
				//Lista_inserir_auxi_de_juntar(&lista, &auxiA);
				Juntar(&auxiA);
			} else {
				//Lista_inserir_auxi_de_juntar(&lista, &auxiB);
				Juntar(&auxiB);
			}
		} else if (auxiA) {
			//Lista_inserir_auxi_de_juntar(&lista, &auxiA);
			Juntar(&auxiA);
		} else if (auxiB) {
			//Lista_inserir_auxi_de_juntar(&lista, &auxiB);
			Juntar(&auxiB);
		}
	}
	return lista.inicio;
}

int Lista_len(Celula* inicio) {
	int conta = 0;
	Celula* auxi = inicio;
	while (auxi) {
		conta++;
		auxi = auxi->prox;
	}
	return conta;
}

Celula* Lista_dividir(Celula* inicio, int meio) {
	if (meio < 1) {
		return NULL;
	}

	int conta = 1;

	Celula* auxi = inicio;
	Celula* ant = NULL;
	while (auxi && conta <= meio) {
		conta++;
		ant = auxi;
		auxi = auxi->prox;
	}

	ant->prox = NULL;
	return auxi;
}

Celula* Lista_merge_sort(Celula* inicio) {
	int len = Lista_len(inicio);
	if (!inicio || len <= 1) {
		return inicio;
	}
	Celula* listaA = inicio;
	Celula* listaB = Lista_dividir(listaA, len / 2);

	listaA = Lista_merge_sort(listaA);
	listaB = Lista_merge_sort(listaB);

	return Lista_juntar(listaA, listaB);
}

void Lista::organizar() {
	this->inicio = Lista_merge_sort(this->inicio);
}
