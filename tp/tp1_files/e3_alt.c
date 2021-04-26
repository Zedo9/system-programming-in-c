#include <stdio.h>

int main()
{
    FILE *fich;
    int i;
    int input;
    fich = fopen("e3_fich", "wb+");
    for (i = 0; i < 10; i++)
    {
        printf("Entier Num %d : ", i + 1);
        scanf("%d", &input);
        putw(input, fich);
    }
    fseek(fich, 0, 0); // == rewind(fich);
    printf("\nContenu du fichier : ");
    while ((input = getw(fich)) != EOF)
    {
        printf("\n%d", input);
    }
    fclose(fich);
    return 0;
}
