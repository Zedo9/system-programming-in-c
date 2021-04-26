#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    int p, x;
    x = 2;
    p = fork();
    switch (p)
    {
    case -1:
        printf("Erreur: echec du fork()\n");
        break;
    case 0:
        /* processus fils */
        printf("\nFils: \nmon PID est %d, celui de mon père est %d ", getpid(), getppid());
        printf("\nFils: gid : %d ", getgid());
        printf("\nFils: uid : %d ", getuid());
        x += 3;
        break;
    default:
        /* processus père */
        printf("\npere:\nmon pid est %d,mon fils est %d", getpid(), p);
        printf("\npere: gid : %d ", getgid());
        printf("\npere: uid : %d ", getuid());
        printf("\nFin du père.");
        x *= 5;
        wait(0);
        break;
    }
    printf("\nX=%d", x);
    /*
On remarque qu'il y a duplication des données. Ce n'est le meme X qui a été manipulé.
*/
    return 0;
}