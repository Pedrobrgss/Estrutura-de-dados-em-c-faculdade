#include <stdio.h>
#include <stdlib.h>
#define TAM 55

char pilha[TAM];
int topo = 0;

void push(char valor);
char pop();
int empty();
int verifica_expressao(char x[]);

int main()
{
    char expressao[55];
    printf("Digite a expressao para ser analisada: ");
    scanf("%[^\n]",expressao);
    int valido = verifica_expressao(expressao);
    if(valido)
    {
        printf("Expressao bem formada");
    }
    else
    {
        printf("Expressao mal formada");
    }
    return 0;
}

void push(char valor)
{
    if(topo > TAM)
    {
        printf("Pilha cheia");
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
        return printf("Pilha vazia");
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

int verifica_expressao(char x[])
{
    int valido;
    int i;
    valido = 1;
    i = 0;

    while(x[i] != '\0')
    {
        if(x[i] == '{' || x[i] == '[' || x[i] == '(')
        {
            push(x[i]);
        }

        if(x[i] == '}' || x[i] == ']' || x[i] == ')')
        {
            if(empty())
            {
                valido = 0;
            }
            else
            {
                char retorno;
                retorno = pop();
                if((x[i] == ')' && retorno != '(') || (x[i] == ']' && retorno != '[') || (x[i] == '}' && retorno != '{'))
                {
                    valido = 0;
                }
            }
        }
        i++;
    }
    if(!empty())
    {
        valido = 0;
    }
    return valido;
}