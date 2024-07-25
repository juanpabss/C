#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100000

void Vetor_print(char msg[], int vetor[], int tam){
    printf("%s", msg);
    for(int i = 0; i < tam; i++)    
        printf("%d ", vetor[i]);
}

void Vetor_rand(int vetor[], int tam){
    for(int i = 0; i < tam; i++)
        vetor[i] = rand();
}

void Vetor_org(int vetor[], int tam){
    int auxi;
    long long int num_comparacao = 0, num_troca = 0;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < (tam-1); j++){
            num_comparacao++;
            if(vetor[j] > vetor[j+1]){
                num_troca++;
                auxi = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = auxi;
            }
        }
    }

    printf("\n\nComparacao: %lli. Trocas: %lli.\n", num_comparacao, num_troca);
}

int main(){
    //srand(time(NULL));

    int vetor[TAM] = {};
    Vetor_rand(vetor, TAM);
    //Vetor_print("Vetor: ", vetor, TAM);
    Vetor_org(vetor, TAM);
    //Vetor_print("\nBubble_sort: ", vetor, TAM);
    return 0;
}