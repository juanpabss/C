#include<stdio.h>
#include<stdlib.h>


typedef struct No{
    int conteudo;
    struct No *direita;
    struct No *esquerda;
    int altura;
}No;

// função para criar um novo no
No* novoNo(int x){
    
    No *novo =(No *)malloc(sizeof(No));

    
    if(novo){
        novo->conteudo = x;
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->altura = 0;
    
    } else {
        printf("\nErro de alocação de memoria!!");
    }

    return novo;
}


//função para calcular a maior altura de um no
int maior(int a, int b){
    return (a > b)? a : b;
}

// Função que retorna altura de um ou -1 se ele for null
int alturaDoNo(No *no){
    if(no == NULL){
        return -1;
    }else{
        return no->altura;
    }
}

// função que calcular o fator de balanceamento (fb)
int fatorDeBalanceamento(No *no){
    if(no){
        return (alturaDoNo(no->esquerda) - alturaDoNo(no->direita));
    }else{
        return 0;
    }
}

//função responsavel pela rotação a esquerda

No* rotacaoEsquerda(No *r){
    No *y, *f;

    y = r->direita;
    f = y->esquerda;

    y->esquerda = r;
    r->direita = f;

    r->altura = maior(alturaDoNo(r->esquerda), alturaDoNo(r->direita)) + 1;
    y->altura = maior(alturaDoNo(y->esquerda), alturaDoNo(y->direita)) + 1;

    return y ;
}

// Função responsavel pela rotação a direita
No* rotacaoDireita(No* r){
    No *y, *f;
    
    y = r->esuqerda;
    f = y->direita;

    y->direita = r;
    r->esquerda = f;


    r->altura = maior(alturaDoNo(r->esquerda), alturaDoNo(r->direita)) + 1;
    y->altura = maior(alturaDoNo(y->esquerda), alturaDoNo(y->direita)) + 1;

    return y;
}


//Função responsavel pela rotação dupla a esquerda
No* rotacaoDuplaEsquerda(No* r){
    r->direita = rotacaoDireita(r->direita);
    return rotacaoEsquerda(r);
}

//Função responsavel pela rotação dupla a direita
No* rotacaoDuplaDireita(No* r){
    r->esquerda = rotacaoEsquerda(r->esquerda);
    return rotacaoDireita(r);
}




































int main(void){
    printf("Hello world");
    return 0;
}






