#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para preencher vetor
void preencherVetor(int *vetor, int numero) {
    for (int i = 0; i < numero; i++) {
        vetor[i] = rand() % 10;
    }
}

// Função para imprimir vetor
void imprimir(int *vetor, int numero) {
    printf("\n");
    for (int i = 0; i < numero; i++) {
        printf("[%d]", vetor[i]);
    }
}

// Função para criar Heap
void criaHeap(int *vet, int i, int f) {
    int aux = vet[i]; // Armazena o valor atual em 'aux'
    int j = i * 2 + 1; // Calcula o filho esquerdo do nó atual

    // Enquanto ainda houver elementos a serem verificados no heap
    while (j <= f) {
        // Se houver filho direito e ele for maior que o filho esquerdo
        if (j < f) {
            if (vet[j] < vet[j + 1]) {
                j = j + 1; // Atualiza para o filho direito
            }
        }
        // Se o valor armazenado for menor que o valor do filho selecionado
        if (aux < vet[j]) {
            vet[i] = vet[j]; // Troca o valor do pai pelo valor do filho
            i = j; // Atualiza o índice para o filho
            j = 2 * i + 1; // Calcula o próximo filho do filho atual
        } else {
            j = f + 1; // Sai do loop se o valor for maior ou igual ao filho
        }
    }
    vet[i] = aux; // Insere o valor armazenado na posição correta
}

// Função de ordenação Heap Sort
void heapSort(int *vet, int N) {
    int i, aux;

    // Construir um heap máximo
    // Começa pela metade do vetor e vai até o primeiro elemento
    for (i = (N - 1) / 2; i >= 0; i--) {
        criaHeap(vet, i, N - 1); // Chama a função criaHeap para ajustar o heap
    }

    // Extrair elementos um por um do heap
    for (i = N - 1; i >= 1; i--) {
        // Troca o primeiro elemento (maior) com o último
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        // Recria o heap com os elementos restantes
        criaHeap(vet, 0, i - 1);
    }
}


int main(void) {
    int numero;
    char op;

    srand(time(NULL));

    while (1) {
        printf("\t\t Menu");
        printf("\n1 - Criar e ordenar vetor");
        printf("\n0 - Sair");
        printf("\n\t\t................");

        printf("\nEscolha uma opcao: ");
        scanf(" %c", &op);
        system("clear || cls");
        switch (op) {
            case '1': {
                printf("\nInforme o tamanho do vetor: ");
                scanf("%d", &numero);

                int vetor[numero];

                preencherVetor(vetor, numero);
                printf("\nVetor original:");
                imprimir(vetor, numero);

                heapSort(vetor, numero);
                printf("\nVetor ordenado por Heap Sort:");
                imprimir(vetor, numero);

                break;
            }
            case '0':
                printf("\nFim ---");
                exit(0);
                break;

            default:
                printf("Opcao inválida! Tente novamente.");
                break;
        }
    }

    return 0;
}
