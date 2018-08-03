#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,r,sum=0;
    printf("Enter a 4-digit number: ");
    scanf("%d",&n);
    r=n%10;
    sum+=r;
    r=(n/10)%10;
    sum+=r;
    r=(n/100)%10;
    sum+=r;
    r=(n/1000)%10;
    sum+=r;
    printf("\nThe sum of the digits are: %d.\n",sum);
    return 0;
}
