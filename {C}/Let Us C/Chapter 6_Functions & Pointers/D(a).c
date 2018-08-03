#include <stdio.h>
#include <stdlib.h>

void fact(int);
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    fact(n);
    return 0;
}

void fact(int n)
{
    int i,f=1;
    for (i=1;i<=n;i++)
        f*=i;
    printf("Factorial Value: %d",f);
}
