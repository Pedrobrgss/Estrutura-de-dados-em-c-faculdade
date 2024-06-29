#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


long long int *cria_vetor(long long int tamanho);
void mostrar_vetor(long long int *vet, long long int tamanho);
void bubblesort(long long int *vet, long long int tamanho);
void insertionsort(long long int *vet, long long int tam);
void selectionsort(long long int *vet, long long int tam);
void mergesort(long long int *vet, long long int inicio, long long int fim); 
void junta(long long *vet, long long int inicio, long long int meio, long long int fim);
void quicksort(long long int *vet, long long int inicio, long long int fim); 


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

    // Ordena o vetor usando Bubble Sort
    printf("Vetor organizado com Bubble Sort:\n");
    bubblesort(vet, tamanho);
    mostrar_vetor(vet, tamanho);

    // Cria um novo vetor embaralhado
    vet = cria_vetor(tamanho);

    // Ordena o vetor usando Insertion Sort
    printf("Vetor organizado com Insertion Sort:\n");
    insertionsort(vet, tamanho);
    mostrar_vetor(vet, tamanho);

    // Cria um novo vetor embaralhado
    vet = cria_vetor(tamanho);

    // Ordena o vetor usando Selection Sort
    printf("Vetor organizado com Selection Sort:\n");
    selectionsort(vet, tamanho);
    mostrar_vetor(vet, tamanho);

    // Cria um novo vetor embaralhado
    vet = cria_vetor(tamanho);

    // Ordena o vetor usando Merge Sort
    printf("Vetor organizado com Merge Sort:\n");
    mergesort(vet, 0, tamanho - 1);
    mostrar_vetor(vet, tamanho);

    // Cria um novo vetor embaralhado
    vet = cria_vetor(tamanho);

    // Ordena o vetor usando Quick Sort
    printf("Vetor organizado com Quick Sort:\n");
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


void bubblesort(long long int *vet, long long int tamanho)
{
    long long int passadas;
    long long int i;
    long long int aux;
    int trocou;
    trocou = 1;

    // Loop de passadas
    for(passadas = 0; passadas < tamanho-1 && trocou; passadas++)
    {
        // No início de cada passada, assume que não haverá trocas
        trocou = 0;

        // Loop interno para percorrer e comparar os elementos do vetor
        for(i=0; i < tamanho - 1 - passadas; i++)
        {
            // Se os elementos adjacentes estão fora de ordem, troque-os
            if(vet[i] > vet[i+1])
            {
                trocou = 1; // Indica que uma troca ocorreu
                aux = vet[i]; // Armazena temporariamente vet[i]
                vet[i] = vet[i+1]; // Coloca vet[i + 1] na posição i
                vet[i+1] = aux; // Coloca aux (vet[i] original) na posição i + 1
            }
        }
    }
}


void insertionsort(long long int *vet, long long int tam)
{
    long long int i, j, key;

    // Percorre o vetor começando do segundo elemento
    for (i = 1; i < tam; i++) {
        key = vet[i]; // Armazena o valor atual em key
        j = i - 1;

        // Move os elementos da parte ordenada que são maiores que a chave
        // uma posição à frente
        while (j >= 0 && vet[j] > key) {
            vet[j + 1] = vet[j]; // Move o elemento para a direita
            j = j - 1; // Avança para o elemento anterior
        }

        // Insere a chave na posição correta
        vet[j + 1] = key;
    }
}


void selectionsort(long long int *vet, long long int tamanho)
{
    long long int ind_menor, i, j, aux;

    // Loop para percorrer o vetor
    for (i = 0; i < tamanho - 1; i++)
    {
        // Define o índice do menor elemento como o índice atual
        ind_menor = i;

        // Loop para encontrar o índice do menor elemento na sublista não ordenada
        for (j = i + 1; j < tamanho; j++)
        {
            // Se o elemento atual for menor que o menor elemento encontrado até agora
            if (vet[j] < vet[ind_menor])
            {
                // Atualiza o índice do menor elemento
                ind_menor = j;
            }
        }

        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        aux = vet[ind_menor];
        vet[ind_menor] = vet[i];
        vet[i] = aux;
    }
}

void mergesort(long long int *vet, long long int inicio, long long int fim) 
{
    long long int meio;

    // Condição de parada: se ainda houver mais de um elemento na faixa do vetor
    if (inicio < fim)  
    {
        // Calcula o índice do meio da faixa do vetor
        meio = (inicio + fim) / 2;

        // Chama recursivamente mergesort para ordenar a primeira metade do vetor
        mergesort(vet, inicio, meio);

        // Chama recursivamente mergesort para ordenar a segunda metade do vetor
        mergesort(vet, meio + 1, fim);

        // Mescla as duas metades ordenadas
        junta(vet, inicio, meio, fim);
    }
}

// Função para mesclar duas sublistas ordenadas em um único vetor ordenado
void junta(long long *vet, long long int inicio, long long int meio, long long int fim)
{
    long long int i, j, *aux, k;

    // Aloca memória para um vetor auxiliar que armazenará os elementos mesclados
    aux = (long long int *)calloc(fim - inicio + 1, sizeof(long long int));

    // Inicializa os índices para percorrer as duas sublistas e o vetor auxiliar
    i = inicio;
    j = meio + 1;
    k = 0;

    // Enquanto houver elementos em ambas as sublistas, compara e insere o menor no vetor auxiliar
    while (i <= meio && j <= fim) 
    {
        if (vet[i] <= vet[j]) 
        {
            aux[k] = vet[i];
            k++;
            i++;
        } 
        else 
        {
            aux[k] = vet[j];
            k++;
            j++;
        }
    }

    // Insere os elementos restantes da primeira sublista, se houver
    while (i <= meio)
    {
        aux[k] = vet[i];
        k++;
        i++;
    }

    // Insere os elementos restantes da segunda sublista, se houver
    while (j <= fim) 
    {
        aux[k] = vet[j];
        k++;
        j++;
    }

    // Copia os elementos mesclados de volta ao vetor original, começando pelo índice de início
    for (i = 0; i < (fim - inicio + 1); i++)
    {
        vet[inicio + i] = aux[i];
    }

    // Libera a memória alocada para o vetor auxiliar
    free(aux);
}

void quicksort(long long int *vet, long long int inicio, long long int fim) 
{
    // Verifica se a faixa do vetor possui mais de um elemento
    if (inicio > fim)
        return;

    // Declaração das variáveis para o pivô e para as trocas
    long long int pivo, aux, troca;

    // Define o pivô como o primeiro elemento da faixa
    pivo = inicio;

    // Define o índice auxiliar como o último elemento da faixa
    aux = fim;

    // Loop enquanto o pivô não alcançar o índice auxiliar
    while (pivo != aux) 
    {
        // Se o pivô for menor que o índice auxiliar
        if (pivo < aux)
        {
            // Se o elemento no pivô for maior que o elemento no índice auxiliar
            if (vet[pivo] > vet[aux]) 
            {
                // Troca os elementos nos índices pivô e auxiliar
                troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = troca;

                // Troca os índices pivô e auxiliar
                troca = pivo;
                pivo = aux;
                aux = troca;
            }
        }
        // Se o pivô for maior que o índice auxiliar
        else 
        {
            // Se o elemento no pivô for menor que o elemento no índice auxiliar
            if (vet[pivo] < vet[aux]) 
            {
                // Troca os elementos nos índices pivô e auxiliar
                troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = troca;

                // Troca os índices pivô e auxiliar
                troca = pivo;
                pivo = aux;
                aux = troca;
            }
        }

        // Move o índice auxiliar em direção ao pivô ou para longe do pivô
        if (pivo < aux) 
        {
            aux--;
        } 
        else 
        {
            aux++;
        }
    }

    // Chamadas recursivas do quicksort para as subfaixas à esquerda e à direita do pivô
    quicksort(vet, inicio, pivo - 1);
    quicksort(vet, pivo + 1, fim);
}