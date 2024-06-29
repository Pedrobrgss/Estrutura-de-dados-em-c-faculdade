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


void inserir_registro_ordem_crescente(lista *lista1, int novo_valor){

    registro *novo_registro;
    registro *auxiliar = NULL;
    registro *anterior = NULL;

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

        while (auxiliar != NULL && auxiliar->valor < novo_registro->valor){
            anterior = auxiliar;
            auxiliar = auxiliar->prox;
        }
        
        if(anterior == NULL){
            lista1->inicio = novo_registro;
            novo_registro->prox = auxiliar ;
        }

        else{
            novo_registro->prox = auxiliar;
            anterior->prox = novo_registro;
        }
    }
}


void mostrar_lista(lista *lista1){

    registro *auxiliar;

    if(lista1->inicio == NULL){
        printf("A lista ordenada esta vazia!");
    }

    else{
        auxiliar = lista1->inicio;

        while (auxiliar != NULL)
        {
            printf("Valor: %d\n", auxiliar->valor);
            auxiliar = auxiliar->prox;
        }
    }
}


void menu(lista *lista1){

    int opcao;
    int numero;

    do{
        printf("\n1 - inserir valor na lista ordenada");
        printf("\n2 - mostrar lista ordenada");
        printf("\n5 - Sair");
        printf("\n-> ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("Informe o valor que deseja ser inserido na lista\n-> ");
            scanf("%d", &numero);
            inserir_registro_ordem_crescente(lista1, numero);
            break;
        
        case 2:
            mostrar_lista(lista1);
            break;

        case 5:
            printf("Saindo do programa...");
            break;

        default:
            printf("opcao inserida invalida");
            break;
        }

    }while(opcao != 5);
}


int main(){

    lista *lista1;
    lista1 = cria_lista();

    menu(lista1);

    return 0;
}
