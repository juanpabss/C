//
// Created by juanp on 05/08/2024.
//

#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct No{
   int valor;
   struct No *esquerda;
   struct No *direita;
   struct No *pai;
   int altura;
   int cor;
}No;

//Função para descobrir a cor do nó
int cor(No *raiz){
    if(raiz == NULL){
        return BLACK;
    }else{
        return raiz->cor;
    }
}

//Função para trocar a cor do no pai com os filhos
void trocarCor(No *raiz){
    raiz->cor = !raiz->cor;

    if(raiz->esquerda != NULL){
        raiz->esquerda->cor = !raiz->esquerda->cor;
    }
    if(raiz->direita != NULL){
        raiz->direita->cor = !raiz->direita->cor;
    }
}


// função para criar um novo no
No* novoNo(int x){

    No *novo =(No *)malloc(sizeof(No));


    if(novo){
        novo->valor = x;
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->pai = NULL;
        novo->altura = 0;

    } else {
        printf("\nErro de alocação de memoria!!");
    }

    return novo;
}


