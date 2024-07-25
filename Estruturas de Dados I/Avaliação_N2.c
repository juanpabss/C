#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tarefa{
    char nome[50];
    int quant_atividades;
    int hora_criacao;
    struct tarefa *proximo;
}tarefa;

typedef struct ref{
    tarefa *inicio;
    tarefa *fim;
    int tamanho;
}ref;

/*Minha variavel 'hora de criação' vai receber apenas as horas em formato simples, 
sem minutos e segundo, por que fiquei com medo de não coseguir manipular corretamnete essas informações,
e acabar por não fazer as questôes,*/ 

void inseirTarefa(ref **fila){
    tarefa *nova_tarefa = (tarefa *)malloc(sizeof(tarefa));

    if (nova_tarefa == NULL){
        printf("\nErro de alocacao!");
    }else{
        /*O horario de criação vai ser do tipo inteiro, da seguinte forma 22 horas, 9 horas, 8 ...*/
        printf("\n\t ***Informacoes");
        printf("\nDigite o nome do tarefa: ");
        scanf(" %49[^\n]s", nova_tarefa->nome);
        printf("\nDigite a digite a quantidade de atividades da tarefa: ");
        scanf(" %d", &nova_tarefa->quant_atividades);
        printf("\nDigite o horario de criacao( O horario vai de 1 hora ate 24 horas ,exemplo:22,7...): ");
        scanf(" %d", &nova_tarefa->hora_criacao);
        nova_tarefa->proximo = NULL; /* o novo a ser adicionado sempre aponta pra null, por estara no final da fila */
        
        /*verificando se a fila esta vazia */
        if ((*fila)->inicio == NULL){
            (*fila)->inicio = nova_tarefa;

        }else{
            (*fila)->fim->proximo = nova_tarefa;
        }
        
        /*essas proximas mudanças sempre acontecem, idependente de ser o primeiro ou não*/ 
        (*fila)->fim = nova_tarefa;
        (*fila)->fim->proximo = NULL;
        (*fila)->tamanho++;
    }
};

void imprimirTarefas(ref *fila){
    tarefa *aux = (* fila).inicio;/*criação de um auxiliar, para poder percorrer a lista sem alterar os valores*/
    int contador = 0;//essa variavel e para numerar as tarefas na impressao;
    
    printf("\n\t---Fila de Tarefas---");/*verificar se a lista esta vazia*/
    if(aux == NULL){
        printf("\nNão existe fila, Gerenciamento vazio!\n");
        return;
    }else{
        while(aux != NULL){
            contador++;
            printf("\n%d", contador);
            printf("\nNome do tarefa: %s", aux->nome);
            printf("\nQuantidades de atividades da tarefa: %d", aux->quant_atividades);
            printf("\nHora de inicio: %d hora(s)\n", aux->hora_criacao);
            aux = aux->proximo;
        }
        printf("\n\t\t...\n");
    }
};

void calcularAtividades(ref *fila){
    tarefa *aux = (* fila).inicio;/*criação de um auxiliar, para poder percorrer a lista sem alterar os valores*/
    int soma = 0;
    int i = 0; //filas

    printf("\n\t---Somatorio das atividades das tarefas:");
    if(aux == NULL){
        printf("\nNao existe atividades, gerenciamento vazio!\n");
        return;
    }else{
        while(aux != NULL){
            i++;
            soma += aux->quant_atividades;
            aux = aux->proximo;
        }
        
        printf("\n\ntotal de fila(s): %d ", i); 
        printf("\n\ntotal de atividades: %d ", soma);
    }
};

void tarefas_criadas_antes_de_determinada_hora (ref *fila){
    tarefa *aux = (* fila).inicio;
    int hora;
    int contador = 0;/*variavel para contar aqua qauntidade de tarefes antes da hora*/
    printf("\nDigite o horaio(entre 1 hora e 24 horas): ");
    scanf(" %d", &hora);

    if (hora > 24 || hora < 1){
        printf("\nHorario digitado e invalido!\n");
    }else{
        printf("\n\t---Resultado: ");
        if(aux == NULL){
            printf("\nNao existe fila, gerenciamento vazio!\n");
            return;
        }else{
            while(aux != NULL){
                if (aux->hora_criacao < hora){
                  contador++;
                }
                aux = aux->proximo;
            }
            if (contador == 0){
                printf("\nA fila nao possui nenhum elemento antes do horario informado\n");
            }else{
                printf("\nTotal de atividades antes da hora informada: %d \n ", contador);
            }
        }
     
    }
    
};

void executarTarefas(ref **fila){
    tarefa *aux  = (tarefa*)malloc(sizeof(tarefa));
    aux = (*fila)->inicio;

if ( aux == NULL){
        printf("\nfila de tarefas vazias!\n");
    }else{
        printf("\n1 atividade da primeira tarefa executada\n");
        printf("\nFila atualizada\n");
        if (aux->proximo == NULL){//verificar se a fila so tem 1;
            aux->quant_atividades--;// redução de atividade
            if(aux->quant_atividades == 0){
                free(aux);
            }
        }else{
            aux->quant_atividades--;// redução de atividade
            if(aux->quant_atividades == 0){/*verificar se a atividade exutada foi a ultima da tarefa*/
                (*fila)->inicio =(*fila)->inicio->proximo;
                free(aux);/*removendo tarefa que teve todas as atividades executada*/
            }else{
                //atualização de ponteiros;
                (*fila)->fim->proximo = (*fila)->inicio;
                (*fila)->inicio = (*fila)->inicio->proximo;
                (*fila)->fim = (*fila)->fim->proximo;
                (*fila)->fim->proximo = NULL;
            }
        }
    }
    
};

int main () {
    ref *fila =(ref *)malloc(sizeof(ref));
    (* fila).inicio = NULL;
    (* fila).fim = NULL;
    (* fila).tamanho = 0;
    char op;

    while (1){
        printf("\n");
        printf("+---------------------------- MENU ----------------------------+\n");
        printf("| 1 - Iserir nova tarefa                                       |\n");
        printf("| 2 - Imprimir ordem das tarefas                               |\n");
        printf("| 3 - Calcular atividades                                      |\n"); 
        printf("| 4 - Tarefas criadas antes de determinada hora                |\n");
        printf("| 5 - Executar tarefa                                          |\n");
        printf("| 0 - Sair                                                     |\n");
        printf("+--------------------------------------------------------------+\n");
        printf("Selecione uma opcao: ");
        scanf(" %c", &op);
        system("clear || cls");
        switch(op){
            case '1':
            inseirTarefa(&fila);
            break;
            case '2':
            imprimirTarefas(fila);
            break;
            case '3':
            calcularAtividades(fila);
            break;
            case '4':
            tarefas_criadas_antes_de_determinada_hora(fila);
            break;
            case '5':
            executarTarefas(&fila);
            break;
            case '0':
            printf("\nSaindo...");
            exit(1);
            break;
            default:
            printf("\nOpcao invalida!");
            break;
        };
    };
    
    return 0;
}