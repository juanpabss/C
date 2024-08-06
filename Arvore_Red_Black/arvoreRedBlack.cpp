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
   int cor;
}No;

int cor(No *raiz){
    if(raiz == NULL){
        return BLACK;
    }else{
        return raiz->cor;
    }
}

