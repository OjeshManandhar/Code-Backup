#include <stdio.h>
#include <stdlib.h>

int dsum(int);
int main()
{
    int n,s;
    printf("Enter a 5-digit number: ");
    scanf("%d",&n);
    s=dsum(n);
    printf("\nSum of digits: %d.\n",s);
    return 0;
}

int dsum(int n)
{
    int r,sum=0;
    r=n%10;
    if (n==0)
        return 0;
    else
        sum=r+dsum(n/10);
    return (sum);
}
