#include <stdio.h>
#include <stdlib.h>
#include "includes/includes.hpp"

// mingw32-make.exe

int main(){
    Lista lista;
    lista.initi();

    for(int i = 1; i <= 11; i++){
        lista.inserir(rand()%10);
    }

    lista.print();
    lista.organizar();
    printf("\n");
    lista.print();
    return 0;
}