#include <stdio.h>
#include <unistd.h>
int main()
{
    fork();
    //execlp("who", "who", NULL);
    printf("fork 1 \n");
    execlp("pwd", "pwd", NULL);
    //fork();
    printf("fork 2 \n");
    return (0);
}