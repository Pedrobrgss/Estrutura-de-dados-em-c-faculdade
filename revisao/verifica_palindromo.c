#include <stdio.h>
#include <stdlib.h>
#define TAM 50

char pilha[TAM];
int topo = 0;

void push(char valor);
char pop();
int empty();
int verifica_palindromo(char palavra[]);

int main()
{
    char palavra[TAM];
    int valido;
    printf("Digite a palavra palindromo: ");
    scanf("%s", palavra);
    valido = verifica_palindromo(palavra);
    if(valido)
    {
        printf("palindromo");
    }
    else
    {
        printf("nao e palindromo");
    }
    return 0;
}

void push(char valor)
{
    if(topo >= TAM)
    {
        return;
    }
    else
    {
        pilha[topo++] = valor;
    }
}

char pop()
{
    if(empty())
    {
        return -1;
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

int verifica_palindromo(char palavra[])
{
    int valido = 1;
    int i = 0;

    while(palavra[i] != '\0')
    {
        push(palavra[i]);
        i++;
    }
    i=0;
    while(palavra[i] != '\0')
    {
        if(palavra[i] != pop())
        {
            valido = 0;
        }
        i++;
    }
    if(!empty())
    {
        valido = 0;
    }
    return valido;
}