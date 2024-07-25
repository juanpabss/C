#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
  int ano;
  int mes;
  int dia;
} data;

typedef struct ingresso {
  char cpf[12];
  char nome[30];
  data date;
  struct ingresso *prox;
} ingresso;

void inserir(ingresso **inicio) {
  ingresso *aux = *inicio;
  ingresso *novo = (ingresso *)malloc(sizeof(ingresso));
  int a;
  if (aux != NULL) {
    while (a != 0) {
      a = 0;
      printf("Digite o CPF do comprador: ");
      scanf("%s", novo->cpf);
      printf("Digite o nome do comprador: ");
      scanf("%s", novo->nome);
      printf("Digite a data do show: ");
      scanf("%d %d %d", &novo->date.dia, &novo->date.mes, &novo->date.ano);
      while (aux != NULL) {
        if (strcmp(aux->cpf, novo->cpf) == 0 &&
            aux->date.dia == novo->date.dia &&
            aux->date.mes == novo->date.mes &&
            aux->date.ano == novo->date.ano) {
          printf("\nvocê já comprou esse ingresso maldito!\n");
          a = 1;
        }
        aux = aux->prox;
      }
    }
    aux = *inicio;
  } else {
    printf("Digite o CPF do comprador: ");
    scanf("%s", novo->cpf);
    printf("Digite o nome do comprador: ");
    scanf("%s", novo->nome);
    printf("Digite a data do show: ");
    scanf("%d %d %d", &novo->date.dia, &novo->date.mes, &novo->date.ano);
  }

  if (aux == NULL || strcmp(novo->cpf, aux->cpf) <= 0) {
    novo->prox = aux;
    *inicio = novo;
  } else {
    while (aux->prox != NULL && strcmp(novo->cpf, aux->prox->cpf) >= 0) {
      aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
  }
}

void imprimir(ingresso *inicio) {
  ingresso *aux = inicio;
  while (aux != NULL) {
    printf("\n%s", aux->cpf);
    aux = aux->prox;
  }
}

void dados_cpf(ingresso *inicio) {
  ingresso *aux = inicio;
  char cepeefe[12];
  printf("Digite o CPF dos ingressos que procura: ");
  scanf("%s", cepeefe);
  while (aux != NULL) {
    if (strcmp(cepeefe, aux->cpf) == 0) {
      printf("\nnome: %s\ndata: %d/%d/%d\n", aux->nome, aux->date.dia,
             aux->date.mes, aux->date.ano);
    }
    aux = aux->prox;
  }
}

int particion(ingresso **inicio, ingresso **primeiro, ingresso **ultimo) {
  int contador = 0;
  ingresso *aux = *inicio;
  ingresso *aux2 = (ingresso *)malloc(sizeof(ingresso));

  while (aux != NULL) {
    if (aux->date.ano < (*ultimo)->date.ano ||
        (aux->date.ano == (*ultimo)->date.ano &&
         aux->date.mes < (*ultimo)->date.mes) ||
        (aux->date.ano == (*ultimo)->date.ano &&
         aux->date.mes == (*ultimo)->date.mes &&
         aux->date.dia < (*ultimo)->date.dia)) {
      contador++;
      strcpy(aux2->cpf, (*primeiro)->cpf);
      strcpy(aux2->nome, (*primeiro)->nome);
      aux2->date.ano = (*primeiro)->date.ano;
      aux2->date.mes = (*primeiro)->date.mes;
      aux2->date.dia = (*primeiro)->date.dia;
      aux2->prox = (*primeiro)->prox;
      strcpy((*primeiro)->cpf, aux->cpf);
      strcpy((*primeiro)->nome, aux->nome);
      (*primeiro)->date.ano = aux->date.ano;
      (*primeiro)->date.mes = aux->date.mes;
      (*primeiro)->date.dia = aux->date.dia;
      (*primeiro)->prox = aux->prox;
      strcpy(aux->cpf, aux2->cpf);
      strcpy(aux->nome, aux2->nome);
      aux->date.ano = aux2->date.ano;
      aux->date.mes = aux2->date.mes;
      aux->date.dia = aux2->date.dia;
      aux->prox = aux2->prox;
    }
    aux = aux->prox;
  }

  free(aux2);
  return contador;
}
int comparar_datas(data d1, data d2){
  if(d1.ano != d2.ano){
    return d1.ano - d2.ano;
  }else if(d1.mes != d2.mes){
    return d1.mes - d2.mes;
  }else{
    return d1.dia-d2.dia;
  }
}

void trocar(ingresso *a, ingresso *b){
  ingresso aux = *a;
  *a = *b;
  *b = aux;
}
int particionando(ingresso *vetor[], int menor, int maior){
  ingresso *pivo = vetor[maior];
  int particao = menor-1;
  int g;
  for(int j = menor; j < maior; j++){
    if(comparar_datas(vetor[j]->date, pivo->date)<=0){
      particao++;
      trocar(vetor[j], vetor[particao]);
    }
  }
  trocar(vetor[particao+1], vetor[maior]);
  return particao + 1;
}

void quick_sort_vetordelista(ingresso *vetor[], int menor, int maior){
  if(menor<maior){
    int pi = particionando(vetor, menor, maior);
    quick_sort_vetordelista(vetor, menor, pi - 1);
    quick_sort_vetordelista(vetor, pi+1, maior);
  }
}

void quick_sort(ingresso **inicio) {
  int size = 0;
  ingresso *aux = *inicio;
  while(aux!=NULL){
    size++;
    aux = aux->prox;
  }
  ingresso *vetor[size];
  aux = *inicio;
  for(int i = 0; i<size;i++){
    vetor[i] = aux;
    aux = aux->prox;
  }
  quick_sort_vetordelista(vetor, 0, size-1);
  for(int i = 0; i<size-1; i++){
    vetor[i]->prox = vetor[i+1];
  }
  vetor[size-1]->prox = NULL;
  *inicio = vetor[0];
}

void imprimirdata(ingresso *inicio) {
  ingresso *aux = inicio;
  while (aux != NULL) {
    printf("\n%d", aux->date.ano);
    aux = aux->prox;
  }
}

int main(void) {
  ingresso *inicio = (ingresso *)malloc(sizeof(ingresso));
  inicio = NULL;
  int op;
  do {
    printf("\nMenu");
    printf("\n1 - Inserir");
    printf("\n2 - imprimir lista");
    printf("\n3 - procurar ingressos por cpf");
    printf("\n4 - ordenar por data");
    printf("\n0 - Sair");
    printf("\nEscolha: ");
    scanf("%d", &op);
    switch (op) {
    case 1:
      inserir(&inicio);
      break;
    case 2:
      imprimir(inicio);
      break;
    case 3:
      dados_cpf(inicio);
      break;
    case 4:
      quick_sort(&inicio);
      imprimirdata(inicio);
      break;
    }
  } while (op != 0);

  return 0;
}