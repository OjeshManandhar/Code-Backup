#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,sum;
    printf("Enter a 4-digit number: ");
    scanf("%d",&n);
    a=n%10;
    b=(n/1000)%10;
    sum=a+b;
    printf("\nSum of First and Last digit is: %d\n",sum);
    return 0;
}
