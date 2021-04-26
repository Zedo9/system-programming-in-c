#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int pereFils[2];
    pipe(pereFils);
    switch (fork())
    {
    case -1:
        perror("fork()");
        exit(-1);
    case 0:
        close(pereFils[1]);
        dup2(pereFils[0], 0);
        close(pereFils[0]);
        execlp("wc", "wc", "-l", NULL);
        break;
    default:
        close(pereFils[0]);
        dup2(pereFils[1], 1);
        close(pereFils[1]);
        execlp("ls", "ls", "-l", NULL);
        break;
    }
    return 0;
}