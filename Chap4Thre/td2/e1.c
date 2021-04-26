#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *lecture(void *ch)
{
    printf("\nYour Data? ");
    scanf("%s", (char *)ch);
    pthread_exit(0);
    //return (void *)ch;
}

void *ecriture(void *ch)
{
    printf("\nYour Data is %s ", (char *)ch);
    pthread_exit(0);
}

void main(void)
{
    void *ret;
    pthread_t th1, th2;
    char ch[20];
    pthread_create(&th1, NULL, lecture, (void *)ch);
    pthread_join(th1, &ret);
    //pthread_create(&th2, NULL, ecriture, (void *)ret);
    pthread_create(&th2, NULL, ecriture, (void *)ch);
    pthread_join(th2, &ret);
}