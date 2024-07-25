#include <stdio.h>
#include <stdlib.h>

void PrintVetor(char msg[], int *vetor, int tamanho) {
  printf("%s", msg);
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n\n");
}

void BubbleSort(int *vetor, int tamanho) {
  int auxi;
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < (tamanho - 1); j++) {
      if (vetor[j] > vetor[j + 1]) {
        auxi = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = auxi;
      }
    }
  }
}

void SelectionSort(int *vetor, int tamanho) {
  int auxi, menor, pos;
  for (int i = 0; i < tamanho; i++) {
    for (int j = i; j < tamanho; j++) {
      if (j == i) {
        menor = vetor[j];
        pos = j;
      }
      if (vetor[j] < menor) {
        menor = vetor[j];
        pos = j;
      }
    }
    auxi = vetor[i];
    vetor[i] = menor;
    vetor[pos] = auxi;
  }
}

void AvancarCasa(int *vetor, int menor_casa, int maior_casa) {
  for (int i = maior_casa; i >= menor_casa; i--) {
    vetor[i + 1] = vetor[i];
  }
}

void InsertionSort(int *vetor, int tamanho) {
  int auxi;

  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < i; j++) {
      if (vetor[i] < vetor[j]) {
        auxi = vetor[i];
        AvancarCasa(vetor, j, i - 1);
        vetor[j] = auxi;
      }
    }
  }
}

void PreenchendoVetor(int *vetor, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    vetor[i] = (rand() % 10 + 1);
  }
}

int main(void) {
  int tam_vetor = 10;

  printf("Digite o tamanho do vetor de int: ");
  scanf("%d", &tam_vetor);

  int *vetor = (int *)malloc(tam_vetor * sizeof(int));

  PreenchendoVetor(vetor, tam_vetor);
  PrintVetor("\nVetor: ", vetor, tam_vetor);
  BubbleSort(vetor, tam_vetor);
  PrintVetor("Bubble_sort: ", vetor, tam_vetor);

  PreenchendoVetor(vetor, tam_vetor);
  PrintVetor("\nVetor: ", vetor, tam_vetor);
  SelectionSort(vetor, tam_vetor);
  PrintVetor("Selection_sort: ", vetor, tam_vetor);

  PreenchendoVetor(vetor, tam_vetor);
  PrintVetor("\nVetor: ", vetor, tam_vetor);
  InsertionSort(vetor, tam_vetor);
  PrintVetor("Insertion_sort: ", vetor, tam_vetor);
  return 0;
}