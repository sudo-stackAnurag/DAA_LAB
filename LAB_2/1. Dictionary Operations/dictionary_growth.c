#include <stdio.h>
#include <math.h>

int main()
{
    FILE *fp = fopen("dictionary.dat", "w");

    if(fp == NULL)
    {
        printf("Error creating file!\n");
        return 1;
    }

    fprintf(fp, "#n O1 Ologn On\n");

    for(int n = 10; n <= 1000; n += 10)
    {
        fprintf(fp, "%d %.2f %.2f %d\n",
                n,
                1.0,
                log2(n),
                n);
    }

    fclose(fp);

    printf("Data generated successfully in dictionary.dat\n");

    return 0;
}