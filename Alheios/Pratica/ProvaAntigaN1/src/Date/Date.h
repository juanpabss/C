#ifndef DATE_H
#define DATE_H

#include "../String/String.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int ano, mes, dia;
}Date;

Date Date_new(int dia, int mes, int ano);
Date Date_receber();

void Date_print(Date* date);

bool Date_igual(Date* this, Date* date);
bool Date_menor(Date* this, Date* date);
bool Date_manior(Date* this, Date* date);

#endif