#include <stdio.h>
#include <unistd.h>

int main()
{
    int i = 1;
    while (fork() == 0 && i <= 3)
        i++;
    printf("%d %d %d\n", i, getpid(), getppid());
    return 0;
}
/*
1 40956 37817
2 40957 40956
3 40958 40957
4 40959 40958
4 40960 1
*/