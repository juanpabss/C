#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro {
  char isbn[14];
  char titulo[30];
  int ano;
  char autor[30];
  int quantidade;
  struct livro *prox;
  struct livro *ant;
} livro;

typedef struct info {
  int contador;
  livro *inicio;
  livro *fim;
} info;

void inserir(info **lista) {
  livro *aux = (*lista)->inicio;
  livro *novo = (livro *)malloc(sizeof(livro));
  if (novo != NULL) {
    printf("\nDigite o ISBN do livro: ");
    scanf(" %s", novo->isbn);
    if (aux != NULL) {
      while (aux != NULL) {
        if (strcmp(aux->isbn, novo->isbn) == 0) {
          printf("\nEsse ISBN já esta registrado no sistema.");
          printf("\nDigite quantos exemplares da obra %s voce quer adicionar: ", aux->titulo);
          scanf("%d", &novo->quantidade);
          aux->quantidade += novo->quantidade;
          return;
        }
        aux = aux->prox;
      }
    }
    aux = (*lista)->inicio;
    printf("\nDigite o título do livro: ");
    scanf(" %30[^\n]s", novo->titulo);
    do {
      printf("\nDigite o ano de publicação do livro: ");
      scanf("%d", &novo->ano);
      if (novo->ano > 2024) {
        printf("\nEsse ano ainda não esta dísponível nessa atualização, tente novamente em %d anos\n",novo->ano - 2023);
      }
    } while (novo->ano > 2024);
    printf("\nDigite o nome do autor do livro: ");
    scanf(" %30[^\n]s", novo->autor);
    printf("\nDigite a quantidade de livros disponíveis: ");
    scanf("%d", &novo->quantidade);
    if (aux == NULL || strcmp(novo->titulo, aux->titulo) < 0 ||
        strcmp(novo->titulo, aux->titulo) == 0) {
      if (aux == NULL) {
        novo->prox = NULL;
        (*lista)->fim = novo;
      } else if (strcmp(novo->titulo, aux->titulo) < 0) {
        novo->prox = (*lista)->inicio;
        aux->ant = novo;
      } else if (strcmp(novo->titulo, aux->titulo) == 0) {
        aux->quantidade = novo->quantidade + aux->quantidade;
        return;
      }
      (*lista)->inicio = novo;
      novo->ant = NULL;
      (*lista)->contador++;
    } else {
      while (aux->prox != NULL &&
             strcmp(novo->titulo, aux->prox->titulo) >= 0) {
        aux = aux->prox;
      }
      if (aux->prox == NULL) {
        novo->prox = NULL;
        novo->ant = aux;
        aux->prox = novo;
        (*lista)->fim = novo;
      } else if (strcmp(novo->titulo, aux->prox->titulo) < 0) {
        novo->prox = aux->prox;
        novo->ant = aux;
        aux->prox->ant = novo;
        aux->prox = novo;
      } else if (strcmp(novo->titulo, aux->prox->titulo) == 0) {
        printf("\n Esse livro ja existe no sistema, vamos apenas incrementar a quantidade e atribuir o ISBN existente");
        aux->quantidade = novo->quantidade + aux->quantidade;
        return;
      }
      (*lista)->contador++;
    }

  } else {
    printf("\nerro de alocação.");
  }
}
void imprimir(info *lista) {
  livro *auxInicio = (*lista).inicio;
  livro *auxFim = (*lista).fim;
  int op2;
  if (auxInicio != NULL) {
    printf("\nEscolha uma opção");
    printf("\n1 - Ordem alfabética crescente");
    printf("\n2 - Ordem alfabetica decrescente");
    printf("\nEscolha: ");
    scanf("%d", &op2);
    if (op2 == 1) {
      while (auxInicio != NULL) {
        printf("\nlivro: %s\nQuantidade: %d", auxInicio->titulo, auxInicio->quantidade);
        auxInicio = auxInicio->prox;
      }
    } else if (op2 == 2) {
      while (auxFim != NULL) {
        printf("\nlivro: %s\nQuantidade: %d", auxFim->titulo, auxFim->quantidade);
        auxFim = auxFim->ant;
      }
    } else {
      printf("\nOpção inválida.");
    }
  } else {
    printf("\nLista vazia.");
  }
}

void excluir(info **lista) {
  char excluir[15];
  int numexc;
  livro *aux = (*lista)->inicio;
  if (aux != NULL) {
    printf("Digite o ISBN da obra que quer excluir: ");
    scanf("%s", excluir);
    while (aux != NULL) {
      if (strcmp(aux->isbn, excluir) == 0) {
        printf("\nQuantidade no sistema: %d", aux->quantidade);
        printf("\nDigite o numero de licros que quer excluir: ");
        scanf("%d", &numexc);
        aux->quantidade = aux->quantidade - numexc;
        if (aux->quantidade <= 0) {
          if ((*lista)->inicio == aux) {
            (*lista)->inicio = aux->prox;
            if (aux->prox != NULL) {
              aux->prox->ant = NULL;
            } else {
              (*lista)->fim = NULL;
            }
            (*lista)->contador--;
            free(aux);
            return;
          }
          if ((*lista)->fim == aux) {
            (*lista)->fim = aux->ant;
            if (aux->ant != NULL) {
              aux->ant->prox = NULL;
            } else {
              (*lista)->inicio = NULL;
            }
            (*lista)->contador--;
            free(aux);
            return;
          }
          aux->ant->prox = aux->prox;
          aux->prox->ant = aux->ant;
          (*lista)->contador--;
          free(aux);
          return;
        }
        return;
      }
      aux = aux->prox;
    }
    printf("\nObra não encontrada, verifique se digitou corretamente o ISBN");
  } else {
    printf("\nA lista esta vazia");
  }
}

void buscar(info *lista) {
  int contador = 1;
  char buscar[30];
  int op3;
  livro *aux = (*lista).inicio;
  if (aux != NULL) {
    printf("\nEscolha uma das opções:");
    printf("\n1 - Busca por ISBN");
    printf("\n2 - Busca por autor");
    printf("\nEscolha:");
    scanf("%d", &op3);
    if (op3 == 1) {
      printf("\nDigite o ISBN da obra que gostaria de buscar: ");
      scanf(" %29[^\n]s", buscar);
      while (aux != NULL) {
        if (strcmp(aux->isbn, buscar) == 0) {
          printf("\nObra: %s", aux->titulo);
          printf("\nAutor: %s", aux->autor);
          printf("\nAno de lançamento: %d", aux->ano);
          printf("\nquantidade disponíveis: %d", aux->quantidade);
          return;
        }
        aux = aux->prox;
      }
      printf("\nISBN não encontrado!");
    } else if (op3 == 2) {
      printf("\nDigite o nome do autor que deseja ver as obras: ");
      scanf(" %29[^\n]s", buscar);
      while (aux != NULL) {
        if (strcmp(aux->autor, buscar) == 0) {
          if (contador == 1) {
            printf("\nObras do(a) autor(a) %s", buscar);
            contador++;
          }
          printf("\n\ntítulo: %s", aux->titulo);
        }
        aux = aux->prox;
      }
      if (contador == 1) {
        printf("\nnenhuma obra de %s encontrada em nosso acervo", buscar);
      }
    }
  } else {
    printf("\nSua lista esta vazia.");
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
    printf("\n\t1 - inserir livro\t\t\t|");
    printf("\n\t2 - imprimir livros\t\t\t|");
    printf("\n\t3 - excluir livro\t\t\t|");
    printf("\n\t4 - Buscar livro\t\t\t|");
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
      excluir(&lista);
      break;
    case 4:
      buscar(lista);
      break;
    default:
      printf("\nOpção inválida!");
      break;
    }
  } while (op != 0);

  return 0;
}
