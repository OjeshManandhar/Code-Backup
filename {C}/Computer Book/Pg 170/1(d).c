#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,t=4,x;
    for (i=1;i<=5;i++,t--)
    {
        for (x=1;x<=t;x++)
            printf(" ");
        for (j=1;j<=i;j++)
            printf("* ");
        printf("\n");
    }
    return 0;
}
