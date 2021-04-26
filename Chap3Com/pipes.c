#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    char buffer[30];
    int fd[2];
    pipe(fd);
    switch (fork())
    {
    case -1:
        perror("fork()");
        exit(-1);
    case 0:
        close(fd[1]);
        printf("\nChild : Readin from pipe");
        read(fd[0], buffer, sizeof(buffer));
        printf("\nChild : %s", buffer);
        break;
    default:
        close(fd[0]);
        printf("\nYour input? ");
        scanf("%s", buffer);
        printf("\nParent : writing to pipe");
        write(fd[1], buffer, 20);
        wait(NULL);
        break;
    }
    return 0;
}