#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// função para prencher vetor
void prencherVetor(int *vetor, int numero){
   for(int i = 0; i < numero; i++){
     vetor[i] = rand() % 10;
   }
}//função para imprimir vetor
void imprimir(int *vetor, int numero) {
  printf("\n");
  for(int i = 0; i < numero; i++){
    printf("[%d]", vetor[i]);
  }
}
//função para ordenar vetor, usando o metodo Shell sort



int main(void) {
  int numero;
  char op;
  //char pausa;

  srand(time(NULL));

  while(1){
    
    printf("\t\t Menu");
    printf("\n1 - Criar e ordena vetor");
    printf("\n0 - Sair");
    printf("\n\t\t................");

    printf("\nEscolha uma opcao:" );
    scanf(" %c", &op);
    system("clear || cls");
    switch(op){
      case '1':{
        printf("\nInformae o tamanho do vetor: ");
        scanf("%d", &numero);

        int vetor[numero];

        prencherVetor(vetor, numero);
        imprimir(vetor, numero);

        
        printf("\nVetor ordenado por Shell Sorte: ");
        shellSort(vetor, numero);
        imprimir(vetor, numero);
                
        break;
    }
      case '0':
        printf("\nFim ---");
        exit(0);
      break;

      default:
      printf("Opcao invalida! Tente novamente.");
      break;
    }



  }

  return 0;
};
