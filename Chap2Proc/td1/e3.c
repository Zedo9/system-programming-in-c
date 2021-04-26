#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void main()
{
    int i = 1;
    while (i < 3)
    {
        if (fork())
        {
            printf("P: %d %d \n", getpid(), getppid());
            break;
        }
        else
            printf("F: %d %d \n", getpid(), getppid());
        i++;
    }
}
/*
P: 49854 37817
F: 49855 49854
P: 49855 1
F: 49856 49855
*/