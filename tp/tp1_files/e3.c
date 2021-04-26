#include <stdio.h>

void write()
{
    FILE *fich;
    int i;
    int input;
    fich = fopen("e3_fich", "wb");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &input);
        putw(input, fich);
    }
    fclose(fich);
}

void read()
{
    FILE *fich;
    int output;
    fich = fopen("e3_fich", "rb");
    output = (int)getw(fich);
    while (output != EOF)
    {
        printf("\n%d", output);
        output = (char)getc(fich);
    }
    fclose(fich);
}

int main()
{
    write();
    read();
    return 0;
}
