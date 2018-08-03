#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1,j,p=1,t,tc=3;
    for (;i<=4;i++)
    {
        for (t=1;t<=tc;t++)
            printf("  ");
        tc--;
        for (j=1;j<=i;j++,p++)
            printf("%d   ",p);
        printf("\n");
    }
    return 0;
}
