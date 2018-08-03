#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,p=1;
    for (i=1;i<=5;i++)
    {
        for (j=1;j<=i;j++,p++)
            printf("%d\t",p);
        printf("\n");
    }
    return 0;
}
