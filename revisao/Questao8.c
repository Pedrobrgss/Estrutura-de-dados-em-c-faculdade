#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 106

int pilha[TAM];
int topo = 0;
void push(int valor);
int pop();
int empty();
void min();

int main()
{
    int qtd_operacoes;
    char operacao[10];
    int valor;

    scanf("%d", &qtd_operacoes);

    for(int i=0; i<qtd_operacoes;i++)
    {
        scanf("%s", operacao);
        if (strcmp(operacao, "push")==0||
            strcmp(operacao, "Push")==0||
            strcmp(operacao, "PUSH")==0)
        {
            scanf("%d", &valor);
            push(valor);
        }
         if (strcmp(operacao, "pop")==0||
             strcmp(operacao, "Pop")==0||
             strcmp(operacao, "POP")==0)
        {
            pop();
        }
         if (strcmp(operacao, "min")==0||
             strcmp(operacao, "Min")==0||
             strcmp(operacao, "MIN")==0)
        {
            min();
        }
    }
    
    return 0;
}

void push(int valor)
{
    if(topo > TAM)
    {
        printf("Pilha cheia!");
        return;
    }

    else
    {
        pilha[topo++] = valor;
    }
}

int pop()
{
    if(topo == 0)
    {
        printf("Pilha vazia\n");
    }

    else
    {
        return pilha[--topo];
    }
}

int empty()
{
    return topo == 0 ? 1 : 0;
}

void min()
{
    int valor_menor;
    valor_menor = pilha[0];

    if(empty())
    {
        printf("Pilha vazia");
    }
   
    for(int i=0;i<topo;i++)
    {
        if(pilha[i] < valor_menor)
        {
            valor_menor = pilha[i];
        }
    }
    printf("%d",valor_menor);
}

