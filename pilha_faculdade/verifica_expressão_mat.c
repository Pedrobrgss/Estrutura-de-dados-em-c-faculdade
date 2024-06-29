#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    struct registro *topo;
}pilha;


typedef struct registro{
    char caractere;
    struct registro *prox;
}registro;


pilha * cria_pilha(){
    return (pilha*)calloc(1,sizeof(pilha));
}


registro * cria_registro(){
    return (registro*)calloc(1,sizeof(registro));
}


int empty(pilha *p){
    if(p->topo == NULL){
        return 1;
    }

    else{
        return 0;
    }
}


void push(pilha *p, char c){
    registro *novo = cria_registro();
    novo->caractere = c;

    if(empty(p)){
        p->topo = novo;
    }

    else{
        novo->prox = p->topo;
        p->topo  = novo;
    }
}


char pop(pilha *p){
    char retorno;

    if(empty(p)){
        return printf("Esta vazia");
    }

    else{
        retorno = p->topo->caractere;
        p->topo=p->topo->prox;
        return retorno;
    }
}


int verifica_expressao(pilha *p, char x[]){
    int valido;
    valido = 1;
    int i = 0;

    while(x[i] != '\0'){
        if(x[i] == '(' || x[i] == '[' || x[i] == '{'){
            push(p,x[i]);
        }

        if(x[i] == ')' || x[i] == ']' || x[i] == '}'){
            if(empty(p)){
                valido = 0;
            }

            else{
                char retorno;
                retorno = pop(p);
                if((x[i] == ')' && retorno != '(') || (x[i] == ']' && retorno != '[') || (x[i] == '}' && retorno != '{')){
                    valido = 0;
                }
            }
        }
        i++;
    }
    if(!empty(p)){
        valido = 0;
    }

    return valido;
}


int main(){
    pilha *p;
    p = cria_pilha();
    char expressao[100];
    printf("Escreva uma expressao para ser verificada: ");
    scanf("%[^\n]", expressao);

    int valido = verifica_expressao(p,expressao);

    if(valido == 1){
        printf("A expressao e valida!");
    }

    else{
        printf("A expressao e invalida!");
    }

}