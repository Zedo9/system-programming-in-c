#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int pereFils[2], filsPere[2];
    int resFils, resPere;
    int opPere[2];
    int opFils[2];
    pipe(pereFils);
    pipe(filsPere);
    switch (fork())
    {
    case -1:
        perror("fork()");
        exit(-1);
    case 0:
        close(pereFils[1]);
        read(pereFils[0], opFils, sizeof(int[2]));
        resFils = *opFils + *(opFils + 1);
        write(filsPere[1], &resFils, sizeof(int));
        close(pereFils[0]);
        close(filsPere[1]);
        break;
    default:
        close(filsPere[1]);
        printf("\nop1=?");
        scanf("%d", opPere);
        printf("\nop2=?");
        scanf("%d", opPere + 1);
        write(pereFils[1], opPere, sizeof(int[2]));
        read(filsPere[0], &resPere, sizeof(int));
        printf("\nResultat %d : ", resPere);
        close(filsPere[0]);
        close(pereFils[1]);
        break;
    }
    return 0;
}