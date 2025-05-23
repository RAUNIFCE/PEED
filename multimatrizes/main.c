#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define LINHAS 2
#define COLUNAS 3
void mostramatriza(int matriz[LINHAS][COLUNAS]);
void mostramatrizb(int matriz[3][2]);
int preenchermatriz(int linha,int coluna,int matriz[linha][coluna]);
int mostramatriz(int linha,int coluna,int matriz[linha][coluna]);
int main()
{
    setlocale(LC_ALL,"portuguese" );
/*
    printf("exibição de matrizes\n");
    int A[LINHAS][COLUNAS]={{1,2,3},{4,5,6}};
    int B[LINHAS][COLUNAS]={{6,5,4},{3,2,1}};
    int resultado[LINHAS][COLUNAS];
    //EXIBIÇÃO DE MATRIZES
    mostramatriz(A);
    printf("matriz B\n");
    mostramatriz(B);
    //SOMA DE MATRIZES
    printf("\n");
    for(int i=0;i<LINHAS;i++) {
        for(int j=0;j<COLUNAS;j++) {
            resultado[i][j]=A[i][j]+B[i][j];
        }
    }
    mostramatriz(resultado);
*/


//teste multiplicação de matrizes
    /*
    printf("Multiplicação de matrizes");
    int a[2][3]={{2,2,2},{1,1,1}};
    int b[3][2]={{1,2},{3,4},{5,6}};
    int c[2][2];
    mostramatriza(a);
    mostramatrizb(b);

    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            c[i][j]=0;
           for (int k=0;k<3;k++) {
               c[i][j]=c[i][j]+a[i][k]*b[k][j];
           }
            printf("\n[%d]\n",c[i][j]);
        }
    }
    printf("mostrando a matriz resultante");
    for(int i=0;i<2;i++) {
        printf("\n");
        for(int j=0;j<2;j++) {
            printf("[%d]",c[i][j]);
        }
    }*/

    printf("************MULTIPLICACAO DE MATRIZES INTELIGENTE********************\n");
    int ai,aj,bi,bj;
    printf("\n Digite o numero de linhas da matriz A ");
    scanf("%d",&ai);
    printf("\n Digite o numero de colunas da matriz A ");
    scanf("%d",&aj);
    printf("\n Digite o numero de linhas da matriz B ");
    scanf("%d",&bi);
    printf("\n Digite o numero de colunas da matriz b ");
    scanf("%d",&bj);
    srand(time(NULL));
    int a[ai][aj];
    int b[bi][bj];
    preenchermatriz(ai,aj,a);
    preenchermatriz(bi,bj,b);
    mostramatriz(ai,aj,a);
    mostramatriz(bi,bj,b);
    if (aj!=bi) {
        printf("\n não da certo a matriz A não tem o mesmo numero de colunas que o numero de linhas da matriz B");
        return 1;
    }else {

        int c[ai][bj];
        for(int i=0;i<ai;i++) {
            for(int j=0;j<bj;j++) {
                c[i][j]=0;
                for (int k=0;k<aj;k++) {
                    c[i][j]=c[i][j]+a[i][k]*b[k][j];
                }
                printf("\n[%d]\n",c[i][j]);
            }
        }
        printf("mostrando a matriz resultante");
        for(int i=0;i<ai;i++) {
            printf("\n");
            for(int j=0;j<bj;j++) {
                printf("[%d]",c[i][j]);
            }
        }
    }

}
int preenchermatriz(int linha,int coluna,int matriz[linha][coluna]) {
    srand(time(NULL));
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            matriz[i][j]=(int)(rand()%62);
        }
    }
    return 0;
}
int mostramatriz(int linha,int coluna,int matriz[linha][coluna]) {

    for(int i=0;i<linha;i++){

        for(int j=0;j<coluna;j++){
            printf("[%d]",matriz[i][j]);
            if (j==coluna-1) {
                printf("\n");
            }
        }
    }
    return 0;
}
void mostramatriza(int matriz[LINHAS][COLUNAS]) {
    for(int i=0;i<2;i++) {
        for(int j=0;j<3;j++) {
            printf("[%d] ",matriz[i][j]);
            if (j==2 ) {
                printf("\n");
            }
        }
    }
    printf("\n");
}
void mostramatrizb(int matriz[3][2]) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<2;j++) {
            printf("[%d] ",matriz[i][j]);
            if (j==1 ) {
                printf("\n");
            }
        }
    }
    printf("\n");
}