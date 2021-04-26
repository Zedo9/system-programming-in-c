#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int nb, i;
    printf("\nNb of processes?");
    scanf("%d", &nb);
    for (i = 0; i < nb; i++)
    {
        if (fork() == 0)
        {
            printf("%d %d \n", getpid(), getppid());
            break;
        }
    }
    wait(0);
    return 0;
}