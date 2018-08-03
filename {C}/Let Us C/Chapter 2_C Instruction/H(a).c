#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,c,d,e,sum;
    printf("Enter a 5-digit number: ");
    scanf("%d",&n);
    a=n%10;
    b=(n/10)%10;
    c=(n/100)%10;
    d=(n/1000)%10;
    e=(n/10000)%10;
    sum=a+b+c+d+e;
    printf("\nSum of digits: %d.\n",sum);
    return 0;
}
