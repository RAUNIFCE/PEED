#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
    struct No* anterior;
} No;
//criei um VOID pra inserir no inicio
void inserirInicio(No** inicio,int dado){
    No* novo=(No*)malloc(sizeof(No));
    novo->dado=dado;
    if(*inicio==NULL){
        novo->proximo=novo;
        novo->anterior=NULL;
        *inicio=novo;
        return;
    }
    novo->proximo=*inicio;
    novo->anterior=NULL;
    (*inicio)->anterior=novo;
    *inicio=novo;
}
//primeiro exercicio
void inserirordenado(No** inicio, int valor){

    //criei o nó
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    No* temp1 = *inicio;/*mais atualizado*/
    No* temp2 = *inicio;/*1 ponteiro para trás*/

    //fui até o possível nó seguinte
        while (temp1 != NULL&& (temp1->dado)<valor){
            temp1 = temp1->proximo;
        }
    //se ele tiver no meio da lista
    if(temp1!=NULL&&temp1->anterior!=NULL){
    temp2 = temp1->anterior;
    novo->proximo=temp1;
    novo->anterior=temp1->anterior;
    temp2->proximo=novo;
    temp1->anterior=novo;

    }

     temp2 = temp1->anterior;

    //se tiver no final
    if(temp1==NULL){
        inserirFim(&inicio,valor);
        return;
    }
    //se tiver no começo
    if(temp2==NULL){
        inserirInicio(inicio,valor);
        return;
    }
}
//Exercicio 2 remover impares
void removerimpares(No** lista){
    No* atual = *lista;

    while(atual!=NULL){
        No* proximo = atual->proximo;
        if(atual->dado%2==1){
            if(atual->anterior==NULL){
                *lista=atual->proximo;
                (*lista)->anterior=NULL;
                free(atual);

            }
            else if(atual->proximo!=NULL){
                atual->proximo->anterior=atual->anterior;
                atual->anterior->proximo=atual->proximo;
                free(atual);
            }
            else{
                atual->anterior->proximo=atual->proximo;
                free(atual);
                 }


        }

       atual = proximo;
    }

}
//Terceiro exercicio remover duplicatas
void removerduplicatas(No** lista){
    No* p1 = *lista;

    while(p1!=NULL){
         No* p2 =p1->proximo;
        while(p2!=NULL){
            No* proximo =p2->proximo;
                if(p1->dado==p2->dado){
                        if(p2->proximo!=NULL){
                            p2->proximo->anterior= p2->anterior;
                            p2->anterior->proximo= p2->proximo;
                            free( p2);
                        }
                        else{
                             p2->anterior->proximo= p2->proximo;
                            free(p2);
                         }
                }
                p2=proximo;
        }
    p1=p1->proximo;
    }
}
void inserirFim(No** inicio, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;

    if (*inicio == NULL) {
        novo->anterior = NULL;
        *inicio = novo;
        return;
    }

    No* temp = *inicio;
    while (temp->proximo != NULL)
        temp = temp->proximo;

    temp->proximo = novo;
    novo->anterior = temp;
}


void removerInicio(No** lista) {
    if (*lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    No* temp = *lista;
    *lista = temp->proximo;
    (*lista)->anterior=NULL;
    free(temp);
}

void exibir(No* lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->dado);
        lista = lista->proximo;
    }
    printf("NULL\n");
}

// Função que inverte a lista duplamente encadeada
void inverterLista(No** lista) {
    if (*lista == NULL) {
        return; // Lista vazia, nada a fazer
    }

    No* temp = NULL;
    No* atual = *lista;

    // Invertendo os ponteiros de cada nó
    while (atual != NULL) {
        temp = atual->anterior;
        atual->anterior = atual->proximo;
        atual->proximo = temp;
        atual = atual->anterior;
    }

    // Ajustando o início da lista após a inversão
    if (temp != NULL) {
        *lista = temp->anterior;
    }
}

int main() {
    No* lista = NULL;


    inserirFim(&lista, 20);
    inserirFim(&lista, 30);
    inserirFim(&lista, 30);
    inserirFim(&lista, 40);
    inserirInicio(&lista,10);
    inserirordenado(&lista,31);
    inserirordenado(&lista,33);
    inserirordenado(&lista,1);
    inserirordenado(&lista,11);

    exibir(lista);
    removerimpares(&lista);
    removerduplicatas(&lista);

    printf("Lista atual:\n");
    exibir(lista);




    return 0;
}
