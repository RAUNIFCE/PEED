#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

void inserirInicio(No** lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = *lista;
    *lista = novo;
}

/* Primeira fun��o da lista*/
void inserirFinal(No** lista,int valor){
    No *atual = *lista;
    while(atual->proximo!=NULL){
        atual=atual->proximo;
    }
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

/*Segunda fun��o da lista*/
//A segunda fun��o o professor j� fez e � a a fun��o inserirposicao()
/* A terceira fun��o */
void removervalores(No **lista, int valor){
     if (*lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    No *atual1 = *lista;
    No *atual2 = *lista;
    int cont=0;
    while(atual2->dado!=valor&&atual2!=NULL){
        atual2=atual2->proximo;
        cont++;
    }
    if(cont==0){
    removerInicio(lista);
    return;

    }
    while(atual1->proximo!=atual2){
        atual1=atual1->proximo;
        printf("\ndeu certo");
    }
    atual1->proximo=atual2->proximo;
    free(atual2);
}
/* Quarta fun��o*/


void removerposicao(No **lista, int posicao){
    if (*lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    No *atual1 = *lista;
    No *atual2 = *lista;
    int i=0;
        while(i < posicao-1 && atual2->proximo != NULL){
        atual2 = atual2->proximo;
        i++;
    }
        while(atual1->proximo!=atual2){
        atual1=atual1->proximo;
        printf("\ndeu certo");
    }
    atual1->proximo=atual2->proximo;
    free(atual2);
}

/* Quinta fun��o*/
int contano(No* lista){
    int enlace=0;
    while (lista != NULL) {

        lista = lista->proximo;
        enlace++;
    }

    return enlace;
}

/* Sexta fun��o*/
void kilist(No** lista){
    No *atual1 = *lista;
    No *atual2 = *lista;
    while(atual1!=NULL){
        atual2=atual1->proximo;
        free(atual1);
        atual1=atual2;
        printf("*excluido\n");
    }
    *lista=NULL;
}




void removerInicio(No** lista) {
    if (*lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    No* temp = *lista;
    *lista = temp->proximo;
    free(temp);
}

No* buscar(No* lista, int valor) {
    while (lista != NULL) {
        if (lista->dado == valor)
            return lista;
        lista = lista->proximo;
    }
    return NULL;
}

void exibir(No* lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->dado);
        lista = lista->proximo;
    }
    printf("NULL\n");
}

void inserirPosicao(No **lista, int valor, int index){
    if(index < 0){
        printf("Posi��o inv�lida!\n");
        return ;
    }
    if(index == 0){
        inserirInicio(lista, valor);
        return ;
    }
    No *atual = *lista;
    int i = 0;

    while(i < index - 1 && atual->proximo != NULL){
        atual = atual->proximo;
        i++;
    }

    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;

    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

int main() {
    No* lista = NULL;
    printf("Lista atual:\n");

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 30);
    printf("Lista atual:\n");
    exibir(lista);

    inserirPosicao(&lista, 40, 2);
    exibir(lista);

    /* 1 FUN��O*/
    inserirFinal(&lista,500);
    printf("Lista atual:\n");
    exibir(lista);

    int cod,opc,num,pos;
    printf("deseja acessar o menu? \n0-N \n1-S\n");
    scanf("%d",&cod);

    if(cod==1){
       printf("digite a op��o desejada\n1-remover por valor\n2-remover por posicao\n3-contar os n�s da listalista\n4-finalizar lista\n");
       scanf("%d",&opc);


           if(opc==1){
            printf("deseja retirar qual numero?");
            scanf("%d",&num);
            printf("removendo o valor%d\n",num);
           }


           if(opc==2){
            printf("deseja retirar qual posi��o?");
            scanf("%d",&pos);
                if(pos==1){
                removerInicio(&lista);
                }else{
                    removerposicao(&lista,pos);
                }
           }

           if(opc==3){
            printf("o numero de nos � %d",contano(lista));
            }
            if(opc==4){
            kilist(&lista);
            }

        }

    exibir(lista);
    printf("fim");

    return 0;
}
