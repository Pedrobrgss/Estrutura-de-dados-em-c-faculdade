#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

long long int *cria_vetor(long long int tamanho);
long long int *quicksort(long long int *vet, long long int inicio, long long int fim);
void mostrar_vetor(long long int *vet, long long int tamanho);


int main()
{
    long long int *vet;
    long long int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%lld", &tamanho);

    // Cria um vetor embaralhado de tamanho especificado
    vet = cria_vetor(tamanho);

    printf("Vetor embaralhado:\n");
    mostrar_vetor(vet, tamanho);

   // Ordena o vetor usando Merge Sort
    printf("Vetor organizado com quick Sort:\n");
    quicksort(vet, 0, tamanho - 1);
    mostrar_vetor(vet, tamanho);
    return 0;
}


long long int *cria_vetor(long long int tamanho)
{
    long long int *vet;
    long long int i;
    // Inicializa o gerador de números aleatórios com a semente baseada no tempo atual
    srand(time(NULL));
    int sorteio;
    int aux;

    vet = (long long int *)calloc(tamanho,sizeof(long long int));

    for(i=0; i<tamanho; i++)
    {
        vet[i] = i + 1;
    }

    for(i=0; i<tamanho; i++)
    {
        sorteio = rand() % tamanho;
        aux = vet[i];
        vet[i]= vet[sorteio];
        vet[sorteio] = aux;
    }

    return vet;
}


void mostrar_vetor(long long int *vet, long long int tamanho)
{
    long long int i;

    for(i=0;i<tamanho;i++)
    {
        printf("%lld ", vet[i]);
    }
    printf("\n");
}


long long int *quicksort(long long int *vet, long long int inicio, long long int fim)
{
    if(inicio > fim)
    {
        return;
    }

    long long int pivo;
    long long int aux;
    long long int troca;

    pivo = inicio;
    aux = fim;

    while(pivo!=aux)
    {
        if(pivo < aux)
        {
            if(vet[pivo] > vet[aux])
            {
                troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = troca;

                troca = pivo;
                pivo = aux;
                aux = troca;
            }
        }

        else
        {
            if(vet[pivo] < vet[aux])
            {
                troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = troca;

                troca = pivo;
                pivo = aux;
                aux = troca;
            }
        }

        if(pivo < aux)
        {
            aux--;
        }

        else
        {
            aux++;
        }
    }

    quicksort(vet, inicio, pivo-1);
    quicksort(vet, pivo +1, fim);
}