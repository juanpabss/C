#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paciente{
    char nome[50];
    char plano_de_saude[100];
    int idade;
    struct paciente *proximo;
}paciente;

typedef struct ref{
    paciente *inicio;
    paciente *fim;
    int tamanho;
}ref;

void adicionarPaciente(ref **lista){
    paciente *novo = (paciente *)malloc(sizeof(paciente));

    if (novo == NULL){
        printf("\nErro de alocacao!");
    }else{
        system("cls");
        printf("\n\t ***Coleta de dados");
        printf("\nDigite o nome do paciente: ");
        scanf(" %49[^\n]s", novo->nome);
        printf("\nDigite a idade do paciente: ");
        scanf(" %d", &novo->idade);
        printf("\nDigite o tipo de plano de saude: ");
        scanf(" %99[^\n]s", novo->plano_de_saude);
        novo->proximo = NULL;

        if ((*lista)->inicio == NULL){
            (*lista)->inicio = novo;

        }else{
            (*lista)->fim->proximo = novo;
        }
        (*lista)->fim = novo;
        (*lista)->fim->proximo = NULL;
        (*lista)->tamanho++;
    }

};
void imprimirFila(ref *lista){

    paciente *aux = (*lista).inicio;
    int contador = 0;

    printf("\n\t---Fila de espera---");
    if(aux == NULL){
        printf("\nfila vazia\n");
        return;
    }else{
        while(aux != NULL){
            contador++;
            printf("\n%d", contador);
            printf("\nNome do paciente: %s", aux->nome);
            printf("\nIdade do paciente: %d", aux->idade);
            printf("\nPlano do paciente: %s\n", aux->plano_de_saude);
            aux = aux->proximo;
        }
        printf("\nnumero de pacientes em espera: %d", (*lista).tamanho);
        //printf("\nInicio: %s", (*lista).inicio);
        //printf("\nFim: %s", (*lista).fim);
        //printf("\n%s", (*lista).inicio->proximo);
        printf("\n\t\t...\n");
    }

};
void removerFila(ref **lista){
    paciente *aux =(*lista)->inicio;


    if(aux != NULL){
        if(aux->proximo == NULL){
            (*lista)->inicio = NULL;
            (*lista)->fim = NULL;
            (*lista)->tamanho--;
            printf("\nPaciente %s atendido e removido da fila de espera.\n", aux->nome);
            free(aux);

        }else{
            (*lista)->inicio = aux->proximo;
            (*lista)->tamanho--;
            printf("\nPaciente %s atendido e removido da fila de espera.\n", aux->nome);
            free(aux);
        }

    }else{
        printf("\nA Fila esta vazia!\n");
        return;
    }


};
void verificar(ref *lista, char* nome){
    paciente *aux = (*lista).inicio;
    int contador = 0;

    if(aux != NULL){
        if (strcmp(aux->nome, nome) == 0){
            printf("\nO paciente %s e o primerio da fila\n", aux->nome);
            return;
        }else{
           while(aux != NULL && strcmp(aux->nome, nome) != 0) {
            contador++;
            aux = aux->proximo;
        }
        }
        if(aux != NULL){
            printf("\nTem %d pacientes na frente do paciente %s.\n", contador, nome);
        }else {
            printf("\nA fila tem %d pacientes, mas %s não esta registrado.\n", contador, nome);
        }

        

    }else{
        printf("\nA lista esta vazia, esse paciente ainda nao foi registrado\n");
        return;
    }
};
int main (){
    ref *lista =(ref*)malloc(sizeof(ref));
    (* lista).inicio = NULL;
    (* lista).fim = NULL;
    (* lista).tamanho = 0;
    char op;
    char nome[50];

    while (1){
        printf("\n******************AUTO_PLANO ******************");
        printf("\n\t 1 - Adicionar paciente na fila");
        printf("\n\t 2 - Imprimir lista de pacientes");
        printf("\n\t 3 - Verificar quantos pacientes tem na frente");
        printf("\n\t 4 - Remover paciente da lista");
        printf("\n\t 0 - sair");
        printf("\n***************************************************");
        printf("\nEscolha uma opcao: ");
        scanf(" %c", &op);

        switch(op){
            case '1':
            adicionarPaciente(&lista);
            break;
            case '2':
            imprimirFila(lista);
            break;
            case '3':
            printf("Digite o nome do paciente: ");
            scanf(" %49[^\n]s", nome);
            verificar(lista,nome);
            break;
            case '4':
            removerFila(&lista);
            break;
            case '0':
            printf("\nTenha um bom dia...");
            exit(1);
            break;
            default:
            printf("\nOpcao invalida!");
            break;
        };
    };
    return 0;
};
