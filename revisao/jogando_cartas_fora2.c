#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    struct baralho *inicio;
    struct baralho *final;
    int qtd;
}fila;

typedef struct baralho
{
    int valor;
    struct baralho *prox;
    struct baralho *ant;
}baralho;

fila * criar_fila();
baralho * criar_baralho();
void inserir_no_baralho(int qtd, fila *f);
void jogando_cartas_fora(fila *f);
void tirar_do_topo(fila *f, baralho *novo_inicio);

int main()
{
    fila *f;
    f = criar_fila();
    int valor;
    scanf("%d", &valor);
    for(int i=0;i<valor;i++)
    {
        inserir_no_baralho(i+1, f);
    }
    jogando_cartas_fora(f);
    return 0;
}

fila * criar_fila()
{
    return (fila *)calloc(1,sizeof(fila));
}

baralho * criar_baralho()
{
    return (baralho *)calloc(1,sizeof(baralho));
}

void inserir_no_baralho(int valor, fila *f)
{
    baralho *novo_baralho;
    novo_baralho = criar_baralho();
    novo_baralho->valor = valor;

    if(f->inicio == NULL && f->final == NULL)
    {
        f->inicio = novo_baralho;
        f->final = novo_baralho;
    }
    else
    {
        f->inicio->ant = novo_baralho;
        novo_baralho->prox = f->inicio;
        f->inicio = novo_baralho;
    }
    f->qtd++;
}

void tirar_do_topo(fila *f, baralho *novo_inicio)
{
    f->final = novo_inicio->ant;
    f->inicio->ant = novo_inicio;
    novo_inicio->prox = f->inicio;
    f->inicio = novo_inicio;
    f->final->prox = NULL;
}

void jogando_cartas_fora(fila *f)
{

    if(f->qtd < 2)
    {
        return;
    }
    else
    {
        printf("Discarted cards: ");
    }
    while(f->qtd > 1)
    {
        if(f->qtd != 2)
        {
            printf("%d, ",f->final->valor );
        }
        else
        {
            printf("%d ", f->final->valor);
        }
        f->final = f->final->ant;
        tirar_do_topo(f,f->final);
        f->qtd--;
    }
    printf("\nRemaining card: %d\n", f->inicio->valor);
}
