#include <stdio.h>
#include <stdlib.h>
#include "../includes/includes.h"
#include "Menu/Menu.h"

// mingw32-make.exe

int main(){
    Lista lista;
    Lista_init(&lista);
    int op;
    
    Lista_push(&lista, Ingresso_new("aa", "00000000001", Date_new(17, 2, 2024)));
    Lista_push(&lista, Ingresso_new("aa", "00000000011", Date_new(17, 2, 2024)));
    Lista_push(&lista, Ingresso_new("aa", "00000000031", Date_new(17, 2, 2024)));

    Lista_push(&lista, Ingresso_new("aa", "00000000011", Date_new(19, 2, 2024)));
    Lista_push(&lista, Ingresso_new("aa", "00000000021", Date_new(15, 2, 2024)));
    Lista_push(&lista, Ingresso_new("aa", "00000000031", Date_new(16, 2, 2024)));
    Lista_push(&lista, Ingresso_new("aa", "00000000041", Date_new(9, 2, 2024)));

    Lista_push(&lista, Ingresso_new("aa", "00000000021", Date_new(6, 2, 2024)));
    Lista_push(&lista, Ingresso_new("aa", "00000000031", Date_new(6, 2, 2024)));
    Lista_push(&lista, Ingresso_new("aa", "00000000051", Date_new(6, 2, 2024)));
    Lista_push(&lista, Ingresso_new("aa", "00000000081", Date_new(6, 2, 2024)));

    Lista_push(&lista, Ingresso_new("aa", "00000000001", Date_new(7, 2, 2024)));
    Lista_push(&lista, Ingresso_new("aa", "00000000001", Date_new(10, 2, 2024)));
    
    do{
        op = Menu();
        Opcoes(op, &lista);
    }while(op);
    return 0;
}