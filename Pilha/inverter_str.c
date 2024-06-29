#include<stdio.h>
#include<stdlib.h>

/*
Escreva um algoritmo para inverter a ordem de cada palavra de um string, preservando a ordem das palavras. Por exemplo, dado o texto:
ABRA A PORTA MARIQUINHA a saida deve ser ARBA A ATROP AHNIUQIRAM

*/
typedef struct no{
    char caracter;
    struct no *proximo;
}No;

No* empilhar(No *pilha, char valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->caracter = valor;
        novo->proximo = pilha;
        return novo;
    }
    else
        printf("\tErro ao alocar memoria!\n");
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}

void inverter_palavra(char x[]){ 
    int i = 0;
    No *remover, *pilha = NULL;

    while(x[i] != '\0'){
        if(x[i] != ' '){
            pilha = empilhar(pilha, x[i]);
        }
        else{
            while(pilha){
                remover = desempilhar(&pilha);
                printf("%c",remover->caracter);
                free(remover);
            }
            printf(" ");
        }
        i++;
    }
    while(pilha){ //
        remover = desempilhar(&pilha);
        printf("%c",remover->caracter);
        free(remover);
    }
    printf("\n");
}

int main(){
    char texto[50] = "ABBABABA";
    printf("%s\n",texto);
    inverter_palavra(texto);
}