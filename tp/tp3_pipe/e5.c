#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// pere -> fils1 -> fils2

int main()
{
    int pereFils1[2];
    int fils1Fils2[2];
    int fils2Pere[2];
    char msgPere[20];
    char msgFils1[20];
    char msgFils2[20];

    pipe(pereFils1);
    pipe(fils1Fils2);
    pipe(fils2Pere);

    printf("\nTapez votre message");
    scanf("%d", msgPere);

    close(pereFils1[0]);
    close(pereFils1[1]);

    close(fils2Pere[0]);
    close(fils2Pere[1]);

    write(pereFils1[1], msgPere, sizeof(char[20]));
    read(fils2Pere[0], msgFils2, sizeof(char[20]));

    // fils1
    if (fork() == 0)
    {
        read(pereFils1[0], msgFils1, sizeof(char[20]));
        write(fils1Fils2[1], msgFils1, sizeof(char[20]));
    }
    // fils2
    if (fork() == 0)
    {
        read(fils1Fils2[0], msgFils2, sizeof(char[20]));
        write(fils2Pere[1], msgFils2, sizeof(char[20]));
    }

    return 0;
}