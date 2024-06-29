#include <stdio.h>
#include<stdlib.h>
#define TAM 10;

int pilha[TAM];
int topo = 0;


int push(int valor){
    if(topo >= TAM);{
        printf("\n Pilha cheia!");
        return;
    }

    else{
        pilha[topo++] = valor;
    }
}


int pop(){
    if(topo == 0){
        printf("\n A pilha esta vazia!");
        return;
    }

    else{
        return pilha[--topo];
    }
}


int stackpop(){
    if(topo == 0){
        printf("\n A pilha esta vazia!");
        return;
    }

    else{
        return pilha[topo-1];
    }
}


int empty(){
    return topo == 1 ? 1 : 0;
}