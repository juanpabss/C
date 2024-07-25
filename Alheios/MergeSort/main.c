#include <stdio.h>
#include <stdlib.h>
#include "includes/includes.h"

// mingw32-make.exe

int main(){
    Lista lista;

    Lista_initi(&lista);

    Lista_inserir(&lista, 4);
    Lista_inserir(&lista, 2);
    Lista_inserir(&lista, 3);
    Lista_inserir(&lista, 6);

    Lista_print(&lista);

    Lista_organizar(&lista);

    Lista_print(&lista);
    
    return 0;
}