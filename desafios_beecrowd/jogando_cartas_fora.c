// 1110 beecrowd

#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    struct baralho *inicio;
    struct baralho *final; 
    int qtd_cartas;
}fila;


typedef struct baralho{
    int numero_carta;
    struct baralho *prox;
}baralho;


fila * cria_fila(){
    fila *nova_fila;

    nova_fila = (fila *)malloc(sizeof(fila));
    nova_fila->final = NULL;
    nova_fila->inicio=NULL;
    nova_fila->qtd_cartas = 0;

    return nova_fila;
}


baralho * criar_baralho(){
    baralho * novo_baralho;

    novo_baralho = (baralho *)malloc(sizeof(fila));
    novo_baralho->numero_carta = 0;
    novo_baralho->prox = NULL;

    return novo_baralho;
}


void inserir_no_baralho(fila *fila1, int quantidade){
    baralho *novo_baralho;
    baralho *aux;

    for(int i=0; i<=quantidade; i++){
        novo_baralho = criar_baralho();      
        novo_baralho->numero_carta = i+1;
        fila1->qtd_cartas = quantidade;

        if(fila1->inicio==NULL){
            fila1->inicio = novo_baralho;
        }

        else{
            aux = fila1->inicio;
            while(aux->prox != NULL){
                aux = aux->prox;
            }

            aux->prox = novo_baralho;
        }
    }
    fila1->final = aux;
}


void tirar_do_topo(fila *fila1, baralho *novo_topo){
    fila1->final->prox = novo_topo;
    fila1->final = novo_topo;
    fila1->inicio = fila1->inicio->prox;
    novo_topo->prox = NULL;
}

void jogar_cartas_fora(fila *fila1){

    if (fila1->qtd_cartas < 2){
        return;
    }
    
    else{
        printf("Discarded cards: ");
    }
    
    while(fila1->qtd_cartas > 1){

        if(fila1->qtd_cartas != 2){
            printf("%d, ", fila1->inicio->numero_carta);
        }
        else{
            printf("%d",fila1->inicio->numero_carta);
        }
        fila1->inicio = fila1->inicio->prox;
        
        tirar_do_topo(fila1, fila1->inicio);

        fila1->qtd_cartas --;   
    }

    printf("\nRemaining card: %d\n",fila1->inicio->numero_carta);
}


int main(){

    fila *fila1;
    fila1=cria_fila();
    int numero_de_cartas;
    
    do{
    scanf("%d", &numero_de_cartas);
    inserir_no_baralho(fila1, numero_de_cartas);
    jogar_cartas_fora(fila1);
    fila1->inicio = NULL;

    } while (numero_de_cartas != 0);
    
    return 0;
}