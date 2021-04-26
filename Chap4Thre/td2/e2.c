#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *affiche(void *ch)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("\n%s", (char *)ch);
        sleep(1);
    }
    pthread_exit(0);
}

void main(void)
{
    pthread_t th1, th2;
    void *ret;
    pthread_create(&th1, NULL, affiche, (void *)"1");
    pthread_create(&th2, NULL, affiche, (void *)"2");
    pthread_join(th1, &ret);
    pthread_join(th2, &ret);
}
