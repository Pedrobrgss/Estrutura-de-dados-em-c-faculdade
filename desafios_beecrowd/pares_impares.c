//1259 beecrowd 
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    struct registro *inicio;
}lista;


typedef struct registro{
    int valor;
    struct registro *prox;
}registro;


lista * cria_lista(){
    return (lista *)calloc(1,sizeof(lista));
}


registro * cria_registro(){
    return (registro *)calloc(1,sizeof(registro));
}


void inserir_par_crescente(lista *l, int valor){
    registro *novo;
    registro *aux = NULL;
    registro *ant = NULL;

    novo = cria_registro();
    novo->valor = valor;

    if(l->inicio == NULL){
        l->inicio = novo;
    }

    else{
        aux = l->inicio;

        while(aux != NULL && aux->valor < novo->valor){
            ant = aux;
            aux = aux->prox ;
        }

        if(ant == NULL){
            novo->prox = aux;
            l->inicio = novo;
        }

        else{
            novo->prox = aux;
            ant->prox = novo;
        }
    }
}


void inserir_impar_decrescente(lista *l, int valor){
    registro *novo;
    registro *aux = NULL;
    registro *ant = NULL;

    novo = cria_registro();
    novo->valor = valor;

    if(l->inicio == NULL){
        l->inicio = novo;
    }

    else{
        aux = l->inicio;

        while(aux !=NULL && aux->valor > novo->valor){
            ant = aux;
            aux = aux->prox;
        }

        if(ant == NULL){
            novo->prox = aux;
            l->inicio = novo;
        }

        else{
            novo->prox = aux;
            ant->prox = novo;
        }
    }

}

lista * concatena_lista(lista *par, lista *impar){
    lista *lista_concatenada;
    registro *aux;

    lista_concatenada = par;
    aux = lista_concatenada->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = impar->inicio;
    return lista_concatenada;
}


void mostrar_lista(lista *l){
    registro *aux;
    aux = l->inicio;
    if(l == NULL){
        printf("Lista vazia");
    }

    else{
        while(aux != NULL){
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }
}

int main(){
    lista *lista_par;
    lista *lista_impar;
    int qtd;
    int valor;

    lista_par = cria_lista();
    lista_impar = cria_lista();

    printf("Insira a quantidade de linhas: ");
    scanf("%d", &qtd);

    for(int i = 0; i < qtd; i++){
        printf("Insira o valor a ser incluido na lista: ");
        scanf("%d", &valor);
        if(valor % 2 == 0){
            inserir_par_crescente(lista_par, valor);
        }  
        else{
            inserir_impar_decrescente(lista_impar,valor);
        }
    }

    lista *lista_concatenada = concatena_lista(lista_par, lista_impar);
    mostrar_lista(lista_concatenada);
    return 0;
}
