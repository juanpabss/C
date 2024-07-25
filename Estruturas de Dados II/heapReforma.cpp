#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
  int numeros[MAX];
  int qnt;
} heap_struct;

heap_struct heap;

int pai_pos(int pos) { return (pos - 1) / 2; }

int filho1_pos(int pos) {
  int pos_filho1 = 2 * pos + 1;
  if (pos_filho1 >= heap.qnt) {
    return -1;
  }

  return pos_filho1;
}

int filho2_pos(int pos) {
  int pos_filho2 = 2 * pos + 2;
  if (pos_filho2 >= heap.qnt) {
    return -1;
  }

  return pos_filho2;
}

void troca(int pos1, int pos2) {
  int aux = heap.numeros[pos1];
  heap.numeros[pos1] = heap.numeros[pos2];
  heap.numeros[pos2] = aux;
}

void ordenar_pai(int indice) {
  if (indice == 0) {
    return;
  }
  int indice_pai = pai_pos(indice);
  int filho = heap.numeros[indice];
  int pai = heap.numeros[indice_pai];
  if (filho <= pai) {
    return;
  } else {
    troca(indice, indice_pai);
    ordenar_pai(indice_pai);
  }
}

void inserir_heap(int num) {
  if (heap.qnt >= MAX) {
    printf("A heap está cheia.\n");
    return;
  }
  heap.numeros[heap.qnt] = num;
  heap.qnt++;

  ordenar_pai(heap.qnt - 1);
}

void imprimir_heap() {
  printf("Quantidade: %d | ", heap.qnt);
  for (int i = 0; i < heap.qnt; i++) {
    printf("%d - ", heap.numeros[i]);
  }
  printf("fim\n");
}

void ordenar_filhos(int indice) {
  int f1_indice = filho1_pos(indice);
  if (f1_indice > 0) {
    if (heap.numeros[indice] < heap.numeros[f1_indice]) {
      troca(indice, f1_indice);
      ordenar_filhos(f1_indice);
    }
  }
  int f2_indice = filho2_pos(indice);
  if (f2_indice > 0) {
    if (heap.numeros[indice] < heap.numeros[f2_indice]) {
      troca(indice, f2_indice);
      ordenar_filhos(f2_indice);
    }
  }
}

int remover_heap() {
  if (heap.qnt <= 0) {
    printf("Heap vazia\n");
    return -1;
  }
  int remover = heap.numeros[0];
  heap.qnt--;
  troca(0, heap.qnt);

  ordenar_filhos(0);

  return remover;
}

int main(int argc, char const *argv[]) {
  heap.qnt = 0;
  int opcao, num;

  do {
    printf("\nMenu:\n");
    printf("1. Inserir número na heap\n");
    printf("2. Remover número da heap\n");
    printf("3. Imprimir heap\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        printf("Digite o número a ser inserido: ");
        scanf("%d", &num);
        inserir_heap(num);
        break;
      case 2:
        printf("Removido: %d\n", remover_heap());
        break;
      case 3:
        imprimir_heap();
        break;
      case 4:
        printf("Saindo...\n");
        break;
      default:
        printf("Opção inválida. Tente novamente.\n");
    }
  } while (opcao != 4);

  return 0;
}
