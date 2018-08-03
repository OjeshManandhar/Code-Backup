#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i,sum=0;
    printf("Enter two different numbers.\n");
    printf("Enter the smaller/lower number: ");
    scanf("%d",&a);
    printf("Enter the bigger/higher number: ");
    scanf("%d",&b);
    for (i=a;i<=b;i++)
        sum+=i;
    printf("\nThe sum from lower to higher number is %d.\n",sum);
    return 0;
}
