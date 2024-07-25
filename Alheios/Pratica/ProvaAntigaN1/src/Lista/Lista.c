#include "Lista.h"

void Lista_init(Lista* lista) {
	lista->inicio = NULL;
}

bool Lista_push_cel(Lista* lista, Celula* nova) {
	if (!lista->inicio) {
		lista->inicio = nova;
		return true;
	}

	Celula* auxi = lista->inicio;
	Celula* ant = NULL;

	while (auxi) {
		if (Ingresso_igual(auxi->conteudo, nova->conteudo)) {
			return false;
		}
		if (Ingresso_get_int_CPF(nova->conteudo) < Ingresso_get_int_CPF(auxi->conteudo)) {
			nova->prox = auxi;
			if (!ant) {
				lista->inicio = nova;
			} else {
				ant->prox = nova;
				nova->prox = auxi;
			}
			return true;
		}
		ant = auxi;
		auxi = auxi->prox;
	}
	ant->prox = nova;
	return true;
}

bool Lista_push(Lista* lista, Ingresso* novo) {
	Celula* nova = (Celula*)malloc(sizeof(Ingresso));
	nova->conteudo = novo;
	nova->prox = NULL;

	bool deu_certo = Lista_push_cel(lista, nova);

	if (deu_certo) {
		return true;
	} else {
		free(nova);
		return false;
	}
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

void Lista_print_CPF(Lista* lista, char CPF[]) {
	int cpf_int = atoi(CPF);
	Celula* auxi = lista->inicio;
	bool ultimo_igual = false;

	while (auxi) {
		if (Ingresso_get_int_CPF(auxi->conteudo) == cpf_int) {
			Ingresso_print(auxi->conteudo);
			ultimo_igual = true;
		} else {
			if (ultimo_igual) {
				return;
			}
			ultimo_igual = false;
		}
		auxi = auxi->prox;
	}
}

void Lista_print(Lista* lista) {
	Celula* auxi = lista->inicio;

	while (auxi) {
		Ingresso_print(auxi->conteudo);
		auxi = auxi->prox;
	}
}

void Lista_print_quant_ingres_date_pos_org(Lista* lista) {
	Celula* auxi = lista->inicio;
	Celula* ant = NULL;

	bool mudou_date = false;
	int conta_ingresso_date = 0;
	while (auxi) {
		if (ant) {
			if (!Date_igual(Ingresso_get_date(ant->conteudo), Ingresso_get_date(auxi->conteudo))) {
				Date_print(Ingresso_get_date(ant->conteudo));
				printf(" - %d.\n", conta_ingresso_date);
				conta_ingresso_date = 0;
			}
		}
		conta_ingresso_date++;
		ant = auxi;
		auxi = auxi->prox;
	}
}

void Lista_print_quant_ingres_date(Lista* lista) {
	if (!lista->inicio) {
		printf("\nLista vazia!\n");
		return;
	}

	Lista_organ_Date(lista);
	Lista_print_quant_ingres_date_pos_org(lista);
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

Celula* Lista_separar_celulas(Celula* inicio, Celula* pivo, int* num) {
	if (!inicio) {
		return NULL;
	}
	Celula* auxi = inicio;
	Celula* new_inicio = inicio;
	Celula* ant = NULL;
	Celula* troca = NULL;

	while (auxi) {
		if (Ingresso_igual(auxi->conteudo, pivo->conteudo)) {
			return new_inicio;
		}

		if (Date_manior(Ingresso_get_date(auxi->conteudo), Ingresso_get_date(pivo->conteudo))) {
			if (ant) {
				ant->prox = auxi->prox;
			} else {
				new_inicio = auxi->prox;
			}
			troca = auxi;
			auxi = auxi->prox;
			troca->prox = pivo->prox;
			pivo->prox = troca;

			*num = *num + 1;
		} else {
			ant = auxi;
			auxi = auxi->prox;
		}
	}
	return new_inicio;
}

Celula* Lista_quick_sort(Celula* inicio, int tam) {
	if (tam == 0 || tam == 1) {
		return inicio;
	}
	int num_afrente_pivo = 0;

	/** Pega o elemento da posição n, no caso a ultima posição para usalo
	 *  como pivô.
	 */
	Celula* pivo = Lista_get_cel_position(inicio, tam);

	/** Vai separar todos elementos maiores que o pivô para a sua esquerda,
	 *  deixando os menores a sua direita.
	 *  Caso o elemento da posição 1 seja alterado, vai retornar o elemento da posição seguinte.
	 *  O num_afrente_pivo é necessario porque preciso saber quantos elementos passaram a frente
	 *  do pivô.
	 */
	Celula* new_inicio = Lista_separar_celulas(inicio, pivo, &num_afrente_pivo);

	/** Separando a lista em duas, os elementos que estão a direita do pivô.
	 *  E os elementos que estão a esquerda do pivô.
	 */
	pivo->prox = Lista_quick_sort(pivo->prox, num_afrente_pivo);
	new_inicio = Lista_quick_sort(new_inicio, tam - (num_afrente_pivo + 1));

	return new_inicio;
}

void Lista_organ_Date(Lista* lista) {
	lista->inicio = Lista_quick_sort(lista->inicio, Lista_tam(lista->inicio));
}