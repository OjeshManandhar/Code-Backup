#include <stdio.h>
#include <stdlib.h>

int main()
{
    int o=0,e=0,n,i=1;
    printf("Enter the total number of the terms of the series: ");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        if (i%2==0)
            e+=i;
        else
            o+=i;
    printf("\nSum of even and odd integers of the series are %d and %d respectively.\n",e,o);
    return 0;
}
