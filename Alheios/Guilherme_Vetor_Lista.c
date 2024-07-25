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

int comparar_datas(data d1, data d2) {
  if (d1.ano != d2.ano) {
    return d1.ano - d2.ano;
  } else if (d1.mes != d2.mes) {
    return d1.mes - d2.mes;
  } else {
    return d1.dia - d2.dia;
  }
}

void trocar(ingresso *a, ingresso *b) {
  ingresso aux = *a;
  *a = *b;
  *b = aux;
}
int particionando(ingresso *vetor[], int menor, int maior) {
  ingresso *pivo = vetor[maior];
  int particao = menor - 1;
  for (int j = menor; j < maior; j++) {
    if (comparar_datas(vetor[j]->date, pivo->date) <= 0) {
      particao++;
      trocar(vetor[j], vetor[particao]);
    }
  }
  trocar(vetor[particao + 1], vetor[maior]);
  return particao + 1;
}

void quick_sort_vetordelista(ingresso *vetor[], int menor, int maior) {
  if (menor < maior) {
    int pi = particionando(vetor, menor, maior);
    quick_sort_vetordelista(vetor, menor, pi - 1);
    quick_sort_vetordelista(vetor, pi + 1, maior);
  }
}

void quick_sort(ingresso **inicio) {
  int size = 0;
  ingresso *aux = *inicio;
  while (aux != NULL) {
    size++;
    aux = aux->prox;
  }
  ingresso *vetor[size];
  aux = *inicio;
  for (int i = 0; i < size; i++) {
    vetor[i] = aux;
    aux = aux->prox;
  }
  quick_sort_vetordelista(vetor, 0, size - 1);
  for (int i = 0; i < size - 1; i++) {
    vetor[i]->prox = vetor[i + 1];
  }
  vetor[size - 1]->prox = NULL;
  *inicio = vetor[0];
}

void imprimirdata(ingresso *inicio) {
  ingresso *aux = inicio;
  while (aux != NULL) {
    printf("\n%d", aux->date.ano);
    aux = aux->prox;
  }
}
void merge(ingresso *vetor[], int inicio, int meio, int fim) {
  int tamanhoEsquerda =
      meio - inicio + 1; // o meio ta sendo adicionado na segunda parte
  int tamanhoDireita = fim - meio;

  ingresso *listaEsquerda =
      (ingresso *)malloc(tamanhoEsquerda * sizeof(ingresso));
  ingresso *listaDireita =
      (ingresso *)malloc(tamanhoDireita * sizeof(ingresso));

  for (int i = 0; i < tamanhoEsquerda; i++) {
    listaEsquerda[i] = *vetor[inicio + i];
  }
  for (int j = 0; j < tamanhoDireita; j++) {
    listaDireita[j] = *vetor[meio + 1 + j];

    int indiceEsquerda = 0;
    int indiceDireita = 0;
    int indiceMerged = inicio;

    while (indiceEsquerda < tamanhoEsquerda && indiceDireita < tamanhoDireita) {
      if (comparar_datas(listaEsquerda[indiceEsquerda].date,
                         listaDireita[indiceDireita].date) < 0) {
        *vetor[indiceMerged] = listaEsquerda[indiceEsquerda];
        indiceEsquerda++;
      } else {
        *vetor[indiceMerged] = listaDireita[indiceDireita];
        indiceDireita++;
      }
      indiceMerged++;
    }

    // Copiando os elementos restantes da sublista esquerda, se houver
    while (indiceEsquerda < tamanhoEsquerda) {
      *vetor[indiceMerged] = listaEsquerda[indiceEsquerda];
      indiceEsquerda++;
      indiceMerged++;
    }

    // Copiando os elementos restantes da sublista direita, se houver
    while (indiceDireita < tamanhoDireita) {
      *vetor[indiceMerged] = listaDireita[indiceDireita];
      indiceDireita++;
      indiceMerged++;
    }

    // Liberando a memória alocada para as sublistas temporárias
    free(listaEsquerda);
    free(listaDireita);
  }
}
void merge_sort_aux(ingresso *vetor[], int inicio, int fim) {
  if (inicio < fim) {
    int meio = inicio + (fim - inicio) / 2;
    merge_sort_aux(vetor, inicio, meio);
    merge_sort_aux(vetor, meio + 1, fim);

    merge(vetor, inicio, meio, fim);
  }
}
void merge_sort(ingresso **inicio) {
  int size = 0;
  ingresso *aux = *inicio;
  while (aux != NULL) {
    size++;
    aux = aux->prox;
  }
  ingresso *vetor[size];
  aux = *inicio;
  for (int i = 0; i < size; i++) {
    vetor[i] = aux;
    aux = aux->prox;
  }
  merge_sort_aux(vetor, 0, size - 1);
  for (int i = 0; i < size - 1; i++) {
    vetor[i]->prox = vetor[i + 1];
  }
  vetor[size - 1]->prox = NULL;
  *inicio = vetor[0];
}
void shell_sort_aux(ingresso *vetor[], int tamanho) {
  int intervalo = 1;
  while (intervalo < tamanho / 3)
    intervalo = intervalo * 3 + 1;

  while (intervalo >= 1) {
    for (int i = intervalo; i < tamanho; i++) {
      ingresso *chave = vetor[i];
      int j = i;
      while (j >= intervalo && comparar_datas(vetor[j - intervalo]->date, chave->date) > 0) {
        vetor[j] = vetor[j - intervalo];
        j -= intervalo;
      }
      vetor[j] = chave;
    }
    intervalo /= 3;
  }
}

void shell_sort(ingresso **inicio) {
  int size = 0;
  ingresso *aux = *inicio;
  while (aux != NULL) {
    size++;
    aux = aux->prox;
  }
  ingresso *vetor[size];
  aux = *inicio;
  for (int i = 0; i < size; i++) {
    vetor[i] = aux;
    aux = aux->prox;
  }
  shell_sort_aux(vetor, size);

  for (int i = 0; i < size - 1; i++) {
    vetor[i]->prox = vetor[i + 1];
  }
  vetor[size - 1]->prox = NULL;
  *inicio = vetor[0];
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
    printf("\n4 - ordenar por data(quick)");
    printf("\n5 - ordenar por data(merge)");
    printf("\n6 - Ordenar por data(shell)");
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
    case 5:
      merge_sort(&inicio);
      imprimirdata(inicio);
      break;
    case 6:
      shell_sort(&inicio);
      imprimirdata(inicio);
      break;
    }
  } while (op != 0);

  return 0;
}