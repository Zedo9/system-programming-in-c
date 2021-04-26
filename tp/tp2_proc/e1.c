#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    int p;
    p = fork();
    switch (p)
    {
    case -1:
        printf("Erreur: echec du fork()\n");
        break;
    case 0:
        /* processus fils */
        sleep(5); //3
        printf("Fils: \nmon PID est %d, celui de mon père est %d \n", getpid(), getppid());
        break;
    default:
        /* processus père */
        //wait(0);//2
        printf("Père:\nmon pid est %d,mon fils est %d\n", getpid(), p);
        printf("Fin du père.\n");
        break;
    }
    /* 
1/ Lors de cette creation, le processus fils hérite tous les attributs de son pére (contexte mémoire, données,pile) sauf le PID, et le PPID.
Le temps d'execution du processus fils est nul.
A l'issu de l'execution du fork, chaque processus reprend son execution. Le code et les données etant strictement identiques, il est nécsaire de disposer d'un mechanisme pour differencier le comportement des deux processus aprés le fork => On utilise pour cela la valeur de retout du fork() qui est different (chez le fils = 0 , chez le pere = Pid du fils).

2/ wait() ne peut etre présente que dans les processus peres.

3/ le PPID du fils dans ce cas devient 1 
*/
    return 0;
}