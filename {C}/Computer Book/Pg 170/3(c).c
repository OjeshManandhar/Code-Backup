#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    int p[]={'N','E','P','A','L'};
    for (i=5;i>=1;i--)
    {
        for (j=0;j<=i-1;j++)
            printf("%c ",p[j]);
        printf("\n");
    }
    return 0;
}
