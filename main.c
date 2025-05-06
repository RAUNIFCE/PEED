/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
void dobrarvalores(int *vetor);
invertervalores(int *vetor);
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
    dobrarvalores(vetor);
    invertervalores(vetor,tamvetor);
    return 0;
}
void dobrarvalores(int *vetor){
    for(int i=0;i<3;i++){
        vetor[i]=vetor[i]*2;
        printf("%d\n",vetor[i]);
    }
}
invertervalores(int *vetor,int tamvetor){
    for(int i=tamvetor-1;i>0;i--){
        
        printf("%d\n",vetor[i]);
    }
}