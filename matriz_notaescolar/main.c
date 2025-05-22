#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   double medias[15];
    double notas [15][4];
    double mediaDisciplinas[4];
    double notaDisciplinas[4]={0};
    double maiornotaaluno=0;
    double menornotaDisciplina;

    srand(time(NULL));
    for(int i=0;i<15;i++){
        for(int j=0;j<4;j++){
            notas[i][j]=(double)(rand()%101)/10.0;
        }
    }
    for(int i=0;i<15;i++){
            printf("\n aluno %d",i+1);
        for(int j=0;j<4;j++){
            printf("[%.1f] ",notas[i][j]);
        }
    }
    printf("\nagora a media dos alunos");
    for(int i=0;i<15;i++){
        medias[i]=(notas[i][0]+notas[i][1]+notas[i][2]+notas[i][3])/4;
        printf("\n aluno %d [%.2f]",i+1,medias[i]);
    }
    for(int i=0;i<4;i++){

        for(int j=0;j<15;j++){
            mediaDisciplinas[i]+=notas[j][i];
            if (j==14) {
                notaDisciplinas[i]=mediaDisciplinas[i]/15;
                printf(" \nnota da disciplina %d %.2f ",i+1,notaDisciplinas[i]);
            }
        }
    }
    for(int i=0;i<15;i++) {
        printf("\nagora a media %.2f\n",medias[i]);
        if (medias[i]>maiornotaaluno) {
            maiornotaaluno=medias[i];
            printf("\nnovo aluno com maior nota");
        }
        if (i==14) {
            printf("\n\n maior media entre os alunos %.2f",maiornotaaluno);
        }
    }
    printf("\nAgora as notas das disciplinas");
    for(int i=0;i<4;i++) {
        printf("\n%.2f ",notaDisciplinas[i]);
        if (i==0) {
            menornotaDisciplina=notaDisciplinas[i];
        }
        if (notaDisciplinas[i]<menornotaDisciplina) {
            menornotaDisciplina=notaDisciplinas[i];
        }
    }
    printf("\n menor nota de disciplina %.2f",menornotaDisciplina);


    return 0;
}
