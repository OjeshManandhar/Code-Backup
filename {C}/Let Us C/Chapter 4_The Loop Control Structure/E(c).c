#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1,f=1,j;
    for (;i<=7;i++,f=1)
    {
        for (j=1;j<=i;j++)
            f*=j;
        printf("%.2f + ",(i*1.0)/f);
    }
    printf("\n");
    return 0;
}
