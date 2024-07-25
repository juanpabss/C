#include <stdio.h>



int main (){
    int op;
    printf("\n Hello World!\n How are you ?\n I'm great, thanks, and you ?\n I'm good.");


    printf("\n Data: %s \n Hora: %s", __DATE__,__TIME__);

    while(1){
       printf("\n 1-continuar\n 0- sair\n ");
       scanf("%d", &op);

       switch(op){
        case 1:
        
        break;
        case 0:
        printf("fim");
        exit (1);
        break;
        default:
        printf("op INVALIDA");
        break;
       };

    }
    return 0;
}