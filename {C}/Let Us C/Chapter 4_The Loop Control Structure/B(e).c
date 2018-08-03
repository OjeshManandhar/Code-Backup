#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,n,r,a=0;
    printf("Enter a number: ");
    scanf("%d",&x);
    n=x;
    while (n>0)
    {
        r=n%10;
        a+=(r*r*r);
        n/=10;
    }
    if (a==x)
        printf("\nThe given number is a ARMSTRONG number.\n");
    else
        printf("\nThe given number is NOT a ARMSTRONG number.\n");
    return 0;
}
