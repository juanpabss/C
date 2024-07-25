#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "list/list.h"

#define TAM 100000

void Vetor_print(char msg[], int vetor[], int tam){
    printf("%s", msg);
    for(int i = 0; i < tam; i++)    
        printf("%d ", vetor[i]);
}

void Vetor_rand(int vetor[], int tam){
    for(int i = 0; i < tam; i++)
        vetor[i] = rand();
}

void Vetor_org(int vetor[], int tam){
    List list;
    list.inicio = NULL;
    int num_comparacao = tam*2;
    
    for(int i = 0; i < tam; i++){
        List_insert(&list, Celula_new(vetor[i]));
    }

    for(int i = tam-1; i >= 0; i--)
        vetor[i] = List_pop(&list);

    printf("\nComparacao: %d.\n", num_comparacao);
}

int main(){
    //srand(time(NULL));

    int vetor[TAM] = {};
    Vetor_rand(vetor, TAM);
    //Vetor_print("Vetor: ", vetor, TAM);
    Vetor_org(vetor, TAM);
    //Vetor_print("\nBubble_sort: ", vetor, TAM);
    return 0;
}