#include "String.h"

void String_receber(char msg[], char string[], int tam) {
    fflush(stdin);
    printf("%s", msg);
    fgets(string, tam, stdin);
    string[tam-1] = '\0';
    fflush(stdin);
}