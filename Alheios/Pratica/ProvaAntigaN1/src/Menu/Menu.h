#ifndef MENU_H
#define MENU_H

#include "../Lista/Lista.h"
#include <stdio.h>

int Menu(){
    int op;
    printf("\n#   MENU    #\n\n");
    printf("1. Emitir novo ingresso.\n");
    printf("2. Buscar ingresso por CPF.\n");
    printf("3. Numero de ingressos por data.\n");
    printf("0. Sair.\n\n");

    printf("Digite a opcao: ");
    scanf("%d", &op);

    return op;
}

void Inserir_ingresso_lista(Lista *lista){
    Ingresso *novo = Ingresso_receber();

    if(!Lista_push(lista, novo)){
        printf("\nNao foi possivel emitir novo ingresso para a data: \n");
        Date_print(&novo->date_evento);
        printf("\n");
        free(novo);
    }
}

void Buscar_CPF(Lista *lista){
    char CPF[13] = {};
    String_receber("\nDigite o CPF: ", CPF, 13);
    Lista_print_CPF(lista, CPF);
}

void Num_ingressos_date(Lista *lista){
    if(!lista->inicio){
        printf("\nNenhum ingresso foi emitido.\n");
        return;
    }

    printf("\nA data e apos ela o numero de ingressos emitidos:\n\n");
    Lista_print_quant_ingres_date(lista);
}

void Opcoes(int op, Lista *lista){
    if(op == 1){
        Inserir_ingresso_lista(lista);
    }else if(op == 2){
        Buscar_CPF(lista);
    }else if(op == 3){
        Num_ingressos_date(lista);
    }else if(op != 0){
        printf("\nERRO.\n");
    }
}

#endif