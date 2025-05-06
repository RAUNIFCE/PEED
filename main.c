#include <stdio.h>
void dobrarvalores(int *vetor,int tamvetor);
void invertervalores(int *vetor,int tamvetor);
int main()
{
    int tamvetor=0;
    printf("digite o tamanho do vetor");
    scanf("%d",&tamvetor);
    int vetor[tamvetor];
    for(int i=0;i<tamvetor;i++){
        printf("digite o %dº número",i+1);
        scanf("%d",&vetor[i]);
    }
    dobrarvalores(vetor,tamvetor);
    invertervalores(vetor,tamvetor);
    return 0;
}
void dobrarvalores(int *vetor,int tamvetor){
    printf("dobrando valores\n");
    for(int i=0;i<tamvetor;i++){
        vetor[i]=vetor[i]*2;
        printf("%d\n",vetor[i]);
    }
}
void invertervalores(int *n,int tamvetor){
    printf("invertendo valores");
    int metade=0;
    
        metade=tamvetor/2;
        for(int i=0;i<metade;i++){
        n[i]=n[i]^n[tamvetor-1-i];
        n[tamvetor-1-i]=n[i]^n[tamvetor-1-i];
        n[i]=n[i]^n[tamvetor-1-i];
        }
    
    for(int i=0;i<tamvetor;i++){
        printf("%d\n",n[i]);
    }
    
    
}