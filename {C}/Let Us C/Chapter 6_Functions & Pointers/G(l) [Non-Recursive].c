#include <stdio.h>
#include <stdlib.h>

void check(int,int);
int main()
{
    int a,b;
    printf("Enter the value of A: ");
    scanf("%d",&a);
    printf("Enter the value of B: ");
    scanf("%d",&b);
    check(a,b);
    return 0;
}

void check(int a,int b)
{
    int x=1,q;
    while (x!=0)
    {
        q=a/b;
        x=a-q*b;
        if (x==0)
            printf("\nThe greatest common divisor is %d.\n",b);
        else
        {
            a=b;
            b=x;
        }
    }
}
