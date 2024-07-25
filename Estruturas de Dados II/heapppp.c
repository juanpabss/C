#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void pai( int *vetor, int contador){



}

// Função para preencher vetor
void preencherVetor(int *vetor, int contador) {
    for (int i = 0; i < 10; i++) {
       printf("Digite o valor do %d° elemento: ", i+1);
       scanf("%d", &vetor[i]);

       contador += 1;
    }
}



// Função para imprimir vetor
void imprimir(int *vetor) {
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("[%d]", vetor[i]);
    }
}



int main(void) {
    int contador;
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
                int vetor[10];
                preencherVetor(vetor,contador);


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
