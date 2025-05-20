#include <stdio.h>
#include <stdlib.h>
//função strcmp se duas strings forem identicas diga sim
int simple_strcmp(const char *s1,const char *s2){
    //percorre as duas strings ao mesmo tempo
    while(*s1!='\0' && *s2!='\0'){
        //se encontar algum caractere diferente
        if(*s1!=*s2){
            return 0;
        }
        s1++;s2++;
    }
    //ve se acabou ao mesmo tempo
    return (*s1 == '\0' && *s2 == '\0') ? "sim" : "não";
}
void strcat_simples( char *str1, char *str2){
    printf("\nestou ativo");
    int *comeco=sizeof(str1);
    while(*str1!='\0'){
        str1++;
        }
      while(*str2!='\0'){
        *str1=*str2;
        str1++;
        str2++;
        }
        *str1 = '\0';

}
void substr(char *str1, char *str2){
    char *inicio=str2;
    char *h,*n;


    int ver=0;
    int cont=0;
    int tamanho;
    tamanho=strlen(str2);
    printf("\n%d",tamanho);
    printf("\n                      achador de substring comecou                \n");
    while(*str1){
        h=str1;
        n=str2;
        do{
            printf("\n%c %c",*h,*n);
            h++;
            n++;
        }while(*h==*n&&*h!='\0'&&*n!='\0');
        if(*n=='\0'){
            printf("**************EXISTE**************");
            return;
        }
    str1++;
    }
     printf("**************NAO EXISTE**************");
}

int main()
{
    char str[]="casa";
    printf("%s",str);
    char strmy[20]="minha";
    char *p=str;
    while(*p){
        printf("%c",*p);
        p++;
    }
    printf("\n");

    //função strcat(destino,fonte)
    printf("strcatsimples vai ser executado");
    char dest[]="casa";
    char src[]="ABC";
    strcat_simples(dest,src);
    printf("\n%s",dest);
    //chamada de função strcmp
    /*
    simple_strcmp(destino,str);
    printf("%s\n",simple_strcmp(destino,str)?"\nsim":"\nnao");
    */
    //função strstr
    char haystac[]="piripaque";
    char needle[]="paque";
    substr(haystac,needle);




    return 0;
}
