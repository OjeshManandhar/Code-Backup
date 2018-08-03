#include <stdio.h>
#incldue <stdlib.h>

int main()
{
    int i,j;
    printf("     ");
    for (j=1;j<=10;j++)
        printf(" %4d",j);
    printf("\n     ");
    for (j=1;j<=50;j++)
        printf("-");
    printf("\n");
    for (i=1;i<=10;i++)
    {
        printf("%-3d |",i);
        for (j=1;j<=10;j++)
            printf(" %4d",i*j);
        printf("\n");
    }
}
