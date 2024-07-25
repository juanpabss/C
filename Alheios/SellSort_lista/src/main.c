#include <stdio.h>
#include <stdlib.h>
#include "../includes/includes.h"

// mingw32-make.exe

int main(){
    Lista lista;
    Lista_init(&lista);

    Lista_push(&lista, 18);
    Lista_push(&lista, 15);
    Lista_push(&lista, 17);
    Lista_push(&lista, 9);
    Lista_push(&lista, 13);

    Lista_print(&lista);
    return 0;
}