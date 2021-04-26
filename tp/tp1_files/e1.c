#include <stdio.h>

int main()
{
    FILE *fichSrc, *fichDest;
    char c;
    fichSrc = fopen("e1_test.dat", "r");
    fichDest = fopen("e1_test_copy.dat", "w");
    ;
    while (c = (char)getc(fichSrc) != EOF)
    {
        fputc(c, fichDest);
    }
    fclose(fichSrc);
    fclose(fichDest);
    return 0;
}