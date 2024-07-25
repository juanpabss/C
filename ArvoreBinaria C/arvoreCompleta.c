#include<stdio.h>
#include<stdlib.h>


typedef struct noArv{
    int conteudo;
    struct noArv *direita;
    struct noArv *esquerda;
}noArv;

noArv* insert_version_I(noArv *raiz, int numero){
    if(raiz == NULL){
        noArv *novo = malloc(sizeof(noArv));

        novo->conteudo = numero;
        novo->direita = NULL;
        novo->esquerda = NULL;

        return novo;
    }else{
        if(numero < raiz->conteudo){
            raiz->esquerda = insert_version_I(raiz->esquerda,numero);
        }else{
            raiz->direita = insert_version_I(raiz->direita,numero);
        }
        return raiz;
    }
}

void insert_version_II(noArv **raiz, int numero){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(noArv));

        (*raiz)->conteudo = numero;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }else{
        if(numero < (*raiz)->conteudo){
            insert_version_II(&((*raiz)->esquerda), numero);
        }else{
            insert_version_II(&((*raiz)->direita), numero);
        }

    }
}

void insert_version_III(noArv **raiz, int numero){
    noArv *aux = *raiz;
    while(aux){
        if(numero < aux->conteudo){
            raiz = &aux->esquerda;
        }else{
            raiz = &aux->direita;
        }
        aux = *raiz;
    }

    aux = malloc(sizeof(noArv));
    aux->conteudo = numero;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

void search_element_I(noArv **raiz, int numero){
    noArv *aux = *raiz;
    if(aux == NULL) {
        printf("\nArvore vazia!");
        return;
    }
    while( aux != NULL && numero != aux->conteudo) {
        if (numero < aux->conteudo)
            aux = aux->esquerda;
        else
            aux = aux->direita;
    }

    if (aux == NULL)
        printf("\nelemento não encontrado!");
    else {
        printf("elemento encontrado na lista de dados %d", aux->conteudo);
    }

    printf("\n----------------------------------------------------------");
}


void print_version_I(noArv *raiz){
    if(raiz){
        printf("%d ", raiz->conteudo);
        print_version_I(raiz->esquerda);
        print_version_I(raiz->direita);

    }
}
void print_version_II_Sort(noArv *raiz){
    if(raiz){
        print_version_II_Sort(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        print_version_II_Sort(raiz->direita);

    }
}

void print_version_III(noArv* raiz, int tab) {
    if (raiz) {
        // Imprime as tabulações correspondentes ao nível atual
        for (int i = 0; i < tab; i++) {
            printf("\t");
        }
        // Imprime o conteúdo do nó
        printf("%d\n", raiz->conteudo);

        // Chamada recursiva para os filhos esquerdo e direito
        print_version_III(raiz->esquerda, tab + 1);
        print_version_III(raiz->direita, tab + 1);
    }
}

int height(noArv *raiz){ 
    if(raiz == NULL){
        return -1;
    }else{
        int esquerda = height(raiz->esquerda);
        int direita = height(raiz->direita);
        if(esquerda > direita){
            return esquerda + 1;
        }else {
            return direita + 1;
        }

    }
}

int main(void) {
    noArv *raiz = NULL;
    int numero;
    int altura;

    int op;

    do {
        printf("\n\n ------------------MENU-----------------");
        printf("\n|\t1 - Insert version I\t\t|");
        printf("\n|\t2 - Insert version II \t\t|");
        printf("\n|\t3 - Insert version III \t\t|");
        printf("\n|\t4 - search element I(Me) \t|");
        printf("\n|\t5 - Print version I \t\t|");
        printf("\n|\t6 - Print version II (Sort)\t|");
        printf("\n|\t7 - Print version III (ladder)\t|");
        printf("\n|\t8 - Height\t\t\t|");
        printf("\n|\t0 - SAIR\t\t\t|");
        printf("\n --------------------------------------");
        printf("\nEscolha: ");
        scanf("%d", &op);

        switch (op) {
            case 0:
                printf("\nFIM!!!!");
                break;
            case 1:
                printf("\nDigite um numero: ");
                scanf("%d", &numero);
                raiz = insert_version_I(raiz,numero);
                printf("Elemento inserido na arvore ccom sucesso.");

                break;
            case 2:
                printf("\nDigite um numero: ");
                scanf("%d", &numero);
                insert_version_II(&raiz,numero);
                printf("Elemento inserido na arvore ccom sucesso.");

                break;

            case 3:
                printf("\nDigite um numero: ");
                scanf("%d", &numero);
                insert_version_III(&raiz,numero);
                printf("Elemento inserido na arvore ccom sucesso.");

                break;

            case 4:
                printf("\nDigite o numero que você quer encontrar: ");
                scanf("%d", &numero);
                search_element_I(&raiz,numero);
                break;
            case 5:
                print_version_I(raiz);

                break;
            case 6:
                print_version_II_Sort(raiz);

                break;
            case 7:
                print_version_III(raiz,0);
                break;

            case 8:
                altura = height(raiz);
                printf("\nAltura da arvore: %d", altura);
                
                break;

            default:
                printf("\nOpção inválida!");
                break;
        }
    } while (op != 0);

    return 0;
}