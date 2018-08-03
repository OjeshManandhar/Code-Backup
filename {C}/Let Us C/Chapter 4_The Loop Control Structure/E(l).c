#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x,i;
    float a,sum;
    printf("Enter a number: ");
    scanf("%d",&x);
    a=(x-1)/(x*1.0);
    for (i=2;i<=7;i++)
        sum+=pow(a,i);
    printf("\nThe sum of natural logarithm of %d is: %.2f.\n",x,a+1*sum/2);
    return 0;
}
