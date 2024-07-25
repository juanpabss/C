#include "Date.h"

Date Date_new(int dia, int mes, int ano) {
	Date novo;

	novo.dia = dia;
	novo.mes = mes;
	novo.ano = ano;

	return novo;
}


Date Date_receber() {
    int dia, mes, ano;

    printf("\nDigite a data: \n");
    printf("Dia: ");
    scanf("%d", &dia);
    printf("Mes: ");
    scanf("%d", &mes);
    printf("Ano: ");
    scanf("%d", &ano);

    return Date_new(dia, mes, ano);
}
void Date_print(Date* date) {
	printf("%02d / %02d / %04d", date->dia, date->mes, date->ano);
}

bool Date_igual(Date* this, Date* date) {
	if (this->dia == date->dia) {
		if (this->mes == date->mes) {
			if (this->ano == date->ano) {
				return true;
			}
		}
	}

	return false;
}

bool Date_menor(Date* this, Date* date) {
	
}

bool Date_manior(Date* this, Date* date){
    if (this->ano > date->ano) {
		return true;
	} else if (this->ano < date->ano) {
		return false;
	}

	if (this->mes > date->mes) {
		return true;
	} else if (this->mes < date->mes) {
		return false;
	}

    if(this->dia > date->dia){
        return true;
    }

    return false;
}