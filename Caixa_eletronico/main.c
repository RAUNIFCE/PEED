#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()

{   int opc;
    float saldo=0,deposito,saque;
    do{
    setlocale(LC_ALL,"portuguese" );
    system("cls");
    printf("--------menu de op��es-------\n1-consultar saldo \n2-depositar \n3-sacar \n4-sair do programa\n");
    scanf("%d",&opc);

    switch(opc){
    case 1:

    printf("Seu saldo � R$ %.2f \n",saldo);
    system("pause");
    system("cls");
    break;

    case 2:
    printf("Digite o valor a ser depositado: R$ ");
    scanf("%f",&deposito);
    if(deposito<=0){
        printf("coloque um numero positivo,opera��o cancelada\n");
        system("pause");
        break;
    }
    else{
    saldo=saldo+deposito;
    system("cls");
    break;
    }
    case 3:
    printf("Digite o valor a ser sacado: R$ ");
    scanf("%f",&saque);
    if(saque>saldo ){
        printf("saldo insuficiente seu saldo atual � %.2f,opera��o cancelada\n",saldo);
        system("pause");
    }
    else if(saque<=0){
        printf("digite um valor positivo!\n");
        system("pause");
    }
    else{
    saldo=saldo-saque;
    printf("opera��o feita com sucesso!\nseu novo saldo � %.2f\n",saldo);
    system("pause");

    break;
    }
    }
    }while(opc!=4);

    return 0;
}
