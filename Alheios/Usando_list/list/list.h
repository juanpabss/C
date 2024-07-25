#include <stdio.h>
#include <stdlib.h>

typedef struct Cel{
    int valor;
    struct Cel *prox;
}Celula;

typedef struct{
    Celula *inicio;
}List;

Celula *Celula_new(int valor){
    Celula *nova = (Celula*) malloc(sizeof(Celula));

    nova->valor = valor;
    nova->prox = NULL;

    return nova;
}

void List_insert(List *list, Celula *cel){
    if(!cel){
        return;
    }

    if(!list->inicio){
        list->inicio = cel;
        return;
    }

    Celula *auxi = list->inicio;
    Celula *ant = NULL;

    while(auxi){
        if(auxi->valor < cel->valor){
            if(!ant){
                cel->prox = list->inicio;
                list->inicio = cel;
            }else{
                ant->prox = cel;
                cel->prox = auxi;
            }
            return;
        }
        ant = auxi;
        auxi = auxi->prox;
    }
    ant->prox = cel;
}

int List_pop(List *list){
    Celula *auxi = list->inicio;
    list->inicio = list->inicio->prox;

    int int_auxi = auxi->valor;
    free(auxi);

    return int_auxi;
}
