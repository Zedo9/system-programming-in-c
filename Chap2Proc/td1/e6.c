#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

char *getFlag(char *command)
{
    char *flag;
    flag = strtok(command, " ");
    flag = strtok(NULL, " ");
    return flag;
}
int main(int argc, char *argv[])
{
    char buffer[30];
    int fd[2];
    pipe(fd);
    if (fork() == 0)
    {
        close(fd[0]);
        dup2(fd[1], 1);
        execlp(argv[1], argv[1], getFlag(argv[1]), NULL);
    }
    if (fork() == 0)
    {
        close(fd[1]);
        dup2(fd[0], 0);
        execlp(argv[2], argv[2], getFlag(argv[2]), NULL);
    }
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}