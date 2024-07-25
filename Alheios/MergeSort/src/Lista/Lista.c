#include "Lista.h"

Celula *Celula_new(int valor){
    Celula *nova = (Celula*) malloc(sizeof(Celula));

    nova->valor = valor;
    nova->prox = NULL;

    return nova;
}

void Lista_initi(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void Lista_inserir_push_back(Lista *lista, Celula *nova){
    if(!nova){
        return;
    }

    lista->tam++;
    nova->prox = NULL;

    if(!lista->inicio){
        lista->inicio = nova;
        lista->fim = nova;
        return;
    }

    lista->fim->prox = nova;
    lista->fim = nova;
}

void Lista_inserir(Lista *lista, int valor){
    Celula *nova = Celula_new(valor);

    Lista_inserir_push_back(lista, nova);
}

Celula* Lista_pop_begin(Lista *lista){
    if(!lista->inicio){
        lista->fim = NULL;
        return NULL;
    }
    Celula *auxi = lista->inicio;

    lista->inicio = auxi->prox;

    auxi->prox = NULL;
    return auxi;
}

void Lista_print(Lista *lista){
    if(!lista->inicio){
        return;
    }

    for(Celula *auxi = lista->inicio; auxi; auxi = auxi->prox){
        printf("%d ", auxi->valor);
    }
    printf("\nTam: %d.", lista->tam);
}

Celula* Lista_celu_central(Celula *inicio, int meio){
    Celula *auxi = inicio;

    if(!meio){
        return inicio;
    }
    
    for(int i = 1; auxi && i != meio; auxi = auxi->prox){
        i++;
    }

    return auxi;
}

Lista Lista_merge_sort(Celula *inicio, Celula *fim, int tam){
    if(!inicio && !fim){
        Lista lis;
        Lista_initi(&lis);
        return lis;
    }

    Lista esq, dir;

    Lista_initi(&esq);
    Lista_initi(&dir);

    if(tam > 1){
        esq = Lista_merge_sort(inicio, Lista_celu_central(inicio, tam/2), tam/2);
        dir = Lista_merge_sort(Lista_celu_central(inicio, 1+(tam/2)), fim, tam-(tam/2));
    }else{
        //return NULL;
    }

    Lista nova;
    Lista_initi(&nova);

    Celula *auxi_esq = Lista_pop_begin(&esq);
    Celula *auxi_dir = Lista_pop_begin(&dir);

    for(int i = 1; i <= tam; i++){
        if(auxi_esq->valor <= auxi_dir->valor){
            Lista_inserir_push_back(&nova, auxi_esq);
            Lista_inserir_push_back(&nova, auxi_dir);
        }else{
            Lista_inserir_push_back(&nova, auxi_dir);
            Lista_inserir_push_back(&nova, auxi_esq);
        }
        auxi_esq = Lista_pop_begin(&esq);
        auxi_dir = Lista_pop_begin(&dir);
    }

    return nova;
}

void Lista_organizar(Lista *lista){
    *lista = Lista_merge_sort(lista->inicio, lista->fim, lista->tam);
}