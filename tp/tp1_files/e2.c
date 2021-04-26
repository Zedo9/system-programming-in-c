#include <stdio.h>

int main()
{
    FILE *fich;
    int nbChar;
    nbChar = 0;
    fich = fopen("e1_test.dat", "r");
    while (getc(fich) != EOF)
    {
        nbChar++;
    }
    printf("%d chars -> octets", nbChar);
    fclose(fich);
    return 0;
}