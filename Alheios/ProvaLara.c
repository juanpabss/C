#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// evitar que a mesma pessoa possua várias entradas na mesma dia.
int tam=0;

typedef struct no
{
    char cpf[11];
    char nomeDoComprador[30];
    int dataDia;
    int dataMes;
    int dataAno;
    struct no *prox;
    int tamanho;
} No;

/*Antes de realizar a inserção de um novo ingresso, o sistema deve conferir se existe
algum registro de cpf e data já cadastrado e notificar o usuário.*/

int VerificarCPF(No *lista, char *CPF, int dataDia,  int dataMes,  int dataAno) {
    while (lista != NULL) {
        if (strcmp(lista->cpf, CPF ) == 0 && (lista->dataDia == dataDia && lista->dataMes== dataMes && lista->dataAno == dataAno  )) {
            return 1; // cpf já existe
        }
        lista = lista->prox;
    }
    return 2; 
}

void inseriri_no_inicio(No **lista)
{
    No *novo = (No *)malloc(sizeof(No));
    No *aux = *lista;

    if (novo == NULL)
    {
        printf("Erro!");
        exit(1);
    }
    else
    {
          int datadia;
           int datames;
           int dataano;
            char CPF[11];

        printf("\nPreencha para ter um ingresso: \n");
        printf("\nDigite seu nome: ");
        scanf("%s", novo->nomeDoComprador);
        printf("\nDigite seu cpf: ");
        scanf("%s", CPF);
        strcpy(novo->cpf, CPF); 
        printf("\nDigite o dia do evento: ");
        scanf("%d", &datadia);
        novo->dataDia =  datadia;
        printf("\nDigite o mes do evento: ");
        scanf("%d", &datames);
        novo->dataMes = datames;
        printf("\nDigite o ano do evento: ");
        scanf("%d", &dataano);
        novo->dataAno=dataano;

        int receber = VerificarCPF(aux, CPF, datadia, datames, dataano);
  


    if(receber == 2){
        //inicio do insertion gambiarrado
       if(aux == NULL || (strcmp(aux->cpf, novo->cpf)>=0)){
        novo->prox = aux;
        *lista = novo;
        tam++;
       }else{
        while(aux->prox!=NULL && strcmp(aux->prox->cpf, novo->cpf)<=0){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;

       }


    }else{
        printf("aaaaaaa");
    
    }
        
    }
}





void imprimir(No *lista)
{
    if (lista == NULL)
    {
        printf("\nA lista esta vazia.\n");
        return;
    }



    while (lista != NULL)  {
        printf("\nNome: %s", lista->nomeDoComprador);
        printf("\nCpf: %s", lista->cpf);
        
        lista = lista->prox;
    }
    printf("\nTamanho da lista: %d", tam);
}

//imprimir ingressos de um determinado cpf
void imprimirPorCpf(No *lista, char cpf[]){
    while(lista!=NULL){
        if(strcmp(lista->cpf, cpf )==0){
        printf("\nNome: %s", lista->nomeDoComprador);
        printf("\nCpf: %s", lista->cpf);
        }
        lista = lista->prox;
    }
}

void menu()
{
    printf("\n1-Inserir\n2-Buscar por cpf\n3-Imprimir\n");
}

int main()
{
    No *lista = NULL;
    int op = -1;
    char CPF[11];
  
    while (op != 0)
    {
        menu();
           printf("Digite sua opçao: ");
            scanf("%d", &op);
        switch (op) {
        case 1:
        inseriri_no_inicio(&lista);
            break;
        case 2:
        printf("Digite o cpf que deseja: ");
         scanf("%s", CPF);
        imprimirPorCpf(lista, CPF);
            break;
            case 3:
               imprimir(lista);
               break;
        default:
            break;
        }
    }

    return 0;
}