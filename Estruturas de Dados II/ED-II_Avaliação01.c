#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct processo{
  char data_inicio[11];
  char nome[20];
  int qnt_memoria;
  struct processo *prox;
  struct processo *ant;
} processo;

typedef struct info {
  int contador;
  processo *inicio;
  processo *fim;
} info;

void inserir(info **lista){
  processo *novo_processo = (processo *)malloc(sizeof(processo));
  processo *aux = (*lista)->inicio;
  
  novo_processo->prox = NULL;
  novo_processo->ant = NULL;
  
  if(novo_processo == NULL){
    printf("Erro ao alocar memória!\n");
  }else{
    printf("\n\t ***Informacoes");
    printf("\nDigite o nome do processo: ");
    scanf(" %19[^\n]s", novo_processo->nome);
    printf("\nDigite a digite a quantidade de memoria do processo: ");
    scanf("%d", &novo_processo->qnt_memoria);
    printf("\nAgora digite a data de inicio do processo da seguinte forma:\n froma YYYY-MM-DD 2024-03-15: ");
    printf("\nDigite a data de inicio do processo: ");
    scanf(" %10[^\n]s", novo_processo->data_inicio);

    if (aux == NULL) {
        novo_processo->prox = NULL;
        (*lista)->inicio = novo_processo;
      } else {
        while (aux->prox != NULL) {
          aux = aux->prox;
        }
        aux->prox = novo_processo;
        novo_processo->ant = aux;
      (*lista)->fim = novo_processo;
      }
  }
  
};

void imprimir(info *lista){
  processo *aux = lista->inicio;
  int i = 0;
  if(aux != NULL){ 
  printf("\n--- Processos\n");
    while(aux != NULL){
      i++;
      printf("\n %d°", i);
      printf("\nNome: %s", aux->nome);
      printf("\nQuantidade de memoria: %d", aux->qnt_memoria);
      printf("\nData de inicio: %s", aux->data_inicio);
      aux = aux->prox;
      printf("\n\t----------------------");
      }
  }else{
    printf("\nNão há processos cadastrados!");
  }
  
};

void bubblesort(info **inicio) {
  processo *atual;
  processo *loop1 = (*inicio)->inicio;
  if (*inicio == NULL || (*inicio)->inicio == NULL) {
    return;
  }

  while(loop1 != NULL) {
    atual = (*inicio)->inicio;

    while (atual->prox != NULL) {
      if (strcmp(atual->nome, atual->prox->nome) > 0) {
        processo *temp = atual->prox;
        atual->prox = temp->prox;
        if (temp->prox != NULL) {
          temp->prox->ant = atual;
        }
        temp->ant = atual->ant;
        if (atual->ant != NULL) {
          atual->ant->prox = temp;
        } else {
          (*inicio)->inicio = temp;
        }
        atual->ant = temp;
        temp->prox = atual;
      } else {
        atual = atual->prox;
      }
    }
    loop1 = loop1->prox;
  }
}

void selectsort(info **lista) {
  processo *atual, *menor, *temp;
  
  if ((*lista)->inicio == NULL || (*lista)->inicio->prox == NULL) {
    return;
  }

  atual = (*lista)->inicio;
  while (atual != NULL) {
    menor = atual;
    temp = atual->prox;

    while (temp != NULL) {
      
      if (strcmp(temp->data_inicio, menor->data_inicio) < 0) {
        menor = temp;
      }
      temp = temp->prox;
    }

    
    if (menor != atual) {
      if (atual->ant != NULL) {
        atual->ant->prox = menor;
      } else {
        (*lista)->inicio = menor;
      }

      if (menor->ant != NULL) {
        menor->ant->prox = atual;
      } else {
        (*lista)->inicio = atual;
      }

      if (atual->prox != menor) {
        processo *aux = menor->prox;
        menor->prox = atual->prox;
        atual->prox->ant = menor;
        atual->prox = aux;
        aux->ant = atual;
      } else {
        menor->prox = atual;
        atual->prox = NULL;
        atual->ant = menor->ant;
        menor->ant = atual;
      }
      
      temp = atual->ant;
      atual->ant = menor->ant;
      menor->ant = temp;
    }

    atual = menor->prox;
  }
}

int main(void) {
  info *lista = (info *)malloc(sizeof(info));
  (*lista).contador = 0;
  (*lista).inicio = NULL;
  (*lista).fim = NULL;
  int op;

  do {
    printf("\n\n--------------MENU--------------");
    printf("\n1 - inserir processo");
    printf("\n2 - imprimir processo");
    printf("\n3 - Ordena processos pelo nome");//bubble sort
    printf("\n4 - Ordena processos pela data de inicio");//selection sort
    printf("\n5 - Ordena processos pela quantidade de memoria");//merge sort
    printf("\n\t\t0 - sair");
    printf("\n--------------------------------");
    printf("\nEscolha: ");
    scanf("%d", &op);
    switch (op) {
      case 0:
      printf("\nFIM!!!!");
      break;
      case 1:
      inserir(&lista);
      break;
      case 2:
      imprimir(lista);
      break;
      case 3:
      bubblesort(&lista);
      printf("\nOrdenado com bubble");
      imprimir(lista);
      break;
      case 4:
      selectsort(&lista);
      printf("\nOrdenado com select");
      imprimir(lista);
      break;
      case 5:
      break;
    default:
      printf("\nOpção inválida!");
      break;
    }
  } while (op != 0);

  return 0;
}
