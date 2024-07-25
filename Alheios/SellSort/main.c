#include <stdio.h>
#include <stdlib.h>

#define TAM 11

void Vetor_print(char msg[], int vetor[], int tam){
    printf("%s", msg);
    for(int i = 0; i < tam; i++)    
        printf("%d ", vetor[i]);
}

void Vetor_rand(int vetor[], int tam){
    for(int i = 0; i < tam; i++)
        vetor[i] = rand();
}

void SellSort(int vector[], int tam){
    int gap = 0, auxi;

    while(gap < tam){
        gap = 3*gap + 1;
    }  
    gap = (gap-1)/3;

    while(gap > 0){
        for(int i = 0; (i+gap) < tam; i++){
            for(int j = i; j < (tam-gap); j += gap){
                if(vector[j] > vector[j+gap]){
                    auxi = vector[j];
                    vector[j] = vector[j+gap];
                    vector[j+gap] = auxi;
                }
            }
        }

        if(gap == 2)
            gap = 1;
        else if(gap == 4 || gap == 3)
            gap = 2;
        else
            gap = (gap-1)/3;
    }
}

int main(){
    int vector[] = {
        50, 35, 10, 25, 45, 40, 20, 15, 30, 25, 35
    };

    Vetor_print("Antes: ", vector, TAM);
    SellSort(vector, 11);
    Vetor_print("\n\nDepois: ", vector, TAM);
    return 0;
}