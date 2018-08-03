#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d,b=0,x,m=1;
    printf("Enter a decimal number: ");
    scanf("%d",&d);
    x=d;
    while (d!=0)
    {
        b+=(d%2)*m;
        d/=2;
        m*=10;
    }
    printf("\nThe binary equivalent of %d is %d.\n",x,b);
    return 0;
}
