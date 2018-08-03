#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,f=1;
    for (i=1;i<=10;i++)
    {
        for(j=1,f=1;j<=i;j++)
            f*=j;
        printf("Factorial of %d is %d.\n",i,f);
    }
    return 0;
}
