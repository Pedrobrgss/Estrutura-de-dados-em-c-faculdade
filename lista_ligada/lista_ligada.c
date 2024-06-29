#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct registro *inicio;
}lista;


typedef struct registro{
    int valor;
    struct registro *prox;
}registro;


lista * cria_lista(){
    
    lista *nova_lista;

    nova_lista = (lista *)malloc(sizeof(lista));
    nova_lista->inicio = NULL;
    nova_lista->qtd = 0;

    return nova_lista;
}


registro * cria_registro(){

    registro *novo_registro;

    novo_registro = (registro *)malloc(sizeof(registro));
    novo_registro->prox = NULL;
    novo_registro->valor = 0;

    return novo_registro;
}


void inserir_registro_final(lista *lista1, int novo_valor){

    registro *novo_registro;
    registro *auxiliar;

    if(lista1 == NULL){
        return;
    }

    novo_registro = cria_registro();
    novo_registro->valor = novo_valor;

    if(lista1->inicio == NULL){
        lista1->inicio = novo_registro;
    }

    else{
        auxiliar = lista1->inicio;

        while (auxiliar->prox != NULL){
            auxiliar = auxiliar->prox;
        }
        
        auxiliar->prox = novo_registro;
    }
    lista1->qtd++;
}


void inserir_registro_inicio(lista *lista1, int novo_valor){

    registro *novo_registro;

    if(lista1 == NULL){
        return;
    }

    novo_registro = cria_registro();
    novo_registro->valor = novo_valor;

    if(lista1->inicio == NULL){
        lista1->inicio = novo_registro;
    }

    else{
        novo_registro->prox = lista1->inicio;
        lista1->inicio = novo_registro;
    }
    lista1->qtd++;
}

void mostrar_lista(lista *lista1){

    registro *auxiliar;

    if(lista1->inicio == NULL){
        printf("A lista está vazia! ");
    }

    else{
        auxiliar = lista1->inicio;

        while (auxiliar != NULL){
            printf("\n Valor: %d", auxiliar->valor);
            auxiliar = auxiliar->prox;
        }
    }
}


void menu(lista *lista1){

    int opcao = 0;
    int numero;

    do{
        printf("\n\n1 - Inserir no final da lista");
        printf("\n2 - Inserir no inicio da lista");
        printf("\n3 - mostrar lista");
        printf("\n5 - sair");
        printf("\n--> ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("Digite o numero que deseja inserir no final da lista: ");
            scanf("%d", &numero);
            inserir_registro_final(lista1,numero);
            break;
        
        case 2:
            printf("Digite o numero que deseja inserir no inicio da lista: ");
            scanf("%d", &numero);
            inserir_registro_inicio(lista1, numero);

        case 3:
            mostrar_lista(lista1);
            break;

        case 5:
            printf("Saindo do programa...");
            break;

        default:
            printf("Valor inserido invalido!");
            break;
        }
    }while(opcao != 5);
}


int main(){

    system("cls");
    lista *lista1;
    lista1 = cria_lista();
    menu(lista1);

    return 0;
}