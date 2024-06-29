#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct lista
{
    struct registro *inicio;
    struct registro *final;
    int qtd;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

lista *criar_lista();
registro *criar_registro();
void menu(lista *l);
void inserir_na_lista(int valor, lista *l);
void remover(lista *l);
void zerar_lista(lista *l);
void inverter_lista(lista *l);
void mostrar_lista(lista *l);

int main()
{
    lista *l;
    l = criar_lista();
    menu(l);
    return 0;
}

lista *criar_lista()
{
    return (lista *)calloc(1, sizeof(lista));
}

registro *criar_registro()
{
    return (registro *)calloc(1, sizeof(registro));
}

void inserir_na_lista(int valor, lista *l)
{
    registro *novo;
    novo = criar_registro();
    novo->valor = valor;

    if (l == NULL)
    {
        printf("Apaguei a lista fudeu");
    }
    if (l->inicio == NULL && l->final == NULL)
    {
        l->inicio = novo;
        l->final = novo;
    }

    else
    {
        l->final->prox = novo;
        l->final = novo;
    }

    l->qtd++;
}

void remover(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("Fila vazia\n");
        return;
    }
    else
    {
        registro *aux = l->inicio;
        l->inicio = l->inicio->prox; 
        free(aux);                   
        l->qtd--;                   

        if (l->inicio == NULL)
        { 
            l->final = NULL; 
        }

        printf("Primeiro elemento removido\n");
    }
}

void zerar_lista(lista *l)
{
    registro *aux;
    aux = l->inicio;

    if (l->inicio == NULL && l->final == NULL)
    {
        printf("Fila vazia\n");
    }

    else
    {
        while (aux != NULL && l->inicio != NULL && l->final != NULL)
        {
            remover(l);
            aux = aux->prox;
        }
    }
}

void inverter_lista(lista *l)
{
    registro *atual;
    registro *anterior;
    registro *proximo;
    anterior = NULL;
    atual = l->inicio;

    if (l->inicio == NULL && l->final == NULL)
    {
        printf("Fila vazia\n");
        return;
    }

    else
    {
        while (atual != NULL)
        {
            proximo = atual->prox;
            atual->prox = anterior;
            anterior = atual;
            atual = proximo;
        }
    }
    l->final = l->inicio;
    l->inicio = anterior;
}

void mostrar_lista(lista *l)
{
    registro *aux;
    aux = l->inicio;
    if (l->inicio == NULL && l->final == NULL)
    {
        printf("Fila vazia\n");
        return;
    }

    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n\n");
}

void menu(lista *l)
{
    int opcao;
    int valor;

    do
    {
        sleep(1);
        system("cls || clear");
        printf("1.Incluir na fila\n");
        printf("2.Remover da fila\n");
        printf("3.zerar a fila\n");
        printf("4.Inverter a fila\n");
        printf("5.mostrar fila\n");
        printf("6.Sair\n");
        printf("Digite a opcao desejada-> ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido na fila\n");
            printf("->");
            scanf("%d", &valor);
            inserir_na_lista(valor, l);
            printf("Valor inserido");
            break;

        case 2:
            remover(l);
            break;

        case 3:
            zerar_lista(l);
            printf("fila zerada\n");
            break;

        case 4:
            inverter_lista(l);
            printf("fila invertida\n\n");
            break;

        case 5:
            mostrar_lista(l);
            break;
        case 6:
            break;

        default:
            break;
        }
    } while (opcao != 6);
}
