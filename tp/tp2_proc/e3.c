#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    int p;
    FILE *fich;
    char c[5];
    fich = fopen("toto", "a+");
    p = fork();
    switch (p)
    {
    case -1:
        printf("Erreur: echec du fork()\n");
        break;
    case 0:
        fputs("ab", fich);
        sleep(5);
        rewind(fich);
        fgets(c, 3, fich);
        puts(c);
        break;
    default:
        sleep(10);
        rewind(fich);
        fgets(c, 3, fich);
        puts(c);
        fputs("AB", fich);
        wait(0);
        break;
    }
    fclose(fich);
    return 0;
}