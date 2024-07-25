#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void PrintVector(int *vector, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void PreencherVector(int *vector, int tam){
    for(int i = 0; i < tam; i++){
        vector[i] = rand()%100;
    }
}

void Trocar(int *vector, int indiceA, int indiceB){
    int auxi = vector[indiceA];
    vector[indiceA] = vector[indiceB];
    vector[indiceB] = auxi;
}

int Separar(int *vector, int tam){
    int pivo = tam-1;

    int menor_que_pivo = -1;
    for(int i = 0; i < tam; i++){
        if(vector[i] <= vector[pivo]){
            menor_que_pivo++;
            Trocar(vector, i, menor_que_pivo);
        }

        if(i == (tam-1)){
            pivo = menor_que_pivo;
        }
    }

    return pivo;
}

void QuickSort(int *vector, int tam){
    if(tam <= 1){
        return;
    }
    int indice_pivo = Separar(vector, tam);

    QuickSort(&vector[0], indice_pivo);
    QuickSort(&vector[indice_pivo+1], tam-indice_pivo);
}

int main(){
    int vetor[TAM] = {};
    PreencherVector(vetor, TAM);

    PrintVector(vetor, TAM);
    QuickSort(vetor, TAM);
    PrintVector(vetor, TAM);

    return 0;
}