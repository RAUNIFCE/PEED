#include <stdio.h>
#include <stdlib.h>
void exibirarray(int *array,int tamanho,int index);

int main()
{
    int tamanho;
    printf("digite o tamanho do seu array");
    scanf("%d",&tamanho);

    int array[tamanho];
    for (int i=0;i<tamanho;i++){
        printf("\n digite o %d elemento",i+1);
        scanf("%d",&array[i]);
    }
    exibirarray(array,tamanho,0);
    //Bubble sort
    int codigo;

    printf("\ndigite 1 para crescente e 2 descrescente\n");
    scanf("%d",&codigo);
    if(codigo==1){
        for(int i=0;i<tamanho-1;i++){
            for(int j=0;j<tamanho-1-i;j++){
                if(array[j]>array[j+1]){

                    int temp;
                    temp=array[j];
                    array[j]=array[j+1];
                    array[j+1]=temp;

                }
            }
        }
    }
    if(codigo==2){
        for(int i=0;i<tamanho-1;i++){
            for(int j=0;j<tamanho-1-i;j++){
                if(array[j]<array[j+1]){

                    int temp;
                    temp=array[j];
                    array[j]=array[j+1];
                    array[j+1]=temp;

                }
            }
        }
    }
    exibirarray(array,tamanho,0);
    return 0;
}
void exibirarray(int *array,int tamanho,int index){
    if(index>=tamanho)
        return;
    printf("[%d]",array[index]);
    exibirarray(array,tamanho,index+1);
}
