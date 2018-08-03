#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int);

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("\nThe factorial of %d is %d.\n",n,fact(n));
    return 0;
}

int fact(int n)
{
    int f;
    if (n==1)
        return 1;
    else
        f=n*fact(n-1);
    return f;
}
